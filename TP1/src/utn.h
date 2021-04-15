/*
 * utn.h
 *
 *  Created on: 14 abr. 2021
 *      Author: jenni
 */

#ifndef UTN_H
#define UTN_H

/** \brief muestra el menu con opciones, toma valores y los reemplaza dentro del menu
*
* \param int a valor de la variable del primer operando
* \param int b valor de la variable del segundo operando
* \param int flagIngresoNumero1 valor de la variable bandera de ingreso del primer operando
* \param int flagIngresoNumero2 valor de la variable bandera de ingreso del segundo operando
*
*/
void mostrarMenu(int a, int b, int flagIngresoNumero1, int flagIngresoNumero2);

/** \brief pide un valor y lo devuelve
*
* \param int* pNumero direccion en memoria del numero ingresado
* \param char* pMensaje direccion en memoria del mensaje a mostrar para pedir el numero
* \return retorna un entero que indica si se ingreso o no un valor
*
*/
int ingresarNumero(int *pNumero, char *pMensaje);

/** \brief toma el valor de las dos banderas para saber si debe calcular, realiza todas las operaciones matematicas y asigna los valores por direccion en memoria
*
* \param int flagNum1 valor de la variable bandera del primer operando
* \param int flagNum2 valor de la variable bandera del segundo operando
* \param int* a direccion en memoria del primer operando
* \param int* b direccion en memoria del segundo operando
* \param int* pResultadoSuma direccion en memoria de resultadoSuma
* \param int* pResultadoResta direccion en memoria de resultadoResta
* \param int* pResultadoMultiplicacion direccion en memoria de resultadoMultiplicacion
* \param float* pResultadoDivision direccion en memoria de resultadoDivision
* \param int* pRetornoDivision direccion en memoria de retornoDivision
* \param long long int* pResultadoFactorialA direccion en memoria de resultadoFactorialA
* \param long long int* pResultadoFactorialB direccion en memoria de resultadoFactorialB
* \return retorna un int que indica si se realizo la operacion
*
*/
int calcularTodo(int flagNum1, int flagNum2, int* a, int* b, int* pResultadoSuma, int* pResultadoResta, int* pResultadoMultiplicacion, float* pResultadoDivision, int* pRetornoDivision, long long int* pResultadoFactorialA, long long int* pResultadoFactorialB);

/** \brief toma dos numeros enteros y los suma
 *
 * \param int a valor de la variable del primer numero ingresado
 * \param int b valor de la variable del segundo numero ingresado
 * \return retorna el resultado de la suma
 *
 */
int sumar(int a, int b);

/** \brief toma dos numeros enteros y los divide
*
* \param float* pResultadoDivision puntero direccion en memoria del resultado de la division
* \param int a valor de la variable del primer numero ingresado
* \param int b valor de la variable del segundo numero ingresado
* \return retorna un int que indica si se pudo realizar la operacion
*
*/
int dividir(float *pResultadoDivision, int a, int b);

/** \brief toma dos numeros enteros y los resta
*
* \param int a valor de la variable del primer numero ingresado
* \param int b valor de la variable del segundo numero ingresado
* \return retorna el resultado de la resta
*
*/
int restar(int a, int b);

/** \brief toma dos numeros enteros y los multiplica
*
* \param int a valor de la variable del primer numero ingresado
* \param int b valor de la variable del segundo numero ingresado
* \return retorna el resultado de la multiplicacion
*
*/
int multiplicar(int a, int b);

/** \brief toma un numero entero positivo y lo factoriza
*
* \param int a valor de la variable del numero a factorizar
* \return retorna el resultado final de la factorizacion
*
*/
long long int factorial(int a);

/** \brief toma los valores y, si corresponde, los muestra
*
* \param int flagCalculos valor de la variable bandera que usa para saber si mostrar o no
* \param int resultadoSuma resultado de la funcion sumar
* \param int resultadoResta resultado de la funcion restar
* \param int resultadoMultiplicacion resultado de la funcion multiplicar
* \param float resultadoDivision resultado de la funcion dividir
* \param int retornoDivision retorno de la funcion dividir
* \param long long int resultadoFactorialA resultado de la funcion factorial para el valor a
* \param long long int resultadoFactorialB resultado de la funcion factorial para el valor b
*
*/
void mostrarResultados(int flagCalculos, int resultadoSuma, int resultadoResta, int resultadoMultiplicacion, float resultadoDivision, int retornoDivision, long long int resultadoFactorialA, long long int resultadoFactorialB);

/** \brief pide un caracter, verifica que sea correcto y lo pasa en direccion en memoria
*
* \param char* a  en memoria de la variable salir
*
*/
void salirValidacion(char* a);

#endif /* UTN_H */
