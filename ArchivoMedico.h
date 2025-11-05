#pragma once
#include <string>
#include "Medico.h"


class ArchivoMedico
{
    public:
        ArchivoMedico(const std::string &nombreArchivo="medico.dat");

        bool guardarMedico(const Medico &reg);//Alta
        int buscarRegistro(const std::string _idMedico);//Buscar Pos del medico
        Medico leerRegistro(int pos);//Muestra el medico de la Pos encontrada
        bool leerRegistro(int posicion,Medico &reg);
        ///bool modificarRegistro(Medico &reg, int posicion);
        bool modificarRegistro(const std::string _idMedico, int pos);
        bool cambioEstado(const std::string _idPaciente, int pos);
        bool listarMedicos();
        //bool bajaLogica(std::string idMedico);
        //bool altaLogica(std::string idMedico);



    private:
        std::string _nombreArchivo;
        int tamanioRegistro;
};


