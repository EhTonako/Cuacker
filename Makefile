# Estamos guardando dentro de sus respectivas carpetas los .o generados cuando hacemos el "make";
# De esta forma mantenemos el codigo mucho mas legible y ordenado para poder escalar más facilmente el proyecto;
# -> Para ejecutar el programa hay que realizar los siguientes pasos:
#	0) Si estamos en windows activamos la virtualización: "wls"
#	1) Generamos el ejecutable: "make"
#	2) Para realizar pruebas hacemos: "./a.out"
#		2.1) Para obtener la salida introduciendo unos valores de entrada: "./a.out < pruebas/301a.in > pruebas/salida"
#		2.2) Para comparar las salidas obtenida y la deseada: "diff pruebas/301a.out pruebas/salida > pruebas/diferencias"
#	3) Para realizar la funcion tar ahora tenemos que añadir lo siguiente para leer dentro de las carpetas: 
# 		"tar -cf archivo.tar main.cpp Makefile $(find . -type f \( -name "*.cpp" -o -name "*.h" \))"

a.out: main.o cuac/cuac.o diccionarioCuacs/diccionarioCuacs.o fecha/fecha.o tablaHash/tablaHash.o arbolALV/arbolALV.o arbolALV/nodoALV.o
	g++ main.o cuac/cuac.o diccionarioCuacs/diccionarioCuacs.o fecha/fecha.o tablaHash/tablaHash.o arbolALV/arbolALV.o arbolALV/nodoALV.o -o a.out

cuac/cuac.o: cuac/cuac.cpp cuac/cuac.h fecha/fecha.h
	g++ -c cuac/cuac.cpp -o cuac/cuac.o

diccionarioCuacs/diccionarioCuacs.o: diccionarioCuacs/diccionarioCuacs.cpp diccionarioCuacs/diccionarioCuacs.h cuac/cuac.h fecha/fecha.h tablaHash/tablaHash.h arbolALV/arbolALV.h
	g++ -c diccionarioCuacs/diccionarioCuacs.cpp -o diccionarioCuacs/diccionarioCuacs.o

tablaHash/tablaHash.o: tablaHash/tablaHash.cpp tablaHash/tablaHash.h cuac/cuac.h
	g++ -c tablaHash/tablaHash.cpp -o tablaHash/tablaHash.o

arbolALV/arbolALV.o: arbolALV/arbolALV.cpp arbolALV/arbolALV.h arbolALV/nodoALV.h cuac/cuac.h
	g++ -c arbolALV/arbolALV.cpp -o arbolALV/arbolALV.o

arbolALV/nodoALV.o: arbolALV/nodoALV.cpp arbolALV/nodoALV.h cuac/cuac.h
	g++ -c arbolALV/nodoALV.cpp -o arbolALV/nodoALV.o

fecha/fecha.o: fecha/fecha.cpp fecha/fecha.h
	g++ -c fecha/fecha.cpp -o fecha/fecha.o

main.o: main.cpp cuac/cuac.h diccionarioCuacs/diccionarioCuacs.h fecha/fecha.h arbolALV/arbolALV.h tablaHash/tablaHash.h
	g++ -c main.cpp -o main.o

clean:
	rm -f main.o cuac/cuac.o diccionarioCuacs/diccionarioCuacs.o fecha/fecha.o tablaHash/tablaHash.o arbolALV/arbolALV.o arbolALV/nodoALV.o a.out