#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validaciones.h"
#include "menu.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
	int toReturn=-1;
	FILE* pFile;
	pFile = fopen(path,"r");
	if (pFile != NULL && parser_EmployeeFromText(pFile , pArrayListEmployee) == 0){
		toReturn=0;
	}
	fclose(pFile);
	return toReturn;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
	int toReturn=-1;
	FILE* pFile;
	pFile = fopen(path,"rb");
	if (pFile!=NULL && parser_EmployeeFromBinary(pFile , pArrayListEmployee)==0){
		toReturn=0;
	}
	fclose(pFile);
	return toReturn;
}

int controller_addEmployee(LinkedList* pArrayListEmployee){
	int toReturn=-1;
	int bufferId;
	char bufferNombre[4096];
	int bufferHorasTrabajadas;
	float bufferSueldo;
	Employee* pEmployee;

	if (pArrayListEmployee!=NULL){
		utn_getString(bufferNombre, "\n\t\tIngrese el nombre del empleado: ", "El nombre debe tener entre 2 y 50 caracteres.\n\t\tIntente nuevamente: ", 2, 50);
		utn_getNumber(&bufferHorasTrabajadas, "\n\t\tIngrese las horas trabajadas: ", "\n\t\tERROR:\n\t\tLas horas trabajadas deben estar entre 4 y 9", 4, 9);
		utn_getFloat(&bufferSueldo, "\n\t\tIngrese el salario: ", "\n\t\tERROR:\n\t\tEl salario ingresado debe estar comprendido entre $50.000,- y $5.000.000,-", 50000, 5000000);
		bufferId=employee_generarId();
		pEmployee=employee_new();
		if (pEmployee!=NULL &&
			employee_setId(pEmployee,bufferId)==0 &&
			employee_setNombre(pEmployee,bufferNombre)==0 &&
			employee_setHorasTrabajadas(pEmployee,bufferHorasTrabajadas)==0 &&
			employee_setSueldo(pEmployee,bufferSueldo)==0 &&
			ll_add(pArrayListEmployee,pEmployee)==0){
				toReturn=0;
			} else {
				printf("\n\t\tNo se pudo agregar el empleado.");
			}
	}
	return toReturn;
}

int controller_editEmployee(LinkedList* pArrayListEmployee){
	int toReturn=-1;
	int id;
	int bufferIdNode;
	char bufferNombre[128];
	float bufferSueldo;
	int bufferHorasTrab;
	int opcion;
	Employee *bufferEmployee;
	if(pArrayListEmployee!=NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		utn_getNumber(&id,"\n\t\tIngrese ID a modificar: ", "\n\t\tERROR:\n\t\tEl ID es incorrecto", 1, 10000);
		bufferIdNode=controller_searchIdEmployee(pArrayListEmployee,id);
		if(bufferIdNode==-1){
			printf("\n\t\tNo existe este ID");
		} else {
			do {       //copiar printf de alta
				bufferEmployee=ll_get(pArrayListEmployee,bufferIdNode);
				employee_printNode(bufferEmployee);

				switch(menuModificacion()) {
					case 1:
						utn_getString(bufferNombre, "\n\t\tIngrese el nombre del empleado: ", "El nombre debe tener entre 2 y 50 caracteres.\n\t\tIntente nuevamente: ", 2, 50);
						employee_setNombre(bufferEmployee,bufferNombre);
						break;
					case 2:
						utn_getNumber(&bufferHorasTrab, "\n\t\tIngrese las horas trabajadas: ", "\n\t\tERROR:\n\t\tLas horas trabajadas deben estar entre 4 y 9", 4, 9);
						employee_setHorasTrabajadas(bufferEmployee,bufferHorasTrab);
						break;
					case 3:
						utn_getFloat(&bufferSueldo, "\n\t\tIngrese el salario: ", "\n\t\tERROR:\n\t\tEl salario ingresado debe estar comprendido entre $50.000,- y $5.000.000,-", 50000, 5000000);
						employee_setSueldo(bufferEmployee,bufferSueldo);
						break;
					case 4:
						opcion = 4;
						break;
					default:
						printf("\n\t\tError:\n\t\tElija una de las opciones numericas del menu");
				}
			} while(opcion!=4);
			toReturn=0;
		}
	}
	return toReturn;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee){
	int toReturn=-1;
	int id;
	int bufferIdNode;
	if(pArrayListEmployee!=NULL){
		controller_ListEmployee(pArrayListEmployee);
		utn_getNumber(&id,"\n\t\tIngrese ID a eliminar: ", "\n\t\tERROR:\n\t\tEl ID es incorrecto", 1, 10000);
		bufferIdNode=controller_searchIdEmployee(pArrayListEmployee,id);
		if(bufferIdNode==-1) {
			printf("\n\t\tNo existe este ID");
		} else {
			ll_remove(pArrayListEmployee,bufferIdNode);
			toReturn=0;
		}
	}
	return toReturn;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee){
	int toReturn=-1;
	int i;
	int lenLista;
	if (pArrayListEmployee!=NULL && ll_len(pArrayListEmployee)!=0) {
		lenLista=ll_len(pArrayListEmployee);
		for (i=0;lenLista>i;i++) {
		   employee_printNode(ll_get(pArrayListEmployee,i));
		}
	} else {
		printf("\n\t\tLa lista esta vacia");
	}
	return toReturn;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee){
	int toReturn=-1;
	if (pArrayListEmployee!=NULL) {
		ll_sort(pArrayListEmployee,employee_comparaNombre,1);
		toReturn=0;
	}
	return toReturn;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
	int toReturn=-1;
	int i;
	int size;
	int bufferId;
	char bufferNombre[4096];
	int bufferHorasTrabajadas;
	int bufferSueldo;
	Employee* pEmployee;
	FILE* fp = fopen(path,"w+");
	if (fp!=NULL) {
		size=ll_len(pArrayListEmployee);
		fprintf(fp,"id,nombre,horasTrabajadas,sueldo\n");
		for(i=0;i<size;i++) {
			pEmployee=ll_get(pArrayListEmployee,i);
			employee_getId(pEmployee,&bufferId);
			employee_getNombre(pEmployee,bufferNombre);
			employee_getHorasTrabajadas(pEmployee,&bufferHorasTrabajadas);
			employee_getSueldo(pEmployee,&bufferSueldo);

			fprintf(fp,"%d,%s,%d,%d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

		}
		toReturn=0;
		fclose(fp);
	}
	return toReturn;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
	int toReturn=-1;
	int i;
	int size;
	Employee* pEmployee;
	FILE* fp = fopen(path,"w+b");
	if (fp!=NULL) {
		size=ll_len(pArrayListEmployee);
		for(i=0;i<size;i++) {
			pEmployee=ll_get(pArrayListEmployee,i);
			fwrite(pEmployee,sizeof(Employee),1,fp);
		}
		toReturn=0;
		fclose(fp);
	}
	return toReturn;
}

int controller_searchIdEmployee(LinkedList* pArrayListEmployee, int id) {
    int toReturn=-1;
    int lenLista;
    int i;
    int bufferId;
    if (pArrayListEmployee != NULL && id > 0 && ll_len(pArrayListEmployee) != 0) {
        lenLista=ll_len(pArrayListEmployee);
        for (i=0;i<lenLista;i++) {
            employee_getId(ll_get(pArrayListEmployee,i),&bufferId);
            if (id==bufferId) {
                toReturn=i;
                break;
            }
        }
    } else {
        printf("\n\t\tLa lista esta vacia");
    }
    return toReturn;
}
