JNI example 3: Wrapping a C++ class with JNI corrrectly
==============

Here I create a Java class `com.example.Box` which wraps a C++ class `BoxImpl`.

How to build this. First, make sure you have JDK installed, the environment
variable `JAVA_HOME` is set (to the JDK root), and `${JAVA_HOME}/bin` is in
`PATH`. You will also need a C++ compiler.


To build the Java code (creates `com/example/*.class`):  

`javac com/example/Hello.java com/example/Box.java`  

To build the C++ code on Linux (creates `libidiot.so`):  

`./build.sh`  

For other OS's you'll have to improvise.


To run the Java code:  

`java -Djava.library.path=.  com.example.Hello`

The option here is needed to tell the JVM where to look for the `.so` files (current directory in this case). Alternatively, on Linux you can use:

`export LD_LIBRARY_PATH=.`

