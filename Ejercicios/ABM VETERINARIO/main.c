#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "AbmVet.h"
#include "utn.h"
//#include "dataWarehouse.h"

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
                                {1004, 2, "Blanc", "Bulldog", 5, 3, 'm', 0},
                                {1005, 2, "j", "b", 5, 3, 'm', 1},
                                {1005, 2, "j", "b", 5, 3, 'm', 1},
                                {1005, 2, "j", "b", 5, 3, 'm', 1},
                                {1005, 2, "j", "b", 5, 3, 'm', 1},
                                {1005, 2, "j", "b", 5, 3, 'm', 1},
                                {1005, 2, "j", "b", 5, 3, 'm', 1},
                                {1005, 2, "j", "b", 5, 3, 'm', 1},
                                {1005, 2, "j", "b", 5, 3, 'm', 1},
                                {1005, 2, "j", "b", 5, 3, 'm', 1}};

    eCliente clientes[TAM];
    eTipo tipos[] = { {1, "Gato"}, {2, "Perro"}, {3, "Raro"}};

    inicializarClientes(clientes, TAM);
    //inicializarMascotas(mascotas, TAMMAS);
    hardcodearClientes(clientes, 5);

    do
    {
        opcionMenu = mostrarMenu();
        system("cls");
        switch(opcionMenu)
        {
        case 1:
            system("cls");
            listarClientes(clientes, TAM);
            system("pause");
            break;
        case 2:
            system("cls");
            listarMascotas(clientes, mascotas, tipos, TAMMAS, TAMTIP, TAM);
            system("pause");
            break;
        case 3:
            system("cls");
            listarAmbos(clientes, mascotas, tipos, TAM, TAMMAS, TAMTIP);
            system("pause");
            break;
        case 4:
            altaMascota(mascotas, clientes, TAMMAS, TAM);
            system("pause");
            break;
        case 5:
            bajaMascota(mascotas, clientes, TAMMAS, TAM);
            system("pause");
            break;
        case 6:
            modificarMascota(mascotas, clientes, TAM, TAMMAS);
            system("pause");
            break;
        case 7:
            printf("\n salida exitosa");
        default:
            printf("No es una opcion valida\n");
            break;
        }
        system("cls");
    }
    while(opcionMenu!=7);

    return 0;

}


int mostrarMenu()
{
    int opcion;

    printf("\n***********Menu*********:\n\n");
    printf("1- Listar Clientes\n");
    printf("2- Listar Mascotas\n");
    printf("3- Listar Clientes y Mascotas\n");
    printf("4- Alta Mascota\n");
    printf("5- Baja Mascota\n");
    printf("6- Modificar Mascota\n");
    printf("7- Salir\n");


    fflush(stdin);
    utn_getNumeroEntero(&opcion, "Ingrese opcion: ", "\nEsa opcion no es valida. ", 1, 7, 10);

    return opcion;
}


