import numpy as np
import scipy as sp
import matplotlib.pyplot as plt

def u(n):
    if n > 0 :
        return 1.0
    else :
        return 0.0
def y(n):
    a = 1/(2*1*1e-6)
    b = 1/(2*2*1e-6)
    c = (1-a-b)/(1+a+b)
    d = (2*b)/(1+a+b)
    if n >= 0.0 :
        return (c*y(n-1e-6) + d*u(n) + d*u(n-1e-6))
    else:
        return 0.0

print(y(0.1*1e-5))
y_vec = sp.vectorize(y)
n = np.linspace(0, 1e-6, 100)
plt.plot(n, y_vec(n),'o', label='$y(n)$')
plt.grid()
plt.legend()
plt.savefig('../figs/4_4.png')
plt.show()