#include "tablaHash.h"
#include <iostream>
using namespace std;

TablaHash::TablaHash(){
    nElem = 0;
    M = 1009;
    T = new list<Par>[M];
}

TablaHash::~TablaHash() { delete[] T; }


int TablaHash::hash(const string nombre) const {
    unsigned long h = 0;
    for(char c : nombre)
        h = (h * 31 + c) % M;
    return h % M;
}

Cuac* TablaHash::insertar(Cuac cuac) 
{
    int idx = hash(cuac.usuario);

    // 1. Buscar el usuario (Par) manteniendo la lista de la cubeta ordenada alfabéticamente
    auto itPar = T[idx].begin();
    while (itPar != T[idx].end() && itPar->nombre < cuac.usuario) {
        ++itPar;
    }

    // Si el usuario no existe, creamos el Par e insertamos en itPar para mantener orden
    if (itPar == T[idx].end() || itPar->nombre != cuac.usuario) {
        Par nuevoPar;
        nuevoPar.nombre = cuac.usuario;
        itPar = T[idx].insert(itPar, nuevoPar); 
    }

    // 2. Comprobar si el Cuac es duplicado (mismo usuario, fecha y texto)
    for (Cuac &c : itPar->lista) {
        if (c.fecha.esIgual(cuac.fecha) && c.texto == cuac.texto && c.usuario == cuac.usuario) {
            return &c; 
        }
    }

    // 3. Insertar el Cuac en su lista siguiendo los 3 criterios de ordenación:
    //    Criterio A: De más reciente a más antiguo (Fecha DESC)
    //    Criterio B: Empate fecha -> Alfabético texto (Texto ASC)
    //    Criterio C: Empate fecha y texto -> Alfabético usuario (Usuario ASC)
    auto itCuac = itPar->lista.begin();
    while (itCuac != itPar->lista.end()) {
        // Si el nuevo es más antiguo que el actual, seguimos buscando (va después)
        if (cuac.fecha.esMenor(itCuac->fecha)) {
            ++itCuac;
        } 
        // Si tienen la misma fecha, desempatamos por texto (menor a mayor)
        else if (cuac.fecha.esIgual(itCuac->fecha)) {
            if (cuac.texto > itCuac->texto) {
                ++itCuac;
            }
            // Si el texto es igual, desempatamos por usuario (menor a mayor)
            else if (cuac.texto == itCuac->texto && cuac.usuario > itCuac->usuario) {
                ++itCuac;
            }
            else break;
        } 
        else break; // El nuevo es más reciente, se inserta aquí
    }

    itCuac = itPar->lista.insert(itCuac, cuac);
    nElem++;
    return &(*itCuac);
}

list<Cuac> TablaHash::consultar(string nombre) {
    int idx = hash(nombre);
    for (Par &p : T[idx]) {
        if (p.nombre == nombre) {
            return p.lista;
        }

        // Si el nombre actual es mayor al que buscamos salimos.
        if (p.nombre > nombre) break;
    }

    return list<Cuac>();
}