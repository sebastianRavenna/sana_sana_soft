#pragma once
#include "Persona.h"

class Medico: public Persona
{
    public:
        Medico();

        std::string getIdMedico()const;
        int getCodEspecialidad();
        int getMatricula();
        void setIdMedico(const std::string &idMedico);
        void setCodEspecialidad(int codEspecialidad);
        void setMatricula(int matricula);
        void cargar();
        void mostrar();



    protected:

    private:
        int _codEspecialidad, _matricula;
        char _idMedico[15];
};

