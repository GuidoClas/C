#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "informes.h"
#include "sectores.h"
#include "almuerzo.h"
#include "comida.h"
#include "UTN.h"

#define TAM 20
#define TAMSEC 5
#define TAMAL 50
#define TAMCOM 5


int mostrarMenu();

int main()
{
    int opcionMenu;
    int proximoIdAlmuerzo=20000;
    eEmpleado lista[TAM];
    inicializarEmpleados(lista, TAM);
    eSector sectores[]={{1, "Sistemas"}, {2, "RR.HH"}, {3, "Ventas"}, {4, "Compras"}, {5, "Contable"}};
    eAlmuerzo almuerzos[TAMAL];
    inicializarAlmuerzos(almuerzos, TAMAL);

    eComida comidas[5]={{1, "pizza", 100},
                {2, "milaneza", 80},
                {3, "asado", 150},
                {4, "hamburgesa", 120},
                 {5, "Ensalada", 90}};
    do
    {

        opcionMenu = mostrarMenu();
        system("cls");
        switch(opcionMenu)
        {
        case 1:
            //altaEmpleado(lista, TAM, TAMSEC, sectores);
            hardcodearEmpleados(lista,10);
            break;
        case 2:
            modificarEmpleado(lista, TAM);
            break;
        case 3:
            bajaEmpleado(lista, TAM);
            break;
        case 4:
            ordenarEmpleados(lista, TAM);
            break;
        case 5:
            mostrarEmpleados(lista, TAM, sectores, TAMSEC);
            break;
        case 6:
            informar(lista, TAM, sectores, TAMSEC);
            break;
        case 7:
            altaAlmuerzo(proximoIdAlmuerzo, almuerzos, TAMAL, lista, TAM, sectores, TAMSEC, comidas, TAMCOM);
            break;
        case 8:
            listarAlmuerzos(almuerzos, TAMAL, comidas, TAMCOM, lista, TAM);
            break;
        case 9:
            printf("a\n");
            break;
        }
    }
    while(opcionMenu!=10);

}


int mostrarMenu()
{
    int opcion;

    printf("\n****Menu****:\n\n1.Alta empleado\n");
    printf("2.Modificar empleado\n3.Baja empleado\n");
    printf("4.Ordenar empleado\n5.Lista empleados\n");
    printf("6.Informar\n7.Alta almuerzo\n8.Listar almuerzo\n9.\n10.Salir\n");

    fflush(stdin);
    utn_getNumeroEntero(&opcion, "Ingrese opcion: ", "\nEsa opcion no es valida. ", 1, 10, 10);


    return opcion;

}

