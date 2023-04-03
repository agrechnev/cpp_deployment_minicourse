/// Kotlin example 3: wrapping a C++ class

package com.example

class Box(s: String) {
    init {
        /// Constructor body
        System.loadLibrary("idiot")
        ctorCPP(s)
    }
    
    /// Class field and methods
    var handle : Long = 0L
    
    external fun ctorCPP(s: String)
    
    external fun get() : String
    
    external fun close()
    
}

fun main() {
    val b =  Box("Rabbit")
    println("get() returns s=" + b.get())
    b.close()
    b.close()
}
