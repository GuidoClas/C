#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "validarInt.h"

//La funcion getInt se encargara de solicitar un entero al usuario, validarlo y retornalo al Main.
int getInt()
{
    char numero[5];//Se pedira el numero como char/string y no como int, ya que de ese modo podremos recorrer el string.
    int N;//N es la variable que, dependiendo del retorno de la funcion validarNum, mantendra activo o no el bucle while.
    int numeroValidado;//numeroValidado es la variable en la que vamos a guardar el numero ya validado y como entero, para luego retornalo al Main.

    do
    {
        printf("Ingresa el operando: ");
        scanf("%s", numero);
        N = validarNum(numero);

    }
    while(N==0);
    //Si validarNum retorna un 0, significa que no pudo obtener el numero correctamente y se volvera a ejecutar el bucle.
    //Si validarNum retorna un 1, significa que pudo y se finaliza el bucle.


    numeroValidado = atoi(numero);//Transformaremos el numero de char a int con la funcion atoi.

    return numeroValidado;
}

//validarNum recibe como parametro el numero tomado y guardado como string.
int validarNum(char numero[])
{
    int ret;//La variable ret hace referencia al retorno. Si se logro validar el numero, retornara un 1, de lo contrario retornara un 0.

    //El bucle For recorrera desde el primer caracter de numero hasta el ultimo. La funcion isdigit negada detectara si es o no un digito
    //y tambien verificara si en el primer indice de la cadena corresponde a un signo que indica que el numero es negativo.

    for(int i=0; i<strlen(numero); i++)
    {
        if((!(isdigit(numero[i]))) && numero[0]!='-')
        {
            printf("\nPor favor ingresa solo numeros\n");
            ret = 0;
        }
        else
        {
            ret = 1;
        }
    }
    return ret;
}
