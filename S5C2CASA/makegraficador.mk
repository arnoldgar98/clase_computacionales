euleryrunge.pdf: plotgrafica.py datos.dat datos.dat2
	python plotgrafica.py
datos.dat: GarciaArnoldS5C2casa.cpp
datos.dat2: GarciaArnoldS5C2casa.cpp 
	g++ GarciaArnoldS5C2casa.cpp
	./a.out   
