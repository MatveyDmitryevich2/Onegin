#include "Sortirovka_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

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