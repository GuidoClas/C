#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Paciente.h"
#include "utn.h"

int main()
{
    LinkedList* listaOriginal = ll_newLinkedList();
    LinkedList* listaMapeada = NULL;
    LinkedList* listaFiltradaExitosos = NULL;
    LinkedList* listaFiltradaHorno = NULL;
    int option;
    char path1[51];
    char path2[51];
    char path3[51];
    char path4[51];
    srand(time(NULL));


     if(listaOriginal != NULL)
    {
        do{
            option = mainMenu();
            switch(option)
            {
                //En cada uno de los casos necesarios, se verificara si existen elementos cargados, en orden de ejecutar esa funcion.
                case 1:
                    system("cls");
                    if(!utn_getString(path1, "Ingresa el nombre del archivo sin la extension .csv: ", "Error, solo el nombre: ", 3))
                    {
                        strcat(path1, ".csv");
                        if(!controller_loadFromText(path1, listaOriginal))
                        {
                            printf("\nLos datos fueron cargados correctamente\n");
                        }
                        else
                        {
                            printf("\nLos datos no pudieron ser cargados en el sistema\n");
                        }
                    }
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    if(listaMapeada != NULL)
                    {
                        controller_ListPacients(listaMapeada);
                    }
                    else
                    {
                        printf("Debes cargar los datos antes\n");
                    }
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    if(!ll_isEmpty(listaOriginal))
                    {
                        listaMapeada = ll_map(listaOriginal, mapearRandom);
                        if(listaMapeada != NULL)
                        {
                            printf("Lista mapeada con exito\n");
                        }
                    }
                    else
                    {
                        printf("Debes cargar los datos antes\n");
                    }
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    listaFiltradaExitosos = ll_filter(listaMapeada, controller_filterBySuccess);
                    if(listaFiltradaExitosos != NULL && !utn_getString(path2, "Ingresa el nombre del archivo sin la extension .csv: ", "Error, solo el nombre: ", 3))
                    {
                        strcat(path2, ".csv");
                        if(!controller_saveAsText(path2, listaFiltradaExitosos))
                        {
                            printf("Lista de exitosos guardados correctamente en archivo\n");
                        }
                    }
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    if(!ll_isEmpty(listaMapeada))
                    {
                        listaFiltradaHorno = ll_filter(listaMapeada, controller_filterByFailure);
                        if(listaFiltradaHorno != NULL && !utn_getString(path3, "Ingresa el nombre del archivo sin la extension .csv: ", "Error, solo el nombre: ", 3))
                        {
                            strcat(path3, ".csv");
                            if(!controller_saveAsText(path3, listaFiltradaHorno))
                            {
                                printf("Lista de paises en el horno guardados correctamente en archivo\n");
                            }
                        }
                    }
                    else
                    {
                         printf("Debes cargar los datos antes\n");
                    }
                    system("pause");
                    break;
                    break;
                 case 6:
                    system("cls");
                     if(!ll_isEmpty(listaMapeada))
                    {
                        if(!ll_sort(listaMapeada, sortInfected, 0))
                        {
                            printf("Lista ordenada correctamente\n");
                        }
                    }
                    else
                    {
                         printf("Debes cargar los datos antes\n");
                    }
                    system("pause");
                    break;
                 case 7:
                    system("cls");
                     if(!ll_isEmpty(listaMapeada))
                    {
                        if(!controller_informMorePunished(listaMapeada))
                        {
                            printf("Exito al informar\n");
                        }
                    }
                    else
                    {
                         printf("Debes cargar los datos antes\n");
                    }
                    system("pause");
                    break;
                case 8:
                    system("cls");
                    if(!ll_isEmpty(listaMapeada))
                    {
                        if(!utn_getString(path4, "Ingresa el nombre del archivo sin la extension .csv: ", "Error, solo el nombre: ", 3))
                        {
                            strcat(path4, ".csv");
                            if(!controller_saveAsText(path4, listaMapeada))
                            {
                                printf("Lista mapeada guardada correctamente en archivo\n");
                            }
                        }
                    }
                    else
                    {
                         printf("Debes cargar los datos antes\n");
                    }
                    system("pause");
                    break;
                case 9:
                    system("cls");
                    printf("Salida con exito\n");
                    system("pause");
                    break;
            }

            system("cls");
        }while(option != 9);
    }

    //Al finalizar elimino las listas para evitar ocupar espacio en memoria
    ll_deleteLinkedList(listaOriginal);
    ll_deleteLinkedList(listaMapeada);
    ll_deleteLinkedList(listaFiltradaExitosos);
    ll_deleteLinkedList(listaFiltradaHorno);

    return 0;
}
