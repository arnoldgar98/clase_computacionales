import numpy as np
import matplotlib.pylab as plt

datos= np.genfromtxt("datos.dat",delimiter=";")
x=datos[:,0]
upre=datos[:,1]

plt.figure()
plt.plot(x,upre)
plt.title("Ecuación del resorte ")
plt.xlabel("Tiempo")
plt.ylabel("Posición")
plt.savefig("GarciaArnoldResorte.pdf")