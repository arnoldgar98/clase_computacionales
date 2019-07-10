otro.png: graficador.py datos.dat datos3.dat
	python graficador.py
datos.dat: GarciaArnoldS6C2.cpp
datos3.dat: GarciaArnoldS6C2.cpp
	g++ GarciaArnoldS6C2.cpp
	./a.out   
