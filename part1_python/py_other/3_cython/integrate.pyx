import cython

@cython.cfunc
def f(double x) -> double:
    return x ** 2 - x

def integrate_f(double a, double b, int n) -> double:
    cdef double s = 0
    cdef double dx = (b - a) / n
    cdef int i
    for i in range(n):
        s += f(a + i * dx)
    return s * dx
