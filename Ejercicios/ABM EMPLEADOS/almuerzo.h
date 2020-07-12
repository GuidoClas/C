#include "empleado.h"
#include "sectores.h"
#include "comida.h"

#ifndef UTNALMUERZO_H_INCLUDED
#define UTNALMUERZO_H_INCLUDED

typedef struct{

    int id;
    int idEmpleado;
    int idComida;
    eFechaIngreso fecha;
    int isEmpty;

} eAlmuerzo;
#endif // UTNALMUERZO_H_INCLUDED

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam);
void listarAlmuerzos(eAlmuerzo almuerzos[], int tam, eComida comidas[], int tamCom, eEmpleado empleados[], int tamEmp);
int altaAlmuerzo(int idAlmuerzo, eAlmuerzo almuerzos[], int tamal, eEmpleado vec[], int tamEmp, eSector sectores[], int tamSec, eComida comidas[], int tamCom);
int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam);
int cargarDescripcionComidas(char descripcion[], int id, eComida comidas[], int tam);
int cargarNombreEmpleado(char nombre[], int id, eEmpleado empleados[], int tam);
void listarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamCom, eEmpleado empleados[], int tamEmp);
