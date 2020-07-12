#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Paciente.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los elementos desde el archivo pandemia.csv (modo texto).
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
            if(!parser_PacientFromText(file, pArrayList))
            {
                retorno = 0;
            }
            fclose(file);
        }
    }

    return retorno;
}

/** \brief Listar los paises
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_ListPacients(LinkedList* pArrayList)
{
    int retorno = -1;


    if(pArrayList != NULL) // Verifico que el puntero recibo LL no sea NULL
    {
        listPacients(pArrayList);
    }

    return retorno;
}

/** \brief Guarda los datos de los paises en el archivo path (modo texto).
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
    Paciente* paciente = NULL;
    int auxId;
    char auxPais[51];
    int auxInfectados;
    int auxRecuperados;
    int auxMuertos;


    if(path != NULL && pArrayList != NULL) //Verifico que los punteros recibidos no sean NULL
    {
        file = fopen(path, "w");
        llSize = ll_len(pArrayList);
        if(file != NULL) //Verifico que el archivo abierto no haya devuelto NULL
        {
            for(int i=0; i<llSize; i++)
            {
                paciente = (Paciente*) ll_get(pArrayList, i);
                if(paciente != NULL)
                {
                    paciente_getId(paciente, &auxId);
                    paciente_getPais(paciente, auxPais);
                    paciente_getInfectados(paciente, &auxInfectados);
                    paciente_getRecuperados(paciente, &auxRecuperados);
                    paciente_getMuertos(paciente, &auxMuertos);

                    fprintf(file,"%d,%s,%d,%d,%d\n", auxId, auxPais, auxInfectados, auxRecuperados, auxMuertos);
                }
            }
            retorno = 0;
            fclose(file);
        }
    }

    return retorno;
}

/** \brief Funcion que se le llama en ll_filter para crear una nueva lista con los paises exitosos
 *
 * \param Recibe el puntero al elemento para determinar el filtro
 * \return Retorna 1 en caso de que deba ser agregado a la nueva LL
 *
 */

int controller_filterBySuccess(void* pac)
{
    int retorno = 0;
    Paciente* paciente = NULL;
    int muertos;

    if(pac != NULL)
    {
        paciente = (Paciente*) pac;
        paciente_getMuertos(paciente, &muertos);
        if(muertos < 5000)
        {
            retorno = 1;
        }
    }

    return retorno;
}

/** \brief Funcion que se le llama en ll_filter para crear una nueva lista con los paises complicados
 *
 * \param Recibe el puntero al elemento para determinar el filtro
 * \return Retorna 1 en caso de que deba ser agregado a la nueva LL
 *
 */
int controller_filterByFailure(void* pac)
{
    int retorno = 0;
    Paciente* paciente = NULL;
    int infectados;
    int recuperados;

    if(pac != NULL)
    {
        paciente = (Paciente*) pac;
        paciente_getInfectados(paciente, &infectados);
        paciente_getRecuperados(paciente, &recuperados);
        if(recuperados*3 <= infectados)
        {
            retorno = 1;
        }
    }

    return retorno;
}

/** \brief Se encarga de informar el pais con mas muertos y su cantidad
 *
 * \param Recibe la LL
 * \return Retorna 0 en caso de exito o -1 en caso contrario
 *
 */

int controller_informMorePunished(LinkedList* pArrayList)
{
    int flag = 0;
    int retorno = -1;
    Paciente* paciente = NULL;
    int mayorCantidad;
    int muertos;
    char pais[51];


    if(pArrayList != NULL)
    {
        for(int i=0; i<ll_len(pArrayList); i++)
        {
            paciente = (Paciente*) ll_get(pArrayList, i);
            paciente_getMuertos(paciente, &muertos);
            if(flag == 0 || muertos > mayorCantidad)
            {
                    mayorCantidad = muertos;
                    paciente_getPais(paciente, pais);
                    flag = 1;
                    retorno = 0;
            }
        }

        printf("Pais con mas muertos: %10s\n", pais);
        printf("Cantidad de muertos: %10d\n", mayorCantidad);
    }


    return retorno;
}

int mainMenu()
{
    int option;

    printf("\n---------------------- Menu de Opciones ----------------------\n\n");
    printf("1. Cargar los datos de los pacientes (modo texto).\n");
    printf("2. Imprimir lista de pacientes.\n");
    printf("3. Asignar estadisticas y crear nueva lista\n");
    printf("4. Filtrar paises exitosos.\n");
    printf("5. Filtrar paises en el horno.\n");
    printf("6. Ordenar por nivel de infeccion.\n");
    printf("7. Mostrar pais mas castigado.\n");
    printf("8. Guardar lista mapeada.\n");
    printf("9. Salir\n");
    utn_getNumeroEntero(&option, "Ingresa la opcion: ", "Error, opcion del 1 al 9 solamente: ", 1, 9, 3);

    return option;
}



