int controller_loadFromText(char* path , LinkedList* pArrayListClient);
int controller_loadFromBinary(char* path , LinkedList* pArrayListClient);
int controller_addClient(LinkedList* pArrayListClient);
int controller_editClient(LinkedList* pArrayListClient);
int controller_removeClient(LinkedList* pArrayListClient);
int controller_ListClients(LinkedList* pArrayListClient);
int controller_sortClients(LinkedList* pArrayListClient);
int controller_saveAsText(char* path , LinkedList* pArrayListClient);
int controller_saveAsBinary(char* path , LinkedList* pArrayListClient);
int controller_reinsert(LinkedList* pArrayListClient);
int controller_newFilteredList(LinkedList* pArrayListClient, LinkedList* pArrayListClient2);
int mainMenu();
int getId(int* id);
int updateId(int id);




