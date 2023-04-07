package com.example.funcvandroid

import android.graphics.Bitmap
import android.graphics.BitmapFactory
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView
import com.example.funcvandroid.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Create a bitmap from a resource image (unscaled, mutabe)
        val bOpt = BitmapFactory.Options().apply {
            inScaled = false
            inMutable = true
        }
        val bm: Bitmap = BitmapFactory.decodeResource(resources, R.drawable.ua_chernihiv, bOpt)
//        Log.i("BRIANNA", "bm ${bm.width} x ${bm.height}, mutable = ${bm.isMutable}")



        // Modify the bitmap in C++
        modifyBitmap(bm)

        // Display the modified bitmap on the screen
        binding.imageView.setImageBitmap(bm)
    }

    external fun modifyBitmap(bm: Bitmap)

    companion object {
        // Used to load the 'funcvandroid' library on application startup.
        init {
            System.loadLibrary("funcvandroid")
        }
    }
}