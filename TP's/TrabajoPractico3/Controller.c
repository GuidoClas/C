#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* file;
    char answer;

    if(path != NULL && pArrayListEmployee!= NULL) // Verifico que los punteros recibidos no sean NULL
    {
        if((!ll_isEmpty(pArrayListEmployee) && !utn_getCharacter(&answer, "Desea sobrescribir los datos?", "Error, s/n", 's', 'n', 3) && answer == 's') || ll_isEmpty(pArrayListEmployee))
        {
            //Si la lista no esta vacia, preguntaremos si se quieren sobreescribir los datos, y si la respuesta si, se sobreescribiran.
            //Si la lista esta vacia, simplemente se cargaran los empleados desde el archivo
            ll_clear(pArrayListEmployee);
            file = fopen(path, "r");

            if(file != NULL) // Verifico que el archivo abierto no sea NULL
            {
                if(parser_EmployeeFromText(file, pArrayListEmployee) == 0)
                {
                    retorno = 0;
                    fclose(file);
                }
            }
        }
    }


    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* file;
    char answer;

    if(path != NULL && pArrayListEmployee != NULL) // Verifico que los punteros recibidos no sean NULL
    {
        //Si la lista no esta vacia, preguntaremos si se quieren sobreescribir los datos, y si la respuesta si, se sobreescribiran.
        //Si la lista esta vacia, simplemente se cargaran los empleados desde el archivo
        if((!ll_isEmpty(pArrayListEmployee) && !utn_getCharacter(&answer, "Desea sobrescribir los datos?", "Error, s/n", 's', 'n', 3) && answer == 's') || ll_isEmpty(pArrayListEmployee))
        {
            file = fopen(path, "rb");
            if(file != NULL) // Verifico que el archivo abierto no sea NULL
            {
                if(parser_EmployeeFromBinary(file, pArrayListEmployee) == 0)
                {
                    retorno = 0;
                    fclose(file);
                }
            }
        }
    }


    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* employee = employee_new(); //Solicito espacio en memoria dinamica para un nuevo empleado
    Employee* auxEmployee;
    char auxName[51];
    int auxHours;
    int auxSalary;
    int nextId;
    int llSize;

    if(pArrayListEmployee != NULL && employee != NULL) // Verifico que los punteros recibidos y el empleado generado no sean NULL
    {
        if(ll_isEmpty(pArrayListEmployee)) //En caso de estar vacia la lista, el primer empleado cargado tendria el id 1001
        {
            nextId = 1001;
        }
        else // En caso de que ya haya empleados, vamos a obtener el tamanio de la lista, obtendremos el empleado en el ultimo indice, obtendremos el id y le sumaremos 1
        {
            llSize = ll_len(pArrayListEmployee);
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, (llSize - 1));
            employee_getId(auxEmployee, &nextId);
            nextId = nextId+1;
        }
        printf("\nAlta de empleado\n");
        // Solicito los datos y los valido, los asigno
        if(!utn_getString(auxName, "Ingresa el nombre: ", "Error, solo letras: ", 3) &&
            !utn_getNumeroEntero(&auxHours, "Ingresa la cantidad de horas trabajadas: ", "Error, solo numeros enteros: ", 0, 500000, 3) &&
           !utn_getNumeroEntero(&auxSalary, "Ingresa el sueldo: ", "Error, solo numeros enteros: ", 0, 50000000, 3))
        {
            //Le asigno los atributos al empleado
            formalizarString(auxName);
            employee_setId(employee, nextId);
            employee_setNombre(employee, auxName);
            employee_setHorasTrabajadas(employee, auxHours);
            employee_setSueldo(employee, auxSalary);
            ll_add(pArrayListEmployee, (void*) employee);
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int index;
    int id;
    Employee* employee;

    if(pArrayListEmployee != NULL) // Verifico que el puntero recibido LL no sea NULL
    {
        if(!utn_getNumeroEntero(&id, "Ingresa el id del empleado: ", "Error, solo numeros enteros: ", 1, 1000000, 3))
        {
            index = findEmployee(id, pArrayListEmployee); // Solicito el id a modificar y lo guardo en la variable index
        }

        if(index == -1) // Si findEmployee me devolvio un -1 es que el empleado no existe
        {
            printf("No existe empleado con ese id\n");
        }
        else
        {
             // Obtengo el empleado con ll_get y se lo paso como parametro al switch que permite modificar los datos
            employee = (Employee*) ll_get(pArrayListEmployee, index);
            if(!switchEditMenu(employee))
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int index;
    int id;
    char answer;

    if(pArrayListEmployee != NULL) // Verifico que el puntero recibido LL no sea NULL
    {

        if(!utn_getNumeroEntero(&id, "Ingresa el id del empleado: ", "Error, solo numeros enteros: ", 1, 1000000, 3))
        {
            index = findEmployee(id, pArrayListEmployee); // Solicito el id a eliminar y lo guardo en la variable index
        }

        if(index == -1) // Si findEmployee me devolvio un -1 es que el empleado no existe
        {
            printf("No existe empleado con ese id\n");
        }
        else
        {
            if(!utn_getCharacter(&answer, "Confirma la baja de este empleado?(s/n)", "Error, solo (s/n)", 's', 'n', 3) && answer == 's') //Confirmo la baja y lo remuevo del LL
            {
                ll_remove(pArrayListEmployee, index);
                retorno = 0;
            }
        }
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;


    if(pArrayListEmployee != NULL) // Verifico que el puntero recibo LL no sea NULL
    {
        listEmployees(pArrayListEmployee);
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
    int order;

    if(pArrayListEmployee != NULL) // Verifico que el puntero recibido LL no sea NULL
    {
        if(!utn_getNumeroEntero(&order, "Ingrese el orden\n1-Ascendente\n0-Descendente\n", "Error, solo 1 o 0", 0, 1, 3))
        {
            // Pido el criterio de ordenamiento y se lo paso como parametro al switch que permite elegir la forma de ordenar.
            if(!switchSortMenu(pArrayListEmployee, order))
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* file;
    int llSize;
    Employee* employee;
    int auxId;
    char auxName[51];
    int auxHours;
    int auxSalary;

    if(path != NULL && pArrayListEmployee != NULL) //Verifico que los punteros recibidos no sean NULL
    {
        file = fopen(path, "w");
        llSize = ll_len(pArrayListEmployee);
        if(file != NULL) //Verifico que el archivo abierto no haya devuelto NULL
        {
            for(int i=0; i<llSize; i++)
            {
            //Cada vez que recorra un empleado de la lista, lo obtendra la funcion ll_get, se verificara que no sea NULL
            // Se hara un get de cada dato en auxiliares y se escribira en el archivo.
                employee = (Employee*) ll_get(pArrayListEmployee, i);
                if(employee != NULL)
                {
                    employee_getId(employee, &auxId);
                    employee_getNombre(employee, auxName);
                    employee_getHorasTrabajadas(employee, &auxHours);
                    employee_getSueldo(employee, &auxSalary);

                    fprintf(file,"%d,%s,%d,%d\n", auxId, auxName, auxHours, auxSalary);
                }
            }
            retorno = 0;
            fclose(file);
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* file;
    int llSize;
    Employee* employee;

    if(path != NULL && pArrayListEmployee != NULL) //Verifico que los punteros recibidos no sean NULL
    {
        file = fopen(path, "wb");
        llSize = ll_len(pArrayListEmployee);
        if(file != NULL) //Verifico que el archivo abierto no haya devuelto NULL
        {
            for(int i=0; i<llSize; i++)
            {
            //Cada vez que recorra un empleado de la lista, lo obtendra la funcion ll_get, se verificara que no sea NULL y se escribira en el archivo
               employee = (Employee*) ll_get(pArrayListEmployee, i);
               if(employee != NULL)
               {
                   fwrite(employee, sizeof(Employee), 1, file);
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
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
    printf("10. Salir\n");
    utn_getNumeroEntero(&option, "Ingresa la opcion: ", "Error, opcion del 1 al 10 solamente: ", 1, 10, 3);

    return option;
}



