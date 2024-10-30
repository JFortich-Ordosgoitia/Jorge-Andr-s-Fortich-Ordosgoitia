/*
 * Archivo: Realloc.c
 * Autor: [Jorge Andrés Fortich Ordosgoitia]
 * Fecha: [21/08/2024]
 * Descripción:
 *   Este programa en C demuestra el uso de la función realloc() para redimensionar dinámicamente
 *   un bloque de memoria previamente asignado. El código realiza las siguientes tareas:
 *     1. Asigna un bloque inicial de memoria usando calloc() para almacenar 4 enteros.
 *     2. Inicializa este bloque de memoria con valores secuenciales.
 *     3. Redimensiona el bloque de memoria con realloc() para aumentar su tamaño a 10 enteros.
 *     4. Inicializa los nuevos espacios de memoria con valores adicionales y muestra el contenido
 *        del bloque de memoria antes y después de la redimensión.
 *     5. Maneja errores de asignación y redimensión de memoria, y asegura la liberación adecuada
 *        de la memoria al final del programa para evitar fugas.
 *
 * Funciones Presentadas:
 *   - main(): Función principal que gestiona la asignación, inicialización, redimensión e
 *     impresión de un bloque de memoria dinámica.
 *
 * Repositorio:
 *   Puedes encontrar el código fuente y otros ejemplos en:
 *   [enlace a tu repositorio]
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    /* Declaración y asignación inicial de memoria */
    int *arr = calloc(4, sizeof(int));//Asignación inicial de un bloque de memoria para 4 enteros
    if (arr == NULL){//Verificación de éxito en la asignación
        perror("Error al asignar memoria con calloc");
        return EXIT_FAILURE;
    }

    size_t original_size = 4;//Tamaño inicial del bloque de memoria
    size_t new_size = 10;//Nuevo tamaño del bloque de memoria después de redimensionar

    /* Inicialización del bloque de memoria inicial */
    printf("Inicialización del bloque de memoria:\n");
    for (size_t i = 0; i < original_size; i++){
        arr[i] = i + 1; //Se inicializa el arreglo con valores 1, 2, 3, 4
        printf("El valor en la posición %zu es %d\n", i, arr[i]);
    }

    /* Redimensionamiento del bloque de memoria */
    int *temp = realloc(arr, new_size * sizeof(int));
    if (temp == NULL){ //Verificación de éxito en la redimensión
        perror("Error al redimensionar memoria con realloc");
        free(arr); //Liberar memoria previamente asignada en caso de error
        return EXIT_FAILURE;
    }
    arr = temp;//Actualizar el puntero para apuntar a la nueva ubicación de memoria

    /* Inicialización del nuevo espacio en el bloque de memoria */
    printf("Contenido después de redimensionar:\n");
    for (size_t i = 0; i < new_size; i++){
        if (i < original_size){
            //Los primeros elementos ya están inicializados
            printf("El valor en la posición %zu es %d\n", i, arr[i]);
        } else {
            //Inicializar los nuevos elementos
            arr[i] = i + 1;  //Inicializa nuevos valores, por ejemplo, 5, 6, 7, ...
            printf("El valor en la nueva posición %zu es %d\n", i, arr[i]);
        }
    }

    /* Liberación de la memoria asignada */
    free(arr);

    return EXIT_SUCCESS;
}
