#ifndef UTNEMPLEADO_H_INCLUDED
#define UTNEMPLEADO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFechaIngreso;

typedef struct
{
    int id;
    int idSector;
    char nombre[20];
    int edad;
    char sexo;
    float sueldo;
    int isEmpty;
    eFechaIngreso ingreso;

} eEmpleado;

#include "sectores.h"
#endif // UTNEMPLEADO_H_INCLUDED


void mostrarEmpleado(eEmpleado vec, eSector sectores[], int tamSec);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void inicializarEmpleados(eEmpleado empleados[], int tam);
int buscarLibre (eEmpleado vec[], int tam);
int buscarEmpleado (int id, eEmpleado vec[], int tam);
void altaEmpleado(eEmpleado vec[], int tam, int tamsec, eSector sectores[]);
void bajaEmpleado(eEmpleado vec[], int tam);
void modificarEmpleado(eEmpleado vec[], int tam);
void ordenarEmpleados(eEmpleado vec[], int tam);
void hardcodearEmpleados(eEmpleado vec[], int cant);
