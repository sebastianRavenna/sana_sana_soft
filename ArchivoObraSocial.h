#pragma once
//#include <iostream>
//#include <cstring>
#include "ObraSocial.h"

class ArchivoObraSocial
{
    public:
        ArchivoObraSocial(const std::string &nombreArchivo="obraSocial.dat");

        ObraSocial leerObraSocial (int posicion);
        int buscarObraSocial(const std::string &nombreObraSocial);
        int contarRegistro();
        bool agregarRegistro(const ObraSocial &reg);
        bool leerRegistro(int posicion,ObraSocial &reg);
        bool modificarObraSocial (int posicion);
        bool listarOS();
        bool cambioEstado(const std::string nombreObraSocial,int posicion);

    private:
        std::string _nombreArchivo;
        int tamanioRegistro;
};


