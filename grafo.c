#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void hola();
void buenos();
void dias();
void tenga();
void y();
void usted();
void hasta();
void malos();
void luego();
void lucas();

void nodo(const char* palabra, void (*hijos[])()) {
    printf("%s\n", palabra);
    pid_t pid;
    int c = 0;
    while (hijos[c] != NULL) {
        c++;
    }

    for (int i = 0; i < c; i++) {
        pid = fork();
        if (pid == 0) {
            hijos[i]();
            exit(0);
        }
    }

    for (int i = 0; i < c; i++) {
        wait(NULL);
    }
}

void hola() {
    void (*hijos[])() = {buenos, dias, tenga, NULL};
    nodo("Hola", hijos);
}

void buenos() {
    void (*hijos[])() = {y, usted, NULL};
    nodo("Buenos", hijos);
}

void dias() {
    void (*hijos[])() = {usted, NULL};
    nodo("dias", hijos);
}

void tenga() {
    void (*hijos[])() = {usted, hasta, NULL};
    nodo("tenga", hijos);
}

void y() {
    void (*hijos[])() = {malos, NULL};
    nodo("y", hijos);
}

void usted() {
    void (*hijos[])() = {lucas, NULL};
    nodo("usted.", hijos);
}

void hasta() {
    void (*hijos[])() = {luego, NULL};
    nodo("Hasta", hijos);
}

void malos() {
    void (*hijos[])() = {lucas, NULL};
    nodo("malos", hijos);
}

void luego() {
    void (*hijos[])() = {lucas, NULL};
    nodo("luego", hijos);
}

void lucas() {
    void (*hijos[])() = {NULL};
    nodo("Lucas",hijos);
}

int main() {
    hola();
    return 0;
}
