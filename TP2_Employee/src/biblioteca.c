#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "biblioteca.h"

int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
    int retorno = 0; //0 es ERROR
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){

        do {
            printf("\t%s", mensaje);
            scanf("%d", &bufferInt);

            if(bufferInt >= minimo && bufferInt <= maximo){
                *pResultado = bufferInt;
                retorno = 1; //salio todo bien
                break;
            } else {
                printf("\t%s\n", mensajeError);
                reintentos--;
            }
        } while (reintentos > 0);

    }

    return retorno;
}


int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){
    int retorno = 0; //0 es ERROR
    float bufferFloat;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){

        do {
            printf("\t%s", mensaje);
            scanf("%f", &bufferFloat);

            if(bufferFloat >= minimo && bufferFloat <= maximo){
                *pResultado = bufferFloat;
                retorno = 1; //salio todo bien
                break;
            } else {
                printf("\t%s\n", mensajeError);
                reintentos--;
            }
        } while (reintentos > 0);

    }

    return retorno;
}

int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){
    int retorno = 0; //0 es ERROR
    char bufferChar;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){
        do {
            printf("\t%s", mensaje);
            fflush(stdin);
            scanf("%c", &bufferChar);

            if(bufferChar >= minimo && bufferChar <= maximo){
                *pResultado = bufferChar;
                retorno = 1; //salio todo bien
                break;
            } else {
                printf("\t%s\n", mensajeError);
                reintentos--;
            }
        } while (reintentos > 0);

    }

    return retorno;
}

int utn_getString(char *pStringResult, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int retorno = 0; //0 es ERROR
	char string[maximo];

	if(pStringResult != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo){
		do {
			printf("\t%s", mensaje);
			fflush(stdin);
			fgets(string, maximo, stdin);

			if(strlen(string) >= minimo && strlen(string) <= maximo){
				strcpy(pStringResult, string);
				retorno = 1; //salio todo bien
				break;
			} else {
				printf("\t%s\n", mensajeError);
				reintentos--;
			}

		} while (reintentos > 0);

	}
	return retorno;
}

char utn_getNumeroAleatorio(int desde, int hasta, int iniciar){
	if(iniciar)
		srand(time(NULL));
	return desde + (rand() % (hasta + 1 - desde));
}


int getInt(char mensaje[]){
	int aux;
	printf("%s", mensaje);
	scanf("%d", &aux);
	return aux;
}

float getFloat(char mensaje[]){
	float aux;
	printf("%s", mensaje);
	scanf("%f", &aux);
	return aux;
}

char getChar(char mensaje[]){
	char aux;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &aux);
	return aux;
}


int utn_esNumerico(char str[]){
	int i = 0;
	if(str != NULL){
		while(str[i] != '\0'){
			if(str[i] < '0' || str[i] > '9')
				return 0;
			i++;
		}
	}
	return 1;
}

int utn_esTelefono(char str[]){
	int i = 0;
	int aRetornar = 0;
	if(str != NULL){
		while(str[i] != '\0'){
			if((str[i] != ' ') && (str[i] != '-') && (str[i] != '+') && (str[i] < '0' || str[i] > '9'))
				return 0;
			i++;
		}
	}
	return aRetornar;
}

int utn_esAlfanumerico(char str[]){
	int i = 0;
	int aRetornar = 0;
	if(str != NULL){
		while(str[i] != '\0'){
			if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
				return 0;
			i++;
		}
	}
	return aRetornar;
}

int utn_esSoloLetras(char str[]){
	int i = 0;
	int aRetornar = 0;
	if(str != NULL){
		while(str[i] != '\0'){
			if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
				return 0;
			i++;
		}
	}
	return aRetornar;
}
