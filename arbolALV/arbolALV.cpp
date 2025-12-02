#include "arbolALV.h"
#include <algorithm>
using namespace std;

void ArbolALV::insertarNodo(NodoALV*& nodo, Cuac* c) {
    if (!nodo) {
        nodo = new NodoALV(c);
        return;
    }

    if (c->fecha.esMenor(nodo->fecha)) {
        insertarNodo(nodo->izq, c);
    }
    else if (nodo->fecha.esMenor(c->fecha)) {
        insertarNodo(nodo->der, c);
    }
    else {
        auto it = nodo->cuacs.begin();
        while (it != nodo->cuacs.end()) {
            Cuac* actual = *it;

            if (actual->texto > c->texto)
                break;

            if (actual->texto == c->texto &&
                actual->usuario > c->usuario)
                break;

            ++it;
        }

        nodo->cuacs.insert(it, c);
        return;
    }

    nodo->altura = 1 + max(altura(nodo->izq), altura(nodo->der));
    int bf = balance(nodo);

    if (bf > 1 && nodo->izq && c->fecha.esMenor(nodo->izq->fecha)) RSD(nodo);
    else if (bf < -1 && nodo->der && nodo->der->fecha.esMenor(c->fecha)) RSI(nodo);
    else if (bf > 1 && nodo->izq && nodo->izq->fecha.esMenor(c->fecha)) RDI(nodo);
    else if (bf < -1 && nodo->der && c->fecha.esMenor(nodo->der->fecha)) RDD(nodo);
    
}

void ArbolALV::insertar(Cuac* cuac) {
    insertarNodo(raiz, cuac);
}

void ArbolALV::lastRec(NodoALV* n, int& faltan, list<Cuac>& resultado) {
    if (!n || faltan == 0) return;

    lastRec(n->der, faltan, resultado);

    for (Cuac* c : n->cuacs) {
        if (faltan == 0) break;
        resultado.push_back(*c);
        faltan--;
    }

    lastRec(n->izq, faltan, resultado);
}

list<Cuac> ArbolALV::last(int N) {
    list<Cuac> resultado;
    int faltan = N;
    lastRec(raiz, faltan, resultado);
    return resultado;
}

void ArbolALV::dateRec(NodoALV* n, Fecha& f1, Fecha& f2, list<Cuac>& resultado) {
    if (!n) return;

    // n->fecha es más antigua que f1  → descartar izquierda
    if (n->fecha.esMenor(f1)) {
        dateRec(n->der, f1, f2, resultado);
        return;
    }

    // f2 es más antigua que n->fecha → descartar derecha
    if (f2.esMenor(n->fecha)) {
        dateRec(n->izq, f1, f2, resultado);
        return;
    }

    // Está dentro del rango → recorrer en orden descendente
    dateRec(n->der, f1, f2, resultado);

    for (Cuac* c : n->cuacs) {
        if ((f1.esMenor(c->fecha) || f1.esIgual(c->fecha)) &&
            (c->fecha.esMenor(f2) || c->fecha.esIgual(f2))) {
            resultado.push_back(*c);
        }
    }

    dateRec(n->izq, f1, f2, resultado);
}

list<Cuac> ArbolALV::date(Fecha f1, Fecha f2) {
    list<Cuac> resultado;
    dateRec(raiz, f1, f2, resultado);
    return resultado;
}
