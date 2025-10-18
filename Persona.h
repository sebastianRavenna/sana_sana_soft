#pragma once
#include <string>
#include "Fecha.h"

class Persona
{
    public:
        Persona();

        void cargar();
        void mostrar();
        bool escribir();
        bool leer();
        int getIdPersona();
        std::string getDNI()const;
        std::string getNombre()const;
        std::string getApellido()const;
        std::string getDomicilio()const;
        std::string getMail()const;
        std::string getTelefono()const;
        std::string getSexo()const;
        std::string getNombreCompleto()const;
        Fecha getFechaNac();
        Fecha getFechaIngreso();
        bool getEstado();
        int getEdad();
        int getAntiguedad();
        void setDNI(const std::string &dni);
        void setNombre(const std::string &nombre);
        void setApellido(const std::string &apellido);
        void setDomicilio(const std::string &domicilio);
        void setMail(const std::string &mail);
        void setTelefono(const std::string &telefono);
        void setSexo(const std::string &sexo);
        void setFechaNac (Fecha);
        void setFechaIngreso(Fecha);
        void setEstado(bool);


    protected:

    private:
       int _idPersona;
       char _DNI [10], _nombre[20], _apellido[20], _domicilio[30], _mail[30], _telefono[14], _sexo[2];
       Fecha fechaNac, fechaIngreso;
       bool _estado;
};


