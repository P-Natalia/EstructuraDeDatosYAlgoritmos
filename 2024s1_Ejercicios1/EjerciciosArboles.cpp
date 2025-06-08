#include "EjerciciosArboles.h"

/*

 Def.
La altura de un árbol es:
la cantidad de niveles que tiene, o la cantidad de nodos en el camino más largo de la raíz a una hoja.
La altura del árbol binario vacío es 0
altura (()) = 0
altura ((izq,t,der)) = 1 + max(altura(izq), altura(der))

 */

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int altura(NodoAB* raiz) {
	if (raiz == NULL) {
		return 0;
	}
	else {
		int alturaIzq = altura(raiz->izq);
		int alturaDer = altura(raiz->der);
		return 1 + max(alturaIzq, alturaDer);
	}
}

/*
si el arbol p es vacio pero el arbol q no, entonces no son iguales
si el arbol q es vacio pero p no, entonces no son iguales
if ((p && q) == NULL) { return false; }
si el sub arbol izquierdo de p es vacio pero el subarbol izquierdo de q no, entonces no son iguales
if ((p->izq == NULL) && (q->izq != NULL)) {return false;}
si el sub arbol izquierdo de q es vacio pero el subarbol izquierdo de p no, entonces no son iguales
if ((p->izq != NULL) && (q->izq == NULL)) {return false;}
si el sub arbol derecho de p es vacio pero el subarbol derecho de q no, entonces no son iguales
if ((p->der == NULL) && (q->der != NULL)) {return false;}
si el sub arbol derecho de q es vacio pero el subarbol derecho de p no, entonces no son iguales
if ((p->der != NULL) && (q->der == NULL)) {return false;}
comparo  ambos arboles, deben ser iguales.
son iguales si ambos arboles son vacios.
comparo las raices. si los datos de las raices no son iguales, entonces devuelvo false.
comparo recursivamente los sub arboles.
sub arbol izquierdo de p debe ser igual a sub arbol izquierdo de q
al mismo tiempo sub arbol derecho de p debe ser igual al sub arbol derecho de q.

*/



bool sonIguales(NodoAB* p, NodoAB* q) {
	// caso: ambos arboles vacios, son iguales
	if (p == NULL && q == NULL) {
		return true;
	}
	// caso: solo uno de los nodos es NULL. no son iguales
	if (p == NULL || q == NULL) {
		return false;
	}
	// comparo raices para ver si tienen el mismo dato
	if (p->dato != q->dato) {
		return false;
	}
	//  comparo los subárboles izquierdo y derecho recursivamente
	return sonIguales(p->izq, q->izq) && sonIguales(p->der, q->der);
}

/*
recibo un arbol y un entero por copia ya que no voy a querer modificar el arbol y dejar alli la suma.
mi algoritmo debe distinguir que es hoja y que no es hoja, porque con llegar a NULL no basta para decir que llegue a la hoja.
casos a considerar:
si el arbol es vacio:
si sum es 0 da true, si sum no es 0 da false.
caso t == NULL, retun sum == 0
si el arbol no es vacio:
pregunto si el nodo es hoja o no es hoja.
ES HOJA SI:
t -> t == NULL
es decir,con t == NULL verifico si el puntero t apunta a la dirección de memoria NULL, lo cual me da a entender que es hoja ya que no hay a donde seguir.
si el sub arbol izq y el sub arbol der son nulos (izq == NULL && der == NULL) entonces estoy en caso hoja.
retorno t -> dato == sum, (sum es igual al valor que esta en el nodo).
NO ES HOJA:
si no es hoja entonces al menos uno de los sub-arboles no es vacio.
o el sub arbol izq es vacio y el sub arbol der no lo es, o el sub arbol izq no es vacio y el sub arbol der si lo es.
quiero seguir recorriendo cuando hay al menos un camino:
si estoy en el caso que izq es vacio pero der no, llamo por der.
si estoy en el caso que der es vacio pero izq no, llamo por izq.
en resumen cuando hay un arbol vacio y otro no, voy por el que no esta vacio.
if (t -> izq != NULL ) return existeCaminoConSuma (t -> izq, sum - t -> dato);
else return existeCaminoConSuma (t-> der , sum -t -> dato);
caso ambos sub arboles no son vacios: hago recursiva
if (t -> izq != NULL && t-> der != NULL ) return existeCaminoConSuma (t -> izq, sum - t -> dato)  || (t-> der , sum -t -> dato)
*/
bool existeCaminoConSuma(NodoAB* raiz, int sum) {
	//  si el árbol es vacío, el camino no existe
	if (raiz == NULL) {
		return (sum == 0);
	}
	// a la suma le resto el valor del nodo actual (a sum le resto raiz->dato)
	int sumaAux = sum - raiz->dato;
	// Si es un nodo hoja y la suma es 0, retorna true
	if (raiz->izq == NULL && raiz->der == NULL && sumaAux == 0) {
		return true;
	}

	// Verifica si el nodo izquierdo no es nulo y realiza la llamada recursiva si es el caso
	if (raiz->izq != NULL) {
		if (existeCaminoConSuma(raiz->izq, sumaAux)) {
			return true;
		}
	}

	// Verifica si el nodo derecho no es nulo y realiza la llamada recursiva si es el caso
	if (raiz->der != NULL) {
		if (existeCaminoConSuma(raiz->der, sumaAux)) {
			return true;
		}
	}

	// Si no se encontró un camino válido, retorna falso
	return false;
}



bool esArbolBalanceado(NodoAB* raiz) {
	// Si el árbol está vacío, está balanceado
	if (raiz == NULL) {
		return true;
	}

	// calculo la altura de los subárboles izquierdo y derecho para despues ver la diferencia entre ambas
	int alturaIzq = altura(raiz->izq);
	int alturaDer = altura(raiz->der);

	//me interesa el caso en que la diferencia de aluras sea menor o igual 1.
	if ((alturaIzq >= alturaDer) && (alturaIzq - alturaDer) <= 1) {
		// pregunto recursivamente si el sub arbol izq y el sub arbol der es balanceado
		if (esArbolBalanceado(raiz->izq) && esArbolBalanceado(raiz->der)) {
			// de cumplirse ambas condiciones devuelvo True;
			return true;
		}

	}
	else if ((alturaIzq < alturaDer) && (alturaDer - alturaIzq) <= 1) {
		// pregunto recursivamente si el sub arbol izq y el sub arbol der es balanceado
		if (esArbolBalanceado(raiz->izq) && esArbolBalanceado(raiz->der)) {
			// de cumplirse ambas condiciones devuelvo True;
			return true;
		}

	}
	// Si alguna de las condiciones anteriores no se cumple, el árbol no está balanceado
	return false;
}


//Esta función es una función auxiliar utilizada por enNivel para realizar el recorrido del árbol y encontrar los nodos en el nivel k.
void enNivelUtil(struct NodoAB* nodo, int nivelActual, int k, struct NodoLista** lista) {
	//Recibe el nodo actual del árbol, el nivel actual en el que nos encontramos, el nivel k que estamos buscando y un puntero a la lista de nodos.
	if (nodo == NULL) {
		return;
	}

	if (nivelActual == k) {
		//Si el nivel actual coincide con el nivel k, agrega el valor del nodo a la lista de nodos.
		// Agregamos el nodo al final de la lista
		struct NodoLista* nuevoNodo = new NodoLista(nodo->dato);

		if (*lista == NULL) {
			*lista = nuevoNodo;
		}
		else {
			struct NodoLista* temp = *lista;
			while (temp->sig != NULL) {
				temp = temp->sig;
			}
			temp->sig = nuevoNodo;
		}
	}
	// llamo recursivamente a la función para los subárboles izquierdo y derecho, aumentando el nivel actual en uno en cada llamada.
	// Recorremos recursivamente los subárboles izquierdo y derecho:
	enNivelUtil(nodo->izq, nivelActual + 1, k, lista);
	enNivelUtil(nodo->der, nivelActual + 1, k, lista);
}
// Esta función recibe un árbol binario a y un entero k que representa el nivel que queremos obtener.
NodoLista* enNivel(NodoAB* a, int k) {
	//Comienzo verificando si el árbol a es nulo. En ese caso, retorna NULL, ya que no hay nodos en el nivel k
	struct NodoLista* lista = NULL;
	// invoco a la función auxiliar enNivelUtil, que se encarga de realizar el recorrido del árbol para encontrar los nodos en el nivel k.
	enNivelUtil(a, 1, k, &lista);
	return lista;
}

//Esta función recibe el árbol a y dos enteros desde y hasta que representan los niveles entre los cuales quiero contar los nodos.
int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	if (desde > hasta || desde < 1 || a == NULL) {
		//verifico si los niveles especificados son válidos (osea, desde <= hasta y desde >= 1).
		return 0;
	}
	//inicializo un contador en cero.
	int contador = 0;
	//Itero sobre todos los niveles desde desde hasta hasta
	for (int nivel = desde; nivel <= hasta; ++nivel) {
		//En cada iteración, llamo a la función enNivel para obtener la lista de nodos en el nivel actual y contar el número de nodos en esa lista.
		NodoLista* nodosEnNivel = enNivel(a, nivel);
		NodoLista* temp = nodosEnNivel;
		while (temp != NULL) {
			contador++;
			temp = temp->sig;
		}
	}

	return contador;
	//retorno el contador que representa la cantidad total de nodos entre los niveles desde y hasta.
}

// como voy a resolver el ejercicio "camino" con ABB de busqueda, necesito mantener un orden en los elementos de la lista:
// los elementos menores a la izquiera y los mayores a la derecha.
// lo que garantiza la propiedad de orden son los algoritmos que modifican el arbol (en este caso voy tener una funcion auxiliar para insertar elementos).

// Función auxiliar para insertar un nodo al inicio de la lista ( agregar un nuevo elemento antes de todos los demás nodos existentes en la lista)
void insertarAlInicio(NodoLista*& lista, int dato) {
	NodoLista* nodoInicial = new NodoLista(dato);
	//Se crea un nuevo nodo con el valor dato y se asigna a nodoInicial.
	nodoInicial->sig = lista;
	lista = nodoInicial;
}
//  actualizo el puntero de inicio de la lista para que apunte al nuevo nodo, y el nuevo nodo apunte al nodo que antes era el primero.
//  Esta inserción es eficiente, porque no necesito recorrer la lista para encontrar el último nodo, solo se actualizan los punteros.

// Función auxiliar para insertar un nodo al final de la lista (agregar un nuevo elemento después de todos los nodos existentes en la lista)
// (sirve para poder modificar la lista original si es necesario) 
//  dato  representa el valor que se desea agregar al final de la lista.
void insertarAlFinal(NodoLista*& lista, int dato) {
	NodoLista* nodoFinal = new NodoLista(dato);
	//Se crea un nuevo nodo con el valor dato y se asigna a nodoFinal.
	if (lista == NULL) {
		//Si la lista está vacía (osea, el puntero de inicio "lista" apunta a NULL), se asigna el nuevo nodo como el primer nodo de la lista.
		lista = nodoFinal;
	}
	else {
		//Si la lista no está vacía, recorro la lista hasta encontrar el último nodo, y se inserta el nuevo nodo después de este último nodo.
		NodoLista* temp = lista;
		while (temp->sig != NULL) {
			// recorro la lista hasta llegar al último nodo (osea,a el nodo cuyo puntero sig apunta a NULL).
			temp = temp->sig;
		}
		temp->sig = nodoFinal;
		//Una vez encontrado el último nodo, se actualiza el puntero sig del último nodo para que apunte al nuevo nodo, insertándolo al final de la lista.
	}
}
// recorro la lista hasta encontrar el último nodo, y luego actualizo el puntero del último nodo para que apunte al nuevo nodo.

NodoLista* camino(NodoAB* arbol, int x) {
	NodoLista* lista = NULL; // Inicializo la lista como vacía

	// Mientras el árbol no sea nulo y el valor del nodo actual no sea x
	while (arbol != NULL && arbol->dato != x) {
		//en cada iteración, inserto el valor del nodo actual al final de la lista (para mantener el orden del camino) y  avanzo hacia el subárbol izquierdo o derecho dependiendo de si x es mayor o menor que el valor del nodo actual.
		// (Inserto el valor del nodo actual al final de la lista)
		insertarAlFinal(lista, arbol->dato);

		// Si el valor del nodo actual es mayor que x, avanzo hacia el subárbol izquierdo

		if (arbol->dato > x) {
			arbol = arbol->izq;
		}
		// Si el valor del nodo actual es menor que x, avanzo hacia el subárbol derecho
		else {
			arbol = arbol->der;
		}
	}
	//al terminar el while, si el árbol no es nulo y el valor del nodo actual es igual a x, es porque encontre el nodo buscado.
	// En ese caso, inserto el valor del nodo actual al final de la lista.

	// Si el árbol no es nulo y el valor del nodo actual es x, lo inserto al final de la lista
	if (arbol != NULL && arbol->dato == x) {
		insertarAlFinal(lista, arbol->dato);
	}
	// retorno el puntero a la lista enlazada que representa el camino desde la raíz hasta el nodo con valor x.
	return lista;
}

NodoAB* invertirHastak(NodoAB* a, int k) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}




//funcion auxiliar minimo: me da el puntero al nodo minimo de un arbol
// minimo me va a retornar un puntero al nodo minimo de t. null si es vacio.

NodoAB* minimo(NodoAB* t) {
	if (t == NULL) return NULL;

	while (t->izq != NULL) {
		t = t->izq;
	}

	return t;
}

//La función eliminarNodo se encarga de eliminar un nodo específico con un valor dado del árbol binario de búsqueda. 
void eliminarNodo(NodoAB*& A, int dato) {
	// Caso base: si el árbol está vacío, no hay nada que eliminar
	if (A == NULL) {
		return;
	}
	/*
	-Si el valor a eliminar es menor que el valor del nodo actual:
	 Si el valor que quiero eliminar es menor que el valor del nodo actual, se que el nodo a eliminar se encuentra en el subárbol izquierdo.
	  Por lo tanto, llamamo recursivamente a eliminarNodo pasando el subárbol izquierdo como argumento.
	-Si el valor a eliminar es mayor que el valor del nodo actual:
	Si el valor que quiero eliminar es mayor que el valor del nodo actual, se que el nodo a eliminar se encuentra en el subárbol derecho.
	Por lo tanto, llamo recursivamente a eliminarNodo pasando el subárbol derecho como argumento.
	*/
	// Si el valor está en el subárbol izquierdo
	if (dato < A->dato) {
		eliminarNodo(A->izq, dato);
	}

	// Si el valor está en el subárbol derecho
	else if (dato > A->dato) {
		eliminarNodo(A->der, dato);
	}
	/*
	Cuando encuentro el nodo con el valor a eliminar:
		-Si el nodo es una hoja o tiene un solo nodo hhacia abajo, lo elimino.
		-Si el nodo tiene ambos sub arboles, encuentro el nodo mínimo en su subárbol derecho,
		copio su valor al nodo actual y luego llamo recursivamente a eliminarNodo para eliminar el nodo mínimo del subárbol derecho.
	esto lo hago de esa forma para garantizar que el árbol binario de búsqueda mantenga su propiedad de orden después de eliminar un nodo (ya sea el raíz o cualquier otro nodo.)
	*/

	// Si encuentro el nodo a eliminar
	else {
		// Si el nodo es una hoja o tiene un solo nodo hacia abajo, lo borro
		if (A->izq == NULL) {
			NodoAB* temp = A;
			A = A->der;
			delete temp;
		}
		else if (A->der == NULL) {
			NodoAB* temp = A;
			A = A->izq;
			delete temp;
		}
		// Si el nodo tiene ambos subarboles

		else {
			// Busco el nodo mínimo en el subárbol derecho
			NodoAB* min_A_der = minimo(A->der);
			// Copio los valores del nodo mínimo al nodo actual
			A->dato = min_A_der->dato;
			// Elimino el nodo mínimo del subárbol derecho
			eliminarNodo(A->der, min_A_der->dato);
		}
	}
}


//La función borrarNodoRaiz se encarga de eliminar el nodo raíz de un árbol binario de búsqueda manteniendo la propiedad de orden del árbol. 
void borrarNodoRaiz(NodoAB*& A) {
	// Caso base: si el árbol está vacío, no hay nada que eliminar
	if (A == NULL)
		return;

	// Si el subárbol derecho es nulo, reemplazo el nodo actual con el subárbol izquierdo
	if (A->der == NULL) {
		NodoAB* aBorrar = A;
		A = A->izq;
		delete aBorrar;
	}
	// Si el subárbol izquierdo es nulo, reemplazo el nodo actual con el subárbol derecho
	else if (A->izq == NULL) {
		NodoAB* aBorrar = A;
		A = A->der;
		delete aBorrar;
	}
	// Si el nodo actual tiene ambos subárboles
	else {
		// Busco el nodo mínimo en el subárbol derecho
		NodoAB* min_A_der = minimo(A->der);
		// Copio los valores del nodo mínimo al nodo actual
		A->dato = min_A_der->dato;
		// Elimino el nodo mínimo del subárbol derecho
		eliminarNodo(A->der, min_A_der->dato);
	}
}




bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n)
{
	if (a == NULL) return -1; // Caso base: árbol vacío. no hay nodos en el arbol por lo que retorno -1

	// Si el valor del nodo actual es igual a n, entonces busco el nodo mínimo en el subárbol derecho del nodo actual utilizando la función minimo definida mas arriba.
	// La función minimo es una función auxiliar que devuelve un puntero al nodo mínimo en un árbol binario de búsqueda. 
	//  valor del nodo actual igual a n :
	if (a->dato == n) {
		// Busco el nodo mínimo en el subárbol derecho
		NodoAB* minimoDer = minimo(a->der);

		// Si se encontró el nodo mínimo, retorno su valor
		if (minimoDer != NULL) return minimoDer->dato;
		else return -1; // Si no se encontró, retorno -1
	}
	// Si el valor del nodo actual es menor que n, busco en el subárbol derecho
	else if (a->dato < n) {
		return sucesor(a->der, n);
	}
	//  valor del nodo actual es mayor que n:
	/*
		Si el valor del nodo actual es mayor que n, entonces se que el sucesor de n podría estar en el subárbol izquierdo del nodo actual
		o el nodo actual podría ser el sucesor si no hay un número mayor en el subárbol izquierdo.
		Por lo tanto, llamo recursivamente a la función sucesor con el subárbol izquierdo
	*/
	else {

		int sucesorIzq = sucesor(a->izq, n);
		// Si se encuentra el sucesor en el subárbol izquierdo, lo devuelvo
		if (sucesorIzq != -1) return sucesorIzq;
		//si no se encuentra el sucesor en el subárbol izquierdo, devuelvo el valor del nodo actual.
		else return a->dato;
	}
}

int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	if (raiz == NULL) {
		return 0; // Árbol vacío
	}
	//nivel que tiene más nodos
	int nivelMasNodos = 0;
	//cantidad máxima de nodos
	int max = 0;

	//Itero desde el nivel 1 hasta el nivel nivelHasta.
	for (int nivel = 1; nivel <= nivelHasta; ++nivel) {
		//Para cada nivel, uso la función cantNodosEntreNiveles para contar la cantidad de nodos en ese nivel.
		int cantidadNodos = cantNodosEntreNiveles(raiz, nivel, nivel);
		//llevo un registro del nivel que tiene más nodos (nivelMasNodos) y la cantidad máxima de nodos (max) encontrados hasta ahora.
		if (cantidadNodos > max) {
			max = cantidadNodos;
			nivelMasNodos = nivel;
		}
	}

	return nivelMasNodos;
}

void borrarPares(NodoAB*& a) {
	// IMPLEMENTAR SOLUCION
}

int alturaAG(NodoAG* raiz)
{
	// IMPLEMENTAR SOLUCION
	return 0;
}

int sumaPorNiveles(NodoAG* raiz) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

bool esPrefijo(NodoAG* a, NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

NodoLista* caminoAG(NodoAG* arbolGeneral, int dato) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int nivelConMasNodosAG(NodoAG* arbolGeneral) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

//autor: Natalia Peña
// numero de estudiante: 242466
//materia: estructura de datos y algoritmos 1