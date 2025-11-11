#include <iostream>
#include <ctime>
#include "Fecha.h"
using namespace std;
Fecha::Fecha(){
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

bool Fecha::esBisiesto(int anio){
    if (anio%4==0){
        if(anio%100==0&&anio%400!=0){
            return false;
        }
        return true;
    }else return false;
}

int Fecha::diasEnMes(int mes, int anio){
    int dias;
    if (mes==2){
        if(esBisiesto(anio)){
            dias=29;
        } else dias=28;
    }else if (mes==4 || mes==6 || mes==9 || mes==11){
        dias=30;
    }else dias=31;
    return dias;
}

void Fecha::Cargar(){
    bool fechaValida = false;

    while(!fechaValida){
        cout<<"DIA ";
        cin>>_dia;
        cout<<"MES ";
        cin>>_mes;
        cout<<"A¥O ";
        cin>>_anio;
        if (_anio<1900||_anio>2025){
        cout<<"Indique un a¤o V lido entre 1900 y 2025"<<endl;
        }else if (_mes<1||_mes>12){
        cout<<"Indique un mes V lido entre 1 y 12"<<endl;
        }else if (_dia<1 || _dia>diasEnMes(_mes, _anio)){
        cout<<"Indique un dia V lido entre 1 y "<<diasEnMes(_mes, _anio)<<endl;
        } else {fechaValida=true;
        }
        if(!fechaValida) cout<<"Intente nuevamente: "<<endl;
    }
}

void Fecha::fechaActual(){
    int diaActual, mesActual, anioActual;
    time_t ahora=time(0);
	tm* hoy = localtime(&ahora);

	_dia = hoy->tm_mday;
	_mes = hoy->tm_mon+1;
	_anio = hoy->tm_year+1900;
}
int Fecha::calcularEdad(Fecha fechaNac){
    int edad;

    edad = _anio - fechaNac.getAnio();
    if (_mes < fechaNac.getMes()||(_mes == fechaNac.getMes() && _dia < fechaNac.getDia())) {
        edad--;
    }

    return edad;
}
int Fecha::calcularAntiguedad(Fecha fechaAlta){
    int meses = (_anio - fechaAlta.getAnio())*12;
    meses += (_mes - fechaAlta.getMes());
    return meses;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

std::string Fecha::toString(){
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}
void Fecha::Mostrar(){
        cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
    }

bool Fecha::verificarFecha(){
    Fecha hoy;
    hoy.fechaActual();
if (_anio > hoy.getAnio() ||
       (_anio == hoy.getAnio() && _mes > hoy.getMes()) ||
       (_anio == hoy.getAnio() && _mes == hoy.getMes() && _dia > hoy.getDia())){
            cout<<endl;
            cout<<"No es posible cargar una fecha posterior al dia de hoy."<<endl;
            cout<<"Intente nuevamente"<<endl<<endl;
            return false;
       }
    else{
        return true;
    }

}

bool Fecha::esMasAntigua(Fecha fecha2){
    if(_anio < fecha2.getAnio()) return true;
    if(_anio > fecha2.getAnio()) return false;
    if(_mes < fecha2.getMes()) return true;
    if(_mes > fecha2.getMes()) return false;
    if(_dia < fecha2.getDia()) return true;
    if(_dia > fecha2.getDia()) return false;
}
