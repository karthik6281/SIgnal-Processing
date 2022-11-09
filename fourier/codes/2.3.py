import numpy as np
import matplotlib.pyplot as plt


def c(k):
    if k%2==0:
        return 2*A0/(np.pi * (1- k**2))
    else:
        return 0

def x(t):
    sum=0
    for k in range(-int(1e2),int(1e2)):
            sum+=c(k)*np.exp(2*1j*np.pi*k*f0*t)
    return np.real(sum)

A0 = 12
f0 = 50

t = np.linspace(0, 3/f0, 250)
plt.plot(t, np.abs(A0*np.sin(2*np.pi*f0*t)),label='$|A\sin{2\pi f_0t}|$')
plt.scatter(t,[x(i) for i in t],label='$\sum_{k=-\infty}^{\infty}c_ke^{j2\pi kf_0t}$',color='red')
plt.xlabel('t')
plt.ylabel('x(t)')
plt.grid()
plt.legend()
plt.savefig('../figs/2.3.png')
# plt.savefig('../figs/2.3.pdf')
plt.show()
