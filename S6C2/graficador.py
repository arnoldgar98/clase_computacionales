import numpy as np
import matplotlib.pylab as plt

datos= np.genfromtxt("datos.dat",delimiter=";")
x=datos[:,0]
upre=datos[:,1]

#datos2= np.genfromtxt("datos2.dat",delimiter=";")
#upre2=datos2[:]

datos3= np.genfromtxt("datos3.dat",delimiter=";")
upre3=datos3[:]

plt.figure()
plt.plot(x,upre)
plt.grid()
plt.title("Ecuación del resorte ")
plt.xlabel("Tiempo")
plt.ylabel("Posición")
plt.savefig("otro")

plt.figure()
plt.plot(x,upre)
plt.plot(x,upre2)
plt.plot(x,upre3)
plt.grid()
plt.title("Ecuación del resorte ")
plt.xlabel("Tiempo")
plt.ylabel("Posición")
plt.savefig("otro1")