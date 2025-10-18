#pragma once
#include <string>
#include "Persona.h"



class ArchivoPersona
{
    public:
        ArchivoPersona(const std::string &nombreArchivo="personas.dat");
        bool escribir (const Persona &p);
        bool leer (int posicion,Persona &p);


    protected:

    private:
        std::string _nombreArchivo;
};

