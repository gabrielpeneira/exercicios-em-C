#include <stdio.h>

/*Questão 02:
Implementar uma função que, dadas duas
strings s1 e s2, crie uma nova string – s3 –
contendo todos os caracteres de s1 que não

estejam em s2.
Nota: em s3, não devem existir caracteres
repetidos.
*/

void naoTem(int tam, char s1[tam], char s2[tam], char s3[tam]);
int main(void)
{

    char s1[30] = "gabriel";
    char s2[30] = "jorge";
    char s3[30];

    naoTem(30, s1, s2, s3);
}
void naoTem(int tam, char s1[tam], char s2[tam], char s3[tam])
{

    int k = 0;
    for (int i = 0; s1[i]; i++)
    {

        for (int j = 0; s2[j]; j++)
        {

            if (s1[i] != s2[j])
            {
                if(s3[k]!=s1[i]){


                    s3[k] = s1[i];
                    k++;
                }
            }

        }
    }
    s3[k] = '\0';
    printf("%s", s3);
}