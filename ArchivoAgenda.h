#pragma once
#include <string>
#include "Agenda.h"
#include "Hora.h"
#include "Fecha.h"

class ArchivoAgenda
{
    public:
        ArchivoAgenda(const std::string &nombreArchivo="agenda.dat");
        bool escribirRegistro (Agenda agenda);
        int buscarRegistro(int idAgenda);
        Agenda leerRegistro(int tamRegistro);
        //hbool modificarRegistro(Agenda agenda, int pos2);
        int contarRegistros();

        void generarAgenda(const std::string &idMedico, int codEspecialidad,
                           Fecha fecha, Hora horaInicio, Hora horaFin);
        void generarAgendaRango(const std::string &idMedico, int codEspecialidad,
                                Fecha fechaDesde, Fecha fechaHasta, Hora horaInicio,
                                Hora horaFin, bool diasSemana[7]);
        bool cambioEstado(const std::string &idMedico, Fecha fechaDesde, Fecha fechaHasta);

        bool listarAgendaCompleta();
        bool listarAgendaPorFecha(Fecha fecha);
        bool listarAgendaPorRangoFecha(Fecha fechaDesde, Fecha fechaHasta);
        bool listarAgendaPorMedicoRangoFecha(const std::string &idMedico,Fecha fechaDesde, Fecha fechaHasta);


  private:
        std::string _nombreArchivo;
        int tamanioRegistro;
};






