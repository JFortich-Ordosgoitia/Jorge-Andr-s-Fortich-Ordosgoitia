/***************************************************************
 * Fecha: 13 agosto 2024
 * Autor: Jorge Andrés Fortich Ordosgoitia
 * Materia: Sistemas Operativos
 * Tema: Gestión de Memoria
 * Tópico: Reserva de memoria con la función malloc().
 * 
 * Descripción:
 *   Este programa en C demuestra el uso de la función malloc() para la asignación dinámica
 *   de memoria. La función malloc() se usa para reservar un bloque de memoria de tamaño
 *   especificado, pero a diferencia de calloc(), no inicializa el contenido de la memoria
 *   reservada. Este programa realiza lo siguiente:
 *     1. Asigna dos bloques de memoria con diferentes tamaños utilizando malloc().
 *     2. Inicializa y muestra el contenido del primer bloque de memoria.
 *     3. Muestra el contenido del segundo bloque de memoria en una posición específica.
 *     4. Libera la memoria asignada para evitar fugas.
 * 
 * Detalles de la Asignación de Memoria:
 *   - bloque00: Reserva memoria para un arreglo de 4 enteros.
 *   - puntero: Reserva memoria para un bloque de 15 enteros.
 * 
 * Funciones Presentadas:
 *   - main(): Función principal que realiza la asignación, inicialización, impresión y
 *     liberación de memoria dinámica.
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Declaración de variables y punteros */
    int *bloque00 = malloc(4 * sizeof(int));       // Asignación de un bloque de memoria para un arreglo de 4 enteros
    int *puntero = malloc(15 * sizeof(*puntero)); // Asignación de un bloque de memoria para un arreglo de 15 enteros
    
    // Verificación de errores en la asignación de memoria
    if (bloque00 == NULL || puntero == NULL) {
        perror("Error al asignar memoria con malloc");
        free(bloque00);  // Liberar memoria asignada previamente
        free(puntero);  // Liberar memoria asignada previamente
        return EXIT_FAILURE;
    }
    
    /* BUCLE PARA LLENAR ESPACIOS DEL PRIMER BLOQUE RESERVADO (bloque00) */
    for (int i = 0; i < 4; i++) {
        bloque00[i] = i * 2;  // Inicializa el arreglo con valores multiplicados por 2
        printf("El valor de memoria reservado bloque00[%d] = %d\n\n", i, bloque00[i]);
    }
    
    /* BUCLE PARA LLENAR ESPACIOS DEL SEGUNDO BLOQUE RESERVADO (puntero) */
    if (puntero != NULL) {
        *(puntero + 8) = 9889;  // Inicializa la posición 9na del arreglo con el valor 9889
        printf("El valor de la posición 9na de puntero es %d\n\n", *(puntero + 8));
        printf("El valor de la posición 9na de puntero es %d\n\n", puntero[8]);
    }
    
    /* LIBERACIÓN DE LA MEMORIA ASIGNADA */
    free(bloque00);  // Liberar el bloque de memoria reservado para 'bloque00'
    free(puntero);  // Liberar el bloque de memoria reservado para 'puntero'

    return 0;
}
                            
                        
