#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bine (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        option = mainMenu();
        switch(option)
        {
            //En cada uno de los casos necesarios, se verificara si existen empleados cargados, en orden de ejecutar esa funcion.
            case 1:
                system("cls");
                if(!controller_loadFromText("data.csv",listaEmpleados))
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
                if(!controller_loadFromBinary("data.bin",listaEmpleados))
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
                if(!controller_addEmployee(listaEmpleados))
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
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_editEmployee(listaEmpleados))
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
                    printf("Debes cargar o agregar empleados antes\n");
                }
                system("pause");
                break;
            case 5:
                system("cls");
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_removeEmployee(listaEmpleados))
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
                    printf("Debes cargar o agregar empleados antes\n");
                }
                system("pause");
                break;
            case 6:
                system("cls");
                if(!ll_isEmpty(listaEmpleados))
                {
                    listEmployees(listaEmpleados);
                }
                else
                {
                    printf("Debes cargar o agregar empleados antes\n");
                }
                system("pause");
                break;
            case 7:
                system("cls");
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_sortEmployee(listaEmpleados))
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
                    printf("Debes cargar o agregar empleados antes\n");
                }
                system("pause");
                break;
            case 8:
                system("cls");
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_saveAsText("data.csv", listaEmpleados))
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
                    printf("Debes cargar o agregar empleados antes\n");
                }
                system("pause");
                break;
            case 9:
                system("cls");
               if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_saveAsBinary("data.bin", listaEmpleados))
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
                    printf("Debes cargar o agregar empleados antes\n");
                }
                system("pause");
                break;
            case 10:
                system("cls");
                printf("Salida con exito\n");
                break;
        }
        system("cls");
    }while(option != 10);


    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
