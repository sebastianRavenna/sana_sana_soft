#pragma once
#include <string>
#include "Fecha.h"
#include "Hora.h"


class Turno
{
    public:
        Turno();
        Turno(int idTurno,int _idAgenda,const std::string &idPaciente,
              const std::string &idMedico,int _codEspecialidad, Fecha fecha, Hora hora);

        int getIdTurno();
        std::string getIdPaciente() const;
        int getIdAgenda();
        Fecha getFechaTurno();
        Hora getHoraTurno();
        std::string getIdMedico() const;
        int getCodEspecialidad();
        bool getEstado();

        void setIdTurno(int idturno);
        void setIdPaciente(const std::string &idPaciente);
        void setIdAgenda(int idagenda);
        void setFechaTurno(Fecha fecha);
        void setHoraTurno(Hora hora);
        void setIdMedico(const std::string &idMedico);
        void setCodEspecialidad(int codEsp);
        void setEstado(bool estado);

        void cargarTurno();
        void mostrarTurno();

    private:
        int _idTurno, _idAgenda, _codEspecialidad;
        Fecha _fechaTurno;
        Hora _horaTurno;
        char _idPaciente[15], _idMedico[15];
        bool _estado;
};

