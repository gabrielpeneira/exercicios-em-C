#include <stdio.h>

/* Questão 03:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de letras existentes
no mesmo (entendendo que no arquivo podem
existir letras, algarismos e símbolos). */

int contaLetras(char nomeArq[]){

    FILE *arq;
    char ch;
    int cont=0;
    arq = fopen(nomeArq,"r");

    if (!arq)
    {
        return -1;
    }
    else
    {

        while (fscanf(arq,"%c",&ch)!=EOF)
        {
            if (ch>=65 && ch<=90 || ch>=97 && ch<=122 )
            {
                cont++;
            }
            
        }
        fclose(arq);
        return cont;
    }
    


}
int main(void)
{
    char nomeArq[30];

    printf("digite o npme do arquivo");
    gets(nomeArq);

    printf("quantidades de letras:%d",contaLetras(nomeArq));
    
    return 0;
}
