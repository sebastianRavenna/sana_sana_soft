#include<iostream>
#include "rlutil.h"
#include "Especialidad.h"
#include "ArchivoEspecialidad.h"
#include "MenuModificarEspecialidad.h"
using namespace std;



void menuEspecialidad(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio, nuevoIdEspecialidad, numero, posBuscar=0;

do{
    rlutil::cls();
    cout <<margenTitulo<< " _____                     _       _ _     _           _  " << endl;
    cout <<margenTitulo<< "| ____|___ _ __   ___  ___(_) __ _| (_) __| | __ _  __| | " << endl;
    cout <<margenTitulo<< "|  _| / __| '_ \\ / _ \\/ __| |/ _` | | |/ _` |/ _` |/ _` | " << endl;
    cout <<margenTitulo<< "| |___\\__ \\ |_) |  __/ (__| | (_| | | | (_| | (_| | (_| | " << endl;
    cout <<margenTitulo<< "|_____|___/ .__/ \\___|\\___  |_|\\__,_|_|_|\\__,_|\\__,_|\\__,_| " << endl;
    cout <<margenTitulo<< "          |_|                                               " << endl<<endl<<endl;


    cout<<margenMenu<<" ================================"<<endl;
    cout<<margenMenu<<"||   1 - AGREGAR ESPECIALIDAD   ||"<<endl;
    cout<<margenMenu<<"||                              ||"<<endl;
    cout<<margenMenu<<"||   2 - BUSCAR ESPECIALIDAD    ||"<<endl;
    cout<<margenMenu<<"||                              ||"<<endl;
    cout<<margenMenu<<"||   3 - MODIF ESPECIALIDAD     ||"<<endl;
    cout<<margenMenu<<"||                              ||"<<endl;
    cout<<margenMenu<<"||   4 - ALTA/BAJA ESPECIALIDAD ||"<<endl;
    cout<<margenMenu<<"||==============================||"<<endl;
    cout<<margenMenu<<"||   0 - VOLVER AL M. INICIAL   ||"<<endl;
    cout<<margenMenu<<" ================================"<<endl<<endl;

    cout<<margenMenu<<"Ingrese la opcion deseada: ";
    cin>> numeroInicio;

    while(numeroInicio>4||numeroInicio<0){
        cout<<margenMenu<<"Numero incorrecto"<<endl;
        cout<<margenMenu<<"Ingrese la opcion deseada: ";
        cin>> numeroInicio;
    }
    ArchivoEspecialidad archivoEspecialidad;
    Especialidad especialidad;
    switch(numeroInicio){
        case 1:{
            rlutil::cls();
            nuevoIdEspecialidad = archivoEspecialidad.contarRegistros()+1;
            especialidad.setCodEspecialidad(nuevoIdEspecialidad);
            cout<<"=== NUEVA ESPECIALIDAD (Cod "<<especialidad.getCodEspecialidad()<<") ==="<<endl<<endl;
            especialidad.cargar();
            archivoEspecialidad.agregarRegistro(especialidad);
        break;
        }

       case 2:{
            rlutil::cls();
            cout<<"=== BUSCAR ESPECIALIDAD ==="<<endl<<endl;
            cout<<"Ingrese el codigo de la especialidad a buscar: ";
            cin>>numero;
            posBuscar=archivoEspecialidad.buscarRegistro(numero);
            if(posBuscar>=0){
                especialidad = archivoEspecialidad.leerRegistro(posBuscar);
                cout<<endl;
                especialidad.mostrar();
                cout<<endl;
                cout<<"Presione ENTER para continuar...";
            }
            else{
                cout<<endl;
                cout<<"Codigo de Especialidad No Encontrado"<<endl<<endl;
                cout<<"Presione ENTER para continuar...";
            }
            break;

    }

        case 3:
            rlutil::cls();
            cout<<"=== MODIFICAR ESPECIALIDAD ==="<< endl<<endl;
            cout<< "Ingrese el Codigo de la Especialidad a modificar: ";
            cin>> numero;
            posBuscar=archivoEspecialidad.buscarRegistro(numero);
            if(posBuscar>=0){
                archivoEspecialidad.leerRegistro(posBuscar, especialidad);
                submenuModificar(especialidad);
                archivoEspecialidad.modificarRegistro(especialidad, posBuscar);
            }
            else{
                cout<<endl;
                cout<<"Codigo de Especialidad No Encontrado"<<endl<<endl;
                cout<<"Presione ENTER para continuar...";
            }
        break;

        case 4:{
            int opcion;
            rlutil::cls();
            cout<<"=== ALTA/BAJA ESPECIALIDAD ==="<< endl;
            cout<<endl;
            cout<< "Ingrese el Codigo de la Especialidad a modificar: ";
            cin>> numero;
            posBuscar=archivoEspecialidad.buscarRegistro(numero);
            if(posBuscar>=0){
                archivoEspecialidad.leerRegistro(posBuscar,especialidad);
                if(especialidad.getEstado()){
                    cout<<endl;
                    cout<<"La especialidad "<<especialidad.getDescripcion()<<" se encuentra ACTIVA."<<endl<<endl;
                    cout<<"Presione 1 para cambiar su estado a INACTIVO o 0 para cancelar: ";
                    cin>> opcion;
                    if(opcion==1){
                        cout<<endl;
                        archivoEspecialidad.bajaLogica(numero);
                        cout<<"El cambio se realizo de forma existosa."<<endl<<endl;
                        cout<<"Presione ENTER para continuar...";
                    }
                    else if(opcion==0){
                        cout<<endl;
                        cout<<"No se realiz¢ ningun cambio"<<endl<<endl;
                        cout<<"Presione ENTER para continuar...";
                    }
                    else{
                        cout<<endl;
                        cout<<"La opcion ingresada no es valdia."<<endl;
                        cout<<"No se realiz¢ ningun cambio"<<endl<<endl;
                        cout<<"Presione ENTER para continuar...";

                    }
                }
                else{
                    cout<<endl;
                    cout<<"La especialidad "<<especialidad.getDescripcion()<<" se encuentra INACTIVA."<<endl<<endl;
                    cout<<"Presione 1 para cambiar su estado a ACTIVO o 0 para cancelar: ";
                    cin>> opcion;
                    if(opcion==1){
                        cout<<endl;
                        archivoEspecialidad.altaLogica(numero);
                        cout<<"El cambio se realizo de forma existosa."<<endl<<endl;
                        cout<<"Presione ENTER para continuar...";
                    }
                    else if(opcion==0){
                        cout<<endl;
                        cout<<"No se realiz¢ ningun cambio"<<endl<<endl;
                        cout<<"Presione ENTER para continuar...";
                }
                    else{
                        cout<<endl;
                        cout<<"La opcion ingresada no es valdia."<<endl;
                        cout<<"No se realiz¢ ningun cambio"<<endl<<endl;
                        cout<<"Presione ENTER para continuar...";
            }
            }
            }
            else{
                cout<<endl;
                cout<<"Codigo de Especialidad No Encontrado"<<endl<<endl;
                cout<<"Presione ENTER para continuar...";
            }

        break;
}

        case 0:
            rlutil::cls();
            cout<<"Volviendo al Menu Inicial";

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


