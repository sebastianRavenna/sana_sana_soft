#pragma once
#include <string>
#include "Paciente.h"

class ArchivoPaciente
{
    public:
        ArchivoPaciente(const std::string &nombreArchivo="pacientes.dat");
        Paciente leerRegistros(int tamRegistro);
        bool listarPacientes();
        bool guardarPaciente(Paciente pac);
/*        bool agregarRegistro(const Especialidad &reg);
        bool leerRegistro(int posicion,Especialidad &reg);
        bool modificarRegistro(Especialidad &reg,int pos);
        int buscarRegistro(int codEspecialidad); ///no se si el parametro esta bien puesto
        int contarRegistros();
        bool bajaLogica(int codEspecialidad);
        bool altaLogica(int codEspecialidad);*/
    private:
        std::string _nombreArchivo;
        int tamanioRegistro;
};
