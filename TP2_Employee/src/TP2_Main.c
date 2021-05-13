/*
 ============================================================================
 Name        : TP2_Employee.c
 Author      : Rodrigo Katz
 Version     : 1.0.0
 Description : Trabajo Práctico Número 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "arrayEmployees.h"

#define QTY_EMPLOYEES 5

int main(void) {
	setbuf(stdout, NULL);

	int exit = 0;
	int flagCreacion = 0;
	int initEmployeeId = 10000;
	int initializedEmployees;
	Employee arrayEmployees[QTY_EMPLOYEES];
	initializedEmployees = initEmployees(arrayEmployees, QTY_EMPLOYEES);
	//printEmployees(arrayEmployees, QTY_EMPLOYEES);

	do {
		switch (menu()) {
			case 1:
				if(initializedEmployees){
					printMenuMessage("Creando empleado ...");
					if(addEmployeeMenu(arrayEmployees, QTY_EMPLOYEES, &initEmployeeId)){
						printMenuMessage("Empleado creado");
						flagCreacion = 1;
					} else {
						printMenuMessage("El empleado no se pudo crear");
					}
				} else {
					printMenuMessage("Por el momento no se pueden crear empleados");
					flagCreacion = 0;
				}
				break;
			case 2:
				if(flagCreacion){
					printMenuMessage("Modificando empleado ...");
					if(modifyEmployeeMenu(arrayEmployees, QTY_EMPLOYEES)){
						printMenuMessage("Empleado modificado");
					} else {
						printMenuMessage("El empleado no se pudo modificar");
					}
				} else {
					printMenuMessage("No se puede hacer una modificacion sin agregar algun empleado");
				}
				break;
			case 3:
				if(flagCreacion){
					printMenuMessage("Eliminando empleado ...");
					if(removeEmployeeMenu(arrayEmployees, QTY_EMPLOYEES)){
						printMenuMessage("Empleado borrado");
					} else {
						printMenuMessage("El empleado no se pudo borrar");
					}
				} else {
					printMenuMessage("No se puede borrar sin agregar algun empleado");
				}
				break;
			case 4:
				if(flagCreacion){
					printMenuMessage("Creando reportes ...");
					showReportSubMenu(arrayEmployees, QTY_EMPLOYEES);
				} else {
					printMenuMessage("No se puede informar sin agregar algun empleado");
				}
				break;
			case 0:
				printMenuMessage("Saliendo de la aplicacion ...");
				exit = exitMenu();
				break;
			default:
				printMenuMessage("La opción ingresada no se encuentra en el menú. Intente nuevamente!");
				fflush(stdin);
				break;
		}
	}
	while (exit == 0);

	return EXIT_SUCCESS;
}
