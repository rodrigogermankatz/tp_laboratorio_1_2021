#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculadora.h"

int menu(){
	int opcion;
	printf("\n\n\tCalculadora\n");
	printf("\n\t1. Ingresar 1er operando");
	printf("\n\t2. Ingresar 2do operando");
	printf("\n\t3. Calcular todas las operaciones");
	printf("\n\t4. Informar resultados");
	printf("\n\t5. Salir\n");
	printf("\n\tOpción: ");
	scanf("%d", &opcion);
	return opcion;
}

int salirCalculadora(){
    char opcion;
    int retornar = 0;
    printf("\n\t   Esta seguro de que desea salir? s/n ");
    fflush(stdin);
    scanf("%c", &opcion);
    if(opcion == 's' || opcion == 'S') retornar = 1;
    return retornar;
}

int pedirOperando(int* operando){
    int resultado = 0;
    if(operando != NULL){
        printf("\n\tIngrese un numero: ");
        resultado = scanf("%d", operando);
    }
    return resultado;
}

void imprimirError(char mensajeDeError[]){
	printf("\n\t-------------------------------------------------------------");
	printf("\n\t%s", mensajeDeError);
	printf("\n\t-------------------------------------------------------------\n\n");
}

void imprimirOperandos(int primerOperando, int segundoOperando){
	printf("\n\t-----------------");
	printf("\n\t(A=%d) & (B=%d)", primerOperando, segundoOperando);
	printf("\n\t-----------------");
}

int hacerTodosLosCalculos(int primerOperando, int segundoOperando, int *suma, int *resta, int *multiplicacion, float *division, int *primerFactorial, int *segundoFactorial){
    int resultado = 0;
    if(suma != NULL && resta != NULL && multiplicacion != NULL && division != NULL && primerFactorial != NULL && segundoFactorial != NULL){
        *suma = sumarOperandos(primerOperando, segundoOperando);
        *resta = restarOperandos(primerOperando, segundoOperando);
        *multiplicacion = multiplicarOperandos(primerOperando, segundoOperando);
        *division = dividirOperandos(primerOperando, segundoOperando);
        *primerFactorial = factoriarOperando(primerOperando);
        *segundoFactorial = factoriarOperando(segundoOperando);
        resultado = 1;
    }
    return resultado;
}

int sumarOperandos(int operando1, int operando2){
    return operando1 + operando2;
}
int restarOperandos(int operando1, int operando2){
    return operando1 - operando2;
}
int multiplicarOperandos(int operando1, int operando2){
    return operando1 * operando2;
}
float dividirOperandos(int operando1, int operando2){
    float resultado = 0;
    if(operando2 !=0 ){
        resultado = (float) operando1 / (float) operando2;
    }
    return resultado;
}

int factoriarOperando(int operando){
    int factorial = 1;
	for (int i = 0; i < operando; i++) {
		factorial = factorial * (i + 1);
	}
	return factorial;
}

void informarResultados(int primerOperando, int segundoOperando, int *suma, int *resta, int *multiplicacion, float *division, int *primerFactorial, int *segundoFactorial){
    printf("\n\t-------------------------------------------------------------------");
    printf("\n\t                         RESULTADOS");
    printf("\n\t-------------------------------------------------------------------");
    printf("\n\tEl resultado de %d+%d es: %d", primerOperando, segundoOperando, *suma);
    printf("\n\tEl resultado de %d-%d es: %d", primerOperando, segundoOperando, *resta);
    segundoOperando != 0 ? printf("\n\tEl resultado de %d/%d es: %.2f", primerOperando, segundoOperando, *division) : printf("\n\tEl resultado de %d/%d es: ERROR!", primerOperando, segundoOperando);
    printf("\n\tEl resultado de %d*%d es: %d", primerOperando, segundoOperando, *multiplicacion);
    primerOperando >= 0 && primerOperando <= 12 ? printf("\n\tEl factorial de %d es: %d ", primerOperando, *primerFactorial) : printf("\n\tNo se puede mostrar el factorial del primer operando ");
    segundoOperando >= 0 && segundoOperando <= 12 ? printf("y el factorial de %d es: %d", segundoOperando, *segundoFactorial) : printf("y no se puede mostrar el factorial del segundo operando");
    printf("\n\t-------------------------------------------------------------------");
}
