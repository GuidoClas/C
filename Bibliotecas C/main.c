#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    char nombre[50];

    if((utn_getString(nombre, "\nIngresa un nombre: ", "\nError, ese no es un nombre.\n", 2))== 0)
    {
        formalizarString(nombre);
        printf("%s", nombre);
    }
    return 0;
}
