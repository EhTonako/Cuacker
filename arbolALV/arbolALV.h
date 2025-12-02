#ifndef ARBOLALV
#define ARBOLALV
#include "../cuac/cuac.h"
#include "nodoALV.h"
#include <iostream>

class ArbolALV {
private:
    NodoALV* raiz;

    void RSI(NodoALV*& A) { A = A->RSI(); }
    void RSD(NodoALV*& A) { A = A->RSD(); }
    void RDI(NodoALV*& A) { A = A->RDI(); }
    void RDD(NodoALV*& A) { A = A->RDD(); }

    int altura(NodoALV* n) { return n ? n->altura : 0; }
    int balance(NodoALV* n) { return n ? altura(n->izq) - altura(n->der) : 0; }

    void insertarNodo(NodoALV*& nodo, Cuac* c);
    void lastRec(NodoALV* n, int& faltan, list<Cuac>& resultado);
    void dateRec(NodoALV* n, Fecha& f1, Fecha& f2, list<Cuac>& resultado);

public:
    ArbolALV() : raiz(nullptr) {}
    ~ArbolALV() { delete raiz; }

    void insertar(Cuac* c);
    list<Cuac> last(int N);
    list<Cuac> date(Fecha f1, Fecha f2);
};
#endif
