#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

int main(void)
{
    FILE *nachalniy = fopen("Evgeniy.txt", "r");
    FILE *szhatiy   = fopen("EvgeniyPEREMENA.txt", "w");

    char* buffer = (char *)calloc(40, sizeof(char));
    char** Massiv_ukazatelelei_na_stroki = (char **)calloc(5, sizeof(char *));

    fseek(nachalniy, 0, SEEK_END);
    size_t razmer_faila = ftell(nachalniy); //TODO: func get_size

    fread(buffer, sizeof(char), razmer_faila, nachalniy);

    size_t nomer_stroki = 0;
    for (int i = 0; i < razmer_faila; i++)
    {
        char ch = buffer[i];
        if (ch == '\r') //strchr()
        {
            int razmer_stroki_i = i - (int)Massiv_ukazatelelei_na_stroki[nomer_stroki];
            nomer_stroki++;
            Massiv_ukazatelelei_na_stroki[nomer_stroki] = (char *)calloc(razmer_stroki_i, sizeof(char));

            buffer[i] = '\0';
        }

        if (Massiv_ukazatelelei_na_stroki[nomer_stroki] != 0)
        {
            for (size_t nomer_simvola = 0; nomer_simvola < i + 1; nomer_simvola++)
            {
                Massiv_ukazatelelei_na_stroki[nomer_stroki][nomer_simvola] = buffer[i];
            }
        }
    }

    for (size_t i = 0; i < nomer_stroki; i++)
    {
        fputs(Massiv_ukazatelelei_na_stroki[i], szhatiy);
    }


    return 0;
}