#include "informes.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"


void informar(eEmpleado vec[], int tam, eSector sectores[], int tamsec)
{
    char opcion;

    system("cls");


    do{
        opcion=menuInformes();

        switch(opcion){
            case 'A':
                listarEmpleadosAnio(vec, tam, sectores, tamsec);
                break;
            case 'B':
                informarEmpleadosVarones(vec, tam, sectores, tamsec);
                break;
            case 'C':
                informarTotalSueldos(vec, tam);
                break;
            case 'D':
                informarEmpleadosSector(vec, tam, sectores, tamsec);
                break;
            case 'E':
                informarEmpleadoXSector(vec, tam, sectores, tamsec);
                break;
            case 'F':
                informarMayorSueldoSector(vec, tam, sectores, tamsec);
                break;
            case 'G':
                informarMayorSueldoXSector(vec, tam, sectores, tamsec);
                break;
            case 'H':
                aumentarSueldosSectorPorcentaje(vec, tam, sectores, tamsec);
                break;
            case 'I':
                sectorQueMasCobra(vec, tam, sectores, tamsec);
                break;

        }
    }while(opcion!='J');
}

char menuInformes()
{
        char opcion;

        printf("******Menu de informes******\n\n");
        printf("A. Listar empleados de un anio.\n");
        printf("B. Listar empleados varones \n");
        printf("C. Total sueldos\n");
        printf("D. Sector de empleados\n");
        printf("E. Sectores de empleados\n");
        printf("F. Mayor sueldo del sector\n");
        printf("G. Mayor sueldo por sector\n");
        printf("H. Aumentar sueldos de sector\n");
        printf("I. Sector mayor sueldo\n");
        printf("J. Ingrese J para salir\n");

        printf("Ingrese la opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

        opcion=toupper(opcion);

        while(opcion<'A' || opcion>'J'){
            printf("\nError. Ingrese una funcion valida: ");
            fflush(stdin);
            scanf("%c", &opcion);

            opcion=toupper(opcion);

        }

        return opcion;
}

void listarEmpleadosAnio(eEmpleado vec[], int tam, eSector sector[], int tamsec){
    int auxAnio;
    int flag=-1;

    system("cls");

    printf("Ingrese el anio: ");
    scanf("%d", &auxAnio);

    for(int i=0; i<tam; i++)
    {
        if(vec[i].ingreso.anio == auxAnio && vec[i].isEmpty==0){

            mostrarEmpleado(vec[i], sector, tamsec);
            flag=0;
        }
    }

    if(flag==-1){
            printf("No hay empleados ingresados en el anio: %d\n", auxAnio);
        }


}

void informarEmpleadosVarones(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int flag=-1;

    system("cls");
    printf("***Empleados varones***\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].sexo == 'm' && vec[i].isEmpty==0){

            mostrarEmpleado(vec[i], sectores, tamSec);
            flag=0;
        }
    }

    if(flag==-1){
            printf("No hay empleados varones que mostrar");
    }

}

void informarTotalSueldos(eEmpleado vec[], int tam)
{
    float acumulador=0;

    system("cls");
    printf("******Total Sueldos******");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0){

            acumulador=acumulador+vec[i].sueldo;
        }
    }

    printf("Total sueldos: %.2f\n\n", acumulador);

}



void informarEmpleadosSector(eEmpleado empleados[],int tam, eSector sectores[], int tamSec)
{
    int idSector;
    int flag=0;
    system("cls");
    printf("****Informar empleados sector****\n");

    mostrarSectores(sectores, tamSec);
    printf("Ingrese id del sector: ");
    scanf("%d", &idSector);


    for(int i=0;i<tam;i++){
        if(empleados[i].idSector==idSector&&empleados[i].isEmpty==0){
            mostrarEmpleado(empleados[i], sectores, tamSec);
            flag=1;
        }
    }

    if(!flag){
        printf("\nNo hay empleados que mostrar\n");
    }

}

void informarEmpleadoXSector(eEmpleado empleados[],int tam, eSector sectores[], int tamSec)
{
    system("cls");
    int flag;
   /* printf("Sistemas: \n");

    for(int i=0;i<tam;i++){
        if(empleados[i].idSector==1&&empleados[i].isEmpty==0){
            mostrarEmpleado(empleados[i], sectores, tamSec);
        }
    }

    printf("Recuros Humanos: \n");

    for(int i=0;i<tam;i++){
        if(empleados[i].idSector==2&&empleados[i].isEmpty==0){
            mostrarEmpleado(empleados[i], sectores, tamSec);
        }
    }

    printf("Ventas: \n");

    for(int i=0;i<tam;i++){
        if(empleados[i].idSector==3&&empleados[i].isEmpty==0){
            mostrarEmpleado(empleados[i], sectores, tamSec);
        }
    }

    printf("Compras: \n");

    for(int i=0;i<tam;i++){
        if(empleados[i].idSector==4&&empleados[i].isEmpty==0){
            mostrarEmpleado(empleados[i], sectores, tamSec);
        }
    }

    printf("Contable: \n");

    for(int i=0;i<tam;i++){
        if(empleados[i].idSector==5&&empleados[i].isEmpty==0){
            mostrarEmpleado(empleados[i], sectores, tamSec);
        }
    }*/

    for(int s=0;s<tamSec;s++)
    {
        flag=0;
        printf("\n%s: \n", sectores[s].descripcion);
        for(int j=0;j<tam;j++)
        {
            if(empleados[j].idSector==sectores[s].id && empleados[j].isEmpty==0){
                mostrarEmpleado(empleados[j], sectores, tamSec);
                flag=1;
            }
        }

        if(!flag){
            printf("No hay empleados en este sector\n\n");
        }

    }
}

void informarMayorSueldoSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec){

    int idSector;
    int flag=0;
    int flagMax=0;
    int idSueldoMax;
    float sueldoMax;
    system("cls");
    printf("****Informar mayor sueldo del sector****\n");

    mostrarSectores(sectores, tamsec);
    printf("Ingrese id del sector: ");
    scanf("%d", &idSector);

    for(int i=0;i<tam;i++){

        if(!flagMax&&empleados[i].isEmpty==0&&idSector==empleados[i].idSector){
            sueldoMax = empleados[i].sueldo;
            idSueldoMax = i;
            flagMax=1;
            flag=1;
        }

        if(flagMax==1&&empleados[i].isEmpty==0&&sueldoMax<empleados[i].sueldo&&idSector==empleados[i].idSector){
            idSueldoMax = i;
            sueldoMax = empleados[i].sueldo;
        }

    }

    if(!flag){
            printf("No hay empleados en este sector\n\n");
        }else{
        printf("\nEl mayor sueldo del sector es el de: \n");
        mostrarEmpleado(empleados[idSueldoMax], sectores, tamsec);
        }

}

void informarMayorSueldoXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec){

    system("cls");
    printf("****Mayor sueldo por sector****");
    int flag;
    int flagMax=0;
    int idSueldoMax;
    float sueldoMax;

    for(int s=0;s<tamsec;s++)
    {
        flagMax=0;
        flag=0;

        printf("\n%s: \n", sectores[s].descripcion);
        for(int j=0;j<tam;j++)
        {
                if(!flagMax&&empleados[j].isEmpty==0&&sectores[s].id==empleados[j].idSector){
                sueldoMax = empleados[j].sueldo;
                idSueldoMax = j;
                flagMax=1;
                flag=1;
                }

                if(flagMax==1&&empleados[j].isEmpty==0&&sueldoMax<empleados[j].sueldo&&sectores[s].id==empleados[j].idSector){
                    idSueldoMax = j;
                    sueldoMax = empleados[j].sueldo;
                }


        }

        if(!flag){
            printf("No hay empleados en este sector\n\n");
        }else{
            mostrarEmpleado(empleados[idSueldoMax], sectores, tamsec);
        }


        flagMax=0;
        flag=0;
    }



}

void aumentarSueldosSectorPorcentaje(eEmpleado empleados[], int tam, eSector sectores[], int tamsec)
{
    int idSector;
    float porcentaje;
    int flag=0;

    system("cls");
    printf("****Aumentar sueldos del sector****\n");

    mostrarSectores(sectores, tamsec);

    utn_getNumeroEntero(&idSector, "Ingrese id del sector: ", "\nError. ", 1,5,10);

    utn_getNumeroFlotante(&porcentaje, "\nIngrese porcentaje a aumentar: ", "\nError. ", 1, 100, 10);

    porcentaje = (porcentaje / 100) + 1;



    for(int i=0; i<tam; i++)
    {
        if(empleados[i].idSector==idSector && empleados[i].isEmpty==0)
        {
            empleados[i].sueldo=empleados[i].sueldo * porcentaje;
            flag=1;
        }

    }



    if(!flag){
            printf("No hay empleados en este sector\n\n");
        }else{
            for(int i=0;i<tam;i++)
            {
                if(empleados[i].idSector==idSector&&empleados[i].isEmpty==0)
                {
                mostrarEmpleado(empleados[i], sectores, tamsec);

                }
            }
        }

}

float obtenerTotalSueldos(int idSector, eEmpleado vec[], int tam)
{
    float totalSueldos=0;

    for(int i=0; i<tam; i++)
    {
            if(vec[i].isEmpty==0&&vec[i].idSector==idSector){

                totalSueldos += vec[i].sueldo;
            }
    }

    return totalSueldos;

}
void sectorQueMasCobra(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    float totalSueldos[tamSec];

    for(int s=0; s<tamSec;s++)
    {
       totalSueldos[s]=obtenerTotalSueldos(sectores[s].id, vec, tam);
    }

    int idMaxSueldo=0;

    for(int s=1;s<tamSec;s++)
    {
        if(totalSueldos[0]<totalSueldos[s])
        {
            idMaxSueldo=s;
        }
    }

    printf("***Sector que mas cobra***\n");

    for(int s=1;s<tamSec;s++)
    {
        if(totalSueldos[idMaxSueldo]==totalSueldos[s])
        {
            printf("%10s: %6.2f\n", sectores[s].descripcion, totalSueldos[s]);
        }
    }
}


void informarTotalSueldosSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec)
{
    int idSector;
    int flag=0;
    char descripcionSector[20];
    float acumuladorSueldos=0;
    system("cls");
    printf("****Informar total sueldos sector****\n");

    mostrarSectores(sectores, tamsec);
    printf("Ingrese id del sector: ");
    scanf("%d", &idSector);


    for(int i=0;i<tam;i++){
        if(empleados[i].idSector==idSector&&empleados[i].isEmpty==0){
            acumuladorSueldos= acumuladorSueldos + empleados[i].sueldo;
            flag=1;
        }
    }

    cargarDescripcionSector(descripcionSector, idSector, sectores, tamsec);

    if(flag==1){
        printf("\nTotal de sueldos del sector %s: %.2f\n", descripcionSector, acumuladorSueldos );
    }else if(!flag){
        printf("\nNo hay empleados en este sector\n");
    }

}

