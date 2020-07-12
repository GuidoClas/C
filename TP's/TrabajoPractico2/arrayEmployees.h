#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

//Estructura de empleados con sus respectivas variables.
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int idSector;
    int isEmpty;

} eEmployee;

//Estructura de Sectores con su id y descripcion respectivas, anidadas con la variable idSector de eEmployee.
typedef struct
{
    int id;
    char descripcion[20];

} eSector;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief Inicializa a todos los empleados, colocando su campo isEmpty == 1.
 *
 * \param Recibe el vector de empleados, en este caso vacio.
 * \param Recibe el tamanio del vector de empleados.
 * \return Retornara un 0 en caso de exito, y un -1 en caso contrario.
 *
 */

int initEmployees(eEmployee* vec, int tam);

/** \brief La funcion agrega un empleado, antes verificando disponibilidad y coloca su campo isEmpty == 0.
 *
 * \param Recibe el id almacenado en main, para poder asignarselo al empleado que se cargara.
 * \param Recibe el vector de empleados para poder gestionarlo.
 * \param Recibe el tamanio del vector de empleados.
 * \param Recibe el vector de sectores para poder asignarlos correctamente y anidarlo con el vector de empleados.
 * \param Recibe el tamanio del vector de sectores.
 * \return Retornara un 0 en caso de exito, y un -1 en caso contrario.
 *
 */

int addEmployee(int Idx, eEmployee* vec, int tam, eSector* sectors, int tamSec);

/** \brief La funcion remueve un empleado de la lista, es baja logica ya que coloca su campo isEmpty == 1 nuevamente.
 *
 * \param Recibe el vector de empleados para poder gestionarlo.
 * \param Recibe el tamanio del vector de empleados.
 * \param Recibe el vector de sectores para poder anidarlo y mostrar al empleado a eliminar.
 * \param Recibe el tamanio del vector de sectores.
 * \return Retornara un 0 en caso de exito y un -1 en caso contrario.
 *
 */

int removeEmployee(eEmployee* vec, int tam, eSector* sectors, int tamSec);

/** \brief La funcion modifica un empleado, verificando antes que exista y luego dando a elegir el campo a modificar.
 *
 * \param Recibe el vector de empleados para poder gestionarlo.
 * \param Recibe el tamanio del vector de empleados.
 * \param Recibe el vector de sectores para poder dar a elegir a cual modificar.
 * \param Recibe el tamanio del vector de sectores.
 * \return Retornara un 0 en caso de exito y un -1 en caso contrario.
 *
 */

int modifyEmployee(eEmployee* vec, int tam, eSector* sectors, int tamSec);

/** \brief La funcion solicitara el orden de ordenamiento, y mostrara, los empleados ordenados, y los informes solicitados.
 *
 * \param Recibe el vector de empleados para poder gestionar los informes.
 * \param Recibe el tamanio del vector de empleados.
 * \param Recibe el vector de sectores para poder gestionar los informes y ordenamientos por sector.
 * \param Recibe el tamanio del vector de sectores.
 * \return Retornara un 0 en caso de exito y un -1 en caso contrario.
 *
 */

int informEmployees(eEmployee* vec, int tam, eSector* sectors, int tamSec);

/** \brief La funcion efectuara los ordenamientos y calculos, para que la funcion de informes los muestre.
 *
 * \param Recibe el vector de empleados para poder efectuar los ordenamientos.
 * \param Recibe el tamanio del vector de empleados para poder recorrerlo.
 * \param Recibe el order elegido por el usuario (A para Ascendiente, D para Descendiente).
 * \param Recibe el vector de sectores para poder efectuar los ordenamientos.
 * \param Recibe el tamanio del vector de sectores para poder recorrerlo.
 * \param Recibe un puntero para poder guardar alli el total de los sueldos a pagar.
 * \param Recibe un puntero para poder guardar alli el promedio de todos los salarios.
 * \param Recibe un puntero para poder guardar alli la cantidad de empleados que superan el promedio de salarios.
 *
 */

void sortEmployees(eEmployee* vec, int tam, char order, eSector* sectors, int tamSec, float* totalSalarios, float* promedioSalarios, int* contadorEmpleados);

/** \brief Recorrera el vector de empleados y llamara a la funcion printEmployee cada vez que tenga que mostrar un empleado, mostrando todos los empleados disponibles.
 *
 * \param Recibe el vector de empleados para poder mostrar cada uno de aquellos que cuenten con el campo isEmpty==0.
 * \param Recibe el tamanio del vector de empleados para recorrerlo.
 * \param Recibe el vector de sectores para poder mostrar tambien a que sector pertenece cada empleado (Su descripcion).
 * \param Recibe el tamanio del vector de sectores para recorrerlo.
 *
 */

void printEmployees(eEmployee* vec, int tam, eSector* sectors, int tamSec);

/** \brief Recibira un solo empleado del vector de empleados, y mostrara cada uno de sus campos.
 *
 * \param Recibe el empleado en el indice que en que se llamo a la funcion, cada vez que se la llama.
 * \param Recibe el vector de sectores para poder mostrar su descripcion.
 * \param Recibe el tamanio del vector de sectores para recorrerlo.
 *
 */

void printEmployee(eEmployee x, eSector* sectors, int tamSec);

/** \brief Despliega el menu inicial y solicita una opcion al usuario.
 *
 * \return Devuelve la opcion elegida por el usuario al Main.
 *
 */

int mostrarMenu();

/** \brief Despliega el menu para que el usuario seleccione que campo desea modificar del empleado.
 *
 * \return Devuelve la opcion elegida por el usuario, correspondiente al campo a modificar.
 *
 */

int menuModificar();

/** \brief La funcion busca en el vector de empleados una posicion libre, es decir con el campo isEmpty == 1.
 *
 * \param Recibe el vector de empleados para buscar en el una posicion libre.
 * \param Recibe el tamanio del vector de empleados para recorrerlo.
 * \return Devuelve el indice en donde esta la posicion libre en caso de exito. En caso contrario devuelve un -1.
 *
 */

int buscarLibre(eEmployee* vec, int tam);

/** \brief Recorre el vector de empleados buscando si existe algun empleado ya cargado en el, es decir con campo isEmpty == 0.
 *
 * \param Recibe el vector de empleados para buscar en el alguna posicion ocupada.
 * \param Recibe el tamanio del vector de empleados para recorrerlo.
 * \return Devuelve un 0 en caso de exito, en caso contrario devuelve un -1.
 *
 */

int buscarOcupado(eEmployee* vec, int tam);

/** \brief La funcion busca un empleado mediante un ID en el vector de empleados que este activo, es decir con campo isEmpty == 0.
 *
 * \param Recibe el ID del empleado que quiere encontrar en el vector de empleados.
 * \param Recibe el vector de empleados para poder buscar el ID.
 * \param Recibe el tamanio del vector de empleados para recorrerlo.
 * \return Devuelve el indice en donde esta el empleado en caso de exito. En caso contrario devuelve un -1.
 *
 */

int buscarEmpleado(int id, eEmployee* vec, int tam);

/** \brief Despliega un menu, mostrandole a los usuario los sectores disponibles para que elija.
 *
 * \param Recibe un puntero para poder guardar alli la opcion elegida por el usuario, correspondiente al sector.
 * \return Devuelve un 0 en caso de exito, en caso contrario devuelve un -1.
 *
 */

int funcionSector(int* opcionSector);

/** \brief La funcion verifica que haya un sector con un ID igual al que recibe como parametro, de ser asi carga en el puntero "descripcion" su la descripcion de ese sector.
 *
 * \param Recibe el puntero donde guardara la descripcion del sector que corresponda.
 * \param Recibe el ID del sector que se quiere mostrar su descripcion.
 * \param Recibe el vector de sectores para poder buscar su descripcion.
 * \param Recibe el tamanio del vector de sectores para recorrerlo.
 * \return Devuelve un 0 en caso de exito, de lo contrario devuelve un -1.
 *
 */

int cargarDescripcionSector(char* descripcion, int id, eSector* sectors, int tamSec);
