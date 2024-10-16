#ifndef SCHITAETKOLICHESTVOSTROK_FILE_H 
#define SCHITAETKOLICHESTVOSTROK_FILE_H

#include <stdio.h>
#include <stdlib.h>

#include "Structura.h"

size_t Schitaet_kolichestvo_strok(size_t razmer_bukv, char* buffer);
void Schitaet_razmer_strok(struct Struka_info* Informacia_O_Stroke, size_t razmer_bukv, char* buffer);
void Delaet_massiv_ukazateley_na_bufer(struct Struka_info* Informacia_O_Stroke, size_t razmer_bukv, char* buffer);
void Vivod_konca(struct Struka_info* Informacia_O_Stroke, size_t kolichestvo_strok, FILE *szhatiy);
void Ochistitel_huiti(struct Struka_info* Informacia_O_Stroke,  char* buffer, size_t kolichestvo_strok, 
                      FILE* nachalniy, FILE* szhatiy);

#endif