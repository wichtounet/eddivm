//=======================================================================
// Copyright Baptiste Wicht 2011.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#include <commons/Timer.hpp>

#include "VirtualMachine.hpp"
#include "Stack.hpp"
#include "Variables.hpp"
#include "StringPool.hpp"

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;

struct Instruction {
	ByteCode bytecode;
	int operand;
};

int VirtualMachine::run(string file){
	cout << "Run " << file << endl;

	Timer timer;

	ByteCodeFileReader reader(file);

	if(reader.isNotOpen()){
		cout << "Unable to open " << file << endl;
		
		return 1;
	}

	int code = runFile(reader);

	cout << "Run took " << timer.elapsed() << "ms" << endl;

	reader.close();
	
	return code;
}

int VirtualMachine::runFile(ByteCodeFileReader& reader){
	int header = reader.readHeader();

	if(header != ('E' + 'D' + 'D' + 'I')){
		cout << "Not an EDDI compiled file" << endl;
		return 1;
	}

	StringPool pool;

	int strings = reader.readInt();

	cout << "String pool size = " << strings << endl;

	for(int i = 0; i < strings; i++){
		int index = reader.readInt();
		string value = reader.readLitteral();

		pool.add(index, value);
	}

	vector<Instruction> instructions;
	int current = 0;

	map<int, int> branches;

	while(reader.hasMore()){
		ByteCode bytecode = reader.readByteCode();

		if(bytecode == LABEL){
			int branche = reader.readInt();

			branches[branche] = current;
		} else {
			Instruction instruction;
			instruction.bytecode = bytecode;
	
			if(instruction.bytecode > LABEL && instruction.bytecode <= JUMP_IF_NOT){
				instruction.operand = reader.readInt();	
			}

			instructions.push_back(instruction);
			++current;
		}	
	}

	Stack stack;
	Variables variables;

	int programCounter = 0;

	while(true){
		Instruction instruction = instructions[programCounter];
		ByteCode bytecode = instruction.bytecode;
		
		programCounter++;

		switch(bytecode){
			case LDCS:
			case LDCI:
				stack.push(instruction.operand);

				break;
			case PRINTI:
				cout << stack.pop() << endl;

				break;
			case PRINTS:
				cout << pool.get(stack.pop()) << endl;

				break;
			case SSTORE:
			case ISTORE:{
				unsigned int variable = (unsigned int) instruction.operand;
				
				variables.assign(variable, stack.pop());
				
				break;
			}
			case SLOAD:
			case ILOAD:{
				unsigned int variable = (unsigned int) instruction.operand;

				stack.push(variables.get(variable));	
				
				break;
			}
			case IADD:{
				int rhs = stack.pop();
				int lhs = stack.pop();
				
				stack.push(lhs + rhs);
				
				break;
			}
			case ISUB:{
				int rhs = stack.pop();
				int lhs = stack.pop();
				
				stack.push(lhs - rhs);
				
				break;
			}
			case IMUL:{
				int rhs = stack.pop();
				int lhs = stack.pop();
				
				stack.push(lhs * rhs);
				
				break;
			}
			case IDIV:{
				int rhs = stack.pop();
				int lhs = stack.pop();
				
				stack.push(lhs / rhs);
				
				break;
			}
			case IMOD:{
				int rhs = stack.pop();
				int lhs = stack.pop();
				
				stack.push(lhs % rhs);
				
				break;
			}
			case SADD:{
				string rhs = pool.get(stack.pop());
				string lhs = pool.get(stack.pop());

				int index = pool.addNew(lhs + rhs);	

				stack.push(index);

				break;
			}
			case JUMP: {
				programCounter = branches[instruction.operand];
		
				break;
			} 
			case JUMP_IF: {
				int result = stack.pop();

				if(result == 1){
					programCounter = branches[instruction.operand];
				}
		
				break;
			} 
		 
			case JUMP_IF_NOT: {
				int result = stack.pop();

				if(result == 0){
					programCounter = branches[instruction.operand];
				}
		
				break;
			} 

			case EQUALS: {
				int rhs = stack.pop();
				int lhs = stack.pop();

				if(lhs == rhs){
					stack.push(1);
				} else {
					stack.push(0);
				}
		
				break;
			} 
			case NOT_EQUALS: {
				int rhs = stack.pop();
				int lhs = stack.pop();

				if(lhs != rhs){
					stack.push(1);
				} else {
					stack.push(0);
				}
		
				break;
			} 
			case GREATER_THAN: {
				int rhs = stack.pop();
				int lhs = stack.pop();

				if(lhs > rhs){
					stack.push(1);
				} else {
					stack.push(0);
				}
		
				break;
			} 
			case LESS_THAN: {
				int rhs = stack.pop();
				int lhs = stack.pop();

				if(lhs < rhs){
					stack.push(1);
				} else {
					stack.push(0);
				}
		
				break;
			} 
			case GREATER_THAN_EQUALS: {
				int rhs = stack.pop();
				int lhs = stack.pop();

				if(lhs >= rhs){
					stack.push(1);
				} else {
					stack.push(0);
				}
		
				break;
			} 
			case LESS_THAN_EQUALS: {
				int rhs = stack.pop();
				int lhs = stack.pop();

				if(lhs <= rhs){
					stack.push(1);
				} else {
					stack.push(0);
				}
		
				break;
			} 
			case END:
				return 0;
		}
	}

	return 1;
}
