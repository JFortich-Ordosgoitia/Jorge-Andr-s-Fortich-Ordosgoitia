/************************
* Fecha: 03 de septiembre de 2024
* Autor: Jorge Andrés Fortich Ordosgoitia
* Materia: Sistemas Operativos
* Tema: Introducción a Procesos con Fork
*
* Descripción:
* Este programa introduce el uso de la llamada al sistema `fork()` para
* la creación de procesos en un sistema operativo. Al ejecutarse, se crean
* dos tipos de procesos: el "Padre" y el "Hijo", cada uno con su propio
* espacio de memoria, lo que significa que son independientes entre sí
* desde el punto de vista de la memoria.
*
* El proceso Hijo siempre tendrá un valor de retorno de 0 tras la llamada
* `fork()`, lo que permite identificarlo fácilmente. El proceso Padre ejecuta
* un bloque de código distinto al del Hijo, aunque ambos comparten la misma
* estructura hasta el momento de bifurcación.
*
* Además, el programa realiza un ciclo que imprime los números del 10 al 1
* tanto en el proceso Padre como en el Hijo, para demostrar la ejecución
* paralela de los procesos.
*
* Características importantes:
* - Uso de `fork()` para crear procesos independientes.
* - Diferenciación entre el proceso Padre y el proceso Hijo mediante
*   mensajes impresos en consola.
* - Sección compartida del código que imprime números en orden descendente.
* - En caso de error en la creación de procesos, se muestra un mensaje de error.
************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> //
#include<sys/types.h>

int main (){
  
  
    int id;
    printf("Hola Profesionales en Formación \n\n"); //Creación del proceso hijo, con su misma información  
    printf("\n\n \t -->PROGRAMA PRINCIPAL<--\n\n"); 
    //Se crean los procesos diferentes
    id = fork();
    if(id > 0) {
         printf("\n SECCIÓN DEL PADRE \n"); 
    } else if(id == 0) {
         printf("\n-->SECCIÓN DEL HIJO \n");     
    } else {
      
         printf("\n\n ERROR en la creacion FORK()");  
    }
  
  //Se imprimen los numeros del 10 al 1
  for(int i=10; i>0; i--){
    
    printf("--> %d\n", i);
      
  }
                
                
        
    printf("\n --- FIN DEL PROGRAMA --- \n"); 
  

  
  
  
  
  
  return 0;
  
}

