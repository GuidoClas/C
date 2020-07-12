#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);
int controller_ListPacients(LinkedList* pArrayList);
int controller_filterBySuccess(void* pac);
int controller_filterByFailure(void* pac);
int controller_informMorePunished(LinkedList* pArrayList);
//LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*));

int mainMenu();

