#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "dog.h"
#include "utn.h"


Dog* dog_new()
{
    Dog* dog = (Dog*) malloc(sizeof(Dog)); // Solicitamos espacio en memoria dinamica para un cliente

    if(dog != NULL) // Verificamos que ese cliente generado no sea NULL y ponemos los campos vacios para evitar basura
    {
        dog_setId(dog, 0);
        dog_setNombre(dog, " ");
        dog_setDias(dog, 0);
        dog_setRaza(dog, " ");
        dog_setReserva(dog, " ");
        dog_setGenero(dog, " ");
    }

    return dog;
}

Dog* dog_newParametros(char* idStr,char* nombreStr,char* diasStr, char* razaStr, char* reservadoStr, char* generoStr)
{
    Dog* dog = dog_new(); // Solicitamos espacio en memoria dinamica para un cliente

    if(dog != NULL && idStr != NULL && nombreStr != NULL && diasStr != NULL && razaStr != NULL && reservadoStr != NULL && generoStr != NULL) // Verificamos que ese cliente generado no sea NULL y le asignamos los atributos recibidos como parametros
    {
        dog_setId(dog, atoi(idStr));
        dog_setNombre(dog, nombreStr);
        dog_setDias(dog, atoi(diasStr));
        dog_setRaza(dog, razaStr);
        dog_setReserva(dog, reservadoStr);
        dog_setGenero(dog, generoStr);
    }
    else
    {
        free(dog);
        dog = NULL;
    }

    return dog;
}

void listDogs(LinkedList* pArrayList)
{
    int llSize;
    Dog* dog = NULL;

    if(pArrayList != NULL) // Verifico que el puntero LL recibido no sea NULL
    {
        printf("\n%10s%10s%10s%10s%10s%10s\n", "Id", "Nombre", "Dias", "Raza" , "Reservado", "Genero"); // Imprimo de manera ordenada las columnas
        llSize = ll_len(pArrayList);
        for(int i=0; i<llSize; i++)
        {
            //Obtengo en cada iteracion un cliente, y se lo envio a la funcion listEmployee destinada a mostrarlo
            dog = (Dog*) ll_get(pArrayList, i);
            listDog(dog);
        }
    }
}

void listDog(Dog* dog)
{
    int id;
    char nombre[21];
    int dias;
    char raza[21];
    char reserva[4];
    char genero[3];

    if(dog != NULL) // Verifico que el cliente recibido no sea NULL
    {
        dog_getId(dog, &id);
        dog_getNombre(dog, nombre);
        dog_getDias(dog, &dias);
        dog_getRaza(dog, raza);
        dog_getReserva(dog, reserva);
        dog_getGenero(dog, genero);
        printf("%10d%10s%10d%10s%10s%10s\n", id, nombre, dias, raza, reserva, genero);
    }

}

int dog_setId(Dog* this, int id)
{
    int retorno = -1;

    if(this != NULL && id > 0) // Verifico que el cliente recibido no sea NULL y que el id sea valido
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;
}

int dog_getId(Dog* this, int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL) // Verifico que el cliente recibido no sea NULL y que el id sea valido
    {
       *id = this->id;
       retorno = 0;
    }

    return retorno;
}

int dog_setNombre(Dog* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL) // Verifico que el cliente recibido no sea NULL y que el nombre sea valido
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }

    return retorno;
}

int dog_getNombre(Dog* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL) // Verifico que el cliente recibido no sea NULL y que el nombre sea valido
    {
       strcpy(nombre, this->nombre);
       retorno = 0;
    }

    return retorno;
}

int dog_setDias(Dog* this, int dias)
{
    int retorno = -1;

    if(this != NULL && dias >= 0) // Verifico que el cliente recibido no sea NULL y que el año sea valido
    {
        this->dias = dias;
        retorno = 0;
    }

    return retorno;
}

int dog_getDias(Dog* this,int* dias)
{
    int retorno = -1;

    if(this != NULL && dias != NULL)  // Verifico que el cliente recibido no sea NULL y que el año sea valido
    {
       *dias = this->dias;
       retorno = 0;
    }

    return retorno;

}


int dog_setRaza(Dog* this,char* raza)
{
    int retorno = -1;

    if(this != NULL && raza != NULL)  // Verifico que el cliente recibido no sea NULL y que el raza sea valido
    {
        strcpy(this->raza, raza);
        retorno = 0;
    }

    return retorno;
}

int dog_getRaza(Dog* this,char* raza)
{
    int retorno = -1;

    if(this != NULL && raza != NULL) // Verifico que el cliente recibido no sea NULL y que el raza sea valido
    {
       strcpy(raza, this->raza);
       retorno = 0;
    }

    return retorno;
}


int dog_setReserva(Dog* this,char* reservado)
{
    int retorno = -1;

    if(this != NULL && reservado != NULL)  // Verifico que el cliente recibido no sea NULL y que el reservado sea valido
    {
        strcpy(this->reservado, reservado);
        retorno = 0;
    }

    return retorno;
}

int dog_getReserva(Dog* this, char* reservado)
{
    int retorno = -1;

    if(this != NULL && reservado != NULL) // Verifico que el cliente recibido no sea NULL y que el reservado sea valido
    {
       strcpy(reservado, this->reservado);
       retorno = 0;
    }

    return retorno;
}

int dog_setGenero(Dog* this,char* genero)
{
    int retorno = -1;

    if(this != NULL && genero != NULL)  // Verifico que el cliente recibido no sea NULL y que el genero sea valido
    {
        strcpy(this->genero, genero);
        retorno = 0;
    }

    return retorno;
}

int dog_getGenero(Dog* this,char* genero)
{
    int retorno = -1;

    if(this != NULL && genero != NULL) // Verifico que el cliente recibido no sea NULL y que el genero sea valido
    {
       strcpy(genero, this->genero);
       retorno = 0;
    }

    return retorno;
}

