#include <iostream>
#include <cstdio>  // Para printf
using namespace std;

class Fecha {
private:
    int dia, mes, ano;
    int hora, minuto, segundo;
public:
    Fecha();
    bool leerFecha();
    void escribirFecha();
    bool esMenor(const Fecha &otro);
    bool esIgual(const Fecha &otro);
};

Fecha::Fecha() {
    dia = mes = ano = hora = minuto = segundo = 0;
}

bool Fecha::leerFecha() {
    char c1, c2, c3, c4;
    if (!(cin >> dia >> c1 >> mes >> c2 >> ano >> hora >> c3 >> minuto >> c4 >> segundo)) {
        return false;
    }

    // Validamos separadores
    if (c1 != '/' || c2 != '/' || c3 != ':' || c4 != ':') return false;

    // Validamos rangos
    if (dia < 1 || dia > 31) return false;
    if (mes < 1 || mes > 12) return false;
    if (hora < 0 || hora > 23) return false;
    if (minuto < 0 || minuto > 59) return false;
    if (segundo < 0 || segundo > 59) return false;

    return true;
}

void Fecha::escribirFecha() {
    // Día, mes y año sin ceros a la izquierda
    cout << dia << "/" << mes << "/" << ano << " ";
    // Hora, minuto y segundo con ceros a la izquierda
    printf("%02d:%02d:%02d", hora, minuto, segundo);
}

bool Fecha::esIgual(const Fecha &otro) {
    return (ano == otro.ano &&
            mes == otro.mes &&
            dia == otro.dia &&
            hora == otro.hora &&
            minuto == otro.minuto &&
            segundo == otro.segundo);
}

bool Fecha::esMenor(const Fecha &otro) {
    if (ano != otro.ano) return ano < otro.ano;
    if (mes != otro.mes) return mes < otro.mes;
    if (dia != otro.dia) return dia < otro.dia;
    if (hora != otro.hora) return hora < otro.hora;
    if (minuto != otro.minuto) return minuto < otro.minuto;
    return segundo < otro.segundo;
}

int main() {
    int N;
    cin >> N;

    Fecha anterior, actual;

    for (int i = 0; i < N; ++i) {
        if (!actual.leerFecha()) return 1;

        if (i > 0) {
            actual.escribirFecha();

            if (actual.esIgual(anterior)) {
                cout << " ES IGUAL A ";
            } else if (actual.esMenor(anterior)) {
                cout << " ES ANTERIOR A ";
            } else {
                cout << " ES POSTERIOR A ";
            }

            anterior.escribirFecha();
            cout << endl;
        }

        anterior = actual;
    }

    return 0;
}