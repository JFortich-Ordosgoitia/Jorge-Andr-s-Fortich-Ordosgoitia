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
#define CAPACIDAD_INICIAL 4
#include "libreria.h"

int main(){
        int i;
        vectorDinamico editor;
        vectorInicio(&editor);

        printf("\n");
        addVector(&editor, "Hola");
        addVector(&editor, "Profesional");
        addVector(&editor, "en");
        addVector(&editor, "Formacion");
        addVector(&editor, "en");
        addVector(&editor, "Ingenieria");
        
  
        for (i = 0; i < totalVector(&editor); i++)
        printf("%s ", (char *) getVector(&editor, i));
        
        printf("\n\n");
  
        while(i>1){
          borrarVector(&editor, i);
          i--;
        }
        printf("\n\n");
         
        setVector(&editor, 1, "Buenos");
        addVector(&editor, "dias");
        
        printf("\n\n");

        for (i = 0; i < totalVector(&editor); i++)
        printf("%s ", (char *) getVector(&editor, i));
        
        printf("\n\n");
  
        
        freeVector(&editor);
  
  return 0;
}