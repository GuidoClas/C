#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getCharacter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int utn_getNumeroEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getEmail(char* pResultado, char* mensaje, char* mensajeError, int reintentos);

int utn_getString(char* pResultado, char* mensaje, char* mensajeError, int reintentos);

int utn_getAlfanumerico(char* pResultado, char* mensaje, char* mensajeError, int reintentos);

int myGets(char* cadena, int longitud);

int getInt(int* pResultado);

int getString(char* pResultado);

int getAlfanumerico(char* pResultado);

int getFloat(float* pResultado);

int getMail(char* pResultado);

int esNumerica(char* cadena, int limite);

int esFlotante(char* cadena, int limite);

int esMail(char* cadena, int limite);

int esString(char* pResultado, int limite);

int esAlfanumerico(char* cadena, int limite);

void formalizarString(char* pString);

#endif // UTN_H_INCLUDED
