#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Paciente.h"


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
    LinkedList* list = malloc(sizeof(LinkedList));

    if(list != NULL)
    {
        list->pFirstNode = NULL;
        list->size = 0;
    }


    return list;
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

    if(this != NULL)
    {
        returnAux = this->size;
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
    Node* auxNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        auxNode = this->pFirstNode;

        for(int i=0; i<nodeIndex; i++)
        {
            auxNode = auxNode->pNextNode;
        }
    }

    return auxNode;
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
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node* newNode = NULL;
    Node* preNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        newNode = malloc(sizeof(Node));

        if(newNode != NULL)
        {
            newNode->pElement = pElement;
            newNode->pNextNode = NULL;
            if(nodeIndex == 0)
            {
                newNode->pNextNode = this->pFirstNode;
                this->pFirstNode = newNode;
            }
            else
            {
                preNode = getNode(this, nodeIndex-1);
                newNode->pNextNode = preNode->pNextNode;
                preNode->pNextNode = newNode;

            }
            this->size++;
            returnAux = 0;
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

    if(this != NULL)
    {
        if(!addNode(this, ll_len(this), pElement))
        {
            returnAux = 0;
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
    Node* auxNode = NULL;

    if(this != NULL && index >= 0 && index <ll_len(this))
    {
        auxNode = getNode(this, index);
        if(auxNode != NULL)
        {
            returnAux = auxNode->pElement;
        }
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
    Node* auxNode = NULL;

    if(this != NULL && index >= 0 && index <ll_len(this))
    {
        auxNode = getNode(this, index);
        if(auxNode != NULL)
        {
            auxNode->pElement = pElement;
            returnAux = 0;
        }
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
    Node* remNode = NULL;
    Node* preNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        remNode = getNode(this, index);
        if(remNode != NULL)
        {
            if(index == 0)
            {
                this->pFirstNode = remNode->pNextNode;
                free(remNode);
                this->size--;
                returnAux = 0;
            }
            else
            {
                preNode = getNode(this, index-1);
                if(preNode != NULL)
                {
                    preNode->pNextNode = remNode->pNextNode;
                    free(remNode);
                    this->size--;
                    returnAux = 0;
                }
            }
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

    if(this != NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            ll_remove(this, i);
        }
        if(ll_len(this) == 0)
        {
            returnAux = 0;
        }
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
    if(this != NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            returnAux = 0;
        }
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
    Node* auxNode = NULL;

    if(this != NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            auxNode = getNode(this, i);
            if(auxNode != NULL && auxNode->pElement == pElement)
            {
                returnAux = i;
                break;
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

    if(this != NULL)
    {
        if(ll_len(this) == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
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
    return addNode(this, index, pElement);
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

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        returnAux = ll_get(this, index);
        if(ll_remove(this, index))
        {
            returnAux = NULL;
        }
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
    Node* auxNode = NULL;

    if(this != NULL)
    {
        returnAux = 0;
        for(int i=0; i<ll_len(this); i++)
        {
            auxNode = getNode(this, i);
            if(auxNode->pElement == pElement)
            {
                returnAux = 1;
                break;
            }
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
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* auxElement = NULL;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(int i=0; i<ll_len(this2); i++)
        {
            auxElement = ll_get(this2, i);
            if(ll_contains(this, auxElement) != 1)
            {
                returnAux = 0;
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

    if(!(this == NULL || from<0 || from > ll_len(this) || to <= from || to > ll_len(this)))
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(int i=from; i<to; i++)
            {
                ll_add(cloneArray, ll_get(this, i));
            }
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

    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, ll_len(this));
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
    void* auxElement;
    int size;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        size = ll_len(this);
        for(int i=0; i < size-1; i++)
        {
            for(int j=i+1; j < size; j++)
            {
                if( (pFunc(ll_get(this, i), ll_get(this, j)) > 0 && order) || (pFunc(ll_get(this, i), ll_get(this, j)) < 0 && !order))
                {
                    auxElement = ll_get(this, i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, auxElement);
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;

}

/** \brief Crea una nueva LL y mapea los datos de la LL recibida, para luego devolverla completa
 *
 * \param Recibe la LL
 * \param Recibe el puntero a funcion que llamara en el desarrollo
 * \return Retorna una nueva LL con los datos mapeados
 *
 */

LinkedList* ll_map(LinkedList* this, void* (*pFunc)(void*))
{
    LinkedList* mapeado = NULL;
    void* auxElement;
    int size;

    if(this != NULL && pFunc != NULL)
    {
        mapeado = ll_newLinkedList();
        if(mapeado != NULL)
        {
            size = ll_len(this);
            for(int i=0; i < size-1; i++)
            {
                auxElement = ll_get(this, i);
                auxElement = (void*) pFunc(auxElement);
                if(auxElement != NULL)
                {
                    ll_add(mapeado, auxElement);
                }
            }
        }
    }

    return mapeado;
}

/** \brief Crea una nueva LL y filtra los datos de la LL recibida, para luego devolverla filtrada
 *
 * \param Recibe la LL
 * \param Recibe el puntero a funcion que llamara en el desarrollo
 * \return Retorna una nueva LL con los datos filtrados por la funcion
 *
 */

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* listaFiltrada = NULL;
    void* auxElement = NULL;

    if(this != NULL && pFunc != NULL)
    {
        listaFiltrada = ll_newLinkedList();
        if(listaFiltrada != NULL)
        {
            for(int i=0; i<ll_len(this); i++)
            {
                auxElement = ll_get(this, i);
                if(auxElement != NULL && pFunc(auxElement))
                {
                    ll_add(listaFiltrada, auxElement);
                }
            }
        }
    }

    return listaFiltrada;
}
