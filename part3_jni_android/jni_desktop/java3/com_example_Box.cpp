/// JNI wrapper to a pure C++ object HelloIMPL
/// This serves as a bridge between Java and pure C++ (BoxImpl.h)

#include <string>

#include <jni.h>

#include "BoxImpl.h"

#include "com_example_Box.h"


/// The "native constructor", here we create a C++ object and store its pointer in the Java field handle
JNIEXPORT void JNICALL Java_com_example_Box_ctorCPP(JNIEnv *env, jobject thisObj, jstring s) {
    // Raw pointer to string
    const char * pS = env->GetStringUTFChars(s, NULL);
    
    // Create a C++ box on heap
    BoxImpl * pBox = new BoxImpl(std::string(pS));
    
    // Release pS
    env->ReleaseStringUTFChars(s, NULL);
    
    // Find class field named "handle" in thisObj
    jclass thisClass = env->GetObjectClass(thisObj);
    jfieldID fieldHandle = env->GetFieldID(thisClass, "handle", "J");  // "J" means long !
    
    // Set pBox to handle
    env->SetLongField(thisObj, fieldHandle, (long)pBox);
}


/// Java get() method, we redirect to 
JNIEXPORT jstring JNICALL Java_com_example_Box_get(JNIEnv *env, jobject thisObj) {
    // Find class field named "handle" in thisObj
    jclass thisClass = env->GetObjectClass(thisObj);
    jfieldID fieldHandle = env->GetFieldID(thisClass, "handle", "J");  // "J" means long !
    
    // Get handle as long
    long handle = env->GetLongField(thisObj, fieldHandle);
    
    // Cast to BoxImpl * and run get()
    BoxImpl * pBox = (BoxImpl *) handle;
    std::string s;
    // Get the string, check if pBox is not null
    if (pBox != nullptr)
        s = pBox->get();
    
    // Conver the result to a new jstring object
    return env->NewStringUTF(s.c_str());
}


/// Java close() method, destroy the C++ object, set handle to zero
JNIEXPORT void JNICALL Java_com_example_Box_close(JNIEnv *env, jobject thisObj) {
    // Find class field named "handle" in thisObj
    jclass thisClass = env->GetObjectClass(thisObj);
    jfieldID fieldHandle = env->GetFieldID(thisClass, "handle", "J");  // "J" means long !
    
    // Get handle as long
    long handle = env->GetLongField(thisObj, fieldHandle);
    
    // Cast to BoxImpl * and delete the C++ object
    BoxImpl * pBox = (BoxImpl *) handle;
    if (pBox != nullptr)
        delete pBox;
    
    // Very important: now set the field to 0, to avoid doble delete
    env->SetLongField(thisObj, fieldHandle, 0);
}


