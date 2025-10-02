/* funciones.c - Practica 1: funciones con apuntadores
   Alumna: Daniela Monserraht Munoz Solis
*/

#include <stdio.h>

/* Intercambia los valores apuntados por a y b.
   Parametros: a, b -> punteros a int
   Retorno: ninguno (si alguno es NULL, no hace nada)
*/
void swap(int *a, int *b) {
    if (a == NULL || b == NULL) return;
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Retorna la longitud de la cadena -sin usar strlen-.
   Parametros: cadena -> puntero a char
   Retorno: longitud >= 0; si cadena == NULL retorna -1
*/
int longitudCadena(char * cadena) {
    if (cadena == NULL) return -1;
    int len = 0;
    while (cadena[len] != '\0') len++;
    return len;
}

/* Invierte un arreglo in-place usando apuntadores.
   Parametros: arr -> puntero al primer elemento
               size -> numero de elementos
   Retorno: ninguno (si arr==NULL o size<=1 no hace nada)
*/
void invertirArreglo(int *arr, int size) {
    if (arr == NULL || size <= 1) return;       //git add, // 
    for (int i = 0; i < size/2; i++) {
        swap(&arr[i], &arr[size - 1 - i]);
    }
}

/* Cuenta cuantos elementos pares hay en arr.
   Parametros: arr, size
   Retorno: cantidad de pares; si arr==NULL o size<0 retorna -1
*/
int cuentaPares(int *arr, int size) {
    if (arr == NULL || size < 0) return -1;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) count++;
    }
    return count;
}0

/* Main de pruebas: casos correctos e incorrectos */
int main(void) {
    printf("=== Pruebas Practica 1 ===\n\n");

    /* swap */
    int a = 5, b = 10;
    printf("Antes swap: a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("Despues swap: a=%d, b=%d\n", a, b);
    swap(&a, &a); // mismo puntero (debe ser estable)
    printf("Swap mismo puntero: a=%d\n", a);
    swap(NULL, &b); // seguro, no debe crashear

    /* longitudCadena */
    char s1[] = "Hola";
    char s2[] = "";
    printf("\n longitud('%s') = %d\n", s1, longitudCadena(s1));
    printf("longitud(cadena vacia) = %d\n", longitudCadena(s2));
    printf("longitud(NULL) = %d (esperado -1)\n", longitudCadena(NULL));

    /* invertirArreglo */
    int arr1[] = {1,2,3,4,5};
    int n1 = 5;
    printf("\nArreglo original: ");
    for (int i=0;i<n1;i++) printf("%d ", arr1[i]);
    printf("\n");
    invertirArreglo(arr1, n1);
    printf("Arreglo invertido: ");
    for (int i=0;i<n1;i++) printf("%d ", arr1[i]);
    printf("\n");

    /* cuentaPares */
    int arr2[] = {1,2,3,4,5,6};
    int n2 = 6;
    printf("\n Cuenta pares en {1,2,3,4,5,6} = %d\n", cuentaPares(arr2, n2));
    printf("Cuenta pares NULL o size invalido = %d (esperado -1)\n", cuentaPares(NULL, -1));

    return 0;
}
