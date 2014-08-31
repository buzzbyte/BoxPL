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
In a Linux terminal at the boxlang's directory, type `./boxlang` followed by the BoxPL filename to run the interpreter on that file.
For example, to run the included test sample under the current directory:
```unix
./boxlang test-box.bpl
```

###Windows
In a Windows command prompt at the boxlang-win's directory, type `boxlang-win` followed by the BoxPL filename to run the interpreter on that file.
For example, to run the included test sample under the current directory:
```dos
boxlang-win32 test-box.bpl
```
