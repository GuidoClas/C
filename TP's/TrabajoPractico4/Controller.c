#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Client.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los clientes desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListClient)
{
    int retorno = -1;
    FILE* file;
    char answer;

    if(path != NULL && pArrayListClient!= NULL) // Verifico que los punteros recibidos no sean NULL
    {
        if((!ll_isEmpty(pArrayListClient) && !utn_getCharacter(&answer, "Desea sobrescribir los datos?", "Error, s/n", 's', 'n', 3) && answer == 's') || ll_isEmpty(pArrayListClient))
        {
            //Si la lista no esta vacia, preguntaremos si se quieren sobreescribir los datos, y si la respuesta si, se sobreescribiran.
            //Si la lista esta vacia, simplemente se cargaran los clientes desde el archivo
            ll_clear(pArrayListClient);
            file = fopen(path, "r");

            if(file != NULL) // Verifico que el archivo abierto no sea NULL
            {
                if(parser_ClientFromText(file, pArrayListClient) == 0)
                {
                    retorno = 0;
                }
                fclose(file);
            }
        }
    }


    return retorno;
}

/** \brief Carga los datos de los clientes desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListClient)
{
    int retorno = -1;
    FILE* file;
    char answer;

    if(path != NULL && pArrayListClient != NULL) // Verifico que los punteros recibidos no sean NULL
    {
        //Si la lista no esta vacia, preguntaremos si se quieren sobreescribir los datos, y si la respuesta si, se sobreescribiran.
        //Si la lista esta vacia, simplemente se cargaran los clientes desde el archivo
        if((!ll_isEmpty(pArrayListClient) && !utn_getCharacter(&answer, "Desea sobrescribir los datos?", "Error, s/n", 's', 'n', 3) && answer == 's') || ll_isEmpty(pArrayListClient))
        {
            file = fopen(path, "rb");
            if(file != NULL) // Verifico que el archivo abierto no sea NULL
            {
                if(parser_ClientFromBinary(file, pArrayListClient) == 0)
                {
                    retorno = 0;
                }
                fclose(file);
            }
        }
    }


    return retorno;
}

/** \brief Alta de clientes
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_addClient(LinkedList* pArrayListClient)
{
    int retorno = -1;
    Client* client = client_new(); //Solicito espacio en memoria dinamica para un nuevo cliente
    char auxName[51];
    int auxYear;
    char auxGender[51];
    int nextId;

    if(pArrayListClient != NULL && client != NULL) // Verifico que los punteros recibidos y el cliente generado no sean NULL
    {
        getId(&nextId);

        printf("\nAlta de cliente\n");
        // Solicito los datos y los valido, los asigno
        if(!utn_getString(auxName, "Ingresa el nombre: ", "Error, solo letras: ", 3) &&
            !utn_getNumeroEntero(&auxYear, "Ingresa el anio de inscripcion: ", "Error, solo numeros enteros: ", 0, 2020, 3) &&
           !utn_getString(auxGender, "Ingresa el genero(Male/Female): ", "Error, solo (Male/Female): ", 3))
        {
            //Le asigno los atributos al cliente
            formalizarString(auxName);
            formalizarString(auxGender);
            client_setId(client, nextId);
            client_setNombre(client, auxName);
            client_setAnio(client, auxYear);
            client_setGenero(client, auxGender);
            if(!ll_add(pArrayListClient, (void*) client))
            {
                updateId(nextId);
                retorno = 0;
            }


        }
    }

    return retorno;
}

/** \brief Modificar datos de cliente
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_editClient(LinkedList* pArrayListClient)
{
    int retorno = -1;
    int index;
    int id;
    Client* client;

    if(pArrayListClient != NULL) // Verifico que el puntero recibido LL no sea NULL
    {
        if(!utn_getNumeroEntero(&id, "Ingresa el id del cliente: ", "Error, solo numeros enteros: ", 1, 1000000, 3))
        {
            index = findClient(id, pArrayListClient); // Solicito el id a modificar y lo guardo en la variable index
        }

        if(index == -1) // Si findEmployee me devolvio un -1 es que el cliente no existe
        {
            printf("No existe cliente con ese id\n");
        }
        else
        {
             // Obtengo el cliente con ll_get y se lo paso como parametro al switch que permite modificar los datos
            client = (Client*) ll_get(pArrayListClient, index);
            if(!switchEditMenu(client))
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

/** \brief Baja de cliente
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_removeClient(LinkedList* pArrayListClient)
{
    int retorno = -1;
    int index;
    int id;
    char answer;

    if(pArrayListClient != NULL) // Verifico que el puntero recibido LL no sea NULL
    {

        if(!utn_getNumeroEntero(&id, "Ingresa el id del cliente: ", "Error, solo numeros enteros: ", 1, 1000000, 3))
        {
            index = findClient(id, pArrayListClient); // Solicito el id a eliminar y lo guardo en la variable index
        }

        if(index == -1) // Si findClient me devolvio un -1 es que el cliente no existe
        {
            printf("No existe cliente con ese id\n");
        }
        else
        {
            if(!utn_getCharacter(&answer, "Confirma la baja de este cliente?(s/n)", "Error, solo (s/n)", 's', 'n', 3) && answer == 's') //Confirmo la baja y lo remuevo del LL
            {
                ll_remove(pArrayListClient, index);
                retorno = 0;
            }
        }
    }

    return retorno;
}

/** \brief Listar clientes
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_ListClients(LinkedList* pArrayListClient)
{
    int retorno = -1;


    if(pArrayListClient != NULL) // Verifico que el puntero recibo LL no sea NULL
    {
        listClients(pArrayListClient);
    }

    return retorno;
}

/** \brief Ordenar clientes
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_sortClients(LinkedList* pArrayListClient)
{
    int retorno;
    int order;

    if(pArrayListClient != NULL) // Verifico que el puntero recibido LL no sea NULL
    {
        if(!utn_getNumeroEntero(&order, "Ingrese el orden\n1-Ascendente\n0-Descendente\n", "Error, solo 1 o 0", 0, 1, 3))
        {
            // Pido el criterio de ordenamiento y se lo paso como parametro al switch que permite elegir la forma de ordenar.
            if(!switchSortMenu(pArrayListClient, order))
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

int controller_reinsert(LinkedList* pArrayListClient)
{
    int retorno = -1;
    int index;
    int reIndex;
    int id;
    int id2;
    char answer;
    Client* auxClient;

    if(pArrayListClient != NULL)
    {
        getId(&index);
        if(!utn_getNumeroEntero(&id, "\nIngrese el cliente a reubicar: ", "\nError, solo numeros enteros: ", 0, index, 3))
        {
            index = findClient(id, pArrayListClient);
        }
        if(index == -1) // Si findClient me devolvio un -1 es que el cliente no existe
        {
            printf("No existe cliente con ese id\n");
        }
        else
        {
            if(!utn_getCharacter(&answer, "Confirma reinsertar este cliente?(s/n)", "Error, solo (s/n)", 's', 'n', 3) && answer == 's')
            {
                auxClient = (Client*) ll_pop(pArrayListClient, index);
                getId(&index);
                if(!utn_getNumeroEntero(&id2, "En que indice quiere reinsertarlo?", "\nError, solo indices validos: ", 0, index, 3))
                {
                    reIndex = findClient(id2, pArrayListClient);
                }
                if(reIndex == -1)
                {
                    printf("\nNo es un indice valido a reinsertar, revirtiendo operacion\n");
                    ll_push(pArrayListClient, index, auxClient);
                }
                else
                {
                    ll_push(pArrayListClient, reIndex, auxClient);
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

int controller_newFilteredList(LinkedList* pArrayListClient, LinkedList* pArrayListClient2)
{
    int retorno = -1;
    Client* auxClient;
    int from;
    int to;

    if(pArrayListClient != NULL && pArrayListClient2 != NULL)
    {
        if((!utn_getNumeroEntero(&from, "Ingrese desde que anio quiere filtrar la nueva lista: ", "Error, solo anios validos: ", 0, 2050, 3)) && (!utn_getNumeroEntero(&to, "Ingrese hasta que anio quiere filtrar la nueva lista: ","Error, solo anios validos: ", 0, 2050, 3)))
        {
            for(int i=0; i<ll_len(pArrayListClient); i++)
            {
                auxClient = (Client*) ll_get(pArrayListClient, i);
                if(auxClient != NULL)
                {
                    if(auxClient->anioInscripcion >= from && auxClient->anioInscripcion <= to)
                    {
                        ll_add(pArrayListClient2, auxClient);
                    }
                }
            }
        }
        retorno = 0;
    }

    return retorno;
}


/** \brief Guarda los datos de los clientes en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListClient)
{
    int retorno = -1;
    FILE* file;
    int llSize;
    Client* client;
    int auxId;
    char auxName[51];
    int auxYear;
    char auxGender[21];

    if(path != NULL && pArrayListClient != NULL) //Verifico que los punteros recibidos no sean NULL
    {
        file = fopen(path, "w");
        llSize = ll_len(pArrayListClient);
        if(file != NULL) //Verifico que el archivo abierto no haya devuelto NULL
        {
            for(int i=0; i<llSize; i++)
            {
            //Cada vez que recorra un cliente de la lista, lo obtendra la funcion ll_get, se verificara que no sea NULL
            // Se hara un get de cada dato en auxiliares y se escribira en el archivo.
                client = (Client*) ll_get(pArrayListClient, i);
                if(client != NULL)
                {
                    client_getId(client, &auxId);
                    client_getNombre(client, auxName);
                    client_getAnio(client, &auxYear);
                    client_getGenero(client, auxGender);

                    fprintf(file,"%d,%s,%d,%s\n", auxId, auxName, auxYear, auxGender);
                }
            }
            retorno = 0;
            fclose(file);
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los clientes en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListClient)
{
    int retorno = -1;
    FILE* file;
    int llSize;
    Client* client;

    if(path != NULL && pArrayListClient != NULL) //Verifico que los punteros recibidos no sean NULL
    {
        file = fopen(path, "wb");
        llSize = ll_len(pArrayListClient);
        if(file != NULL) //Verifico que el archivo abierto no haya devuelto NULL
        {
            for(int i=0; i<llSize; i++)
            {
            //Cada vez que recorra un cliente de la lista, lo obtendra la funcion ll_get, se verificara que no sea NULL y se escribira en el archivo
               client = (Client*) ll_get(pArrayListClient, i);
               if(client != NULL)
               {
                   fwrite(client, sizeof(Client), 1, file);
               }
            }
            retorno = 0;
            fclose(file);
        }

    }

    return retorno;
}

int mainMenu()
{
    int option;

    printf("\n---------------------- Menu de Opciones ----------------------\n\n");
    printf("1. Cargar los datos de los clientes desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los clientes desde el archivo data.csv (modo binario)\n");
    printf("3. Alta de cliente\n");
    printf("4. Modificar datos de cliente\n");
    printf("5. Baja de cliente\n");
    printf("6. Listar clientes\n");
    printf("7. Ordenar clientes\n");
    printf("8. Reinsertar un cliente en otra posicion\n");
    printf("9. Guardar los datos de los clientes en el archivo data.csv (modo texto)\n");
    printf("10. Guardar los datos de los clientes en el archivo data.csv (modo binario)\n");
    printf("11. Crear nueva lista filtrada por anio de inscripcion\n");
    printf("12. Cargar los datos de la lista filtrada desde el archivo dataFiltrada.csv (modo texto)\n");
    printf("13. Listar clientes de la lista filtrada\n");
    printf("14. Guardar los datos de los clientes de la lista filtrada en el archivo dataFiltrada.csv (modo texto)\n");
    printf("15. Salir\n");
    utn_getNumeroEntero(&option, "Ingresa la opcion: ", "Error, opcion del 1 al 10 solamente: ", 1, 15, 3);

    return option;
}



int getId(int* id)
{
	int returnAux = -1;
	*id = 1001;

	FILE* file;
	file = fopen("proximoId.bin", "rb");
	if(file != NULL)
	{
		fread(id, sizeof(int), 1, file);
		fclose(file);
		returnAux = 0;
	}

	return returnAux;
}

int updateId(int id)
{
	int returnAux = -1;
	id++;

	FILE* file = fopen("proximoId.bin", "wb");
	if(file != NULL)
	{
		fwrite(&id, sizeof(int), 1, file);
		fclose(file);
		returnAux = 0;
	}

	return returnAux;
}
