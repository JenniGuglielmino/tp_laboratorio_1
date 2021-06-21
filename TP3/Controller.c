#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn_biblioteca.h"
#include "parser.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f = NULL;
    if(pArrayListEmployee != NULL && path != NULL)
    {
        f = fopen(path, "r");
        if(f != NULL)
        {
            parser_EmployeeFromText(f, pArrayListEmployee);
            todoOk = 1;
        }
        else
        {
            printf("Hubo un error al abrir el archivo\n");
        }
    }
    fclose(f);
    return todoOk;
}

/** \brief buscar un indice libre
 *
 * \param pArrayListEmployee LinkedList*
 * \param int*pIndice
 * \return int
 *
 */
int buscarLibre(LinkedList* pArrayListEmployee, int*pIndice)
{
    int todoOk = 0;
    *pIndice = -1;
    Employee* aux = NULL;
    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0 && pIndice != NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            aux = (Employee*)ll_get(pArrayListEmployee, i);
            if(aux == NULL)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Busca el proximo id
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int buscarProximoId(LinkedList* pArrayListEmployee)
{
    int valorMaximo = -1;
    int tam = 0;
    int i;
    int cant = 0;
    Employee* aux;

    if(pArrayListEmployee != NULL)
    {
        tam = ll_len(pArrayListEmployee);

        if(tam > 0)
        {
            for(i = 0; i < tam; i++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee, i);

                if(aux != NULL)
                {
                    if(cant == 0)
                    {
                        valorMaximo = aux->id;
                    }
                    else
                    {
                        if(aux->id > valorMaximo
                                && aux->id < 1000)
                        {
                            valorMaximo = aux->id;
                        }
                    }

                    cant++;
                }
            }
        }

        if(cant > 0)
        {
            valorMaximo++;
        }
        else
        {
            valorMaximo = 1;
        }
    }

    return valorMaximo;
}

/** \brief Busca el mayor id de los empleados cargados
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int*
 * \return int
 *
 */
int buscarMayorId(LinkedList* pArrayListEmployee, int* id)
{
    int todoOk = 0;
    Employee* auxiliar = NULL;
    int mayorId;
    if(pArrayListEmployee != NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxiliar = (Employee*)ll_get(pArrayListEmployee, i);
            if(i==0 || auxiliar->id > mayorId)
            {
                mayorId = auxiliar->id;
            }
        }
        *id = mayorId + 1;
        todoOk =1;
    }

    return todoOk;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* f = NULL;
    if(pArrayListEmployee != NULL)
    {
        f = fopen(path, "rb");
        if(f != NULL)
        {
            parser_EmployeeFromBinary(f, pArrayListEmployee);
            todoOk = 1;
        }
        else
        {
            printf("No se pudo abrir el archivo\n");
        }
    }
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* pId)
{
    int todoOk = 0;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    Employee* nuevoEmpleado = NULL;
    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("\n\n\t\t\t1.Alta empleado\n");
        printf("\t\t\t================\n");
        if(*pId == -1)
        {
            printf("\n\tNo hay lugar en el sistema\n");
        }
        else
        {
            pedirString(nombre, "Ingrese nombre: ", 128);
            pedirNumero(&horasTrabajadas, "Ingrese las horas trabajadas: ", "Error ingrese un numero valido", 0, 100000, 10);
            pedirNumero(&sueldo, "Ingrese el sueldo: ", "Error ingrese un numero valido", 0, 2000000, 10);

            nuevoEmpleado = nuevoEmpleadoParam(*pId, nombre, horasTrabajadas, sueldo);

            if(nuevoEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, (Employee*)nuevoEmpleado);
                (*pId)++;
                todoOk = 1;
            }
        }
    }
    return todoOk;
}



/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxiliar = employee_new();
    Employee* auxiliar2;
    int todoOk = 0;
    int indice;
    int id;
    char seguir = 'n';
    system("cls");
    if(ll_len(pArrayListEmployee)== 0)
    {
        todoOk = -1;

    }
    else
    {
        printf("\n\n\t\t\t\t\t\t2.Modificar empleado\n");
        printf("\t\t\t\t\t\t====================\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("\n\tIngrese id: ");
        scanf("%d", &id);

        if(pArrayListEmployee != NULL)
        {
            indice = buscarEmpleado(pArrayListEmployee, id);

            if(indice == -1)
            {
                printf("\t\tNo se encontro el empleado ingresado");
            }
            else
            {
                printf("\n\t  Id\t\tNombre\t\tHoras trabajadas\t\t\tSueldo\n");
                printf("\t----------------------------------------------------------");
                mostrarEmpleado((Employee*) ll_get(pArrayListEmployee, indice));
                auxiliar = (Employee*) ll_get(pArrayListEmployee, indice);
                if(auxiliar != NULL)
                {
                    auxiliar2 = nuevoEmpleadoParam(auxiliar->id, auxiliar->nombre,auxiliar->horasTrabajadas, auxiliar->sueldo);
                    do
                    {
                        switch(menuEdit())
                        {
                        case 1:
                            pedirString(auxiliar2->nombre, "\n\tIngrese nombre: ", 127);
                            employee_setNombre(auxiliar2, auxiliar2->nombre);
                            break;
                        case 2:
                            pedirNumero(&auxiliar2->horasTrabajadas, "\n\tIngrese las horas trabajadas: ","Error ingrese un numero valido", 0, 100000, 10);
                            employee_setHorasTrabajadas(auxiliar2, auxiliar2->horasTrabajadas);
                            break;
                        case 3:
                            pedirNumero(&auxiliar2->sueldo, "\n\tIngrese el sueldo: ", "Error ingrese un numero valido", 0, 2000000, 10);
                            employee_setSueldo(auxiliar2, auxiliar2->sueldo);
                            break;
                        case 4:
                            pedirChar(&seguir, "\n\tDesea salir sin guardar cambios? (s/n): ", "Error ingrese un caracter", 10);
                            break;
                        case 5:
                            ll_set(pArrayListEmployee, indice, (Employee*)auxiliar2);
                            printf("\n------------------------------------------------------------------------------\n");
                            printf("\tId        |       Nombre        |    Horas trabajadas    |    Sueldo  |\n");
                            printf("------------------------------------------------------------------------------\n");
                            mostrarEmpleado((Employee*) ll_get(pArrayListEmployee, indice));
                            todoOk = 1;
                            seguir = 's';
                            break;
                        }
                    }
                    while(seguir == 'n');
                }
            }

        }
    }
    return todoOk;
}

/** \brief Muestra el menu de edicion
 *
 * \return int
 *
 */
int menuEdit()
{
    int opcion;
    system("cls");
    printf("\n\n\t\t\tMENU EDITAR EMPLEADO\n");
    printf("\t\t\t--------------------");
    printf("\n\t1-Editar nombre\n");
    printf("\t2-Editar horas trabajadas\n");
    printf("\t3-Editar salario\n");
    printf("\t4-Salir sin guardar\n");
    printf("\t5-Aplicar cambios y volver al menu\n");
    pedirNumero(&opcion, "\tIngrese la opcion: ", "Error, reingrese un numero valido: ", 1, 6, 10);
    return opcion;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int indice;
    int id;
    char confirma;
    Employee* auxiliar = employee_new();
    system("cls");
    if(ll_len(pArrayListEmployee)== 0)
    {
        todoOk = -1;
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t3.Baja empleados\n");
        printf("\t\t\t\t\t\t====================\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("\n\tIngrese id: ");
        scanf("%d", &id);

        indice = buscarEmpleado(pArrayListEmployee, id);

        if(indice == -1)
        {
            printf("\tNo existe un empleado con el legajo %d\n\n", id);
        }
        else
        {
            auxiliar =  (Employee*)ll_get(pArrayListEmployee, indice);
            if(auxiliar != NULL)
            {
                printf("\n------------------------------------------------------------------------------\n");
                printf("\tId        |       Nombre        |    Horas trabajadas    |    Sueldo  |\n");
                printf("------------------------------------------------------------------------------\n");
                mostrarEmpleado(auxiliar);
                printf("\n\tConfirma baja?(s/n): ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma == 's' || confirma == 'S')
                {
                    if(ll_remove(pArrayListEmployee, indice) == 0)
                    {
                        todoOk = 1;
                        employee_delete(auxiliar);
                        auxiliar = NULL;
                    }
                }
                else
                {
                    printf("\n\tBaja cancelada por el usuario\n");
                }

            }
        }
    }
    return todoOk;
}

/** \brief Busca un empleado especifico por su id
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int
 *
 */
int buscarEmpleado(LinkedList* pArrayListEmployee, int id)
{
    int indice = -1;
    Employee* auxiliar;
    if(pArrayListEmployee != NULL)
    {
        if(ll_len(pArrayListEmployee) > 0)
        {
            for(int i=0; i< ll_len(pArrayListEmployee); i++)
            {
                auxiliar =  (Employee*)ll_get(pArrayListEmployee, i);
                if(auxiliar != NULL && auxiliar->id == id)
                {
                    indice = i;
                    break;
                }
            }
        }
    }
    return indice;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* auxiliar = NULL;
    if(pArrayListEmployee != NULL)
    {
        printf("\n------------------------------------------------------------------------------\n");
        printf("\tId        |       Nombre        |    Horas trabajadas    |    Sueldo  |\n");
        printf("------------------------------------------------------------------------------\n");
        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            auxiliar = (Employee*)ll_get(pArrayListEmployee, i);
            mostrarEmpleado(auxiliar);
            todoOk = 1;
        }
    }
    return todoOk;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char salir = 's';

    do{
      switch(menuSort())
        {
        case 1:
            printf("\tEsto podria tardar...");
            ll_sort(pArrayListEmployee, employee_cmpId, 0);
            controller_ListEmployee(pArrayListEmployee);
            break;
        case 2:
            printf("\tEsto podria tardar...");
            ll_sort(pArrayListEmployee, employee_cmpSueldo, 0);
            controller_ListEmployee(pArrayListEmployee);
            break;
        case 3:
            printf("\tEsto podria tardar...");
            ll_sort(pArrayListEmployee, employee_cmpNombre, 0);
            controller_ListEmployee(pArrayListEmployee);
            break;
        case 4:
            pedirChar(&salir, "Desea salir? s/n: ", "Error, ingrese un caracter valido", 10);
            break;
        default:
            printf("Error, ingrese un valor valido.");
            break;
        }
    }while(salir == 'n');
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char confirma = 's';
    char path[128];
    Employee* auxiliar = employee_new();
    int cant;
    int flag = 0;
    FILE* f = NULL;
    printf("\n\t\tPath sugerido 'data.csv'\n");
    printf("\t\tIngrese path para archivo de texto: ");
    fflush(stdin);
    gets(path);
    f = fopen(path, "r");
    if(f != NULL)
    {
        pedirChar(&confirma, "\t\tCuidado, el archivo existe y se va a sobrescribir. Confirma? s/n: ", "Error ingrese un caracter valido", 10);
    }
    fclose(f);
    if(confirma == 's')
    {
        f = fopen(path, "w");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            fprintf(f, "id ,nombre,sexo,sueldo\n");

            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxiliar = (Employee*)ll_get(pArrayListEmployee, i);
                if(auxiliar != NULL)
                {
                    cant = fprintf(f, "%d,%s,%d,%d\n", auxiliar->id,auxiliar->nombre,auxiliar->horasTrabajadas,auxiliar->sueldo);//ree
                    if(cant < 4)
                    {
                        flag = 1;
                        break;
                    }
                }
            }

        }
         fclose(f);
    }
    if(flag)
    {
        printf("Ocurrio un problema al guardar los empleados en el archivo\n");
    }
    else
    {
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(LinkedList* pArrayListEmployee)
{
    int todoOk= 0;
    char confirma = 's';
    int cant;
    char path[128];
    Employee * auxiliar = NULL;
    int flag = 0;
    FILE* f = NULL;
    printf("\n\t\tPath sugerido 'data.bin'\n");
    printf("\t\tIngrese path para archivo binario: ");
    fflush(stdin);
    gets(path);
    f = fopen(path, "rb");
    if(f != NULL)
    {
        pedirChar(&confirma, "\t\tCuidado, el archivo existe y se va a sobrescribir. Confirma? s/n: ", "Error ingrese un caracter valido", 10);
        todoOk = -1;
    }
    fclose(f);
    if(confirma == 's')
    {
          f = fopen(path,"wb");
          if(f == NULL)
          {
              printf("No se pudo abrir el archivo\n");
          }
          else
          {
              for(int i=0; i<ll_len(pArrayListEmployee); i++)
              {
                    auxiliar = (Employee*)ll_get(pArrayListEmployee, i);
                    if( auxiliar != NULL)
                    {
                        cant = fwrite(auxiliar, sizeof(Employee), 1, f);
                        if(cant < 1)
                        {
                            flag = 1;
                        }
                    }
              }

          }
          fclose(f);
    }

    if(flag)
    {
        printf("Ocurrio un problema al guardar los empleados en el archivo\n");
    }
    else
    {
        todoOk= 1;
    }

    return todoOk;
}

/** \brief Muestra el menu de ordenamiento
 *
 * \return int
 *
 */
int menuSort()
{
    int opcion;
    system("cls");
    printf("\n\n\t\t\tMENU ORDENAR EMPLEADO\n");
    printf("\t\t\t--------------------");
    printf("\n\t1-Ordenar por id\n");
    printf("\t2-Ordenar por salario\n");
    printf("\t3-Ordenar por nombre\n");
    printf("\t4-Volver al menu principal\n");
    pedirNumero(&opcion, "\tIngrese la opcion: ", "Error, reingrese un numero valido: ", 1, 4, 10);
    return opcion;
}

