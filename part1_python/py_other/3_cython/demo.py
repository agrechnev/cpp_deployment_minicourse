import time
import integrate

t1 = time.time()
print(integrate.integrate_f(0, 3, 10000000))   # Ten million
t2 = time.time()
print('Time elapsed=', t2-t1)
