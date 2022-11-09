import matplotlib.pyplot as plt
import numpy as np

A = 12
f0 = 50
t = np.linspace(0, 3/f0, 1000)
plt.plot(t, np.abs(A*np.sin(2*np.pi*f0*t)),label='$|A\sin(2\pi f_0t)|$')
plt.title('$x(t) = A|\sin(2\pi f_0t)|$')
plt.xlabel('t (in s)')
plt.legend()
plt.grid()
plt.savefig('../figs/1.1.png')
# plt.savefig('../figs/1.1.pdf')
plt.show()