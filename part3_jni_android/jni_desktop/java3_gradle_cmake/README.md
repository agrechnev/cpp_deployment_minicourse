Java example 3 with Gradle and CMake
===================

The code is exactly the same as in `java3`, but now I build Java with Gradle, and C++ with CMake.  
Note: Building both C++ and Java in the same build is techically possible, but too ugly.  

Note on Gradle and Gradlew:  
You will have to download Gradle and include its `bin` directory into your path if you want to create a new Gradle project.
Not needed for building existing projects with `gradlew`. If something doesn't work, delete the directory `${HOME}/.gradle` and try again.

This setup prepares your for Android, which also uses Gradle and CMake.  
Disclaimer: This setup is not perfect, I'm not bundling `libidiot.so` into a JAR or anything like that.  

How to build this project?

`gradlew build`  
`mkdir build_cpp`  
`cd build_cpp`  
`cmake ../src_cpp/`  
`make`  
`cd ..`  
`export LD_LIBRARY_PATH=$(pwd)/build_cpp`  
`gradlew run`  
