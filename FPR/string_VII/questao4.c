#include <stdio.h>

/* Questão 04:
Implementar uma função que remova todas as
ocorrências de determinado caracter em uma
string.*/
void removeLetra(int tam,char string[tam],char letra);

int main(void)
{
    char string[30]="gabriel pereira";
    char letra='e';

    printf("string %s sem a letra %c:\n",string,letra);

    removeLetra(30,string,letra);

    printf("%s",string); 

    return 0;
}
void removeLetra(int tam,char string[tam],char letra){

    int i,j,contador=0;
    for (i = 0; string[i]; i++)
    {
        if (string[i]==letra)
        {
            for (j = i+1; string[i]; j++)
            {
                string[i]=string[j];
                i++;
                contador++;
            }
            i=i-contador;
        }
        
    }
    

}