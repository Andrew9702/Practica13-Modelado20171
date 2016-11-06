#include "b_sort.h"

/*  bsort: ordena un arreglo usando el algoritmo bubble sort
    base: es un apuntador a un arreglo a ordenar
    num: es el número de elementos en el arreglo
    size: es el tamaño en bytes de cada elemento en el arreglo
    compar: es el apuntador a una función comparadora, que regresa:
           número negativo si el primer elemento es menor
           0 si ambos elementos son iguales
           número positivo si el primer elemento es mayor
*/
void bsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)){
	//Vamos a tener un indice para el arreglo
	int indice, jindice;
	double *temp = base;
	int *tempo = base;
	if(size == 8){//El caso en el que sea un arreglo de doubles
		//Vamos a recorrer el arreglo 
		for(indice = 0; indice<num; indice++){
			//Recorremos el arreglo una cantidad menor a como avance el indice
			//Si indice vale 1, un elemento(el ultimo se queda estatico) pues ya sería el mayor
			for(jindice = 0; jindice < num-indice; jindice++){
				//Llamamos a la funcion comparadora
			    //Si el valor del arreglo en la posicion del indice es mayor a
				//la que esta adelante del indice
				if((*compar)(temp + jindice,temp + jindice + 1)>0){
					//Guardamos el valor de jindice
					double save = *(temp +  jindice);
					//modificamos el arreglo en la posicion delante del indice
					//le damos un swap con el de atras

					*(temp + jindice) = *(temp + jindice + 1);
					//Al de atras lo igualamos al de adelante
					*(temp + jindice + 1) = save;
				}
			}
		}
	} else{ //Entonces es un arreglo tipo int
		for(indice = 0; indice<num; indice++){
			//Llamamos a la funcion comparadora
			//Recorremos el arreglo una cantidad menor a como avance el indice
			//Si indice vale 1, un elemento(el ultimo se queda estatico) pues ya sería el mayor
			for(jindice = 0; jindice < num-indice; jindice++){
				if((*compar)(tempo + jindice, tempo + jindice + 1)==1){
					//Guardamos el valor de jindice
					int save = *(tempo + jindice); 
					//modificamos el arreglo en la posicion delante del indice
					//le damos un swap con el de atras
					*(tempo + jindice) = *(tempo + jindice + 1);
					//Al de atras lo igualamos al de adelante
					*(tempo + jindice + 1) = save;
				}
			}
		}
	}
}

