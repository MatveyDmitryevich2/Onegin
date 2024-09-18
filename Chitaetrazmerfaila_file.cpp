#include "Chitaetrazmerfaila_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

size_t Chitaet_razmer_faila(FILE *nachalniy)
{
    assert(nachalniy != NULL);

    fseek(nachalniy, 0, SEEK_END);
    size_t razmer_bukv = ftell(nachalniy);
    fseek(nachalniy, 0, SEEK_SET);

    return razmer_bukv;
}