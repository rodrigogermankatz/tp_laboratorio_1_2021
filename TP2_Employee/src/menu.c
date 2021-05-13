#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "biblioteca.h"


#define MAX_STR_SIZE 50
#define MIN_STR_SIZE 2

int menu() {
	int option = 0;
	printf("\n\t-----------------------------");
	printf("\n\t  ADMINISTRADOR DE EMPLEADOS");
	printf("\n\t-----------------------------");
	printf("\n\t1. ALTA EMPLEADO");
	printf("\n\t2. MODIFICAR EMPLEADO");
	printf("\n\t3. BAJA EMPLEADO");
	printf("\n\t4. INFORMES");
	printf("\n\t0. SALIR");
	printf("\n\t-----------------------------");
	printf("\n\tOpción: ");
	fflush(stdin);
	scanf("%i", &option);
	return option;
}

int reportsSubMenu() {
	int option = 0;
	printf("\n\t-----------------------------");
	printf("\n\t      MENU DE INFORMES");
	printf("\n\t-----------------------------");
	printf("\n\t1. LISTAR EMPLEADOS ORDENADOS");
	printf("\n\t2. SUMA TOTAL DE SALARIOS;\n\t   PROMEDIO DE SALARIOS;\n\t   SUPERAN SALARIO PROMEDIO");
	printf("\n\t0. SALIR");
	printf("\n\t-----------------------------");
	printf("\n\tOpción: ");
	fflush(stdin);
	scanf("%i", &option);
	return option;
}

int employeeConditionsMenu(){
	int option;
	printf("\n\t-----------------------------");
	printf("\n\tMOD. CONDICIONES DEL EMPLEADO");
	printf("\n\t-----------------------------");
	printf("\n\t1. MODIFICAR NOMBRE");
	printf("\n\t2. MODIFICAR APELLIDO");
	printf("\n\t3. MODIFICAR SALARIO");
	printf("\n\t4. MODIFICAR SECTOR");
	printf("\n\t5. GUARDAR");
	printf("\n\t0. CANCELAR Y VOLVER");
	printf("\n\t-----------------------------");
	printf("\n\tOption: ");
	scanf("%d", &option);
	return option;
}

void showReportSubMenu(Employee* list, int len, int* employeeId){
	setbuf(stdout, NULL);
		int exit = 0;
		do {
			switch (reportsSubMenu()) {
				case 1:
					if(sortEmployees(list, len, 1)){
						printMenuMessage("Lista de empleados ordenada satisfactoriamente");
						printEmployeesMenu(list, len);
					} else {
						printMenuMessage("La lista de empleados no pudo ser ordenada");
					}
					break;
				case 2:
					if(getReports(list, len)){
						printMenuMessage("Reportes generados");
					} else {
						printMenuMessage("Los reportes no se pudieron generar");
					}
					break;
				case 0:
					exit = exitMenu();
					break;
				default:
					printMenuMessage("La opción ingresada no se encuentra en el menú. Intente nuevamente!");
					fflush(stdin);
					break;
			}
		}
		while (exit == 0);
}

int addEmployeeMenu(Employee* list, int len, int* employeeId){
	int sector = 0;
	float salary = 0;
	char name[MAX_STR_SIZE];
	char lastName[MAX_STR_SIZE];
	int toReturn = 0;
	int flagSpace = 0;

	flagSpace = checkSpace(list, len);

	if( list != NULL && len > 0 && flagSpace){
		int isNameOk = utn_getString(name, "Nombre\n\tEntre 2 y 50 caracteres: ", "El nombre debe tener entre 2 y 50 caracteres.\n\tIntente nuevamente: ", MIN_STR_SIZE, MAX_STR_SIZE, 3);
		int isLastNameOk = utn_getString(lastName, "Apellido\n\tEntre 2 y 50 caracteres: ", "El apellido es demasiado largo.\n\tIntente nuevamente: ", MIN_STR_SIZE, MAX_STR_SIZE, 3);
		int isSectorOk = utn_getInt(&sector, "Sector\n\tEntre 1 y 5: ", "El sector ingresado debe estar comprendido entre 100 y 104\n\tIntente nuevamente: ", 100, 104, 3);
		int isSalaryOk = utn_getFloat(&salary, "Salario\n\tEntre $50.000,- y $5.00.000,-: ", "El salario ingresado debe estar comprendido entre $50.000,- y $5.00.000,-\n\tIntente nuevamente: ", 50000, 5000000, 3);

		if(isNameOk == 1 && isLastNameOk == 1 && isSectorOk == 1 && isSalaryOk == 1){
			toReturn = addEmployee(list, len, (*employeeId), name, lastName, salary, sector);
			(*employeeId)++;

		} else {
			printMenuMessage("\n\tAlguno de los campos ingresados no es correcto");
		}
	}
	return toReturn;
}

int modifyEmployeeMenu(Employee* list, int len){
	int toReturn = 0;
	int flagPrintEmployee = 0;
	int flagEmployeeList = 0;
	int indiceEmployee = 0;
	int employeeId;
	if( list != NULL && len > 0){
		flagEmployeeList = printEmployees(list, len);
		flagPrintEmployee = utn_getInt(&employeeId, "ID empleado a modificar: ", "El ID del empleado debe ir entre 10000 y 10004\n\tIntente nuevamente: ", 10000, 10004, 3);
		indiceEmployee = findEmployeeById(list, len, employeeId);
		if(flagEmployeeList && flagPrintEmployee && (indiceEmployee > -1)){
			toReturn = modifyEmployee(list, len, indiceEmployee, employeeId);
		} else {
			printf("\n\tNo hay un empleado con el ID %d", employeeId);
		}
	}
	return toReturn;
}

int removeEmployeeMenu(Employee* list, int len){
	int toReturn = 0;
	int flagPrintEmployee = 0;
	int flagEmployeeList = 0;
	int flagEmployeeExists = 0;
	int employeeId;
	if( list != NULL && len > 0){
		flagEmployeeList = printEmployees(list, len);
		flagPrintEmployee = utn_getInt(&employeeId, "ID empleado a remover: ", "El ID del empleado debe ir entre 10000 y 10004\n\tIntente nuevamente: ", 10000, 10004, 3);
		flagEmployeeExists = findEmployeeById(list, len, employeeId);
		if(flagEmployeeList && flagPrintEmployee && (flagEmployeeExists > -1)){
			toReturn = removeEmployee(list, len, employeeId);
		}
	}
	return toReturn;
}


int printEmployeesMenu(Employee* list, int len){
	int toReturn = 0;
	if( list != NULL && len > 0){
		toReturn  = printEmployees(list, len);
	}
	return toReturn;
}

int exitMenu(){
	char option;
	int toReturn = 0;
	printf("\n\t\tEsta seguro de que desea salir? s/n ");
	fflush(stdin);
	scanf("%c", &option);
	if(tolower(option) == 's') toReturn = 1;
	return toReturn;
}

void printMenuMessage(char message[]){
	printf("\n\t-------------------------------------------------------------------");
	printf("\n\t%s", message);
	printf("\n\t-------------------------------------------------------------------\n\n");
}
