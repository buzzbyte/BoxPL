BoxPL
=====

A simple Esoteric Programming Language. Currently under development.

Structure
---------
BoxPL requires that you always start your code with `Open Box` and end your code with `Close Box` and that you indent your runnable code by four spaces before the command. See the included test sample ([test-box.bpl](https://github.com/buzzbyte/BoxPL/blob/master/test-box.bpl)) for more info on the basic structure.

###Simple "Hello World" Program
```boxpl
Open Box
    unpack [Hello World!]
    makeline
Close Box
```

How to Use the Interpreter (boxlang)
------------------------------------
###Linux
*Prebuilt only for amd64 Linux architectures. If you use other, you would have to build it yourself from source (see [Building from source](#building-from-source)).*

In a Linux terminal at the directory where boxlang is located (e.g. builds/), type `./boxlang` followed by the BoxPL filename to run the interpreter on that file.
For example, to run the included test sample under the current directory:
```unix
./boxlang test-box.bpl
```

###Windows
In a Windows command prompt at the directory where boxlang-win32.exe is located (e.g. builds/), type `boxlang-win32` followed by the BoxPL filename to run the interpreter on that file.
For example, to run the included test sample under the current directory:
```dos
boxlang-win32 test-box.bpl
```

How to get it
-------------
You could get the interpreter in two ways, either download the pre-built version on GitHub (might not be the latest), or build it yourself from source.

###Downloading Pre-built
You can download the whole zip file from GitHub by clicking the "Download ZIP" button on the right of the repository page (or you can clone it).

If you only want the binary, go to the builds folder on GitHub then choose the appropiate pre-build for your machine.

###Building from source
Download the ZIP (see above) and extract it to your working directory (e.g. a folder under your home/user directory).

On a Linux shell (or on Windows with Cygwin, MinGW, or anything similar), `cd` to your working directory then `make` and wait for the compiler to finish. The compiled binary will be under the `ubuild/` directory (unless you edited the Makefile).

Contact
-------
If problems should arise or if you have any questions or suggestions, you can [create an "issue"](https://github.com/buzzbyte/BoxPL/issues/new) on GitHub (for right now) and I will address them as usual. :smile:

Licence
-------
Copyright &copy; 2014  Mohamed Salah (buzzbyte)

This software is licenced under the GNU GPL v3.

A copy of the licence should be [available with this software](https://github.com/buzzbyte/BoxPL/blob/master/LICENSE). If it's not, see http://www.gnu.org/licenses/gpl.html.
