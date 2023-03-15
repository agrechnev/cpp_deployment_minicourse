import sys
import pathlib

import tensorflow as tf

# Load ResNet50 (Keras) and convert it to tflite
model = tf.keras.applications.resnet50.ResNet50() 
converter = tf.lite.TFLiteConverter.from_keras_model(model)
tflite_model = converter.convert()

# Save tflite model
pathlib.Path('./build').mkdir(exist_ok=True)
with open('./build/resnet50.tflite', 'wb') as f:
    f.write(tflite_model)
