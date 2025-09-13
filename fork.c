#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid_hijo;
    printf("El pid del programa principal es %d\n", (int) getpid());
    pid_hijo = fork();
    if(pid_hijo != 0) {
        printf("Este es el proceso padre con ID %d\n", (int) getpid());
        printf("El ID del hijo es %d\n", (int) pid_hijo);
        wait(NULL);
    } else {
        pid_t pid_nieto;
        printf("Este es el proceso hijo con ID %d\n", (int) getpid());
        pid_nieto = fork();
        if(pid_nieto != 0) {
            wait(NULL);
        } else {
            printf("Este es el proceso nieto, con ID %d\n", (int) getpid());
            printf("El nieto va a ejecutar el script del Ejercicio 1...\n");
            execlp("./script01", "script01", NULL);

            perror("execlp falló");
            exit(1);
        }
    }
    return 0;
}