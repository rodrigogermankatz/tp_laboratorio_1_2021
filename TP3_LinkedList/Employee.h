#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct {
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

/**
 * brief constructor de Employee
 * param no recibe params
 * return puntero a Employee
 **/
Employee* employee_new();

/**
 * brief
 * param
 * return
 **/
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/**
 * brief
 * param
 * return
 **/
int employee_generarId();

/**
 * brief
 * param
 * return
 **/
void employee_setIdInicial(int val);

/**
 * brief
 * param
 * return
 **/
void employee_delete();

/**
 * brief
 * param
 * return
 **/
int employee_setId(Employee* this,int id);

/**
 * brief
 * param
 * return
 **/
int employee_setIdStr(Employee* this,char* id);

/**
 * brief
 * param
 * return
 **/
int employee_getId(Employee* this,int* id);

/**
 * brief
 * param
 * return
 **/
int employee_setNombre(Employee* this,char* nombre);

/**
 * brief
 * param
 * return
 **/
int employee_getNombre(Employee* this,char* nombre);

/**
 * brief
 * param
 * return
 **/
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * brief
 * param
 * return
 **/
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * brief
 * param
 * return
 **/
int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadasStr);

/**
 * brief
 * param
 * return
 **/
int employee_setSueldo(Employee* this,int sueldo);

/**
 * brief
 * param
 * return
 **/
int employee_getSueldo(Employee* this,int* sueldo);

/**
 * brief
 * param
 * return
 **/
int employee_setSueldoStr(Employee* this,char* sueldo);

/**
 * brief
 * param
 * return
 **/
int employee_printNode(Employee *this);

/**
 * brief
 * param
 * return
 **/
int employee_comparaNombre(void *this,void *that);

#endif // employee_H_INCLUDED


