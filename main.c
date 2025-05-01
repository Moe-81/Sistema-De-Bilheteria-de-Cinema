#include <stdio.h>
#include <string.h>
#include "sala.h"
#include "bilhete.h"
#include "util.h"

int main() {
    char sala[MAX_LINHA][MAX_COLUNA];
    Bilhete bilhetes[MAX_BILHETES];
    int totalBilhetes = 0;
    int opcao;

    inicializarSala(sala);
    totalBilhetes = carregarBilhetesTXT(bilhetes, sala);

    mostrarCabecalho();

    do {
        menu();
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            printf("Entrada invalida. Por favor, digite um numero.\n");
            opcao = -1;
            continue;
        }
        getchar();

        if (opcao == 1) {
            int linha, coluna;
            printf("\n------ RESERVAR LUGAR ------\n");
            mostrarSala(sala);

            if (totalBilhetes >= MAX_BILHETES) {
                printf("Limite de bilhetes atingido.\n");
                continue;
            }

            printf("Informe a linha e a coluna do assento desejado (0 a %d): ", MAX_LINHA - 1);
            scanf("%d %d", &linha, &coluna);
            getchar();

            if (linha < 0 || linha >= MAX_LINHA || coluna < 0 || coluna >= MAX_COLUNA || sala[linha][coluna] == 'X') {
                printf("Assento invalido ou ja ocupado.\n");
                continue;
            }

            sala[linha][coluna] = 'X';
            bilhetes[totalBilhetes] = criarBilhete(totalBilhetes + 1, linha, coluna);
            printf("Bilhete gerado com sucesso. Numero: %d\n", bilhetes[totalBilhetes].numero);
            totalBilhetes++;
            salvarBilhetesTXT(bilhetes, totalBilhetes);

        } else if (opcao == 2) {
            printf("\n------ IMPRIMIR BILHETE ------\n");
            if (totalBilhetes == 0) {
                printf("Nenhum bilhete registrado.\n");
                continue;
            }

            ordenarBilhetes(bilhetes, totalBilhetes);
            int numBusca;
            printf("Informe o numero do bilhete: ");
            scanf("%d", &numBusca);

            int idx = buscaBinaria(bilhetes, 0, totalBilhetes - 1, numBusca);
            if (idx != -1) {
                Bilhete b = bilhetes[idx];
                printf("\n========= BILHETE #%d =========\n", b.numero);
                printf("Cliente: %s\nFilme: %s\nAssento: [%d,%d]\nTipo: %s\n",
                       b.nomeCliente, b.filme.nome, b.assento.linha, b.assento.coluna, b.tipoIngresso);
                printf("===============================\n");
            } else {
                printf("Bilhete nao encontrado.\n");
            }

        } else if (opcao == 3) {
            printf("\n------ RELATORIO DE BILHETES ------\n");
            ordenarBilhetes(bilhetes, totalBilhetes);
            for (int i = 0; i < totalBilhetes; i++) {
                printf("#%d - %s - Assento [%d,%d] - %s\n",
                       bilhetes[i].numero,
                       bilhetes[i].nomeCliente,
                       bilhetes[i].assento.linha, bilhetes[i].assento.coluna,
                       bilhetes[i].tipoIngresso);
            }

        } else if (opcao == 4) {
            printf("\n------ CANCELAR BILHETE ------\n");
            if (totalBilhetes == 0) {
                printf("Nenhum bilhete registrado.\n");
                continue;
            }

            ordenarBilhetes(bilhetes, totalBilhetes);
            int numCancela;
            printf("Informe o numero do bilhete a cancelar: ");
            scanf("%d", &numCancela);

            if (cancelarBilhete(bilhetes, &totalBilhetes, sala, numCancela)) {
                printf("Bilhete #%d cancelado com sucesso.\n", numCancela);
            } else {
                printf("Bilhete nao encontrado.\n");
            }

        } else if (opcao == 5) {
            printf("\n------ ESTATISTICAS DO SISTEMA ------\n");
            int meia = 0, inteira = 0;
            for (int i = 0; i < totalBilhetes; i++) {
                if (strcmp(bilhetes[i].tipoIngresso, "meia") == 0) meia++;
                else inteira++;
            }
            int totalAssentos = MAX_LINHA * MAX_COLUNA;
            int ocupados = totalBilhetes;
            int livres = totalAssentos - ocupados;
            float ocupacao = (ocupados * 100.0f) / totalAssentos;

            printf("Ingressos inteiros: %d\n", inteira);
            printf("Ingressos meia: %d\n", meia);
            printf("Assentos ocupados: %d\n", ocupados);
            printf("Assentos livres: %d\n", livres);
            printf("Ocupacao da sala: %.2f%%\n", ocupacao);

        } else if (opcao == 0) {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}
