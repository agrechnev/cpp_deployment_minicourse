Java example 3 with Gradle and CMake
===================

The code is exactly the same as in `java3`, but now I build Java with Gradle, and C++ with CMake.  
Note: Building both C++ and Java in the same build is techically possible, but too ugly.  
You will have to download Gradle and include its `bin` directory into your path (`gradlew` might also work).  

This setup prepares your for Android, which also uses Gradle and CMake.  
Disclaimer: This is not perfect, I'm not bundling `idiot.so` into a JAR or anything like that.  

How to build this project?

`gradle build`  
`mkdir build_cpp`  
`cd build_cpp`  
`cmake ../src_cpp/`  
`make`  
`cd ..`  
`export LD_LIBRARY_PATH=$(pwd)/build_cpp`  
`gradle run`  
