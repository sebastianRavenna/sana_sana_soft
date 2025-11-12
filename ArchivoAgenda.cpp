#include <iostream>
#include <string>
#include "ArchivoAgenda.h"
#include "Agenda.h"
#include "Funciones.h"
#include "rlutil.h"

using namespace std;


ArchivoAgenda::ArchivoAgenda(const string &nombreArchivo){
            _nombreArchivo=nombreArchivo;
            tamanioRegistro=sizeof(Agenda);
}

bool ArchivoAgenda::escribirRegistro(Agenda agenda){
    FILE *pArchivo=fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }

    fwrite(&agenda, sizeof(Agenda), 1, pArchivo);

    //cout<<"Guardado exitoso"<<endl;
    fclose(pArchivo);
    return true;
}

int ArchivoAgenda::buscarRegistro(int idAgenda){
    Agenda agenda;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
        if (pArchivo==NULL){
            return -2;
        }
    int pos=0;
    while(fread(&agenda, tamanioRegistro, 1, pArchivo)==1){
        if(agenda.getIdAgenda()== idAgenda){
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

Agenda ArchivoAgenda::leerRegistro(int pos){
    Agenda agenda;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
        if (pArchivo==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return agenda;
    }
    fseek(pArchivo, pos*tamanioRegistro,0); //pos*tama¤oRegistro multiplica la posicion por el tama¤o de cada registro para moverse dentro del archivo
    fread(&agenda, tamanioRegistro, 1, pArchivo);

    fclose(pArchivo);
    return agenda;
}

bool ArchivoAgenda::modificarRegistro(Agenda idAgenda, int pos2){
    Agenda agenda;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb+");
        if (pArchivo==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return false;
    }

    fseek(pArchivo, pos2 * tamanioRegistro, 0);
    fread(&agenda, tamanioRegistro, 1, pArchivo);

    int opcionModificar=-1;
    Fecha nuevaFecha;
    /*do{
    system("cls");
    agenda.mostrar();
    cout<<endl;
    //cout << "Agenda: "<<agenda.getNombre()<<" "<<agenda.getApellido()<<endl<<endl;
    cout << "================================" << endl;
    cout << "   SELECCIONE QUE MODIFICAR" << endl;
    cout << "================================" << endl;
    cout << "1. DNI" << endl;
    cout << "2. Nombre" << endl;
    cout << "3. Apellido" << endl;
    cout << "4. Domicilio" << endl;
    cout << "5. Mail" << endl;
    cout << "6. Telefono" << endl;
    cout << "7. Sexo" << endl;
    cout << "8. Fecha de Nacimiento" << endl;
    cout << "9. Fecha de Ingreso" << endl;
    cout << "0. Volver" << endl;
    cout << "================================" << endl;
    cout << "Opcion: ";
    cin >> opcionModificar;
    cin.ignore();

    while(opcionModificar>9||opcionModificar<0){
        cout<<"Numero incorrecto"<<endl;
        cout<<"Ingrese la opcion deseada: ";
        cin>> opcionModificar;
        cin.ignore();
    }


    switch(opcionModificar) {
        case 1:{
            cout << "Ingrese nuevo DNI: ";
            agenda.setDNI(cargarCadena());
            agenda.setIdPersona(agenda.getDNI());
            cout << endl;

            string idagenda = "P-" + agenda.getDNI();
            agenda.setIdAgenda(idagenda);
            cout << "DNI modificado exitosamente." << endl;
            break;
        }
        case 2:
            cout << "Ingrese nuevo Nombre: ";
            agenda.setNombre(cargarCadena());
            cout << "Nombre modificado exitosamente." << endl;
            break;

        case 3:
            cout << "Ingrese nuevo Apellido: ";
            agenda.setApellido(cargarCadena());
            cout << "Apellido modificado exitosamente." << endl;
            break;

        case 4:
            cout << "Ingrese nuevo Domicilio: ";
            agenda.setDomicilio(cargarCadena());
            cout << "Domicilio modificado exitosamente." << endl;
            break;

        case 5:
            cout << "Ingrese nuevo Mail: ";
            agenda.setMail(cargarCadena());
            cout << "Mail modificado exitosamente." << endl;
            break;

        case 6:
            cout << "Ingrese nuevo Telefono: ";
            agenda.setTelefono(cargarCadena());
            cout << "Telefono modificado exitosamente." << endl;
            break;

        case 7:
            cout << "Ingrese nuevo Sexo (M/F): ";
            agenda.setSexo(cargarCadena());
            cout << "Sexo modificado exitosamente." << endl;
            break;

        case 8: {
            cout << "Ingrese nueva Fecha de Ingreso: " << endl;
            nuevaFecha.Cargar();
            agenda.setFechaNac(nuevaFecha);
            cout << "Fecha de Nacimiento modificada exitosamente." << endl;
            break;
        }

        case 9: {
            Fecha nuevaFecha;
            cout << "Ingrese nueva Fecha de Ingreso: " << endl;
            nuevaFecha.Cargar();
            agenda.setFechaIngreso(nuevaFecha);
            cout << "Fecha de Ingreso modificada exitosamente." << endl;
            break;
        }

        case 0:
            cout << "Volviendo al menu anterior..." << endl;
            break;

        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            break;
    }

    }while (opcionModificar!=0);*/

    fseek(pArchivo, pos2 * tamanioRegistro, 0);
    fwrite(&agenda, tamanioRegistro, 1, pArchivo);

    fclose(pArchivo);
    return true;
}

int ArchivoAgenda::contarRegistros(){
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
        if (pArchivo==NULL){
            return 0;
    }

    fseek(pArchivo, 0, 2); // los numeros indican: 0 desde el inicio, 1 posicion actual, 2 final del archivo
    int tamBytes= ftell(pArchivo);
    int cantReg= tamBytes/tamanioRegistro;

    return cantReg;
}

bool ArchivoAgenda::cambioEstado(const std::string _idAgenda, int pos2){
    Agenda agenda;
    bool nuevoEstado;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb+");
        if (pArchivo==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return false;
    }

    fseek(pArchivo, pos2 * tamanioRegistro, 0);
    fread(&agenda, tamanioRegistro, 1, pArchivo);


    int opcCambio;
    if(agenda.getEstado()==1){
        cout<<"¨Desea pasar el Agenda a Estado Inactivo? 1.Si - 2.No:";
        cin>>opcCambio;
        cin.ignore();
        if(opcCambio==1){
            nuevoEstado = false;
            cout<<"El Agenda fue dado de Baja en el sistema"<<endl;
        }
    }else{
        cout<<"¨Desea cambiar el Agenda a Estado Activo? 1.Si - 2.No:";
        cin>>opcCambio;
        cin.ignore();
        if(opcCambio==1){
            nuevoEstado = true;
            cout<<"El Agenda fue dado de Alta en el sistema"<<endl;
        }
    }
    agenda.setEstado(nuevoEstado);

    fseek(pArchivo, pos2 * tamanioRegistro, 0);
    fwrite(&agenda, tamanioRegistro, 1, pArchivo);

    fclose(pArchivo);
    return agenda.getEstado();
}

void ArchivoAgenda::generarAgenda(const std::string &idMedico, int codEspecialidad, Fecha fecha, Hora horaInicio, Hora horaFin){

    int hora, minutos, minutosInicio, minutosFin, minutoActual, idConsDisp, duracionMinutos=30;

    minutosInicio = horaInicio.getHora()*60 + horaInicio.getMinuto();
    minutosFin = horaFin.getHora()*60 + horaFin.getMinuto();
    minutoActual = minutosInicio;

    while (minutoActual<minutosFin){
        Agenda nuevaConsDisp;

        hora=minutoActual/60;
        minutos=minutoActual%60;
        Hora horaConsulta(hora, minutos);

        idConsDisp = contarRegistros()+1;
        nuevaConsDisp.setIdAgenda(idConsDisp);
        nuevaConsDisp.setIdMedico(idMedico);
        nuevaConsDisp.setCodEspecialidad(codEspecialidad);
        nuevaConsDisp.setFechaTurno(fecha);
        nuevaConsDisp.setHoraTurno(horaConsulta);

        escribirRegistro(nuevaConsDisp);
        minutoActual += duracionMinutos;
    }
}

void ArchivoAgenda::generarAgendaRango(const std::string &idMedico, int codEspecialidad, Fecha fechaDesde,
                        Fecha fechaHasta, Hora horaInicio, Hora horaFin, bool diasActivo[7]){
    int hora, minutos, minutosInicio, minutosFin, minutoActual,
    idConsDisp, duracionMinutos=30;

    Fecha fechaActual = fechaDesde;

    while(fechaActual.esIgualOMenor(fechaHasta)){
        if(diasActivo[fechaActual.getDiaSemana()]){
            generarAgenda(idMedico, codEspecialidad,fechaActual,
                          horaInicio, horaFin);
        }
        fechaActual = fechaActual.sumarUnDia();
    }

}

bool ArchivoAgenda::listarAgendaCompleta(){
    Agenda agenda;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }
    cout << "\n=== AGENDA COMPLETA ==="<< endl;
    while (fread(&agenda, tamanioRegistro,1, pArchivo)==1){
        agenda.mostrarAgenda();
    }

    fclose(pArchivo);
    system("pause");
    return true;
}

bool ArchivoAgenda::listarAgendaPorFecha(Fecha fecha){
    Agenda agenda;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }
    cout << "\n=== AGENDA DEL DIA: ";
    fecha.Mostrar();
    cout << " ===" << endl;
    while (fread(&agenda, tamanioRegistro,1, pArchivo)==1){
        if (agenda.getFechaTurno().esIgual(fecha)){
            agenda.mostrarAgenda();
        }
    }
    fclose(pArchivo);
    system("pause");
    return true;
}
