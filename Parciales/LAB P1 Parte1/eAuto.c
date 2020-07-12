#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "lavadero.h"
#include "eTrabajo.h"
#include "eAuto.h"

void ordenarAutos(eAuto* autos, eMarca* marcas, int tamAu, int tamMa)
{
    eAuto auxAuto;

    if(autos != NULL && tamAu > 0 && marcas != NULL && tamMa > 0)
    {
        for(int i=0; i < tamAu - 1; i++)
        {
            for(int j=1; j < tamAu; j++)
            {
                if(autos[i].idMarca < autos[j].idMarca)
                {
                    auxAuto = autos[i];
                    autos[i]=autos[j];
                    autos[j]=auxAuto;
                }
            }
        }

        for(int m=0; m < tamMa; m++)
        {
            for(int i=0; i < tamAu -1; i++)
            {
                for(int j=1; j< tamAu; j++)
                {
                    if(autos[i].idMarca == m && autos[j].idMarca == m)
                    {
                        if(autos[i].patente < autos[j].patente)
                        {
                            auxAuto = autos[i];
                            autos[i]=autos[j];
                            autos[j]=auxAuto;
                        }
                    }
                }
            }
        }
    }
}

int altaAuto(eAuto* autos, int tamAu)
{
    int retorno = -1;
    int index = buscarLibreAuto(autos, tamAu);
    eAuto auxAuto;
    int contador = 0;

    if(autos != NULL && tamAu > 0)
    {
        system("cls");
        printf("********* ALTA AUTO ********\n\n");

        if(index == -1)
        {
            printf("Sistema completo. Sin lugares-\n");
        }
        else
        {

            fflush(stdin);
            if((utn_getNumeroEntero(&auxAuto.id, "\nIngresa el id: ", "\nError, solo numeros.\n",1 , 50000, 2)) == 0)
            {
                contador++;
            }

            fflush(stdin);
            if((contador == 1) &&(utn_getAlfanumerico(auxAuto.patente, "\nIngresa la patente (Numeros y letras Mayuscula): ", "\nError, solo numeros y letras en mayuscula.\n", 2)) == 0)
            {
                printf("Patente: %s\n", auxAuto.patente);
                contador++;
            }

            fflush(stdin);
            if((contador == 2) && (utn_getNumeroEntero(&auxAuto.idMarca, "\nIngresa la marca\n1000-Renault\n1001-Fiat\n1002-Ford\n1003-Chevrolet\n1004-Peugeot: ", "\nError, marca no valida.\n", 1000, 1004, 2) == 0))
            {
                contador++;
            }
            fflush(stdin);
            if((contador == 3) && (utn_getNumeroEntero(&auxAuto.idColor, "\nIngresa el color\n5000-Negro\n5001-Blanco\n5002-Gris\n5003-Rojo\n5004-Azul: ", "\nError, ingrese nuevamente el color.\n", 5000, 5004, 2) == 0))
            {
                contador++;
            }
            if((contador == 4) &&(utn_getNumeroEntero(&auxAuto.modelo, "\nIngresa el modelo(anio): ", "\nError, solo numeros", 1900, 2020, 2) == 0))
            {
                contador++;
            }
            if(contador == 5)
            {
                auxAuto.isEmpty = 0;

                autos[index] = auxAuto;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int modificarAuto(eAuto* autos, int tamAu)
{
    int retorno = -1;
    int index;
    int opcionMenu;
    char confirm;
    char patente[10];
    int nuevoIdColor;
    int nuevoModelo;

        system("cls");
        if((utn_getAlfanumerico(patente, "Ingresa la patente: ", "Error, ingresa solo numeros y letras mayusuculas.", 2)) == 0)
        {
            index = buscarAuto(patente, autos, tamAu);
        }
        if(index == -1)
        {
            printf("\nNo hay registro de ese auto.\n");
        }
        else
        {
            system("pause");
            fflush(stdin);
            if(utn_getCharacter(&confirm, "¿Confirma la modificacion de este auto (s/n)?", "Error, ingrese (s/n): ", 's', 'n', 2) == 0)
            {
                if( confirm == 's')
                {
                    do
                    {
                        opcionMenu = menuModificar();
                        switch(opcionMenu)
                        {
                        case 1:
                            fflush(stdin);
                            if((utn_getNumeroEntero(&nuevoIdColor, "\nIngrese el nuevo color: \n5000-Negro\n5001-Blanco\n5002-Gris\n5003-Rojo\n5004-Azul", "Error, ingrese un numero por favor", 5000, 5004, 2))== 0)
                            {
                                autos[index].idColor = nuevoIdColor;
                                retorno = 0;
                            }
                            break;
                        case 2:
                            fflush(stdin);
                            if((utn_getNumeroEntero(&nuevoModelo, "\nIngrese el nuevo modelo(anio): ", "Error, ingrese un numero por favor", 1900, 2020, 2))== 0)
                            {
                                autos[index].modelo = nuevoModelo;
                                retorno = 0;
                            }
                            break;
                        case 3:
                            printf("\n Salida exitosa");
                            break;
                        default:
                            printf("\nNo es una opcion valida");
                            break;
                        }
                    }while (opcionMenu!=3);
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
    printf("******** MENU DE MODIFICACIONES DEL AUTO********\n\n");
    printf("1- Modificar Color\n");
    printf("2- Modificar Modelo\n");
    printf("3- Salir\n\n");
    fflush(stdin);
    if(utn_getNumeroEntero(&opcion, "Ingresa la opcion: ", "Por favor ingresa una opcion valida.", 1, 3, 2) == 0)
    {
        printf("\nOpcion %d\n", opcion);
    }

    return opcion;
}

int bajaAuto(eAuto* autos, int tamAu)
{
    int retorno = -1;
    char patenteAuto[10];
    int index;
    char confirm;

    system("cls");
    if(autos != NULL && tamAu > 0)
    {
        printf("************ BAJA AUTO ************\n\n");

        if((utn_getAlfanumerico(patenteAuto, "Ingresa la patente: ", "Error, ingresa solo numeros y letras mayusculas.", 2)) == 0)
        {
            index = buscarAuto(patenteAuto, autos, tamAu);
        }
        if(index == -1)
        {
            printf("\nNo hay registro de ese auto.\n");
        }
        else
        {
            if(utn_getCharacter(&confirm, "¿Confirma la baja de este auto (s/n)?", "Error, ingrese (s/n): ", 's', 'n', 2) == 0)
            {
                if(confirm == 's')
                {
                    autos[index].isEmpty = 1;
                    printf("Baja realizada con exito!\n\n");
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}

void listarAutos(eAuto* autos, eMarca* marcas, eColor* colores, int tamAu, int tamMa, int tamCo)
{
    int flag=1;

    ordenarAutos(autos, marcas, tamAu, tamMa);

    printf("   ID        PATENTE           MARCA           COLOR          MODELO    \n\n");
    for(int i=0; i<tamAu; i++)
    {
        if(autos[i].isEmpty==0)
        {
            listarAuto(autos[i], marcas, colores, tamAu, tamMa, tamCo);
            flag=0;
        }

    }
    if(flag==1)
    {
        printf("No hay autos para mostrar");
    }

}

void listarAuto(eAuto autos, eMarca* marcas, eColor* colores, int tamAu, int tamMa, int tamCo)
{
    char marcaAuto[20];
    char colorAuto[20];

    cargarMarcaAuto(marcaAuto, autos.idMarca, marcas, tamMa);
    cargarColorAuto(colorAuto, autos.idColor, colores, tamCo);

    printf("%2d             %6s         %7s           %7s          %2d         \n\n", autos.id, autos.patente, marcaAuto, colorAuto, autos.modelo);

}

int cargarMarcaAuto(char* descripcion, int idAuto, eMarca* marcas, int tamMa)
{
    int todoOk=0;

    for(int i=0; i<tamMa; i++)
    {
        if(marcas[i].id == idAuto)
        {
            strcpy(descripcion, marcas[i].descripcion);
            todoOk=1;
        }
    }

   return todoOk;
}

int cargarColorAuto(char* descripcion, int idAuto, eColor* colores, int tamCo)
{
    int todoOk=0;

    for(int i=0; i<tamCo; i++)
    {
        if(colores[i].id == idAuto)
        {
            strcpy(descripcion, colores[i].nombreColor);
            todoOk=1;
        }
    }

   return todoOk;
}

int buscarAuto(char* patente, eAuto* autos, int tamAu)
{
    int indice = -1;

    for(int i=0; i < tamAu; i++)
    {
        if(strcmp(autos[i].patente, patente) == 0 && autos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarLibreAuto(eAuto* autos, int tamAu)
{
    int index = -1;

    if(autos != NULL && tamAu > 0)
    {
        for(int i=0; i < tamAu; i++)
        {
            if(autos[i].isEmpty == 1)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

void inicializarAutos(eAuto* autos, int tamAu)
{
    for(int i=0; i<tamAu; i++)
    {
        autos[i].isEmpty = 1;
    }

}


int informar(eAuto* autos, eTrabajo* trabajos, eMarca* marcas, eColor* colores, eServicio* servicios, int tamAu, int tamTra, int tamMa, int tamCo, int tamSer)
{
    int opcionMenuInformes;

     do
        {
        opcionMenuInformes = mostrarMenuInformes();
        system("cls");
        switch(opcionMenuInformes)
        {
        case 1:
            system("cls");
            informarAutoPorColor(autos, colores, marcas, tamAu, tamCo, tamMa);
            system("pause");
            break;
        case 2:
            system("cls");
            informarAutoPorMarca(autos, colores, marcas, tamAu, tamCo, tamMa);
            system("pause");
            break;
        case 3:
            system("cls");
            informarAutoMasViejo(autos, marcas, colores, tamAu, tamMa, tamCo);
            system("pause");
            break;
        case 4:
            system("cls");
            listarAutosPorMarca(autos, marcas, colores, tamAu, tamMa, tamCo);
            system("pause");
            break;
        case 5:
            system("cls");
            contarAutosPorColorYMarca(autos, tamAu);
            system("pause");
            break;
        case 6:
            system("cls");
            informarMarcaMasElegida(autos, marcas, tamAu, tamMa);
            system("pause");
            break;
        case 7:
            system("cls");
            informarTrabajosPorAuto(autos, trabajos, servicios, tamAu, tamTra, tamSer);
            system("pause");
            break;
        case 8:
            system("cls");
            informarImporteTotalAuto(autos, trabajos, servicios, tamAu, tamTra, tamSer);
            system("pause");
            break;
        case 9:
            system("cls");
            informarServiciosPorAuto(autos, marcas, colores, servicios, trabajos, tamAu, tamMa, tamCo, tamSer, tamTra);
            system("pause");
            break;
        case 10:
            //informar();
            break;
        case 11:
            printf("\n Salida exitosa");
            break;
        default:
            printf("No es una opcion valida\n");
            break;
        }
        system("cls");
    }
    while(opcionMenuInformes!=11);

    return 0;
}

void informarAutoPorColor(eAuto* autos, eColor* colores, eMarca* marcas, int tamAu, int tamCo, int tamMa)
{
    int colorElegido;
    int flag = 0;

    if(utn_getNumeroEntero(&colorElegido, "\nIngresa color:\n5000-Negro\n5001-Blanco\n5002-Gris\n5003-Rojo\n5004-Azul:\n", "\nError, solo los numeros indicados\n", 5000, 5004, 3)== 0)
    {
       printf("\nProcediendo a mostrar autos con ese color!\n\n");
    }
    printf("   ID        PATENTE           MARCA           COLOR          MODELO    \n\n");
    for(int i=0; i<tamAu; i++)
    {
        if(autos[i].idColor == colorElegido)
        {
            listarAuto(autos[i], marcas, colores, tamAu, tamMa, tamCo);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay autos con ese color\n");
    }
}

void informarAutoPorMarca(eAuto* autos, eColor* colores, eMarca* marcas, int tamAu, int tamCo, int tamMa)
{
    int marcaElegida;
    int flag = 0;

    if(utn_getNumeroEntero(&marcaElegida, "\nIngresa marca:\n1000-Renault\n1001-Fiat\n1002-Ford\n1003-Chevrolet\n1004-Peugeot\n", "\nError, solo los numeros indicados\n", 1000, 1004, 3) == 0)
    {
        printf("\nProcediendo a mostrar autos con esa marca!\n\n");
    }
    printf("   ID        PATENTE           MARCA           COLOR          MODELO    \n\n");
    for(int i=0; i<tamAu; i++)
    {
        if(autos[i].isEmpty == 0 && autos[i].idMarca == marcaElegida)
        {
            listarAuto(autos[i], marcas, colores, tamAu, tamMa, tamCo);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay autos con esa marca\n");
    }
}

void informarAutoMasViejo(eAuto* autos, eMarca* marcas, eColor* colores, int tamAu, int tamMa, int tamCo)
{
    int flag =0;
    int masViejo;

    for(int i = 0; i < tamAu ; i++)
	{
		if(autos[i].isEmpty == 0)
		{
			if(flag == 0 || autos[i].modelo < masViejo)
			{
				masViejo = autos[i].modelo;
				flag = 1;
			}
		}
	}
	printf("   ID        PATENTE           MARCA           COLOR          MODELO    \n\n");
	for(int j=0; j<tamAu; j++)
    {
        if(autos[j].isEmpty == 0 && autos[j].modelo == masViejo)
        {
            listarAuto(autos[j], marcas, colores, tamAu, tamMa, tamCo);
        }
    }
}

void listarAutosPorMarca(eAuto* autos, eMarca* marcas, eColor* colores, int tamAu, int tamMa, int tamCo)
{

    printf("\n************AUTOS SEPARADOS POR MARCA*************\n\n");
    printf("   ID        PATENTE           MARCA           COLOR          MODELO    \n\n");
    printf("\n*** MARCA RENAULT ***\n");
    for(int i=0; i < tamAu; i++)
    {
        if(autos[i].isEmpty == 0 && autos[i].idMarca == 1000)
        {
            listarAuto(autos[i], marcas, colores, tamAu, tamMa, tamCo);
        }
    }
    printf("\n*** MARCA FIAT ***\n");
    for(int j=0; j < tamAu; j++)
    {
        if(autos[j].isEmpty == 0 && autos[j].idMarca == 1001)
        {
            listarAuto(autos[j], marcas, colores, tamAu, tamMa, tamCo);
        }
    }
    printf("\n*** MARCA FORD ***\n");
    for(int k=0; k < tamAu; k++)
    {
        if(autos[k].isEmpty == 0 && autos[k].idMarca == 1002)
        {
            listarAuto(autos[k], marcas, colores, tamAu, tamMa, tamCo);
        }
    }
    printf("\n*** MARCA CHEVROLET ***\n");
    for(int l=0; l < tamAu; l++)
    {
        if(autos[l].isEmpty == 0 && autos[l].idMarca == 1003)
        {
            listarAuto(autos[l], marcas, colores, tamAu, tamMa, tamCo);
        }
    }
    printf("\n*** MARCA PEUGEOT ***\n");
    for(int m=0; m < tamAu; m++)
    {
        if(autos[m].isEmpty == 0 && autos[m].idMarca == 1004)
        {
            listarAuto(autos[m], marcas, colores, tamAu, tamMa, tamCo);
        }
    }

}

void contarAutosPorColorYMarca(eAuto* autos, int tamAu)
{
    int contadorAutos = 0;
    int flag = 0;
    int marcaElegida;
    int colorElegido;

    if(utn_getNumeroEntero(&marcaElegida, "\nIngresa marca:\n1000-Renault\n1001-Fiat\n1002-Ford\n1003-Chevrolet\n1004-Peugeot\n", "\nError, solo los numeros indicados\n", 1000, 1004, 3) == 0)
    {
        printf("\nProcediendo a cuantificar autos con esa marca!\n\n");
    }
    if(utn_getNumeroEntero(&colorElegido, "\nIngresa color:\n5000-Negro\n5001-Blanco\n5002-Gris\n5003-Rojo\n5004-Azul:\n", "\nError, solo los numeros indicados\n", 5000, 5004, 3)== 0)
    {
       printf("\nProcediendo a cuantificar autos con ese color!\n\n");
    }

    for(int i=0; i< tamAu; i++)
    {
        if(autos[i].isEmpty == 0 && autos[i].idColor == colorElegido && autos[i].idMarca == marcaElegida)
        {
            contadorAutos++;
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo se encuentran autos con esa marca y ese color!\n");
    }
    else
    {
        printf("\nLa cantidad de autos con esa marca y color es: %d\n\n", contadorAutos);
    }
}

void informarMarcaMasElegida(eAuto* autos, eMarca* marcas, int tamAu, int tamMa)
{
    int contadorMayor;
    int flag=0;
    int contadorDeMarcas[5]={0, 0, 0, 0, 0};
    char marcaAuto[20];

    for(int i=0; i < tamMa; i++){

        for(int j=0; j < tamMa; j++)
        {
            if(autos[j].idMarca == marcas[i].id)
            {
                contadorDeMarcas[i]++;
            }
        }
    }

    for(int i=0; i < tamMa; i++)
    {
        if(flag == 0 || contadorDeMarcas[i] > contadorMayor)
        {
            contadorMayor = contadorDeMarcas[i];
            flag=1;
        }
    }

    printf("\nMarcas mas elegidas:\n");

    for(int i=0; i < tamMa; i++)
    {
        if(contadorMayor == contadorDeMarcas[i])
        {
            cargarMarcaAuto(marcaAuto, marcas[i].id, marcas, tamMa);
            printf("%7s\n", marcaAuto);
        }
    }
}

void informarTrabajosPorAuto(eAuto* autos, eTrabajo* trabajos, eServicio* servicios, int tamAu, int tamTra, int tamSer)
{
    char patente[21];
    int index;
    int flag = 0;

    if(utn_getAlfanumerico(patente, "\nIngresa la patente: ", "\nError, solo numeros y mayusculas\n", 3) == 0)
    {
        index = buscarPatenteTrabajo(patente, trabajos, tamTra);
    }
    if(index == -1)
    {
        printf("\nEsa patente no corresponde a ningun auto\n");
    }

    if(trabajos[index].isEmpty == 0)
    {
        printf("   ID        PATENTE           SERVICIO           FECHA    \n\n");
        listarTrabajo(trabajos[index], servicios, tamTra, tamSer);
        flag=1;
    }

    if(flag == 0)
    {
        printf("\nEste auto no recibio trabajos\n");
    }

}

void informarImporteTotalAuto(eAuto* autos, eTrabajo* trabajos, eServicio* servicios, int tamAu, int tamTra, int tamSer)
{
    char patente[21];
    int index;
    int flag = 0;
    float acumuladorImporte = 0;

    if(utn_getAlfanumerico(patente, "\nIngresa la patente: ", "\nError, solo numeros y mayusculas\n", 3) == 0)
    {
        index = buscarPatenteTrabajo(patente, trabajos, tamTra);
    }
    if(index == -1)
    {
        printf("\nEsa patente no corresponde a ningun auto\n");
    }

    for(int s=0; s < tamSer; s++)
    {
        if(trabajos[index].isEmpty == 0 && trabajos[index].idServicio == servicios[s].id)
        {
            acumuladorImporte+=servicios[s].precio;
            flag=1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo se le realizaron servicios al auto\n");
    }
    printf("\nEl importe total fue de: %.2f\n", acumuladorImporte);

}

void informarServiciosPorAuto(eAuto* autos, eMarca* marcas, eColor* colores, eServicio* servicios, eTrabajo* trabajos, int tamAu, int tamMa, int tamCo, int tamSer, int tamTra)
{
    int idServicio;
    int index;

    if(utn_getNumeroEntero(&idServicio, "\nIngresa servicio:\n20000-Lavado\n20001-Pulido\n20002-Encerado\n20003-Completo\n", "\nError, solo los numeros indicados\n", 20000, 20003, 3) == 0)
    {
        printf("\nProcediendo a mostrar trabajos con ese servicio!\n\n");
    }

    printf("   ID        PATENTE           MARCA           COLOR          MODELO\n\n\n");

    for(int i=0; i<tamTra; i++)
    {
        if(trabajos[i].isEmpty == 0 && trabajos[i].idServicio == idServicio)
        {
            index = buscarAuto(trabajos[i].patente, autos, tamAu);
            printf("**************FECHA**************\n");
            printf("           %d/%d/%d\n\n", trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
            listarAuto(autos[index], marcas, colores, tamAu, tamMa, tamCo);
        }
    }

}

int mostrarMenuInformes()
{
    int opcion;

    printf("\n***********MENU DE INFORMES*********:\n\n");
    printf("1- Mostrar autos por color\n");
    printf("2- Mostrar autos por marca\n");
    printf("3- Informar el auto mas viejo\n");
    printf("4- Listado de autos por marca\n");
    printf("5- Contador de autos por color y marca\n");
    printf("6- Marca mas elegida por clientes\n");
    printf("7- Trabajos por auto\n");
    printf("8- Importe total por auto\n");
    printf("9- Informes por servicio\n");
    printf("10- Informes por fecha\n");
    printf("11- Salir\n");


    fflush(stdin);
    utn_getNumeroEntero(&opcion, "Ingrese opcion: ", "\nEsa opcion no es valida. ", 1, 11, 10);

    return opcion;
}
