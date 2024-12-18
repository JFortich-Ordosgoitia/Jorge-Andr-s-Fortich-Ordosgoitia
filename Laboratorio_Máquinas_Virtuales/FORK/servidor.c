/****************************************************************************
Pontificia Universidad Javeriana
Autor: Francisco Javier Guzman Villegas
Materia: Sistemas Operativos
Tema: Pipe Named o FIFO o Tuberia
Topico: Comunicacion uni-Direccional
            SERVIDOR
****************************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "MYFIFO"
  int main() {
     int ArchivoDesc;
     char BusMensaje[80];
     char final[10];
     int fin;
     /* Create the FIFO if it does not exist */
     mknod(FIFO_FILE, S_IFIFO|0640, 0);
     strcpy(final, "end");
     while(1) {
     int cantidadBytes;
     printf("\n \t\t >>>>>> INICIO <<<<<<<\n \t\t");
       ArchivoDesc = open(FIFO_FILE, O_RDONLY);
       cantidadBytes = read(ArchivoDesc, BusMensaje, sizeof(BusMensaje));
       BusMensaje[cantidadBytes] = '\0';
       printf("Cadena recibida: \"%s\" y cantidad de bytes %d\n", BusMensaje, (int)strlen(BusMensaje));
        fin = strcmp(BusMensaje, final);
        if (fin == 0) {
           close(ArchivoDesc);
           break;
        }
     }
    return 0;
  }
