import numpy as np
import matplotlib.pylab as plt
datos= np.genfromtxt("datos.dat")
datos1= np.genfromtxt("datos1.dat")
datos2= np.genfromtxt("datos2.dat")
datos3= np.genfromtxt("datos3.dat")
datos4= np.genfromtxt("datos4.dat")

plt.figure(figsize=(15,10))
plt.subplot(1,5,1)
plt.title("Inicial")
plt.xlabel("X")
plt.ylabel("Y")
plt.imshow(datos)
plt.colorbar()
#con imshow para graficar los 2d
plt.subplot(1,5,2)
plt.title("FIJAS 100")
plt.xlabel("X")
plt.ylabel("Y")
plt.imshow(datos1)
plt.colorbar()
##para t=2500s
plt.subplot(1,5,3)
plt.title("FIJAS 2500")
plt.xlabel("X")
plt.ylabel("Y")
plt.imshow(datos2)
plt.colorbar()
##libres
plt.subplot(1,5,4)
plt.title("LIBRES 100")
plt.xlabel("X")
plt.ylabel("Y")
plt.imshow(datos3)
plt.colorbar()
##libres t2500
plt.subplot(1,5,5)
plt.title("LIBRES 2500")
plt.xlabel("X")
plt.ylabel("Y")
plt.imshow(datos4)
plt.colorbar()
plt.savefig("imagen4")