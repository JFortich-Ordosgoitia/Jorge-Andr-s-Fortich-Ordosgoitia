/************************
 * Fecha: 27 de agosto de 2024
 * Autor: Jorge Andrés Fortich Ordosgoitia
 * Materia: Sistemas Operativos
 * Tema: Gestión de Memoria, Punteros, Compilación Modular
 *
 * Descripción:
 *
 * Gestión de Memoria (Dinámica y Estática):
 * 
 * La gestión de memoria implica la manipulación del espacio de memoria 
 * según las necesidades de la aplicación. Se distinguen dos tipos principales:
 *
 * 1. *Memoria Estática*: 
 *    - La memoria se asigna en tiempo de compilación.
 *    - Incluye variables globales, vectores con tamaño fijo, entre otros.
 *    - No es necesario liberar esta memoria manualmente, y siempre tiene un tamaño fijo.
 *
 * 2. *Memoria Dinámica*:
 *    - Permite al usuario cambiar o modificar el espacio de memoria según los requisitos del problema.
 *    - Es importante liberar esta memoria al finalizar su uso para evitar fugas de memoria.
 *
 * Punteros:
 *
 * Los punteros son variables auxiliares que permiten al usuario señalar de manera ligera 
 * el espacio de memoria o los contenedores (como estructuras de datos). Proporcionan la 
 * capacidad de obtener de forma precisa la dirección de memoria. Son especialmente útiles 
 * cuando se desea que el programa administre eficientemente el uso de la memoria.
 *
 * Compilación Modular:
 *
 * La compilación modular consiste en crear bibliotecas de funciones con sus respectivas interfaces,
 * de forma que estas bibliotecas estén disponibles para otros programas o usuarios. Además, 
 * se utiliza un archivo llamado "Makefile" cuyo propósito es automatizar el proceso de compilación.
 *
 * Tópico: Reserva de memoria y Compilación Modular
 ************************/

#include <stdio.h>
#include <stdlib.h>

#include "dinamiclib.h"

/* Función principal */
int main() {
    int i;
    vectorDinamico editor;  // Declara una variable de tipo vectorDinamico

    vectorInicio(&editor);  // Inicializa el vector

    resizeVector(&editor, 10);  // Redimensiona el vector a capacidad 10

    // Añade varios elementos al vector
    addVector(&editor, "Hola");
    addVector(&editor, "Profesional");
    addVector(&editor, "en");
    addVector(&editor, "Formación");
    addVector(&editor, "en");
    addVector(&editor, "Ingeniería");

    // Imprime todos los elementos del vector
    for (i = 0; i < totalVector(&editor); i++)
        printf("%s ", (char *) getVector(&editor, i));

    printf("\n\n");

    // Borra los últimos elementos del vector hasta el primero
    while (i > 1) {
        borrarVector(&editor, i);
        i--;
    }

    // Modifica un elemento y añade uno nuevo
    setVector(&editor, 1, "Buenos");
    addVector(&editor, "Días");

    printf("\n\n");

    // Imprime todos los elementos del vector después de las modificaciones
    for (i = 0; i < totalVector(&editor); i++)
        printf("%s ", (char *) getVector(&editor, i));

    // Libera la memoria utilizada por el vector
    freeVector(&editor);

    return 0;
}
