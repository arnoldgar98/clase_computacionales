import numpy as np
import matplotlib.pylab as plt

datos= np.genfromtxt("datos.dat",delimiter=";")
t=datos[:,0]
x=datos[:,1]

plt.figure()
plt.plot(t,x)
plt.title("Ecuación del resorte ")
plt.xlabel("Tiempo")
plt.ylabel("Posición")
plt.savefig("GarciaArnoldResorte.pdf")