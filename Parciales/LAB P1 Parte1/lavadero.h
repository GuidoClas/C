#ifndef LAVADERO_H_INCLUDED
#define LAVADERO_H_INCLUDED

typedef struct
{
    int id; //1000
    char descripcion[20];

} eMarca;

typedef struct
{
    int id; //5000
    char nombreColor[20];

} eColor;

typedef struct
{
    int id; //20000
    char descripcion[25];
    float precio;

} eServicio;

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

#endif // LAVADERO_H_INCLUDED


void listarColores(eColor* colores, int tamCo);

void listarColor(eColor x);

void listarMarcas(eMarca* marcas, int tamMas);

void listarMarca(eMarca x);

void listarServicios(eServicio* servicios, int tamSer);

void listarServicio(eServicio x);

int buscarServicio(int idServicio, eServicio* servicios, int tamSer);


