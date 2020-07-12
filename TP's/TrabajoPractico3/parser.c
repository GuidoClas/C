#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int retorno = -1;
    char buffer[4][101];
    int quantity;
    Employee* employee;

    if(pFile != NULL && pArrayListEmployee != NULL) // Verifico antes que el archivo recibido no sea NULL y que la LL no sea NULL
    {
        while(!feof(pFile)) // Logramos que itere hasta que llegue al final del archivo
        {
            quantity = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            // Validamos que haya podido leer los 4 atributos de los empleados
            if(quantity == 4)
            {
                employee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                // Si logro obtener todos los datos, se los asignaremos mediante la funcion en forma de string
                if(employee != NULL) // Verifico que la funcion no haya devuelto un empleado NULL y finalmente lo agrego a la lista
                {
                    ll_add(pArrayListEmployee, employee);
                    retorno = 0;
                }
            }
            else
            {
                break;
            }
        }
    }


    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int quantity;
    Employee* employee;

    if(pFile != NULL && pArrayListEmployee != NULL) // Verifico antes que el archivo recibido no sea NULL y que la LL no sea NULL
    {
        while(!feof(pFile)) // Logramos que itere hasta que llegue al final del archivo
        {
            employee = employee_new();

            if(employee != NULL) // Verifico que la funcion no haya devuelto un empleado NULL
            {
                quantity = fread(employee, sizeof(Employee), 1, pFile);
                 // Validamos que haya podido leer un empleado de manera completa
                if(quantity == 1)
                {
                    // finalmente lo agrego a la lista
                    ll_add(pArrayListEmployee, employee);
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}
