import numpy as np
import matplotlib.pylab as plt

datos= np.genfromtxt("datos.dat",delimiter=";")
x=datos[:,0]
upre=datos[:,1]

datos1= np.genfromtxt("datos1.dat",delimiter=";")
x1=datos1[:,0]
upre1=datos1[:,1]

datos2= np.genfromtxt("datos2.dat",delimiter=";")
x2=datos2[:,0]
upre2=datos2[:,1]

datos3= np.genfromtxt("datos3.dat",delimiter=";")
x3=datos3[:,0]
upre3=datos3[:,1]


plt.figure()
plt.plot(x,upre)
plt.grid()
plt.title("Amplitud inicial")
plt.xlabel("Posicion")
plt.ylabel("Amplitud")
plt.savefig("inicial.png")

plt.figure()
plt.plot(x1,upre1)
plt.grid()
plt.title("Extremos fijos")
plt.xlabel("Posicion")
plt.ylabel("Amplitud")
plt.savefig("extremosfijos.png")

plt.figure()
plt.plot(x2,upre2)
plt.grid()
plt.title("Extremo libre")
plt.xlabel("Posicion")
plt.ylabel("Amplitud")
plt.savefig("extremoslibres.png")

plt.figure()
plt.plot(x3,upre3)
plt.grid()
plt.title("Extremo variable")
plt.xlabel("Posicion")
plt.ylabel("Amplitud")
plt.savefig("extremosvariables.png")