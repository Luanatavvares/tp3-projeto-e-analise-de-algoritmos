#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/casamento.h"

int main() {
    char filename[256];
    char pattern[256];
    int choice;

    printf("Inclua o nome do arquivo: ");
    scanf("%255s", filename);
    printf("Digite o padrão que deseja encontrar: ");
    scanf("%255s", pattern);

    printf("Escolha o algoritmo desejado:\n");
    printf("1. Shift-And\n");
    printf("2. KMP\n");
    printf("Digite sua escolha: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            busca(filename, pattern, shift_and);
            break;
        case 2:
            busca(filename, pattern, kmp);
            break;
        default:
            printf("Escolha inválida.\n");
    }

    return 0;
}