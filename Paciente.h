#pragma once
#include "Persona.h"

class Paciente:Persona
{
    public:
        Paciente();
        virtual ~Paciente();
        int getIdPaciente();
        int getIdObraSocial();
        void setIdPaciente(int idPaciente);
        void setIdObraSocial(int idObraSocial);
        void cargar();
        void mostrar();



    protected:

    private:
        int _idPaciente, _idObraSocial;
};

