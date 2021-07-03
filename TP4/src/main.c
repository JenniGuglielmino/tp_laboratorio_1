/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

typedef struct
{
    int id;
    char nombre[20];
    int edad;
    char sexo;
} eMascota;

//funciones para mostar
int mostrarMascota(eMascota* m1);
int mostrarListaMascota(LinkedList* lista);

//funciones para filtrar
int esMacho(void* m);
int esHembra(void* m);
int esKira(void* m);
int esMayor5(void* m);

//funciones para ordenar
int cmp_SexoMascota(void* a, void* b);
int cmp_NombreMascota(void* a, void* b);
int cmp_EdadMascota(void* a, void* b);

int main(void)
{
    //startTesting(1);  // ll_newLinkedList
    //startTesting(2);  // ll_len
    //startTesting(3);  // getNode - test_getNode
    //startTesting(4);  // addNode - test_addNode
    //startTesting(5);  // ll_add
    //startTesting(6);  // ll_get
    //startTesting(7);  // ll_set
    //startTesting(8);  // ll_remove
    //startTesting(9);  // ll_clear
    //startTesting(10); // ll_deleteLinkedList
    //startTesting(11); // ll_indexOf
    //startTesting(12); // ll_isEmpty
    //startTesting(13); // ll_push
    //startTesting(14); // ll_pop
    //startTesting(15); // ll_contains
    //startTesting(16); // ll_containsAll
    //startTesting(17); // ll_subList
    //startTesting(18); // ll_clone
    //startTesting(19); // ll_sort

    //Crear un linkedlist -> funcion ll_newLinkedList
    LinkedList* lista = ll_newLinkedList();

    //hardcodeo de mascotas para pruebas
    eMascota m1 = {1, "kira", 1, 'h'};
    eMascota m2 = {2, "simon", 7, 'm'};
    eMascota m3 = {3, "tomi", 7, 'm'};
    eMascota m4 = {4, "lupe", 5, 'h'};
    eMascota m5 = {5, "nina", 3, 'h'};

    //Agregar una mascota a la lista linkedlist -> funcion ll_add
    if(!ll_add(lista, &m1)&&
            !ll_add(lista, &m2)&&
            !ll_add(lista, &m3)&&
            !ll_add(lista, &m4)&&
            !ll_add(lista, &m5))
    {
        printf("Se agregaron correctamente\n");
    }

    //Saber cuantos elementos tengo en la lista -> funcion ll_len
    //printf("Hay %d elemento/s en la lista\n", ll_len(lista));

    //Mostrar a un elemento solo ingresando el indice --> funcion ll_get
    //mostrarMascota((eMascota*)ll_get(lista, 4));

    //filtrar la lista --> funcion ll_filter
    //LinkedList* machos = ll_filter(lista, esMacho);
    //mostrarListaMascota(machos);

    //modificar un elemento de la lista ->funcion ll_set
    /*eMascota m5Actualizada = {5, "nino", 8, 'm'};
    if(!ll_set(lista, 4, &m5Actualizada))
    {
        mostrarListaMascota(lista);
    }
    else
    {
        printf("No pudo modificarse el elemento\n");
    }*/

    //eliminar un elemento de la lista --> funcion ll_remove
    /*if(!ll_remove(lista, 3))
    {
        mostrarListaMascota(lista);
    }
    else
    {
        printf("No se pudo eliminar el elemento\n");
    }*/

    //borrar todos los elementos del linkedlist -> funcion ll_clear
    /*if(!ll_clear(lista))
    {
       printf("Quedaron %d elementos\n", ll_len(lista));
    }
    else
    {
        printf("No se pudo eliminar los elementos\n");
    }*/

    //eliminar el linkedlist -> funcion ll_deleteLinkedList
    /*if(!ll_deleteLinkedList(lista))
    {
        printf("Se ha eliminado la lista correctamente");
    }
    else
    {
        printf("Se produjo un error al eliminar la lista\n");
    }*/

    //Buscar el indice de cierto elemento --> funcion ll_indexOf
    //printf("El indice es %d\n", ll_indexOf(lista, &m4));

    //Saber si la lista contiene elementos o no -> funcion ll_isEmpty
    /*if(ll_isEmpty(lista))
    {
        printf("La lista esta vacia\n");
    }
    else if(!ll_isEmpty(lista))
    {
        printf("La lista contiene elementos\n");
    }*/

    //Insertar un elemento en cierto indice dezplazando al resto -> funcion ll_push
    /*eMascota nuevaMascota = {2, "garrafa", 8, 'm'};
    if(!ll_push(lista, 1, &nuevaMascota))
    {
        mostrarListaMascota(lista);
    }
    else
    {
        printf("Hubo un error al insertar el elemento\n");
    }*/

    //Obtener un elemento de una lista y  luego eliminarlo--> funcion ll_pop
    /*LinkedList* lista2 = ll_newLinkedList();//nueva lista para prueba
    mostrarListaMascota(lista);
    void* popAux = ll_pop(lista, 2);
    if(popAux != NULL)
    {
        mostrarListaMascota(lista);
        ll_add(lista2, popAux);
        printf("Se elimino a %s y se agrego en otra lista\n", &m3.nombre);
        mostrarListaMascota(lista2);
    }
    else
    {
        printf("Se produjo un error al querer realizar la operacion\n");
    }*/

    //Saber si la lista contiene o no cierto elemento -> funcion ll_contains
    /*if(ll_contains(lista, &m5))
    {
        printf("La lista contiene al elemento\n");
    }
    else if(!ll_contains(lista, &m5))
    {
         printf("La lista no contiene este elemento!\n");
    }*/

    //Saber si la lista contiene todos los elementos de la segunda lista -> funcion ll_containsAll
    /*LinkedList* lista2 = ll_newLinkedList();//nueva lista de prueba
    if(ll_containsAll(lista, lista2))
    {
        printf("Las listas son distintas!\n");
    }
    else if(!ll_containsAll(lista, lista2))
    {
        printf("La listas contienen los mismos elementos!\n");
    }*/

    //crear un nuevo linkedlist a partir de uno, con un subconjuntos de elementos seleccionados -> funcion ll_sublist
    /*LinkedList* sublista = ll_subList(lista, 2, 5);
    if(sublista != NULL)
    {
        mostrarListaMascota(sublista);
    }
    else
    {
        printf("Hubo un error al crear la sublista!\n");
    }*/

    //Crear una lista exactamente igual a una existente -> funcion ll_clone
    /*LinkedList* listaClonada = ll_clone(lista);
    mostrarListaMascota(lista);
    printf("\nLista clonada\n");
    mostrarListaMascota(listaClonada);*/

    //Ordenar los elementos de la lista -> ll_sort
    /*printf("Ordenar por nombre\n");
    ll_sort(lista, cmp_NombreMascota, 1);
    mostrarListaMascota(lista);

    printf("Ordenar por sexo\n");
    ll_sort(lista, cmp_SexoMascota, 1);
    mostrarListaMascota(lista);

    printf("Ordenar por edad\n");
    ll_sort(lista, cmp_EdadMascota, 1);
    mostrarListaMascota(lista);*/

    return 0;
}

int mostrarMascota(eMascota* m1)
{
    printf("%d  %10s  %5d  %5c\n", m1->id, m1->nombre, m1->edad, m1->sexo);
    return 1;
}

int esMacho(void* m)
{
    int todoOk = 0;
    eMascota* unaMascota = NULL;
    if(m != NULL)
    {
        unaMascota = (eMascota*)m;
        if(unaMascota->sexo == 'm')
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int esHembra(void* m)
{
    int todoOk = 0;
    eMascota* unaMascota = NULL;
    if(m != NULL)
    {
        unaMascota = (eMascota*)m;
        if(unaMascota->sexo == 'h')
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int esKira(void* m)
{
    int todoOk = 0;
    eMascota* unaMascota = NULL;
    if(m != NULL)
    {
        unaMascota = (eMascota*)m;
        if(!strcmp(unaMascota->nombre, "Kira"))
        {
            todoOk = 1;
        }
    }
    return todoOk;

}
int esMayor5(void* m)
{
    int todoOk = 0;
    eMascota* unaMascota = NULL;
    if(m != NULL)
    {
        unaMascota = (eMascota*)m;
        if(unaMascota->edad > 5)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int mostrarListaMascota(LinkedList* lista)
{
    printf("Id      Nombre    Edad  Sexo\n");
    for(int i=0; i<ll_len(lista); i++)
    {
        mostrarMascota((eMascota*)ll_get(lista, i));
    }
    printf("\n\n");
    return 0;
}

int cmp_NombreMascota(void* a, void* b)
{
    int todoOk= 0;
    eMascota* auxiliar = NULL;
    eMascota* auxiliar2 = NULL;
    if(a != NULL && b != NULL)
    {
        auxiliar = (eMascota*) a;
        auxiliar2 = (eMascota*)b;
        todoOk = strcmp(auxiliar->nombre, auxiliar2->nombre);
    }
    return todoOk;
}

int cmp_EdadMascota(void* a, void* b)
{
    int todoOk= 0;
    eMascota* auxiliar = NULL;
    eMascota* auxiliar2 = NULL;
    if(a != NULL && b != NULL)
    {
        auxiliar = (eMascota*) a;
        auxiliar2 = (eMascota*)b;
        if(auxiliar->edad > auxiliar2->edad)
        {
            todoOk = 1;
        }
        else if(auxiliar->edad < auxiliar2->edad)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int cmp_SexoMascota(void* a, void* b)
{
    int todoOk= 0;
    eMascota* auxiliar = NULL;
    eMascota* auxiliar2 = NULL;
    if(a != NULL && b != NULL)
    {
        auxiliar = (eMascota*) a;
        auxiliar2 = (eMascota*)b;
        if(auxiliar->sexo > auxiliar2->sexo || (auxiliar2->sexo == auxiliar->sexo))
        {
            todoOk = 1;
        }
        else if(auxiliar->sexo < auxiliar2->sexo || (auxiliar2->sexo == auxiliar->sexo))
        {
            todoOk = -1;
        }
    }
    return todoOk;
}


































