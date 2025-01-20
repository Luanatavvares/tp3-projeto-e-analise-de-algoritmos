#ifndef CASAMENTO_H
#define CASAMENTO_H

void shift_and(const char *text, const char *pattern);
void kmp_search(const char *text, const char *pattern);
void compute_lps(const char *pattern, int m, int *lps);
void search_from_file(const char *filename, const char *pattern, void (*search_func)(const char *, const char *));

#endif 
