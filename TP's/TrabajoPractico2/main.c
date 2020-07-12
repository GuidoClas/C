#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayEmployees.h"
#include "UTN.h"


#define TAM 1000
#define TAMSEC 7

int main()
{
    eEmployee lista[TAM]; //Vector de empleados con tamanio definido en scope global.
    int opcionMenu; //Opcion elegida por el usuario.
    int proximoId = 1000; //Id autoincremental cada vez que se agrega un empleado.
    eSector sectors[TAMSEC] = {{1, "RRHH"}, {2, "Sistemas"}, {3, "Contable"}, {4, "Compras"}, {5, "Ventas"}, {6, "Limpieza"}, {7, "Direccion"}}; //Vector de sectores ya hardcodeado.

    if(initEmployees(lista, TAM) == 0)//Si logra inicializar los empleados, el menu podra ejecutarse.
    {
        do
        {
            opcionMenu = mostrarMenu();
            switch(opcionMenu)
            {
            case 1:
                if((addEmployee(proximoId, lista, TAM, sectors, TAMSEC) == 0))//Si logra agregar empleado, el id se autoincrementara.
                {
                    printf("\nAlta realizada con exito!\n");
                    proximoId++;
                }
                else
                {
                    printf("\nHa fallado el sistema. Volver a intentar.\n");
                }
                break;
            case 2:
                if(buscarOcupado(lista, TAM) == 0) //En caso de que haya algun empleado, se ejecutara la funcion para modificar.
                {
                    if(modifyEmployee(lista, TAM, sectors, TAMSEC) == 0)
                    {
                        printf("\nModificacion realizada con exito!\n");
                    }
                }
                else //En caso de que no haya empleados se mostrara un mensaje indicandolo.
                {
                    printf("Primero debes agregar un empleado.\n");
                }
                break;
            case 3:
                if(buscarOcupado(lista, TAM) == 0) //En caso de que haya algun empleado, se ejecutara la funcion para dar de baja.
                {
                    if((removeEmployee(lista, TAM, sectors, TAMSEC) == 0))
                    {
                        printf("\nBaja realizada con exito!\n");
                    }
                }
                else //En caso de que no haya empleados se mostrara un mensaje indicandolo.
                {
                    printf("Primero debes agregar un empleado.\n");
                }
                break;
            case 4:
                if(buscarOcupado(lista, TAM) == 0) //En caso de que haya algun empleado, se ejecutara la funcion para informar.
                {
                    if((informEmployees(lista, TAM, sectors, TAMSEC) == 0))
                    {
                        printf("\nInformes realizados con exito!\n");
                    }
                }
                else //En caso de que no haya empleados se mostrara un mensaje indicandolo.
                {
                    printf("Primero debes agregar un empleado.\n");
                }
                break;
            case 5:
                printf("Ha finalizado el programa.\n");
                break;
            default:
                    printf("No es una opcion valida\n");
                    break;
            }
            system("pause");
        } while(opcionMenu!=5);

    }
    return 0;
}


