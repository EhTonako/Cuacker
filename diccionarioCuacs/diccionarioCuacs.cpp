#include "diccionarioCuacs.h"
#include <iostream>
using namespace std;

DiccionarioCuacs::DiccionarioCuacs(){
    contador = 0;
}
void DiccionarioCuacs::insertar(Cuac nuevo) {
    contador++;
    cuacs.push_back(nuevo);
}

list<Cuac> DiccionarioCuacs::last(int N) {
    if (cuacs.size() <= N) return cuacs;

    list<Cuac> listado;
    int avance = cuacs.size() - N;

    list<Cuac>::iterator it;
    for (it = cuacs.begin(); it != cuacs.end(); it++) {
        if (avance > 0) {
            avance--;
        } else {
            listado.push_back(*it);
        }
    }
    return listado;
}

list<Cuac> DiccionarioCuacs::follow (string nombre){
    int contador_aux = 0;
    list<Cuac> listado;

    list<Cuac>::iterator it;
    for (it = cuacs.begin(); it != cuacs.end(); it++) {
        if (it->usuario == nombre) listado.push_back(*it);
    }
    return listado;
}

list<Cuac> DiccionarioCuacs::date (Fecha f1, Fecha f2){
    list<Cuac> listado;
    list<Cuac>::iterator it;
    for (it = cuacs.begin(); it != cuacs.end(); it++) {
        if (it->fecha.esMenor(f2) || f1.esMenor(it->fecha)) listado.push_back(*it);
    }
    return listado;
}

   