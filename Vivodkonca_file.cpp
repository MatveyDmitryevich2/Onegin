#include "Vivodkonca_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

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