#pragma once


class Turno
{
    public:
        Turno();

        int getIdTurno();
        int getAgenda();
        int getPaciente();
        bool getEstado();

        void setIdTurno(int idturno);
        void setAgenda(int idagenda);
        void setIdPaciente(int idPaciente);
        void setEstado(bool estado);

        void cargarTurno();
        void mostrarTurno();


    protected:

    private:
        int _idTurno, _idAgenda, _idPaciente;
        bool _estado;
};

