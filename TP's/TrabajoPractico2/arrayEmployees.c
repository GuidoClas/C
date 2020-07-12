#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayEmployees.h"
#include "UTN.h"




int initEmployees(eEmployee* vec, int tam)
{
    int retorno= -1; //Retorna -1 en caso de fracaso.

    if(vec != NULL && tam > 0) //Verifica que los parametros recibidos esten correctos.
    {
        for(int i=0; i < tam; i++)//Recorre el vector de empleados y coloca en todos su campo isEmpty en 1.
        {
            vec[i].isEmpty = 1;
        }
        retorno = 0; //Retorna 0 en caso de exito.
    }

    return retorno;
}

int mostrarMenu()
{
    int opcion;

    system("Cls");
    printf("************** GESTION DE OPERACIONES **************\n\n");
    printf("1- ALTA EMPLEADO\n");
    printf("2- MODIFICAR EMPLEADO\n");
    printf("3- BAJA EMPLEADO\n");
    printf("4- INFORMAR EMPLEADOS\n");
    printf("5- SALIR \n");

    fflush(stdin);
    if(utn_getNumeroEntero(&opcion, "\nIngresa una opcion: ", "\nError, ingresa una opcion valida: ", 1, 5, 3) == 0) //Solicita una opcion al usuario.
    {
        printf("\nOpcion: %d", opcion);
    }

    return opcion;
}

int addEmployee(int Idx, eEmployee* vec, int tam, eSector* sectors, int tamSec)
{
    int retorno = -1;
    int opcionSector;
    int index = buscarLibre(vec, tam); //Busca una posicion libre para agregar un empleado.
    eEmployee auxEmployee;
    int contador = 0;

    if(vec != NULL && sectors != NULL && tam > 0 && tamSec > 0) //Verifica que los parametros recibidos esten correctos.
    {
        system("cls");
        printf("********* ALTA EMPLEADO ********\n\n");

        if(index == -1) //En caso de no encontrar un campo isEmpty en 1 el index sera un -1.
        {
            printf("Sistema completo. Sin lugares-\n");
        }
        else //Solicitara todos los campos al usuario menos el ID que es autoincremental y solo si logro obtener cada uno de ellos se agrega el empleado.
        {
            auxEmployee.id = Idx;

            fflush(stdin);
            if((utn_getString(auxEmployee.name, "\nIngresa el nombre: ", "\nError, ese no es un nombre valido.\n", 2)) == 0)
            {
                formalizarString(auxEmployee.name);
                printf("%s\n", auxEmployee.name);
                contador++;
            }

            fflush(stdin);
            if((contador == 1) && (utn_getString(auxEmployee.lastName, "\nIngresa el apellido: ", "\nError, ese no es un apellido valido.\n", 2) == 0))
            {
                formalizarString(auxEmployee.lastName);
                printf("%s\n", auxEmployee.lastName);
                contador++;
            }
            fflush(stdin);
            if((contador == 2) && (utn_getNumeroFlotante(&auxEmployee.salary, "\nIngresa el sueldo: ", "\nError, ese no es un sueldo valido.\n", 0, 1000000000, 2) == 0))
            {
                printf("%.2f\n", auxEmployee.salary);
                contador++;
            }
            if((contador == 3) &&(funcionSector(&opcionSector) == 0))
            {
                auxEmployee.idSector = opcionSector;
                contador++;
            }
            if(contador == 4)
            {
                auxEmployee.isEmpty = 0;

                vec[index] = auxEmployee;

                retorno = 0;
            }
        }

    }
    return retorno;
}

int modifyEmployee(eEmployee* vec, int tam, eSector* sectors, int tamSec)
{
    int retorno = -1;
    int id;
    int index;
    char confirm;
    int opcionMenu;
    char nuevoNombre[51];
    char nuevoApellido[51];
    float nuevoSueldo;
    int opcionSector;

    system("cls");
    if(vec != NULL && tam > 0 && sectors != NULL && tamSec > 0) //Verifica que los parametros recibidos esten correctos.
    {
        printf("************ MODIFICAR EMPLEADO ************\n\n");
        if((utn_getNumeroEntero(&id, "Ingresa el ID: ", "\nError, ingresa solo numeros.", 1000, 2000, 2)) == 0)
        {
            printf("\nID: %d", id);
        }
        index = buscarEmpleado(id, vec, tam); //Buscara si existe un empleado con ese id.
        if(index == -1) //Si no existe un empleado con ese id, index sera -1.
        {
            printf("\nNo hay registro de ese empleado.\n");
        }
        else //Si existe el empleado, confirma la modificacion y le da a elegir al usuario que quiere modificar menos el id.
        {
            printf(" ID          NOMBRE               APELLIDO                   SUELDO     SECTOR \n");
            printEmployee(vec[index], sectors, tamSec);
            system("pause");
            fflush(stdin);
            if(utn_getCharacter(&confirm, "¿Confirma la modificacion de este empleado (s/n)?", "Error, ingrese (s/n): ", 's', 'n', 2) == 0)
            {
                if( confirm == 's')
                {
                    do
                    {
                        opcionMenu = menuModificar();
                        switch(opcionMenu)
                        {
                        case 1: //nombre
                            fflush(stdin);
                            if((utn_getString(nuevoNombre, "Ingrese el nuevo nombre: ", "Error, ingrese un nombre por favor", 2))== 0)
                            {
                                formalizarString(nuevoNombre);
                                strcpy(vec[index].name, nuevoNombre);
                                retorno = 0;
                            }
                            break;
                        case 2: //apellido
                            fflush(stdin);
                            if((utn_getString(nuevoApellido, "Ingrese el nuevo apellido: ", "Error, ingrese un apellido por favor.", 2))== 0)
                            {
                                formalizarString(nuevoApellido);
                                strcpy(vec[index].lastName, nuevoApellido);
                                retorno = 0;
                            }
                            break;
                        case 3: //sueldo
                            fflush(stdin);
                            if((utn_getNumeroFlotante(&nuevoSueldo, "Ingrese el nuevo sueldo: ", "Error, ingrese un sueldo valido por favor.", 0, 1000000000, 2))== 0)
                            {
                                vec[index].salary = nuevoSueldo;
                                retorno = 0;
                            }
                            break;
                        case 4: //sector
                            fflush(stdin);
                            if((funcionSector(&opcionSector)) == 0) //Despliega un menu para elegir sectores ingresando el numero correspondiente al idSector.
                            {
                                vec[index].idSector = opcionSector;
                                retorno = 0;
                            }
                            break;
                        case 5:
                            printf("Salida con exito!\n");
                            retorno = 0;
                            break;
                        default:
                            printf("No es una opcion valida\n");
                            break;
                        }
                    }while(opcionMenu != 5);

                }
                else
                {
                    printf("Se cancelo la operacion.\n\n");
                }
            }
        }
    }
    return retorno;
}

int removeEmployee(eEmployee* vec, int tam, eSector* sectors, int tamSec)
{
    int retorno = -1;
    int id;
    int index;
    char confirm;


    system("cls");
    if(vec != NULL && tam > 0 && sectors != NULL && tamSec > 0) //Verifica que los parametros recibidos esten correctos.
    {
        printf("************ BAJA EMPLEADO ************\n\n");
        if((utn_getNumeroEntero(&id, "Ingresa el ID: ", "\nError, ingresa solo numeros.", 1000, 2000, 2)) == 0)
        {
            printf("\nID: %d", id);
        }
        index = buscarEmpleado(id, vec, tam); //Buscara un empleado con ese id.
        if(index == -1) //Si no hay un empleado con ese id, index sera -1.
        {
            printf("\nNo hay registro de ese empleado.\n");
        }
        else //Si existe un empleado con ese id, confirmara la baja y colocara el campo isEmpty en la posicion index en 1.
        {
            printEmployee(vec[index], sectors, tamSec);
            system("pause");
            if(utn_getCharacter(&confirm, "¿Confirma la modificacion de este empleado (s/n)?", "Error, ingrese (s/n): ", 's', 'n', 2) == 0)
            {
                if( confirm == 's')
                {
                    vec[index].isEmpty = 1;
                    printf("Baja realizada con exito!\n\n");
                    retorno = 0;
                }
                else
                {
                    printf("Se ha cancelado la operacion.\n");
                }
            }
        }
    }

    return retorno;
}

int informEmployees(eEmployee* vec, int tam, eSector* sectors, int tamSec)
{
    int retorno = -1;
    char order;
    float totalSalarios;
    float promedioSalarios;
    int contadorEmpleadosArribaDelPromedio = 0;

    if(vec != NULL && tam > 0 && sectors != NULL && tamSec > 0) //Verifica que los parametros recibidos esten correctos.
    {

        if(utn_getCharacter(&order, "ORDENAR\n\nA- Ascendente\nD- Descendente\n", "Error, ingrese A o B.", 'A', 'D', 2)== 0) //Solicita el orden para enviar como parametro.
        {
            sortEmployees(vec, tam, order, sectors, tamSec, &totalSalarios, &promedioSalarios, &contadorEmpleadosArribaDelPromedio); //La funcion ordena los empleados y hace los calculos.

            printf("*********** EMPLEADOS ORDENADOS ALFABETICAMENTE POR APELLIDO Y POR SECTOR ***********\n\n");
            printEmployees(vec, tam, sectors, tamSec);
            getch();
            system("cls");

            printf("Total salarios: $ %.2f\n", totalSalarios);
            printf("Promedio salarios: $ %.2f\n", promedioSalarios);
            printf("Cantidad de empleados sobre el promedio: %d\n", contadorEmpleadosArribaDelPromedio);
            retorno = 0;
        }
    }

    return retorno;
}

void sortEmployees(eEmployee* vec, int tam, char order, eSector* sectors, int tamSec, float* totalSalarios, float* promedioSalarios, int* contadorEmpleados)
{
    int contadorEmpleadosTotales = 0;
    int contadorEmpleadosArribaDelPromedio = 0;
    eEmployee auxEmployee;

    if(vec != NULL && tam > 0 && (order == 'A' || order == 'D') && sectors != NULL && tamSec > 0) //Verifica que los parametros recibidos esten correctos.
    {
        if(order == 'A') //Ordena los sectores de manera Ascendiente.
        {
            for(int i=0; i < tam - 1; i++)
            {
                for(int j=i+1; j < tam; j++)
                {
                    if(vec[i].idSector < vec[j].idSector)
                    {
                        auxEmployee = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmployee;
                    }
                }
            }
        }
        else //Ordena los sectores de manera Descendiente.
        {
            for(int i=0; i < tam - 1; i++)
            {
                for(int j=i+1; j < tam; j++)
                {
                    if(vec[i].idSector > vec[j].idSector)
                    {
                        auxEmployee = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmployee;
                    }
                }
            }
        }

        if(order == 'A') //Con sectores ya ordenados, ordena los empleados de manera Ascendiente.
        {
            for(int i=0; i < tam -1; i++)
            {
                for(int j=i+1; j < tam; j++)
                {
                    if(vec[i].idSector==vec[j].idSector && strcmp(vec[i].lastName, vec[j].lastName)==-1) //Ordena solo si hay diferencia en los apellidos.
                    {
                        auxEmployee = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmployee;
                    }
                    else
                    {
                        if(vec[i].idSector == vec[j].idSector && strcmp(vec[i].lastName, vec[j].lastName)==0) //Si los apellidos son iguales, los ordena por nombre.
                        {
                            if(strcmp(vec[i].name, vec[j].name)==-1)
                            {
                                auxEmployee = vec[i];
                                vec[i]=vec[j];
                                vec[j]=auxEmployee;
                            }
                        }
                    }
                }
            }
        }
        else //Con sectores ya ordenados, ordena los empleados de manera Descendiente.
        {
            for(int i=0; i < tam -1; i++)
            {
                for(int j=i+1; j < tam; j++)
                {
                    if(vec[i].idSector==vec[j].idSector && strcmp(vec[i].lastName, vec[j].lastName)==1) //Ordena solo si hay diferencia en los apellidos.
                    {
                        auxEmployee = vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxEmployee;
                    }
                    else
                    {
                        if(vec[i].idSector == vec[j].idSector && strcmp(vec[i].lastName, vec[j].lastName)==0) //Si los apellidos son iguales, los ordena por nombre.
                        {
                            if(strcmp(vec[i].name, vec[j].name)==1)
                            {
                                auxEmployee = vec[i];
                                vec[i]=vec[j];
                                vec[j]=auxEmployee;
                            }
                        }
                    }
                }
            }
        }

        for(int i=0; i < tam; i++) //Recorre el vector de empleados activos, autoincrementando el salario en cada iteracion, para calcular el total.
        {                          //Calcula tambien la cantidad de empleados totales.
            if(vec[i].isEmpty == 0)
            {
                *totalSalarios += vec[i].salary; //Guarda el valor en la direccion que recibio como parametro.
                contadorEmpleadosTotales++;
            }
        }

        *promedioSalarios = *totalSalarios/contadorEmpleadosTotales; //Calcula el salario y lo guarda en la direccion que recibio como parametro.

        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty == 0 && vec[i].salary > *promedioSalarios)
            {
                contadorEmpleadosArribaDelPromedio++; //Recorre el vector de empleados, e incrementa la variable solo si el salario de algun empleado supera el promedio calculado.
            }
        }
        *contadorEmpleados = contadorEmpleadosArribaDelPromedio; //Asigna a la direccion recibida como parametro, la cantidad de empleados superando el promedio.

    }
}

int buscarLibre(eEmployee* vec, int tam)
{
    int index = -1;

    if(vec != NULL && tam > 0) //Verifica que los parametros recibidos esten correctos.
    {
        for(int i=0; i < tam; i++) //Recorre el vector buscando una posicion libre para agregar un empleado.
        {
            if(vec[i].isEmpty == 1)
            {
                index = i; //Devuelve el indice de la posicion libre.
                break;
            }
        }
    }

    return index;
}

int buscarOcupado(eEmployee* vec, int tam)
{
    int retorno = -1;

    if(vec != NULL && tam > 0) //Verifica que los parametros recibidos esten correctos.
    {
        for(int i=0; i< tam; i++) //Recorre el vector buscando si hay alguna posicion ocupada.
        {
            if(vec[i].isEmpty == 0) //Si encontro al menos una, se rompe la iteracion y se retorna un 0.
            {
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

int buscarEmpleado(int id, eEmployee* vec, int tam)
{
    int indice = -1;

    if(id >= 0 && vec != NULL && tam > 0) //Verifica que los parametros recibidos esten correctos.
    {
        for(int i=0; i < tam; i++) //Recorre el vector verificando si existe un ID que corresponda al recibido por parametro.
        {
            if(vec[i].id == id && vec[i].isEmpty == 0)
            {
                indice = i; //Devuelve el indice de la posicion donde se encuentra ese empleado.
                break;
            }
        }
    }

    return indice;
}

void printEmployees(eEmployee* vec, int tam, eSector* sectors, int tamSec)
{
    int flag=0;

    system("cls");
    printf("\n******** LISTADO DE EMPLEADOS********\n");
    printf(" ID          NOMBRE                APELLIDO                    SUELDO                  SECTOR\n\n");

    for(int i=0; i < tam; i++) //Recorre los empleados y llama a printEmployee() para que los muestre.
    {

        if(vec[i].isEmpty==0)
        {
            printEmployee(vec[i], sectors, tamSec);
            flag=1;
        }
    }
    if(flag == 0) //Si no mostro empleados, mostrara un mensaje indicandolo.
    {
        printf("\nNo hay empleados que listar!\n");
    }

}

void printEmployee(eEmployee x, eSector* sectors, int tamSec)
{
    char nombreSector[20];
    if((cargarDescripcionSector(nombreSector, x.idSector, sectors, tamSec)) == 0) //Cargara la descripcion del sector correspondiente al empleado que recibe, en la variable local nombreSector.
    {
        printf("%4d     %10s                  %10s                %5.2f                  %10s\n", x.id, x.name, x.lastName, x.salary, nombreSector);
    }

}

int menuModificar()
{
    int opcion;

    system("cls");
    printf("******** MENU DE MODIFICACIONES ********\n\n");
    printf("1- Modificar NOMBRE\n");
    printf("2- Modificar APELLIDO\n");
    printf("3- Modificar SUELDO\n");
    printf("4- Modificar SECTOR\n");
    printf("5- Salir\n\n");
    fflush(stdin);
    if(utn_getNumeroEntero(&opcion, "Ingresa la opcion: ", "Por favor ingresa una opcion valida.", 1, 5, 2) == 0) //Solicita una opcion al usario y la devuelve.
    {
        printf("\nOpcion %d\n", opcion);
    }

    return opcion;
}


int funcionSector(int* opcionSector)
{
   int retorno = -1;

   if(opcionSector != NULL) //Verifica que los parametros recibidos esten correctos.
   {
       printf("***** SECTORES *****\n\n"); //Despliega el menu dandole a elegir al usuario el sector que desea.

       printf("1- RRHH\n");
       printf("2- Sistemas\n");
       printf("3- Contable\n");
       printf("4- Compras\n");
       printf("5- Ventas\n");
       printf("6- Limpieza\n");
       printf("7- Direccion");
       if( (utn_getNumeroEntero(opcionSector,"\nIngresa el sector: ","No es un sector valido.", 1, 7, 2) ) == 0 )
       {
           retorno = 0;
       }
   }

   return retorno;
}

int cargarDescripcionSector(char* descripcion, int id, eSector* sectors, int tamSec)
{
    int retorno = -1;

    for(int i=0; i < tamSec; i++) //Recorre los sectores, verificando que el id recibido como parametro corresponda a algun sector.
    {                             //De ser asi, cargara la descripcion de ese sector, en la direccion de la variable que recibio como parametro.
        if(sectors[i].id == id)
        {
            strcpy(descripcion, sectors[i].descripcion);
            retorno = 0;
        }
    }

    return retorno;
}
