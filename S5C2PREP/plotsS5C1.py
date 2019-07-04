import numpy as np
import matplotlib.pylab as plt

x=np.linspace(0,10,100)

def funcion(x):
    return np.cos(x)
    
def derivada():
    h= x[1]-x[0]
    derivada= (funcion(x+h)-funcion(x))/h
    return derivada
plt.figure()
plt.plot(x,funcion(x),Label="Original")
plt.plot(x,derivada(),Label="Derivada")
plt.title("Función y derivada")
plt.xlabel("X")
plt.ylabel("Función")
plt.legend()
plt.savefig("S5C1PLOT.pdf")

    