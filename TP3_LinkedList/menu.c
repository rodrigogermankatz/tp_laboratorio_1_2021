/*
 * menu.c
 *
 *  Created on: Nov 3, 2020
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>

int menuPrimario() {
	int option = 0;
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tMenu");
	printf("\n\t\t01. Cargar Empleados (txt)");
	printf("\n\t\t02. Cargar Empleado (bin)");
	printf("\n\t\t03. Alta Empleado");
	printf("\n\t\t04. Modificar Empleado");
	printf("\n\t\t05. Baja Empleado");
	printf("\n\t\t06. Listar Empleados");
	printf("\n\t\t07. Ordenar Empleados");
	printf("\n\t\t08. Guardar Empleados (txt)");
	printf("\n\t\t09. Guardar Empleados (bin)");
	printf("\n\t\t10. Salir");
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tOpción: ");
	__fpurge(stdin);
	scanf("%i", &option);
	return option;
}

int menuModificacion() {
	int option = 0;
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tMenu de modificaciones");
	printf("\n\t\t1. Modificar nombre");
	printf("\n\t\t2. Modificar horas");
	printf("\n\t\t3. Modificar salario");
	printf("\n\t\t4. Salir");
	printf("\n\t\t------------------------------------------------");
	printf("\n\t\tOpción: ");
	__fpurge(stdin);
	scanf("%i", &option);
	return option;
}
