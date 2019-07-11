import numpy as np
import matplotlib.pylab as plt
datos= np.genfromtxt("datos.dat")
plt.figure()
#con imshow para graficar los 2d
plt.imshow(datos)
plt.savefig("imagen")