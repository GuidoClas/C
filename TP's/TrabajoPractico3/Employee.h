#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void listEmployees(LinkedList* pArrayListEmployee);
void listEmployee(Employee* employee);

int editMenu();
int switchEditMenu(Employee* employee);

int sortIds(void* employee1, void* employee2);
int sortNames(void* employee1,void* employee2);
int sortHours(void* employee1, void* employee2);
int sortSalary(void* employee1, void* employee2);

int switchSortMenu(LinkedList* pArrayListEmployee, int order);
int sortMenu();

int findEmployee(int id, LinkedList* pArrayListEmployee);

#endif // employee_H_INCLUDED
