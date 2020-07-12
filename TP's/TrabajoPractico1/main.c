#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "operacionesMat.h"
#include "validarInt.h"
#include "menu.h"

int main()
{
    int x; //Primer operando que se guardara en la variable X.
    int y; //Segundo operando que se guardara en la variable Y.
    int flagX = 0;
    int flagY = 0;
    int flagOperaciones = 0;
    int flagInformar = 0;
    int opcion; //Opcion sera la variable que almacenara la funcion que muestra el menu y sus parametros correspondientes.

    //flagX y flagY seran las variables que cambiaran su valor a 1 una vez que se hayan ingresado los operandos respectivamente.
    //flagOperaciones cambiara su valor a 1 una vez que se hayan calculado las operaciones y flagInformar es el parametro
    //que recibe la funcion mostrarMenu para indicarle que puede informar los resultados correctamente.
    do
    {
        opcion = mostrarMenu(x, y, flagX, flagY, flagInformar);
        switch(opcion)
        {
        case 1:
            x = getInt();//Se le asignara a X la funcion getInt(solicita y valida enteros) y si logra retornar un entero, flagX cambiara su valor a 1.
            flagX = 1;
            system("pause");
            system("cls");
            break;
        case 2:
            //Si no se ingreso el primer operando, se le solicitara al usuario, si se ingreso, se le asignara a la variable Y
            //la funcion getInt(solicita y valida enteros) y si logra retornar un entero, flagY cambiara su valor a 1.
            if(flagX == 0)
            {
                printf("\nIngresa el primer operando antes!\n");
                system("pause");
            }
            else
            {
                y = getInt();
                flagY = 1;
                system("pause");
            }
            system("cls");
            break;
        case 3:
            //Si el segundo operando no fue ingresado, se le solicitara que lo ingrese, si fue ingresado se le indicara que se pudieron calcular
            //las operaciones correctamente y flagOperaciones cambiara su valor a 1.
            if(flagY==0)
            {
                printf("\nDebes ingresar los dos operandos antes de calcular!\n");
                system("pause");
            }
            else
            {
                printf("\nLas operaciones se calcularon exitosamente!\n");
                flagOperaciones = 1;
                system("pause");
            }
            system("cls");
            break;
        case 4:
            //Si las operaciones no fueron calculadas correctamente, se le solicitara nuevamente al usuario. En cambio si fueron calculadas
            //correctamente, flagInformar cambiara su valor a 1 y se enviara como parametro a la funcion mostrarMenu().
            if(flagOperaciones==0)
            {
                printf("\nDebes calcular las operaciones antes de informar los resultados!\n");
                system("pause");
            }
            else
            {
                flagInformar = 1;
                system("pause");
            }
            system("cls");
            break;
        case 5:
            //En caso de que el usuario elija la opcion 5, simplemente se mostrar un mensaje por pantalla y se finalizara el programa
            //ya que es la opcion de salida del mismo.
            system("cls");
            printf("\nEl programa finalizo exitosamente.\n");
            break;
        default:
            //En caso de no ingresarse una opcion dentro de los parametros 1 al 5, se le indicara al usuario que esa opcion no es valida.
            printf("No es una opcion valida\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while (opcion!=5); //El bucle solo finalizara si el usuario ingresa la opcion 5.


    return 0;
}


