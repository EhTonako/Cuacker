#ifndef DICCIONARIOCUACS
#define DICCIONARIOCUACS

#include "../cuac/cuac.h"
#include "../tablaHash/tablaHash.h"
#include <list>

class DiccionarioCuacs
{
private:
    TablaHash tabla;

public:
    DiccionarioCuacs(); 
    //-> SI SE PUEDE QUITAR EL CONSTRUCTOR DADO QUE
    // TABLAHASH TIENE UNO POR DEFECTO Y SE INVOCA AUTOMÁTICAMENTE
    void insertar(Cuac nuevo)
    {
        tabla.insertar(nuevo);
    };
    list<Cuac> follow(string nombre)
    {
        return tabla.consultar(nombre);
    };
    int numElem()
    {
        return tabla.numElem();
    }
};

#endif