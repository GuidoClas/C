#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "lavadero.h"
#include "eTrabajo.h"
#include "eAuto.h"

#define TAMAU 5
#define TAMMA 5
#define TAMCO 5
#define TAMSER 4
#define TAMTRA 5

int mostrarMenu();

int main()
{
    int opcionMenu;
    int proximoIdTrabajo =+ 3000;

    eTrabajo trabajos[TAMTRA] = {{2000, "AAA111", 20001, {12,5,2015}, 0},
                                {2001, "BBB222", 20003, {10,4,2014}, 0},
                                {2002, "CCC333", 20002, {12,10,2020}, 0},
                                {2003, "DDD444", 20001, {19,7,2007}, 0},
                                {2004, "EEE555", 20003, {30,3,2011}, 0}};

    eAuto autos [TAMAU] = {{1, "AAA111", 1001, 5000, 2015, 0},
                            {2, "BBB222", 1003, 5000, 2010, 0},
                            {3, "CCC333", 1001, 5002, 2016, 0},
                            {4, "DDD444", 1003, 5003, 2011, 0},
                            {5, "EEE555", 1000, 5004, 2013, 0}};

    eMarca marcas[] = {{1000, "Renault",},{1001, "Fiat"}, {1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"}};
    eColor colores[] = {{5000, "Negro"}, {5001, "Blanco"},{5002, "Gris"}, {5003, "Rojo"}, {5004, "Azul"}};
    eServicio servicios[] = {{20000, "Lavado", 250},{20001, "Pulido", 300},{20002, "Encerado", 400},{20003, "Completo", 600}};

    //inicializarAutos(autos, TAMAU);
    //inicializarTrabajos(trabajos, TAMTRA);

    do
    {
        opcionMenu = mostrarMenu();
        system("cls");
        switch(opcionMenu)
        {
        case 1:
            system("cls");
            if(altaAuto(autos, TAMAU) == 0)
            {
                printf("\nAlta con exito\n");
            }
            else
            {
                printf("\n Alta fallida\n");
            }
            system("pause");
            break;
        case 2:
            system("cls");
            if(modificarAuto(autos, TAMAU) == 0)
            {
                printf("\nModificado con exito\n");
            }
            else
            {
                printf("\n Modificacion fallida\n");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if(bajaAuto(autos, TAMAU) == 0)
            {
                printf("\nBaja con exito\n");
            }
            else
            {
                printf("\nBaja fallida\n");
            }
            system("pause");
            break;
        case 4:
            system("cls");
            listarAutos(autos, marcas, colores, TAMAU, TAMMA, TAMCO);
            system("pause");
            break;
        case 5:
            system("cls");
            listarMarcas(marcas, TAMMA);
            system("pause");
            break;
        case 6:
            system("cls");
            listarColores(colores, TAMCO);
            system("pause");
            break;
        case 7:
            system("cls");
            listarServicios(servicios, TAMSER);
            system("pause");
            break;
        case 8:
            system("cls");
            if(altaTrabajo(proximoIdTrabajo, trabajos, autos, servicios, TAMTRA, TAMAU, TAMSER) == 0)
            {
                printf("\nAlta de trabajo exitosa!\n");
                proximoIdTrabajo++;
            }
            else
            {
                printf("\nAlta de trabajo fallida\n");
            }
            system("pause");
            break;
        case 9:
            system("cls");
            listarTrabajos(trabajos, servicios, TAMTRA, TAMSER);
            system("pause");
            break;
        case 10:
            printf("\n Salida exitosa");
            break;
        default:
            printf("No es una opcion valida\n");
            break;
        }
        system("cls");
    }
    while(opcionMenu!=10);
    return 0;
}

int mostrarMenu()
{
    int opcion;

    printf("\n***********Menu*********:\n\n");
    printf("1- ALTA AUTO\n");
    printf("2- MODIFICAR AUTO\n");
    printf("3- BAJA AUTO\n");
    printf("4- LISTAR AUTOS\n");
    printf("5- LISTAR MARCAS\n");
    printf("6- LISTAR COLORES\n");
    printf("7- LISTAR SERVICIOS\n");
    printf("8- ALTA TRABAJO\n");
    printf("9- LISTAR TRABAJOS\n");
    printf("10- Salir\n");


    fflush(stdin);
    utn_getNumeroEntero(&opcion, "Ingrese opcion: ", "\nEsa opcion no es valida. ", 1, 10, 10);

    return opcion;
}
