import numpy as np
import matplotlib.pylab as plt

datos= np.genfromtxt("datos.dat",delimiter=";")
x=datos[:,0]
upre=datos[:,1]

datos3= np.genfromtxt("datos3.dat",delimiter=";")
x3=datos3[:,0]
upre3=datos3[:,1]

datos4= np.genfromtxt("datos4.dat",delimiter=";")
x4=datos4[:,0]
upre4=datos4[:,1]

plt.figure()
plt.plot(x,upre)
plt.grid()
plt.title("Ecuación del resorte ")
plt.xlabel("Tiempo")
plt.ylabel("Posición")
plt.savefig("inicial")

plt.figure()
plt.plot(x3,upre3)
plt.grid()
plt.title("Ecuación del resorte ")
plt.xlabel("Tiempo")
plt.ylabel("Posición")
plt.savefig("extremosfijos")

plt.figure()
plt.plot(x4,upre4)
plt.grid()
plt.title("Ecuación del resorte ")
plt.xlabel("Tiempo")
plt.ylabel("Posición")
plt.savefig("extremoslibres")