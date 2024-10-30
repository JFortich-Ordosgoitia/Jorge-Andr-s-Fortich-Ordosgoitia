/***************************************************************
 * Fecha: 13 agosto 2024
 * Autor: Jorge Andrés Fortich Ordosgoitia
 * Materia: Sistemas Operativos
 * Tema: Gestión de Memoria
 * Tópico: Reserva de memoria con la función calloc().
 * 
 * Descripción:
 *   Este programa en C demuestra la utilización de la función calloc() para la
 *   asignación dinámica de memoria. La función calloc() se usa para reservar un
 *   bloque de memoria contigua y también inicializarla a cero. Este programa realiza
 *   lo siguiente:
 *     1. Asigna tres bloques de memoria con diferentes tamaños utilizando calloc().
 *     2. Inicializa y muestra el contenido del primer bloque de memoria.
 *     3. Libera la memoria asignada para evitar fugas.
 * 
 * Detalles de la Asignación de Memoria:
 *   - p1: Reserva memoria para un arreglo de 4 enteros.
 *   - puntero: Reserva memoria para un bloque de 10 enteros, donde cada entero
 *     tiene el tamaño de un arreglo de 4 enteros (esto es un uso inusual y podría
 *     no ser lo que se pretende, pero se usa para ilustrar el uso de `calloc`).
 *   - p3: Reserva memoria para un arreglo de 5 enteros.
 * 
 * Funciones Presentadas:
 *   - main(): Función principal que realiza la asignación, inicialización, impresión y
 *     liberación de memoria dinámica.
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Declaración de variables y punteros */
    int *p1 = calloc(4, sizeof(int));           // Asignación de un bloque de memoria para un arreglo de 4 enteros
    int *puntero = calloc(10, sizeof(int[4])); // Asignación de un bloque de memoria para 10 enteros, con cada entero usando el tamaño de un arreglo de 4 enteros (esto es inusual)
    int *p3 = calloc(5, sizeof *p3);           // Asignación de un bloque de memoria para un arreglo de 5 enteros

    // Verificación de errores en la asignación de memoria
    if (p1 == NULL || puntero == NULL || p3 == NULL) {
        perror("Error al asignar memoria con calloc");
        free(p1);
        free(puntero);
        free(p3);
        return EXIT_FAILURE;
    }
    
    /* BUCLE PARA LLENAR ESPACIOS DEL PRIMER BLOQUE RESERVADO (puntero) */
    printf("Construcción y cálculo de los primeros 10 términos:\n");
    for (int i = 0; i < 10; i++) {
        *(puntero + i) = i;  // Inicializa cada posición del bloque con su índice
        printf("El valor de la secuencia en la posición %d es %d\n", i, *(puntero + i));
    }
    
    /* LIBERACIÓN DE MEMORIA */
    free(puntero); // Liberar el bloque de memoria reservado para 'puntero'
    free(p1);      // Liberar el bloque de memoria reservado para 'p1'
    free(p3);      // Liberar el bloque de memoria reservado para 'p3'

    return 0;
}
               
                        
