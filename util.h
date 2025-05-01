#ifndef UTIL_H
#define UTIL_H

typedef struct {
    char nome[100];
    char dataLancamento[11];
} Filme;

void mostrarCabecalho();

void menu();
int compararPorNumero(const void *a, const void *b);

#endif
