#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "lavadero.h"
#include "eTrabajo.h"
#include "eAuto.h"

void ordenarAutos(eAuto* autos, eMarca* marcas, int tamAu, int tamMa)
{
    eAuto auxAuto;

    if(autos != NULL && tamAu > 0 && marcas != NULL && tamMa > 0)
    {
        for(int i=0; i < tamAu - 1; i++)
        {
            for(int j=1; j < tamAu; j++)
            {
                if(autos[i].idMarca < autos[j].idMarca)
                {
                    auxAuto = autos[i];
                    autos[i]=autos[j];
                    autos[j]=auxAuto;
                }
            }
        }

        for(int m=0; m < tamMa; m++)
        {
            for(int i=0; i < tamAu -1; i++)
            {
                for(int j=1; j< tamAu; j++)
                {
                    if(autos[i].idMarca == m && autos[j].idMarca == m)
                    {
                        if(autos[i].patente < autos[j].patente)
                        {
                            auxAuto = autos[i];
                            autos[i]=autos[j];
                            autos[j]=auxAuto;
                        }
                    }
                }
            }
        }
    }
}

int altaAuto(eAuto* autos, int tamAu)
{
    int retorno = -1;
    int index = buscarLibreAuto(autos, tamAu);
    eAuto auxAuto;
    int contador = 0;

    if(autos != NULL && tamAu > 0)
    {
        system("cls");
        printf("********* ALTA AUTO ********\n\n");

        if(index == -1)
        {
            printf("Sistema completo. Sin lugares-\n");
        }
        else
        {

            fflush(stdin);
            if((utn_getNumeroEntero(&auxAuto.id, "\nIngresa el id: ", "\nError, solo numeros.\n",1 , 50000, 2)) == 0)
            {
                contador++;
            }

            fflush(stdin);
            if((contador == 1) &&(utn_getAlfanumerico(auxAuto.patente, "\nIngresa la patente (Numeros y letras Mayuscula): ", "\nError, solo numeros y letras en mayuscula.\n", 2)) == 0)
            {
                printf("Patente: %s\n", auxAuto.patente);
                contador++;
            }

            fflush(stdin);
            if((contador == 2) && (utn_getNumeroEntero(&auxAuto.idMarca, "\nIngresa la marca\n1000-Renault\n1001-Fiat\n1002-Ford\n1003-Chevrolet\n1004-Peugeot: ", "\nError, marca no valida.\n", 1000, 1004, 2) == 0))
            {
                contador++;
            }
            fflush(stdin);
            if((contador == 3) && (utn_getNumeroEntero(&auxAuto.idColor, "\nIngresa el color\n5000-Negro\n5001-Blanco\n5002-Gris\n5003-Rojo\n5004-Azul: ", "\nError, ingrese nuevamente el color.\n", 5000, 5004, 2) == 0))
            {
                contador++;
            }
            if((contador == 4) &&(utn_getNumeroEntero(&auxAuto.modelo, "\nIngresa el modelo(anio): ", "\nError, solo numeros", 1900, 2020, 2) == 0))
            {
                contador++;
            }
            if(contador == 5)
            {
                auxAuto.isEmpty = 0;

                autos[index] = auxAuto;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int modificarAuto(eAuto* autos, int tamAu)
{
    int retorno = -1;
    int index;
    int opcionMenu;
    char confirm;
    char patente[10];
    int nuevoIdColor;
    int nuevoModelo;

        system("cls");
        if((utn_getAlfanumerico(patente, "Ingresa la patente: ", "Error, ingresa solo numeros y letras mayusuculas.", 2)) == 0)
        {
            index = buscarAuto(patente, autos, tamAu);
        }
        if(index == -1)
        {
            printf("\nNo hay registro de ese auto.\n");
        }
        else
        {
            system("pause");
            fflush(stdin);
            if(utn_getCharacter(&confirm, "¿Confirma la modificacion de este auto (s/n)?", "Error, ingrese (s/n): ", 's', 'n', 2) == 0)
            {
                if( confirm == 's')
                {
                    do
                    {
                        opcionMenu = menuModificar();
                        switch(opcionMenu)
                        {
                        case 1:
                            fflush(stdin);
                            if((utn_getNumeroEntero(&nuevoIdColor, "\nIngrese el nuevo color: \n5000-Negro\n5001-Blanco\n5002-Gris\n5003-Rojo\n5004-Azul", "Error, ingrese un numero por favor", 5000, 5004, 2))== 0)
                            {
                                autos[index].idColor = nuevoIdColor;
                                retorno = 0;
                            }
                            break;
                        case 2:
                            fflush(stdin);
                            if((utn_getNumeroEntero(&nuevoModelo, "\nIngrese el nuevo modelo(anio): ", "Error, ingrese un numero por favor", 1900, 2020, 2))== 0)
                            {
                                autos[index].modelo = nuevoModelo;
                                retorno = 0;
                            }
                            break;
                        case 3:
                            printf("\n Salida exitosa");
                            break;
                        default:
                            printf("\nNo es una opcion valida");
                            break;
                        }
                    }while (opcionMenu!=3);
                }
                else
                {
                    printf("Se cancelo la operacion.\n\n");
                }
            }
        }

    return retorno;
}

int menuModificar()
{
    int opcion;

    system("cls");
    printf("******** MENU DE MODIFICACIONES DEL AUTO********\n\n");
    printf("1- Modificar Color\n");
    printf("2- Modificar Modelo\n");
    printf("3- Salir\n\n");
    fflush(stdin);
    if(utn_getNumeroEntero(&opcion, "Ingresa la opcion: ", "Por favor ingresa una opcion valida.", 1, 3, 2) == 0)
    {
        printf("\nOpcion %d\n", opcion);
    }

    return opcion;
}

int bajaAuto(eAuto* autos, int tamAu)
{
    int retorno = -1;
    char patenteAuto[10];
    int index;
    char confirm;

    system("cls");
    if(autos != NULL && tamAu > 0)
    {
        printf("************ BAJA AUTO ************\n\n");

        if((utn_getAlfanumerico(patenteAuto, "Ingresa la patente: ", "Error, ingresa solo numeros y letras mayusculas.", 2)) == 0)
        {
            index = buscarAuto(patenteAuto, autos, tamAu);
        }
        if(index == -1)
        {
            printf("\nNo hay registro de ese auto.\n");
        }
        else
        {
            if(utn_getCharacter(&confirm, "¿Confirma la baja de este auto (s/n)?", "Error, ingrese (s/n): ", 's', 'n', 2) == 0)
            {
                if(confirm == 's')
                {
                    autos[index].isEmpty = 1;
                    printf("Baja realizada con exito!\n\n");
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

void listarAutos(eAuto* autos, eMarca* marcas, eColor* colores, int tamAu, int tamMa, int tamCo)
{
    int flag=1;

    ordenarAutos(autos, marcas, tamAu, tamMa);

    printf("   ID        PATENTE           MARCA           COLOR          MODELO    \n\n");
    for(int i=0; i<tamAu; i++)
    {
        if(autos[i].isEmpty==0)
        {
            listarAuto(autos[i], marcas, colores, tamAu, tamMa, tamCo);
            flag=0;
        }

    }
    if(flag==1)
    {
        printf("No hay autos para mostrar");
    }

}

void listarAuto(eAuto autos, eMarca* marcas, eColor* colores, int tamAu, int tamMa, int tamCo)
{
    char marcaAuto[20];
    char colorAuto[20];

    cargarMarcaAuto(marcaAuto, autos.idMarca, marcas, tamMa);
    cargarColorAuto(colorAuto, autos.idColor, colores, tamCo);

    printf("%2d             %6s         %7s           %7s          %2d         \n\n", autos.id, autos.patente, marcaAuto, colorAuto, autos.modelo);

}

int cargarMarcaAuto(char* descripcion, int idAuto, eMarca* marcas, int tamMa)
{
    int todoOk=0;

    for(int i=0; i<tamMa; i++)
    {
        if(marcas[i].id == idAuto)
        {
            strcpy(descripcion, marcas[i].descripcion);
            todoOk=1;
        }
    }

   return todoOk;
}

int cargarColorAuto(char* descripcion, int idAuto, eColor* colores, int tamCo)
{
    int todoOk=0;

    for(int i=0; i<tamCo; i++)
    {
        if(colores[i].id == idAuto)
        {
            strcpy(descripcion, colores[i].nombreColor);
            todoOk=1;
        }
    }

   return todoOk;
}

int buscarAuto(char* patente, eAuto* autos, int tamAu)
{
    int indice = -1;

    for(int i=0; i < tamAu; i++)
    {
        if(strcmp(autos[i].patente, patente) == 0 && autos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarLibreAuto(eAuto* autos, int tamAu)
{
    int index = -1;

    if(autos != NULL && tamAu > 0)
    {
        for(int i=0; i < tamAu; i++)
        {
            if(autos[i].isEmpty == 1)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

void inicializarAutos(eAuto* autos, int tamAu)
{
    for(int i=0; i<tamAu; i++)
    {
        autos[i].isEmpty = 1;
    }

}

