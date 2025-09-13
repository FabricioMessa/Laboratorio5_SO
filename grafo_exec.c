#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    printf("Hola\n");
    pid = fork();

    if (pid == 0) {
        pid = fork();
        if (pid == 0) {
            pid = fork();
            if (pid == 0) {
                pid = fork();
                if (pid == 0) {
                    execl("./imprimir", "imprimir", "Lucas", NULL);
                } else {
                    wait(NULL);
                    exit(0);
                }
            } else {
                wait(NULL);
                execl("./imprimir", "imprimir", "y", "malos", NULL);
            }
        } else {
            wait(NULL);
            execl("./imprimir", "imprimir", "usted.", "Lucas", NULL);
        }
    } else {
        pid = fork();
        if (pid == 0) {
            pid = fork();
            if (pid == 0) {
                execl("./imprimir", "imprimir", "usted.", "Lucas", NULL);
            }
            else {
                wait(NULL);
                execl("./imprimir", "imprimir", "dias", "usted.", NULL);
            }
        } else {
            pid = fork();
            if (pid == 0)
            {
                pid = fork();
                if (pid == 0) {
                    execl("./imprimir", "imprimir", "usted.", "Lucas", NULL);
                } else {
                    wait(NULL);
                    execl("./imprimir", "imprimir", "Hasta", "luego", NULL);
                }
            } else {
                wait(NULL);
                execl("./imprimir", "imprimir", "tenga", "usted.", "Hasta", NULL);
            }
        }
    }

    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}