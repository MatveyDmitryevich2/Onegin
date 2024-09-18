#include "Delaetmassivukazateleynabufer_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

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