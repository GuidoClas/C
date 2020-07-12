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

int informar(eAuto* autos, eTrabajo* trabajos, eMarca* marcas, eColor* colores, eServicio* servicios, int tamAu, int tamTra, int tamMa, int tamCo, int tamSer);

int mostrarMenuInformes();

void informarAutoPorColor(eAuto* autos, eColor* colores, eMarca* marcas, int tamAu, int tamCo, int tamMa);

void informarAutoPorMarca(eAuto* autos, eColor* colores, eMarca* marcas, int tamAu, int tamCo, int tamMa);

void informarAutoMasViejo(eAuto* autos, eMarca* marcas, eColor* colores, int tamAu, int tamMa, int tamCo);

void listarAutosPorMarca(eAuto* autos, eMarca* marcas, eColor* colores, int tamAu, int tamMa, int tamCo);

void contarAutosPorColorYMarca(eAuto* autos, int tamAu);

void informarMarcaMasElegida(eAuto* autos, eMarca* marcas, int tamAu, int tamMa);

void informarTrabajosPorAuto(eAuto* autos, eTrabajo* trabajos, eServicio* servicios, int tamAu, int tamTra, int tamSer);

void informarImporteTotalAuto(eAuto* autos, eTrabajo* trabajos, eServicio* servicios, int tamAu, int tamTra, int tamSer);

void informarServiciosPorAuto(eAuto* autos, eMarca* marcas, eColor* colores, eServicio* servicios, eTrabajo* trabajos, int tamAu, int tamMa, int tamCo, int tamSer, int tamTra);

