# Example 1: ctypes
# Call a vanilla (not python-adapted) C/C++ dynamic library from Python
# For Windows, the C library will be called something else (if present at all)

import ctypes

libc = ctypes.CDLL('libc.so.6')
print(libc.time(None))
