#include "Ochistitelhuiti_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

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