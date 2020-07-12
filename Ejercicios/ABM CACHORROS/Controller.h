#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_ListDogs(LinkedList* pArrayList);
int controller_filterByDays(void* dog);
int controller_filterByGender(void* dog);
int controller_filterByBreed(void* dog);
//LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*));

int mainMenu();

