#pragma once
#include <string>
#include "Paciente.h"

class ArchivoPaciente
{
    public:
        ArchivoPaciente(const std::string &nombreArchivo="pacientes.dat");
        Paciente leerRegistro(int tamRegistro);
        bool listarPacientes();
        bool guardarPaciente(Paciente pac);
        int buscarPaciente(const std::string _idPaciente);
        bool leerRegistro(int posicion,Paciente &reg);
/*      bool agregarRegistro(const Especialidad &reg);
        bool modificarRegistro(Especialidad &reg,int pos);
        int buscarRegistro(int codEspecialidad); ///no se si el parametro esta bien puesto
        int contarRegistros();
        bool bajaLogica(int codEspecialidad);
        bool altaLogica(int codEspecialidad);*/
    private:
        std::string _nombreArchivo;
        int tamanioRegistro;
};
