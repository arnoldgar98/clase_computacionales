import numpy as np
import matplotlib.pylab as plt

datos= np.genfromtxt("datos.dat",delimiter=";")
x=datos[:,0]
u=datos[:,1]

datos2= np.genfromtxt("datos2.dat",delimiter=";")
x2=datos[:,0]
u2=datos[:,1]
plt.figure()
plt.plot(x,u)
plt.plot(x2,u2)
plt.title("pasos en el tiempo")
plt.xlabel("Tiempo")
plt.ylabel("U")
plt.savefig("GarciaArnoldResorte.png")