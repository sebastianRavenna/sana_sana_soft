#include <iostream>
#include <string>
#include "MenuModificarHistoriaClinica.h"
#include "HistoriaClinica.h"
#include "Fecha.h"
#include "Funciones.h"
#include "rlutil.h"
#include "ArchivoPaciente.h"
#include "Paciente.h"
#include "ArchivoMedico.h"
#include "Medico.h"

using namespace std;

void submenuModificar(HistoriaClinica &his){

    int opcion = -1, posBuscar, posBuscar2;
    Fecha nuevaFecha;
    string idPac, idMed;

    ArchivoPaciente archivoPaciente;
    ArchivoMedico archivoMedico;


do {
   system("cls");
   his.mostrar();
   cout<<endl;

    cout << "================================" << endl;
    cout << "   SELECCIONE QUE MODIFICAR" << endl;
    cout << "================================" << endl;
    cout << "1. DNI" << endl;
    cout << "2. ID Medico" << endl;
    cout << "3. Fecha de Consulta" << endl;
    cout << "4. Descripcion" << endl;
    cout << "0. Volver" << endl;
    cout << "================================" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    while(opcion>4 || opcion<0){
        cout<<"Numero incorrecto"<<endl;
        cout<<"Ingrese la opcion deseada: ";
        cin>> opcion;
        cin.ignore();
        }

        switch(opcion){
            case 1:{
                cout<<"Ingrese nuevo DNI: ";
                idPac=cargarCadena();
                posBuscar=archivoPaciente.buscarPaciente(idPac);
                if(posBuscar>=0){
                    his.setDniPaciente(idPac);
                    cout<<"DNI modificado exitosamente.";
                    cin.get();
                }
                else{
                    cout<<endl;
                    cout<<"El DNI ingresado no corresponde a un paciente registrado."<<endl;
                    cout<<"Por favor, registre al paciente para poder crear su historia clinica"<<endl<<endl;
                    cout<<"Presione ENTER para continuar...";
                    cin.get();
                }
                break;
                }

            case 2:{
                cout<<"Ingrese DNI del Medico: ";
                idMed=cargarCadena();
                posBuscar2=archivoMedico.buscarRegistro(idMed);
                if(posBuscar2>=0){
                    idMed="M-"+idMed;
                    his.setIdMedico(idMed);
                    cout<<"ID Medico modificado exitosamente.";
                    cin.get();
                }
                else{
                    cout<<endl;
                    cout<<"El DNI ingresado no corresponde a un doctor registrado."<<endl;
                    cout<<"Por favor, registre al doctor para poder crear la historia clinica"<<endl<<endl;
                    cout<<"Presione ENTER para continuar...";
                    cin.get();
                }

                break;
                }

            case 3:{
                bool fechaValida;
                cout<<"Ingrese nueva Fecha de Consulta: "<<endl;
                nuevaFecha.Cargar();
                fechaValida=nuevaFecha.verificarFecha();
                if(fechaValida){
                    his.setFechaConsulta(nuevaFecha);
                    cin.get();
                    cout << "Fecha de Ingreso modificada exitosamente." << endl;
                    cin.get();
                    break;
                }
                else{
                    cin.get();
                    cout<<"Presione ENTER para continuar...";
                    cin.get();
                    break;
                }
                }

            case 4:{
                cout<<"Ingrese nueva Descripcion: "<<endl;
                his.setDescripcion(cargarCadena());
                cout<<"Descripcion modificada exitosamente.";
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

