#include <stdio.h>

/*Questão 07:
Desenvolver uma função recursiva que
determine o número de caracteres comuns
entre duas strings s1 e s2.*/

int comum(int i, int j, int tama, int tamb, char a[], char b[]);
int main(void)
{

    char a[10] = "ola mundo";
    char b[10] = "halo world";
     printf("%d", comum(0, 0, 10, 10, a, b));
}
int comum(int i, int j, int tama, int tamb, char a[], char b[])
{
    int cont = 0;

    if (i > tama)
    {
        return cont;
    }

    if (a[i] == b[j])
    {

        cont++;
        comum(i+1, j, tama, tamb, a, b);
    }
    else
    {
        comum(i, j + 1, tama, tamb, a, b);
    }
    if (b[j] == '\0'){

        comum(i + 1, j, tama, tamb, a, b);
    }
        
}
