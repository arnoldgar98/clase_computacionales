# Ejercicio 1

import numpy as np
import matplotlib.pylab as plt


# Use esta funcion que recibe un valor x y retorna un valor f(x) donde f es la forma funcional que debe seguir su distribucion. 
def mifun(x):
    x_0 = 3.0
    a = 0.01
    return np.exp(-(x**2))/((x-x_0)**2 + a**2)
x=np.linspace(-4,4,100)
plt.figure()
plt.plot(x,mifun(x))
plt.savefig("distribucion")

# Dentro de una funcion que reciba como parametros el numero de pasos y el sigma de la distribucion gausiana que va a usar para calcular el paso de su caminata, implemente el algortimo de Metropolis-Hastings. Finalmente, haga un histograma de los datos obtenidos y grafique en la misma grafica, la funcion de distribucion de probabilidad fx (Ojo, aca debe normalizar). Guarde la grafica sin mostrarla en un pdf. Use plt.savefig("histograma_"+str(sigma)+"_"+str(pasos)+".pdf"), donde sigma y pasos son los parametros que recibe la funcion. 
##definimos el tamaño del paso
def fun(x0,sig):
    paso=[]
    #un aleatorio entre nuestros valores a evaluar, osea -4 y 4
    b=8*(np.random.random())-4
    paso.append(b)
    for i in range(x0):
        xguess=np.random.normal(paso[i],sig)
        #defino alfa como en el tablero el nuevo sobre el inicial generado en el paso
        alfa= mifun(xguess)/mifun(paso[i])
        #empiezo condiciones
        if alfa>1.0:
            paso.append(xguess)
        else:
            #como en el enunciado hago beta con distribucion normal
            beta=np.random.uniform(0,1,1)
            if beta<=alfa:
                paso.append(xguess)
            else:
                paso.append(paso[i])
           
    return paso            
#normalizacion con la integral                
a=-4
b=4
resIntegral=0
def integralRec(xguess1,m):
  
    ancho= (b-a)/m
    resIntegral = np.sum(ancho*mifun(xguess1)) 
    return resIntegral

plt.figure()
plt.plot(x,mifun(x)/integralRec(x,100))
plt.title("Sigma 0.01 pasos 100000")
plt.hist(fun(100000,0.01),bins=100,density=True)
plt.savefig("sigma1")

plt.figure()
plt.plot(x,mifun(x)/integralRec(x,100))
plt.title("Sigma 5 pasos 100000")
plt.hist(fun(100000,5),bins=100,density=True)
plt.savefig("sigma2")

plt.figure()
plt.plot(x,mifun(x)/integralRec(x,100))
plt.title("Sigma 0.2 pasos 100000")
plt.hist(fun(100000,0.2),bins=100,density=True)
plt.savefig("sigma3")

plt.figure()
plt.plot(x,mifun(x)/integralRec(x,100))
plt.title("Sigma 0.1 pasos 1000")
plt.hist(fun(1000,0.1),bins=100,density=True)
plt.savefig("sigma4")

plt.figure()
plt.plot(x,mifun(x)/integralRec(x,100))
plt.title("Sigma 0.1 pasos 100000")
plt.hist(fun(100000,0.1),bins=100,density=True)
plt.savefig("sigma5")


# Cuando haya verificado que su codigo funciona, use los siguientes parametros:
# sigma = 5, pasos =100000 
# sigma = 0.2, pasos =100000 
# sigma = 0.01, pasos =100000 
# sigma = 0.1, pasos =1000 
# sigma = 0.1, pasos =100000 
# este puede ser muy demorado dependiendo del computador: sigma = 0.1, pasos =500000 

# Al ejecutar el codigo, este debe generar 6 (o 5) graficas .pdf una para cada vez que se llama a la funcion.
