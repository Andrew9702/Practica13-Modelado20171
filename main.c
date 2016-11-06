/*Incluye las funciones de b_sort.c y arreglos_random.c*/
#include "b_sort.h"
#include "arreglos_random.h"

//Para imprimir en consola
#include "stdio.h"

/*Declara las funciones que vamos a ocupar*/

// función que compara dos enteros
int cmp_int(const void *a, const void *b);
// función que compara dos doubles
int cmp_double(const void *a, const void *b);
// función que imprime una lista de enteros de tamaño num
void imprime_int(int *arreglo, size_t num);
// función que imprime una lista de doubles de tamaño num
void imprime_double(double *arreglo, size_t num);


int main()
{
    // Se inicializan 2 arreglos, uno de ints y otro de doubles
    int *arr1 = arreglo_int(20, 0, 10);
    double *arr2 = arreglo_double(20, 0, 10);

    // Se imprime ordena e imprime el primer arreglo
    imprime_int(arr1, 20);
    bsort(arr1, 20, sizeof(int), &cmp_int);
    imprime_int(arr1, 20);

    // Se imprime ordena e imprime el segundo arreglo
    imprime_double(arr2, 20);
    bsort(arr2, 20, sizeof(double), &cmp_double);
    imprime_double(arr2, 20);

    // Se libera la memoria que ocupan los arreglos ordenados
    //Se libera la del primer arreglo, arr1 vale lo que el metodo arreglo_int regresa
    //El apuntador solo tiene la direccion en memoria de este valor
    free(arr1);
    //Se libera la del segundo, arr2vale lo que arreglo_double regresa
    //El apuntador como su nombre lo dice solo apunta a la direccion en memoria de este valor
    free(arr2);

    return 0;
}

//Recibe dos apuntadores inmutables, el hecho de que sean void, implica que no tiene ningun tipo de valor asociado a él
//Los parametros const void, apuntan a un espacio de memoria que no será modificado
//Si los enteros son identicos se regresa 0 (C no tiene booleanos :/)
int cmp_int(const void *a, const void *b){
    //Se obtiene el valor del apuntador en un entero, haciendo un casting al tipo de valor int para el apuntador
    int v1 = *(int *) a;
    //Lo mismo para b
    int v2 = *(int *) b;
    if(v1 == v2){
        return 0;
    }

    return -1;
}

//Recibe dos apuntadores que no tienen ningun tipo de valor asociado
//Son apuntadores inmutables
//Regresa 0 si son iguales, -1 en otro caso
int cmp_double(const void *a, const void *b){
    //Obtenemos el valor de a, en un float haciendo un casting al apuntador
    double v1 = *(double *)a;
    //Lo mismo en b
    double v2 = *(double *)b;
    if(v1 == v2){
        return 0;
    }
    return -1;
}

//Imprime el arreglo y no regresa nada
//Recibe un apuntador a un arreglo y size_t es un entero no asignado (unsigned int) el cual no es nunca negativo
void imprime_int(int *arreglo, size_t num){
    int indice = 0;
    for(indice;indice<num;indice++){
        printf("%d\n", arreglo[indice]);
    }

}

//Imprime el arreglo de doubles
//Recibe un arreglo de doubles y un numero siempre positivo(size_t)
void imprime_double(double *arreglo, size_t num){
    int indice = 0;
    for(indice;indice<num;indice++){
        printf("%f\n", arreglo[indice]);
    }
}

