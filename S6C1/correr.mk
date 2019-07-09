GarciaArnoldResorte.png: graficador.py datos.dat datos2.dat
	python graficador.py
datos.dat: S6C1_PDEss.cpp
datos2.dat: S6C1_PDEss.cpp
	g++ S6C1_PDEss.cpp
	./a.out   
