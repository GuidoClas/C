#include <stdio.h>
#include <stdlib.h>

int Sumar(int A, int B)
{
    int suma;

    suma = A + B;

    return suma;
}

int Restar(int A, int B)
{
    int resta;

    resta = A - B;

    return resta;
}

int Multiplicar(int A, int B)
{
    int multiplicacion;

    multiplicacion = A*B;

    return multiplicacion;
}

float Dividir(int A, int B)
{
    float division;


    division = (float) A/B;


    return division;
}

//En el caso del factorial, si el operando es un 1 o un 0, utilizaremos por consenso el valor 1.
long long int Factorial(int num)
{
    unsigned long long factorial = 1;
    int i = 1;

    if(num==0 || num==1)
    {
        factorial=1;
    }
    else
    {
        for (i=1; i<=num; i++)
        {
            factorial = factorial * i;
        }

    }
    return factorial;

}
