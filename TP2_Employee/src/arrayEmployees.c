#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arrayEmployees.h"
#include "biblioteca.h"
#include "menu.h"

#define MIN_STR_SIZE 2
#define MAX_STR_SIZE 50

int initEmployees(Employee* list, int len){
	int toReturn = 0;
	if(list != NULL && len > 0){
		for(int i = 0; i < len ; i++){
			list[i].isEmpty = 1;
		}
		printf("\n\tLista de empleados inicializada");
		toReturn = 1;
	}
	return toReturn;
}

int checkSpace(Employee* list, int len){
	int toReturn = 0;
	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 1) {
				toReturn = 1;
				break;
			}
		}
	}
	return toReturn;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector){
	int toReturn = 0;
	if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL && salary > 49999 && sector > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 1){
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = 0;
				toReturn = 1;
				break;
			}
		}
		printEmployees(list, len);
	}
	return toReturn;
}

int findEmployeeById(Employee* list, int len,int id){
	int index = -1;
	if(list != NULL && len > 0 && id > 0){
		for(int i = 0; i < len; i++){
			if(list[i].id == id && list[i].isEmpty == 0){
				index = i;
				break;
			}
		}
	}
	return index;
}

int modifyEmployee(Employee* list, int len, int index,  int employeeId){
	int toReturn = 0;
	char response = 'n';
	Employee auxEmployee;

	int flagName = 0;
	int flagLastName = 0;
	int flagSalary = 0;
	int flagSector = 0;

	if(list != NULL && len > 0){
		do {
			switch(employeeConditionsMenu()){
			case 1:
				flagName = utn_getString(auxEmployee.name, "Nombre: ", "El nombre debe tener entre 2-50 caracteres", 2, 50, 3);
				if(flagName) printMenuMessage("Nombre editado");
				break;
			case 2:
				flagLastName = utn_getString(auxEmployee.lastName, "Apellido: ", "El apellido debe tener entre 2-50 caracteres", 2, 50, 3);
				if(flagName) printMenuMessage("Apellido editado");
				break;
			case 3:
				flagSalary = utn_getFloat(&auxEmployee.salary, "Salario: ", "El salario debe ser numerico entre 1500 y 5000000", 1500, 5000000, 3);
				if(flagName) printMenuMessage("Salario editado");
				break;
			case 4:
				flagSector = utn_getInt(&auxEmployee.sector, "Sector: ", "El sector debe estar entre 1000 y 1004", 1000, 1004, 3);
				if(flagName) printMenuMessage("Sector editado");
				break;
			case 5:
				if(list[index].isEmpty == 0 && list[index].id == employeeId){
					if(flagName) strcpy(list[index].name, auxEmployee.name);
					if(flagLastName) strcpy(list[index].lastName, auxEmployee.lastName);
					if(flagSalary) list[index].salary = auxEmployee.salary;
					if(flagSector) list[index].sector = auxEmployee.sector;
					printf("\n\t-------------------------------------------------");
					printf("\n\t     NUEVAS CONDICIONES DEL EMPLEADO %3d", employeeId);
					printf("\n\t-------------------------------------------------");
					printf("\n\tID       Salario         Sector    Nombre");
					printf("\n\t-------------------------------------------------");
					printEmployee(list[index].id, list[index].name, list[index].lastName, list[index].salary, list[index].sector);
					printf("\n\t-------------------------------------------------\n\n");
					toReturn = 1;
				} else {
					printf("\n\tEl empleado con ID %d no pudo ser modificado\n\n", employeeId);
				}
				break;
			case 0:
				response = 'y';
				break;
			default:
				printf("\n\tOpcion invalida. Intente nuevamente\n\n");
				fflush(stdin);
				break;
			}
		}  while (response != 'y');
	}

	return toReturn;

}

int removeEmployee(Employee* list, int len, int id){
	int toReturn = 0;
	if(list != NULL && len > 0 && id > 0){
		for(int i = 0; i < len; i++){
			if(list[i].id == id && list[i].isEmpty == 0){
				list[i].isEmpty = 1;
				toReturn = 1;
				break;
			}
		}
	}
	return toReturn;
}

int sortEmployees(Employee* list, int len, int order){
	int toReturn = 0;
	Employee auxEmployee;
	if(order == 1){ // asc
		for(int i = 0; i < len - 1; i++){
			for(int j = i + 1; j < len; j++){
				if(strcmp(list[i].lastName, list[j].lastName) > 0 || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector)){
					auxEmployee = list[i];
					list[i] = list[j];
					list[j] = auxEmployee;
					toReturn = 1;
				} else {
					toReturn = 1;
				}

			}
		}
	} else { // desc
		for(int i = 0; i < len - 1; i++){
			for(int j = i + 1; j < len; j++){
				if(strcmp(list[i].lastName, list[j].lastName) < 0 || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector)){
					auxEmployee = list[i];
					list[i] = list[j];
					list[j] = auxEmployee;
					toReturn = 1;
				} else {
					toReturn = 1;
				}
			}
		}
	}
	return toReturn;
}

int getReports(Employee* list, int len){
	int toReturn = 0;
	float total = 0;
	float promedio = 0;
	int contadorEmpleados = 0;
	int contadorPromedio = 0;
	int contadorSupera = 0;
	if(list != NULL && len > 0){
		printf("\n\t--------------------------------------------------------------------------------------");
		printf("\n\tCalculando total, promedio de salarios y cuántos empleados superan el salario promedio");
		printf("\n\t--------------------------------------------------------------------------------------");
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0){
				total = total + list[i].salary;
				contadorEmpleados++;
				contadorPromedio++;
			}
		}
		printf("\n\t\t* Total de salarios:\t\t\t\tARG$ %.2f-", total);
		promedio = (float) total / contadorPromedio;
		printf("\n\t\t* Promedio de salarios:\t\t\t\tARG$ %.2f-", promedio);
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0 && list[i].salary > promedio){
				contadorSupera++;
			}
		}
		printf("\n\t\t* Empleados que superan el salario promedio:\t%d/%d", contadorSupera, contadorEmpleados);
		printf("\n\t--------------------------------------------------------------------------------------\n\n");
	}
	return toReturn;
}

int printEmployees(Employee* list, int len){
	int toReturn = 0;
	int count = 0;
	if(list != NULL && len > 0){
		printf("\n\t-----------------------------------------------------------");
		printf("\n\t                LISTADO DE EMPLEADOS");
		printf("\n\t-----------------------------------------------------------");
		printf("\n\tID        Salario      Sector    Nombre y Apellido");
		printf("\n\t-----------------------------------------------------------");
		for(int i = 0; i < len; i++){
			if(
					//list[i].isEmpty == 1 ||
					list[i].isEmpty == 0
			){
				printEmployee(list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
				count++;
			}
		}
		if(count > 0) {
			toReturn = 1;
		} else {
			printf("\n\t        No hay empleados para listar");
		}
		printf("\n\t-----------------------------------------------------------\n\n");
	}
	return toReturn;
}

void printEmployee(int id, char name[], char lastName[], float salary, int sector){
	char fullName[100] = "";

	//concateno apellido, nombre a fullname
	strcat(fullName, lastName);

	for(int i = 0; fullName[i] != '\0'; i++){
		if(fullName[i] == '\n'){
			fullName[i] = ',';
			fullName[i+1] = ' ';
			break;
		}
	}

	strcat(fullName, name);

	//paso todo a minuscula
	strlwr(fullName);

	//la primera letra del apellido queda en mayuscula
	fullName[0] = toupper(fullName[0]);

	//loopeo mientras el caracter sea distinto de \0
	for(int i = 0; fullName[i] != '\0'; i++){
		if(fullName[i] == ' ') {
			fullName[i+1] = toupper(fullName[i+1]);
			break;
		}
	}

	printf("\n\t%5d    %7.2f         %2d    %s", id, salary, sector, fullName);
}


