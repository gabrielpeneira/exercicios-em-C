#include <stdio.h>
#include <string.h>

/* Questão 03:
Desenvolver uma função que, dada uma string
s, crie uma substring que inicie na posição p de
s e contenha n caracteres.
Observações: se p e/ou n forem inválidos, a
substring será vazia; ii) se s não possuir n
caracteres além de p, a substring a ser criada
começará em p e terminará no final de s.
 */
void subString(int tam, char string[tam], int p, int n);

int main(void)
{
    char s[30] = "gabriel";
    int p = 2;
    int n = 4;

    printf("a string '%s', de p a n fica:\n", s);

    subString(30, s, p, n);

    printf("'%s'", s);
    return 0;
}

void subString(int tam, char string[tam], int p, int n)
{
    char sub[tam];
    int t = strlen(string);

    t = t - p;
    if (p < 0 || n <= 0)
    {
        int i;
        for (i = 0; string[i]; i++)
        {
            sub[i] = '\0';
        }
    }
    else if (n >= t)
    {
        int j = 0, i;
        for (i = p; string[i]; i++)
        {
            sub[j] = string[i];
            j++;
        }
        sub[j] = '\0';
    }
    else
    {
        int j = 0, i;
        for (i = p; i < (p + n); i++)
        {
            sub[j] = string[i];
            j++;
        }
        sub[j] = '\0';
    }
    strcpy(string, sub);
}