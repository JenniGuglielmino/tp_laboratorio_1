#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct{
    int id;
    char nombre[20];
    int edad;
    char sexo;
}eMascota;

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

int main()
{
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
        printf("La lista no contiene este elemento!\n");
    }
    else if(!ll_contains(lista, &m5))
    {
        printf("La lista contiene al elemento\n");
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
    for(int i=0; i<ll_len(lista);i++)
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
