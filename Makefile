# Estamos guardando dentro de sus respectivas carpetas los .o generados cuando hacemos el "make";
# De esta forma mantenemos el codigo mucho mas legible y ordenado para poder escalar más facilmente el proyecto;
# Para realizar la funcion tar ahora tenemos que añadir lo siguiente para leer dentro de las carpetas: 
# 	"tar -cf archivo.tar main.cpp Makefile $(find . -type f \( -name "*.cpp" -o -name "*.h" \))"

a.out: main.o cuac/cuac.o diccionarioCuacs/diccionarioCuacs.o fecha/fecha.o tablaHash/tablaHash.o arbolALV/arbolALV.o arbolALV/nodoALV.o
	g++ main.o cuac/cuac.o diccionarioCuacs/diccionarioCuacs.o fecha/fecha.o tablaHash/tablaHash.o arbolALV/arbolALV.o arbolALV/nodoALV.o -o a.out

cuac.o: cuac/cuac.cpp cuac/cuac.h fecha/fecha.h
	g++ -c cuac/cuac.cpp -o cuac/cuac.o

diccionarioCuacs.o: diccionarioCuacs/diccionarioCuacs.cpp diccionarioCuacs/diccionarioCuacs.h cuac/cuac.h fecha/fecha.h tablaHash/tablaHash.h arbolALV/arbolALV.h
	g++ -c diccionarioCuacs/diccionarioCuacs.cpp -o diccionarioCuacs/diccionarioCuacs.o

tablaHash.o: tablaHash/tablaHash.cpp tablaHash/tablaHash.h cuac/cuac.h
	g++ -c tablaHash/tablaHash.cpp -o tablaHash/tablaHash.o

arbolALV.o: arbolALV/arbolALV.cpp arbolALV/arbolALV.h cuac/cuac.h arbolALV/nodoALV.h
	g++ -c arbolALV/arbolALV.cpp -o arbolALV/arbolALV.o

nodoALV.o: arbolALV/nodoALV.cpp arbolALV/nodoALV.h cuac/cuac.h
	g++ -c arbolALV/nodoALV.cpp -o arbolALV/nodoALV.o

fecha.o: fecha/fecha.cpp fecha/fecha.h
	g++ -c fecha/fecha.cpp -o fecha/fecha.o

main.o: main.cpp cuac/cuac.h diccionarioCuacs/diccionarioCuacs.h fecha/fecha.h
	g++ -c main.cpp -o main.o