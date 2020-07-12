#include "almuerzo.h"
#include "ctype.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        almuerzos[i].isEmpty = 1;
    }

}


void listarAlmuerzos(eAlmuerzo almuerzos[], int tam, eComida comidas[], int tamCom, eEmpleado empleados[], int tamEmp)
{
    int flag=0;

    for(int i=0; i<tam;i++)
    {
        if(almuerzos[i].isEmpty == 0){
            listarAlmuerzo(almuerzos[i], comidas, tamCom, empleados, tamEmp);
            flag=1;
        }
    }

    if(!flag){
        printf("No hay almuerzo que listar\n");
    }

}

int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam)
{

    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(almuerzos[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int altaAlmuerzo(int idAlmuerzo, eAlmuerzo almuerzos[], int tamal, eEmpleado vec[], int tamEmp, eSector sectores[], int tamSec, eComida comidas[], int tamCom)
{
    int todoOk=0;
    eAlmuerzo nuevoAlmuerzo;
    int indice;

    system("cls");
    printf("****Alta almuerzo****\n\n");

    indice = buscarLibreAlmuerzo (almuerzos, tamal);

    if (indice == -1)
    {
        printf("Sistema completo. No se puede dar de alta\n");
    }else
    {
        mostrarEmpleados(vec, tamEmp, sectores, tamSec);
        printf("Ingrese id empleado: ");
        scanf("%d", &nuevoAlmuerzo.idEmpleado);

        listarComidas(comidas, tamCom);
        printf("Ingrese id de comida: ");
        scanf("%d", &nuevoAlmuerzo.idComida);

        printf("Ingrese dia de ingreso: ");
        scanf("%d", &nuevoAlmuerzo.fecha.dia);

        printf("Ingrese mes de ingreso: ");
        scanf("%d", &nuevoAlmuerzo.fecha.mes);

        printf("Ingrese anio de ingreso: ");
        scanf("%d", &nuevoAlmuerzo.fecha.anio);

        nuevoAlmuerzo.id = idAlmuerzo;
        nuevoAlmuerzo.isEmpty=0;

        almuerzos[indice]= nuevoAlmuerzo;

        todoOk=1;
    }

    return todoOk;
}

int cargarDescripcionComidas(char descripcion[], int id, eComida comidas[], int tam)
{
    int todoOk=0;

    for(int i=0; i<tam; i++)
    {
        if(comidas[i].id==id){
            strcpy(descripcion,comidas[i].descripcion);
            todoOk=1;
        }

    }

   return todoOk;
}

int cargarNombreEmpleado(char nombre[], int id, eEmpleado empleados[], int tam)
{
    int todoOk=0;

    for(int i=0; i<tam; i++)
    {
        if(empleados[i].id==id){
            strcpy(nombre,empleados[i].nombre);
            todoOk=1;
        }

    }

   return todoOk;
}

void listarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamCom, eEmpleado empleados[], int tamEmp)
{
    char descComida[20];
    char nombreEmp[20];

    cargarDescripcionComidas(descComida, almuerzo.idComida, comidas, tamCom);
    cargarNombreEmpleado(nombreEmp, almuerzo.idEmpleado, empleados, tamEmp);
    printf("%15s   %5d  %15s %d/%d/%d", nombreEmp, almuerzo.id, descComida, almuerzo.fecha.dia, almuerzo.fecha.mes, almuerzo.fecha.anio);

}
