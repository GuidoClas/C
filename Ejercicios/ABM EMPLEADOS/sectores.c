#include "sectores.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int tam)
{
    int todoOk=0;

    for(int i=0; i<tam; i++)
    {
        if(sectores[i].id==id){
            strcpy(descripcion,sectores[i].descripcion);
            todoOk=1;
        }

    }

   return todoOk;
}

void mostrarSectores(eSector sectores[], int tam){


    printf("*****Sectores*****\n");

    for(int i=0; i<tam; i++)
    {
                printf("%d   %10s   \n", sectores[i].id, sectores[i].descripcion);


    }
}
