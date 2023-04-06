/// Kotlin example 4: Modify IntArray in place

package com.example

class Hello {
    init {
        System.loadLibrary("idiot")
    }
    
    external fun modifyArray(arr: IntArray)
}

fun main() {
        val intArray: IntArray = intArrayOf(3, 4, 11, 7)
        println("BEFORE : ${intArray.contentToString()}")
        Hello().modifyArray(intArray)
        println("AFTER : ${intArray.contentToString()}")
}
