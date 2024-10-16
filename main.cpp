#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "Chitaetrazmerfaila_file.h"
#include "Schitaetkolichestvostrok_file.h"
#include "Sortirovka_file.h"
// typedef int *(Sravnivanie_t)(void* a, void* b);


int main(void)
{
    FILE* nachalniy = fopen("Evgeniy.txt", "r");
    if (nachalniy == nullptr)
    {
        fprintf(stderr, "Файл не открылся, иди читай книгу");
        return EXIT_FAILURE;
    }

    size_t razmer_bukv = Chitaet_razmer_faila(nachalniy);
    char* buffer = (char*)calloc(razmer_bukv + 1, sizeof(char));

    fread(buffer, sizeof(char), razmer_bukv, nachalniy);
    size_t kolichestvo_strok = Schitaet_kolichestvo_strok(razmer_bukv, buffer);

    struct Struka_info* Informacia_O_Stroke = (struct Struka_info*)calloc(kolichestvo_strok + 1, sizeof(Struka_info));

    Schitaet_razmer_strok(Informacia_O_Stroke, razmer_bukv, buffer); //YES

    Delaet_massiv_ukazateley_na_bufer(Informacia_O_Stroke, razmer_bukv, buffer); //YES

    Sortirovka(Informacia_O_Stroke, kolichestvo_strok);

    FILE* szhatiy = fopen("EvgeniyPEREMENA.txt", "w");
    if (szhatiy == nullptr)
    {
        fprintf(stderr, "Файл не открылся, иди читай книгу");
        return EXIT_FAILURE;
    }

    Vivod_konca(Informacia_O_Stroke, kolichestvo_strok, szhatiy); //YES

    Ochistitel_huiti(Informacia_O_Stroke, buffer, kolichestvo_strok, nachalniy, szhatiy);    

    return 0;
}







// void Moy_sort_epta(void** massiv_ukazatelelei_na_stroki, size_t kolichestvo_strok,
//                     size_t tip_peremenih, Sravnivanie_t Sravnivanie)
// {
//     for (size_t u = 0; u < kolichestvo_strok - 1; u++)
//     {
//         for (size_t i = 0; i < kolichestvo_strok - u - 1; i++)
//         {
//             if (Sravnivanie(massiv_ukazatelelei_na_stroki + i * tip_peremenih,
//                 massiv_ukazatelelei_na_stroki + (i + 1) * tip_peremenih))
//             {
//                 void* bufer = massiv_ukazatelelei_na_stroki[i];
//                         massiv_ukazatelelei_na_stroki[i] = massiv_ukazatelelei_na_stroki[i + 1];
//                                 massiv_ukazatelelei_na_stroki[i + 1] = bufer;
//             }
//         }
//     }
// }

// int Sravnivanie(void* a, void* b)
// {
//     assert(a != NULL);   
//     assert(b != NULL);

//     return strcmp(*(char**)a, *(char**)a);
// }