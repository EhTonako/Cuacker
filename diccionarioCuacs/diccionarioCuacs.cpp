#include "diccionarioCuacs.h"
#include <iostream>
using namespace std;

DiccionarioCuacs::DiccionarioCuacs(){
    contador = 0;
}
void DiccionarioCuacs::insertar(Cuac nuevo) {
    // Recorremos el bucle para comprobar si ya existe exactamente
    list<Cuac>::iterator itCheck;
    for (itCheck = cuacs.begin(); itCheck != cuacs.end(); ++itCheck) {
        if (itCheck->fecha.esIgual(nuevo.fecha) &&
            itCheck->usuario == nuevo.usuario &&
            itCheck->texto == nuevo.texto) {
            return; // No insertamos el dato duplicado
        }
    }

    contador++;

    // Recorremos el bucle para buscar la posición correcta
    list<Cuac>::iterator it = cuacs.begin();
    while (it != cuacs.end()) {
        // Comparamos las fechas
        if (nuevo.fecha.esMenor(it->fecha)) {
            // Si el nuevo es más antiguo, seguimos recorriendo el listado
            ++it; 
            continue;
        } else if (it->fecha.esIgual(nuevo.fecha)) {
            // Comparamos el texto alfabéticamente
            if (nuevo.texto > it->texto) {
                ++it;
                continue;
            } else if (nuevo.texto == it->texto) {
                // Comparamos el nombre de usuario alfabéticamente
                if (nuevo.usuario > it->usuario) {
                    ++it;
                    continue;
                }
            }
        }
        // Al tener la posición correcta salimos del bucle;
        break;
    }

    cuacs.insert(it, nuevo);
}



list<Cuac> DiccionarioCuacs::last(int N) {
    list<Cuac> listado;
    int contador = 0;

    for (auto it = cuacs.begin(); it != cuacs.end() && contador < N; ++it, ++contador)
        listado.push_back(*it);

    return listado;
}

list<Cuac> DiccionarioCuacs::follow(string nombre) {
    list<Cuac> listado;
    list<Cuac>::iterator it;
    for (it = cuacs.begin(); it != cuacs.end(); it++) {
        if (it->usuario == nombre) listado.push_back(*it);
    }
    return listado;
}

list<Cuac> DiccionarioCuacs::date(Fecha f1, Fecha f2) {
    list<Cuac> listado;
    for (auto it = cuacs.begin(); it != cuacs.end(); ++it) {
        if (!f2.esMenor(it->fecha) && !it->fecha.esMenor(f1))
            listado.push_back(*it);
    }
    return listado;
}

   