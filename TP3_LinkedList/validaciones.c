#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "validaciones.h"

int utn_getString(char *pStringResult, char* message, char* errorMessage, int min, int max){
	char string[max];
	int toReturn = -1;
	if(pStringResult != NULL && message!= NULL && errorMessage!= NULL && min < max ){
		printf("%s", message);
		__fpurge(stdin);
		fgets(string, max, stdin);
		while(strlen(string) <= min || strlen(string) >= max) {
			printf("%s", errorMessage);
			__fpurge(stdin);
			fgets(string, max, stdin);
		}
		strcpy(pStringResult, string);
		toReturn = 0;
	} else {
		printf("utn_getString ERROR");
	}
	//printf("El valor ingresado fue string %s pStringResult %s", string, pStringResult);
	return toReturn;
}

int utn_getNumber(int* pResult, char* message, char* errorMessage, int min, int max){
	int number;
	int toReturn = -1;
	if(pResult != NULL && message!= NULL && errorMessage!= NULL && min < max ){
		printf("%s",message);
		__fpurge(stdin);
		scanf("%i", &number);
		while(number < min || number > max) {
			printf("%s", errorMessage);
			printf("%s", message);
			__fpurge(stdin);
			scanf("%i", &number);
		}
		*pResult = number;
		toReturn = number;
	} else{
		printf("utn_getNumber ERROR");
	}
	return toReturn;
}

int utn_getFloat(float* pFloatResult, char* message, char* errorMessage, int min, int max){
	float floatNumber;
	int toReturn = -1;
	if(pFloatResult != NULL && message!= NULL && errorMessage!= NULL && min < max ){
		printf("%s",message);
		__fpurge(stdin);
		scanf("%f", &floatNumber);
		while(floatNumber < min || floatNumber > max) {
			printf("%s", errorMessage);
			printf("%s", message);
			__fpurge(stdin);
			scanf("%f", &floatNumber);
		}
		*pFloatResult = floatNumber;
		toReturn = 0;
	} else {
		printf("utn_getFloat ERROR");
	}
	return toReturn;
}
