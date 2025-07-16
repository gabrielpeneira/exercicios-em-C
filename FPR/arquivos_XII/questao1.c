#include <stdio.h>

/*Questão 01:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de caracteres no
mesmo.*/

int contaCh(char nomeArq[])
{

    FILE *arq;
    char ch;
    int cont = 0;

    arq = fopen(nomeArq, "r");

    if (!arq)
    {
        return -1;
    }
    else
    {
        while (fscanf(arq, "%c", &ch) != EOF)
        {
            cont++;
        }
    }
    fclose(arq);
    return cont;
}
int main(void)
{
    char nomeArq[30];

    printf("digite o nome do arquivo: ");
    gets(nomeArq);

    printf("o arquivo contem %d caracteres", contaCh(nomeArq));

    return 0;
}
