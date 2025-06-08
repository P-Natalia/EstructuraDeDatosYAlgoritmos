#include "EjerciciosComienzo.h"

int suma(int a, int b) {
 	// IMPLEMENTAR SOLUCION
    return 0;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {
 	// IMPLEMENTAR SOLUCION
}

void simplificar(int n, int d) {
	// IMPLEMENTAR SOLUCION
}

int ocurrencias123Repetidos(int* vector, int largo) {
        int ocurrencias = 0;

        // Iterar sobre el vector
        for (int i = 0; i < largo - 2; ++i) {
            // Verificar si el elemento actual es 1 y el siguiente es 2
            if (vector[i] == 1 && vector[i + 1] == 2) {
                // Buscar el siguiente elemento 3
                int j = i + 2;
                while (j < largo && vector[j] == 2) {
                    ++j; // Avanzar hasta encontrar un elemento diferente de 2 o el final del vector
                }
                if (j < largo && vector[j] == 3) {
                    // Si se encontró un 3, incrementar el contador de ocurrencias
                    ++ocurrencias;
                }
            }
        }

        return ocurrencias;
    }


int maximoNumero(unsigned int n) {
    int maximo; // Variable para almacenar el número máximo

    // Pido el primer número
    std::cout << "Ingrese el primer número: ";
    std::cin >> maximo;

    // Pido los siguientes n-1 números y actualizo el máximo si es necesario
    for (unsigned int i = 1; i < n; ++i) {
        int numero;
        std::cout << "Ingrese el siguiente número: ";
        std::cin >> numero;
        if (numero > maximo) {
            maximo = numero;
        }
    }

    // Devuelvo el número máximo
    return maximo;
}


void ordenarVecInt(int *vec, int largoVec) {
    for (int i = 1; i < largoVec; ++i) {
        int clave = vec[i];
        int j = i - 1;
        // Muevo los elementos del vector que son mayores que la clave
        // hacia adelante una posición
        while (j >= 0 && vec[j] > clave) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = clave;
    }
}

void imprimirVector(int* vec, int largoVec) {
    std::cout << "[";
    for (int i = 0; i < largoVec; ++i) {
        std::cout << vec[i];
        if (i < largoVec - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}



char* invertirCase(char* str) {
    // Obtengo la longitud de la cadena:
    // uso while para iterar sobre los caracteres de la cadena str hasta encontrar  '\0' (indica el final de la cadena)
    int largo = 0;
    while (str[largo] != '\0') {
        ++largo;
    }
    //cuando termina el while, length va a tener la longitud de la cadena str.

    // Creo una nueva cadena del mismo tamaño:
    // creo un nuevo puntero (strInvertido) 
    char* strInvertido = new char[largo + 1]; // sumo 1 al largo para que '\0' quede bien al final de la cadena invertida

    // Invierto los carácteres:
    //uso for para iterar sobre cada carácter de la cadena original str
    //Para cada carácter,verifico si es una letra minúscula ('a' a 'z') o una letra mayúscula ('A' a 'Z')
    for (int i = 0; i < largo; ++i) {
        //Si es una letra minúscula, se convierte a mayúscula restando 'a' y sumando 'A'
        if (str[i] >= 'a' && str[i] <= 'z') {
            strInvertido[i] = str[i] - 'a' + 'A';
        }
        //Si es una letra mayúscula, se convierte a minúscula restando 'A' y sumando 'a'
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            strInvertido[i] = str[i] - 'A' + 'a';
        }
        else {
            // Los caracteres que no son letras se conservan sin cambios
            strInvertido[i] = str[i];
        }
        //Cada carácter invertido se almacena en la nueva cadena (osea, strInvertido) 
    }
    //cuando termina el for, agrego  '\0' al final de la cadena strInvertido
    strInvertido[largo] = '\0';

    //La función devuelve el puntero strInvertido, que apunta a la nueva cadena invertida
    return strInvertido;

}

int islas(char** mapa, int col, int fil){
	// IMPLEMENTAR SOLUCION
    return 0;
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	// IMPLEMENTAR SOLUCION
    return 0;
}

//  comparo dos strings según la tabla ASCII:
// Esta función compara dos strings str1 y str2 caracter por caracter según la tabla ASCII
int comparar(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        //  comparo el primer carácter de cada string. Si son diferentes, devuelvo la diferencia entre los valores ASCII de los caracteres.
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        // Si ambos caracteres son iguales, avanza al siguiente par de caracteres y repite el proceso.
        ++str1;
        ++str2;
    }
    // Si un string llega al final antes que el otro, el string más corto es menor. 
    return *str1 - *str2;
}

// intercambio dos strings en un vector:
// Intercambio los punteros de los strings en las posiciones i y j del vector v
void intercambiar(char** v, int i, int j) {
    char* aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

//  función principal que ordena un vector de strings vecStr de longitud largoVecStr
char **ordenarVecStrings(char **vecStr, int largoVecStr)
 {
    //creo un nuevo vector (copiaVec) para almacenar copias de los strings originales
    char** copiaVec = new char* [largoVecStr];
    //itero sobre cada string en vecStr y creo una copia de cada uno
    for (int i = 0; i < largoVecStr; ++i) {
        // Obtener la longitud de cada string
        int longitud = 0;
        while (vecStr[i][longitud] != '\0') {
            ++longitud;
        }
        // Asignar memoria para la copia del string
        copiaVec[i] = new char[longitud + 1];
        // Copiar el string original al nuevo espacio de memoria
        for (int j = 0; j <= longitud; ++j) {
            copiaVec[i][j] = vecStr[i][j];
        }
    }
    // Después de hacer las copias, aplico el algoritmo de ordenamiento bubble sort para ordenar los strings en copiaVec
    
    for (int i = 0; i < largoVecStr - 1; ++i) {
        for (int j = 0; j < largoVecStr - i - 1; ++j) {
            //comparo cada par de strings consecutivos utilizando la función compararStrings
            // de ser necesario, intercambio los strings con la función intercambiarStrings
            if (comparar(copiaVec[j], copiaVec[j + 1]) > 0) {
                intercambiar(copiaVec, j, j + 1);
            }
        }
    }

    //  devuelvo el vector copiaVec, que tiene los strings ordenados. 
    return copiaVec;
}



   

int* intercalarVector(int* v1, int* v2, int l1, int l2)
{
   
        // Verifico si alguno de los vectores está vacío  (osea, si sus longitudes l1 y l2 son igual a 0)
        // Si ambos vectores están vacíos,  devuelvo NULL,  porque no hay elementos para intercalar
        if (l1 == 0 && l2 == 0) {
            return NULL;
        }

        //Si al menos uno de los vectores no está vacío, creo un nuevo vector para guardar el resultado de la intercalación
        int* intercalados  = new int[l1 + l2];
        // La longitud del nuevo vector será la suma de las longitudes de v1 y v2
        //Inicializo variables de iteración : i para el vector v1, j para el vector v2 y k para el vector resultado. 
        //voy a usar i,j,k para recorrer los vectores y el vector nuevo "intercalados".
        int i = 0;
        int j = 0;
        int k = 0;

        // Intercalo los elementos de los vectores v1 y v2 en el vector "intercalados"
        // Recorro ambos vectores con i y j, mientras comparo los elementos en cada iteración
        while (i < l1 && j < l2) {
            // Si el elemento de v1 en la posición i es menor o igual que el elemento de v2 en la posición j,  copio el elemento de v1 en el vector "intercalados" y se incrementa i
            if (v1[i] <= v2[j]) {
                intercalados[k++] = v1[i++];
            }
            // si no pasa eso, se copia el elemento de v2 en el vector "intercalados" y se incrementa j
            else {
                intercalados[k++] = v2[j++];
            }
        }

        // Después de la intercalación, pueden quedar elementos restantes en alguno de los vectores v1 o v2.
        // Agrego los elementos restantes de v1
        while (i < l1) {
            intercalados[k++] = v1[i++];
        }

        // Agrego los elementos restantes de v2
        while (j < l2) {
            intercalados[k++] = v2[j++];
        }
        //devuelvo el vector que tiene los elementos de v1 y v2 intercalados
        return intercalados;
    }





bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
    // verifico si v1 es un subconjunto de v2
        // si v1 es vacío, devuelvo true, porque el conjunto vacío es un subconjunto de cualquier conjunto, incluido v2.
        
        if (l1 == 0) {
            return true;
        }

        // Si v2 es vacío pero v1 no lo es, v1 no puede ser subconjunto de v2
        if (l2 == 0) {
            return false;
        }

        // Contador para el número de elementos de v1 encontrados en v2
        int contador = 0;

        // el primer for itera sobre cada elemento de v1, mientras que el segundo for busca ese elemento en v2.
        // entonces recorro v1 y busco cada elemento en v2
        for (int i = 0; i < l1; ++i) {
            bool encontrado = false;
            for (int j = 0; j < l2 && !encontrado; ++j) {
                if (v1[i] == v2[j]) {
                    // Si se encuentra un elemento de v1 en v2, se incrementar el contador
                    ++contador;
                    encontrado = true;
                }
            }
            // Si el elemento de v1 no se encuentra en v2, v1 no es subconjunto de v2, entonces devuelvo false
            if (!encontrado) {
                return false;
            }
        }

        // Si el contador es igual al tamaño de v1,significa que todos los elementos de v1 fueron encontrados en v2 (devuelvo True en ese caso)
        return contador == l1;
}


char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	// IMPLEMENTAR SOLUCION
}

//autor: Natalia Peña
// numero de estudiante: 242466
//materia: estructura de datos y algoritmos 1