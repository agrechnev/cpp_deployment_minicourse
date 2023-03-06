# Example 1: ctypes
# Call a vanilla (not python-adapted) C/C++ dynamic library from Python
# Here we call our own lib with an add() function

import ctypes

a = ctypes.CDLL('./add.so')
print(a.add(10, 7))
