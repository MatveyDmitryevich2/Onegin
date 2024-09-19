#ifndef SCHITAETKOLICHESTVOSTROK_FILE_H 
#define SCHITAETKOLICHESTVOSTROK_FILE_H

#include <stdio.h>
#include <stdlib.h>

size_t Schitaet_kolichestvo_strok(size_t razmer_bukv, char* buffer);
void Schitaet_razmer_strok(size_t* razmer_strok, size_t razmer_bukv, char* buffer);
void Delaet_massiv_ukazateley_na_bufer(char** massiv_ukazatelelei_na_stroki, size_t razmer_bukv, char* buffer);
void Vivod_konca(char** massiv_ukazatelelei_na_stroki, size_t kolichestvo_strok, FILE *szhatiy);
void Ochistitel_huiti(size_t* razmer_strok, char** massiv_ukazatelelei_na_stroki,  char* buffer, size_t kolichestvo_strok, 
                      FILE* nachalniy, FILE* szhatiy);

#endif