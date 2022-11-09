import numpy as np
import matplotlib.pyplot as plt

A0=12
f0=50

def a(k):
    if k==0:
        return 2*A0/np.pi
    elif k%2==0:
        return 4*A0/(np.pi * (1- k**2))
    else:
        return 0

def b(k): 
    return 0

def x(t):
    sum=0
    for k in range(0,100):
        sum+=a(k)*np.cos(2*np.pi*k*f0*t)+b(k)*np.sin(2*np.pi*k*f0*t)
    return sum


t=np.linspace(0,3/(f0),250)
plt.plot(t, np.abs(A0*np.sin(2*np.pi*f0*t)),label='$|A\sin{2\pi f_0t}|$')
plt.scatter(t,[x(i) for i in t],color='orange',label='$\sum_{k=0}^\infty(a_k\cos2\pi kf_0t+b_k\sin2\pi kf_0t)$')
plt.xlabel('t')
plt.ylabel('x(t)')
plt.grid()
plt.legend()
plt.savefig('../figs/2.6.png')
# plt.savefig('../figs/2.6.pdf')
plt.show()
