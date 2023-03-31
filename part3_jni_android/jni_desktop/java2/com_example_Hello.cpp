#include <iostream>
#include <string>

#include <jni.h>

#include "com_example_Hello.h"


/// Add two numbers, this is simple, Java primitives become C++ primitives
JNIEXPORT jint JNICALL Java_com_example_Hello_addInt  (JNIEnv * env, jobject thisObj, jint a, jint b) {
    return a + b;
}


/// Concatenate two strings, this is trickier Java string is NOT a C++ std::string !
JNIEXPORT jstring JNICALL Java_com_example_Hello_addStr  (JNIEnv * env, jobject thisObj, jstring a, jstring b) {
    using namespace std;
    
    // Get raw pointers from Java strings, no copying
    const char * aP = env->GetStringUTFChars(a, NULL);
    const char * bP = env->GetStringUTFChars(b, NULL);
    
    // Create C++ strings and concatenate, the data is copied
    string s = string(aP) + string(bP);
    
//     cout << "s = " << s << endl;
    
    // Create a new Java string, the data is copied
    // Java string is memory-managed by the JVM, no memory leaks
    return env->NewStringUTF(s.c_str());
    
    // Stack object s is destroyed here, but we already copied the data
}
