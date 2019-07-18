#Ejercicio 1 Terminar lo que hizo en clase + dos preguntas adicionales (en mayusculas en el texto)

import numpy as np
import matplotlib.pylab as plt


# 1) lea los datos de resorte.dat y almacenelos.
# 
datos=np.genfromtxt("resorte.dat",delimiter=" ")
t=datos[:,0]
x=datos[:,1]
plt.figure()
plt.plot(t,x)
plt.savefig("primer")
# Los datos corresponden a las posiciones en x de un oscilador (masa resorte) en funcion del tiempo. La ecuacion de movimiento esta dada por
def funcion(a,gamma,omega,t1):
    return a*np.exp(-gamma*t1)*np.cos(omega*t1)
# xt=a*np.exp(-gamma*t)*np.cos(omega*t)
# Donde a, gamma, y omega son parametros.

# 2) Implemente un algoritmo que le permita, por medio de estimacion bayesiana de parametros, encontrar los parametros correspondientes a los datos d. Para esto debe:
# 2a.) definir una funcion que reciba los parametros que se busca estimar y los datos de tiempo y retorne el modelo  
def funcion1(a,gamma,omega,t1):
    return a*np.exp(-gamma*t1)*np.cos(omega*t1)

# 2b.) Definir una funcion que retorne la funcion de verosimilitud
def verosimilitud(x0,xobs):
    l= np.exp(-0.5*(np.sum((x0-xobs)**2)))
    return l
# 2c.) Caminata


acami=[]
gammacami=[]
omegacami=[]
lcami=[]
#condiciones iniciales
aini=7.5
gammaini=0.6
omegaini=18.2

acami.append(aini)
gammacami.append(gammaini)
omegacami.append(omegaini)
xinicial=funcion1(acami[0],gammacami[0],omegacami[0],t)
lcami.append(verosimilitud(x[0],xinicial))
#numero de pasos
iteraciones=100000
for i in range(iteraciones):
    a_otro=np.random.normal(acami[i],2.5)
    g_otro=np.random.normal(gammacami[i],2.5)
    o_otro=np.random.normal(gammacami[i],2.5)
    xinicial= funcion1(acami[i],gammacami[i],omegacami[i],t)
    xotro= funcion1(a_otro,g_otro,o_otro,t)
    
    linicial=verosimilitud(x,xinicial)
    lotro=verosimilitud(x,xotro)
    alfa= lotro/linicial
    if alfa>1.0:
            acami.append(a_otro)
            gammacami.append(g_otro)
            omegacami.append(o_otro)
            lcami.append(lotro)
            
    else:
        #como en el enunciado hago beta con distribucion normal
        beta=np.random.uniform(0,1,1)
        if beta<=alfa: 
            acami.append(a_otro)
            gammacami.append(g_otro)
            omegacami.append(o_otro)
            lcami.append(lotro)
        else:
            acami.append(acami[i])
            gammacami.append(gammacami[i])
            omegacami.append(omegacami[i])
            lcami.append(lcami[i])           
    

# 2d.) Seleccione los mejores parametros E IMPRIMA UN MENSAJE QUE DIGA: 
mejores= np.argmax(lcami)
print("LOS MEJORES PARAMETROS SON a=",acami[mejores],"gamma=", gammacami[mejores],"Y omgega=",omegacami[mejores])
# 2f.) Grafique sus datos originales y su modelo con los mejores parametros. Guarde su grafica sin mostrarla en Resorte.pdf
plt.figure()
plt.plot(t,x,label="original")
plt.plot(t,funcion1(acami[mejores],gammacami[mejores],omegacami[mejores],t),label="mejores")
plt.xlabel("t")
plt.ylabel("Pos")
plt.legend()
plt.title("grafica final")
plt.savefig("resortes.pdf")
# 3) SABIENDO QUE omega=np.sqrt(k/m), IMPRIMA UN MENSAJE DONDE EXPLIQUE SI PUEDE O NO DETERMINAR k Y m DE MANERA INDIVIDUAL USANDO EL METODO ANTERIOR. JUSTIFIQUE BIEN SU RESPUESTA (PUEDE ADEMAS HACER PRUEBAS CON EL CODIGO PARA RESPONDER ESTA PREGUNTA).
print("Considero que es posible ya que estaria usando dentro de omega k y m, ya que al ser incluidos dentro de la funcion que define omega estarian haciendo a estos como los mejores parametros.")


