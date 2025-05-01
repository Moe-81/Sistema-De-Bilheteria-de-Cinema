#include "bilhete.h"
#include <string.h>
#include <stdlib.h>

Bilhete criarBilhete(int numero, int linha, int coluna) {
    Bilhete novo;
    novo.numero = numero;
    novo.assento.linha = linha;
    novo.assento.coluna = coluna;

    printf("Nome do cliente: ");
    fgets(novo.nomeCliente, 100, stdin);
    novo.nomeCliente[strcspn(novo.nomeCliente, "\n")] = 0;

    printf("Tipo de ingresso (inteiro/meia): ");
    fgets(novo.tipoIngresso, 10, stdin);
    novo.tipoIngresso[strcspn(novo.tipoIngresso, "\n")] = 0;

    strcpy(novo.filme.nome, "Filme Exemplo");
    strcpy(novo.filme.dataLancamento, "2025-05-01");

    return novo;
}

void ordenarBilhetes(Bilhete bilhetes[], int total) {
    qsort(bilhetes, total, sizeof(Bilhete), compararPorNumero);
}

int buscaBinaria(Bilhete bilhetes[], int inicio, int fim, int numero) {
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (bilhetes[meio].numero == numero) return meio;
        else if (bilhetes[meio].numero > numero) fim = meio - 1;
        else inicio = meio + 1;
    }
    return -1;
}

int cancelarBilhete(Bilhete bilhetes[], int *total, char sala[MAX_LINHA][MAX_COLUNA], int numero) {
    int idx = buscaBinaria(bilhetes, 0, *total - 1, numero);
    if (idx == -1) return 0;

    int linha = bilhetes[idx].assento.linha;
    int coluna = bilhetes[idx].assento.coluna;

    for (int i = idx; i < *total - 1; i++) {
        bilhetes[i] = bilhetes[i + 1];
    }
    (*total)--;
    sala[linha][coluna] = 'D';
    salvarBilhetesTXT(bilhetes, *total);
    return 1;
}

void salvarBilhetesTXT(Bilhete bilhetes[], int total) {
    FILE *f = fopen("bilhetes.txt", "w");
    if (!f) {
        printf("Erro ao salvar arquivo.\n");
        return;
    }
    for (int i = 0; i < total; i++) {
        Bilhete b = bilhetes[i];
        fprintf(f, "%d|%s|%s|%s|%d|%d\n", b.numero, b.nomeCliente, b.filme.nome, b.tipoIngresso, b.assento.linha, b.assento.coluna);
    }
    fclose(f);
}

int carregarBilhetesTXT(Bilhete bilhetes[], char sala[MAX_LINHA][MAX_COLUNA]) {
    FILE *f = fopen("bilhetes.txt", "r");
    if (!f) return 0;
    int total = 0;
    while (!feof(f)) {
        Bilhete b;
        if (fscanf(f, "%d|%99[^|]|%99[^|]|%9[^|]|%d|%d\n", &b.numero, b.nomeCliente, b.filme.nome, b.tipoIngresso, &b.assento.linha, &b.assento.coluna) == 6) {
            strcpy(b.filme.dataLancamento, "2025-05-01");
            bilhetes[total++] = b;
            sala[b.assento.linha][b.assento.coluna] = 'X';
        }
    }
    fclose(f);
    return total;
}
