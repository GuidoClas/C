#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED


int controller_loadFromText(char* path , LinkedList* pArrayList);
//int controller_ListArticulos(LinkedList* pArrayList, Rubro* rubros);
int controller_sortArticulos(LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);
int mainMenu();

#endif // CONTROLLER_H_INCLUDED


