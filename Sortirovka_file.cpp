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



int Sravnenie(char* i1, char* i2, size_t kolichestvo1, size_t kolichestvo2)
{
    //fprintf(stderr, "i1: %s, i2: %s, kol1: %lu, kol2: %lu\n", i1, i2, kolichestvo1, kolichestvo2);

    size_t min = kolichestvo1 < kolichestvo2 
                    ? kolichestvo1
                    : kolichestvo2;

    for(long long i = min; i > 0; i--)
    {
        char ch1 = tolower(i1[kolichestvo1 - 1]);
        char ch2 = tolower(i2[kolichestvo2 - 1]);
        //fprintf(stderr, "current char: ch1:  %x %c, ch2: %x %c\n", ch1, ch1, ch2, ch2);

        if(ch1 > ch2)
        {
            //fprintf(stderr, "ret 1: ch1: %x %c, ch2: %x %c\n", ch1, ch1, ch2, ch2);
            return 1;
        } else if (ch1 < ch2) {
            //fprintf(stderr, "ret -1: ch1: %x %c, ch2: %x %c\n", ch1, ch1, ch2, ch2);
            return -1;
        }
        kolichestvo1--; 
        kolichestvo2--; 
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




























// int Sravnenie(char* i1, char* i2, size_t kolichestvo1, size_t kolichestvo2)
// {
//     //fprintf(stderr, "i1: %s, i2: %s, kolic1: %lu, kol2: %lu\n", i1, i2, kolichestvo1, kolichestvo2);
//     // fprintf(stderr, "na nahui\n");
//     size_t min = 0, max = 0;
//     if(kolichestvo1 >= kolichestvo2)
//     {
//         max = kolichestvo1;
//         min = kolichestvo2;
//     }
//     else
//     {
//         max = kolichestvo2;
//         min = kolichestvo1;
//     }
 
//     char ch1 = i1[kolichestvo1 - 1];
//     char ch2 = i2[kolichestvo2 - 1];

//     for(size_t i = min, a = min, A = min; i > 0 && a > 0 && A > 0; i--, a--, A--)
//     {
//         while(isalpha(ch2) == 0)
//         {
//             A--;
//             char ch2 = i2[A];
//         }
//         while(isalpha(ch1) == 0)
//         {
//             a--;
//             char ch1 = i1[a]; 
//         }
        
//         if(tolower(ch1) > tolower(ch2))
//         {
//             return 1;
//         } else if (tolower(ch1) < tolower(ch2))
//         {
//             return -1;
//         }
//     }

// return 0;
// }