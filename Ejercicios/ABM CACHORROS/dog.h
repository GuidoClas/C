#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int dias;
    char raza[20];
    char reservado[20];
    char genero [2];
}Dog;

Dog* dog_new();
Dog* dog_newParametros(char* idStr,char* nombreStr,char* diasStr, char* razaStr, char* reservadoStr,char* generoStr);
void dog_delete();

int dog_setId(Dog* this,int id);
int dog_getId(Dog* this,int* id);

int dog_setNombre(Dog* this,char* nombre);
int dog_getNombre(Dog* this,char* nombre);

int dog_setDias(Dog* this,int dias);
int dog_getDias(Dog* this,int* dias);

int dog_setRaza(Dog* this,char* raza);
int dog_getRaza(Dog* this,char* raza);

int dog_setReserva(Dog* this,char* reservado);
int dog_getReserva(Dog* this,char* reservado);

int dog_setGenero(Dog* this,char* genero);
int dog_getGenero(Dog* this,char* genero);

void listDogs(LinkedList* pArrayList);
void listDog(Dog* dog);

#endif // employee_H_INCLUDED
