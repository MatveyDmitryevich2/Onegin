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

void Schitaet_razmer_strok(struct Struka_info* Informacia_O_Stroke, size_t razmer_bukv, char* buffer)
{
    assert(buffer != NULL);
    assert(Informacia_O_Stroke != NULL);
    //fprintf(stderr, "пизда блять\n");
    size_t nomer_stroki = 0;
    long long razmer_stroki = -1;
    for (size_t i = 0; i < razmer_bukv; i++)
    {
        char ch = buffer[i];
        razmer_stroki++;
        if(ch == '\n')
        {
            Informacia_O_Stroke[nomer_stroki].razmer_strok = razmer_stroki;
            //razmer_strok[nomer_stroki] = razmer_stroki;
            //fprintf(stderr, "razmer_strok[%zu] = %zu\n", nomer_stroki, razmer_strok[nomer_stroki]);
            nomer_stroki++;
            
            razmer_stroki = -1;
        }
    }
}

void Delaet_massiv_ukazateley_na_bufer(struct Struka_info* Informacia_O_Stroke, size_t razmer_bukv, char* buffer)
{
    assert(Informacia_O_Stroke != NULL);
    assert(buffer != NULL);

    size_t ineracia_kolichestvo_strok = 1;

    Informacia_O_Stroke[0].massiv_ukazatelelei_na_stroki = buffer;
    //massiv_ukazatelelei_na_stroki[0] = buffer;
    for (size_t i = 0; i < razmer_bukv; i++)
    {
        char ch = buffer[i];
        if (ch == '\n')
        {
            Informacia_O_Stroke[ineracia_kolichestvo_strok].massiv_ukazatelelei_na_stroki = &buffer[i + 1];
            //massiv_ukazatelelei_na_stroki[ineracia_kolichestvo_strok] = &buffer[i + 1];

            ineracia_kolichestvo_strok++;
            buffer[i] = '\0';
        }
    }
}

void Vivod_konca(struct Struka_info* Informacia_O_Stroke, size_t kolichestvo_strok, FILE *szhatiy)
{
    assert(Informacia_O_Stroke != NULL);
    assert(szhatiy != NULL);

    for (size_t i = 0; i < kolichestvo_strok; i++)
    {
        fputs(Informacia_O_Stroke[i].massiv_ukazatelelei_na_stroki, szhatiy);
        //fputs(massiv_ukazatelelei_na_stroki[i], szhatiy);
        fputs("\n", szhatiy);
    }
}

void Ochistitel_huiti(struct Struka_info* Informacia_O_Stroke,  char* buffer, size_t kolichestvo_strok, 
                                              FILE* nachalniy, FILE* szhatiy)
{
    assert(Informacia_O_Stroke != NULL);
    assert(nachalniy != NULL);
    assert(szhatiy != NULL);

    free(Informacia_O_Stroke);
    Informacia_O_Stroke = NULL;

    free(buffer);
    buffer = NULL;

    fclose(nachalniy);
    fclose(szhatiy);
}