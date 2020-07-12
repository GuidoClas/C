#ifndef VALIDARINT_H_INCLUDED
#define VALIDARINT_H_INCLUDED



#endif // VALIDARINT_H_INCLUDED
/** \brief Se encarga de pedir un entero como char y validarlo.
 *
 * \return Retorna el numero tomado como char transformado a int.
 *
 */

int getInt();

/** \brief Se encarga de recorrer todos los caracteres ingresados y validarlos.
 *
 * \param Recibe como parametro el numero tomado como char en getInt().
 * \return Retornara a getInt() un 0 si no se pudo validar un numero. Retornara un 1 si se pudo validar el num.
 *
 */

int validarNum(char numero[]);

