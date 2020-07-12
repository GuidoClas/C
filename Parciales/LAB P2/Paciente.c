#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Paciente.h"
#include "utn.h"

/** \brief Solicita espacio en memoria dinamica para un nuevo elemento y settea cada campo vacio o en 0
 *
 * \return Retorna el paciente setteado en blanco
 *
 */

Paciente* paciente_new()
{
    Paciente* paciente = (Paciente*) malloc(sizeof(Paciente)); // Solicitamos espacio en memoria dinamica para un paciente

    if(paciente != NULL) // Verificamos que ese paciente generado no sea NULL y ponemos los campos vacios para evitar basura
    {
        paciente_setId(paciente, 0);
        paciente_setPais(paciente, " ");
        paciente_setInfectados(paciente, 0);
        paciente_setRecuperados(paciente, 0);
        paciente_setMuertos(paciente, 0);

    }

    return paciente;
}

/** \brief La funcion recibe los datos y los settea en su campo, validando cada uno
 *
 * \param Recibe el id en forma string
 * \param Recibe el pais en forma string
 * \param Recibe los recuperados en forma string
 * \param Recibe los infectados en forma string
 * \param Recibe los muertos en forma string
 * \return En exito retorna el paciente ya seteado con los datos, sino lo libera
 *
 */

Paciente* paciente_newParametros(char* idStr,char* paisStr,char* recuperadoStr, char* infectadosStr, char* muertosStr)
{
    Paciente* paciente = paciente_new(); // Solicitamos espacio en memoria dinamica para un paciente

    if(paciente != NULL && idStr != NULL && paisStr != NULL && recuperadoStr != NULL && infectadosStr != NULL && muertosStr != NULL) // Verificamos que ese paciente generado no sea NULL y le asignamos los atributos recibidos como parametros
    {
        paciente_setId(paciente, atoi(idStr));
        paciente_setPais(paciente, paisStr);
        paciente_setInfectados(paciente, atoi(recuperadoStr));
        paciente_setRecuperados(paciente, atoi(infectadosStr));
        paciente_setMuertos(paciente, atoi(muertosStr));
    }
    else
    {
        free(paciente);
        paciente = NULL;
    }

    return paciente;
}

/** \brief Obtiene los elementos, y muestra cada uno a traves de una funcion
 *
 * \param Recibe la LL
 */

void listPacients(LinkedList* pArrayList)
{
    int llSize;
    Paciente* paciente = NULL;

    if(pArrayList != NULL) // Verifico que el puntero LL recibido no sea NULL
    {
        printf("\n%15s%15s%15s%15s%15s\n", "Id", "Pais", "Infectados", "Recuperados" , "Muertos"); // Imprimo de manera ordenada las columnas
        llSize = ll_len(pArrayList);
        for(int i=0; i<llSize; i++)
        {
            //Obtengo en cada iteracion un cliente, y se lo envio a la funcion listEmployee destinada a mostrarlo
            paciente = (Paciente*) ll_get(pArrayList, i);
            listPacient(paciente);
        }
    }
}

/** \brief Lista los pacientes de manera ordenada y prolija
 *
 * \param Recibe la LL
 *
 */

void listPacient(Paciente* paciente)
{
    int id;
    char pais[21];
    int infectados;
    int recuperados;
    int muertos;

    if(paciente != NULL) // Verifico que el paciente recibido no sea NULL
    {
        paciente_getId(paciente, &id);
        paciente_getPais(paciente, pais);
        paciente_getInfectados(paciente, &infectados);
        paciente_getRecuperados(paciente, &recuperados);
        paciente_getMuertos(paciente, &muertos);
        printf("%15d%15s%15d%15d%15d\n", id, pais, infectados, recuperados, muertos);
    }

}

/** \brief Settea el campo requerido y con el dato recibido
 *
 * \param Recibe la LL
 * \param Recibe el dato a settear
 * \return Retorna 0 en caso de exito y -1 en caso de error
 *
 */
int paciente_setId(Paciente* this, int id)
{
    int retorno = -1;

    if(this != NULL && id > 0) // Verifico que el paciente recibido no sea NULL y que el id sea valido
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene el campo requerido y lo guarda en el puntero recibido
 *
 * \param Recibe la LL
 * \param Recibe el puntero donde se guardara el dato
 * \return Retorna 0 en caso de exito y -1 en caso de error
 *
 */
int paciente_getId(Paciente* this, int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL) // Verifico que el paciente recibido no sea NULL y que el id sea valido
    {
       *id = this->id;
       retorno = 0;
    }

    return retorno;
}

/** \brief Settea el campo requerido y con el dato recibido
 *
 * \param Recibe la LL
 * \param Recibe el dato a settear
 * \return Retorna 0 en caso de exito y -1 en caso de error
 *
 */
int paciente_setPais(Paciente* this, char* pais)
{
    int retorno = -1;

    if(this != NULL && pais != NULL) // Verifico que el paciente recibido no sea NULL y que el pais sea valido
    {
        strcpy(this->pais, pais);
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene el campo requerido y lo guarda en el puntero recibido
 *
 * \param Recibe la LL
 * \param Recibe el puntero donde se guardara el dato
 * \return Retorna 0 en caso de exito y -1 en caso de error
 *
 */
int paciente_getPais(Paciente* this, char* pais)
{
    int retorno = -1;

    if(this != NULL && pais != NULL) // Verifico que el paciente recibido no sea NULL y que el pais sea valido
    {
       strcpy(pais, this->pais);
       retorno = 0;
    }

    return retorno;
}

/** \brief Settea el campo requerido y con el dato recibido
 *
 * \param Recibe la LL
 * \param Recibe el dato a settear
 * \return Retorna 0 en caso de exito y -1 en caso de error
 *
 */
int paciente_setInfectados(Paciente* this, int infectados)
{
    int retorno = -1;

    if(this != NULL && infectados >= 0) // Verifico que el paciente recibido no sea NULL y que el num sea valido
    {
        this->infectados = infectados;
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene el campo requerido y lo guarda en el puntero recibido
 *
 * \param Recibe la LL
 * \param Recibe el puntero donde se guardara el dato
 * \return Retorna 0 en caso de exito y -1 en caso de error
 *
 */
int paciente_getInfectados(Paciente* this,int* infectados)
{
    int retorno = -1;

    if(this != NULL && infectados != NULL)  // Verifico que el paciente recibido no sea NULL y que el num sea valido
    {
       *infectados = this->infectados;
       retorno = 0;
    }

    return retorno;

}

/** \brief Settea el campo requerido y con el dato recibido
 *
 * \param Recibe la LL
 * \param Recibe el dato a settear
 * \return Retorna 0 en caso de exito y -1 en caso de error
 *
 */
int paciente_setRecuperados(Paciente* this, int recuperados)
{
    int retorno = -1;

    if(this != NULL && recuperados >= 0) // Verifico que el paciente recibido no sea NULL y que el num sea valido
    {
        this->recuperados = recuperados;
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene el campo requerido y lo guarda en el puntero recibido
 *
 * \param Recibe la LL
 * \param Recibe el puntero donde se guardara el dato
 * \return Retorna 0 en caso de exito y -1 en caso de error
 *
 */
int paciente_getRecuperados(Paciente* this,int* recuperados)
{
    int retorno = -1;

    if(this != NULL && recuperados != NULL)  // Verifico que el paciente recibido no sea NULL y que el num sea valido
    {
       *recuperados = this->recuperados;
       retorno = 0;
    }

    return retorno;

}

/** \brief Settea el campo requerido y con el dato recibido
 *
 * \param Recibe la LL
 * \param Recibe el dato a settear
 * \return Retorna 0 en caso de exito y -1 en caso de error
 *
 */
int paciente_setMuertos(Paciente* this, int muertos)
{
    int retorno = -1;

    if(this != NULL && muertos >= 0) // Verifico que el paciente recibido no sea NULL y que el num sea valido
    {
        this->muertos = muertos;
        retorno = 0;
    }

    return retorno;
}

/** \brief Obtiene el campo requerido y lo guarda en el puntero recibido
 *
 * \param Recibe la LL
 * \param Recibe el puntero donde se guardara el dato
 * \return Retorna 0 en caso de exito y -1 en caso de error
 *
 */

int paciente_getMuertos(Paciente* this,int* muertos)
{
    int retorno = -1;

    if(this != NULL && muertos != NULL)  // Verifico que el paciente recibido no sea NULL y que el num sea valido
    {
       *muertos = this->muertos;
       retorno = 0;
    }

    return retorno;

}

/** \brief Se encarga de darle valores aleatorios a los campos infectados, recuperados, muertos.
 *
 * \param Recibe el elemento a settear con los valores aleatorios
 * \return Retorna el elemento ya setteado para agregarlo a la LL
 *
 */

void* mapearRandom(void* pac)
{
    Paciente* paciente = NULL;
    int infectados = getRandomInfectados();
    int recuperados = getRandomRecuperados();
    int muertos = getRandomMuertos();

    if(pac != NULL)
    {
        paciente = (Paciente*) pac;
        paciente_setInfectados(paciente, infectados);
        paciente_setRecuperados(paciente, recuperados);
        paciente_setMuertos(paciente, muertos);

    }
    paciente = (void*) paciente;
    return paciente;
}


/** \brief Ordena por cantidad de infectados los paises
 *
 * \param Recibe 1 puntero a void que es el elemento a ordenar
 * \param Recibe 1 puntero a void que es el elemento a ordenar
 * \return Retorna 1 en caso de que el primero sea mas grande, -1 si es al contrario, y 0 si son iguales.
 *
 */

int sortInfected(void* inf1,void* inf2)
{
    int infectado1;
    int infectado2;
    int retorno;

    if(!paciente_getInfectados(inf1, &infectado1) && !paciente_getInfectados(inf2, &infectado2)) //Obtengo el dato a comparar de cada empleado y le doy un criterio
    {
        if(infectado1 > infectado2)
        {
            retorno = 1;
        }
        else if(infectado1 < infectado2)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}


