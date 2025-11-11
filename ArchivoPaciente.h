#pragma once
#include <string>
#include "Paciente.h"

class ArchivoPaciente
{
    public:
        ArchivoPaciente(const std::string &nombreArchivo="pacientes.dat");

        bool guardarPaciente(Paciente pac);//Alta Paciente
        int buscarPaciente(const std::string _idPaciente);//Buscar Pos del paciente
        Paciente leerRegistro(int tamRegistro);//Muestra el Paciente de la Pos encontrada
        bool modificarRegistro(const std::string _idPaciente, int pos2);//Modificar Paciente
        bool cambioEstado(const std::string _idPaciente, int pos2);//Baja Paciente
        bool listarPacientes();
        bool listarTodoPorApellido();


        int contarRegistros();

  private:
        std::string _nombreArchivo;
        int tamanioRegistro;
};
