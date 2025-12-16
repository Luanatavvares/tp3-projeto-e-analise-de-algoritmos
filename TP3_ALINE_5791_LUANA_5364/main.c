#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/casamento.h"
#include "headers/criptografia.h"
#include <time.h>

int main() {
    int choice, key;
    char input_file[256], output_file[256];

    srand(time(NULL)); 

    while (1) {
        printf("\nMenu Principal\n");
        printf("1. Criptografar arquivo\n");
        printf("2. Descriptografar arquivo\n");
        printf("3. Criptografar arquivo com chave aleatória\n");
        printf("4. Buscar padrão em arquivo\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o nome do arquivo de entrada: ");
                scanf("%s", input_file);
                printf("Digite o nome do arquivo de saída: ");
                scanf("%s", output_file);
                printf("Digite a chave de criptografia (número inteiro): ");
                scanf("%d", &key);
                criptografa(input_file, output_file, key);
                printf("Arquivo criptografado com sucesso!\n");
                break;

            case 2:
                printf("Digite o nome do arquivo de entrada: ");
                scanf("%s", input_file);
                printf("Digite o nome do arquivo de saída: ");
                scanf("%s", output_file);
                printf("Digite a chave de descriptografia (número inteiro): ");
                scanf("%d", &key);
                descriptografa(input_file, output_file, key);
                printf("Arquivo descriptografado com sucesso!\n");
                break;

            case 3:
                printf("Digite o nome do arquivo de entrada: ");
                scanf("%s", input_file);
                printf("Digite o nome do arquivo de saída: ");
                scanf("%s", output_file);
                criptografa_chave_aleatoria(input_file, output_file);
                printf("Arquivo criptografado com chave aleatória!\n");
                key = criptografa_chave_aleatoria(input_file, output_file);
                frequencias(input_file);
                advinha_chave(output_file, key);

                break;

           

            case 4:
                {
                    char pattern[256];
                    int search_choice;

                    printf("Digite o nome do arquivo: ");
                    scanf("%s", input_file);
                    printf("Digite o padrão que deseja encontrar: ");
                    scanf("%s", pattern);

                    printf("Escolha o algoritmo desejado:\n");
                    printf("1. Shift-And\n");
                    printf("2. KMP\n");
                    printf("Digite sua escolha: ");
                    scanf("%d", &search_choice);

                    switch (search_choice) {
                        case 1:
                            busca(input_file, pattern, shift_and);
                            break;
                        case 2:
                            busca(input_file, pattern, kmp);
                            break;
                        default:
                            printf("Escolha inválida.\n");
                    }
                }
                break;

            case 5:
                printf("Saindo...\n");
                exit(0);

            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
