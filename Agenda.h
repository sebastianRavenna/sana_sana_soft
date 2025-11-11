#pragma once
#include <string>
#include "Fecha.h"
#include "Hora.h"

class Agenda
{
    public:
        Agenda();
        Agenda(const std::string &idMedico,int codEsp,Fecha fecha, Hora hora);

        int getIdAgenda();
        std::string getIdMedico() const;
        int getCodEspecialidad();
        Fecha getFechaTurno();
        Hora getHoraTurno();
        bool getAsignado();
        bool getEstado();

        void setIdAgenda(int idAgenda);
        void setIdMedico(const std::string &idMedico);
        void setCodEspecialidad(int codEspecilidad);
        void setFechaTurno(Fecha fechaturno);
        void setHoraTurno(Hora hora);
        void setAsignado(bool asignado);
        void setEstado(bool estado);

        void cargarAgenda();
        void mostrarAgenda();

    private:
        int _idAgenda,_codEspecialidad;
        char _idMedico[15];
        Fecha _fechaTurno;
        Hora _horaTurno;
        bool _asignado,_estado;
};


