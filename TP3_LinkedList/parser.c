#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee) {
	char bufferId[4096];
	char bufferNombre[4096];
	char bufferHorasTrabajadas[4096];
	char bufferSueldo[4096];
	int bufferInt;
	int maxId=-1;
	int toReturn=-1;
	Employee *pEmpleado;

	if(pFile != NULL) {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId, bufferNombre, bufferHorasTrabajadas,  bufferSueldo);
		while(!feof(pFile)) {
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,  bufferNombre, bufferHorasTrabajadas, bufferSueldo);
			pEmpleado = employee_newParametros(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);

			if(pEmpleado!=NULL && ll_add(pArrayListEmployee,pEmpleado)==0) {
				employee_getId(pEmpleado,&bufferInt);
				if (bufferInt>maxId) {
					maxId=bufferInt;
				}
				toReturn=0;
			}
		}
		employee_setIdInicial(maxId+1);
	}
	return toReturn;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee) {
	int toReturn=-1;
	Employee *pEmpleado;
	int bufferInt;
	int maxId=-1;
	if(pFile!=NULL) {
		while(!feof(pFile)) {
			pEmpleado=employee_new();
			if(pEmpleado!=NULL && fread(pEmpleado,sizeof(Employee),1,pFile) && ll_add(pArrayListEmployee,pEmpleado)==0) {
				employee_getId(pEmpleado,&bufferInt);
				if (bufferInt>maxId) {
					maxId=bufferInt;
				}
				toReturn=0;
			} else {
				employee_delete(pEmpleado);
			}
		}
		employee_setIdInicial(maxId+1);
	}
	return toReturn;
}
