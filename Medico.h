#pragma once
#include "Persona.h"

class Medico: public Persona
{
    public:
        Medico();

        int getIdMedico();
        int getIdObraSocial();
        int getCodEspecialidad();
        int getMatricula();
        void setIdMedico(int idMedico);
        void setIdObraSocial(int idObraSocial);
        void setCodEspecialidad(int codEspecialidad);
        void setMatricula(int matricula);
        void cargar();
        void mostrar();



    protected:

    private:
        int _idMedico, _idObraSocial, _codEspecialidad, _matricula;
};

