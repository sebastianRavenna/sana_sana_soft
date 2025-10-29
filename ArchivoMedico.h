#pragma once
#include <string>
#include "Medico.h"


class ArchivoMedico
{
    public:
        ArchivoMedico(const std::string &nombreArchivo="medico.dat");
        Medico leerRegistro(int pos);
        bool leerRegistro(int posicion,Medico &reg);
        bool agregarRegistro(const Medico &reg);
        bool modificarRegistro(Medico &reg, int posicion);
        int buscarRegistro(int idMedico);
        int contarRegistro();
        bool bajaLogica(int idMedico);
        bool altaLogica(int idMedico);



    private:
        std::string _nombreArchivo;
        int tamanioRegistro;
};


