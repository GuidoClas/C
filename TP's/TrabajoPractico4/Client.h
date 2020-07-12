#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int anioInscripcion;
    char genero[20];
}Client;

Client* client_new();
Client* client_newParametros(char* idStr,char* nombreStr,char* anioStr, char* generoStr);
void client_delete();

int client_setId(Client* this,int id);
int client_getId(Client* this,int* id);

int client_setNombre(Client* this,char* nombre);
int client_getNombre(Client* this,char* nombre);

int client_setAnio(Client* this,int anio);
int client_getAnio(Client* this,int* anio);

int client_setGenero(Client* this,char* genero);
int client_getGenero(Client* this,char* genero);

void listClients(LinkedList* pArrayListClient);
void listClient(Client* client);

int editMenu();
int switchEditMenu(Client* client);

int sortIds(void* client1, void* client2);
int sortNames(void* client1,void* client2);
int sortYears(void* client1, void* client2);
int sortGender(void* client1, void* client2);

int switchSortMenu(LinkedList* pArrayListClient, int order);
int sortMenu();

int findClient(int id, LinkedList* pArrayListClient);

#endif // employee_H_INCLUDED
