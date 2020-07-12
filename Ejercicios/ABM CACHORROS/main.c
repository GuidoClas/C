#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "dog.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los perros desde el archivo data.csv (modo texto).
     2. Imprimir lista de perros.
     3. Filtrar sin perros menores a 45 dias.
     4. Filtrar sin perros macho.
     5. Generar listado de callejeros.
     6. Salir.
*****************************************************/


int main()
{
    int option;
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaMayor45Dias = ll_newLinkedList();
    LinkedList* listaHembra = ll_newLinkedList();
    LinkedList* listaCallejeros = ll_newLinkedList();
    char path1[31];
    char path2[31];
    char path3[31];

    if(lista != NULL && listaMayor45Dias != NULL && listaHembra != NULL && listaCallejeros != NULL)
    {
        do{
            option = mainMenu();
            switch(option)
            {
                //En cada uno de los casos necesarios, se verificara si existen empleados cargados, en orden de ejecutar esa funcion.
                case 1:
                    system("cls");
                    if(!utn_getString(path1, "Ingresa el nombre del archivo sin la extension .csv: ", "Error, solo el nombre: ", 3))
                    {
                        strcat(path1, ".csv");
                        if(!controller_loadFromText(path1, lista))
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
                    if(!ll_isEmpty(lista))
                    {
                        controller_ListDogs(lista);
                    }
                    else
                    {
                        printf("Debes cargar los perros antes\n");
                    }
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    listaMayor45Dias = ll_filter(lista, controller_filterByDays);
                    if(listaMayor45Dias != NULL && !utn_getString(path2, "Ingresa el nombre del archivo sin la extension .csv: ", "Error, solo el nombre: ", 3))
                    {
                        strcat(path2, ".csv");
                        if(!controller_saveAsText(path2, listaMayor45Dias))
                        {
                            printf("\nPerros mayores a 45 dias guardados correctamente en archivo\n");
                        }
                    }
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    listaHembra = ll_filter(lista, controller_filterByGender);
                    if(listaHembra != NULL && !utn_getString(path3, "Ingresa el nombre del archivo sin la extension .csv: ", "Error, solo el nombre: ", 3))
                    {
                        strcat(path3, ".csv");
                        if(!controller_saveAsText(path3, listaHembra))
                        {
                            printf("\nPerros hembra guardados correctamente en archivo\n");
                        }
                    }
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    listaCallejeros = ll_filter(lista, controller_filterByBreed);
                    if(listaCallejeros != NULL)
                    {
                        controller_ListDogs(listaCallejeros);
                    }
                    else
                    {
                        printf("Debes cargar los perros antes o no hay perros en esta lista\n");
                    }
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    printf("Salida con exito\n");
                    system("pause");
                    break;
            }

            system("cls");
        }while(option != 6);
    }

    ll_deleteLinkedList(lista);
    ll_deleteLinkedList(listaMayor45Dias);
    ll_deleteLinkedList(listaHembra);
    ll_deleteLinkedList(listaCallejeros);
    return 0;
}

