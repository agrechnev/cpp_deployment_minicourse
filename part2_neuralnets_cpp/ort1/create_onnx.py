# This script create the ONNX file in the build directory

import sys
import pathlib

import numpy as np
import torch

# A very minimal neural network
class MyModel(torch.nn.Module):
    def __init__(self):
        super(MyModel, self).__init__()
        self.m = torch.tensor([[1., 2., 3.], [4., 5., 6.]])

    def forward(self, x):
        return self.m @ x
    
model = MyModel()
pathlib.Path('./build').mkdir(exist_ok=True)
x = torch.zeros(3, dtype=torch.float32)
torch.onnx.export(model, x, './build/m.onnx', input_names=['input1'], output_names=['output1'])
