/***********************************************************
Fecha: 24/09/2024
Autor: Jorge Fortich
Materia: Sisteas operativos
Tema: Pipe named o FIFO o tuberia
Topico: Comunicacion unidireccional
***********************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * @def   FIFO_FILE
 * @brief Nombre del archivo FIFO.
 */
#define FIFO_FILE "MYFIFO"

/**
 * @brief Función principal del programa cliente.
 * 
 * Esta función crea una FIFO y envía mensajes a través de ella hasta que el usuario ingresa "fin".
 * 
 * @return int Código de salida del programa.
 */
int main() {
    int fd; /**< Descriptor de archivo de la FIFO. */
    int fin_proceso; /**< Variable que indica si el proceso debe finalizar. */
    int tamMensaje; /**< Tamaño del mensaje a enviar. */
    char leerbuf[80]; /**< Buffer para leer el mensaje del usuario. */
    char fin_men[5]; /**< Cadena que indica el final del proceso. */

    /**
     * Mensaje de bienvenida y explicación del funcionamiento del programa.
     */
    printf("FIFO_CLIENT: Mensajes recibidos, infinitamente, para finalizar \"fin\" \n");

    /**
     * Creación de la FIFO con permisos de escritura.
     */
    fd = open(FIFO_FILE, O_CREAT|O_WRONLY);

    /**
     * Inicialización de la cadena que indica el final del proceso.
     */
    strcpy(fin_men, "end");

    /**
     * Bucle infinito para enviar mensajes hasta que el usuario ingrese "fin".
     */
    while (1) {
        /**
         * Lectura del mensaje del usuario.
         */
        printf("Ingrese mensaje: ");
        fgets(leerbuf, sizeof(leerbuf), stdin);

        /**
         * Eliminación del carácter de nueva línea al final del mensaje.
         */
        tamMensaje = strlen(leerbuf);
        leerbuf[tamMensaje - 1] = '\0';

        /**
         * Verificación de si el mensaje es "fin" para finalizar el proceso.
         */
        fin_proceso = strcmp(leerbuf, fin_men);

        /**
         * Envío del mensaje a través de la FIFO si no es "fin".
         */
        if (fin_proceso != 0) {
            write(fd, leerbuf, strlen(leerbuf));
            printf("Mensaje enviado: \"%s\" con %d\n", leerbuf, (int)strlen(leerbuf));
        } else {
            /**
             * Envío del mensaje "fin" y cierre de la FIFO para finalizar el proceso.
             */
            write(fd, leerbuf, strlen(leerbuf));
            printf("Mensaje enviado: \"%s\" con %d\n", leerbuf, (int)strlen(leerbuf));
            close(fd);
            break;
        }
    }

    return 0;
}
