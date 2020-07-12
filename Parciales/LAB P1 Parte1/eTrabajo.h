#ifndef ETRABAJO_H_INCLUDED
#define ETRABAJO_H_INCLUDED

typedef struct
{
    int id;
    char patente[10];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

} eAuto;

typedef struct
{
    int id;
    char patente[10]; //validar
    int idServicio; //validar
    eFecha fecha;
    int isEmpty;

} eTrabajo;

#endif // ETRABAJO_H_INCLUDED


int altaTrabajo(int proximoIdTrabajo, eTrabajo* trabajos, eAuto* autos, eServicio* servicios ,int tamTra, int tamAu, int tamSer);

int buscarLibreTrabajo(eTrabajo* trabajos, int tamTra);

void inicializarTrabajos(eTrabajo* trabajos, int tamTra);

void listarTrabajos(eTrabajo* trabajos, eServicio* servicios, int tamTra, int tamSer);

void listarTrabajo(eTrabajo x, eServicio* servicios, int tamTra, int tamSer);

int cargarDescripcionServicio(char* descripcion, int idServicio, eServicio* servicios, int tamSer);

int buscarPatenteTrabajo(char* patente, eTrabajo* trabajos, int tamTra);
