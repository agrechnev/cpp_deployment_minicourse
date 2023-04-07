package com.example.app3

import android.graphics.Bitmap
import android.graphics.BitmapFactory
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.ImageView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // Here we don't use bindings for change, just traditional "find by ID"
        // There are so many faces of Android!
        setContentView(R.layout.activity_main)
        val imageView = findViewById<ImageView>(R.id.imageView)
//        imageView.setImageResource(R.drawable.ua_chernihiv)

        // Load a resource image as a bitmap (original size)
        val bOpts = BitmapFactory.Options()
        bOpts.inScaled = false
//        bOpts.inMutable = true   // If needed ...
        val bm: Bitmap = BitmapFactory.decodeResource(resources, R.drawable.ua_chernihiv, bOpts)
        val imW: Int = bm.width
        val imH: Int = bm.height
        Log.i("BRIANNA", "bm : ${imW}x${imH} isMutable=${bm.isMutable}")

        val bmNew : Bitmap

        // We can modify either IntArray (int[]) in C++
        // Or a (mutable) bitmap itself
        // Both approaches work fine
        // The bitmap way probably involves fewer copies

        if (false) {
            // Modify pixels as IntArray in C++

            // Extract pixels from the bitmap as int[], pixels are AGRB_8888 (32-bit) !!!
            val pix = IntArray(imW * imH)
            bm.getPixels(pix, 0, imW, 0, 0, imW, imH);

            // Modify pixels in C++, note: no OpenCv yet !
            // Note: despite the name the pixels here are in fact BGRA !
            modifyPixels(pix, imW, imH)

            // Create a new bitmap from these pixes
            bmNew = Bitmap.createBitmap(imW, imH, Bitmap.Config.ARGB_8888)
            bmNew.setPixels(pix, 0, imW, 0, 0, imW, imH)
        } else {
            // Modify the bitmap itself in C++

            // Make a mutable copy
            bmNew = bm.copy(Bitmap.Config.ARGB_8888, true)

            // Modify it in the C++
            // Note: in C++ the pixels will be RGBA !
            modifyBitmap(bmNew)
        }

        // Set the new bitmap to the ImageView
        imageView.setImageBitmap(bmNew)
    }

    /// Modify ARGB pixels as IntArray in C++
    external fun modifyPixels(pix: IntArray, imW: Int, imH: Int)

    /// Modify the bitmap itself (JavaObject) in C++, bitmap must be mutable
    external fun modifyBitmap(bm: Bitmap)

    companion object {
        // Used to load the 'app3' library on application startup.
        init {
            System.loadLibrary("app3")
        }
    }
}