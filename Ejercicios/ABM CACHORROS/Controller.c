#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "dog.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    int retorno = -1;
    FILE* file;

    if(path != NULL && pArrayList!= NULL) // Verifico que los punteros recibidos no sean NULL
    {
        ll_clear(pArrayList);
        file = fopen(path, "r");

        if(file != NULL) // Verifico que el archivo abierto no sea NULL
        {
            if(!parser_DogFromText(file, pArrayList))
            {
                retorno = 0;
            }
            fclose(file);
        }
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_ListDogs(LinkedList* pArrayList)
{
    int retorno = -1;


    if(pArrayList != NULL) // Verifico que el puntero recibo LL no sea NULL
    {
        listDogs(pArrayList);
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
    int retorno = -1;
    FILE* file;
    int llSize;
    Dog* dog = NULL;
    int auxId;
    char auxNombre[21];
    int auxDias;
    char auxRaza[21];
    char auxReserva[4];
    char auxGenero[3];


    if(path != NULL && pArrayList != NULL) //Verifico que los punteros recibidos no sean NULL
    {
        file = fopen(path, "w");
        llSize = ll_len(pArrayList);
        if(file != NULL) //Verifico que el archivo abierto no haya devuelto NULL
        {
            for(int i=0; i<llSize; i++)
            {
                dog = (Dog*) ll_get(pArrayList, i);
                if(dog != NULL)
                {
                    dog_getId(dog, &auxId);
                    dog_getNombre(dog, auxNombre);
                    dog_getDias(dog, &auxDias);
                    dog_getRaza(dog, auxRaza);
                    dog_getReserva(dog, auxReserva);
                    dog_getGenero(dog, auxGenero);

                    fprintf(file,"%d,%s,%d,%s,%s,%s\n", auxId, auxNombre, auxDias, auxRaza, auxReserva, auxGenero);
                }
            }
            retorno = 0;
            fclose(file);
        }
    }

    return retorno;
}

int controller_filterByDays(void* dog)
{
    int retorno = 0;
    Dog* aDog = NULL;

    if(dog != NULL)
    {
        aDog = (Dog*) dog;
        if(aDog->dias > 45)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int controller_filterByGender(void* dog)
{
    int retorno = 0;
    Dog* aDog = NULL;

    if(dog != NULL)
    {
        aDog = (Dog*) dog;
        if(strcmp(aDog->genero, "H") == 0)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int controller_filterByBreed(void* dog)
{
    int retorno = 0;
    Dog* aDog = NULL;

    if(dog != NULL)
    {
        aDog = (Dog*) dog;
        if(strcmp(aDog->raza, "Callejero") == 0)
        {
            retorno = 1;
        }
    }

    return retorno;
}

int mainMenu()
{
    int option;

    printf("\n---------------------- Menu de Opciones ----------------------\n\n");
    printf("1. Cargar los datos de los perros (modo texto).\n");
    printf("2. Imprimir lista de perros.\n");
    printf("3. Filtrar sin perros menores a 45 dias.\n");
    printf("4. Filtrar sin perros macho.\n");
    printf("5. Generar listado de callejeros.\n");
    printf("6. Salir\n");
    utn_getNumeroEntero(&option, "Ingresa la opcion: ", "Error, opcion del 1 al 6 solamente: ", 1, 6, 3);

    return option;
}



