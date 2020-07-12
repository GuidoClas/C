#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "lavadero.h"
#include "eTrabajo.h"
#include "eAuto.h"

int altaTrabajo(int proximoIdTrabajo, eTrabajo* trabajos, eAuto* autos, eServicio* servicios ,int tamTra, int tamAu, int tamSer)
{
    int retorno = -1;
    int index = buscarLibreTrabajo(trabajos, tamTra);
    char patente[10];
    eTrabajo auxTrabajo;
    int idServicio;
    int contador = 0;
    eFecha fechaTrabajo;


    if(trabajos != NULL && tamTra > 0)
    {
        system("cls");
        printf("********* ALTA TRABAJO ********\n\n");

        if(index == -1)
        {
            printf("Sistema completo. Sin lugares-\n");
        }
        else
        {
            if((utn_getAlfanumerico(patente, "\nIngresa la patente del auto: ", "\nError, solo numeros y letras mayusculas.\n", 2)) == 0 && buscarAuto(patente, autos, tamAu) == -1)
            {
                printf("\n No existe un auto con esa patente");
            }
            else if((utn_getNumeroEntero(&idServicio, "\nIngresa el servicio:\n20000- Lavado\n20001-Pulido\n20002-Encerado\n20003-Completo: ", "\nError, solo numeros.\n", 20000, 20003, 2)) == 0 && buscarServicio(idServicio, servicios, tamSer) == -1)
            {
                printf("\n No existe un servicio con ese ID");
            }
            else
            {
                if(utn_getNumeroEntero(&fechaTrabajo.dia, "\nIngrese el dia: ", "Ingrese un dia valido", 1, 31, 2) == 0)
                {
                    contador++;
                }
                if((contador == 1) && (utn_getNumeroEntero(&fechaTrabajo.mes, "\nIngrese el mes: ", "Ingrese un mes valido", 1, 12, 2) == 0))
                {
                    contador++;
                }
                if((contador == 2) && (utn_getNumeroEntero(&fechaTrabajo.anio, "\nIngrese el anio: ", "Ingrese un anio valido", 1950, 2050, 2) == 0))
                {
                    contador++;
                }
                if(contador == 3)
                {
                    auxTrabajo.id = proximoIdTrabajo;
                    auxTrabajo.fecha.dia = fechaTrabajo.dia;
                    auxTrabajo.fecha.mes = fechaTrabajo.mes;
                    auxTrabajo.fecha.anio = fechaTrabajo.anio;
                    auxTrabajo.idServicio = idServicio;
                    strcpy(auxTrabajo.patente, patente);
                    auxTrabajo.isEmpty = 0;
                    trabajos[index] = auxTrabajo;
                    //trabajos[index].id = proximoIdTrabajo;
                    //trabajos[index].fecha.dia = fechaTrabajo.dia;
                    //trabajos[index].fecha.mes = fechaTrabajo.mes;
                    //trabajos[index].fecha.anio = fechaTrabajo.anio;
                    //trabajos[index].idServicio = idServicio;
                    //strcpy(auxTrabajo.patente, patente);
                    //strcpy(trabajos[index].patente, patente);
                    //trabajos[index].isEmpty = 0;

                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

int buscarLibreTrabajo(eTrabajo* trabajos, int tamTra)
{
    int index = -1;

    if(trabajos != NULL && tamTra > 0)
    {
        for(int i=0; i < tamTra; i++)
        {
            if(trabajos[i].isEmpty == 1)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

void listarTrabajos(eTrabajo* trabajos, eServicio* servicios, int tamTra, int tamSer)
{
    int flag=1;

    printf("   ID        PATENTE           SERVICIO           FECHA\n\n");

    for(int i=0; i<tamTra; i++)
    {
        if(trabajos[i].isEmpty==0)
        {
            listarTrabajo(trabajos[i], servicios, tamTra, tamSer);
            flag=0;
        }

    }
    if(flag==1)
    {
        printf("No hay trabajos para mostrar");
    }

}

void listarTrabajo(eTrabajo x, eServicio* servicios, int tamTra, int tamSer)
{
    char descripcionServicio[20];

    cargarDescripcionServicio(descripcionServicio, x.idServicio, servicios, tamSer);

    printf("%2d             %7s         %7s          %d/%d/%d\n\n", x.id, x.patente, descripcionServicio, x.fecha.dia, x.fecha.mes, x.fecha.anio);

}

int cargarDescripcionServicio(char* descripcion, int idServicio, eServicio* servicios, int tamSer)
{
    int todoOk=0;

    for(int i=0; i<tamSer; i++)
    {
        if(servicios[i].id == idServicio)
        {
            strcpy(descripcion, servicios[i].descripcion);
            todoOk=1;
        }
    }

   return todoOk;
}

void inicializarTrabajos(eTrabajo* trabajos, int tamTra)
{
    for(int i=0; i<tamTra; i++)
    {
        trabajos[i].isEmpty = 1;
    }

}

