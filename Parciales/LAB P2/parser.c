#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Paciente.h"

/** \brief Parsea los datos los datos de los paises desde el archivo path (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_PacientFromText(FILE* pFile , LinkedList* pArrayList)
{

    int retorno = -1;
    char buffer[5][101];
    char header[5][50];
    int quantity;
    Paciente* paciente;

    if(pFile != NULL && pArrayList != NULL) // Verifico antes que el archivo recibido no sea NULL y que la LL no sea NULL
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", header[0],header[1], header[2], header[3], header[4]);
        while(!feof(pFile)) // Logramos que itere hasta que llegue al final del archivo
        {
            quantity = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            // Validamos que haya podido leer los 4 atributos de los clientes
            if(quantity == 5)
            {
                paciente = paciente_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
                // Si logro obtener todos los datos, se los asignaremos mediante la funcion en forma de string
                if(paciente != NULL) // Verifico que la funcion no haya devuelto un empleado NULL y finalmente lo agrego a la lista
                {
                    ll_add(pArrayList, paciente);
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
