#pragma once
#include <string>
#include "Fecha.h"

class HistoriaClinica{

    private:
        int _idHistoria;
        int _idPaciente;
        int _idMedico;
        Fecha _fechaConsulta;
        char _descripcion [300];
        bool _estado;


    public:
        HistoriaClinica();

        int getIdHistoria();
        int getIdPaciente();
        int getIdMedico();
        Fecha getFechaConsulta();
        std::string getDescripcion()const;
        bool getEstado();

        void setIdHistoria(int);
        void setIdPaciente(int);
        void setIdMedico(int);
        void setFechaConsulta(Fecha);
        void setDescripcion (const std::string &descripcion);
        void setEstado(bool);

        void cargar();
        void mostrar();

};

