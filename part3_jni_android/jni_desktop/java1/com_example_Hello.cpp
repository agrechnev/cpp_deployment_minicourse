/// Here the native method sayHi of the Java class com.example.Hello is implemented in C++

#include <iostream>

#include <jni.h>

#include "com_example_Hello.h"

/// THe signature must be exactly like in the .h file !
JNIEXPORT void JNICALL Java_com_example_Hello_sayHi  (JNIEnv *env, jobject thisObj) {
    using namespace std;
    
    cout << "BlaBlaBla !!!" << endl;    
}
