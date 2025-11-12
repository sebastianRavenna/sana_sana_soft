#include <iostream>
#include <string>
#include "ArchivoAgenda.h"
#include "ArchivoTurno.h"
#include "rlutil.h"

using namespace std;


ArchivoTurno::ArchivoTurno(const string &nombreArchivo){
            _nombreArchivo=nombreArchivo;
            tamanioRegistro=sizeof(Turno);
}

bool ArchivoTurno::escribirRegistro(Turno turno){
    FILE *pArchivo=fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }

    fwrite(&turno, sizeof(Turno), 1, pArchivo);

    //cout<<"Guardado exitoso"<<endl;
    fclose(pArchivo);
    return true;
}

int ArchivoTurno::buscarRegistro(int idTurno){
    Turno turno;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
        if (pArchivo==NULL){
            return -2;
        }
    int pos=0;
    while(fread(&turno, tamanioRegistro, 1, pArchivo)==1){
        if(turno.getIdTurno()== idTurno){
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

Turno ArchivoTurno::leerRegistro(int pos){
    Turno turno;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
        if (pArchivo==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return turno;
    }
    fseek(pArchivo, pos*tamanioRegistro,0); //pos*tamanio Registro multiplica la posicion por el tamaÃ±o de cada registro para moverse dentro del archivo
    fread(&turno, tamanioRegistro, 1, pArchivo);

    fclose(pArchivo);
    return turno;
}

bool ArchivoTurno::modificarRegistro(int idTurno, int pos2){
    Turno turno;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb+");
        if (pArchivo==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return false;
    }

    fseek(pArchivo, pos2 * tamanioRegistro, 0);
    fread(&turno, tamanioRegistro, 1, pArchivo);

    int opcionModificar=-1;
    Fecha nuevaFecha;
    do{
    system("cls");
    turno.mostrarTurno();
    cout<<endl;

    cout << "================================" << endl;
    cout << "   SELECCIONE QUE MODIFICAR" << endl;
    cout << "================================" << endl;
    cout << "1. Id Paciente" << endl;
    cout << "2. Id Medico" << endl;
    cout << "3. Cod Especialidad" << endl;
    cout << "0. Volver" << endl;
    cout << "================================" << endl;
    cout << "Opcion: ";
    cin >> opcionModificar;
    cin.ignore();

    while(opcionModificar>3||opcionModificar<0){
        cout<<"Numero incorrecto"<<endl;
        cout<<"Ingrese la opcion deseada: ";
        cin>> opcionModificar;
        cin.ignore();
    }

    string nuevoId;
    switch(opcionModificar) {
        case 1:{
            cout << "Ingrese nuevo Id Paciente: ";
            cin>>nuevoId;
            cin.ignore();
            turno.setIdPaciente(nuevoId);
            cout << "Id Paciente modificado exitosamente" << endl;
            system("pause");
            break;
        }
        case 2:{
            cout << "Ingrese nuevo Id Medico: ";
            cin>>nuevoId;
            cin.ignore();
            turno.setIdMedico(nuevoId);
            cout << "Id Medico modificado exitosamente." << endl;
            break;
        }
        case 3:{
            int nuevoCodEsp;
            cout << "Ingrese nuevo Cod Especialidad: ";
            cin >> nuevoCodEsp;
            cin.ignore();
            turno.setCodEspecialidad(nuevoCodEsp);
            cout << "Cod Especialidad modificado exitosamente." << endl;
            system("pause");
            break;
        }

        case 0:
            cout << "Volviendo al menu anterior..." << endl;
            break;

        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            system("pause");
            break;
    }

    }while (opcionModificar!=0);

    fseek(pArchivo, pos2 * tamanioRegistro, 0);
    fwrite(&turno, tamanioRegistro, 1, pArchivo);

    fclose(pArchivo);
    return true;
}


int ArchivoTurno::contarRegistros(){
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
        if (pArchivo==NULL){
            return 0;
    }

    fseek(pArchivo, 0, 2); // los numeros indican: 0 desde el inicio, 1 posicion actual, 2 final del archivo
    int tamBytes= ftell(pArchivo);
    int cantReg= tamBytes/tamanioRegistro;

    return cantReg;
}

bool ArchivoTurno::cancelarTurno(int idTurno){
    int pos2 = buscarRegistro(idTurno);
    if (pos2 == -1){
        cout << "Turno no encontrado" << endl;
        return false;
    }

    ArchivoAgenda arcAgenda;
    Turno turno = leerRegistro(pos2);
    turno.mostrarTurno();

    cout << "\n¨Esta seguro de cancelar este turno? (1.Si / 0.No): ";
    int confirmar;
    cin >> confirmar;


    if(confirmar){
        turno.setEstado(false);
        FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb+");
        if (pArchivo==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return false;
        }
        fseek(pArchivo, pos2 * tamanioRegistro, 0);
        fwrite(&turno, tamanioRegistro, 1, pArchivo);
        fclose(pArchivo);

        int posAgenda = arcAgenda.buscarRegistro(turno.getIdAgenda());
        FILE* pArchivoAgenda=fopen(_nombreArchivo.c_str(), "rb+");
        if (pArchivoAgenda==NULL){
            cout<<"ERROR EN EL ARCHIVO"<<endl;
            return false;
        }
        fseek(pArchivoAgenda, pos2 * tamanioRegistro, 0);
        fwrite(&turno, tamanioRegistro, 1, pArchivoAgenda);
        fclose(pArchivoAgenda);
        cout << "Turno cancelado" << endl;
    }
    return true;
}

void ArchivoTurno::solicitarTurno(const string &idMedico, const string &idPaciente,
                            Fecha fechaDesde, Fecha fechaHasta){
    ArchivoAgenda arcAgenda;
    Agenda agenda;

    FILE* pArchivo=fopen("agenda.dat", "rb");
        if (pArchivo==NULL){
            cout<<"ERROR EN EL ARCHIVO AGENDA"<<endl;
            return;
    }

    int cantidadDisponibles = 0;
    while (fread (&agenda, sizeof(Agenda), 1, pArchivo)==1){
        if(agenda.getIdMedico()==idMedico && agenda.getFechaTurno().esIgualOMenor(fechaHasta)&&
           fechaDesde.esIgualOMenor(agenda.getFechaTurno())&&!agenda.getAsignado()&&agenda.getEstado()){
           cantidadDisponibles++;
        }
    }

    fclose(pArchivo);

    if(cantidadDisponibles==0){
        cout << "No hay turnos disponibles para el medico " <<idMedico<< " en el rango de fechas seleccionado." << endl;
        system("pause");
        return;
    }

    Agenda *agendasDisponibles = new Agenda[cantidadDisponibles];
    int *posicionesAgenda = new int [cantidadDisponibles];

     pArchivo = fopen("agenda.dat", "rb");
        if (pArchivo == NULL){
        cout << "ERROR: No se pudo abrir el archivo de agendas" << endl;
        delete[] agendasDisponibles;
        delete[] posicionesAgenda;
        return;
    }

    int pos = 0;
    int indice = 0;

    while (fread(&agenda, sizeof(Agenda), 1, pArchivo)==1){
        if (agenda.getIdMedico() == idMedico &&
            agenda.getFechaTurno().esIgualOMenor(fechaHasta) &&
            fechaDesde.esIgualOMenor(agenda.getFechaTurno()) &&
            !agenda.getAsignado() &&
            agenda.getEstado()) {

            agendasDisponibles[indice] = agenda;
            posicionesAgenda[indice] = pos;
            indice++;
        }
        pos++;
    }

    cout << "\n=== TURNOS DISPONIBLES ===" << endl;
    for (int i = 0; i < cantidadDisponibles; i++) {
        cout << "\n[" << (i + 1) << "]" << endl;
        agendasDisponibles[i].mostrarAgenda();
    }

    int opcion;

    do{
        if (opcion != 0 || opcion <= cantidadDisponibles){
        cout << "\nSeleccione el turno deseado entre (1-" << cantidadDisponibles
             << ") o 0 para cancelar: ";
        cin >> opcion;
        }else {
        cout << "Opcion Incorrecta" << endl;
        system("pause");
        }
    }while (opcion != 0 && opcion > cantidadDisponibles);

    Agenda agendaSeleccionada = agendasDisponibles[opcion - 1];
    int posAgendaSeleccionada = posicionesAgenda[opcion - 1];

    Turno nuevoTurno;
    nuevoTurno.setIdTurno(contarRegistros() + 1);
    nuevoTurno.setIdPaciente(idPaciente);
    nuevoTurno.setIdAgenda(agendaSeleccionada.getIdAgenda());
    nuevoTurno.setFechaTurno(agendaSeleccionada.getFechaTurno());
    nuevoTurno.setHoraTurno(agendaSeleccionada.getHoraTurno());
    nuevoTurno.setIdMedico(agendaSeleccionada.getIdMedico());
    nuevoTurno.setCodEspecialidad(agendaSeleccionada.getCodEspecialidad());
    nuevoTurno.setEstado(true);

    if (escribirRegistro(nuevoTurno)) {
        agendaSeleccionada.setAsignado(true);

        FILE* pArchivoAgenda = fopen("agenda.dat", "rb+");
        if (pArchivoAgenda != NULL) {
            fseek(pArchivoAgenda, posAgendaSeleccionada * sizeof(Agenda), 0);
            fwrite(&agendaSeleccionada, sizeof(Agenda), 1, pArchivoAgenda);
            fclose(pArchivoAgenda);
        }

        cout << "Turno asignado exitosamente!" << endl;
        system("pause");

    }

    delete[] agendasDisponibles;
    delete[] posicionesAgenda;
    fclose(pArchivo);
}


bool ArchivoTurno::listarTodosLosTurnos(){
    Turno turno;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }

    cout << "\n=== LISTADO DE TURNOS ===" << endl << endl;
    while (fread(&turno, tamanioRegistro,1, pArchivo)==1){
        turno.mostrarTurno();
    }

    fclose(pArchivo);
    system("pause");
    return true;
}

bool ArchivoTurno::listarTurnosPorFecha(Fecha fecha){
    Turno turno;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }

    cout << "\n=== TURNOS DEL DIA: ";
    fecha.Mostrar();
    cout << " ===" << endl;

    while (fread(&turno, tamanioRegistro,1, pArchivo)==1){
        if (turno.getFechaTurno().esIgual(fecha)){
            turno.mostrarTurno();
        } else {
            cout<<"No se encontraron turnos para esta fecha"<<endl;
        }
    }
    fclose(pArchivo);
    system("pause");
    return true;
}

bool ArchivoTurno::listarTurnosPorPaciente(const string &idPaciente){
    Turno turno;
    FILE* pArchivo=fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo==NULL){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
        return false;
    }
    cout << "\n=== TURNOS DEL PACIENTE: ";
    idPaciente;
    cout << " ===" << endl;
    while (fread(&turno, tamanioRegistro,1, pArchivo)==1){
        if (turno.getIdPaciente()==idPaciente){
            turno.mostrarTurno();
        } else {
            cout<<"No se encontraron turnos para este paciente"<<endl;
            fclose(pArchivo);
            system("pause");
            return false;
        }
    }
    fclose(pArchivo);
    system("pause");
    return true;
}

