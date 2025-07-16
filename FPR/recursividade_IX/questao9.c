#include <stdio.h>

/*09:
Desenvolver uma função recursiva que, dado
um vetor V com quant números inteiros,
determine se seus elementos estão dispostos
de maneira a representar uma progressão
aritmética.*/
int ehPa(int i, int tam, int v[], int r);
int main(void)
{

    int v[] = {5, 10, 15, 20};
    int r = v[0];

    printf("%d", ehPa(0, 4, v, r));
}
int ehPa(int i, int tam, int v[], int r)
{

    if (i == tam - 1)

        return 1;

    if (v[i + 1] - v[i] != r)

        return 0;

    return ehPa(i + 1, tam, v, r);
}