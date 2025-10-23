#pragma once

class Especialidad
{
    public:
        Especialidad();
        int getCodEspecialidad();
        std::string getDescripcion()const;
        float getValorConsulta();
        bool getEstado();
        void setCodEspecialidad(int codEspecialidaad);
        void setDescripcion(const std::string &descripcion);
        void setValorConsulta(float valor);
        void setEstado(bool estado);
        void cargar();
        void mostrar();


    protected:

    private:
        int _codEspecialidad;
        char _descripcion[30];
        float _valorConsulta;
        bool _estado;
};

