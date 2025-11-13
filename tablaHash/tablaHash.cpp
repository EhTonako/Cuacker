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


void TablaHash::insertar(Cuac cuac) {
    int idx = hash(cuac.usuario);
    for (Par &p : T[idx]) {
        if (p.nombre == cuac.usuario) {
           {
                // Recorremos el bucle para comprobar si ya existe exactamente
                list<Cuac>::iterator itCheck;
                for (itCheck = p.lista.begin(); itCheck != p.lista.end(); ++itCheck) {
                    if (itCheck->fecha.esIgual(cuac.fecha) &&
                        itCheck->usuario == cuac.usuario &&
                        itCheck->texto == cuac.texto) {
                        return; // No insertamos el dato duplicado
                    }
                }
                // Recorremos el bucle para buscar la posición correcta
                list<Cuac>::iterator it = p.lista.begin();
                while (it != p.lista.end()) {
                    // Comparamos las fechas
                    if (cuac.fecha.esMenor(it->fecha)) {
                        // Si el nuevo es más antiguo, seguimos recorriendo el listado
                        ++it; 
                        continue;
                    } else if (it->fecha.esIgual(cuac.fecha)) {
                        // Comparamos el texto alfabéticamente
                        if (cuac.texto > it->texto) {
                            ++it;
                            continue;
                        } else if (cuac.texto == it->texto) {
                            // Comparamos el nombre de usuario alfabéticamente
                            if (cuac.usuario > it->usuario) {
                                ++it;
                                continue;
                            }
                        }
                    }
                    // Al tener la posición correcta salimos del bucle;
                    break;
                }

                p.lista.insert(it, cuac);
                nElem++;
            }
        }
    }
    // SI NO SE ENCUENTRA, CREAMOS UN NUEVO PAR
    Par nuevoPar;
    nuevoPar.nombre = cuac.usuario;
    nuevoPar.lista.push_back(cuac);
    T[idx].push_back(nuevoPar);
    nElem++;
}


void TablaHash::consultar(string nombre) {
    int idx = hash(nombre);
    for (Par &p : T[idx]) {
        if (p.nombre == nombre) {
            int contador = 1;
            for (Cuac cuac : p.lista) {
                cout << contador << ". ";
                cuac.escribir();
                contador++;
            }
        }
    }
}


