#pragma once
#include <cstring>
#include <string>
class ObraSocial{
    private:
        int _idObraSocial;
        char _nombreObraSocial[30];
        bool _estado;

    public:
        ObraSocial();

        void cargar();
        void mostrar();
        bool escribir();
        bool leer();
        int getIdObraSocial();
        std::string getNombreObraSocial()const;
        bool getEstado();
        void setIdObraSocial(int);
        void setNombreObraSocial(const std::string &nombreOS);
        void setEstado(bool);


};
