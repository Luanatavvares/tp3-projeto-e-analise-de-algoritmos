#include "../headers/criptografia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <ctype.h>


const double PORTUGUESE_FREQ[ALPHABET_SIZE] = {
    14.63, 1.04, 3.88, 4.99, 12.57, 1.02, 1.30, 1.28, 6.18, 0.40, 0.02, 2.78,
    4.74, 5.05, 10.73, 2.52, 1.20, 6.53, 7.81, 4.34, 4.63, 1.67, 0.01, 0.21, 0.01, 0.47
};

void advinha_chave(const char *input_file, int real_key) {
    int total_chars = 0, frequencies[ALPHABET_SIZE] = {0};
    double calculated_freq[ALPHABET_SIZE] = {0.0};
    char c;

    FILE *file = fopen(input_file, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    while ((c = fgetc(file)) != EOF) {
        if (c >= 'a' && c <= 'z') {
            frequencies[c - ASCII_OFFSET]++;
            total_chars++;
        } else if (c >= 'A' && c <= 'Z') {
            frequencies[c - 'A']++;
            total_chars++;
        }
    }

    fclose(file);

    if (total_chars == 0) {
        printf("Nenhuma letra encontrada no arquivo.\n");
        return;
    }

    // Calcular as frequências relativas
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        calculated_freq[i] = (frequencies[i] / (double)total_chars) * 100;
    }

    int guessed_key = 0;
    double min_diff = INFINITY;

    // Comparar a distribuição de frequências deslocadas
    for (int key = 0; key < ALPHABET_SIZE; key++) {
        double total_diff = 0.0;

        // Comparando as frequências de cada letra deslocada
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            int shifted_index = (i + key) % ALPHABET_SIZE;
            total_diff += fabs(calculated_freq[i] - PORTUGUESE_FREQ[shifted_index]);
        }

        // Verificar se a chave estimada tem uma diferença menor
        if (total_diff < min_diff) {
            min_diff = total_diff;
            guessed_key = key;
        }
    }

    // Exibir resultados
    printf("\nChave real usada: %d\n", real_key);
    printf("Chave estimada: %d\n", guessed_key);
}

void criptografa(const char *input_file, const char *output_file, int key) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");

    if (!in || !out) {
        perror("Erro ao abrir arquivo");
        return;
    }

    char ch;
    while ((ch = fgetc(in)) != EOF) {
        if (isprint(ch)) {
            fputc(((ch - 32 + key) % 95) + 32, out);
        } else {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
}

void descriptografa(const char *input_file, const char *output_file, int key) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");

    if (!in || !out) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char ch;
    while ((ch = fgetc(in)) != EOF) {
        if (isprint(ch)) {
            fputc(((ch - 32 - key + 95) % 95 + 95) % 95 + 32, out);
        } else {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
}

int criptografa_chave_aleatoria(const char *input_file, const char *output_file) {
    int key = rand() % 95;
    criptografa(input_file, output_file, key);
    return key;
}

void frequencias(const char *file_path) {
    FILE *in = fopen(file_path, "r");

    if (!in) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    int frequencies[ALPHABET_SIZE] = {0};
    int total_chars = 0;

    char ch;
    while ((ch = fgetc(in)) != EOF) {
        if (isalpha(ch)) { 
            ch = tolower(ch); 
            frequencies[ch - ASCII_OFFSET]++;
            total_chars++;
        }
    }

    fclose(in);

    if (total_chars == 0) {
        printf("Nenhuma letra encontrada no arquivo.\n");
        return;
    }

    printf("Frequência de caracteres no arquivo de entrada:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (frequencies[i] > 0) {
            printf("%c: %.2f%%\n", i + ASCII_OFFSET, (frequencies[i] / (double)total_chars) * 100);
        }
    }
}
