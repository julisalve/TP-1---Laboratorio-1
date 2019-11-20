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

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void); //crea una lista nueva devuelvo un puntero a linkçed list
int ll_len(LinkedList* this);// se llama etodo el tiempo proque es dinamico
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);// this es el CONTEXTO. sçrecibe como parametro el contexto.. se agrega uno mas al final.
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement); // a la lista de empelados a una posicion en particular pone un elemento. Tieneq eu existir la lista de empleados y la posicion y le paso un elemento. se puede usar en un ordenar para intercambiar posiciones.
int ll_remove(LinkedList* this,int index);// recibe un indez y lo hace desaparcer. El index debe existir. Borra un elemento hace qeu el linkedlist tenga u nuevo tamaño y se modifican las posiciones de la lista. se elimino el 4, lo que estaba en el 5 pasa al 4
int ll_clear(LinkedList* this);// resetea etodo el linked lst. DEja a linkedlist en la misma condicion cuando hicimos el new, esta construido pero sin elemets.. queda sontruido pero vacio. Hace desaparecer un nodo. Primero se debe recrrer el linkedlist y llamar por cada elemento del linkedlist llamar al destructor de cada empelado y despues pasar a clear linked list, sino quedan como zombies los elementos, no se puede acceder epero ocupan lugar en memori.
int ll_deleteLinkedList(LinkedList* this);// hace un clear y despues un free.
int ll_indexOf(LinkedList* this, void* pElement);// recorre el linkedlist y se fija si por cada elemento si ese elemtno en particular le coincide con lo que le paaste como pelement. Si coinicde devueelve el indice.
int ll_isEmpty(LinkedList* this); //dice que no tiene elementos ese linked list. Verdadero si esta vacio.
int ll_push(LinkedList* this, int index, void* pElement);// permite definir donde queeres agregar un elemento. Si lo agregas al final es como usar un add. Peroe sta funcion permite elegir en donde agregar. Primero conviene hacer esta funcion y luego el add ya que es un punto en particular.
void* ll_pop(LinkedList* this,int index);// engloba dos funciones (un get y un remove). Si hay algun elemnto que genera algun grado de interes y ante d eborrarlo quiero hacer algo con ese elemento. Me devuele el puntero de un empleado y lo saca de la lista. HAce las dos cosas a la vez
int ll_contains(LinkedList* this, void* pElement);//  dice verdadero o falso si un elemento esta en la lista. NO devuelve le index. Sirve par prevenir agregar duplciados.
int ll_containsAll(LinkedList* this,LinkedList* this2);//presgunta si son todoss los elementos contenidos. NO analiza un elemento en particular, sino que los elemntos de la lista 2 estan en la lista 1. Si la lista 2 es un subconjunto de la lista 1.
LinkedList* ll_subList(LinkedList* this,int from,int to);// permite generar una lisat nueva desde una lista existente, dandole elemento en particular. Por jemplo cuando paginas
LinkedList* ll_clone(LinkedList* this);// clono la lista por ejemplo pra tener distintos criterios de ordenamiento. ES un caso partiucular del sublist. de la posicion 0 a la n.
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//recibe el contexto y un punter a una funcion. funcion que contiene al algorito de ordenamiento. lo unico que cmabia es el criterio de ordenamiento, DEbe permitir cambios a los tipos de elementos. PUntero a ufncion, se le pasa al ordenar un puntero a una funcion que esta desarrollado para un caso en aprticualr. Esa funcion se le pasa dos elementos. la funcion criterio es la que sabe a que se refiere (a empleado,a banan, o a autos) recibe 2 empelados o dos autos , se fja si es mas alto y devuelve 1, -1 o 0.


int ll_map(LinkedList * this, void(*pFunc)(void*));
LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void*));
LinkedList* ll_reduce(LinkedList *this, int (*pFunc)(void*));
int ll_contar(LinkedList * this, int(*pFunc)(void*));


// ademas vamos a constuir otras funciones, por ejemplo imprimir lista. o si quiero que los elementos aumenten u 10% todos. SE le pasa a la funcion criterio un solo elemento.O criterio selectivo de eliminacion de elementos. Filter (para filtrar cn un cierto parametro)
