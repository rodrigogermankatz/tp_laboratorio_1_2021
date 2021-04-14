/*
 ============================================================================
 Name        : TP1_Calculador.c
 Author      : Rodrigo Katz
 Version     : 1.0.0
 Description : Trabajo Práctico Número 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculadora.h"

int main(void) {
	setbuf(stdout, NULL);

	int salir = 0;
	int flagPrimerOperando = 0;
	int flagSegundoOperando = 0;
	int flagCalculosHechos = 0;
	int primerOperando = 0;
	int segundoOperando = 0;
	int suma = 0;
	int resta = 0;
	int multiplicacion = 0;
	float division = 0;
	int primerFactorial = 0;
	int segundoFactorial = 0;

	do {
		switch (menu()) {
			case 1:
				flagPrimerOperando = pedirOperando(&primerOperando);
				break;
			case 2:
				flagSegundoOperando = pedirOperando(&segundoOperando);
				break;
			case 3:
				if(flagPrimerOperando && flagSegundoOperando){
					printf("\n\t----------------");
					printf("\n\t(A=%d) & (B=%d)", primerOperando, segundoOperando);
					flagCalculosHechos = hacerTodosLosCalculos(primerOperando, segundoOperando, &suma, &resta, &multiplicacion, &division, &primerFactorial, &segundoFactorial);
					if(flagCalculosHechos) printf("\n\tCalculos hechos!");
					printf("\n\t----------------\n");
				} else {
					printf("\n\t-------------------------------------------------------------");
					printf("\n\tAntes de hacer los calculos tiene que ingresar los operandos!");
					printf("\n\t-------------------------------------------------------------\n\n");
				}
				break;
			case 4:
				if(flagCalculosHechos){
					informarResultados(primerOperando, segundoOperando, &suma, &resta, &multiplicacion, &division, &primerFactorial, &segundoFactorial);
				} else {
					printf("\n\t----------------------------------------------------------------");
					printf("\n\tAntes de informar los calculos tiene que calcular!");
					printf("\n\t----------------------------------------------------------------\n");
				}
				break;
			case 5:
				flagPrimerOperando = 0;
				flagSegundoOperando = 0;
				flagCalculosHechos = 0;
				salir = salirCalculadora();
				break;
			default:
				printf("\n\tLa opcion del menu que ingreso es invalida!\n\tPor favor intente de vuelta.\n");
				fflush(stdin);
				break;
		}
	}
	while (salir == 0);
	return EXIT_SUCCESS;
}

