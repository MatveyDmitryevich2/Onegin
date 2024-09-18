#include "Sortirovka_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

void Sortirovka(size_t* razmer_strok, char** massiv_ukazatelelei_na_stroki, size_t kolichestvo_strok)
{
    assert(massiv_ukazatelelei_na_stroki != NULL);
    assert(razmer_strok != NULL);

    for (size_t u = 0; u < kolichestvo_strok - 1; u++)
    {
        for (size_t i = 0; i < kolichestvo_strok - u - 1; i++)
        {
            if (Na_nahuiy_blat(massiv_ukazatelelei_na_stroki[i], massiv_ukazatelelei_na_stroki[i + 1], 
                               razmer_strok[i], razmer_strok[i + 1]) == 1)
            {
                Cvap_char (massiv_ukazatelelei_na_stroki + i, massiv_ukazatelelei_na_stroki + i + 1);
                Cvap_size_t(razmer_strok + i, razmer_strok + i + 1);
            }
        }
    }
}

void Cvap_char(char** chto_menat, char** na_chto_menat)
{
    assert(chto_menat != NULL);
    assert(na_chto_menat != NULL);

    char* bufer = *chto_menat;
                  *chto_menat = *na_chto_menat;
                                *na_chto_menat = bufer;
}

void Cvap_size_t(size_t* chto_menat, size_t* na_chto_menat)
{
    assert(chto_menat != NULL);
    assert(na_chto_menat != NULL);

    size_t bufer = *chto_menat;
                  *chto_menat = *na_chto_menat;
                                *na_chto_menat = bufer;
}

int Na_nahuiy_blat(char* i1, char* i2, size_t kolichestvo1, size_t kolichestvo2)
{
    //fprintf(stderr, "i1: %s, i2: %s, kolic1: %lu, kol2: %lu\n", i1, i2, kolichestvo1, kolichestvo2);
    // fprintf(stderr, "na nahui\n");
    if(kolichestvo1 >= kolichestvo2)
    {
        char ch1 = i1[kolichestvo1 - 1];
        char ch2 = i2[kolichestvo2 - 1];

        for(size_t i = kolichestvo2; i > 0; i--)
        {
            if(tolower(ch1) > tolower(ch2))
            {
                return 1;
            } else if (tolower(ch1) < tolower(ch2))
            {
                return -1;
            }

            kolichestvo1--;
            ch1 = i1[kolichestvo1 - 1];

            kolichestvo2--;
            ch2 = i2[kolichestvo2 - 1];
        }
    }
    else
    {
        char ch1 = i1[kolichestvo1 - 1];
        char ch2 = i2[kolichestvo2 - 1];

        for(size_t i = kolichestvo1; i > 0; i--)
        {
            if(tolower(ch1) > tolower(ch2))
            {
                return 1;
            } else if (tolower(ch1) < tolower(ch2)) 
            {
                return -1;
            }

            kolichestvo1--;
            ch1 = i1[kolichestvo1 - 1];

            kolichestvo2--;
            ch2 = i2[kolichestvo2 - 1];
        }
    }

return 0;
}
