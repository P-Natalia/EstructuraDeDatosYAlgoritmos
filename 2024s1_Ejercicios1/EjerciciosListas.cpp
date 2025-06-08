#include "EjerciciosListas.h"

NodoLista* invertirParcial(NodoLista* l)
{

        // Si la lista de entrada es nula o tiene solo un elemento (el último), devuelve null, ya que no hay elementos para invertir.
        if (l == NULL || l->sig == NULL) {
            return NULL;
        }

        NodoLista* listaInvertida = NULL; // InicializO la lista invertida como vacía

        // RecorrO la lista original hasta que sea nula
        while (l != NULL) {
            NodoLista* nodoNuevo = new NodoLista; // CreO un nuevo nodo
            nodoNuevo->dato = l->dato; // CopiO el dato del nodo original

            // InsertO el nuevo nodo al principio de la lista invertida
            nodoNuevo->sig = listaInvertida;
            listaInvertida = nodoNuevo;

            l = l->sig; // AvanzO al siguiente nodo en la lista original
        }

        // EliminO el último nodo de la lista invertida
        NodoLista* aux = listaInvertida;
        listaInvertida = listaInvertida->sig;
        delete aux;

        return listaInvertida;
  }



void eliminarNesimoDesdeElFinal(NodoLista*& lista, int& n)
{
     
            // Casos base: lista vacía o n es menor que 1
            if (lista == NULL || n < 1) {
                return;
            }

        // RecorrO la lista recursivamente hasta el final
        eliminarNesimoDesdeElFinal(lista->sig, n);

        // Una vez que llego al final, decremento n
        n--;

        // Si n llega a 0, elimino el nodo actual
        if (n == 0) {
            NodoLista* nodoAEliminar = lista;
            lista = lista->sig;
            delete nodoAEliminar;
        }
        
  


    }

/*
Esta función elimina el n-ésimo elemento desde el final de la lista de forma recursiva. Cada llamada recursiva avanza al siguiente nodo hasta llegar al final de la lista.
Luego, comienza a decrementar n. Una vez que n llega a 0, elimina el nodo actual, que es el n-ésimo desde el final.
comentario: se modifican los punteros de los nodos, por lo que se pasa una referencia al puntero de la lista (NodoLista*& lista).
Esto deja que los cambios en la lista sean visibles fuera de la función.
*/
    
    




// Insertar de manera ordenada un elemento en una lista ordenada
void insOrd(int e, NodoLista*& l) {
    if (l == nullptr || e <= l->dato) {
        // Caso base: si la lista está vacía o el elemento es menor o igual al primer elemento,
        // inserto el nodo al principio de la lista
        NodoLista* nuevoNodo = new NodoLista(e);
        nuevoNodo->sig = l;
        l = nuevoNodo;
    }
    else {
        // Busco la posición correcta para insertar el elemento en la lista ordenada
        insOrd(e, l->sig);
    }
}
NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
 // Algoritmo Insertion Sort para ordenar una lista enlazada
 NodoLista* listaOrdenada = NULL; // Lista ordenada que se irá construyendo
// Recorremos la lista original
        while (l != NULL) {
            // Inserto el elemento actual de la lista original en la lista ordenada
            insOrd(l->dato, listaOrdenada);
            l = l->sig; // Avanzo al siguiente nodo en la lista original
        }

        return listaOrdenada;
    }

// la función insOrd se encarga de insertar de manera ordenada un elemento en una lista ordenada (diapositiva del teorico)
// uso esta función en la función listaOrdenadaInsertionSort para implementar el algoritmo Insertion Sort sobre la lista enlazada que recibi como entrada.


void listaOrdenadaSelectionSort(NodoLista*& l)
{
    if (l == NULL || l->sig == NULL) {
        // Si la lista está vacía o tiene solo un elemento, ya está ordenada
        return;
    }

    NodoLista* punteroLista = l; // Puntero para recorrer la lista original

    while (punteroLista != NULL) {
        NodoLista* nodoValMin = punteroLista; // Nodo con el valor mínimo inicialmente es el actual

        // Busco el nodo con el valor mínimo entre los nodos restantes
        NodoLista* aux = punteroLista->sig;
        while (aux != NULL) {
            if (aux->dato < nodoValMin ->dato) {
                nodoValMin = aux;
            }
            aux = aux->sig;
        }

        // Intercambio los datos entre el nodo actual y el nodo con el valor mínimo
        int datosAux = punteroLista->dato;
        punteroLista->dato = nodoValMin->dato;
        nodoValMin->dato = datosAux;

        // Avanzo al siguiente nodo en la lista original
        punteroLista = punteroLista->sig;
    }
}
/*
 itero sobre la lista original y en cada iteración busco el nodo con el valor mínimo entre los nodos restantes. 
 intercambio los datos entre el nodo actual y el nodo con el valor mínimo.  avanzo al siguiente nodo en la lista original.
 repito esto hasta que alcanzo el final de la lista. 
*/

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
    NodoLista* resultado = new NodoLista(); // Nodo cabeza de la lista resultante
    NodoLista* actual = resultado; // Puntero para recorrer la lista resultante

    // Iteradores para recorrer ambas listas
    NodoLista* iter1 = l1;
    NodoLista* iter2 = l2;

    // Construir la lista resultante
    while (iter1 != NULL || iter2 != NULL) {
        if (iter1 == NULL) {
            actual->sig = new NodoLista(iter2->dato);
            iter2 = iter2->sig; // Avanzar en la lista 2
        }
        else if (iter2 == NULL) {
            actual->sig = new NodoLista(iter1->dato);
            iter1 = iter1->sig; // Avanzar en la lista 1
        }
        else {
            if (iter1->dato < iter2->dato) {
                actual->sig = new NodoLista(iter1->dato);
                iter1 = iter1->sig; // Avanzar en la lista 1
            }
            else {
                actual->sig = new NodoLista(iter2->dato);
                iter2 = iter2->sig; // Avanzar en la lista 2
            }
        }
        actual = actual->sig; // Avanzar en la lista resultante
    }

    // Guardar el primer elemento de la lista resultante (el nodo cabeza no contiene datos)
    NodoLista* temp = resultado;
    resultado = resultado->sig;
    delete temp;

    return resultado;
}


//intercalar recursivo


// Función interna para copiar una lista
NodoLista* copia(NodoLista* l) {
    if (l == NULL) {
        return NULL;
    }
    else {
        NodoLista* res = new NodoLista;
        res->dato = l->dato;
        res->sig = copia(l->sig);
        return res;
    }
}
NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2) {
    

    // Casos base: si una de las listas es NULL, se devuelve la otra lista
    if (l1 == NULL) {
        return copia(l2);
    }
    if (l2 == NULL) {
        return copia(l1);
    }

    NodoLista* resultado = NULL;

    // Comparar los valores de los nodos y asignar el menor al nodo resultante
    if (l1->dato <= l2->dato) {
        resultado = new NodoLista(l1->dato);
        resultado->sig = intercalarRec(l1->sig, l2);
    }
    else {
        resultado = new NodoLista(l2->dato);
        resultado->sig = intercalarRec(l1, l2->sig);
    }

    return resultado;
}








NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}


/*
Ambas listas son nulas.
Una lista es nula y la otra no.
Ambas listas contienen elementos únicos.
Ambas listas contienen elementos repetidos.
Una lista contiene elementos únicos y la otra contiene elementos repetidos.
Una lista contiene elementos únicos y la otra no contiene elementos.
Ambas listas son idénticas.
*/



NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
    NodoLista* cabeza = new NodoLista(); // Nodo cabeza de la lista resultante
    NodoLista* actual = cabeza; // Puntero para recorrer la lista resultante

    // Iteradores para recorrer ambas listas
    NodoLista* iter1 = l1;
    NodoLista* iter2 = l2;

    // Recorro ambas listas hasta que al menos una de ellas se haya recorrido completamente
    while (iter1 != NULL || iter2 != NULL) {
        if (iter1 != NULL && (iter2 == NULL || iter1->dato < iter2->dato)) {
            // Si quedan elementos en la lista 1 o no quedan en la lista 2, añado el elemento de la lista 1
            if (actual->dato != iter1->dato) {
                actual->sig = new NodoLista(iter1->dato);
                actual = actual->sig; // Avanzo en la lista resultante
            }
            iter1 = iter1->sig; // Avanzo en la lista 1
        }
        else if (iter2 != NULL && (iter1 == NULL || iter2->dato < iter1->dato)) {
            // Si quedan elementos en la lista 2 o no quedan en la lista 1, añado el elemento de la lista 2
            if (actual->dato != iter2->dato) {
                actual->sig = new NodoLista(iter2->dato);
                actual = actual->sig; // Avanzo en la lista resultante
            }
            iter2 = iter2->sig; // Avanzo en la lista 2
        }
        else {
            // Ambos elementos son iguales, avanzamos en ambas listas
            int valorComun = iter1->dato; // Guardo el valor común
            while (iter1 != NULL && iter1->dato == valorComun) {
                iter1 = iter1->sig; // Avanzo en la lista 1
            }
            while (iter2 != NULL && iter2->dato == valorComun) {
                iter2 = iter2->sig; // Avanzo en la lista 2
            }
        }
    }

    // Guardo el primer elemento de la lista resultante (el nodo cabeza no contiene datos)
    NodoLista* resultado = cabeza->sig;
    delete cabeza; // Elimino el nodo cabeza

    return resultado;
}



void eliminarNodo(NodoLista*& l, NodoLista* nodo) {
    if (nodo == NULL) return;
    if (l == nodo) {
        l = l->sig;
    }
    else {
        NodoLista* temp = l;
        while (temp != NULL && temp->sig != nodo) {
            temp = temp->sig;
        }
        if (temp != NULL) {
            temp->sig = nodo->sig;
        }
    }
    delete nodo;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
    if (l == NULL || l->sig == NULL) return;

    NodoLista* actual = l; // Nodo actual
    NodoLista* siguiente = l->sig; // Nodo siguiente

    // Verificar si hay un nodo duplicado
    if (actual->dato == siguiente->dato) {
        while (siguiente != NULL && actual->dato == siguiente->dato) {
            NodoLista* temp = siguiente; // Nodo duplicado a eliminar
            siguiente = siguiente->sig; // Avanzo al siguiente nodo
            delete temp; // Elimino el nodo duplicado
        }
        l = siguiente; // Actualizo el inicio de la lista
        eliminarDuplicadosListaOrdenadaDos(l); // Llamo recursivamente para manejar más duplicados
    }
    else {
        // No hay duplicados en el inicio
        eliminarDuplicadosListaOrdenadaDos(siguiente); // Llamo recursivamente para el resto de la lista
        actual->sig = siguiente; // Reconstruyo la lista
    }
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}




void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
    if (l == NULL || secuencia == NULL) return;

    NodoLista* actual = l;
    NodoLista* prev = NULL;

    //  iterao sobre la lista l mientras actual no sea NULL. Esto sirve para recorrer toda la lista en busca de la secuencia que quiero eliminar.

    while (actual != NULL) {
        
        //Encontramos el primer elemento de la secuencia cuando actual->dato == secuencia->dato.
        // Si este es el caso, inicio un bucle para comparar los elementos de la lista con los de la secuencia.
        if (actual->dato == secuencia->dato) {
            NodoLista* tempActual = actual;
            NodoLista* tempSecuencia = secuencia;
            bool secuenciaCompleta = true;

            // Avanzo a través de la lista (tempActual) y de la secuencia (tempSecuencia) mientras ambos no sean NULL.
            // Comparamos los elementos de la lista con los de la secuencia
            while (tempActual != NULL && tempSecuencia != NULL) {
                if (tempActual->dato != tempSecuencia->dato) {
                    //En cada iteración, verifico si los datos de los nodos son iguales. Si son diferentes, pongo secuenciaCompleta en false y salgo del bucle.
                    secuenciaCompleta = false;
                    break;
                }
                tempActual = tempActual->sig;
                tempSecuencia = tempSecuencia->sig;
            }
            // si secuenciaCompleta es true y si tempSecuencia es NULL entonces ya recorri toda la secuencia y todos los elementos coinciden.
            // Si la secuencia está completa, la elimino
            if (secuenciaCompleta && tempSecuencia == NULL) {
                if (prev == NULL) {
                    l = tempActual; // Actualizo el inicio de la lista
                }
                else {
                    prev->sig = tempActual; 
                }

                // Elimino los nodos de la secuencia
                while (actual != tempActual) {
                    NodoLista* eliminar = actual;
                    actual = actual->sig;
                    delete eliminar;
                }

                // Después de eliminar los nodos de la secuencia, reinicio actual y secuencia para reiniciar la búsqueda desde el inicio de la lista y de la secuencia
                // (Reinicio actual y secuencia para que vuelvan al inicio de la lista y de la secuencia)
                actual = l;
                secuencia = secuencia;
                prev = NULL; // Reinicio prev porque ya elimine los nodos
            }
        }

        // Avanzo al siguiente nodo  en la lista seguir buscando repeticiones de la secuencia.
        if (actual != NULL) {
            prev = actual;
            actual = actual->sig;
        }
    }
}




void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}

//autor: Natalia Peña
// numero de estudiante: 242466
//materia: estructura de datos y algoritmos 1