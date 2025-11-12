# Estamos guardando dentro de sus respectivas carpetas los .o generados cuando hacemos el "make";
# De esta forma mantenemos el codigo mucho mas legible y ordenado para poder escalar más facilmente el proyecto;
# Para realizar la funcion tar ahora tenemos que añadir lo siguiente para leer dentro de las carpetas: 
# 	"tar -cf archivo.tar main.cpp Makefile $(find . -type f \( -name "*.cpp" -o -name "*.h" \))"

a.out: main.o cuac/cuac.o diccionarioCuacs/diccionarioCuacs.o fecha/fecha.o
	g++ main.o cuac/cuac.o diccionarioCuacs/diccionarioCuacs.o fecha/fecha.o -o a.out

cuac.o: cuac/cuac.cpp cuac/cuac.h fecha/fecha.h
	g++ -c cuac/cuac.cpp -o cuac/cuac.o

diccionarioCuacs.o: diccionarioCuacs/diccionarioCuacs.cpp diccionarioCuacs/diccionarioCuacs.h cuac/cuac.h fecha/fecha.h
	g++ -c diccionarioCuacs/diccionarioCuacs.cpp -o diccionarioCuacs/diccionarioCuacs.o

fecha.o: fecha/fecha.cpp fecha/fecha.h
	g++ -c fecha/fecha.cpp -o fecha/fecha.o

main.o: main.cpp cuac/cuac.h diccionarioCuacs/diccionarioCuacs.h fecha/fecha.h
	g++ -c main.cpp -o main.o