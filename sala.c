#include "sala.h"
#include <stdio.h>

void inicializarSala(char sala[MAX_LINHA][MAX_COLUNA]) {
    for (int i = 0; i < MAX_LINHA; i++)
        for (int j = 0; j < MAX_COLUNA; j++)
            sala[i][j] = 'D';
}

void mostrarSala(char sala[MAX_LINHA][MAX_COLUNA]) {
    printf("\n====== SALA DE CINEMA ======\n");
    printf("   ");
    for (int j = 0; j < MAX_COLUNA; j++) printf(" %d ", j);
    printf("\n");
    for (int i = 0; i < MAX_LINHA; i++) {
        printf(" %d ", i);
        for (int j = 0; j < MAX_COLUNA; j++) {
            char visual = (sala[i][j] == 'X') ? 'X' : 'O';
            printf("[%c]", visual);
        }
        printf("\n");
    }
    printf("\n[O] Disponivel | [X] Ocupado\n");
    printf("============================\n");
}
