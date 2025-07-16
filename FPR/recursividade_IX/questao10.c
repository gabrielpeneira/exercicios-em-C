#include <stdio.h>

/*Questão 10:
Implementar uma função recursiva que,
dados uma string str e um caracter ch,
remova de str todas as ocorrências de ch,
retornando o total de remoções realizadas.*/

int removidas(int cint, int tam, int i, char str[], char car);

int main(void)
{

    char str[] = "gabriaaael";
    char car = 'a';

    printf("%d %s", removidas(0, 11, 0, str, car), str);
}
int removidas(int cont, int tam, int i, char str[], char car)
{

    if (i < tam)
    {

        if (str[i] == car)
        {

            int j = i;
            while (str[j] != '\0')
            {

                str[j] = str[j + 1];
                j++;
            }

            return removidas(cont + 1, tam, i, str, car);
        }
        else
        {
            return removidas(cont, tam, i + 1, str, car);
        }
    }

    return cont;
}