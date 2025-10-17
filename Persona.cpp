#include <cstring>
#include "Persona.h"

Persona::Persona()
{
    idPersona = 0;
    strcpy(_DNI, "00000000");
    strcpy(_nombre, "SinNombre");
    strcpy(_apellido, "SinApellido");
    strcpy(_domicilio, "SinDomicilio");
    strcpy(_mail, "sinmail@ejemplo.com");
    strcpy(_telefono, "0000000000");
    strcpy(_sexo, "N");
    fechaNac = Fecha();
    fechaIngreso = Fecha();
    estado = true;
}


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
Persona::~Persona()
{
    //dtor
}

