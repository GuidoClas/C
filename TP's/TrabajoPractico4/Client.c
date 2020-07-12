#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Client.h"
#include "utn.h"


Client* client_new()
{
    Client* client = (Client*) malloc(sizeof(Client)); // Solicitamos espacio en memoria dinamica para un cliente

    if(client != NULL) // Verificamos que ese cliente generado no sea NULL y ponemos los campos vacios para evitar basura
    {
        client->id = 0;
        strcpy(client->nombre, " ");
        client->anioInscripcion = 0;
        strcpy(client->genero, " ");
    }

    return client;
}



Client* client_newParametros(char* idStr,char* nombreStr,char* anioStr, char* generoStr)
{
    Client* client = client_new(); // Solicitamos espacio en memoria dinamica para un cliente

    if(client != NULL && idStr != NULL && nombreStr != NULL && anioStr != NULL && generoStr != NULL) // Verificamos que ese cliente generado no sea NULL y le asignamos los atributos recibidos como parametros
    {
        client_setId(client, atoi(idStr));
        client_setNombre(client, nombreStr);
        client_setAnio(client, atoi(anioStr));
        client_setGenero(client, generoStr);
    }

    return client;
}

void listClients(LinkedList* pArrayListClient)
{
    int llSize;
    Client* client;

    if(pArrayListClient != NULL) // Verifico que el puntero LL recibido no sea NULL
    {
        printf("\n%10s%10s%10s%10s\n", "Id", "Nombre", "Anio", "Genero"); // Imprimo de manera ordenada las columnas
        llSize = ll_len(pArrayListClient);
        for(int i=0; i<llSize; i++)
        {
            //Obtengo en cada iteracion un cliente, y se lo envio a la funcion listEmployee destinada a mostrarlo
            client = (Client*) ll_get(pArrayListClient, i);
            listClient(client);
        }
    }
}

void listClient(Client* client)
{
   if(client != NULL) // Verifico que el cliente recibido no sea NULL
   {
       printf("%10d%10s%10d%10s\n", client->id, client->nombre, client->anioInscripcion, client->genero);
   }

}

int findClient(int id, LinkedList* pArrayListClient)
{
    int index = -1; // Setteo en -1 el retorno en caso de no encontrar un id igual
    Client* auxClient;
    int llSize;

    if(pArrayListClient != NULL && id > 0) // Verifico que el puntero LL recibido no sea NULL y que el id sea mayor a 0
    {
        llSize = ll_len(pArrayListClient);
        for(int i=0; i<llSize; i++)
        {
            // Recorro la lista y obtengo un cliente en cada iteracion, para comparar igualdad con el id recibido como parametro
            auxClient = (Client*) ll_get(pArrayListClient, i);
            if(auxClient->id == id)
            {
                index = i; // De ser iguales, devuelve el indice en que se encuentra
            }
        }
    }

    return index;
}

int editMenu()
{
    int option;

    printf("\n---------------------- Menu de modificaciones ----------------------\n\n");
    printf("1. Modificar nombre\n");
    printf("2. Modificar Anio de ingreso\n");
    printf("3. Modificar Genero\n");
    printf("4. Salir del menu de modificaciones\n");
    utn_getNumeroEntero(&option, "Ingresa la opcion: ", "Error, opcion del 1 al 10 solamente: ", 1, 4, 3);

    return option;
}


int switchEditMenu(Client* client)
{
    int option;
    char auxName[51];
    int auxYear;
    char auxGender[21];
    int retorno = -1;

    if(client != NULL) // Verifico que el puntero a cliente recibido no sea NULL
    {
        do{
            option = editMenu();
            switch(option)
            {
                case 1:
                    if(!utn_getString(auxName, "Ingresa el nuevo nombre: ", "Error, solo letras: ", 3))
                    {
                        formalizarString(auxName);
                        client_setNombre(client, auxName);
                        retorno = 0;
                    }
                    break;
                case 2:
                    if(!utn_getNumeroEntero(&auxYear, "Ingresa el nuevo anio: ", "Error, solo numeros enteros: ", 0, 2050, 3))
                    {
                       client_setAnio(client, auxYear);
                       retorno = 0;
                    }
                    break;
                case 3:
                    if(!utn_getString(auxGender, "Ingresa el nuevo genero: ", "Error, solo letras: ", 3))
                    {
                        formalizarString(auxGender);
                        client_setGenero(client, auxGender);
                        retorno = 0;
                    }
                    break;
                case 4:
                    printf("Salida exitosa\n");
                    retorno = 0;
                    break;
            }
        }while(option != 4);
    }

    return retorno;
}

int client_setId(Client* this,int id)
{
    int retorno = -1;

    if(this != NULL && id > 0) // Verifico que el cliente recibido no sea NULL y que el id sea valido
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;
}

int client_getId(Client* this,int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL) // Verifico que el cliente recibido no sea NULL y que el id sea valido
    {
       *id = this->id;
       retorno = 0;
    }

    return retorno;
}

int client_setNombre(Client* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL) // Verifico que el cliente recibido no sea NULL y que el nombre sea valido
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }

    return retorno;
}

int client_getNombre(Client* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL) // Verifico que el cliente recibido no sea NULL y que el nombre sea valido
    {
       strcpy(nombre, this->nombre);
       retorno = 0;
    }

    return retorno;
}

int client_setAnio(Client* this,int anio)
{
    int retorno = -1;

    if(this != NULL && anio >= 0) // Verifico que el cliente recibido no sea NULL y que el año sea valido
    {
        this->anioInscripcion = anio;
        retorno = 0;
    }

    return retorno;
}

int client_getAnio(Client* this,int* anio)
{
    int retorno = -1;

    if(this != NULL && anio != NULL)  // Verifico que el cliente recibido no sea NULL y que el año sea valido
    {
       *anio = this->anioInscripcion;
       retorno = 0;
    }

    return retorno;

}

int client_setGenero(Client* this,char* genero)
{
    int retorno = -1;

    if(this != NULL && genero != NULL)  // Verifico que el cliente recibido no sea NULL y que el genero sea valido
    {
        strcpy(this->genero,genero);
        retorno = 0;
    }

    return retorno;
}

int client_getGenero(Client* this,char* genero)
{
    int retorno = -1;

    if(this != NULL && genero != NULL) // Verifico que el cliente recibido no sea NULL y que el genero sea valido
    {
       strcpy(genero, this->genero);
       retorno = 0;
    }

    return retorno;
}


int sortIds(void* client1, void* client2)
{
    int idClient1;
    int idClient2;
    int retorno;

    if(!client_getId(client1, &idClient1) && !client_getId(client2, &idClient2)) //Obtengo el dato a comparar de cada cliente y le doy un criterio
    {
        if(idClient1 > idClient2)
        {
            retorno = 1;
        }
        else if(idClient1 < idClient2)
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

int sortNames(void* client1,void* client2)
{
    char nameClient1[51];
    char nameClient2[51];
    int retorno;

    if(!client_getNombre(client1, nameClient1) && !client_getNombre(client2, nameClient2)) //Obtengo el dato a comparar de cada cliente y le doy un criterio
    {
        if(strcmp(nameClient1, nameClient2) == 1)
        {
            retorno = 1;
        }
        else if(strcmp(nameClient1, nameClient2) == -1)
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

int sortYears(void* client1, void* client2)
{
    int yearClient1;
    int yearClient2;
    int retorno;

    if(!client_getAnio(client1, &yearClient1) && !client_getAnio(client2, &yearClient2)) //Obtengo el dato a comparar de cada cliente y le doy un criterio
    {
        if(yearClient1 > yearClient2)
        {
            retorno = 1;
        }
        else if(yearClient1 < yearClient2)
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

int sortGender(void* client1, void* client2)
{
    char genderClient1 [21];
    char genderClient2 [21];
    int retorno;

    if(!client_getGenero(client1, genderClient1) && !client_getGenero(client2, genderClient2)) //Obtengo el dato a comparar de cada cliente y le doy un criterio
    {
        if(strcmp(genderClient1, genderClient2) == 1)
        {
            retorno = 1;
        }
        else if(strcmp(genderClient1, genderClient2) == -1)
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

int sortMenu()
{
    int option;

    printf("\n---------------------- Menu de Opciones de Ordenamiento ----------------------\n\n");
    printf("1. Ordenar por ID\n");
    printf("2. Ordenar por nombre\n");
    printf("3. Ordenar por anio de inscripcion\n");
    printf("4. Ordenar por genero\n");
    printf("5. Salir del menu\n");
    utn_getNumeroEntero(&option, "Ingresa la opcion: ", "Error, solo numeros enteros", 1, 5, 3);

    return option;
}

int switchSortMenu(LinkedList* pArrayListClient, int order)
{
    int option;
    int retorno = -1;

    if(pArrayListClient != NULL) // Verifico que el puntero a cliente recibido no sea NULL
    {
        do{
            option = sortMenu();
            switch(option)
            {
                case 1:
                    if(!ll_sort(pArrayListClient, sortIds, order))
                    {
                        printf("Clientes ordenados por ID con exito");
                        retorno = 0;
                    }
                    break;
                case 2:
                    if(!ll_sort(pArrayListClient, sortNames, order))
                    {
                        printf("Clientes ordenados por nombre con exito");
                        retorno = 0;
                    }
                    break;
                case 3:
                    if(!ll_sort(pArrayListClient, sortYears, order))
                    {
                        printf("Clientes ordenados por anio con exito");
                        retorno = 0;
                    }
                    break;
                case 4:
                    if(!ll_sort(pArrayListClient, sortGender, order))
                    {
                        printf("Clientes ordenados por genero con exito");
                        retorno = 0;
                    }
                    break;
                case 5:
                    printf("Salida exitosa\n");
                    retorno = 0;
                    break;
            }
        }while(option != 5);
    }

    return retorno;
}
