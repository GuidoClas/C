#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABMFUNC.h"
#include "dataWarehouse.h"


void inicializarClientes(eCliente* clientes, int tam)
{
    for(int i=0; i<tam; i++)
    {
        clientes[i].isEmpty = 1;
    }

}

void inicializarMascota(eMascota* mascotas , int tam)
{
    for(int i=0; i<tam; i++)
    {
        mascotas[i].isEmpty = 1;
    }

}

void listarCliente(eCliente x)
{

    printf("%15s      %15s      %15s      %10d         %d        %2c\n\n", x.nombre, x.apellido, x.localidad, x.telefono, x.edad, x.sexo);

}

void listarClientes(eCliente* vec, int tam)
{
    int flag=1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            listarCliente(vec[i]);
            flag=0;
        }

    }
    if(flag==1)
    {
        printf("No hay clientes para mostrar");
    }

}

void listarMascotas(eCliente* clientes, eMascota* vec, eTipo* tipo, int tamMas, int tamTip, int tam)
{
    int flag=1;

    for(int i=0; i<tamMas; i++)
    {
        if(vec[i].isEmpty==0)
        {
            listarMascota(clientes, vec[i], tipo, tamMas, tamTip, tam);
            flag=0;
        }

    }
    if(flag==1)
    {
        printf("No hay empleados para mostrar");
    }

}

void listarMascota(eCliente* clientes, eMascota vec, eTipo* tipo, int tamMas, int tamTip, int tam)
{
    char tipoMascota[20];
    char nombreDuenio[20];
    cargarDescripcionTipo(tipoMascota, vec.idTipo, tipo, tamTip);
    cargarNombreDuenio(nombreDuenio, vec.idDuenio, clientes, tam);

    printf("%15s  ", vec.nombre);
    printf("%15s  ", tipoMascota);
    printf("%15s  ", vec.raza);
    printf("%2d  ", vec.edad);
    printf("%.2f  ", vec.peso);
    printf("%2c  ", vec.sexo);
    printf("%15s  ", nombreDuenio);
}

int cargarDescripcionTipo(char* descripcion, int id, eTipo* tipo, int tamTip)
{
    int todoOk=0;

    for(int i=0; i<tamTip; i++)
    {
        if(tipo[i].idTipo==id)
        {
            strcpy(descripcion, tipo[i].descripcion);
            todoOk=1;
        }
    }

   return todoOk;
}

int cargarNombreDuenio(char* nombre, int id, eCliente* cliente, int tam)
{
    int todoOk=0;

    for(int i=0; i<tam; i++)
    {
        if(cliente[i].id==id)
        {
            strcpy(nombre, cliente[i].nombre);
            todoOk=1;
        }
    }

   return todoOk;
}

void hardcodearClientes(eCliente* vec, int cant)
{
   for(int i=0; i<cant; i++)
    {

        vec[i].id=ids[i];
        strcpy(vec[i].nombre, nombres[i]);
        strcpy(vec[i].apellido, apellidos[i]);
        strcpy(vec[i].localidad, localidades[i]);
        vec[i].telefono = telefonos[i];
        vec[i].edad=edades[i];
        vec[i].sexo=sexos[i];
        vec[i].isEmpty=0;
    }

}


