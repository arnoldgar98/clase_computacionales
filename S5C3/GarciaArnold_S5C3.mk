GarciaArnoldResorte.pdf: GarciaArnold_S5C3_plots.py datos.dat
	python GarciaArnold_S5C3_plots.py
datos.dat: GarciaArnold_S5C3_ODEs.cpp
	g++ GarciaArnold_S5C3_ODEs.cpp
	./a.out   
