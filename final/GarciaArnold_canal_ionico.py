import numpy as np
import matplotlib.pylab as plt

datos= np.genfromtxt("Canal_ionico.txt",delimiter="\t")
tiempo=datos[:,0]
posicion=datos[:,1]

radio=5
xnue=[]
ynue=[]
x=np.random.uniform(-5,30,1000)
y=np.random.uniform(-5,30,1000)
for i in range(len(x)):
    if ((x[i]**2)+(y[i]**2))**0.5<=radio:
        xnue.append(x[i])
        ynue.append(y[i])
plt.figure()
plt.scatter(xnue,ynue)
plt.scatter(tiempo,posicion)
plt.title("otro circulo")
plt.grid()
plt.savefig("Canal.png")
plt.show()

def funcion(radio0):
    return np.pi*radio0**2

def verosimilitud(r0,robs):
    l= np.exp(-0.5*(np.sum((r0-robs)**2)))
    return l

"""radiofinal=[]
lcaminata=[]
#condiciones iniciales
radioinicial=radio
radiofinal.append(radioinicial)
xinicial=funcion(radiofinal[0])
lcaminata.append(verosimilitud(radiofinal[0],xinicial))
#numero de pasos
#Aca se hace un intento pero seguia sin dar :( y el tiempo no me dio alternativa
iteraciones=1000
for i in range(iteraciones):
    rotro=np.random.normal(radiofinal[0],2.5)
    xinicial= funcion(radiofinal[i])
    xotros= funcion(radioinicial)
    
    linicial=verosimilitud(rotro,radioinicial)
    lotro=verosimilitud(rotro,radioinicial)
    alfa= lotro/linicial
    if alfa>1.0:
            radiofinal.append(rotro) """
    
           


    