#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

void Sortirovka (char** Massiv_ukazatelelei_na_stroki, size_t razmer);
void Vivod_konca (char** Massiv_ukazatelelei_na_stroki, size_t razmer, FILE *szhatiy);
void Cvap (char** chto_menat, char** na_chto_menat);
void Delaet_bykvi_malenkimi(char** Massiv_ukazatelelei_na_stroki, size_t razmer);

int main(void)
{
    FILE *nachalniy = fopen("Evgeniy.txt", "r");
    FILE *szhatiy   = fopen("EvgeniyPEREMENA.txt", "w");
    const size_t razmer = 2000;
    int zapolneniy_razmer = 0;

    if (nachalniy == nullptr || szhatiy == nullptr)
    {
        fprintf(stderr, "Файл не открылся, иди читай книгу");
    }

    char** Massiv_ukazatelelei_na_stroki = (char **)calloc(razmer, sizeof(char *));
    size_t musor = 0;

    for (int i = 0; getline(Massiv_ukazatelelei_na_stroki + i, &musor, nachalniy) != EOF; i++)
    {
        zapolneniy_razmer++;
    }

    Delaet_bykvi_malenkimi (Massiv_ukazatelelei_na_stroki, zapolneniy_razmer);
    Sortirovka (Massiv_ukazatelelei_na_stroki, zapolneniy_razmer);
    Vivod_konca (Massiv_ukazatelelei_na_stroki, zapolneniy_razmer, szhatiy);
    
    for (int i = 0; i <= zapolneniy_razmer; i++)
    {
        free(Massiv_ukazatelelei_na_stroki[i]);
        Massiv_ukazatelelei_na_stroki[i] = NULL;
    }

    free(Massiv_ukazatelelei_na_stroki);
    Massiv_ukazatelelei_na_stroki = NULL;

    fclose(nachalniy);
    fclose(szhatiy);

    return 0;
}














void Sortirovka (const char** Massiv_ukazatelelei_na_stroki, size_t razmer)
{
    assert(Massiv_ukazatelelei_na_stroki != NULL);

    for (size_t u = 0; u < razmer - 1; u++)
    {
        for (size_t i = 0; i < razmer - u - 1; i++)
        {
            if (strcmp(Massiv_ukazatelelei_na_stroki[i], Massiv_ukazatelelei_na_stroki[i + 1]) > 0)
            {
                Cvap (Massiv_ukazatelelei_na_stroki + i, Massiv_ukazatelelei_na_stroki + i + 1);
            }
        }
    }
}

void Vivod_konca (char** Massiv_ukazatelelei_na_stroki, size_t razmer, FILE *szhatiy)
{
    assert(Massiv_ukazatelelei_na_stroki != NULL);

    for (size_t i = 0; i < razmer; i++)
    {
        fputs(Massiv_ukazatelelei_na_stroki[i], szhatiy);
    }
}

void Cvap (const char** chto_menat, const char** na_chto_menat)
{
    assert(chto_menat != NULL);
    assert(na_chto_menat != NULL);

    const char* bufer = *chto_menat;
                  *chto_menat = *na_chto_menat;
                                *na_chto_menat = bufer;
}

void Delaet_bykvi_malenkimi(char** Massiv_ukazatelelei_na_stroki, size_t razmer)
{
    assert(Massiv_ukazatelelei_na_stroki != NULL);

    for (int i = 0; i < razmer; i++)
    {
        for (int u = 0; u < strlen(Massiv_ukazatelelei_na_stroki[i]); u++)
        {
            Massiv_ukazatelelei_na_stroki[i][u] = tolower(Massiv_ukazatelelei_na_stroki[i][u]);
        }
    }
}