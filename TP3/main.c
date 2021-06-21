#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_biblioteca.h"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"
#define RESET   "\033[0m"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int menu();

int main()
{
    int idEmployee = 1;
    int cantidadEmpleados = 0;
    char salir = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados == NULL){
        printf("No se pudo crear el linkedlist");
        exit(1);
    }
    do{
        cantidadEmpleados = ll_len(listaEmpleados);
        switch(menu())
        {
            case 1:
               if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf(BOLDGREEN"\t\t\t\t+--------------------------------------------+");
                    printf("\n\t\t\t\t|    Empleados cargados correctamente!!!     |\n");
                    printf("\t\t\t\t+--------------------------------------------+\n"RESET);
                    buscarMayorId(listaEmpleados, &idEmployee);
                }
               else
                {
                     printf(BOLDRED"\t\t\t\t\tProblemas para cargar a los empleados\n"RESET);
                }
                break;
            case 2:
                if(controller_loadFromBinary("data.bin", listaEmpleados))
                {
                    printf(BOLDGREEN"\t\t\t\t+--------------------------------------------+");
                    printf("\n\t\t\t\t|    Empleados cargados correctamente!!!     |\n");
                    printf("\t\t\t\t+--------------------------------------------+\n"RESET);
                    buscarMayorId(listaEmpleados, &idEmployee);
                }
                else
                {
                    printf(BOLDRED"\t\t\t\t\tProblemas para cargar a los empleados\n"RESET);
                }
                break;
            case 3:
                 if(controller_addEmployee(listaEmpleados, &idEmployee)){
                    printf(BOLDGREEN"\t\t\t\t+------------------------+");
                    printf("\n\t\t\t\t|    Alta exitosa!!!     |\n");
                    printf("\t\t\t\t+------------------------+\n"RESET);
                }
                else{
                    printf(BOLDRED"\t\t\t\tHubo un problema al dar de alta"RESET);
                }
                break;
            case 4:
                if(controller_editEmployee(listaEmpleados)== 1)
                {
                    printf(BOLDGREEN"\t\t\t+-----------------------------+");
                    printf("\n\t\t\t|    Modificacion exitosa!!!  |\n");
                    printf("\t\t\t+-----------------------------+\n"RESET);
                }
                else if(controller_editEmployee(listaEmpleados) == -1)
                {
                     printf(BOLDRED"\t\t\t+-------------------------------+");
                    printf("\n\t\t\t|    No hay empleados cargados  |\n");
                    printf("\t\t\t+-------------------------------+\n"RESET);
                }
                else
                {
                    printf(BOLDRED"\n\t\t\tHubo un problema al modificar"RESET);
                }
                break;
            case 5:
                if(controller_removeEmployee(listaEmpleados)==1)
                {
                    printf(BOLDGREEN"\t\t\t\t+------------------------+");
                    printf("\n\t\t\t\t|    Baja exitosa!!!     |\n");
                    printf("\t\t\t\t+------------------------+\n"RESET);
                }
                else if(controller_removeEmployee(listaEmpleados)== -1)
                {
                     printf(BOLDRED"\t\t\t+-------------------------------+");
                    printf("\n\t\t\t|    No hay empleados cargados  |\n");
                    printf("\t\t\t+-------------------------------+\n"RESET);
                }
                else{
                    printf(BOLDRED"\t\t\t\tHubo un problema al dar de baja\n"RESET);
                }
                break;
            case 6:
                if(cantidadEmpleados == 0)
                {
                    printf(BOLDRED"\t\t\t+-----------------------------------+");
                    printf("\n\t\t\t|    No hay empleados para mostrar  |\n");
                    printf("\t\t\t+-----------------------------------+\n"RESET);
                }
                else
                {
                    controller_ListEmployee(listaEmpleados);
                }
                break;
            case 7:
                if(cantidadEmpleados == 0)
                {
                    printf(BOLDRED"\t\t\t+-----------------------------------+");
                    printf("\n\t\t\t|    No hay empleados para ordenar  |\n");
                    printf("\t\t\t+-----------------------------------+\n"RESET);
                }
                else
                {
                     controller_sortEmployee(listaEmpleados);
                }
                break;
            case 8:
                if(controller_saveAsText(listaEmpleados))
                {
                      printf(BOLDGREEN"\t\t\t\t+----------------------------------------------+");
                    printf("\n\t\t\t\t|   Guardado en texto realizado con exito!     |\n");
                    printf("\t\t\t\t+----------------------------------------------+\n"RESET);
                }
                else
                {
                     printf(BOLDRED"\t\t\t\tProblemas al guardar a los empleados\n"RESET);
                }
                break;
            case 9:
                if(controller_saveAsBinary(listaEmpleados))
                {
                    printf(BOLDGREEN"\t\t\t\t+----------------------------------------------+");
                    printf("\n\t\t\t\t|   Guardado en binario realizado con exito!   |\n");
                    printf("\t\t\t\t+----------------------------------------------+\n"RESET);
                }
                else
                {
                     printf(BOLDRED"\t\t\t\tProblemas al guardar a los empleados\n"RESET);
                }
                break;
            case 10:
                pedirChar(&salir,"\n\tDesea continuar? S/N","Error ingrese un caracter", 10 );
                break;
            default:
                    printf(BOLDRED"\n\tOpcion invalida\n\n"RESET);
            break;
        }
        system("pause");
    }while(salir == 'n');
    return 0;
}

int menu(){
    int opcion;
    system("cls");
    printf("\n\n\t\t\tGESTION DE EMPLEADOS\n");
    printf("\t\t\t--------------------");
    printf("\n\t1-Cargar los datos de los empleados desde el archivo de texto\n");
    printf("\t2-Cargar los datos de los empleados desde el archivo binario\n");
    printf("\t3-Alta de empleado\n");
    printf("\t4-Modificar datos de empleado\n");
    printf("\t5-Baja de empleado\n");
    printf("\t6-Listar empleados\n");
    printf("\t7-Ordenar empleados\n");
    printf("\t8-Guardar los datos de los empleados en el archivo data.csv\n");
    printf("\t9-Guardar los datos de los empleados en el archivo data.bin\n");
    printf("\t10-Salir\n");
    pedirNumero(&opcion, "\tIngrese la opcion: ", BOLDRED"\tError, reingrese un numero valido\n"RESET, 1, 10, 10);
    return opcion;
}



