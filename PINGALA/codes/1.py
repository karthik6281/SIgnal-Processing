import numpy as np
import matplotlib.pyplot as plt
import math
import scipy
def an(n,a,b):
    if n<=0:
        return 0.0
    else:
        return (a**n-b**n)/(a-b)
def bn(n,a,b):
    if n>=1:
        return an(n-1,a,b)+an(n+1,a,b)
    else:
        return 0.0
def f1(n,a,b):
    return an(n+2,a,b)-1
a=(1+math.sqrt(5))/2
b=(1-math.sqrt(5))/2
#1.1
n=np.arange(1,100)
vec_an=scipy.vectorize(an)
def f2(n,a,b):
    return np.sum(vec_an(np.arange(n),a,b))
def f3(n,a,b):
   return np.dot(vec_an(np.arange(n),a,b),np.array([1/10**i for i in range(n)]))-10/89
vec_f1=scipy.vectorize(f1)
vec_f2=scipy.vectorize(f2)
l1=vec_f1(n,a,b)
l2=vec_f2(n,a,b)
plt.subplot(211)
plt.plot(n,l1,label=r'$a_{n+2}-1$',color='r')
plt.grid()
plt.legend()
plt.subplot(212)
plt.plot(n,l2,label=r'$\sum_{k=1}^{n}a_{k}$')
plt.grid()
plt.legend()
plt.savefig('../figs/1_1.png')
plt.show()
#1.2
vec_f3=scipy.vectorize(f3)
l3=vec_f3(n,a,b)
plt.plot(n,l3,label=r'$\sum_{k=1}^{n}\frac{a_{k}}{10^k}-(\frac{10}{89})$',color='r')
plt.legend()
plt.grid()
plt.savefig('../figs/1_2.png')
plt.show()
#1.3
def f4(n,a,b):
    return a**n+b**n
vec_bn=scipy.vectorize(bn)
vec_f4=scipy.vectorize(f4)
l4=vec_bn(n,a,b)
l5=vec_f4(n,a,b)
plt.subplot(211)
plt.plot(n,l4,label=r'$b_{n}$',color='r')
plt.grid()
plt.legend()
plt.subplot(212)
plt.plot(n,l5,label=r'$\alpha^n+\beta^n$')
plt.grid()
plt.legend()
plt.savefig('../figs/1_3.png')
plt.show()
#1.4
def f5(n,a,b):
   return np.dot(vec_bn(np.arange(n),a,b),np.array([1/10**i for i in range(n)]))-8/89
vec_f5=scipy.vectorize(f5)
l6=vec_f5(n,a,b)
plt.plot(n,l6,label=r'$\sum_{k=1}^{n}\frac{b_{k}}{10^k}-(\frac{8}{89})$')
plt.grid()
plt.legend()
plt.savefig('../figs/1_4.png')
plt.show()
