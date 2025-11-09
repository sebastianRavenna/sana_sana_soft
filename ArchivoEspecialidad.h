#pragma once
#include <string>
#include "Especialidad.h"

class ArchivoEspecialidad
{
    public:
        ArchivoEspecialidad(const std::string &nombreArchivo="especialidad.dat");
        Especialidad leerRegistro(int pos);
        bool agregarRegistro(const Especialidad &reg);
        bool leerRegistro(int posicion,Especialidad &reg);
        bool modificarRegistro(Especialidad &reg,int pos);
        int buscarRegistro(int codEspecialidad); ///no se si el parametro esta bien puesto
        int contarRegistros();
        bool bajaLogica(int codEspecialidad);
        bool altaLogica(int codEspecialidad);


    private:
     std::string _nombreArchivo;
     int tamanioRegistro;


};


