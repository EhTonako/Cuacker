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

bool Fecha::esIgual(Fecha &otro){
    return (otro.ano == this->ano &&
    otro.mes == this->mes &&
    otro.dia == this->dia &&
    otro.hora == this->hora &&
    otro.minuto == this->minuto &&
    otro.segundo == this->segundo);
}

void Fecha::escribirFecha() {
    cout << dia << "/";
    cout << mes << "/";
    cout << ano << " ";
    if (hora < 10) cout << "0"; cout << hora << ":";
    if (minuto < 10) cout << "0"; cout << minuto << ":";
    if (segundo < 10) cout << "0"; cout << segundo;
}

bool Fecha::esMenor(Fecha &otro) {
    if (this->esIgual(otro)) return false;
    if (ano != otro.ano) return ano < otro.ano;
    if (mes != otro.mes) return mes < otro.mes;
    if (dia != otro.dia) return dia < otro.dia;
    if (hora != otro.hora) return hora < otro.hora;
    if (minuto != otro.minuto) return minuto < otro.minuto;
    if (segundo != otro.segundo) return segundo < otro.segundo;
    return false;
}


    
Fecha::Fecha(){
    this->dia = 0;
    this->mes = 0;
    this->ano = 0;
    this->hora = 0;
    this->minuto = 0;
    this->segundo = 0;
}