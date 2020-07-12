#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"


Employee* employee_new()
{
    Employee* employee = (Employee*) malloc(sizeof(Employee)); // Solicitamos espacio en memoria dinamica para un empleado

    if(employee != NULL) // Verificamos que ese empleado generado no sea NULL y ponemos los campos vacios para evitar basura
    {
        employee->id = 0;
        strcpy(employee->nombre, " ");
        employee->horasTrabajadas = 0;
        employee->sueldo = 0;
    }

    return employee;
}



Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* employee = employee_new(); // Solicitamos espacio en memoria dinamica para un empleado

    if(employee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL) // Verificamos que ese empleado generado no sea NULL y le asignamos los atributos recibidos como parametros
    {
        employee_setId(employee, atoi(idStr));
        employee_setNombre(employee, nombreStr);
        employee_setHorasTrabajadas(employee, atoi(horasTrabajadasStr));
        employee_setSueldo(employee, atoi(sueldoStr));
    }

    return employee;
}

void listEmployees(LinkedList* pArrayListEmployee)
{
    int llSize;
    Employee* employee;

    if(pArrayListEmployee != NULL) // Verifico que el puntero LL recibido no sea NULL
    {
        printf("\n%10s%10s%10s%10s\n", "Id", "Nombre", "Horas", "Sueldo"); // Imprimo de manera ordenada las columnas
        llSize = ll_len(pArrayListEmployee);
        for(int i=0; i<llSize; i++)
        {
            //Obtengo en cada iteracion un empleado, y se lo envio a la funcion listEmployee destinada a mostrarlo
            employee = (Employee*) ll_get(pArrayListEmployee, i);
            listEmployee(employee);
        }
    }
}

void listEmployee(Employee* employee)
{
   if(employee != NULL) // Verifico que el empleado recibido no sea NULL
   {
       printf("%10d%10s%10d%10d\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);
   }

}

int findEmployee(int id, LinkedList* pArrayListEmployee)
{
    int index = -1; // Setteo en -1 el retorno en caso de no encontrar un id igual
    Employee* auxEmployee;
    int llSize;

    if(pArrayListEmployee != NULL && id > 0) // Verifico que el puntero LL recibido no sea NULL y que el id sea mayor a 0
    {
        llSize = ll_len(pArrayListEmployee);
        for(int i=0; i<llSize; i++)
        {
            // Recorro la lista y obtengo un empleado en cada iteracion, para comparar igualdad con el id recibido como parametro
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            if(auxEmployee->id == id)
            {
                index = i; // De ser iguales, devuelve el indice en que se encuentra
            }
        }
    }

    return index;
}

int editMenu()
{
    int option;

    printf("\n---------------------- Menu de modificaciones ----------------------\n\n");
    printf("1. Modificar nombre\n");
    printf("2. Modificar Horas trabajadas\n");
    printf("3. Modificar Sueldo\n");
    printf("4. Salir del menu de modificaciones\n");
    utn_getNumeroEntero(&option, "Ingresa la opcion: ", "Error, opcion del 1 al 10 solamente: ", 1, 4, 3);

    return option;
}


int switchEditMenu(Employee* employee)
{
    int option;
    char auxName[51];
    int auxHours;
    int auxSalary;
    int retorno = -1;

    if(employee != NULL) // Verifico que el puntero a empleado recibido no sea NULL
    {
        do{
            option = editMenu();
            switch(option)
            {
                case 1:
                    if(!utn_getString(auxName, "Ingresa el nuevo nombre: ", "Error, solo letras: ", 3))
                    {
                        formalizarString(auxName);
                        employee_getNombre(employee, auxName);
                        retorno = 0;
                    }
                    break;
                case 2:
                    if(!utn_getNumeroEntero(&auxHours, "Ingresa las nuevas horas trabajadas: ", "Error, solo numeros enteros: ", 0, 100000, 3))
                    {
                       employee_getHorasTrabajadas(employee, &auxHours);
                       retorno = 0;
                    }
                    break;
                case 3:
                    if(!utn_getNumeroEntero(&auxSalary, "Ingresa el nuevo sueldo: ", "Error, solo numeros enteros: ", 0, 10000000, 3))
                    {
                       employee_getSueldo(employee, &auxSalary);
                       retorno = 0;
                    }
                    break;
                case 4:
                    printf("Salida exitosa\n");
                    retorno = 0;
                    break;
            }
        }while(option != 4);
    }

    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno = -1;

    if(this != NULL && id > 0) // Verifico que el empleado recibido no sea NULL y que el id sea valido
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL) // Verifico que el empleado recibido no sea NULL y que el id sea valido
    {
       *id = this->id;
       retorno = 0;
    }

    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL) // Verifico que el empleado recibido no sea NULL y que el nombre sea valido
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL) // Verifico que el empleado recibido no sea NULL y que el nombre sea valido
    {
       strcpy(nombre, this->nombre);
       retorno = 0;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas >= 0) // Verifico que el empleado recibido no sea NULL y que las horas sean validas
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas != NULL)  // Verifico que el empleado recibido no sea NULL y que las horas sean validas
    {
       *horasTrabajadas = this->horasTrabajadas;
       retorno = 0;
    }

    return retorno;

}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo > 0)  // Verifico que el empleado recibido no sea NULL y que el sueldo sea valido
    {
        this->sueldo = sueldo;
        retorno = 0;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo != NULL) // Verifico que el empleado recibido no sea NULL y que el sueldo sea valido
    {
       *sueldo = this->sueldo;
       retorno = 0;
    }

    return retorno;
}


int sortIds(void* employee1, void* employee2)
{
    int idEmployee1;
    int idEmployee2;
    int retorno;

    if(!employee_getId(employee1, &idEmployee1) && !employee_getId(employee2, &idEmployee2)) //Obtengo el dato a comparar de cada empleado y le doy un criterio
    {
        if(idEmployee1 > idEmployee2)
        {
            retorno = 1;
        }
        else if(idEmployee1 < idEmployee2)
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

int sortNames(void* employee1,void* employee2)
{
    char nameEmployee1[51];
    char nameEmployee2[51];
    int retorno;

    if(!employee_getNombre(employee1, nameEmployee1) && !employee_getNombre(employee2, nameEmployee2)) //Obtengo el dato a comparar de cada empleado y le doy un criterio
    {
        if(strcmp(nameEmployee1, nameEmployee2) == 1)
        {
            retorno = 1;
        }
        else if(strcmp(nameEmployee1, nameEmployee2) == -1)
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

int sortHours(void* employee1, void* employee2)
{
    int hoursEmployee1;
    int hoursEmployee2;
    int retorno;

    if(!employee_getHorasTrabajadas(employee1, &hoursEmployee1) && !employee_getHorasTrabajadas(employee2, &hoursEmployee2)) //Obtengo el dato a comparar de cada empleado y le doy un criterio
    {
        if(hoursEmployee1 > hoursEmployee2)
        {
            retorno = 1;
        }
        else if(hoursEmployee1 < hoursEmployee2)
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

int sortSalary(void* employee1, void* employee2)
{
    int salaryEmployee1;
    int salaryEmployee2;
    int retorno;

    if(!employee_getSueldo(employee1, &salaryEmployee1) && !employee_getSueldo(employee2, &salaryEmployee2)) //Obtengo el dato a comparar de cada empleado y le doy un criterio
    {
        if(salaryEmployee1 > salaryEmployee2)
        {
            retorno = 1;
        }
        else if(salaryEmployee1 < salaryEmployee2)
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

int sortMenu()
{
    int option;

    printf("\n---------------------- Menu de Opciones de Ordenamiento ----------------------\n\n");
    printf("1. Ordenar por ID\n");
    printf("2. Ordenar por nombre\n");
    printf("3. Ordenar por horas trabajadas\n");
    printf("4. Ordenar por sueldo\n");
    printf("5. Salir del menu\n");
    utn_getNumeroEntero(&option, "Ingresa la opcion: ", "Error, solo numeros enteros", 1, 5, 3);

    return option;
}

int switchSortMenu(LinkedList* pArrayListEmployee, int order)
{
    int option;
    int retorno = -1;

    if(pArrayListEmployee != NULL) // Verifico que el puntero a empleado recibido no sea NULL
    {
        do{
            option = sortMenu();
            switch(option)
            {
                case 1:
                    if(!ll_sort(pArrayListEmployee, sortIds, order))
                    {
                        printf("Empleados ordenados por ID con exito");
                        retorno = 0;
                    }
                    break;
                case 2:
                    if(!ll_sort(pArrayListEmployee, sortNames, order))
                    {
                        printf("Empleados ordenados por nombre con exito");
                        retorno = 0;
                    }
                    break;
                case 3:
                    if(!ll_sort(pArrayListEmployee, sortHours, order))
                    {
                        printf("Empleados ordenados por horas trabajadas con exito");
                        retorno = 0;
                    }
                    break;
                case 4:
                    if(!ll_sort(pArrayListEmployee, sortSalary, order))
                    {
                        printf("Empleados ordenados por salario con exito");
                        retorno = 0;
                    }
                    break;
                case 5:
                    printf("Salida exitosa\n");
                    retorno = 0;
                    break;
            }
        }while(option != 5);
    }

    return retorno;
}
