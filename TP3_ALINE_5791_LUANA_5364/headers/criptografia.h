#ifndef CRIPTOGRAFIA_H
#define CRIPTOGRAFIA_H

#define ALPHABET_SIZE 26
#define ASCII_OFFSET 'a'

void advinha_chave(const char *input_file, int real_key);
void criptografa(const char *input_file, const char *output_file, int key);
void descriptografa(const char *input_file, const char *output_file, int key);
int criptografa_chave_aleatoria(const char *input_file, const char *output_file);
void frequencias(const char *file_path);

#endif