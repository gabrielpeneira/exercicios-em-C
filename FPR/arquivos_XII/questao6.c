#include <stdio.h>

/* Questão 06:
Desenvolver uma função que, dados dois
arquivos textos arqA e arqB, crie um novo
arquivo arqC, considerando que:
- arqA e arqB contém números reais,
um por linha, ordenados
crescentemente e sem repetição no
arquivo;
- arqC deve conter todos os números
dos dois arquivos originais;
- Assim como arqA e arqB, arqC
também não possuirá repetições de elementos e estes deverão estar
ordenados de forma crescente. */

int concatena(char nomeArqA[], char nomeArqB[], char nomeArqC[])
{

    FILE *arqA = fopen(nomeArqA, "r");
    FILE *arqB = fopen(nomeArqB, "r");
    FILE *arqC = fopen(nomeArqC, "w");
    float numa, numb;

    if (!arqA || !arqB || !arqC)
    {
        fclose(arqA);
        fclose(arqB);
        fclose(arqC);
        return 0;
    }
    else
    {
        int leua = fscanf(arqA, "%f", &numa);
        int leub = fscanf(arqB, "%f", &numb);

        while (leua == 1 && leub == 1)
        {
            if (numa < numb)
            {
                fprintf(arqC, "%.2f\n", numa);
                leua = fscanf(arqA, "%f", &numa);
            }
            else if (numa > numb)
            {

                fprintf(arqC, "%.2f\n", numb);
                leub = fscanf(arqB, "%f", &numb);
            }
            else
            {

                fprintf(arqC, "%.2f\n", numa);
                leua = fscanf(arqA, "%f", &numa);
                leub = fscanf(arqB, "%f", &numb);
            }
        }

        while (leua == 1)
        {
            fprintf(arqC, "%.2f\n", numa);
            leua = fscanf(arqA, "%f", &numa);
        }
        while (leub == 1)
        {
            fprintf(arqC, "%.2f\n", numb);
            leub = fscanf(arqB, "%f", &numb);
        }
    }
    fclose(arqA);
    fclose(arqB);
    fclose(arqC);
    return 1;
}
int main(void)
{
    char nomeArqA[30] = "testea.txt", nomeArqB[30] = "testeb.txt", nomeArqC[30] = "testec.txt";

    printf("%i", concatena(nomeArqA, nomeArqB, nomeArqC));

    return 0;
}
