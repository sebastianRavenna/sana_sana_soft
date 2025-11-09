#include <iostream>
#include <string>
#include "MenuModificarEspecialidad.h"
#include "Especialidad.h"
#include "Funciones.h"
#include "rlutil.h"
#include "ArchivoEspecialidad.h"

using namespace std;

void submenuModificar(Especialidad &especialidad){


    int opcion = -1;
    float nuevoValorConsulta;
    string nuevaDescripcion;

    ArchivoEspecialidad archivoEspecialidad;

do {
   system("cls");
   especialidad.mostrar();
   cout<<endl;

    cout << "================================" << endl;
    cout << "   SELECCIONE QUE MODIFICAR" << endl;
    cout << "================================" << endl;
    cout << "1. Descripcion" << endl;
    cout << "2. Valor Consulta" << endl;
    cout << "0. Volver" << endl;
    cout << "================================" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    while(opcion>2 || opcion<0){
        cout<<"Numero incorrecto"<<endl;
        cout<<"Ingrese la opcion deseada: ";
        cin>> opcion;
        cin.ignore();
        }

        switch(opcion){
            case 1:{
                cout<<"Ingrese nueva descrpcion: ";
                nuevaDescripcion=cargarCadena();
                especialidad.setDescripcion(nuevaDescripcion);
                cout<<"Descripcion modificada exitosamente.";
                cin.get();
                break;
                }

            case 2:{
                cout<<"Ingrese el nuevo valor de la Consulta: ";
                cin>>nuevoValorConsulta;
                especialidad.setValorConsulta(nuevoValorConsulta);
                cout<<"Valor de la Consulta modificado exitosamente.";
                cin.get();
                break;
                }


            case 0:{
                cout <<"Volviendo al menu anterior..." << endl;
                break;
                }

            default:{
                cout<<"Opcion invalida. Intente nuevamente."<<endl;
                cin.get();
                break;
                }


    }
    }
    while(opcion!=0);
}

