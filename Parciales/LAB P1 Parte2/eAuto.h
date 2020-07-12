#ifndef EAUTO_H_INCLUDED
#define EAUTO_H_INCLUDED

#endif // EAUTO_H_INCLUDED

void inicializarAutos(eAuto* autos, int tamAu);

int altaAuto(eAuto* autos, int tamAu);

int buscarLibreAuto(eAuto* autos, int tamAu);

int buscarAuto(char* patente, eAuto* autos, int tamAu);

int modificarAuto(eAuto* autos, int tamAu);

int menuModificar();

int bajaAuto(eAuto* autos, int tamAu);

void listarAutos(eAuto* autos, eMarca* marcas, eColor* colores, int tamAu, int tamMa, int tamCo);

void listarAuto(eAuto autos, eMarca* marcas, eColor* colores, int tamAu, int tamMa, int tamCo);

void ordenarAutos(eAuto* autos, eMarca* marcas, int tamAu, int tamMa);

int cargarMarcaAuto(char* descripcion, int idAuto, eMarca* marcas, int tamCo);

int cargarColorAuto(char* descripcion, int idAuto, eColor* colores, int tamCo);
