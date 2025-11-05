#ifndef CUAC
#define CUAC

#include <iostream>
#include <string>
#include "../fecha/fecha.h"
using namespace std;


class Cuac {
    friend class DiccionarioCuacs;
    private:
        Fecha fecha;
        string usuario;
        string texto;
    public:
        bool leer_mcuac();
        bool leer_pcuac();
        void escribir();
        bool es_anterior(Cuac& otro);
};

#endif