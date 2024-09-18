#include "Schitaetkolichestvostrok_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

size_t Schitaet_kolichestvo_strok(FILE *nachalniy, size_t razmer_bukv, char* buffer)
{
    assert(nachalniy != NULL);
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

    return kolichestvo_strok;
}