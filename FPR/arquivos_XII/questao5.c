#include <stdio.h>

/* Faça uma função que, dado um arquivo A
contendo números reais, um por linha, crie um
novo arquivo B contendo os mesmos
elementos de A, porém ordenados
decrescentemente e sem repetição. */
int tamanho(char nomeArqA[])
{
    FILE *arq = fopen(nomeArqA, "r");
    int num, cont = 0;

    if (!arq)
    {
        return -1;
    }
    else
    {

        while (fscanf(arq, "%i", &num) != EOF)
        {
            cont++;
        }
    }
    fclose(arq);
    return cont;
}
int ehMaior(char nomeArqA[], int lim)
{

    FILE *arq = fopen(nomeArqA, "r");
    int num, maior;

    if (!arq)
    {
        return -1;
    }
    else
    {

        maior = fscanf(arq, "%i", &num);

        while (fscanf(arq, "%i", &num) != EOF)
        {
            if (maior < num && num < lim)
            {
                maior = num;
            }
        }
    }
    fclose(arq);
    return maior;
}

int decr(char nomeArqA[], char nomeArqB[])
{

    FILE *arqB;
    int maior, lim, tam, i = 0;

    arqB = fopen(nomeArqB, "w");
    tam = tamanho(nomeArqA);
    if (!arqB)
    {
        return -1;
    }
    else
    {
        maior = ehMaior(nomeArqA, 1000000);
        while (i < tam)
        {
            fprintf(arqB, "%i\n", maior);
            lim = maior;
            maior = ehMaior(nomeArqA, lim);
            i++;
        }
    }
    fclose(arqB);
    return 1;
}
int main(void)
{
    char nomeArqA[30], nomeArqB[30];

    printf("digite o nome do arquivo A");
    gets(nomeArqA);
    printf("digite o nome do arquivo B");
    gets(nomeArqB);

    printf("%i",decr(nomeArqA, nomeArqB));
    
    

    return 0;
}
