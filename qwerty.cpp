#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Sortirovka (char** Massiv_ukazatelelei_na_stroki, size_t razmer);
void Vivod_konca (char** Massiv_ukazatelelei_na_stroki, size_t razmer);
void Cvap (char** chto_menat, char** na_chto_menat);

int main(void)
{
    // FILE *nachalniy = fopen("Evgeniy.txt", "r");
    // FILE *szhatiy = fopen("EvgeniyPEREMENA.txt", "w");
    // char dlina_peremeni[9] = {0};

    // int** Massiv_ukazatelei = (int **)calloc(7, sizeof(char *));
    // char* bufer = 0;

    //     for (int i = 0; i < 7; i++)
    //     {
    //         fgets(Massiv_ukazatelei[i], 6, nachalniy);
    //     }
    // //семь на восемь восемь насемь мы фопфов отпидарасим
    // for (int i = 0; i < 7; i++)
    // {
    //     for (int u = 0; u < 6 - 1; u++)
    //     {
    //         if(strcmp(stroka[u], stroka[u + 1]) < 0)
    //         {
    //             bufer = &stroka[u];
    //             stroka[u] = stroka[u + 1];
    //             stroka[u + 1] = bufer;
    //         }
    //     }
    // }

    const size_t razmer = 7;
    char** Massiv_ukazatelelei_na_stroki = (char **)calloc(razmer, sizeof(char *));

    Massiv_ukazatelelei_na_stroki[0] = (char*)calloc(4, sizeof(char));
    Massiv_ukazatelelei_na_stroki[1] = (char*)calloc(6, sizeof(char));
    Massiv_ukazatelelei_na_stroki[2] = (char*)calloc(9, sizeof(char));
    Massiv_ukazatelelei_na_stroki[3] = (char*)calloc(6, sizeof(char));
    Massiv_ukazatelelei_na_stroki[4] = (char*)calloc(7, sizeof(char));
    Massiv_ukazatelelei_na_stroki[5] = (char*)calloc(5, sizeof(char));
    Massiv_ukazatelelei_na_stroki[6] = (char*)calloc(6, sizeof(char));
    
    const char* stroki[razmer] = {"хуй", "пизда", "алкоголь", "дилдо", "залупа", "зима", "пирог"};

    strcpy(Massiv_ukazatelelei_na_stroki[0], stroki[0]);
    strcpy(Massiv_ukazatelelei_na_stroki[1], stroki[1]);
    strcpy(Massiv_ukazatelelei_na_stroki[2], stroki[2]);
    strcpy(Massiv_ukazatelelei_na_stroki[3], stroki[3]);
    strcpy(Massiv_ukazatelelei_na_stroki[4], stroki[4]);
    strcpy(Massiv_ukazatelelei_na_stroki[5], stroki[5]);
    strcpy(Massiv_ukazatelelei_na_stroki[6], stroki[6]);

    Sortirovka (Massiv_ukazatelelei_na_stroki, razmer);
    Vivod_konca (Massiv_ukazatelelei_na_stroki, razmer);
    
    return 0;
}

void Sortirovka (char** Massiv_ukazatelelei_na_stroki, size_t razmer)
{
    for (size_t u = 0; u < razmer - 1; u++)
    {
        for (size_t i = 0; i < razmer - u - 1; i++)
        {
            if (strcmp(Massiv_ukazatelelei_na_stroki[i], Massiv_ukazatelelei_na_stroki[i + 1]) > 0)
            {
                Cvap (Massiv_ukazatelelei_na_stroki + i, Massiv_ukazatelelei_na_stroki + i + 1);
            }
        }
    }
}

void Vivod_konca (char** Massiv_ukazatelelei_na_stroki, size_t razmer)
{
    for (size_t i = 0; i < razmer; i++)
    {
        puts(Massiv_ukazatelelei_na_stroki[i]);
    }
}

void Cvap (char** chto_menat, char** na_chto_menat)
{
    char* bufer = *chto_menat;
                  *chto_menat = *na_chto_menat;
                               *na_chto_menat = bufer;
}