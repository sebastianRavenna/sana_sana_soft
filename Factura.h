#pragma once
#include <cstring>
#include "Fecha.h"


class Factura
{
    private:
        int _idFactura, _idMedico, _codEspecialidad;
        Fecha _fechaFactura;
        char _dniPaciente [10], _tipoFactura [2];
        float _importe;
        bool _estado;

    public:
        Factura(); //ok

        void cargar();
        void mostrar(); //ok
        bool escribir();
        bool leer();
        int getIdFactura(); //okk
        int getIdMedico(); //okk
        int getCodEspecialidad(); //okk
        float getImporte(); //okk
        Fecha getFechaFactura(); //okk
        std::string getDniPaciente()const; //okk
        std::string getTipoFactura()const; //okk
        bool getEstado(); //okk
        void setIdFactura(int); //ok
        void setIdMedico(int); //ok
        void setCodEspecialidad(int); //ok
        void setFechaFactura(Fecha); //ok
        void setDniPaciente(const std::string &dniPaciente); //ok
        void setTipoFactura(const std::string &tipoFactura); //ok
        void setImporte(float); //ok
        void setEstado(bool); //ok

};
