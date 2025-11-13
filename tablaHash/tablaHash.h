#ifndef TABLAHASH
#define TABLAHASH

#include "../cuac/cuac.h"
#include <list>

// DISEÑAMOS UNA TABLA DE DISPERSIÓN ABIERTA VARIABLE
// INICIALIZAMOS CON M = 100
// CADA ENTRADA DE LA TABLA CONTIENE UNA LISTA DE PARES <NOMBRE, LISTA DE CUACS>

class TablaHash
{
private:
    class Par
    {
        friend class TablaHash;
        string nombre;
        list<Cuac> lista;
    };
    list<Par> *T;
    int M;
    int nElem;

public:
    TablaHash();
    ~TablaHash();
    int hash(string& nombre);
    void insertar(Cuac nuevo);
    void consultar(string nombre);
    int numElem(void) { return nElem; }
};

#endif