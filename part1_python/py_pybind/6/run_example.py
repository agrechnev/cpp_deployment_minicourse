import numpy as np
import example

print('fun1 test:')
a = np.array([[1, 2, 3], [4, 5, 6]], dtype=np.float64)
print('a=', a)
b = example.fun1(a)
print('b=', b)

print('\nfun2 test:')
print('Before: a=', a)
#print('flags =', a.flags)
# Eigen matrix ref requires F-order strict, this is why we do .T !!!
# THe Eigen matrix as seen in C++ will be transposed
example.fun2(a.T)
print('After: a=', a)
