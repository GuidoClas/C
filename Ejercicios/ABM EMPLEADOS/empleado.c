#include "empleado.h"
#include "sectores.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dataWarehouse.h"

void mostrarEmpleado(eEmpleado vec, eSector sectores[], int tamSec)
{
    char nombreSector[20];
    cargarDescripcionSector(nombreSector, vec.idSector, sectores, tamSec);

    printf("%4d  ", vec.id);
    printf("%15s  ", nombreSector);
    printf("%20s  ", vec.nombre);
    printf("%15s  ", vec.nombre);
    printf("%2d  ", vec.edad);
    printf("%2c  ", vec.sexo);
    printf("%.2f  ", vec.sueldo);
    printf("%d/%d/%d\n", vec.ingreso.dia, vec.ingreso.mes, vec.ingreso.anio);
}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int flag=1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarEmpleado(vec[i], sectores, tamSec);
            flag=0;
        }

    }

    if(flag==1)
    {
        printf("No hay empleados para mostrar");
    }

}

void inicializarEmpleados(eEmpleado empleados[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        empleados[i].isEmpty = 1;
    }
}


int buscarLibre(eEmpleado vec[], int tam)
{

    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado (int id, eEmpleado vec[], int tam)
{

    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].id==id && vec[i].isEmpty == 0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam, int tamsec, eSector sectores[])
{
    int indiceLibre;
    int id;
    int existe;
    eEmpleado auxEmpleado;

    printf("***Alta empleado***");

    indiceLibre=buscarLibre(vec, tam);

    if(indiceLibre==-1)
    {
        printf("\nSistema completo\n");
    }
    else
    {
        printf("\nIngrese id: \n");
        fflush(stdin);
        scanf("%d", &id);

        existe=buscarEmpleado(id, vec, tam);

        if(existe!=-1)
        {
            printf("\nYa existe un empleado registrado con este id\n");
        }
        else
        {
            auxEmpleado.id = id;

            printf("Ingrese nombre: ");
            gets(auxEmpleado.nombre);

            printf("Ingrese edad: ");
            fflush(stdin);
            scanf("%d", &auxEmpleado.edad);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &auxEmpleado.sexo);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &auxEmpleado.sueldo);

            printf("Ingrese dia de ingreso: ");
            fflush(stdin);
            scanf("%d", &auxEmpleado.ingreso.dia);

            printf("Ingrese mes de ingreso: ");
            fflush(stdin);
            scanf("%d", &auxEmpleado.ingreso.mes);

            printf("Ingrese anio de ingreso: ");
            fflush(stdin);
            scanf("%d", &auxEmpleado.ingreso.anio);

            mostrarSectores(sectores, tamsec);
            printf("\nIngrese id del sector: ");
            scanf("%d", &auxEmpleado.idSector);

            auxEmpleado.isEmpty = 0;

            vec[indiceLibre] = auxEmpleado;
        }
    }
}

void bajaEmpleado(eEmpleado vec[], int tam)
{
    int id;
    int indice;
    char confirmacion;

    system("cls");
    printf("***Baja empleado***\n");

    printf("\nIngrese id: \n");
    fflush(stdin);
    scanf("%d", &id);

    indice=buscarEmpleado(id, vec, tam);

    if(indice==-1)
    {
        printf("Este id no existe");
    }
    else
    {
        printf("\nSeguro que desea dar de baja este empleado? s/n:  ");
        fflush(stdin);
        scanf("%c", &confirmacion);

        if(confirmacion=='s')
        {
            vec[indice].isEmpty=1;
            printf("Operacion realizada con exito");
        }
        else
        {
            printf("Se cancela la operacion");
        }

    }

}

void modificarEmpleado(eEmpleado vec[], int tam)
{
    int id;
    int indice;
    char confirmacion;
    int opcion;

    system("cls");
    printf("***Modificar empleado***\n");

    printf("\nIngrese id: ");
    fflush(stdin);
    scanf("%d", &id);

    indice=buscarEmpleado(id, vec, tam);

    if(indice==-1)
    {
        printf("\nEste id no existe\n");
    }
    else
    {
        printf("\nSeguro que desea modificar este  empleado? s/n:  ");
        fflush(stdin);
        scanf("%c", &confirmacion);

        if(confirmacion=='s')
        {

            printf("\nQue desea cambiar?\n");
            printf("1. Nombre: %s\n", vec[indice].nombre);
            printf("2. Edad: %d\n", vec[indice].edad);
            printf("3. Sexo: %c\n", vec[indice].sexo);
            printf("4. Sueldo: %f\n", vec[indice].sueldo);
            printf("5. Fecha de ingreso: %d/%d/%d\n", vec[indice].ingreso.dia, vec[indice].ingreso.mes, vec[indice].ingreso.anio);
            printf("Elija una opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);

            while(opcion<1&&opcion>5)
            {
                printf("\nIngrese una opcion valida: ");
                fflush(stdin);
                scanf("%d", &opcion);
            }

            switch(opcion)
            {
            case 1:
                printf("Ingrese el nombre: ");
                fflush(stdin);
                gets(vec[indice].nombre);
                break;
            case 2:
                printf("Ingrese edad: ");
                fflush(stdin);
                scanf("%d", &vec[indice].edad);
                break;
            case 3:
                printf("Ingrese sexo: ");
                fflush(stdin);
                scanf("%c", &vec[indice].sexo);
                break;
            case 4:
                printf("Ingrese el nuevo sueldo: ");
                scanf("%f", &vec[indice].sueldo);
                break;
            case 5:
                printf("Ingrese dia de ingreso: ");
                fflush(stdin);
                scanf("%d", &vec[indice].ingreso.dia);

                printf("Ingrese mes de ingreso: ");
                fflush(stdin);
                scanf("%d", &vec[indice].ingreso.mes);

                printf("Ingrese anio de ingreso: ");
                fflush(stdin);
                scanf("%d", &vec[indice].ingreso.anio);
                break;

                printf("\nOperacion realizada con exito\n");


            }
        }
        else
        {
            printf("Se cancela la operacion\n");
        }

    }

}

void hardcodearEmpleados(eEmpleado vec[], int cant)
{


      /*  eEmpleado auxEmpleados[10]={{1233, "Pablo", 40, 'm', 24000,0, {28,5,2005}},
                            {1253, "Cristian", 22, 'm', 22000,0, {23,5,2015}},
                            {1289, "Ana", 19, 'f', 30000,0, {21,4,2005}},
                            {1614, "Juana", 28, 'f', 49000,0, {14,4,2005}},
                            {1234, "Martin", 24, 'm', 41000,0, {11,2,2013}},
                            {1567, "Carlos", 40, 'm', 50000,0, {10,5,2015}},
                            {1001, "Paula", 20, 'f', 19000,0, {31,1,2013}},
                            {1040, "Angela", 30, 'f', 24000,0, {18, 11, 2010}},
                            {1025, "Sandra", 55, 'f', 29000,0, {14,11,2010}},
                            {1099, "Esteban", 19, 'm', 20000,0,{11, 2, 2015}}};


        for(int i=0;i<10;i++)
        {
            vec[i]=auxEmpleados[i];
        }

*/

   for(int i=0; i<cant; i++)
    {

        vec[i].id=ids[i];
        strcpy(vec[i].nombre, nombres[i]);
        vec[i].sexo=sexos[i];
        vec[i].edad=edades[i];
        vec[i].sueldo=sueldos[i];
        vec[i].ingreso.dia=dias[i];
        vec[i].ingreso.mes=meses[i];
        vec[i].ingreso.anio=anios[i];
        vec[i].isEmpty=0;
        vec[i].idSector = idsSector[i];


    }

}

void ordenarEmpleados(eEmpleado vec[], int tam)
{
    eEmpleado auxiliar;
    int opcion;
    int opcionAscDesc;

    printf("\n\nCon que criterio quiere ordenar a los empleados?\n");
    printf("1. id\n");
    printf("2. nombre\n");
    printf("3. edad\n");
    printf("4. sexo\n");
    printf("5. sueldo\n");
    printf("6. Fecha\n");

    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion<1&&opcion>6)
    {
        printf("\nIngrese una opcion valida: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    printf("Desea hacerlo ascendente o descendente?\n");
    printf("1. Ascendente\n");
    printf("2. Descendete\n");

    printf("Elija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcionAscDesc);

    while(opcionAscDesc<1&&opcionAscDesc>2)
    {
        printf("\nIngrese una opcion valida: ");
        fflush(stdin);
        scanf("%d", &opcionAscDesc);
    }

    switch(opcion)
    {
    case 1:
        if(opcionAscDesc==1)
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=1; j<tam; j++)
                {
                    if(vec[i].id<vec[j].id)
                    {

                        auxiliar = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxiliar;
                    }
                }
            }

        }
        else
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=1; j<tam; j++)
                {
                    if(vec[i].id>vec[j].id)
                    {

                        auxiliar = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxiliar;
                    }
                }
            }

        }
        break;
    case 2:
        if(opcionAscDesc==1)
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=1; j<tam; j++)
                {
                    if(strcmp(vec[i].nombre, vec[j].nombre)==-1)
                    {

                        auxiliar = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxiliar;
                    }
                }
            }

        }
        else
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=1; j<tam; j++)
                {
                    if(strcmp(vec[i].nombre, vec[j].nombre)==1)
                    {

                        auxiliar = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxiliar;
                    }
                }
            }

        }
        break;
    case 3:
        if(opcionAscDesc==1)
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=1; j<tam; j++)
                {
                    if(vec[i].edad<vec[j].edad)
                    {

                        auxiliar = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxiliar;
                    }
                }
            }

        }
        else
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=1; j<tam; j++)
                {
                    if(vec[i].edad>vec[j].edad)
                    {

                        auxiliar = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxiliar;
                    }
                }
            }

        }
        break;
    case 4:
        if(opcionAscDesc==1)
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=1; j<tam; j++)
                {
                    if(vec[i].sexo<vec[j].sexo)
                    {

                        auxiliar = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxiliar;
                    }
                }
            }

        }
        else
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=1; j<tam; j++)
                {
                    if(vec[i].sexo>vec[j].sexo)
                    {

                        auxiliar = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxiliar;
                    }
                }
            }

        }
        break;
    case 5:
        if(opcionAscDesc==1)
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=1; j<tam; j++)
                {
                    if(vec[i].sueldo<vec[j].sueldo)
                    {

                        auxiliar = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxiliar;
                    }
                }
            }

        }
        else
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=1; j<tam; j++)
                {
                    if(vec[i].sueldo>vec[j].sueldo)
                    {

                        auxiliar = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxiliar;
                    }
                }
            }

        }
        break;
    case 6:
        if(opcionAscDesc==1)
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=1; j<tam; j++)
                {
                    if(vec[i].ingreso.anio<vec[j].ingreso.anio)
                    {

                        auxiliar = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxiliar;

                    }
                    else if(vec[i].ingreso.anio==vec[j].ingreso.anio)
                    {
                        if(vec[i].ingreso.mes<vec[j].ingreso.mes)
                        {

                            auxiliar = vec[i];
                            vec[i]=vec[j];
                            vec[j]=auxiliar;

                        }
                        else if(vec[i].ingreso.mes==vec[j].ingreso.mes)
                        {
                            if(vec[i].ingreso.dia<vec[j].ingreso.dia)
                            {
                                auxiliar = vec[i];
                                vec[i]=vec[j];
                                vec[j]=auxiliar;

                            }

                        }


                    }

                }
            }

        }
        else
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=1; j<tam; j++)
                {
                    if(vec[i].ingreso.anio>vec[j].ingreso.anio)
                    {

                        auxiliar = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxiliar;

                    }
                    else if(vec[i].ingreso.anio==vec[j].ingreso.anio)
                    {
                        if(vec[i].ingreso.mes>vec[j].ingreso.mes)
                        {

                            auxiliar = vec[i];
                            vec[i]=vec[j];
                            vec[j]=auxiliar;

                        }
                        else if(vec[i].ingreso.mes==vec[j].ingreso.mes)
                        {
                            if(vec[i].ingreso.dia>vec[j].ingreso.dia)
                            {
                                auxiliar = vec[i];
                                vec[i]=vec[j];
                                vec[j]=auxiliar;
                            }
                        }
                    }
                }
            }

        }
        break;

    }

}
