#include "fecha.h"
#include <iostream>
using namespace std;


bool Fecha::leerFecha() {
    char c1, c2, c3, c4;
    if (!(cin >> dia >> c1 >> mes >> c2 >> ano >> hora >> c3 >> minuto >> c4 >> segundo)) return false;
    if (c1 != '/' || c2 != '/' || c3 != ':' || c4 != ':') return false;
    
    if (dia < 1 || dia > 31) return false;
    if (mes < 1 || mes > 12) return false;
    if (hora < 0 || hora > 23) return false;
    if (minuto < 0 || minuto > 59) return false;
    if (segundo < 0 || segundo > 59) return false;

    return true;
}

void Fecha::escribirFecha(){
    cout << this-> dia << "/" << this->mes << "/" << this->ano << " " << this->hora << ":" << this->minuto << ":" << this->segundo << endl;
}

bool Fecha::esIgual(Fecha &otro){
    return (otro.ano == this->ano &&
    otro.mes == this->mes &&
    otro.dia == this->dia &&
    otro.hora == this->hora &&
    otro.minuto == this->minuto &&
    otro.segundo == this->segundo);
}

bool Fecha::esMenor(Fecha &otro){
    if (this->esIgual(otro))
        return false;
    if (otro.ano != this->ano) return otro.ano < this->ano;
    if (otro.mes != this->mes) return otro.mes < this->mes;
    if (otro.dia != this->dia) return otro.dia < this->dia;
    if (otro.hora != this->hora) return otro.hora < this->hora;
    if (otro.minuto != this->minuto) return otro.minuto < this->minuto;
    if (otro.segundo != this->segundo) return otro.segundo < this->segundo;
}
    
Fecha::Fecha(){
    this->dia = 0;
    this->mes = 0;
    this->ano = 0;
    this->hora = 0;
    this->minuto = 0;
    this->segundo = 0;
}