#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "lavadero.h"
#include "eTrabajo.h"
#include "eAuto.h"

void listarMarcas(eMarca* marcas, int tamMas)
{
    int flag=1;

    printf("ID              MARCA\n\n");
    for(int i=0; i<tamMas; i++)
    {
        listarMarca(marcas[i]);
        flag=0;
    }
    if(flag==1)
    {
        printf("No hay Marcas para mostrar");
    }

}

void listarMarca(eMarca x)
{
    printf("%2d        %10s   \n", x.id, x.descripcion);
}

void listarColores(eColor* colores, int tamCo)
{
    int flag=1;

    printf("ID              COLOR\n\n");
    for(int i=0; i<tamCo; i++)
    {
        listarColor(colores[i]);
        flag=0;
    }
    if(flag==1)
    {
        printf("No hay colores para mostrar");
    }

}

void listarColor(eColor x)
{
    printf("%2d        %10s   \n", x.id, x.nombreColor);
}

void listarServicios(eServicio* servicios, int tamSer)
{
    int flag=1;

    printf("ID                 TIPO    PRECIO\n\n");
    for(int i=0; i<tamSer; i++)
    {
        listarServicio(servicios[i]);
        flag=0;
    }
    if(flag==1)
    {
        printf("No hay servicios para mostrar");
    }

}

void listarServicio(eServicio x)
{
    printf("%2d        %10s    %.2f\n", x.id, x.descripcion, x.precio);
}

int buscarServicio(int idServicio, eServicio* servicios, int tamSer)
{
    int indice = -1;

    for(int i=0; i < tamSer; i++)
    {
        if(servicios[i].id == idServicio)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
