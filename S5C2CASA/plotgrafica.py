import numpy as np
import matplotlib.pylab as plt

datos1= np.genfromtxt("datos.dat",delimiter=";")
x=datos1[:,0]
y=datos1[:,1]
datos2=np.genfromtxt("datos.dat2",delimiter=";")
x1=datos2[:,0]
y1=datos2[:,1]
plt.figure()
plt.plot(x,y,Label="Euler")
plt.plot(x1,y1,Label="Runge-kutta")
plt.title("Euler y runge-kutta")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.savefig("euleryrunge.pdf")