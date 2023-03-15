# Load ResNet50 (tflite) and run it on a sample image

import sys

import numpy as np
import cv2 as cv
import tensorflow as tf

# Load and preprocess image
img = cv.imread('../images/gpig1.jpg')
img = cv.resize(img, (224, 224))
img = cv.cvtColor(img, cv.COLOR_BGR2RGB)
img = img.astype('float32') - np.array([103.939, 116.779, 123.68], dtype='float32')
img = img[None, :, :, :]

# Load model, run tflite inference
interpreter = tf.lite.Interpreter('./build/resnet50.tflite')
interpreter.allocate_tensors()
input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()
interpreter.set_tensor(input_details[0]['index'], img)
interpreter.invoke()
out_data = interpreter.get_tensor(output_details[0]['index'])
#print('out_idx=', output_details[0]['index'])
print('CLASS =', out_data.squeeze().argmax())    # 338
