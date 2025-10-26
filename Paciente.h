#pragma once
#include <string>
#include "Persona.h"

class Paciente: public Persona
{
    public:
        Paciente();
        //virtual ~Paciente();
        std::string getIdPaciente()const;
        int getIdObraSocial();
        void setIdPaciente(const std::string &idPaciente);
        void setIdObraSocial(int idObraSocial);
        void cargar();
        void mostrar();



    protected:

    private:
        int _idObraSocial;
        char _idPaciente[15];
};

