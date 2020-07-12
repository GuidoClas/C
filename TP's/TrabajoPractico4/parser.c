#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Client.h"

/** \brief Parsea los datos los datos de los clientes desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int parser_ClientFromText(FILE* pFile , LinkedList* pArrayListClient)
{

    int retorno = -1;
    char buffer[4][101];
    int quantity;
    Client* client;

    if(pFile != NULL && pArrayListClient != NULL) // Verifico antes que el archivo recibido no sea NULL y que la LL no sea NULL
    {
        while(!feof(pFile)) // Logramos que itere hasta que llegue al final del archivo
        {
            quantity = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            // Validamos que haya podido leer los 4 atributos de los clientes
            if(quantity == 4)
            {
                client = client_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                // Si logro obtener todos los datos, se los asignaremos mediante la funcion en forma de string
                if(client != NULL) // Verifico que la funcion no haya devuelto un empleado NULL y finalmente lo agrego a la lista
                {
                    ll_add(pArrayListClient, client);
                    retorno = 0;
                }
            }
            else
            {
                break;
            }
        }
    }


    return retorno;
}

/** \brief Parsea los datos los datos de los clientes desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */

int parser_ClientFromBinary(FILE* pFile , LinkedList* pArrayListClient)
{
    int retorno = -1;
    int quantity;
    Client* client;

    if(pFile != NULL && pArrayListClient != NULL) // Verifico antes que el archivo recibido no sea NULL y que la LL no sea NULL
    {
        while(!feof(pFile)) // Logramos que itere hasta que llegue al final del archivo
        {
            client = client_new();

            if(client != NULL) // Verifico que la funcion no haya devuelto un empleado NULL
            {
                quantity = fread(client, sizeof(Client), 1, pFile);
                 // Validamos que haya podido leer un empleado de manera completa
                if(quantity == 1)
                {
                    // finalmente lo agrego a la lista
                    ll_add(pArrayListClient, client);
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}
