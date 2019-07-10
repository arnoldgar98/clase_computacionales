import numpy as np
import matplotlib.pylab as plt

datos= np.genfromtxt("datos.dat",delimiter=";")
x=datos[:,0]
upre=datos[:,1]

datos2= np.genfromtxt("datos2.dat",delimiter=";")
x2=datos2[:,0]
upre2=datos2[:,1]

datos3= np.genfromtxt("datos3.dat",delimiter=";")
x3=datos3[:,0]
upre3=datos3[:,1]

plt.figure()
plt.plot(x,upre)
plt.grid()
plt.title("Ecuación del resorte ")
plt.xlabel("Tiempo")
plt.ylabel("Posición")
plt.savefig("otro")

plt.figure()
plt.plot(x3,upre3)
plt.grid()
plt.title("Ecuación del resorte ")
plt.xlabel("Tiempo")
plt.ylabel("Posición")
plt.savefig("otro1")