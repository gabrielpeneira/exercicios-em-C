#include <stdio.h>
#include <stdlib.h>
/*Crie um vetor de 10 inteiros e preencha com valores digitados pelo usuário, utilizando apenas ponteiros. */
int *criaVetor(int n)
{

    int* p = (int*)malloc(n * sizeof(int));
    return p;
}
int main(void)
{
    int n = 4, num;
    int *v = criaVetor(n);

    for (int i = 0; i < n; i++)
    {
        printf("digite um valor");
        scanf("\n%d", &num);
        *(v + i) = num;
        
    }

    for (int j = 0; j < n; j++)
    {
        printf("\n %d", *(v + j));
    }
    
    free(v);
    return 0;
}
