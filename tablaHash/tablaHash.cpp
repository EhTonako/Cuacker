#include "tablaHash.h"
#include <iostream>
using namespace std;

TablaHash::TablaHash(){
    nElem = 0;
    M = 101;
    T = new list<Par>[M];
}

TablaHash::~TablaHash() { delete[] T; }


int TablaHash::hash(string& nombre) {
    unsigned long h = 0;
    for(char c : nombre)
        h = (h * 31 + c) % M;
    return h % M;
}

Cuac* TablaHash::insertar(Cuac cuac) 
{
    int idx = hash(cuac.usuario);

    for (Par &p : T[idx]) 
    {
        if (p.nombre == cuac.usuario) 
        {
            // 1. Comprobación de duplicados
            for (Cuac &c : p.lista) {
                if (c.fecha.esIgual(cuac.fecha) &&
                    c.usuario == cuac.usuario &&
                    c.texto   == cuac.texto) 
                {
                    return &c;  // ya existe → devolvemos su dirección REAL
                }
            }

            // 2. Insertar en orden
            auto it = p.lista.begin();
            while (it != p.lista.end()) {
                if (cuac.fecha.esMenor(it->fecha)) { ++it; continue; }
                if (it->fecha.esIgual(cuac.fecha) && cuac.texto > it->texto) {
                    ++it; continue;
                }
                break;
            }

            it = p.lista.insert(it, cuac);
            nElem++;
            return &(*it);     // ← ← PUNTERO REAL al Cuac recién insertado
        }
    }

    // 3. Crear nuevo Par si no existe
    Par nuevoPar;
    nuevoPar.nombre = cuac.usuario;
    nuevoPar.lista.push_back(cuac);
    T[idx].push_back(nuevoPar);
    nElem++;

    // Devolver puntero al único elemento de esa lista
    return &T[idx].back().lista.back();
}

list<Cuac> TablaHash::consultar(string nombre) {
    int idx = hash(nombre);
    for (Par &p : T[idx]) {
        if (p.nombre == nombre) {
            return p.lista;
        }
    }

    return list<Cuac>();
}



