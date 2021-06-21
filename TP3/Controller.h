#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "Employee.h"
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(LinkedList* pArrayListEmployee);
int controller_saveAsBinary(LinkedList* pArrayListEmployee);
int buscarEmpleado(LinkedList* pArrayListEmployee, int id);
int buscarProximoId(LinkedList* pArrayListEmployee);
int buscarLibre(LinkedList* pArrayListEmployee, int*pIndice);
int buscarMayorId(LinkedList* pArrayListEmployee, int* id);
int menuEdit();
int menuSort();
#endif // CONTROLLER_H_INCLUDED
