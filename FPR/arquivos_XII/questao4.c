#include <stdio.h>

/* Questão 04:
Desenvolver uma função que, dado um arquivo
texto contendo números, determine se estes
encontram-se ordenados crescentemente.
*/
int confereNum(char nomeArq[])
{

    FILE *arq;
    int num, compara;
    arq = fopen(nomeArq,"r");

    if (!arq)
    {
        return -1;
    }
    else
    {
        fscanf(arq, "%i", &compara);

        while (fscanf(arq, "%i", &num) != EOF)
        {

            if (compara >= num)
            {
                return 0;
            }
            else
            {
                compara = num;
            }
        }
        return 1;
    }
}
int main(void)
{
    char nomeArq[30];
    printf("digite o nome do arquivo:");
    gets(nomeArq);

    printf("%d", confereNum(nomeArq));

    return 0;
}
