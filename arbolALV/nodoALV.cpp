#include "nodoALV.h"
using namespace std;

NodoALV::NodoALV(Cuac* c) : fecha(c->fecha), izq(nullptr), der(nullptr), altura(1) {
    cuacs.push_back(c);
}

NodoALV::~NodoALV() {
    delete izq;
    delete der;
}

NodoALV* NodoALV::RSI() {
    if (!der) return this;
    NodoALV* y = der;
    der = y->izq;
    y->izq = this;

    altura = 1 + max(izq ? izq->altura : 0, der ? der->altura : 0);
    y->altura = 1 + max(y->izq ? y->izq->altura : 0, y->der ? y->der->altura : 0);
    return y;
}

NodoALV* NodoALV::RSD() {
    if (!izq) return this;
    NodoALV* x = izq;
    izq = x->der;
    x->der = this;

    altura = 1 + max(izq ? izq->altura : 0, der ? der->altura : 0);
    x->altura = 1 + max(x->izq ? x->izq->altura : 0, x->der ? x->der->altura : 0);
    return x;
}

NodoALV* NodoALV::RDI() {
    if (!der) return this;
    der = der->RSD();
    return RSI();
}

NodoALV* NodoALV::RDD() {
    if (!izq) return this;
    izq = izq->RSI();
    return RSD();
}
