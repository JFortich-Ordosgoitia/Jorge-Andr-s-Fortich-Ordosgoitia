/************************
 * Fecha: 03 de septiembre de 2024
 * Autor: Jorge Andrés Fortich Ordosgoitia
 * Materia: Sistemas Operativos
 * Tema: Introducción a Procesos con Fork
 *
 * Descripción:
 * Este programa introduce el concepto de procesos en sistemas operativos
 * utilizando la llamada al sistema `fork()`. Al ejecutarlo, se crean dos
 * procesos: uno "Padre" y uno "Hijo". Estos procesos son independientes
 * y tienen su propio espacio de memoria, aunque ambos comparten la misma
 * ejecución hasta el punto donde el programador indique diferencias.
 *
 * Funcionalidades:
 * 1. Uso de la llamada `fork()` para generar un proceso hijo.
 * 2. Ambos procesos (Padre e Hijo) ejecutan el mismo código hasta que
 *    se determine un comportamiento distinto.
 * 3. El programa imprime un mensaje en pantalla que es ejecutado tanto por
 *    el proceso Padre como por el proceso Hijo, demostrando la creación
 *    de procesos simultáneos.
 *
 ************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> //

int main (){
  
    fork();  
    printf("Hola Profesionales en Formación \n\n"); //Creación del proceso hijo, con su misma información 
  
  
}

