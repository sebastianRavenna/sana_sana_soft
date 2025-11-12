#pragma once
#include <string>
#include "Turno.h"


class ArchivoTurno
{
    public:
        ArchivoTurno(const std::string &nombreArchivo="turnos.dat");

        bool escribirRegistro (Turno turno);
        int buscarRegistro(int idTurno);
        Turno leerRegistro(int tamRegistro);
        bool modificarRegistro(int idTurno, int pos2);
        int contarRegistros();



        void solicitarTurno(const std::string &idMedico, const std::string &idPaciente,
                            Fecha fechaDesde, Fecha fechaHasta);
        bool cancelarTurno(int idTurno);


        bool listarTodosLosTurnos();
        bool listarTurnosPorPaciente(const std::string &idPaciente);
        bool listarTurnosPorFecha(Fecha fecha);

  private:
        std::string _nombreArchivo;
        int tamanioRegistro;
};






