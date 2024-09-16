#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

// typedef int *(Sravnivanie_t)(void* a, void* b);

void Vivod_konca(char** massiv_ukazatelelei_na_stroki, size_t kolichestvo_strok, FILE *szhatiy);
void Delaet_bykvi_malenkimi(char** massiv_ukazatelelei_na_stroki, size_t kolichestvo_strok);
void Delaet_massiv_ukazateley_na_bufer(char** massiv_ukazatelelei_na_stroki, size_t razmer_bukv, char* buffer);
void Ochistitel_huiti(char** massiv_ukazatelelei_na_stroki, char* buffer, size_t kolichestvo_strok, 
                      FILE *nachalniy, FILE *szhatiy);
size_t Chitaet_razmer_faila(FILE *nachalniy);
size_t Schitaet_kolichestvo_strok(FILE *nachalniy, size_t razmer_bukv, char* buffer);

void Sortirovka(char** massiv_ukazatelelei_na_stroki, size_t kolichestvo_strok);
void Cvap(char** chto_menat, char** na_chto_menat);


    
    // посчитал размер файла да нах
    // выделил буфер под фалй да нах
    // функция которая считает колво строк да нах
    // выделил массив указателей да нах
    // функция которая мзаполняет массив и заменяет \n -> \0

int main(void)
{
    FILE *nachalniy = fopen("Evgeniy.txt", "r");
    if (nachalniy == nullptr)
    {
        fprintf(stderr, "Файл не открылся, иди читай книгу");
        return EXIT_FAILURE;
    }

    size_t razmer_bukv = Chitaet_razmer_faila(nachalniy);
    char* buffer = (char *)calloc(razmer_bukv + 1, sizeof(char));

    size_t readed = fread(buffer, sizeof(char), razmer_bukv, nachalniy);
    size_t kolichestvo_strok = Schitaet_kolichestvo_strok(nachalniy, razmer_bukv, buffer);
    
    char** massiv_ukazatelelei_na_stroki = (char **)calloc(kolichestvo_strok + 1, sizeof(char *));
            // fprintf(stderr, "readed: %lu\n", readed);
            // fprintf(stderr, "kolichestvo strok: %lu\n", kolichestvo_strok);

    Delaet_massiv_ukazateley_na_bufer(massiv_ukazatelelei_na_stroki, razmer_bukv, buffer);

    Delaet_bykvi_malenkimi(massiv_ukazatelelei_na_stroki, kolichestvo_strok);

    Sortirovka(massiv_ukazatelelei_na_stroki, kolichestvo_strok);

    FILE *szhatiy = fopen("EvgeniyPEREMENA.txt", "w");
    if (szhatiy == nullptr)
    {
        fprintf(stderr, "Файл не открылся, иди читай книгу");
        return EXIT_FAILURE;
    }

    Vivod_konca(massiv_ukazatelelei_na_stroki, kolichestvo_strok, szhatiy);

    Ochistitel_huiti(massiv_ukazatelelei_na_stroki, buffer, kolichestvo_strok, nachalniy, szhatiy);
    
    return 0;
}










size_t Chitaet_razmer_faila(FILE *nachalniy)
{
    assert(nachalniy != NULL);

    fseek(nachalniy, 0, SEEK_END);
    size_t razmer_bukv = ftell(nachalniy);
    fseek(nachalniy, 0, SEEK_SET);

    return razmer_bukv;
}

size_t Schitaet_kolichestvo_strok(FILE *nachalniy, size_t razmer_bukv, char* buffer)
{
    assert(nachalniy != NULL);
    assert(buffer != NULL);
    size_t kolichestvo_strok = 0;

    for (size_t i = 0; i < razmer_bukv; i++)
    {
        char ch = buffer[i];
        if (ch == '\n')
        {
            kolichestvo_strok++;
        }
    }

    return kolichestvo_strok;
    //fprintf(stderr, "kol str: %lu\n", *kolichestvo_strok);
}

void Delaet_massiv_ukazateley_na_bufer(char** massiv_ukazatelelei_na_stroki, size_t razmer_bukv, char* buffer)
{
    assert(massiv_ukazatelelei_na_stroki != NULL);
    assert(buffer != NULL);

    size_t ineracia_kolichestvo_strok = 1;

    massiv_ukazatelelei_na_stroki[0] = buffer;
    for (size_t i = 0; i < razmer_bukv; i++)
    {
        char ch = buffer[i];
        if (ch == '\n')
        {
            massiv_ukazatelelei_na_stroki[ineracia_kolichestvo_strok] = &buffer[i + 1];

            ineracia_kolichestvo_strok++;
            buffer[i] = '\0';
        }
    }
}

void Delaet_bykvi_malenkimi(char** massiv_ukazatelelei_na_stroki, size_t kolichestvo_strok)
{
    assert(massiv_ukazatelelei_na_stroki != NULL);

    for (size_t i = 0; i < kolichestvo_strok; i++)
    {
        size_t razmer_strokii = strlen(massiv_ukazatelelei_na_stroki[i]);
        for (size_t u = 0; u < razmer_strokii; u++)
        {
            massiv_ukazatelelei_na_stroki[i][u] = tolower(massiv_ukazatelelei_na_stroki[i][u]);
        }
    }
}

void Sortirovka(char** massiv_ukazatelelei_na_stroki, size_t kolichestvo_strok)
{
    assert(massiv_ukazatelelei_na_stroki != NULL);

    for (size_t u = 0; u < kolichestvo_strok - 1; u++)
    {
        for (size_t i = 0; i < kolichestvo_strok - u - 1; i++)
        {
            if (strcmp(massiv_ukazatelelei_na_stroki[i], massiv_ukazatelelei_na_stroki[i + 1]) > 0)
            {
                Cvap (massiv_ukazatelelei_na_stroki + i, massiv_ukazatelelei_na_stroki + i + 1);
            }
        }
    }
}

void Cvap(char** chto_menat, char** na_chto_menat)
{
    assert(chto_menat != NULL);
    assert(na_chto_menat != NULL);

    char* bufer = *chto_menat;
                  *chto_menat = *na_chto_menat;
                                *na_chto_menat = bufer;
}

void Vivod_konca(char** massiv_ukazatelelei_na_stroki, size_t kolichestvo_strok, FILE *szhatiy)
{
    assert(massiv_ukazatelelei_na_stroki != NULL);
    assert(szhatiy != NULL);

    for (size_t i = 0; i < kolichestvo_strok; i++)
    {
        fputs(massiv_ukazatelelei_na_stroki[i], szhatiy);
        fputs("\n", szhatiy);
    }
}

void Ochistitel_huiti(char** massiv_ukazatelelei_na_stroki,  char* buffer, size_t kolichestvo_strok, 
                                              FILE* nachalniy, FILE* szhatiy)
{
    assert(massiv_ukazatelelei_na_stroki != NULL);
    assert(nachalniy != NULL);
    assert(szhatiy != NULL);

    free(massiv_ukazatelelei_na_stroki);
    massiv_ukazatelelei_na_stroki = NULL;

    free(buffer);
    buffer = NULL;

    fclose(nachalniy);
    fclose(szhatiy);
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
//
//     return strcmp(*(char**)a, *(char**)a);
// }