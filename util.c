#include "util.h"
#include <stdio.h>
#include "bilhete.h"

void mostrarCabecalho() {
    printf("**********************************************\n");
    printf("*       Sistema de Bilheteria de Cinema      *\n");
    printf("* ------------------------------------------ *\n");
    printf("* Autores: Lucas , Walid \n");
    printf("* Última atualizacao: Maio de 2025\n");
    printf("* ------------------------------------------ *\n");

    printf("**********************************************\n\n");
}

void menu() {
    printf("\n========= MENU PRINCIPAL =========\n");
    printf("1. Reservar Lugar\n");
    printf("2. Imprimir Bilhete\n");
    printf("3. Relatorio de Bilhetes\n");
    printf("4. Cancelar Bilhete\n");
    printf("5. Estatisticas\n");
    printf("0. Sair\n");
    printf("=================================\n");
}

int compararPorNumero(const void *a, const void *b) {
    Bilhete *b1 = (Bilhete *)a;
    Bilhete *b2 = (Bilhete *)b;
    return b1->numero - b2->numero;
}

