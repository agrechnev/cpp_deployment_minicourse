import numpy as np
import example

a = np.array([[1, 2, 3], [4, 5, 6]], dtype=np.float64)
print('before : a=', a)
example.fun(a)
print('after : a=', a)
