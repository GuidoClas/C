#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Articulo.h"
#include "parser.h"
#include "Rubro.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    int retorno = -1;
    FILE* file;

    if(path != NULL && pArrayList!= NULL) // Verifico que los punteros recibidos no sean NULL
    {
        ll_clear(pArrayList);
        file = fopen(path, "r");

        if(file != NULL) // Verifico que el archivo abierto no sea NULL
        {
            if(!parser_ArticuloFromText(file, pArrayList))
            {
                retorno = 0;
            }
            fclose(file);
        }
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */

int controller_ListArticulos(LinkedList* pArrayList, Rubro* rubros)
{
    int retorno = -1;

    if(pArrayList != NULL) // Verifico que el puntero recibo LL no sea NULL
    {
        listArticulos(pArrayList, rubros);
    }

    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
    int retorno = -1;
    FILE* file;
    int llSize;
    Articulo* articulo = NULL;
    int auxId;
    char auxArticulo[21];
    float auxPrecio;
    int auxMedida;
    int auxRubroId;


    if(path != NULL && pArrayList != NULL) //Verifico que los punteros recibidos no sean NULL
    {
        file = fopen(path, "w");
        llSize = ll_len(pArrayList);
        if(file != NULL) //Verifico que el archivo abierto no haya devuelto NULL
        {
            for(int i=0; i<llSize; i++)
            {
                articulo = (Articulo*) ll_get(pArrayList, i);
                if(articulo != NULL)
                {
                    articulo_getId(articulo, &auxId);
                    articulo_getArticulo(articulo, auxArticulo);
                    articulo_getPrecio(articulo, &auxPrecio);
                    articulo_getMedida(articulo, &auxMedida);
                    articulo_getRubroId(articulo, &auxRubroId);

                    fprintf(file,"%d,%s,%.2f,%d,%d\n", auxId, auxArticulo, auxPrecio, auxMedida, auxRubroId);
                }
            }
            retorno = 0;
            fclose(file);
        }
    }

    return retorno;
}

int mainMenu()
{
    int option;

    printf("\n---------------------- Menu de Opciones ----------------------\n\n");
    printf("1. Cargar los datos de los articulos desde el archivo articulos.csv (modo texto)\n");
    printf("2. Ordenar\n");
    printf("3. Listar\n");
    printf("4. Aplicar descuentos\n");
    printf("5. Guardar descuentos en archivo mapeado.csv\n");
    printf("6. Salir\n");
    utn_getNumeroEntero(&option, "Ingresa la opcion: ", "Error, opcion del 1 al 10 solamente: ", 1, 6, 3);

    return option;
}
