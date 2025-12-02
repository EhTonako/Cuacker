
#ifndef NODOALV
#define NODOALV

#include "../cuac/cuac.h"
#include <list>
#include <algorithm>

class ArbolALV;

class NodoALV {
private:
    Fecha fecha;
    std::list<Cuac*> cuacs;
    NodoALV* izq;
    NodoALV* der;
    int altura;

public:
    NodoALV(Cuac* c);
    ~NodoALV();

    NodoALV* RSI();
    NodoALV* RSD();
    NodoALV* RDI();
    NodoALV* RDD();

    friend class ArbolALV;
};

#endif