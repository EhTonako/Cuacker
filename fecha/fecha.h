#ifndef FECHA
#define FECHA

#include <iostream>

class Fecha {

    private:
        int dia, mes, ano;
        int hora, minuto, segundo;
    public:
        Fecha();
        bool leerFecha();
        void escribirFecha();
        bool esMenor(Fecha &otro);
        bool esIgual(Fecha &otro);
};


#endif