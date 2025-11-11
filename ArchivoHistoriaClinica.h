#pragma once
#include <string>
#include "HistoriaClinica.h"

class ArchivoHistoriaClinica{

    public:
        ArchivoHistoriaClinica(const std::string &nombreArchivo="historiaClinica.dat"); //ok
        HistoriaClinica leerRegistro(int tamRegistro); //ok
        bool listarHistoriaClinica(); //ok
        bool listarHistoriaClinicaxPaciente(std::string &dniPacienteBuscado);
        bool guardarHistoriaClinica(HistoriaClinica his); //ok
        int buscarHistoriaClinica(int posicion); // REVISAR
        bool leerRegistro(int posicion, HistoriaClinica &reg); //ok
        bool modificarRegistro(HistoriaClinica his, int posicion);

        int CantidadRegistros();
        bool abmLogico(std::string &dniPacienteBuscado);
        bool listarPorFecha(); // lista Historias Clinicas de mas antiguo a mas reciente
        bool listarPorDNI(); // lista Historias Clinicas de menor a mayor

    private:
        std::string _nombreArchivo;
        int _tamanioRegistro;
};
