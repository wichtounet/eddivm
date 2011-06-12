# EDDI Virtual Machine #

The virtual machine of the EDDI programming language. 

## Building ##

To build the virtual machine, you need to install the [eddi-commons](http://github.com/wichtounet/eddi-commons/) library. 

Then, you juste have to use make to build the compiler : 

    $ git clone git://github.com/wichtounet/eddivm.git
    $ cd eddivm
    $ make

## Usage ##

You can run an EDDI compiled file using the virtual machine easily, for example: 

    $ cd eddivm
    $ ./bin/eddic compiled.v

That will run the compiled.v file. 

You can compile EDDi source file using the EDDI compiler ([eddic](http://github.com/wichtounet/eddic/)). 

## Troubleshooting ##

Please consider using [Github issues tracker](http://github.com/wichtounet/eddivm/issues) to submit bug reports or feature requests. You can also contact me via my [website](http://baptiste-wicht.com/). 

## License ##

This project is distributed under the Boost Software License 1.0. See `LICENSE_1_0.txt` for details.
