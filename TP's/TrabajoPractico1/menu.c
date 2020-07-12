#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operacionesMat.h"

//La funcion mostrarMenu recibe como parametros el primer operando y el segundo operando, la bandera correspondiente a cada uno y la bandera
//flagInformar que indica que se podran informar los resultados sin problemas.
//La funcion mostrarMenu, mostrar por pantalla, los printf correspondientes al menu que vera el usuario, dependiendo de si las banderas fueron activadas en main.
int mostrarMenu(int num1, int num2, int flagX, int flagY, int flagInformar)
{
    int opcion; //Opcion es la variable que retornaremos a Main, siendo esta la opcion del switch.

    printf("\n************* Menu de opciones *************\n");
    //Si x fue ingresado se mostrara reemplazado en el menu. Si no fue ingresado, se mostrara el menu por defecto.
    if(flagX==0)
    {
        printf("\n1- Ingresar 1er operando (A=x)\n");
    }
    else
    {
        printf("\n1- 1er operando (A=%d)\n", num1);
    }
    //Si y fue ingresado se mostrara reemplazado en el menu. Si no fue ingresado, se mostrara el menu por defecto.
    if(flagY==0)
    {
        printf("\n2- Ingresar 2do operando (B=y)\n");
    }
    else
    {
        printf("\n2- 2do operando (B=%d)\n", num2);
    }
    //Si no se ingresaron los dos operandos, mostrara el menu para calcular operaciones por defecto. En cambio si se ingresaron
    //mostrara el menu para calcular las operaciones con ambos operandos reemplazados en A y B.
    if(flagX==0 && flagY==0)
    {
        printf("\n\n3- Calcular las operaciones: \n");
        printf("\n\tA) Calcular la suma (A + B)");
        printf("\n\tB) Calcular la resta (A - B)");
        printf("\n\tC) Calcular la division (A / B)");
        printf("\n\tD) Calcular la multiplicacion (A * B)");
        printf("\n\tD) Calcular los factoriales (A! y B!)");
    }
    else
    {
        printf("\n\n3- Calcular resultados: \n");
        printf("\n\tA) Calcular la suma (%d + %d)", num1, num2);
        printf("\n\tB) Calcular la resta (%d - %d)", num1, num2);
        printf("\n\tC) Calcular la division (%d / %d)", num1, num2);
        printf("\n\tD) Calcular la multiplicacion (%d * %d)", num1, num2);
        printf("\n\tD) Calcular los factoriales (%d! y %d!)", num1, num2);
    }
    //Si la bandera flagInformar no fue activada en Main, se mostrara el menu para informar resultados por defecto.
    //En cambio si la bandera flagInformar fue activada desde Main, se mostrara el menu con los operandos reemplazados y los resultados correspondientes.
    //Cada printf que muestra los resultados, estara haciendo una llamada a la funcion matematica de "operacionesMat.h" correspondiente.
    if(flagInformar==0)
    {
        printf("\n\n4- Informar resultados: \n");
        printf("\n\tA) El resultado de A+B es: r");
        printf("\n\tB) El resultado de A-B es: r");
        printf("\n\tC) El resultado de A/B es: r");
        printf("\n\tD) El resultado de A*B es: r");
        printf("\n\tE) El factorial de A es: r1 y El factorial de B es: r2 ");
    }
    else
    {
        printf("\n\n4- Informar resultados: \n");
        printf("\n\tA) El resultado de %d + %d es: %d", num1, num2, Sumar(num1, num2));
        printf("\n\tB) El resultado de %d - %d es: %d", num1, num2, Restar(num1, num2));
        printf("\n\tD) El resultado de %d * %d es: %d", num1, num2, Multiplicar(num1, num2));
    //Si el segundo operando es el numero 0, se informara que no se puede realizar la division entre 0, de lo contrario se
    //realizara la division sin problemas.
        if(num2==0)
        {
            printf("\n\tC) No es posible dividir por cero");
        }
        else
        {
            printf("\n\tC) El resultado de %d / %d es: %.2f", num1, num2, Dividir(num1, num2));
        }

    //Si el operando es negativo, se informara que no se podra realizar un factorial de numero negativo.
        if(num1<0)
        {
            printf("\n\tE) No es posible calcular factorial de %d (numero negativo)", num1);
        }
        else
        {
            printf("\n\tE) El factorial de %d es: %llu ", num1, Factorial(num1));
        }

        if(num2<0)
        {
            printf("\n\t   No es posible calcular factorial de %d (numero negativo)", num2);
        }
        else
        {
            printf("\n\t   El factorial de %d es: %llu \n\n", num2, Factorial(num2));
        }
    }
    printf("\n\n5- Salir");
    printf("\n\nIngrese una opcion: ");
    scanf("%d", &opcion);//Solicitara la opcion al usuario y esta opcion se retornara al switch de Main.
    return opcion;
}
