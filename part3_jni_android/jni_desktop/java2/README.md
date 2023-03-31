JNI example 2: Arguments, return values
==============

Here I create a Java class `com.example.Hello` with native methods `addInt`, `addStr`.

How to build this. First, make sure you have JDK installed, the environment
variable `JAVA_HOME` is set (to the JDK root), and `${JAVA_HOME}/bin` is in
`PATH`. You will also need a C++ compiler.


To build the Java code (creates `com/example/Hello.class`):  

`javac com/example/Hello.java`  

To build the C++ code on Linux (creates `libidiot.so`):  

`./build.sh`  

For other OS's you'll have to improvise.


To run the Java code:  

`java -Djava.library.path=.  com.example.Hello`

The option here is needed to tell the JVM where to look for the `.so` files (current directory in this case). Alternatively, on Linux you can use:

`export LD_LIBRARY_PATH=.`


Note: The file `com_example_Hello.h` was auto-generated with

`javac -h . com/example/Hello.java`  

But you don't have to repeat this step!
