#ifndef HEADERS_VALIDACIONES_H_
#define HEADERS_VALIDACIONES_H_

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pFloatResult Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param message Es el mensaje a ser mostrado
 * \param errorMessage Es el mensaje de Error a ser mostrado
 * \param min Es el numero maximo a ser aceptado
 * \param max Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero float y -1 si no
 */
int utn_getFloat(float* pFloatResult, char* message, char* errorMessage, int min, int max);

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pStringResult Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param message Es el mensaje a ser mostrado
 * \param errorMessage Es el mensaje de Error a ser mostrado
 * \param min Es el numero maximo a ser aceptado
 * \param max Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el string y -1 si no
 */
int utn_getString(char *pStringResult, char* message, char* errorMessage, int min, int max);

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResult Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param message Es el mensaje a ser mostrado
 * \param errorMessage Es el mensaje de Error a ser mostrado
 * \param min Es el numero maximo a ser aceptado
 * \param max Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumber(int* pResult, char* message, char* errorMessage, int min, int max);

#endif /* HEADERS_VALIDACIONES_H_ */
