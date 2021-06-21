#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

/** \brief Genera un nuevo empleado con parametros string
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleado = employee_new();
    if(nuevoEmpleado != NULL)
    {
        if(!(employee_setId(nuevoEmpleado, atoi(idStr))
           && employee_setNombre(nuevoEmpleado, nombreStr)
           && employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))
           && employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))))
        {
            employee_delete(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}

/** \brief Genera un nuevo empleado vacio inicializado en 0
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*)malloc(sizeof(Employee));
    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, " ");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }
    return nuevoEmpleado;
}

/** \brief Genera un nuevo empleado
 *
 * \param id int
 * \param nombre char*
 * \param horas int
 * \param sueldo int
 * \return Employee*
 *
 */
Employee* nuevoEmpleadoParam(int id, char* nombre, int horas, int sueldo)
{
    Employee* nuevoEmpleado = employee_new();
    if(nuevoEmpleado != NULL)
    {
        if(!(employee_setId(nuevoEmpleado, id)
           && employee_setNombre(nuevoEmpleado, nombre)
           && employee_setHorasTrabajadas(nuevoEmpleado, horas)
           && employee_setSueldo(nuevoEmpleado, sueldo)))
        {
            employee_delete(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}

/** \brief Muestra un solo empleado
 *
 * \param this Employee*
 * \return int
 *
 */
int mostrarEmpleado(Employee* this)
{
    int todoOk = 0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    if(this != NULL
       && employee_getId(this, &id)
       && employee_getNombre(this, nombre)
       && employee_getHorasTrabajadas(this, &horasTrabajadas)
       && employee_getSueldo(this, &sueldo))
    {
        printf("    %5d      %20s       %10d    %20d\n", id, nombre, horasTrabajadas, sueldo);
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Set id
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{
        int todoOk=0;
        if(this != NULL && id > 0)
        {
            this->id = id;
            todoOk = 1;
        }
        return todoOk;
}

/** \brief Get id
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{
        int todoOk=0;
        if(this != NULL && id != NULL)
        {
            (*id) = this->id;
            todoOk = 1;
        }
        return todoOk;
}

/** \brief Set nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
        int todoOk=0;
        if(this != NULL && nombre != NULL && strlen(nombre) > 2 && strlen(nombre) < 129)
        {
            strcpy(this->nombre, nombre);
            todoOk = 1;
        }
        return todoOk;
}

/** \brief Get nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
        int todoOk=0;
        if(this != NULL && nombre != NULL)
        {
            strcpy(nombre, this->nombre);
            todoOk = 1;
        }
        return todoOk;

}

/** \brief set horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
        int todoOk=0;
        if(this != NULL && horasTrabajadas >= 0)
        {
            this->horasTrabajadas = horasTrabajadas;
            todoOk = 1;
        }
        return todoOk;
}

/** \brief  get horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
        int todoOk=0;
        if(this != NULL && horasTrabajadas != NULL)
        {
            (*horasTrabajadas) = this->horasTrabajadas;
            todoOk = 1;
        }
        return todoOk;
}

/** \brief
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
        int todoOk=0;
        if(this != NULL && sueldo >= 0)
        {
            this->sueldo = sueldo;
            todoOk = 1;
        }
        return todoOk;
}

/** \brief Get sueldo
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
        int todoOk=0;
        if(this != NULL && sueldo != NULL)
        {
            (*sueldo) = this->sueldo;
            todoOk = 1;
        }
        return todoOk;
}

/** \brief Elimina un empleado
 *
 * \param this Employee*
 * \return int
 *
 */
int employee_delete(Employee* this){
        int todoOk=0;
        if(this != NULL)
        {
            free(this);
            todoOk = 1;
        }
        return todoOk;
}

/** \brief Ordena comparando id
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employee_cmpId(void* a, void* b)
{
    int todoOk= 0;
    Employee* auxiliar = NULL;
    Employee* auxiliar2 = NULL;
    if(a != NULL && b != NULL)
    {
        auxiliar = (Employee*) a;
        auxiliar2 = (Employee*)b;
        if(auxiliar->id > auxiliar2->id)
        {
            todoOk = 1;
        }
        else if(auxiliar->id < auxiliar2->id)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

/** \brief Ordena comparando nombres
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employee_cmpNombre(void* a, void* b)
{
    int todoOk= 0;
    Employee* auxiliar = NULL;
    Employee* auxiliar2 = NULL;
    if(a != NULL && b != NULL)
    {
        auxiliar = (Employee*) a;
        auxiliar2 = (Employee*)b;
        todoOk = strcmp(auxiliar->nombre, auxiliar2->nombre);
    }
    return todoOk;
}

/** \brief Ordena comparando sueldos
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employee_cmpSueldo(void* a, void* b)
{
    int todoOk= 0;
    Employee* auxiliar = NULL;
    Employee* auxiliar2 = NULL;
    if(a != NULL && b != NULL)
    {
        auxiliar = (Employee*) a;
        auxiliar2 = (Employee*)b;
        if(auxiliar->sueldo > auxiliar2->sueldo)
        {
            todoOk = 1;
        }
        else if(auxiliar->sueldo < auxiliar2->sueldo)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

