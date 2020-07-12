#ifndef UTNSECTORES_H_INCLUDED
#define UTNSECTORES_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eSector;

#endif // UTNSECTORES_H_INCLUDED


int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int tam);
void mostrarSectores(eSector sectores[], int tam);
