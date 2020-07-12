#ifndef ABMFUNC_H_INCLUDED
#define ABMFUNC_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char localidad[20];
    int telefono;
    int edad;
    char sexo;
    int isEmpty;

} eCliente;

typedef struct
{
    int idDuenio;
    int idTipo;
    char nombre[20];
    char raza[20];
    int edad;
    float peso;
    char sexo;
    int isEmpty;

} eMascota;

typedef struct
{
  int idTipo;
  char descripcion[20];

} eTipo;

#endif

void inicializarClientes(eCliente* clientes, int tam);

void inicializarMascota(eMascota* mascotas , int tam);

void listarCliente(eCliente x);

void listarClientes(eCliente* vec, int tam);

void listarMascotas(eCliente* clientes, eMascota* vec, eTipo* tipo, int tamMas, int tamTip, int tam);

void listarMascota(eCliente* clientes, eMascota vec, eTipo* tipo, int tamMas, int tamTip, int tam);

int cargarNombreDuenio(char* nombre, int id, eCliente* cliente, int tam);

int cargarDescripcionTipo(char* descripcion, int id, eTipo* tipo, int tamTip);

void hardcodearClientes(eCliente* vec, int cant);
