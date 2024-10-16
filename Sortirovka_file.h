#ifndef SORTIROVKA_FILE_H 
#define SORTIROVKA_FILE_H

#include <stdio.h>

#include "Structura.h"

void Sortirovka(struct Struka_info* Informacia_O_Stroke, size_t kolichestvo_strok);
void Cvap_struct (struct Struka_info* a, struct Struka_info* b);
//void Cvap_char(char** chto_menat, char** na_chto_menat);
//void Cvap_size_t(size_t* chto_menat, size_t* na_chto_menat);
int Sravnenie(char* i1, char* i2, size_t kolichestvo1, size_t kolichestvo2);

#endif