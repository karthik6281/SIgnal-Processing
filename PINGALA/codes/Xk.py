import lcapy as lc
from lcapy.discretetime import z

X0=1/(1-z**(-1)-z**(-2))
xk=X0.IZT()
print(xk)
print("\n") 
Y0=(1+2*z**(-1))/(1-z**(-1)-z**(-2))
yk=Y0.IZT()
print(yk)