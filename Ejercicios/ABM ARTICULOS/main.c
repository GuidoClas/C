#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Articulo.h"
#include "utn.h"
#include "Rubro.h"


int main()
{
    LinkedList* listaArticulos = ll_newLinkedList();
    LinkedList* listaMapeada = NULL;
    int opcionMenu;
    char path1[31];
    Rubro rubros[4] = {{1, "CUIDADO DE ROPA"}, {2, "LIMPIEZA Y DESINFECCION"}, {3, "CUIDADO PERSONAL E HIGIENE"}, {4, "CUIDADO DEL AUTOMOTOR"}};

    if(listaArticulos != NULL)
    {
        do
        {
            opcionMenu = mainMenu();
            system("cls");
            switch(opcionMenu)
            {
            case 1:
                system("cls");
                if(!utn_getString(path1, "Ingresa el nombre del archivo sin la extension .csv: ", "Error, solo el nombre: ", 3))
                {
                    strcat(path1, ".csv");
                    if(!controller_loadFromText(path1, listaArticulos))
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
                if(!ll_isEmpty(listaArticulos))
                {
                    if(!ll_sort(listaArticulos, sortArticulos, 1))
                    {
                        printf("\nLos datos fueron ordenados correctamente\n");
                    }
                    else
                    {
                        printf("\nLos datos no pudieron ser ordenados correctamente\n");
                    }
                }
                else
                {
                    printf("Debes cargar los articulos antes\n");
                }
                system("pause");
                break;
            case 3:
                system("cls");
                if(!ll_isEmpty(listaArticulos))
                {
                    listArticulos(listaArticulos, rubros);
                }
                else
                {
                    printf("Debes cargar los articulos antes\n");
                }
                system("pause");
                break;
            case 4:
                system("cls");
                listaMapeada = ll_map(listaArticulos, aplicarDescuentos);
                if(listaMapeada != NULL)
                {
                    printf("Lista mapeada con exito\n");
                }
                else
                {
                    printf("Lista mapeada fallida");
                }
                system("pause");
                break;
             case 5:
                system("cls");
                if(!ll_isEmpty(listaMapeada))
                {
                    if(!controller_saveAsText("mapeado.csv", listaMapeada))
                    {
                        printf("Se logro guardar con exito en archivo\n");
                    }
                    else
                    {
                        printf("No se pudo guardar en archivo\n");
                    }
                }
                else
                {
                     printf("Debes cargar los articulos antes\n");
                }
                system("pause");
                break;
            case 6:
                system("cls");
                printf("Salida exitosa\n");
                system("pause");
                break;
            default:
                printf("No es una opcion valida\n");
                break;
            }
            system("cls");
        }
        while(opcionMenu!=6);
    }

    ll_deleteLinkedList(listaArticulos);
    return 0;
}
