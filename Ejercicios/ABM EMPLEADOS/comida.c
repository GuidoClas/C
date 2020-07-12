#include "comida.h"
#include <stdio.h>
#include <stdlib.h>

void listarComidas(eComida comidas[], int tam)
{
    for(int i=0; i<tam;i++)
    {
        printf("%d   %10s  %5.2f \n", comidas[i].id, comidas[i].descripcion, comidas[i].precio);
    }

    printf("\n");
}
