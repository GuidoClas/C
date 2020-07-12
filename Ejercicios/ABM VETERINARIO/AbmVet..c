#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AbmVet.h"
#include "dataWarehouse.h"
#include "utn.h"


void inicializarClientes(eCliente* clientes, int tam)
{
    for(int i=0; i<tam; i++)
    {
        clientes[i].isEmpty = 1;
    }

}

void inicializarMascotas(eMascota* mascotas , int tam)
{
    for(int i=0; i<tam; i++)
    {
        mascotas[i].isEmpty = 1;
    }

}

void listarCliente(eCliente x)
{

    printf("%15s      %15s      %15s      %10d         %d        %2c\n", x.nombre, x.apellido, x.localidad, x.telefono, x.edad, x.sexo);
   // printf("Es duenio de las siguientes mascotas: \n\n");
   // printf("Nombre            Tipo           Raza      Edad  Peso   Sexo   ID duenio\n\n");
    //listarMascotasDuenio(cliente.id, clientes, mascotas, tipos, int tam, int tamMas, int tamTip);

}

void listarClientes(eCliente* vec, int tam)
{
    int flag=1;

    printf("           NOMBRE           APELLIDO           LOCALIDAD          TELEFONO       EDAD       SEXO\n\n");
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

    printf("NOMBRE         TIPO         RAZA        EDAD      PESO      SEXO      DUENIO\n\n");
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

    printf("%7s     %7s    %10s       %2d       %.2f       %2c  %10s\n\n", vec.nombre, tipoMascota, vec.raza, vec.edad, vec.peso, vec.sexo, nombreDuenio);

}
/*
void listarMascotasDuenio(int idD, eCliente* clientes, eMascotas* mascotas, eTipo* tipos, int tam, int tamMas, int tamTip)
{
	for(int i = 0; i < tamMas; i++)
	{
		if(idD == mascotas[i].idDuenio)
		{
			listarMascota(clientes, mascotas[i], tipos, tamMas, tamTip, tam);
		}
	}
}
*/
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

void listarAmbos(eCliente* clientes, eMascota* mascotas, eTipo* tipos, int tam, int tamMas, int tamTip)
{
    printf("***** Listado de clientes con sus mascotas *****\n\n");

    for(int i = 0; i < tam; i++)
    {
        if(clientes[i].isEmpty == 0)
        {
            printf("Duenio : %10s         %10s\n", clientes[i].nombre, clientes[i].apellido);

            for(int j = 0; j < tamMas; j++)
            {
                if(mascotas[j].isEmpty==0 && clientes[i].id == mascotas[j].idDuenio)
                {
                    listarMascota(clientes, mascotas[j], tipos, tamMas, tamTip, tam);
                }
            }
        }
    }
}

int altaMascota(eMascota* mascotas, eCliente* clientes, int tamMas, int tam)
{
    int retorno = -1;
    int index = buscarLibre(mascotas, tamMas);
    eMascota auxMascota;
    int contador = 0;

    if(mascotas != NULL && clientes != NULL && tam > 0 && tamMas > 0)
    {

        system("cls");
        printf("********* ALTA EMPLEADO ********\n\n");

        if(index == -1)
        {
            printf("Sistema completo. Sin lugares-\n");
        }
        else
        {
            printf("\nDUENIOS\n");
            for(int i=0; i<tam; i++)
            {
                if(clientes[i].isEmpty==0)
                {
                    printf("%d  %7s\n", clientes[i].id, clientes[i].nombre);
                }
            }
            fflush(stdin);
            if((utn_getNumeroEntero(&auxMascota.idDuenio, "\nIngresa el id del dueño: ", "\nError, solo numeros.\n", 1000, 1004, 2)) == 0)
            {
                contador++;
            }

            fflush(stdin);
            if((contador == 1) &&(utn_getString(auxMascota.nombre, "\nIngresa el nombre: ", "\nError, ese no es un nombre valido.\n", 2)) == 0)
            {
                formalizarString(auxMascota.nombre);
                printf("%s\n", auxMascota.nombre);
                contador++;
            }

            fflush(stdin);
            if((contador == 2) && (utn_getNumeroEntero(&auxMascota.idTipo, "\nIngresa el tipo\n1-Gato\n2-Perro\n3-Raro: ", "\nError, ese no es un tipo valido.\n", 1, 3, 2) == 0))
            {
                contador++;
            }
            fflush(stdin);
            if((contador == 3) && (utn_getString(auxMascota.raza, "\nIngresa la raza: ", "\nError, ingrese nuevamente.\n", 2) == 0))
            {
                printf("%7s\n", auxMascota.raza);
                contador++;
            }
            if((contador == 4) &&(utn_getNumeroEntero(&auxMascota.edad, "\nIngresa la edad: ", "\nError, solo numeros", 1, 50, 2) == 0))
            {
                printf("%d", auxMascota.edad);
                contador++;
            }
            if((contador == 5) && (utn_getNumeroFlotante(&auxMascota.peso, "\nIngrese el peso: ", "\nError, solo numeros", 0, 1000, 2)==0))
            {
                printf("%.2f", auxMascota.peso);
                contador++;
            }
            if((contador == 6) && (utn_getCharacter(&auxMascota.sexo, "\nIngrese el sexo(m/f): ", "\nError, solo (m/f)", 'm', 'f', 2)==0))
            {
                printf("%c", auxMascota.sexo);
                contador++;
            }
            if(contador == 7)
            {
                auxMascota.isEmpty = 0;

                mascotas[index] = auxMascota;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int bajaMascota(eMascota* mascotas, eCliente* clientes, int tamMas, int tam)
{
    int retorno = -1;
    char nombreMascota[20];
    int index;

    system("cls");
    if(mascotas != NULL && tam > 0 && clientes != NULL && tamMas > 0)
    {
        printf("************ BAJA MASCOTA ************\n\n");

        if((utn_getString(nombreMascota, "Ingresa el nombre de la mascota: ", "Error, ingresa solo letras.", 2)) == 0)
        {
            formalizarString(nombreMascota);
        }
        index = buscarMascota(nombreMascota, mascotas, tamMas);
        if(index == -1)
        {
            printf("\nNo hay registro de esa mascota.\n");
        }
        else
        {
            mascotas[index].isEmpty = 1;
            printf("Baja realizada con exito!\n\n");
            retorno = 0;
        }
    }

    return retorno;
}

int modificarMascota(eMascota* mascotas, eCliente* clientes, int tam, int tamMas)
{
    int retorno = -1;
    int index;
    char confirm;
    char nombreMascota[51];
    int opcionMenu;
    char nuevoNombre[51];
    int nuevoTipo;
    char nuevaRaza[51];
    int nuevaEdad;
    float nuevoPeso;
    char nuevoSexo;

    system("cls");
    if((utn_getString(nombreMascota, "Ingresa el nombre de la mascota: ", "Error, ingresa solo letras.", 2)) == 0)
        {
            formalizarString(nombreMascota);
        }
        index = buscarMascota(nombreMascota, mascotas, tamMas);
        if(index == -1)
        {
            printf("\nNo hay registro de esa mascota.\n");
        }
        else
        {
            system("pause");
            fflush(stdin);
            if(utn_getCharacter(&confirm, "¿Confirma la modificacion de esta mascota (s/n)?", "Error, ingrese (s/n): ", 's', 'n', 2) == 0)
            {
                if( confirm == 's')
                {
                    do
                    {
                        opcionMenu = menuModificar();
                        switch(opcionMenu)
                        {
                        case 1: //nombre
                            fflush(stdin);
                            if((utn_getString(nuevoNombre, "\nIngrese el nuevo nombre: ", "Error, ingrese un nombre por favor", 2))== 0)
                            {
                                formalizarString(nuevoNombre);
                                strcpy(mascotas[index].nombre, nuevoNombre);
                                retorno = 0;
                            }
                            break;
                        case 2: //tipo
                            fflush(stdin);
                            if((utn_getNumeroEntero(&nuevoTipo, "\nIngrese el nuevo tipo\n1-Gato\n2-Perro\n3-Raro: ", "Error, ingrese un tipo por favor.", 1,3,2))== 0)
                            {
                                mascotas[index].idTipo = nuevoTipo;
                                retorno = 0;
                            }
                            break;
                        case 3: //raza
                            fflush(stdin);
                            if((utn_getString(nuevaRaza, "\nIngrese la nueva raza: ", "Error, ingrese una raza.", 2))== 0)
                            {
                                formalizarString(nuevaRaza);
                                strcpy(mascotas[index].raza, nuevaRaza);
                                retorno = 0;
                            }
                            break;
                        case 4: //edad
                            fflush(stdin);
                            if((utn_getNumeroEntero(&nuevaEdad, "\nIngrese la nueva edad: ", "Error, ingrese un numero valido", 1, 50, 2)) == 0)
                            {
                                mascotas[index].edad = nuevaEdad;
                                retorno = 0;
                            }
                            break;
                        case 5: //peso
                            fflush(stdin);
                            if((utn_getNumeroFlotante(&nuevoPeso, "\nIngrese el nuevo peso: ", "Error, ingrese un numero valido", 1, 500, 2)) == 0)
                            {
                                mascotas[index].peso = nuevoPeso;
                                retorno = 0;
                            }
                            break;
                        case 6: //sexo
                            if((utn_getCharacter(&nuevoSexo, "\nIngrese el nuevo sexo: ", "Error, ingrese un sexo valido", 'm', 'f', 2)) == 0)
                            {
                                mascotas[index].sexo = nuevoSexo;
                                retorno = 0;
                            }
                            break;
                        case 7:
                            printf("Salir\n");
                            retorno = 0;
                            break;
                        default:
                            printf("No es una opcion valida\n");
                            break;
                        }
                    }while(opcionMenu != 7);
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
    printf("******** MENU DE MODIFICACIONES ********\n\n");
    printf("1- Modificar NOMBRE\n");
    printf("2- Modificar TIPO\n");
    printf("3- Modificar RAZA\n");
    printf("4- Modificar EDAD\n");
    printf("5- Modificar PESO\n");
    printf("6- Modificar SEXO\n");
    printf("7- Salir\n\n");
    fflush(stdin);
    if(utn_getNumeroEntero(&opcion, "Ingresa la opcion: ", "Por favor ingresa una opcion valida.", 1, 7, 2) == 0)
    {
        printf("\nOpcion %d\n", opcion);
    }

    return opcion;
}

int buscarMascota(char* nombreMascota, eMascota* mascotas, int tamMas)
{
    int indice = -1;

    for(int i=0; i < tamMas; i++)
    {
        if(strcmp(mascotas[i].nombre, nombreMascota) == 0 && mascotas[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarLibre(eMascota* mascotas, int tamMas)
{
    int index = -1;

    if(mascotas != NULL && tamMas > 0)
    {
        for(int i=0; i < tamMas; i++)
        {
            if(mascotas[i].isEmpty == 1)
            {
                index = i;
                break;
            }
        }
    }

    return index;
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
