#ifndef DICCIONARIOCUACS
#define DICCIONARIOCUACS

#include "../cuac/cuac.h"
#include <list>


class DiccionarioCuacs {
    private:
        list<Cuac> cuacs;
        int contador;
    public:
        DiccionarioCuacs();
        void insertar(Cuac nuevo);
        list<Cuac> last(int N);
        list<Cuac> follow(string nombre);
        list<Cuac> date(Fecha f1, Fecha f2);
        int numElem() {
            return contador;
        }
};

#endif