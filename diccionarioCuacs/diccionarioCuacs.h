#ifndef DICCIONARIOCUACS
#define DICCIONARIOCUACS

#include "../cuac/cuac.h"
#include "../tablaHash/tablaHash.h"
#include "../arbolALV/arbolALV.h"
#include <list>

class DiccionarioCuacs
{
private:
    TablaHash tabla;
    ArbolALV arbol;

public:
    // DiccionarioCuacs();
    //-> SI SE PUEDE QUITAR EL CONSTRUCTOR DADO QUE
    // TABLAHASH TIENE UNO POR DEFECTO Y SE INVOCA AUTOMÁTICAMENTE
    ~DiccionarioCuacs(){
        // El destructor de TablaHash se invoca automáticamente
        // El destructor de ArbolALV se invoca automáticamente
    };

    void insertar(Cuac nuevo)
    {
        Cuac *ref = tabla.insertar(nuevo);
        arbol.insertar(ref);
    };
    list<Cuac> follow(string nombre)
    {
        return tabla.consultar(nombre);
    };
    list<Cuac> last(int N)
    {
        return arbol.last(N);
    }
    list<Cuac> date(Fecha f1, Fecha f2)
    {
        return arbol.date(f1, f2);
    }
    int numElem()
    {
        return tabla.numElem();
    }
};

#endif