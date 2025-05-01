#ifndef SALA_H
#define SALA_H

#define MAX_LINHA 5
#define MAX_COLUNA 5

typedef struct {
    int linha, coluna;
} Assento;

void inicializarSala(char sala[MAX_LINHA][MAX_COLUNA]);
void mostrarSala(char sala[MAX_LINHA][MAX_COLUNA]);

#endif
