#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

#define TAMNOT 4

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;

} eNotebook;

float aplicarDescuento(float precio);

int contarCaracteres(char* cadena, char caracter);

void ordenarEstructura(eNotebook* notebooks, int tamNot);

void listarNotebooks(eNotebook* notebooks, int tamNot);

void listarNotebook(eNotebook x);

int main()
{
    float precio;
    char cadena[51];
    char caracter;
    int cantidadDeCaracteres;
    eNotebook notebooks[TAMNOT]={{1000, "Ryzen", "Dell", 25000}, {1001, "Intel", "Lenovo", 30000},{1002, "Amd", "Acer", 18500},{1003, "Intel", "Acer", 44000}};

    //1ER EJERCICIO
    printf("Ingresa el precio: ");
    scanf("%f", &precio);

    precio = aplicarDescuento(precio);
    printf("%.2f", precio);

    //2DO EJERCICIO
    utn_getString(cadena, "\nIngresa una cadena: ", "Error, solo caracteres", 3);

    printf("Ingresa el caracter: ");
    scanf("%c", &caracter);

    cantidadDeCaracteres = contarCaracteres(cadena, caracter);
    printf("\nLa cantidad de veces que aparece es: %d\n\n", cantidadDeCaracteres);

    //3ER EJERCICIO
    ordenarEstructura(notebooks, TAMNOT);
    listarNotebooks(notebooks, TAMNOT);

    return 0;
}

float aplicarDescuento(float precio)
{
    float nuevoPrecio;
    float descuento;

    descuento = (float) (precio *5/100);
    nuevoPrecio = precio-descuento;

    return nuevoPrecio;
}

int contarCaracteres(char* cadena, char caracter)
{
    int contadorCaracteres=0;

    for(int i=0; i<strlen(cadena); i++)
    {
        if(cadena[i] == caracter)
        {
            contadorCaracteres++;
        }
    }

    return contadorCaracteres;
}

void ordenarEstructura(eNotebook* notebooks, int tamNot)
{
    eNotebook auxNot;


    for(int i=0; i < tamNot -1; i++)
    {
        for(int j=i+1; j < tamNot; j++)
        {
            if(strcmp(notebooks[i].marca, notebooks[j].marca)==1)
            {
                auxNot = notebooks[i];
                notebooks[i]=notebooks[j];
                notebooks[j]=auxNot;
            }
            else
            {
                if(strcmp(notebooks[i].marca, notebooks[j].marca)==0)
                {
                    if(notebooks[i].precio < notebooks[j].precio)
                    {
                        auxNot = notebooks[i];
                        notebooks[i]=notebooks[j];
                        notebooks[j]=auxNot;
                    }
                }
            }
        }
    }

}

void listarNotebooks(eNotebook* notebooks, int tamNot)
{
    int flag=1;

    printf("ID       PROCESADOR               MARCA      PRECIO\n\n");
    for(int i=0; i<tamNot; i++)
    {
        listarNotebook(notebooks[i]);
        flag=0;
    }
    if(flag==1)
    {
        printf("No hay notebooks para mostrar");
    }

}

void listarNotebook(eNotebook x)
{
    printf("%2d      %10s       %10s        %.2f\n\n", x.id, x.procesador, x.marca, x.precio);
}
