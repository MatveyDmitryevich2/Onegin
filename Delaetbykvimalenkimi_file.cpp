#include "Delaetbykvimalenkimi_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

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
