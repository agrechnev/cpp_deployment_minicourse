JNI kotlin examples
================

Here I repeat the JNI examples in Kotlin. The C++ part is exactly the same.

To build and run:  
`./build.sh`  
`kotlinc hello.kt`  
`export LD_LIBRARY_PATH=.`  
`kotlin com.example.HelloKt`  

Note that unlike Java, Kotlin does not auto-generate C++ headers.
