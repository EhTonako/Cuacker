#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

const int CANTIDAD_CODIFICACIONES = 30;

const string codificaciones[CANTIDAD_CODIFICACIONES] = {
    "Afirmativo.",
    "Negativo.",
    "Estoy de viaje en el extranjero.",
    "Muchas gracias a todos mis seguidores por vuestro apoyo.",
    "Enhorabuena, campeones!",
    "Ver las novedades en mi pagina web.",
    "Estad atentos a la gran exclusiva del siglo.",
    "La inteligencia me persigue pero yo soy mas rapido.",
    "Si no puedes convencerlos, confundelos.",
    "La politica es el arte de crear problemas.",
    "Donde estan las llaves, matarile, rile, rile...",
    "Si no te gustan mis principios, puedo cambiarlos por otros.",
    "Un dia lei que fumar era malo y deje de fumar.",
    "Yo si se lo que es trabajar duro, de verdad, porque lo he visto por ahi.",
    "Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas.",
    "Mi vida no es tan glamurosa como mi pagina web aparenta.",
    "Todo tiempo pasado fue anterior.",
    "El azucar no engorda... engorda el que se la toma.",
    "Solo los genios somos modestos.",
    "Nadie sabe escribir tambien como yo.",
    "Si le molesta el mas alla, pongase mas aca.",
    "Me gustaria ser valiente. Mi dentista asegura que no lo soy.",
    "Si el dinero pudiera hablar, me diria adios.",
    "Hoy me ha pasado una cosa tan increible que es mentira.",
    "Si no tienes nada que hacer, por favor no lo hagas en clase.",
    "Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon y salio una calabaza.",
    "Me despido hasta la proxima. Buen viaje!",
    "Cualquiera se puede equivocar, inclusivo yo.",
    "Estoy en Egipto. Nunca habia visto las piramides tan solas.",
    "El que quiera saber mas, que se vaya a Salamanca."
};

string decodificarTexto(int index) {
    if (index >= 1 && index <= CANTIDAD_CODIFICACIONES)
        return codificaciones[index - 1];
    return "";
}

class Fecha {
private:
    int dia, mes, ano;
    int hora, minuto, segundo;
public:
    Fecha();
    bool leerFecha();
    void escribirFecha() const;
    bool esMenor(const Fecha& otro) const;
    bool esIgual(const Fecha& otro) const;
};

Fecha::Fecha() {
    dia = mes = ano = hora = minuto = segundo = 0;
}

bool Fecha::leerFecha() {
    char c1, c2, c3, c4;
    if (!(cin >> dia >> c1 >> mes >> c2 >> ano >> hora >> c3 >> minuto >> c4 >> segundo)) {
        return false;
    }

    if (c1 != '/' || c2 != '/' || c3 != ':' || c4 != ':') return false;
    if (dia < 1 || dia > 31) return false;
    if (mes < 1 || mes > 12) return false;
    if (hora < 0 || hora > 23) return false;
    if (minuto < 0 || minuto > 59) return false;
    if (segundo < 0 || segundo > 59) return false;

    return true;
}

void Fecha::escribirFecha() const {
    cout << dia << "/" << mes << "/" << ano << " ";
    printf("%02d:%02d:%02d", hora, minuto, segundo);
}

bool Fecha::esIgual(const Fecha& otro) const {
    return (ano == otro.ano &&
            mes == otro.mes &&
            dia == otro.dia &&
            hora == otro.hora &&
            minuto == otro.minuto &&
            segundo == otro.segundo);
}

bool Fecha::esMenor(const Fecha& otro) const {
    if (ano != otro.ano) return ano < otro.ano;
    if (mes != otro.mes) return mes < otro.mes;
    if (dia != otro.dia) return dia < otro.dia;
    if (hora != otro.hora) return hora < otro.hora;
    if (minuto != otro.minuto) return minuto < otro.minuto;
    return segundo < otro.segundo;
}

class Cuac {
private:
    Fecha fecha;
    string usuario;
    string texto;
public:
    bool leer_mcuac();
    bool leer_pcuac();
    void escribir() const;
    bool es_anterior(const Cuac& otro) const;
};

bool Cuac::leer_mcuac() {
    cin >> usuario;
    if (!fecha.leerFecha()) return false;
    cin.ignore();
    getline(cin, texto);
    return true;
}

bool Cuac::leer_pcuac() {
    int index;
    cin >> usuario;
    if (!fecha.leerFecha()) return false;
    cin >> index;
    texto = decodificarTexto(index);
    return true;
}

void Cuac::escribir() const {
    cout << usuario << " ";
    fecha.escribirFecha();
    cout << "\n   " << texto << endl;
}

bool Cuac::es_anterior(const Cuac& otro) const {
    if (!fecha.esIgual(otro.fecha)) return !fecha.esMenor(otro.fecha);
    if (texto != otro.texto) return texto < otro.texto;
    return usuario < otro.usuario;
}

int main() {
    int num = 0;
    string comando;

    while (cin >> comando) {
        Cuac cuac;
        if (comando == "mcuac") {
            if (!cuac.leer_mcuac()) break;
        } else if (comando == "pcuac") {
            if (!cuac.leer_pcuac()) break;
        }
        cout << ++num << " cuac" << endl;
        cuac.escribir();
    }

    return 0;
}