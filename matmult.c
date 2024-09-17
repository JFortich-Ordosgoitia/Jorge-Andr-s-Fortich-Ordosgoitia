/******************************************************************
* Pontificia Universidad Javeriana
* Autor: Jorge Andrés Fortich Ordosgoitia
* Fecha: 6/08/2024
* Materia: Sistemas Operativos
* Tema: Evaluación de Rendimiento de Sistemas de Cómputo
*
* Descripción:
* El presente código tiene como objetivo evaluar el rendimiento del
* sistema de cómputo mediante la multiplicación de matrices de gran tamaño.
* Se reserva memoria para tres matrices de NxN elementos, las cuales son
* inicializadas con valores predeterminados y luego multiplicadas.
*
* Funcionalidades principales:
* 1. Inicialización de matrices con valores específicos.
* 2. Multiplicación de matrices utilizando un algoritmo clásico.
* 3. Impresión de las matrices en consola, si son de tamaño pequeño (menor a 9).
*
* Este ejercicio permite observar el comportamiento del sistema en términos de
* manejo de memoria y procesamiento, en particular cuando se trabaja con
* estructuras de datos de gran tamaño.
******************************************************************/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


#define DATA_RESERVA (1024*1024*64*3)

static double MEM_CHUNK[DATA_RESERVA];

/********** Funcion para Multiplicar las Matrices ***********/

void Mult_Matriz(int SZ, double *a, double *b, double *c){
   int i, j, k;
    for(k=0; k<SZ; k++){
        for(j=0; j<SZ; j++){
              double *pA, *pB, SumaTemp;
              SumaTemp = 0.0;
              pA = a+(i*SZ); pB = b+j;
              for(k=SZ; k>0; k--, pA++, pB+=SZ){
                  SumaTemp += (*pA * *pB);
              c[i*SZ+j] = SumaTemp;
              }
        }
    
    }
  
}


/***********  Función Para inicializar la matriz  **********/
void Init_Matriz(int SZ, double *a, double *b, double *c){
  
  int i, j, k;
  for(k=0; k<SZ; k++){
      for(j=0;j<SZ; j++){
          a[j+k*SZ] = 2.3*(j+k);
          b[j+k*SZ] = 3.2*(j-k);
          c[j+k*SZ] = 1.3;
      
      }
  
  }
  
}


/********** Función para Imprimir la Matriz **********/

void Print_MAtriz(int SZ, double*a){
  int i, j, k;
  for(k=0; k<SZ; k++){
      for(j=0; j<SZ; j++){
          printf(" %f", a[j+k*SZ]);
      }
    printf("\n");
  }
  printf("------------------------------------\n");
  
}

int main(int argc, char *argv[]){
  
    if(argc <2){
    printf(":/MatMult MatrizSize NumHilos....\n\n");
    return -1;
    
  }
  
  int N = (int) atof(argv[1]);
  int h = (int) atof(argv[2]); 
 
  double *A, *B, *C;
  /*Reserva de Memoria Inicial de las Matrices*/
  A = MEM_CHUNK;
  B = A + N*N;
  C = B + N*N;
  
  printf("Valores ingresados: \n");
  
  printf("Hola Mundo\n");
  printf("Matriz Size (NxN): %dx%d \n",N,N);
  printf("Numero de hilos (h) %d \n",h);
  Init_Matriz(N, A, B, C);
  
  Print_MAtriz(N, A);
  Print_MAtriz(N, B);
  Print_MAtriz(N, C);
  
  Mult_Matriz(N, A, B, C);
  
  if(n<9){
    Print_Matriz(N, C);
    
  
  }
  return 0;
}