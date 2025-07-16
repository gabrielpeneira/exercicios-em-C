#include <stdio.h>
#include <string.h>

/* Questão 02:
Dada uma string s, desenvolver uma função
que determine se s é ou não um palíndromo.
Observação: uma string s será um palíndromo
quando seus caracteres formarem a mesma
sequência, independente se s é percorrida da
esquerda para direita ou vice-versa. */
int palindromo(int tam,char string[tam]);
int main(void)
{
    char s[30]="subinoonibus";
    
    if (palindromo(30,s))
    {
        printf("eh palindromo");
    }else{
        printf("nao eh palindromo");
    }
    
    return 0;
}
int palindromo(int tam, char string[tam]){

    int t =strlen(string)-1;

    for (int i = 0; string[i]; i++)
    {
        if (string[i]!=string[t])
        {
            return 0;
        }
        t--;
    }
    
    return 1;
}