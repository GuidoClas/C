#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABMFUNC.h"

#define TAM 10
#define TAMMAS 20
#define TAMTIP 3




int mostrarMenu();

int main()
{
    int opcionMenu;
    //int proximoId;
    eMascota mascotas[TAMMAS] ={{1000, 1, "Kichana", "Persa", 5, 3, 'f', 0},
                                {1000, 1, "Macrina", "Persas", 3, 1.5, 'f', 0},
                                {1001, 2, "Bro", "Doberman", 2, 5, 'm', 0},
                                {1001, 2, "Negro", "Doberman", 3, 3, 'm', 0},
                                {1001, 1, "Michi", "Siames", 2, 2, 'm', 0},
                                {1002, 2, "Dogo", "Pitbull", 3, 4, 'm', 0},
                                {1002, 3, "Mik", "Iguana", 1, 0.5, 'm', 0},
                                {1003, 2, "Misty", "Labrador", 6, 5, 'm', 0},
                                {1004, 1, "Jorge", "Persa", 3, 2, 'm', 0},
                                {1004, 1, "Bella", "Persa", 3, 2, 'f', 0},
                                {1004, 1, "Blanc", "Bulldog", 5, 3, 'm', 0}};

    eCliente clientes[TAM];
    eTipo tipos[] = { {1, "Gato"}, {2, "Perro"}, {3, "Raro"}};

    inicializarClientes(clientes, TAM);
    //inicializarMascotas(mascotas, TAMMAS);

    do
    {
        opcionMenu = mostrarMenu();
        system("cls");
        switch(opcionMenu)
        {
        case 1:
            system("cls");
            hardcodearClientes(clientes, 5);
            listarClientes(clientes, TAM);
            break;
        case 2:
            system("cls");
            listarMascotas(clientes, mascotas, tipos, TAMMAS, TAMTIP, TAM);
            break;
        case 3:
            system("cls");
            printf("OPCION 3");
            //listarClientes();
            //listarMascotas();
            break;
        case 4:
            printf("\nSalida exitosa\n");
        default:
            printf("No es una opcion valida\n");
            break;
        }
        system("cls");
    }
    while(opcionMenu!=4);

    return 0;
}


int mostrarMenu()
{
    int opcion;

    printf("\n***********Menu*********:\n\n");
    printf("1- Listar Clientes\n");
    printf("2- Listar Mascotas\n");
    printf("3- Listar Clientes y Mascotas\n");
    printf("4- Salir\n");


    fflush(stdin);
    utn_getNumeroEntero(&opcion, "Ingrese opcion: ", "\nEsa opcion no es valida. ", 1, 10, 10);

    return opcion;
}

