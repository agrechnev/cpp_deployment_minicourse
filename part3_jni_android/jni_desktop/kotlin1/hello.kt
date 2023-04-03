/// A minimal Kotlin JNI example, basically you use external instead of native

package com.example


class Hello {
    init {
        System.loadLibrary("idiot")
    }
    

    external fun sayHi()
}

fun main(){
    val h = Hello()
    h.sayHi()
}
