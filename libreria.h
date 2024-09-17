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
 
 ***********************************************************************************
 
                       INTERFAZ DE FUNCIONES DE LA BIBLIOTECA
 
 **********************************************************************************/

#ifndef LIBRERIA_H
#define LIBRERIA_H


#define CAPACIDAD_INICIAL 4

typedef struct vectorDinamico{
        int capacidad;
        int totalElementos;
        void **elementos;
} vectorDinamico;

void vectorInicio(vectorDinamico *V);
      
int totalVector(vectorDinamico *V);
       
static void resizeVector(vectorDinamico *V, int capacidad);
             
void addVector(vectorDinamico *V, void *elemento);
      
void freeVector(vectorDinamico *V);
       
void *getVector(vectorDinamico *V, int indice);
      
void setVector(vectorDinamico *V, int indice, void *elemento);
       
void borrarVector(vectorDinamico *V, int indice);
      
#endif


