/* Practica 1/ funciones.c: funciones con apuntadores
   Materia: Introduccion a la Ingeniera en Software 
   Alumna: Daniela Monserraht Munoz Solis
   Grupo:303
*/

#include <stdio.h>

/* Función 1 swap: Intercambia los valores de dos variables enteras usando punteros.
 (si alguno es NULL, no hace nada)
*/
void swap(int *a, int *b) {                    
    if (a == NULL || b == NULL) return;      /*Verifica si alguno de los punteros no apunta a una dirección válida.
                                                Si alguno es NULL, la función termina sin hacer nada, evitando errores de memoria.*/
                                                
    int temp = *a;   //Guarda el valor asignado a esa direccccion//
    *a = *b;         //"a" es donde apunta "b"//
    *b = temp;       //Pone el valor original de "a" en "b"//
}

/* Funcion 2 longitudCadena:
   Entrada: Un apuntador a una cadena (char *).
   Salida: Retorna la longitud de la cadena (sin usar strlen).
*/
int longitudCadena(char * cadena) {  //Funcion que recibe un puntero a cadena y devuelve un entero//
    if (cadena == NULL) return -1;  //Si es NULL, retorna -1 para indicar un error.//
    int len = 0;  //Si es NULL, retorna -1 para indicar un error.//
    while (cadena[len] != '\0') len++;     //Recorre la cadena carácter por carácter//
    return len;     //Devuelve la cantidad de caracteres contados.//
}

/* Funcion 3 invertirArreglo:
   Entrada: Un apuntador a un arreglo de enteros y su tamaño.
   Salida: Invierte el orden del arreglo in-place (usando apuntadores). (si arr==NULL o size<=1 no hace nada)
*/
void invertirArreglo(int *arr, int size) {  //Recibe un puntero a un arreglo de enteros y su tamaño, Invierte el orden de los elementos dentro de ese arreglo//
    if (arr == NULL || size <= 1) return;  //Verifica si el arreglo existe, si no existe, no hay nada que invertir//
    for (int i = 0; i < size/2; i++) {  //Solo recore la mitad del arreglo//
        swap(&arr[i], &arr[size - 1 - i]);  //Usa la función swap() para intercambiar el elemento i con su opuesto desde el final.//
    }
}

/* Funcion 4 cuentaPares:
   Entrada: Un apuntador a un arreglo de enteros y su tamaño.
   Salida: Retorna la cantidad de numeros pares en el arreglo. (si arr==NULL o size<0 retorna -1)
*/
int cuentaPares(int *arr, int size) { //Recibe un puntero a un arreglo y su tamaño, retorna un entero con la cantidad de numeros pares //
    if (arr == NULL || size < 0) return -1;  //Si el puntero no apunta a nada o el tamaño es negativo, devuelve -1//
    int count = 0;  //Inicia el contador de numeros pares//
    for (int i = 0; i < size; i++) { //Recore todo el arreglo//
        if (arr[i] % 2 == 0) count++; //Si el numero es divisible entre dos, entonces aumenta el contador//
    }
    return count; //Da el numero total de pares encontrados//
}

// Inicio del programa //

int main() {  
    printf("+++ Practica 1 +++\n");

    int a = 5, b = 10;
    swap(&a, &b);   // llama a la funcion void y pasa las direcciones de la memoria, intercambiando los valores//
    printf("Despues de swap: a=%d, b=%d\n", a, b);
    
/* Dato incorrecto:Si alguno de los punteros "a" o "b" es "NULL"
   Pasa que: No intercambia nada y termina sin hacer cambios.
   Esto evita que el programa marque error o se cierre por usar memoria que no le pertenece.

*/
    char texto[] = "Daniela";  //Declaracion de la cadena//
    printf("longuitud del texto '%s' = %d\n", texto, longitudCadena(texto)); // se imprime el tamaño del texto//
  
/* Dato incorrecto:Si la cadena "*cadena" es NULL, no apunta a nada.
  Pasa que: Retorna -1 para indicar que el parámetro es inválido.
  No intenta leer memoria, así que el programa no se cierra inesperadamente.
*/
    int arr1[] = {1,2,3,4,5}; //Creacion del arreglo//
    int n1 = 5;
    invertirArreglo(arr1, n1);  //Llama al arreglo y lo invierte//
    printf("Arreglo invertido: ");
    for (int i=0;i<n1;i++) printf("%d ", arr1[i]);  //Imprime el arreglo invertido // 
    printf("\n");
    
/* Dato incorrecto: Si el puntero "arr" es "NULL" o si el tamaño size es 0 o negativo.
       Pasa que:La función no hace nada y termina de inmediato.
       Esto evita intercambiar posiciones que no existen y evita errores de acceso a memoria.
*/
    int arr2[] = {1,2,3,4,5,6};   //Creacion de arreglo//
    int n2 = 6;
    printf("Cantidad de pares: %d\n", cuentaPares(arr2, n2)); //Imprime el numero total de pares//
    
/* Dato incorrecto: Si el puntero arr es NULL o si el tamaño size es negativo.
   Pasa que:Retorna -1 como señal de que los datos de entrada son inválidos.
   No recorre el arreglo ni intenta acceder a posiciones inexistentes.
*/
    return 0; // Fin del programa //
}
