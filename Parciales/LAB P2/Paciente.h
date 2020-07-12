#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

typedef struct
{
    int id;
    char pais[128];
    int recuperados;
    int infectados;
    int muertos;
}Paciente;

Paciente* paciente_new();
Paciente* paciente_newParametros(char* idStr,char* paisStr,char* recuperadoStr, char* infectadosStr, char* muertosStr);
void paciente_delete();

int paciente_setId(Paciente* this,int id);
int paciente_getId(Paciente* this,int* id);

int paciente_setPais(Paciente* this,char* pais);
int paciente_getPais(Paciente* this,char* pais);

int paciente_setRecuperados(Paciente* this,int recuperados);
int paciente_getRecuperados(Paciente* this,int* recuperados);

int paciente_setInfectados(Paciente* this,int infectados);
int paciente_getInfectados(Paciente* this,int* infectados);

int paciente_setMuertos(Paciente* this,int muertos);
int paciente_getMuertos(Paciente* this,int* muertos);

void listPacients(LinkedList* pArrayList);
void listPacient(Paciente* paciente);

void* mapearRandom(void* pac);
int sortInfected(void* inf1,void* inf2);

#endif // PACIENTE_H_INCLUDED
