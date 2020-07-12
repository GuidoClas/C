#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Articulo.h"
#include "Rubro.h"
#include "utn.h"


Articulo* articulo_new()
{
    Articulo* articulo = (Articulo*) malloc(sizeof(Articulo)); // Solicitamos espacio en memoria dinamica para un empleado

    if(articulo != NULL) // Verificamos que ese empleado generado no sea NULL y ponemos los campos vacios para evitar basura
    {
        articulo_setId(articulo, 0);
        articulo_setArticulo(articulo, " ");
        articulo_setPrecio(articulo, 0);
        articulo_setMedida(articulo, 0);
        articulo_setRubroId(articulo, 0);
    }

    return articulo;
}



Articulo* articulo_newParametros(char* idStr,char* articuloStr, char* precioStr, char* medidaStr, char* rubroIdStr)
{
    Articulo* articulo = articulo_new(); // Solicitamos espacio en memoria dinamica para un cliente

    if(articulo != NULL && idStr != NULL && articuloStr != NULL && precioStr != NULL && medidaStr != NULL && rubroIdStr != NULL) // Verificamos que ese cliente generado no sea NULL y le asignamos los atributos recibidos como parametros
    {
        articulo_setId(articulo, atoi(idStr));
        articulo_setArticulo(articulo, articuloStr);
        articulo_setPrecio(articulo, atof(precioStr));
        articulo_setMedida(articulo, atoi(medidaStr));
        articulo_setRubroId(articulo, atoi(rubroIdStr));
    }
    else
    {
        free(articulo);
        articulo = NULL;
    }

    return articulo;
}

void listArticulos(LinkedList* pArrayList, Rubro* rubros)
{
    int llSize;
    Articulo* articulo;

    if(pArrayList != NULL) // Verifico que el puntero LL recibido no sea NULL
    {
        printf("\n%15s%15s%15s%15s%40s\n", "Id", "Articulo", "Precio", "Medida", "Rubro"); // Imprimo de manera ordenada las columnas
        llSize = ll_len(pArrayList);
        for(int i=0; i<llSize; i++)
        {
            //Obtengo en cada iteracion un empleado, y se lo envio a la funcion listEmployee destinada a mostrarlo
            articulo = (Articulo*) ll_get(pArrayList, i);
            listArticulo(articulo, rubros);
        }
    }
}


void listArticulo(Articulo* articulo, Rubro* rubros)
{
    int id;
    char art[21];
    float precio;
    int medida;
    int idRubro;
    char rubro[51];

    if(articulo != NULL) // Verifico que el cliente recibido no sea NULL
    {
        articulo_getId(articulo, &id);
        articulo_getArticulo(articulo, art);
        articulo_getPrecio(articulo, &precio);
        articulo_getMedida(articulo, &medida);
        articulo_getRubroId(articulo, &idRubro);
        cargarDescripcionRubro(rubro, idRubro, rubros);
        printf("%15d%15s%15.2f%15d%   40s\n", id, art, precio, medida, rubro);
    }

}

int articulo_setId(Articulo* this,int id)
{
    int retorno = -1;

    if(this != NULL && id > 0) // Verifico que el empleado recibido no sea NULL y que el id sea valido
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;
}

int articulo_getId(Articulo* this,int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL) // Verifico que el empleado recibido no sea NULL y que el id sea valido
    {
       *id = this->id;
       retorno = 0;
    }

    return retorno;
}

int articulo_setArticulo(Articulo* this,char* articulo)
{
    int retorno = -1;

    if(this != NULL && articulo != NULL) // Verifico que el empleado recibido no sea NULL y que el articulo sea valido
    {
        strcpy(this->articulo, articulo);
        retorno = 0;
    }

    return retorno;
}

int articulo_getArticulo(Articulo* this,char* articulo)
{
    int retorno = -1;

    if(this != NULL && articulo != NULL) // Verifico que el empleado recibido no sea NULL y que el articulo sea valido
    {
       strcpy(articulo, this->articulo);
       retorno = 0;
    }

    return retorno;
}

int articulo_setPrecio(Articulo* this, float precio)
{
    int retorno = -1;

    if(this != NULL && precio > 0) // Verifico que el empleado recibido no sea NULL y que las horas sean validas
    {
        this->precio = precio;
        retorno = 0;
    }

    return retorno;
}

int articulo_getPrecio(Articulo* this, float* precio)
{
    int retorno = -1;

    if(this != NULL && precio != NULL)  // Verifico que el empleado recibido no sea NULL y que las horas sean validas
    {
       *precio = this->precio;
       retorno = 0;
    }

    return retorno;

}

int articulo_setMedida(Articulo* this, int medida)
{
    int retorno = -1;

    if(this != NULL && medida > 0)  // Verifico que el empleado recibido no sea NULL y que el medida sea valido
    {
        this->medida = medida;
        retorno = 0;
    }

    return retorno;
}

int articulo_getMedida(Articulo* this, int* medida)
{
    int retorno = -1;

    if(this != NULL && medida != NULL) // Verifico que el empleado recibido no sea NULL y que el medida sea valido
    {
       *medida = this->medida;
       retorno = 0;
    }

    return retorno;
}

int articulo_setRubroId(Articulo* this, int rubroId)
{
    int retorno = -1;

    if(this != NULL && rubroId > 0)  // Verifico que el empleado recibido no sea NULL y que el sueldo sea valido
    {
        this->rubroId = rubroId;
        retorno = 0;
    }

    return retorno;
}

int articulo_getRubroId(Articulo* this,int* rubroId)
{
    int retorno = -1;

    if(this != NULL && rubroId != NULL) // Verifico que el empleado recibido no sea NULL y que el rubroId sea valido
    {
       *rubroId = this->rubroId;
       retorno = 0;
    }

    return retorno;
}

int sortArticulos(void* articulo1,void* articulo2)
{
    char art1[51];
    char art2[51];
    int retorno;

    if(!articulo_getArticulo(articulo1, art1) && !articulo_getArticulo(articulo2, art2)) //Obtengo el dato a comparar de cada empleado y le doy un criterio
    {
        if(strcmp(art1, art2) == 1)
        {
            retorno = 1;
        }
        else if(strcmp(art1, art2) == -1)
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

Articulo* aplicarDescuentos(void* art)
{

    int rubroId;
    float precio;
    float precioConDescuento;
    Articulo* articulo = NULL;

    if(art != NULL)
    {
        articulo = (Articulo*) art;
        if(!articulo_getPrecio(articulo, &precio) && !articulo_getRubroId(articulo, &rubroId))
        {
            if(rubroId == 1 && precio >= 120)
            {
                precioConDescuento = precio*0.8;
                articulo_setPrecio(articulo, precioConDescuento);
            }
            else if(rubroId == 2 && precio <= 200)
            {
                precioConDescuento = precio*0.9;
                articulo_setPrecio(articulo, precioConDescuento);
            }
        }
    }

    return articulo;
}

int cargarDescripcionRubro(char* descripcion, int idArt, Rubro* rubros)
{
    int retorno = -1;

    for(int i=0; i<4; i++)
    {
        if(rubros[i].id == idArt)
        {
            strcpy(descripcion, rubros[i].descripcion);
            retorno = 0;
        }
    }

   return retorno;
}
