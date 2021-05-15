/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_employees.h"
#include "utn_inputs.h"

#define TAME 1000


int menu();

int main(void) {
	setbuf(stdout, NULL);
	int proxIdE = 0;
	char salir = 'n';
	eEmployee employees[TAME];
	initEmployees(employees, TAME);
	do{
		switch(menu()){
		case 1:
			if(addEmployee(employees, TAME, &proxIdE)){
				printf("\n\t\t\t\t+------------------------+");
				printf("\n\t\t\t\t|    Alta exitosa!!!     |\n");
				printf("\t\t\t\t+------------------------+\n");
			}
			else{
				printf("\n\tNo se puedo realizar el alta");
			}
			break;
		case 2:
			if (modifyEmployee(employees, TAME)) {
				printf("\n\t\t\t+-----------------------------+");
				printf("\n\t\t\t|    Modificacion exitosa!!!  |\n");
				printf("\t\t\t+-----------------------------+\n");
			} else {
				printf("\n\tNo se puedo realizar la modificacion");
			}
			break;
		case 3:
			if(removeEmployee(employees, TAME)){
				printf("\n\t\t\t+---------------------+");
				printf("\n\t\t\t|    Baja exitosa!!!  |\n");
				printf("\t\t\t+---------------------+\n");
			}
			else{
				printf("\tHubo un problema al dar de baja");
			}
			break;
		case 4:
			optionReports(employees, TAME);
			break;
		case 5:
			printf("Desea salir? s/n");
			scanf("%c", &salir);
			break;
		default:
			break;
		}
		system("pause");
	}while(salir == 'n');
	return EXIT_SUCCESS;
}


int menu(){
    int option;
    system("cls");
    printf("\n\n\t\t\tGESTION DE EMPLEADOS\n");
    printf("\t\t\t--------------------");
    printf("\n\t1-Alta\n");
    printf("\t2-Modificar\n");
    printf("\t3-Baja\n");
    printf("\t4-Informe\n");
    printf("\t5-Salir\n");
    printf("\tIngrese opcion: ");
    scanf("%d", &option);
    //getNumero(&opcion, "\tIngrese la opcion: ", "Error, reingrese un numero valido: ", 1, 11, 10);
    return option;
}


