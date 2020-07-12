#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "Client.h"
#include "utn.h"


int main()
{
    int option;
    //int flagFiltrada = 0;
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaFiltrada = ll_newLinkedList();

    do{
        option = mainMenu();
        switch(option)
        {
            //En cada uno de los casos necesarios, se verificara si existen elementos cargados, en orden de ejecutar esa funcion.
            case 1:
                system("cls");
                if(!controller_loadFromText("data.csv", lista))
                {
                    printf("\nLos datos fueron cargados correctamente\n");
                }
                else
                {
                    printf("\nLos datos no pudieron ser cargados en el sistema\n");
                }
                system("pause");
                break;
            case 2:
                system("cls");
                if(!controller_loadFromBinary("data.bin", lista))
                {
                    printf("\nLos datos fueron cargados correctamente\n");
                }
                else
                {
                    printf("\nLos datos no pudieron ser cargados en el sistema\n");
                }
                system("pause");
                break;
            case 3:
                system("cls");
                if(!controller_addClient(lista))
                {
                    printf("\nAlta realizada con exito\n");
                }
                else
                {
                    printf("\nAlta fallida\n");
                }
                system("pause");
                break;
            case 4:
                system("cls");
                if(!ll_isEmpty(lista))
                {
                    if(!controller_editClient(lista))
                    {
                        printf("Modificacion realizada con exito\n");
                    }
                    else
                    {
                        printf("Modificacion fallida\n");
                    }
                }
                else
                {
                    printf("Debes cargar o agregar clientes antes\n");
                }
                system("pause");
                break;
            case 5:
                system("cls");
                if(!ll_isEmpty(lista))
                {
                    if(!controller_removeClient(lista))
                    {
                        printf("Baja realizada con exito\n");
                    }
                    else
                    {
                        printf("Baja fallida\n");
                    }
                }
                else
                {
                    printf("Debes cargar o agregar clientes antes\n");
                }
                system("pause");
                break;
            case 6:
                system("cls");
                if(!ll_isEmpty(lista))
                {
                    listClients(lista);
                }
                else
                {
                    printf("Debes cargar o agregar clientes antes\n");
                }
                system("pause");
                break;
            case 7:
                system("cls");
                if(!ll_isEmpty(lista))
                {
                    if(!controller_sortClients(lista))
                    {
                        printf("Ordenamiento realizado con exito\n");
                    }
                    else
                    {
                        printf("Ordenamiento fallido\n");
                    }
                }
                else
                {
                    printf("Debes cargar o agregar clientes antes\n");
                }
                system("pause");
                break;
             case 8:
                system("cls");
                if(!ll_isEmpty(lista))
                {
                    if(!controller_reinsert(lista))
                    {
                        printf("Reubicacion realizada con exito\n");
                    }
                    else
                    {
                        printf("Reubicacion fallida\n");
                    }
                }
                else
                {
                    printf("Debes cargar o agregar clientes antes\n");
                }
                system("pause");
                break;
            case 9:
                system("cls");
                if(!ll_isEmpty(lista))
                {
                    if(!controller_saveAsText("data.csv", lista))
                    {
                        printf("Guardado realizado con exito\n");
                    }
                    else
                    {
                        printf("Guardado fallido\n");
                    }
                }
                else
                {
                    printf("Debes cargar o agregar clientes antes\n");
                }
                system("pause");
                break;
            case 10:
                system("cls");
                if(!ll_isEmpty(lista))
                {
                    if(!controller_saveAsBinary("data.bin", lista))
                    {
                        printf("Guardado realizado con exito\n");
                    }
                    else
                    {
                        printf("Guardado fallido\n");
                    }
                }
                else
                {
                    printf("Debes cargar o agregar clientes antes\n");
                }
                system("pause");
                break;
            case 11:
                system("cls");
                if(listaFiltrada != NULL)
                {
                    if(!controller_newFilteredList(lista, listaFiltrada))
                    {
                        printf("Lista filtrada con exito\n");
                    }
                    else
                    {
                        printf("Lista filtrada fallida\n");
                    }
                }
                system("pause");
                break;
            case 12:
                system("cls");
                if(!controller_loadFromText("dataFiltrada.csv", listaFiltrada))
                {
                    printf("\nLos datos de la lista filtrada fueron cargados correctamente\n");
                }
                else
                {
                    printf("\nPrimero debes filtrar la lista y guardarla\n");
                }
                system("pause");
                break;
            case 13:
                system("cls");
                if(!ll_isEmpty(listaFiltrada))
                {
                    listClients(listaFiltrada);
                }
                else
                {
                    printf("Debes cargar o agregar clientes antes\n");
                }
                system("pause");
                break;
            case 14:
                system("cls");
                if(!ll_isEmpty(listaFiltrada))
                {
                    if(!controller_saveAsText("dataFiltrada.csv", listaFiltrada))
                    {
                        printf("Guardado de lista filtrada realizado con exito\n");
                    }
                    else
                    {
                        printf("Guardado fallido\n");
                    }
                }
                system("pause");
                break;
            case 15:
                system("cls");
                printf("Salida con exito\n");
                break;
        }
        system("cls");
    }while(option != 15);

    ll_deleteLinkedList(listaFiltrada);
    ll_deleteLinkedList(lista);
    return 0;
}
