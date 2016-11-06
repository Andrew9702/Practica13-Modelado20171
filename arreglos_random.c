#include "arreglos_random.h"

#include <stdio.h>

#include <time.h>
#include <time.h>
#include <stdlib.h>

//Regresa un apuntador del tipo a un arreglo int
//Esto porque se va a crear un arreglo en el heap, entonces para acceder a la parte del heap necesitamos apuntadores
/*  Crea un arreglo de enteros(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
int* arreglo_int(size_t num, int min, int max){
	time_t t;
    srand((unsigned) time(&t));
    int indice = 0;
	//Se crea un apuntador a un arreglo de int en el heap
	//Se aparta en el heap con malloc en donde el tamaño que ocupara en el heap
	int *arregloInt = malloc(num * sizeof(int));
	//Rellenamos el arreglo de numeros al azar
	for(indice;indice<num;indice++){
		//Se agrega al arreglo
		arregloInt[indice] = rand()%(max - min) + min;
	}
	//Finalmente devolvemos el apuntador al arreglo de enteros random
	return arregloInt;
}

/*  Crea un arreglo de doubles(en el heap) con números aleatorios
    num indica el tamaño del arreglo
    min indica el mínimo número aleatorio permitido en el arreglo
    max indica el máximo número aleatorio permitido en el arreglo
*/
double* arreglo_double(size_t num, double min, double max){
	time_t t;
    srand((unsigned) time(&t));
	//Se crea un apuntador a un arreglo de float en el heap
	//Apartamos un espacio en la memoria del heap con el metodo malloc
	double *arregloDouble = malloc(num * sizeof(double));
	int indice = 0;
	//Rellenamos el arreglo con floats
	for(indice;indice<num;indice++){
		arregloDouble[indice] = rand()%(int)(max - min+1) + min;
	}
	return arregloDouble;
}



