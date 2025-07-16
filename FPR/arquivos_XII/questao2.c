#include <stdio.h>

  /* Questão 02:
Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.
*/

int contaCh(char nomeArq[],char x){

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
            if (ch==x)
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
  char nomeArq[30],x;

  printf("digite o nome do arquivo:");
  gets(nomeArq);
  printf("digite o caracter que deseja saber a regularidade");
  scanf("%c",&x);
  printf("o total é de %d",contaCh(nomeArq,x));

    return 0;
}
