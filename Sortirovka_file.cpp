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
            if (Sravnenie(massiv_ukazatelelei_na_stroki[i], massiv_ukazatelelei_na_stroki[i + 1], 
                          razmer_strok[i], razmer_strok[i + 1]) > 0)
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



int Sravnenie(char* bukva1, char* bukva2, size_t kolichestvo1, size_t kolichestvo2)
{
    //fprintf(stderr, "\ni1: [%s]\ni2: [%s]\nkol1: %lu, kol2: %lu\n", i1, i2, kolichestvo1, kolichestvo2);

    char ch1 = tolower(bukva1[kolichestvo1 - 1]);
    char ch2 = tolower(bukva2[kolichestvo2 - 1]);

    for(long long nomer_s_conca1 = kolichestvo1, nomer_s_conca2 = kolichestvo2;
        nomer_s_conca1 > 0 && nomer_s_conca2 > 0; 
        nomer_s_conca1--, nomer_s_conca2--)
    {
        while(isalpha(ch2) == 0)
        {
            nomer_s_conca2--;
            ch2 = tolower(bukva2[nomer_s_conca2]);
        }
        while(isalpha(ch1) == 0)
        {
            nomer_s_conca1--;
            ch1 = tolower(bukva1[nomer_s_conca1]); 
        }
        //fprintf(stderr, "current char: ch1:  %x %c, ch2: %x %c\n", ch1, ch1, ch2, ch2);

        if(ch1 > ch2)
        {
            //fprintf(stderr, "> ch1: %zu [%c], ch2: %zu [%c]\n", kolichestvo1 - a, ch1, kolichestvo2 - A, ch2);
            return 1;
        } else if (ch1 < ch2) {
            //fprintf(stderr, "< ch1: %zu [%c], ch2: %zu [%c]\n", kolichestvo1 - a, ch1, kolichestvo2 - A, ch2);
            return -1;
        }
    }

    if (kolichestvo1 == kolichestvo2)
    {
    //fprintf(stderr, "ret 0\n");  //1> 1 2> -1
        return 0;
    }

    if (kolichestvo1 > kolichestvo2)
    {
        return 1;
    }

    if (kolichestvo1 < kolichestvo2)
    {
        return -1;
    }
}