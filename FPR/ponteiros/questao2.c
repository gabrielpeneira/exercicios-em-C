#include <stdio.h>
#include <stdlib.h>
/*Leia um vetor de 5 inteiros e imprima os valores na ordem inversa utilizando ponteiros. */
int *criaVetor(int n)
{

    int *p = (int *)malloc(n * sizeof(int));
    return p;
}
int main(void)
{
    int n = 5, i = 0, num;
    int *v = criaVetor(n);

    while (i < n)
    {
        printf("digite um valor");
        scanf("\n%d", &num);
        *(v + i) = num;
        i++;
    }

    i = n-1;
    while (i > -1)
    {
        printf("\n%d", *(v + i));
        i--;
    }

    free(v);

    return 0;
}
