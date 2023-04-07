package com.example.app2

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import java.io.File

import com.example.app2.databinding.ActivityMainBinding


class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // We want a file on the "external storage"
        // Where you read the file in Android file manager or via USB
        val storage: File = applicationContext.getExternalFilesDir(null)!!
        val file  = File(storage, "from_cpp.txt")
        Log.i("BRIANNA", "file = $file")

        // Call the native method to write some text to the disk
        writeText(file.toString())

        // Now read the data in Kotlin
        val text : String = file.readText()

        // ANd show it in our TextView
        binding.sampleText.text = text
    }

    // Native method which writes the text to a file in C++
    external fun writeText(fileName: String)

    companion object {
        // Used to load the 'app2' library on application startup.
        init {
            System.loadLibrary("app2")
        }
    }
}