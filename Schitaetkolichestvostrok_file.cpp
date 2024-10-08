#include "Schitaetkolichestvostrok_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

size_t Schitaet_kolichestvo_strok(size_t razmer_bukv, char* buffer)
{
    assert(buffer != NULL);

    size_t kolichestvo_strok = 0;

    for (size_t i = 0; i < razmer_bukv; i++)
    {
        char ch = buffer[i];
        //fprintf(stderr, "%c", ch);
        if (ch == '\n')
        {
            kolichestvo_strok++;
        }
    }
    //fprintf(stderr, "kolichestvo_strok = %zu\n", kolichestvo_strok);
    //fprintf(stderr, "razmer_bukv = %zu\n", razmer_bukv);
    return kolichestvo_strok;
}

void Schitaet_razmer_strok(size_t* razmer_strok, size_t razmer_bukv, char* buffer)
{
    assert(buffer != NULL);
    assert(razmer_strok != NULL);
    //fprintf(stderr, "пизда блять\n");
    size_t nomer_stroki = 0;
    long long razmer_stroki = -1;
    for (size_t i = 0; i < razmer_bukv; i++)
    {
        char ch = buffer[i];
        razmer_stroki++;
        if(ch == '\n')
        {
            razmer_strok[nomer_stroki] = razmer_stroki;
            //fprintf(stderr, "razmer_strok[%zu] = %zu\n", nomer_stroki, razmer_strok[nomer_stroki]);
            nomer_stroki++;
            
            razmer_stroki = -1;
        }
    }
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

void Ochistitel_huiti(size_t* razmer_strok, char** massiv_ukazatelelei_na_stroki,  char* buffer, size_t kolichestvo_strok, 
                                              FILE* nachalniy, FILE* szhatiy)
{
    assert(massiv_ukazatelelei_na_stroki != NULL);
    assert(nachalniy != NULL);
    assert(szhatiy != NULL);

    free(massiv_ukazatelelei_na_stroki);
    massiv_ukazatelelei_na_stroki = NULL;

    free(buffer);
    buffer = NULL;

    free(razmer_strok);
    razmer_strok = NULL;

    fclose(nachalniy);
    fclose(szhatiy);
}