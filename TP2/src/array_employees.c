#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "array_employees.h"
#include "utn_inputs.h"
#define TRUE 1
#define FALSE 0
#define EMPTY 1
#define FULL 0
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int initEmployees(eEmployee list[], int len) {
	int ret = 0;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = EMPTY;
		}
		ret = 1;
	}
	return ret;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (0) if Error [Invalid length or NULL pointer or without
 free space] - (1) if Ok
 *
 **/
int addEmployee(eEmployee list[], int len, int *pId) {
	int ret = 0;
	int index;
	eEmployee auxiliar;
	if (list != NULL && len > 0 && pId != NULL) {
		system("cls");
		printf("\n\n\t\t\t1.Alta empleado\n");
		printf("\t\t\t================");
		index = searchAvailablePlace(list, len);
		if (index == -1) {
			printf("\n\tNo hay lugar en el sistema");
		} else {
			auxiliar.id = *pId;

			printf("\n\tIngrese nombre: ");
			fflush(stdin);
			gets(auxiliar.name);
			while (strlen(auxiliar.name) > 51) {
				printf("\n\tError, nombre muy largo. Reingrese nombre: ");
				fflush(stdin);
				gets(auxiliar.name);
			}

			printf("\n\tIngrese apellido: ");
			fflush(stdin);
			gets(auxiliar.lastname);
			while (strlen(auxiliar.lastname) > 51) {
				printf("\n\tError, apellido muy largo. Reingrese apellido: ");
				fflush(stdin);
				gets(auxiliar.lastname);
			}

			printf("\n\tIngrese sueldo: ");
			scanf("%f", &auxiliar.salary);

			//mostrarSectores(sectores, tamSec);
			printf("\n\tIngrese id sector: ");
			scanf("%d", &auxiliar.sector);

			//Agregar una validacion antes de pasar la struct
			auxiliar.isEmpty = FULL;
			list[index] = auxiliar;
			//Actualizar id
			(*pId)++;
			ret = 1;
		}
	}
	return ret;
}

/** \brief To indicate there is a place in the array or not
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return the number of index to suscribe the employee
 *
 */
int searchAvailablePlace(eEmployee list[], int len) {
	int index = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty) {
				index = i;
				break;
			}
		}
	}
	return index;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee list[], int len, int id) {
	int index = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (!list[i].isEmpty && list[i].id == id) {
				index = i;
				break;
			}
		}
	}
	return index;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (0) if Error - (1) if Ok
 *
 */
int removeEmployee(eEmployee list[], int len) {
	int ret = 0;
	int index;
	int id;
	char confirm;

	system("cls");
	printf("\n\n\t\t\t\t\t\t3.Baja empleados\n");
	printf("\t\t\t\t\t\t====================\n");
	printEmployees(list, len);
	pedirNumero(&id,"\tIngrese id: ", "\tError id incorrecto: ", 0, 1000, 20);

	index = findEmployeeById(list, len, id);

	if (index == -1) {
		printf("\tNo existe un empleado con el legajo %d\n\n", id);
	} else {
		printEmployees(list, len);
		pedirChar(&confirm, "\n\tConfirma baja?: ", "\n\tError, ingrese un valor valido: ", 20);

		if (confirm == 's' || confirm == 'S') {
			list[index].isEmpty = 1;
			ret = 1;
		} else {
			printf("\n\tBaja cancelada por el usuario\n");
		}
	}
	return ret;
}

/** \brief Sort the elements in the array of employees, the argument order
 indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int sortEmployees(eEmployee list[], int len, int order) {
	int ret = 0;
	eEmployee auxEmployee;
	if (list != NULL && len > 0 && (order == 1 || order == 0)) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {

				stringToLower(list[i].lastname);
				stringToLower(list[j].lastname);

				if (order > 0) {
					if (strcmp(list[i].lastname, list[j].lastname) < 0
							|| (strcmp(list[i].lastname, list[j].lastname) == 0
									&& list[i].sector < list[j].sector)) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
				} else {
					if (strcmp(list[i].lastname, list[j].lastname) > 0
							|| (strcmp(list[i].lastname, list[j].lastname) == 0
									&& list[i].sector > list[j].sector)) {
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
				}

			}
		}
		ret = 1;
	}

	return ret;
}

/** \brief Convert string in lowercase
 *
 * \param list list[] string to convert
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int stringToLower(char list[]) {
	int ret = 0;
	if (list != NULL) {
		for (int i = 0; i < strlen(list); i++) {
			list[i] = tolower(list[i]);
			ret = 1;
		}
	}
	return ret;
}

/** \brief Convert string in capital letters
 *
 * \param list list[] string to convert
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int stringToUpper(char list[]) {
	int ret = 0;
	if (list != NULL) {
		for (int i = 0; i < strlen(list); i++) {
			list[i] = toupper(list[i]);
		}
	}
	return ret;
}

/** \brief print the content of one employee
 *
 * \param one employee
 * \return void
 *
 */
void printEmployee(eEmployee employee) {
	printf("\n\t|%10d|%20s|%20s|%9.2f|%10d|", employee.id, employee.name,
			employee.lastname, employee.salary, employee.sector);
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(eEmployee list[], int len) {
	int flag = 0;
	printf("\n\n\t\t\t\t\t\tLista de empleados\n");
	printf(
			"\t\t\t-----------------------------------------------------------------\n");
	printf("\t  Id\t\t\tNombre\t\tApellido\tSalario\t  Sector\n");
	printf(
			"\t--------------------------------------------------------------------------------------------------------------");
	for (int i = 0; i < len; i++) {
		if (!list[i].isEmpty) {
			printEmployee(list[i]);
			flag = 1;
		}
	}
	if (!flag) {
		printf("\n\tNo hay empleados en la lista");
	}
	printf("\n\n");
	return flag;
}


/** \brief Show a menu and get a number
 *
 * \return int option of menu
 *
 */
int menuReports() {
	int option;
	system("cls");
	printf("\n\n\t\t\tINFORMES\n");
	printf("\t\t=======================");
	printf("\n\t1-Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n");
	printf("\t2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
	printf("\t3-Salir\n");
	pedirNumero(&option, "\tIngrese la opcion: ", "Error, reingrese un numero valido: ", 1, 3, 10);
	return option;
}

/** \brief Controller of a menu
 *
 *\param employees[] array
 *\param int len length of array
 * \return Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int optionReports(eEmployee employees[], int len) {
	int ret = 0;
	char exit = 'n';
	do {
		int option = menuReports();
		switch (option) {
		case 1:
			sortEmployees(employees, len, 0);
			printEmployees(employees, len);
			break;
		case 2:
			totalSalary(employees, len);
			break;
		case 3:
			pedirChar(&exit, "\n\tDesea volver al menu principal? s/n\n", "\n\tError, caracter invalido, reingrese: \n", 20);
			break;
		default:
			printf("\n\tError, opcion incorrecta");
			break;
		}
	} while (exit == 'n');
	return ret;
}

/** \brief add all the salaries in the array and make average
 *
 *\param employees[] array
 *\param int len length of array
 *
 */
void totalSalary(eEmployee list[], int len) {
	float total = 0;
	float average = 0;
	int count = 0;
	int flag = 0;
	int countHighest = 0;
	system("cls");
	printf("\n\n\t\t\tTotal y promedio de sueldos");
	printf("\n\t\t..................................\n");
	for (int i = 0; i < len; i++) {
		if (list[i].isEmpty == 0) {
			total += list[i].salary;
			count++;
			flag = 1;
		}
	}

	if (count != 0 && flag) {
		average = (float) total / count;
		printf("\n\tTotal de todos los sueldos: %.2f\n", total);
		printf("\tEl promedio de sueldos es: %.2f\n", average);
		countHighest = countHighestSalary(list, len, average);
		printf(
				"\tLa cantidad de empleados que supera el sueldo promedio es: %d\n",
				countHighest);
	} else {
		printf("\tNo hay salarios para calcular");
	}

}

/** \brief count the highest salary in array
 *
 *\param employees[] array
 *\param int len length of array
 *\param int average
 *\return result of count
 */
int countHighestSalary(eEmployee list[], int len, int average) {
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (!list[i].isEmpty) {
			if (list[i].salary > average) {
				count++;
			}
		}
	}
	return count;
}
/** \brief show a menu of modify and get an option
 *
 *\return return an int with option
 *
 */
int menuModify() {
	int option;
	system("cls");
	printf("\n\n\t\t\t2.Modificar empleado\n");
	printf("\t\t==================================");
	printf("\n\t1-Nombre\n");
	printf("\t2-Apellido\n");
	printf("\t3-Salario\n");
	printf("\t4-Sector\n");
	printf("\t5-Guardar y volver al menu principal\n");
	printf("\t6-Salir sin modificar\n");
	pedirNumero(&option, "\tIngrese la opcion: ", "Error, reingrese un numero valido: ", 1, 6, 10);
	return option;
}

/** \brief Modify an employee. Let select what input change
 *
 *\param employees[] array
 *\param int len length of array
 * \return Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int modifyEmployee(eEmployee employees[], int len) {
	eEmployee  aux;
	int ret = 0;
	int option;
	int index;
	int id;
	char exit = 'n';
	int flagName= 0;
	int flagLastname = 0;
	int flagSector = 0;
	int flagSalary = 0;
	system("cls");
	printf("\n\n\t\t\t\t\t\t2.Modificar empleado\n");
	printf("\t\t\t\t\t\t====================\n");
	printEmployees(employees, len);
	pedirNumero(&id, "\tIngrese id: ", "Error, reingrese un numero valido: ", 0, 1000, 10);

	if (employees != NULL && len > 0) {
		index = findEmployeeById(employees, len, id);

		if (index == -1) {
			printf("\n\t\tNo se encontro el empleado ingresado");
		} else {
			printf("\n\t  ID\t\tNombre\t\tApellido\tSueldo\t\tSector\n");
			printf("\t--------------------------------------------------------------------------------------------------------------");
			printEmployee(employees[index]);
			do {
				option = menuModify();
				switch (option) {
				case 1:
					pedirString(&aux.name, "\tIngrese nombre: ", 51);
					flagName = 1;
					break;
				case 2:
					pedirString(&aux.lastname, "\tIngrese Apellido: ", 51);
					flagLastname = 1;
					break;
				case 3:
					pedirFloat(&aux.salary, "\tIngrese sueldo: ", "\tError, reingrese un sueldo: ", 0, 1000000, 10);
					flagSalary = 1;
					break;
				case 4:
					pedirNumero(&aux.sector, "\tIngrese sector: ", "Error, reingrese un sector: ", 1, 10, 10);
					flagSector = 1;
					break;
				case 5:
					if (flagName) {
						strcpy(employees[index].name, aux.name);
					}
					if (flagLastname) {
						strcpy(employees[index].lastname, aux.lastname);
					}
					if (flagSalary) {
						employees[index].salary= aux.salary;
					}
					if (flagSector) {
						employees[index].sector = aux.sector;
					}
					printEmployee(employees[index]);
					ret = 1;
					exit = 's';
					break;
				case 6:
					pedirChar(&exit, "\n\tDesea salir sin guardar cambios?\n",  "\n\tError, valor incorrecto\n", 10);
				}
			} while (exit == 'n');
		}

	}
	return ret;
}
