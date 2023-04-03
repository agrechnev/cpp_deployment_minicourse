

package com.example

class Hello {
    init {
        System.loadLibrary("idiot")
    }
    
    external fun addInt(a: Int, b: Int) : Int
    
    external fun addStr(a: String, b: String) : String
}

fun main() {
    val h = Hello()
    println(h.addInt(13, 8))
    println(h.addStr("One", "Two"))
}
