# This script create the ONNX file in the build directory

import sys
import pathlib

import numpy as np
import torch
import torchvision

# Load ResNet-50 from torchvision
weights = torchvision.models.ResNet50_Weights.IMAGENET1K_V2
model = torchvision.models.resnet50(weights=weights)
# eval() is super-important, the model misbehaves otehrwise !
model.eval()

# Export to ONNX
pathlib.Path('./build').mkdir(exist_ok=True)
x = torch.zeros((1, 3, 224, 224), dtype=torch.float32)
torch.onnx.export(model, x, './build/resnet50.onnx', input_names=['input1'], output_names=['output1'])
