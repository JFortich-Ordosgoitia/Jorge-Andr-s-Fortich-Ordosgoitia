/************************
* Fecha: 03 de septiembre de 2024
* Autor: Jorge Andrés Fortich Ordosgoitia
* Materia: Sistemas Operativos
* Tema: Introducción a Procesos con Fork
*
* Descripción:
* Este programa introduce el uso de la llamada `fork()` para la creación de
* procesos en sistemas operativos, y además implementa la comunicación entre
* procesos mediante la función `pipe()`. Cuando el programa se ejecuta, se
* crean dos procesos: el "Padre" y el "Hijo", cada uno con su propio espacio de
* memoria. Estos procesos pueden intercambiar información a través de una
* tubería (pipe) que se establece entre ellos.
*
* Características importantes:
* - La función `fork()` se utiliza para crear un proceso hijo a partir del proceso
*   padre.
* - Se utiliza `pipe()` para crear un canal de comunicación unidireccional entre
*   los dos procesos.
* - El proceso Hijo escribe un mensaje en la tubería, y el proceso Padre lo
*   recibe y lo imprime.
* - Se cierran las tuberías correspondientes después de la escritura y lectura
*   para evitar fugas de recursos.
* - En caso de error en la creación de procesos, se muestra un mensaje de error.
*
* Funcionalidad:
* 1. El proceso Hijo envía un mensaje al proceso Padre a través de la tubería.
* 2. El proceso Padre lee el mensaje de la tubería y lo imprime en la consola.
************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> //
#include<sys/types.h>
#include<string.h>
int main (){
  
    pid_t proceso;
    int id, aux;
   
    printf("\n\n \t -->PROGRAMA PRINCIPAL<--\n\n"); 
  
   printf("--> Creación de Pipes entre Procesos <-- \n\n"); 
  
    //Se crea el  mensaje a enviar
  char sms[] = ("Hola, te envio este mensaje profesional en formación");
    //Se crea un bus de memoria para el envio
  char lectorMensaje[80];
    //Se crea un arreglo para identificar el INICIO DEL PIPE Y EL FIN DEL PIPE
  int tuberia[2];
    //Se crea el PIPE
  pipe(tuberia);
  
    if((proceso = fork()) > 0) {
      //El padre envía el mensaje
      //Se cierra la entrada tubería 
       close(tuberia[1]);
      //Se lee el mensaje
      aux = read(tuberia[0], lectorMensaje, sizeof(lectorMensaje));
 
         printf("\n --> Mensaje Recibido: \n \t %s \n", lectorMensaje); 
    } else if((proceso == fork()) == 0) {
         printf("\n-->SECCIÓN DEL HIJO \n");  
      //El hijo envía el mensaje
      //Se cierra la entrada tubería 
      close(tuberia[0]);
      //Se escribe el mensaje
      write(tuberia[1], sms, (strlen(sms)+1));
      //Finalización del proceso
      exit(0);
    } else {
      
         printf("\n\n ERROR en la creacion FORK()");  
    }
  

                
                
        
    printf("\n --- FIN DEL PROGRAMA --- \n"); 
  

  
  
  
  
  
  return 0;
  
}

