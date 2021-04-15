/*
 ============================================================================
 Name        : hola.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"


int main(void) {

	setbuf(stdout, NULL);
	char salir = 'n';
	int num1;
	int num2;
	int resultadoSuma;
	float resultadoDivision;
	int resultadoMultiplicacion;
	int resultadoResta;
	int retornoDivision;
	long long int resultadoFactorialA;
	long long int resultadoFactorialB;
	int flagCalculos = 0;
	int flagNum1 = 0;
	int flagNum2 = 0;
	int opcion;

	do {
		mostrarMenu(num1, num2, flagNum1, flagNum2);
		ingresarNumero(&opcion, "Ingrese una opcion: ");

		switch(opcion)
		{
		case 1:
			flagNum1 = ingresarNumero(&num1, "Ingrese el primer operando: ");
			system("pause");
		break;
		case 2:
			flagNum2 = ingresarNumero(&num2, "Ingrese el segundo operando: ");
			system("pause");
		break;
		case 3:
			flagCalculos = calcularTodo(flagNum1, flagNum2, &num1, &num2, &resultadoSuma, &resultadoResta, &resultadoMultiplicacion, &resultadoDivision, &retornoDivision, &resultadoFactorialA, &resultadoFactorialB);
			system("pause");
		break;
		case 4:
			mostrarResultados(flagCalculos, resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision, retornoDivision, resultadoFactorialA, resultadoFactorialB);
			system("pause");
			break;
		break;
		case 5:
			salirValidacion(&salir);
			break;
		default:
			printf("Error, el numero ingresado es incorrecto, debe elegir del 1 al 5\n");
		break;
		}

	} while (salir == 'n');
	printf("Salió del programa");
	return 0;
}







