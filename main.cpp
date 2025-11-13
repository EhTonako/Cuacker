#include "cuac/cuac.h"
#include "diccionarioCuacs/diccionarioCuacs.h"
#include "fecha/fecha.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;


DiccionarioCuacs dic;
Cuac cuac;
list<Cuac> lista;

void imprimirListadoCuacs() {
    int contador = 1;
    list<Cuac>::iterator it;
    for (it = lista.begin(); it != lista.end(); it++) {
        cout << contador << ". ";
        it->escribir();
        contador++;
    }
    cout << "Total: " << lista.size() << " cuac" << endl;
}

void procesar_pcuac()
{
    Cuac nuevo;
    nuevo.leer_pcuac();
    dic.insertar(nuevo);
    cout << dic.numElem() << " cuac" << endl;
}

void procesar_mcuac()
{
    Cuac nuevo;
    nuevo.leer_mcuac();
    dic.insertar(nuevo);
    cout << dic.numElem() << " cuac" << endl;
}

// void procesar_last() {
//     int N;
//     if (!(cin >> N)) return;
//     cout << "last " << N << endl;
//     lista = dic.last(N);
//     imprimirListadoCuacs();
// }

void procesar_follow() {
    string nombre;
    cin >> nombre;
    cout << "follow " << nombre << endl;
    lista = dic.follow(nombre);
    imprimirListadoCuacs();
}

// void procesar_date() {
//     Fecha fmin, fmax;
//     if (!fmin.leerFecha()) return;
//     if (!fmax.leerFecha()) return;
//     cout << "date ";
//     fmin.escribirFecha(); cout << " ";
//     fmax.escribirFecha(); cout << endl;
//     lista = dic.date(fmin, fmax);
//     imprimirListadoCuacs();
// }


int main()
{
    string comando;

    while (cin >> comando)
    {
        if (comando == "exit") break;
        if (comando == "mcuac") procesar_mcuac();
        if (comando=="pcuac") procesar_pcuac();
        // if (comando == "last") procesar_last();
        if (comando == "follow") procesar_follow();
        // if (comando == "date") procesar_date();        
    }

    return 0;
}