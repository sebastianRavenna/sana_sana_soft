#include <iostream>
#include "rlutil.h"
#include "menuPrincipal.h"
#include "menuHistoriaClinica.h"
#include "HistoriaClinica.h"
#include "ArchivoHistoriaClinica.h"
#include "ArchivoPaciente.h"
#include "funciones.h"
#include "MenuModificarHistoriaClinica.h"
#include "ArchivoMedico.h"
#include "Medico.h"

using namespace std;

void menuHistoriaClinica(){

char margenTitulo[]={"          "};
char margenMenu[]={"                    "};
int numeroInicio, posBuscar=0, posBuscar2=0, idBuscado, nuevoIdHistoriaClinica;
string idPac, idDoc;

do{
    rlutil::cls();

    cout <<margenTitulo<< " _   _ _     _             _          ____ _ _       _" << endl;
    cout <<margenTitulo<< "| | | (_)___| |_ ___  _ __(_) __ _   / ___| (_)_ __ (_) ___ __ _" << endl;
    cout <<margenTitulo<< "| |_| | / __| __/ _ \\| '__| |/ _` | | |   | | | '_ \\| |/ __/ _` |" << endl;
    cout <<margenTitulo<< "|  _  | \\__ \\ || (_) | |  | | (_| | | |___| | | | | | | (_| (_| |" << endl;
    cout <<margenTitulo<< "|_| |_|_|___/\\__\\___/|_|  |_|\\__,_|  \\____|_|_|_| |_|_|\\___\\__,_|" << endl<<endl<<endl;


    cout<<margenMenu<<" =============================="<<endl;
    cout<<margenMenu<<"||  1 - CREAR H. CLINICA      ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  2 - BUSCAR H. CLINICA     ||"<<endl;
    cout<<margenMenu<<"||                            ||"<<endl;
    cout<<margenMenu<<"||  3 - MODIFICAR H. CLINICA  ||"<<endl;
    cout<<margenMenu<<"||============================||"<<endl;
    cout<<margenMenu<<"||  0 - VOLVER AL M. INICIAL  ||"<<endl;
    cout<<margenMenu<<" =============================="<<endl<<endl;

    cout<<margenMenu<<"Ingrese la opcion deseada: ";
    cin>> numeroInicio;

    while(numeroInicio>3||numeroInicio<0){
        cout<<margenMenu<<"Numero incorrecto"<<endl;
        cout<<margenMenu<<"Ingrese la opcion deseada: ";
        cin>> numeroInicio;
    }
    HistoriaClinica historia;
    ArchivoHistoriaClinica archivoHistoria;
    ArchivoPaciente archivoPaciente;
    Paciente paciente;
    ArchivoMedico archivoMedico;
    Medico medico;

    switch(numeroInicio){
        case 1:
            rlutil::cls();
            nuevoIdHistoriaClinica = archivoHistoria.CantidadRegistros() + 1;
            historia.setIdHistoria(nuevoIdHistoriaClinica);
            cout<<"=== NUEVA HISTORIA CLINICA (ID "<<historia.getIdHistoria()<<") ==="<<endl<<endl;
            cout<<"INGRESE DNI DEL PACIENTE: ";
            idPac=cargarCadena();
            cout<<endl;
            posBuscar = archivoPaciente.buscarPaciente(idPac);
            if(posBuscar>=0){
                cout<<"INGRESE DNI DEL DOCTOR: ";
                idDoc=cargarCadena();
                cout<<endl;
                posBuscar2 = archivoMedico.buscarRegistro(idDoc);
                if(posBuscar2>=0){
                    idDoc="M-"+idDoc;
                    historia.cargar(idPac, idDoc);
                    archivoHistoria.guardarHistoriaClinica(historia);
                }
                else{
                    cout<<"El DNI ingresado no corresponde a un doctor registrado."<<endl;
                    cout<<"Por favor, registre al doctor para poder crear la historia clinica"<<endl<<endl;
                }
            }
            else{
                cout<<"El DNI ingresado no corresponde a un paciente registrado."<<endl;
                cout<<"Por favor, registre al paciente para poder crear su historia clinica"<<endl<<endl;
            }

        break;

        case 2:{
            rlutil::cls();
            cout<<"=== BUSCAR HISTORIA CLINICA ==="<<endl<<endl;
            cout<<"Ingrese el DNI del paciente: ";
            idPac=cargarCadena();
            cout<<endl;
            posBuscar = archivoPaciente.buscarPaciente(idPac);
            if(posBuscar>=0){
                paciente=archivoPaciente.leerRegistro(posBuscar);
                cout<<"*** Historia Clinica de "<<paciente.getNombre()<<" "<<paciente.getApellido()<<" ***"<<endl<<endl;

            }
            archivoHistoria.listarHistoriaClinicaxPaciente(idPac);
            cout<<endl<<endl;
            cout<<"Presione ENTER para continuar...";

            }
        break;


        case 3:
                rlutil::cls();
                cout << "=== MODIFICAR HISTORIA CLINICA ===" << endl<<endl;
                cout << "Ingrese el ID de la Historia Clinica a modificar: ";
                cin >> idBuscado;
                cin.ignore();
                posBuscar = archivoHistoria.buscarHistoriaClinica(idBuscado);
                if(posBuscar>=0){
                    archivoHistoria.leerRegistro(posBuscar, historia);
                    submenuModificar(historia);
                    archivoHistoria.modificarRegistro(historia, posBuscar);
                }
                else{
                    cout<<endl;
                    cout<<"Historia Clinica No Encontrada"<<endl<<endl;
                    cout<<"Presione ENTER para continuar...";
                }
        break;

        case 4:
            rlutil::cls();
            cout<<"BAJA H. CLINICA";
        break;

        case 0:
            rlutil::cls();
            cout<<"Volviendo al Menu Inicial";

        return;
    }
    rlutil::anykey();
    }while (numeroInicio!=0);

}


