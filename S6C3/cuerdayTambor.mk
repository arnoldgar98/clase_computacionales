inicial.png: plots_cuerdayTambor.py datos.dat datos1.dat datos2.dat
extremosfijos.png: plots_cuerdayTambor.py datos1.dat
extremoslibres.png: plots_cuerdayTambor.py datos2.dat
extremosvariables.png: plots_cuerdayTambor.py datos3.dat
	python plots_cuerdayTambor.py
datos.dat: GarciaArnold_cuerdayTambor.cpp
datos1.dat: GarciaArnold_cuerdayTambor.cpp
datos2.dat: GarciaArnold_cuerdayTambor.cpp
datos3.dat: GarciaArnold_cuerdayTambor.cpp
	g++ GarciaArnold_cuerdayTambor.cpp
	./a.out   
