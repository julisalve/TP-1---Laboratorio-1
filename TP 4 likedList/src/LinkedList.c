#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this =malloc(sizeof(LinkedList));
    this->size =0;
    this->pFirstNode =NULL;
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;
	if(this!=NULL)
	{
		returnAux=this ->size;
	}
	return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int saltos;
	Node *pNodo=NULL;
	if(this!=NULL && nodeIndex>=0 && nodeIndex<this -> size)
	{
		pNodo = this ->pFirstNode;
		for(saltos=0;saltos<nodeIndex;saltos++)
		{
			pNodo = pNodo->pNextNode;
		}
	}
	return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	Node * pNodo;
	Node *pNodoAnterior;
	if(this!=NULL && nodeIndex>=0 && nodeIndex <=this ->size)
	{
		pNodo=malloc(sizeof(pNodo));
		if(pNodo==NULL)
		{
			returnAux= -1;
		}
		else
		{
			returnAux=0;
			this->size++;
			pNodo->pElement = pElement;
			if(nodeIndex==0)
			{
				pNodo ->pNextNode = this ->pFirstNode;
				this ->pFirstNode = pNodo;
			}
			else
			{
				pNodoAnterior = getNode(this,nodeIndex-1);
				pNodo->pNextNode = pNodoAnterior->pNextNode;
				pNodoAnterior->pNextNode =pNodo;
			}
		}
	}
	return returnAux;
}




/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int nodeIndex=ll_len(this);//this->size;
    if(this!=NULL)
    {
    	if(addNode(this,nodeIndex,pElement)==0)
    	{
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	void* returnAux = NULL;
	Node* pNodo;
	if(this!=NULL && index>=0 && index<this->size)
	{
		pNodo=getNode(this, index);
		returnAux=pNodo->pElement;
	}
	return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodo;
    if(this!=NULL && index>=0 && index<this ->size)
    {
    	pNodo=getNode(this, index);
    	pNodo->pElement=pElement;
    	returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int returnAux = -1;
	Node*pNodo;
	Node *pNodoAnterior;
	if(this!=NULL && index>=0 && index<ll_len(this))//this ->size
	{
		pNodo=getNode(this,index);
		pNodoAnterior=getNode(this,index-1);
		if(pNodo!=NULL)
		{
			this->size--;
			if(index==0)
			{
				this ->pFirstNode = pNodo->pNextNode;
				free(pNodo);
			}
			else
			{
				pNodoAnterior->pNextNode=pNodo->pNextNode;
				free(pNodo);
			}
			returnAux=0;
		}
	}
	return returnAux;
}




/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int returnAux = -1;
	int index;
	if(this!=NULL)
	{
		for(index=0;index>ll_len(this);index++)
		{
			ll_remove(this, index);
		}
		this->size=0;
		returnAux=0;
	}
	return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;
    if(this!=NULL)
    {
    	for(index=0;index<ll_len(this);index++)
    	{
    		if(ll_get(this,index)==pElement)
    		{
    			returnAux = index;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
	int returnAux = -1;
	if(this!=NULL)
	{
		if(ll_len(this)>0)
		{
			returnAux=0;
		}
		else if (ll_len(this)==0)
		{
			returnAux=1;
		}
	}
	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int returnAux = -1;
	if(this!=NULL && index>=0 && index<=ll_len(this))//this->size
	{
		if(addNode(this,index,pElement)==0)
		{
			returnAux=0;
		}
	}
	return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node *pNodo;
    if(this!=NULL && index>=0 && index<this->size)
    {
    	pNodo=getNode(this, index);
		returnAux=pNodo->pElement;
		ll_remove(this,index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	int index;
	if(this!=NULL )
	{
		index=ll_indexOf(this,pElement);
		if(index==-1)
		{
			returnAux=0;
		}
		else
		{
			returnAux=1;

		}
	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2si los elementos de () estan contenidos en la lista (this)
                        ( 0) this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;
	int index;
	if(this!=NULL && this2!=NULL)
	{
		returnAux=1;
		for(index=0;index<ll_len(this2);index++)
		{
			if(ll_contains(this,ll_get(this2,index))==0)
			{
				returnAux=0;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int index;
    if(this!=NULL && from>=0 && to>=0 && from<=ll_len(this) && to<=ll_len(this) && from<=to)
    {
    	cloneArray=ll_newLinkedList();
    	for(index=from;index<to;index++)
    	{
    		ll_add(cloneArray,ll_get(this,index));
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
	LinkedList* cloneArray = NULL;
	if(this!=NULL)
	{
		cloneArray=ll_newLinkedList();
		cloneArray=ll_subList(this,0,ll_len(this));
	}
	return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux =-1;
	int i;
	//int j;
	Node* pElement1;
	Node* pElement2;
	Node* bElement;
	int flag;
	if(this!=NULL && pFunc !=NULL && (order==1 || order==0))
	{
		do
		{
		flag=0;
		for(i=0;i<ll_len(this)-1;i++)
		{
			pElement1= ll_get(this,i);
			pElement2= ll_get(this,i+1);
			if(order==1 && pFunc(pElement1, pElement2)==1) // ascendente
			{
				bElement=pElement1;
				pElement1=pElement2;
				pElement2=bElement;
				flag=1;
			}
			else if(order==0 && pFunc(pElement1, pElement2)==-1)
			{
				bElement=pElement1;
				pElement1=pElement2;
				pElement2=bElement;
				flag=1;
			}
			ll_set(this,i,pElement1);
			ll_set(this,i+1,pElement2);
		}
		}while(flag==1);
		returnAux=0;
	}
	return returnAux;
}




///** \brief Mapea los elementos de la lista utilizando la funcion criterio recibida como parametro
// * \param pList LinkedList* Puntero a la lista
// * \param pFunc (*pFunc) Puntero a la funcion criterio
// * \param
// * \return int Retorna  (-1) Error: si el puntero a la listas o la funcion criterio  es NULL
//                                ( 0) Si ok
// */
//int ll_map(LinkedList * this, void(*pFunc)(void*))
//{
//	int retorno =-1;
//	int i;
//	Node* pElement1;
//	if(this!=NULL && pFunc!=NULL)
//	{
//		printf("ll map");
//		for(i=0;i<ll_len(this);i++)
//		{
//			pElement1=ll_get(this,i);
//
//			pFunc(pElement1);
//			ll_set(this,i,pElement1);
//		}
//		retorno=0;
//	}
//	return retorno;
//}
//
///** \brief Filtra los elementos de la lista utilizando la funcion criterio recibida como parametro, creando una lista nueva
// * \param pList LinkedList* Puntero a la lista
// * \param pFunc (*pFunc) Puntero a la funcion criterio , la cual devuelve 1 si cumple con la condicion, o -1 si no la cumple
// * \param
// * \return int Retorna  la lista nueva filtrada
// */
//
//LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void*))
//{
//	int i;
//	LinkedList* listaFiltrada =NULL;
//	Node*pElement1;
//	if(this!=NULL && pFunc!=NULL)
//	{
//		listaFiltrada=ll_newLinkedList();
//		for(i=0;i<ll_len(this);i++)
//		{
//			pElement1=ll_get(this,i);
//			if(pFunc(pElement1)==1)
//			{
//				ll_add(listaFiltrada,pElement1);
//			}
//		}
//	}
//	return listaFiltrada;
//}
//
//
///** \brief Reduce los elementos de la lista utilizando la funcion criterio recibida como parametro, reduciendo la lista original
// * \param pList LinkedList* Puntero a la lista
// * \param pFunc (*pFunc) Puntero a la funcion criterio , la cual devuelve 1 si cumple con la condicion, o -1 si no la cumple
// * \param
// * \return int Retorna  la lista reducida
// */
//LinkedList* ll_reduce(LinkedList *this, int (*pFunc)(void*))
//{
//	int i;
//	Node* pElement1;
//	int cantidad;
//	if(this!=NULL && pFunc!=NULL)
//	{
//		cantidad=this->size;
//		for(i=0;i<cantidad;i++)
//		{
//			pElement1=ll_get(this,i);
//			if(pFunc(pElement1)==-1)
//			{
//				ll_remove(this,i);
//				this->size --;
//			}
//		}
//	}
//	return this;
//}
//
//
///** \brief Cuenta los elementos de la lista utilizando la funcion criterio recibida como parametro
// * \param pList LinkedList* Puntero a la lista
// * \param pFunc (*pFunc) Puntero a la funcion criterio , la cual devuelve 1 si cumple con la condicion, o -1 si no la cumple
// * \param
// * \return int Retorna  el contador
// */
//int ll_contar(LinkedList * this, int(*pFunc)(void*))
//{
//	int retorno =-1;
//	int i;
//	int contador=0;
//	Node* pElement1;
//	if(this!=NULL && pFunc!=NULL)
//	{
//		for(i=0;i<ll_len(this);i++)
//		{
//			pElement1=ll_get(this,i);
//			if(pFunc(pElement1)==1)
//			{
//				contador++;
//			}
//		}
//		retorno=contador;
//	}
//	return retorno;
//}

