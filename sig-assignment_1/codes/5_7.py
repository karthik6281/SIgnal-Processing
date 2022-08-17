import numpy as np
import matplotlib.pyplot as plt

n = np.arange(12)
def u(n):
    if n <0 :
        return 0.0
    else :
        return 1.0
        
def h(n):
 if n > 0 : 
    return u(n)*(-1.0/2)**n + u(n-2)*(-1.0/2)**(n-2) -(1/2)*h(n-1)
 else :
    return 0
plt.stem(n, [h(t) for t in n])
plt.title('Filter Impulse Response')
plt.xlabel('$n$')
plt.ylabel('$h(n)$')
plt.grid()# minor
plt.show()   

