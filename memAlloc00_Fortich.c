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
        int *bloque00 = malloc(4*sizeof(int)); //Asignación de vector de 4 tamaño int
        int *puntero = malloc(15*sizeof(*puntero)); //Bloque de memoria de 14 int
                                                    
        /*BUCLE PARA LLENAR ESPACIOS DEL PRIMER BLOQUE RESERVADO (bloque00)*/
        for(int i = 0; i<4; i++){
                bloque00[i] = i*2;
                printf("El valor de memoria reservado bloque00[%d]= %d\n\n", i, bloque00[i]);
        
        }

          /*BUCLE PARA LLENAR ESPACIOS DEL PRIMER BLOQUE RESERVADO (puntero)*/
        if(puntero!=NULL){
                *(puntero+8) = 9889; //se llena la posición 9na con 9889
                printf("El valor de la posición 9na de puntero es %d\n\n", *(puntero+8));
                 printf("El valor de la posición 9na de puntero es %d\n\n", puntero[8]);

        }

        
        /*LIBERACIÓN O RETORNO DE MEMORIA*/
        free(bloque00);
        free(puntero);
        return 0;
                        }                 
                        
                        