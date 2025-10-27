#pragma once
#include "Fecha.h"
#include "Hora.h"

class Agenda
{
    public:
        Agenda();
        Agenda(int idAgenda,int idMedico,int codEsp,Fecha fecha, Hora hora);
        int getIdAgenda();
        int getIdMedico();
        int getCodEspecialidad();
        Fecha getFechaTurno();
        Hora getHoraTurno();
        bool getAsignado();
        bool getEstado();

        void setIdAgenda(int idAgenda);
        void setIdMedico(int idMedico);
        void setCodEspecialidad(int codEspecilidad);
        void setFechaTurno(Fecha fechaturno);
        void setHoraTurno(Hora hora);
        void setAsginado(bool asignado);
        void setEstado(bool estado);

        void cargarAgenda();
        void mostrarAgenda();

    protected:

    private:
        int _idAgenda,_idMedico,_codEspecialidad;
        Fecha fechaTurno;
        Hora horaTurno;
        bool _asignado,_estado;
};


