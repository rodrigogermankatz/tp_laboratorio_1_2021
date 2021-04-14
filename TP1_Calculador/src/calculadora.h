
#ifndef CALCULADORA_H_
#define CALCULADORA_H_

/** \brief funcion que muestra opciones del menu y retorna la opcion seleccionada
 *
 * \return int opcion seleccionada
 *
 */
int menu();

/** \brief funcion para confirmar la salida del programa que retorna la opcion elegida
 *
 * \return int opcion a retornar
 *
 */
int salirCalculadora();

/** \brief guarda el operador en una direccion de memoria y retorna si fue posible o no
 *
 * \return int 1 ok / 0 error
 *
 */
int pedirOperando(int* operando);

/** \brief funcion que hace todos los calculos
  *
  * \param primerOperando int
  * \param segundoOperando int
  * \param suma int* puntero al resultado de la suma
  * \param resta int* puntero al resultado de la resta
  * \param multiplicacion int* puntero al resultado de la multiplicacion
  * \param division float* puntero al resultado de la division
  * \param *primerFactorial long longint puntero al resultado del primer factorial
  * \param *segundoFactorial long longint puntero al resultado del segundo factorial
  * \return int 1 ok / 0 error
  *
  */
 int hacerTodosLosCalculos(int primerOperando, int segundoOperando, int *suma, int *resta, int *multiplicacion, float *division, int *primerFactorial, int *segundoFactorial);

 /** \brief funcion que recibe dos operandos, los suma y luego retorna el resultado
  *
  * \param operando1 int primer operando
  * \param operando2 int segundo operando
  * \return int resultado
  *
  */
 int sumarOperandos(int operando1, int operando2);

 /** \brief funcion que recibe dos operandos, los resta y luego retorna el resultado
  *
  * \param operando1 int primer operando
  * \param operando2 int segundo operando
  * \return int resultado
  *
  */
 int restarOperandos(int operando1, int operando2);

 /** \brief funcion que recibe dos operandos, los multiplica y luego retorna el resultado
  *
  * \param operando1 int primer operando
  * \param operando2 int segundo operando
  * \return int resultado
  *
  */
 int multiplicarOperandos(int operando1, int operando2);

 /** \brief funcion que recibe dos operandos, los multiplica y luego retorna el resultado
  *
  * \param operando1 int primer operando
  * \param operando2 int segundo operando
  * \return float resultado
  *
  */
 float dividirOperandos(int operando1, int operando2);

 /** \brief funcion que calcula el factorial de un numero
  *
  * \param operando int numero a factoriar
  * \return int
  *
  */
 int factoriarOperando(int operando);

 /** \brief funcion que informa los resultados de los calculos realizados
  *
  * \param primerOperando int primer operando ingresado
  * \param segundoOperando int segundo operando ingresado
  * \param suma int* puntero al resultado de la suma
  * \param resta int* puntero al resultado de la resta
  * \param multiplicacion int* puntero al resultado de la multiplicacion
  * \param division float* puntero al resultado de la division
  * \param *primerFactorial int puntero al resultado del primer factorial
  * \param *segundoFactorial int puntero al resultado del segundo factorial
  * \return void no retorna, solo imprime
  *
  */
 void informarResultados(int primerOperando, int segundoOperando, int *suma, int *resta, int *multiplicacion, float *division, int *primerFactorial, int *segundoFactorial);


#endif /* CALCULADORA_H_ */
