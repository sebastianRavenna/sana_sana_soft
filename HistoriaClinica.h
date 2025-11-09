#pragma once
#include <string>
#include "Fecha.h"


class HistoriaClinica{

    private:
        int _idHistoria;
        char _dniPaciente[15];
        char _idMedico[15];
        Fecha _fechaConsulta;
        char _descripcion [300];
        bool _estado;


    public:
        HistoriaClinica();

        int getIdHistoria();
        std::string getDniPaciente()const;
        std::string getIdMedico()const;
        Fecha getFechaConsulta();
        std::string getDescripcion()const;
        bool getEstado();

        void setIdHistoria(int);
        void setDniPaciente(const std::string &dniPaciente);
        void setIdMedico(const std::string &idMed);
        void setFechaConsulta(Fecha);
        void setDescripcion (const std::string &descripcion);
        void setEstado(bool);

        void cargar(const std::string &idPac, const std::string &idMedico);
        void mostrar();
        void mostrarxPaciente(const std::string &nombreMedico, const std::string &sexoMedico);
        //void abmLogica(HistoriaClinica &his);

};

