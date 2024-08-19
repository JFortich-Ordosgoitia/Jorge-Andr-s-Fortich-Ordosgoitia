/***************************************************************
 * Fecha: 13 agosto 2024
 * Autor: Jorge Andrés Fortich Ordosgoitia
 * Materia: Sistemas Op
 * Tema: Gestión de Memoria
 * Tópico: Reserva de memoria con la funcion malloc().
 * La función malloc reserva un espacio de memoria de tamaño requerido.
 * Esta devuelve un puntero señalado el inicio del espacio de memoria reservado.
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(){
        /*Declaración de variables y punteros*/
        int *p1 = calloc(4, sizeof(int)); //Asignación de vector de 4 tamaño int
        int *puntero = calloc(10, sizeof(int[4])); //Bloque de memoria de 1 int
        int *p3 = calloc(5, sizeof *p3); //Bloque de memoria de 5 int
                                                    
      
        

          /*BUCLE PARA LLENAR ESPACIOS DEL PRIMER BLOQUE RESERVADO (puntero)*/
         printf("construccion y calculo de los primeros 10 terminos1");
        for(int i=0; i<10; i++){
                *(puntero+i) = i; //se llena la posición 9na con 9889
               
                 printf("El valor de lasecuencia es de %d \n", *(puntero+i));

        }

        
        /*LIBERACIÓN O RETORNO DE MEMORIA*/
        free(puntero);
        free(p1);
        free(p1);                 
        return 0;
                        }                 
                        
                        