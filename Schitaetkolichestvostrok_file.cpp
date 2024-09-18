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