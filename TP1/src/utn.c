/*
 * utn.c
 *
 *  Created on: 14 abr. 2021
 *      Author: jenni
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"

void mostrarMenu(int num1, int num2, int flagNum1, int flagNum2) {
	system("cls");
	printf("**Menu de opciones**\n\n");
	if(flagNum1)
	{
	printf("1-Ingrese el primer operando (A = %d)\n", num1);
	}
	else
	{
		printf("1-Ingrese el primer operando (A = x)\n");
	}
	if(flagNum2)
	{
		printf("2-Ingrese el segundo operando (B = %d)\n", num2);
	}
	else
	{
		printf("2-Ingrese el segundo operando (B = y)\n");
	}
	printf("3-Calcular todas las operaciones\n");
	printf("\t a) Calcular la suma (A+B)\n");
	printf("\t b) Calcular la resta (A-B)\n");
	printf("\t c) Calcular la division (A/B)\n");
	printf("\t d) Calcular la multiplicacion (A*B)\n");
	printf("\t e) Calcular el factorial (A!)\n");
	printf("4-Informar los resultados\n");
	printf("5-Salir\n");
}

int ingresarNumero(int *pNumero, char *pMensaje) {
	int num;
	int retorno = 0;
	if(pNumero != NULL && pMensaje != NULL)
	{
	printf(pMensaje);
	scanf("%d", &num);
	*pNumero = num;
	retorno = 1;
	}
	return retorno;
}

int calcularTodo(int flagNum1, int flagNum2, int* a, int* b, int* pResultadoSuma, int* pResultadoResta, int* pResultadoMultiplicacion, float* pResultadoDivision, int* pRetornoDivision, long long int* pResultadoFactorialA, long long int* pResultadoFactorialB){
	int retorno = 0;
	if (flagNum1 && !flagNum2)
	{
		printf("Para realizar el calculo, debes ingresar el segundo operando\n");
	}
	else if (!flagNum1)
	{
		printf("Para realizar el calculo, debes ingresar el primer operando\n");
	}
	else
	{
		*pResultadoSuma = sumar(*a, *b);
		*pResultadoResta = restar(*a, *b);
		*pResultadoMultiplicacion = multiplicar(*a, *b);
		*pRetornoDivision = dividir(pResultadoDivision, *a, *b);
		*pResultadoFactorialA = factorial(*a);
		*pResultadoFactorialB = factorial(*b);
		retorno = 1;
		printf("Se han realizado los calculos\n");
	}
	return retorno;
}

int sumar(int a, int b) {
	int resultado;
	resultado = a + b;
	return resultado;
}

int restar(int a, int b) {
	int resultado;
	resultado = a - b;
	return resultado;
}

int multiplicar(int a, int b) {
	int resultado;
	resultado = a * b;
	return resultado;
}

int dividir(float *pResultadoDivision, int a, int b) {

	float resultado;
	int retorno = 0;
	if (pResultadoDivision != NULL && b != 0) {
		resultado = (float) a / b;
		*pResultadoDivision = resultado;
		retorno = 1;
	}

	return retorno;
}

long long int factorial(int a){
	int respuesta = 0;
	if (a < 13 && a > 0) {
		if (a == 1) {
			respuesta = 1;
		}
		else
		{
		respuesta = a * factorial(a - 1);
		}
	}
	else
	{
		respuesta = -1;
	}
	return respuesta;
}

void mostrarResultados(int flagCalculos, int resultadoSuma, int resultadoResta, int resultadoMultiplicacion, float resultadoDivision, int retornoDivision, long long int resultadoFactorialA, long long int resultadoFactorialB)
{
	if(flagCalculos)
	{
		printf("El resultado de la suma es %d\n", resultadoSuma);
		if (retornoDivision == 1)
		{
			printf("El resultado de la division es %.2f\n", resultadoDivision);
		}
		else
		{
			printf("No se puede dividir por 0\n");
		}
		printf("El resultado de la resta es %d\n", resultadoResta);
		printf("El resultado de la multiplicacion es %d\n", resultadoMultiplicacion);
		if (resultadoFactorialA >= 1)
		{
			//para linux //printf("El resultado del factorial del primer operando es %lld\n", *pResultadoFactorialA);
			printf("El resultado del factorial del primer operando es %I64u\n", resultadoFactorialA);
		}
		else
		{
			printf("El primer operando no puede ser factorizado\n");
		}
		if (resultadoFactorialB >=1)
		{
			//para linux //printf("El resultado del factorial del primer operando es %lld\n", *pResultadoFactorialB);
			printf("El resultado del factorial del segundo operando es %I64u\n", resultadoFactorialB);
		}
		else
		{
			printf("El segundo operando no puede ser factorizado\n");
		}
	}
	else
	{
		printf("¡Primero debes realizar los calculos!\n");
	}
}


void salirValidacion(char* salir)
{
	printf("¿Desea salir? (s/n)?:");
	fflush(stdin);
	*salir = getchar();
	while(*salir != 'n' && *salir != 's')
	{
		printf("Por favor, ingrese un caracter valido, s = si, n = no\n");
		fflush(stdin);
		*salir = getchar();
	}
}
