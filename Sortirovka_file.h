#ifndef SORTIROVKA_FILE_H 
#define SORTIROVKA_FILE_H

#include <stdio.h>

void Sortirovka(size_t* razmer_strok, char** massiv_ukazatelelei_na_stroki, size_t kolichestvo_strok);
void Cvap_char(char** chto_menat, char** na_chto_menat);
void Cvap_size_t(size_t* chto_menat, size_t* na_chto_menat);
int Na_nahuiy_blat(char* i1, char* i2, size_t kolichestvo1, size_t kolichestvo2);

#endif