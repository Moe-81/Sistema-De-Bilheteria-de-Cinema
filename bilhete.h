#ifndef BILHETE_H
#define BILHETE_H

#include "sala.h"
#include "util.h"
#include <stdio.h>

#define MAX_BILHETES 100

typedef struct {
    int numero;
    char nomeCliente[100];
    Filme filme;
    Assento assento;
    char tipoIngresso[10]; // "inteiro" ou "meia"
} Bilhete;

Bilhete criarBilhete(int numero, int linha, int coluna);
void ordenarBilhetes(Bilhete bilhetes[], int total);
int buscaBinaria(Bilhete bilhetes[], int inicio, int fim, int numero);
int cancelarBilhete(Bilhete bilhetes[], int *total, char sala[MAX_LINHA][MAX_COLUNA], int numero);
void salvarBilhetesTXT(Bilhete bilhetes[], int total);
int carregarBilhetesTXT(Bilhete bilhetes[], char sala[MAX_LINHA][MAX_COLUNA]);

#endif
