#ifndef UTNCOMIDA_H_INCLUDED
#define UTNCOMIDA_H_INCLUDED
typedef struct{

    int id;
    char descripcion[20];
    float precio;

}eComida;
#endif // UTNCOMIDA_H_INCLUDED

void listarComidas(eComida comidas[], int tam);
