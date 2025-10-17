#pragma once


class Persona
{
    public:
        Persona();
        virtual ~Persona();
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
        void setDNI(std::string dni);
        void setNombre(std::string nombre);
        void setApellido(std::string apellido);
        void setDomicilio(std::string domicilio);
        void setMail(std::string mail);
        void setTelefono(std::string telefono);
        void setSexo(std::string sexo);
        void setFechaNac (Fecha);
        void setFechaIngreso(Fecha);
        void setEstado(bool);


    protected:

    private:
       int idPersona;
       char _DNI [10], _nombre[20], _apellido[20], _domicilio[30], _mail[30], _telefono[14], _sexo[2];
       Fecha fechaNac, fechaIngreso;
       bool estado;
};


