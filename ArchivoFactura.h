#pragma once
#include "Factura.h"

class ArchivoFactura
{
    public:
        ArchivoFactura(const std::string &nombreArchivo="factura.dat");

        Factura leerFactura(int posicion);
        int buscarFactura(int idFactura);
        int contarRegistro();
        bool agregarRegistro(const Factura &reg);
        bool leerRegistro(int posicion,Factura &reg);
        bool modificarFactura(int posicion);
        bool cambioEstado(int idFactura,int posicion);
        bool listarFacturas();

    protected:

    private:
        std::string _nombreArchivo;
        int tamanioRegistro;
};


