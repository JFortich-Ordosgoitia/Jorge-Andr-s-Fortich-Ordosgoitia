/************************
* Fecha: 03 de septiembre de 2024
* Autor: Jorge Andrés Fortich Ordosgoitia
* Materia: Sistemas Operativos
* Tema: Introducción a Procesos con Fork
*
* Descripción:
* Este programa ejemplifica el uso de la llamada al sistema `fork()` para
* la creación de procesos en sistemas operativos. Al invocar `fork()`, se crean
* dos procesos: el "Padre" y el "Hijo". Estos procesos tienen espacios de
* memoria independientes, pero ejecutan el mismo código hasta que el programador
* decida diferenciarlos.
*
* Detalles importantes:
* - El proceso Padre y el Hijo se identifican con diferentes IDs (PID).
* - El proceso Hijo siempre tiene un valor de retorno de 0 tras la llamada `fork()`,
*   lo que facilita su identificación.
* - En el programa, se imprimen mensajes diferenciados para el proceso Padre y
*   el proceso Hijo, mostrando sus respectivos PIDs.
* - En caso de error en la creación de procesos, se notifica con un mensaje de error.
************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> //
#include<sys/types.h>

int main (){
  
  
    int id;
    printf("Hola Profesionales en Formación \n\n"); //Creación del proceso hijo, con su misma información  
  
    //Se crean los procesos diferentes
    id = fork();
    if(id > 0) {
         printf("\n\n Soy el proceso PADRE ID =  %d\n\n", getpid()); 
    } else if(id == 0) {
         printf("\n\n Soy el proceso PADRE ID =  %d\n\n", getpid()); //trampita del profe
         printf("\n\n Soy el HIJO ID =  %d\n\n", getpid()); 
         
    } else {
      
         printf("\n\n ERROR en la creacion FORK()");  
      }
                
                 
       
  
  
  return 0;
  
}

