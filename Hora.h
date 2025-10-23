#pragma once
#include <string>


class Hora{
    private:
    int _hora, _minuto;

    public:
    Hora();
    Hora(int hora, int minuto);
    void Cargar();
    void Mostrar();
    int getHora();
    int getMinuto();
    void setHora(int hora);
    void setMinuto(int minuto);
    std::string toString();
};
