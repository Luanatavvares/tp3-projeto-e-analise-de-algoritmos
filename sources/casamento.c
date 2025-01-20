#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/casamento.h"

void shift_and(const char *text, const char *pattern) {
    int m = strlen(pattern);
    int n = strlen(text);

    if (m > 32) {
        printf("Erro: O padrão excede o tamanho máximo suportado (32).\n");
        return;
    }

    unsigned int mask[256] = {0};
    for (int i = 0; i < m; i++) {
        mask[(unsigned char)pattern[i]] |= (1 << i);
    }

    unsigned int state = 0;
    unsigned int match_bit = 1 << (m - 1);

    for (int i = 0; i < n; i++) {
        state = ((state << 1) | 1) & mask[(unsigned char)text[i]];
        if (state & match_bit) {
            printf("Padrão encontrado no índice %d\n", i - m + 1);
        }
    }
}

void kmp_search(const char *text, const char *pattern) {
    int m = strlen(pattern);
    int n = strlen(text);

    int *lps = (int *)malloc(m * sizeof(int));
    if (!lps) {
        perror("Erro ao alocar memória para o vetor LPS");
        return;
    }

    compute_lps(pattern, m, lps);

    int i = 0; 
    int j = 0; 
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Padrão encontrado no índice %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    free(lps);
}

void compute_lps(const char *pattern, int m, int *lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void search_from_file(const char *filename, const char *pattern, void (*search_func)(const char *, const char *)) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *text = (char *)malloc(file_size + 1);
    if (!text) {
        perror("Erro ao alocar memória para o texto");
        fclose(file);
        return;
    }

    fread(text, 1, file_size, file);
    text[file_size] = '\0';
    fclose(file);

    search_func(text, pattern);

    free(text);
}
