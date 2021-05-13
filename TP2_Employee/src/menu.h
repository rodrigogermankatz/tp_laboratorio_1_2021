
#include "arrayEmployees.h"

#ifndef MENU_H_
#define MENU_H_


/** \brief funcion que muestra opciones del menu y retorna la opcion seleccionada
 *
 * \return int opcion seleccionada
 *
 */
int menu();

/** \brief funcion que imprime opciones del sub menu y retorna la opcion seleccionada
 *
 * \return int opcion seleccionada
 *
 */
int reportsSubMenu();

/** \brief funcion que imprime opciones para modificar un empleado y retorna la opcion seleccionada
 *
 * \return int opcion seleccionada
 *
 */
int employeeConditionsMenu();

/** \brief funcion que muestra opciones del sub menu
 *
 * \return void
 *
 */
void showReportSubMenu();

/** \brief funcion del menu para agregar un empleado
 *
 * \param list Employee* lista para agregar el empleado
 * \param len int tamaño de la lista de empleados
 * \param employeeID int* puntero para autogenerar un id de empleado
 * \return int 1 ok/ 0 error
 *
 */
int addEmployeeMenu(Employee* list, int len, int* employeeID);

/** \brief funcion del menu para modificar un empleado
 *
 * \param list Employee* lista para agregar el empleado
 * \param len int tamaño de la lista de empleados
 * \return int 1 ok/ 0 error
 */
int modifyEmployeeMenu(Employee* list, int len);

/** \brief funcion del menu para borrar un empleado
 *
 * \param list Employee* lista para agregar el empleado
 * \param len int tamaño de la lista de empleados
 * \return int 1 ok/ 0 error
 */
int removeEmployeeMenu(Employee* list, int len);

/** \brief funcion para imprimir todos los empleados de la lista
 *
 * \param list Employee* lista de empleados
 * \param len int tamaño de la lista
 * \return int
 *
 */
int printEmployeesMenu(Employee* list, int len);

/** \brief funcion para imprimir un mensaje
 *
 * \param char mensaje[] mensaje a imprimir
 * \return void
 */
void printMenuMessage(char message[]);

/** \brief funcion para intentar salir de la app
 *
 * \return int s salir / otros no sale
 *
 */
int exitMenu();

/** \brief funcion para mostrar un mensaje de error
 *
 * \param errorMessage[] char mensaje de error
 * \return void
 *
 */
void printMenuError(char errorMessage[]);

#endif
