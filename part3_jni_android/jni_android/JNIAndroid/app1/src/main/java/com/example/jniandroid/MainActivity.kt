package com.example.jniandroid

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.example.jniandroid.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Call our two native methods
        val i : Int = addInt(13, 8)
        val s : String = addStr("One", "Two")
        binding.sampleText.text = "$i\n$s"
    }

    // Here I implement a couple of JNI methods, same as in java2/kotlin2
    external fun addInt(a: Int, b: Int) : Int

    external fun addStr(a: String, b: String) : String

    companion object {
        // Used to load the 'jniandroid' library on application startup.
        init {
            System.loadLibrary("jniandroid")
        }
    }
}