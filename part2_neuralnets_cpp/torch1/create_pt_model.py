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

# Convert to graph by tracing
x = torch.randn((1, 3, 224, 224))
model_ts = torch.jit.trace(model, x)

# Save model
pathlib.Path('./build').mkdir(exist_ok=True)
model_ts.save('./build/resnet50_traced.pt')
