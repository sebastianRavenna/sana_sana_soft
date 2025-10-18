#include "ArchivoPersona.h"

using namespace std;

ArchivoPersona::ArchivoPersona(const std::string &nombreArchivo)
:_nombreArchivo(nombreArchivo){}


bool ArchivoPersona::escribir (const Persona &p){
FILE *archivo;
archivo=fopen(_nombreArchivo.c_str(),"ab");

if (archivo==NULL)return false;

fwrite(&p,sizeof(Persona),1,archivo);
fclose(archivo);

return true;

}
bool ArchivoPersona::leer(int posicion,Persona &p){
FILE *archivo;
archivo=fopen(_nombreArchivo.c_str(),"rb");

if(archivo==NULL)return false;

fseek(archivo,sizeof(Persona)* posicion,SEEK_SET);
fread(&p,sizeof(Persona),1,archivo);
fclose(archivo);

return true;
}
