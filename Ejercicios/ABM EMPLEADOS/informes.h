#include "empleado.h"

#ifndef UTNINFORMES_H_INCLUDED
#define UTNINFORMES_H_INCLUDED



#endif // UTNINFORMES_H_INCLUDED

void informar(eEmpleado vec[], int tam, eSector sectores[], int tamsec);
char menuInformes();
void listarEmpleadosAnio(eEmpleado vec[], int tam, eSector sector[], int tamsec);
void informarEmpleadosVarones(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarTotalSueldos(eEmpleado vec[], int tam);
void informarEmpleadosSector(eEmpleado empleados[],int tam, eSector sectores[], int tamSec);
void informarEmpleadoXSector(eEmpleado empleados[],int tam, eSector sectores[], int tamSec);
void informarMayorSueldoSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
void informarMayorSueldoXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
void informarTotalSueldosSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
void aumentarSueldosSectorPorcentaje(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
float obtenerTotalSueldos(int idSector, eEmpleado vec[], int tam);
void sectorQueMasCobra(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
