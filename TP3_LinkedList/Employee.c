/*
 * Employee.c
 *
 *  Created on: Nov 3, 2020
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "validaciones.h"
#include "string.h"

static int idPer=0;

Employee* employee_new(){
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){
    Employee* pEmployee=employee_new();
    if (pEmployee!=NULL){
        employee_setIdStr(pEmployee,idStr);
        employee_setNombre(pEmployee,nombreStr);
        employee_setHorasTrabajadasStr(pEmployee,horasTrabajadasStr);
        employee_setSueldoStr(pEmployee,sueldoStr);
    }
    return pEmployee;
}

int employee_generarId(){
    return idPer++;
}

void employee_setIdInicial(int val) {
   idPer= val;
}

void employee_delete(Employee* this){
    free(this);
}

int employee_setId(Employee* this,int id){
    int retorno=-1;
    if (this!=NULL && id>0){
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id){
    int retorno=-1;
    if (this!=NULL){
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setIdStr(Employee* this,char* id){
    int retorno=-1;
    int bufferInt;
    if (this!=NULL){
        bufferInt= atoi(id);
        if (bufferInt>0){
            employee_setId(this,bufferInt);
        }
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
    int retorno = -1;
    if(this!=NULL){
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre){
    int retorno = -1;
    if(this != NULL){
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int retorno=-1;
    if (this!=NULL && horasTrabajadas>0){
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int retorno=-1;
    if (this!=NULL){
        *horasTrabajadas = this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadasStr){
    int retorno=-1;
    int bufferHora;
    if (this!=NULL){
        bufferHora= atoi(horasTrabajadasStr);
        if (bufferHora>0){
            employee_setHorasTrabajadas(this,bufferHora);
        }
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){
    int retorno=-1;
    if (this!=NULL && sueldo>0){
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo){
    int retorno=-1;
    if (this!=NULL) {
        *sueldo = this->sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldoStr(Employee* this,char* sueldo) {
    int retorno=-1;
    int buffersueldo;
    if (this!=NULL) {
        buffersueldo=atoi(sueldo);
        if (buffersueldo>0) {
            employee_setSueldo(this,buffersueldo);
        }
    }
    return retorno;
}

int employee_printNode(Employee *this){
    int retorno=-1;
    char bufferNombre[4096];
    int bufferSueldo;
    int bufferHorasTrab;
    int bufferId;
    if (this!=NULL) {
        employee_getId(this,&bufferId);
        printf("\n\t\tID: %d",bufferId);
        employee_getNombre(this,bufferNombre);
        printf("\n\t\tNombre: %s",bufferNombre);
        employee_getHorasTrabajadas(this,&bufferHorasTrab);
        printf("\n\t\tHoras trabajadas: %d",bufferHorasTrab);
        employee_getSueldo(this,&bufferSueldo);
        printf("\n\t\tSueldo: %d",bufferSueldo);
        retorno=0;
    }
    return retorno;
}

int employee_comparaNombre(void *this,void *that) {
    int retorno;
    int comparacion = strcmp(((Employee*)this)->nombre,((Employee*)that)->nombre);
    if (comparacion<0) {
        retorno=1;
    } else if (comparacion>0) {
        retorno=-1;
    } else {
        retorno=0;
    }
    return retorno;
}
