#include <stdio.h>
#include <stdlib.h>

/* Dado um vetor de float com 5 valores, divida todos os elementos pelo maior valor do vetor (normalização), usando ponteiros*/

float* criaVetor(int n){

    float *p= (float*)malloc(n*sizeof(float));
    return p;
}
float ehMaior(float *v,int n){

    float maior=*v;

    for (int i = 0; i < n; i++)
    {
        if (*(v+i)<maior)
        {
            maior=*(v+i);
        }
        
    }
    return maior;
}
int main(void)
{

    int n=5;
    float *v=criaVetor(n);
    printf("preencha o vetor:");

    for (int i = 0; i < n; i++)
    {
        scanf("%f",&*(v+i));
    }
 
    float maior=ehMaior(v,n);
    
    for (int j = 0; j < n; j++)
    {
        printf("%f \n",*(v+j)/(float)maior);
    }
    
    return 0;
}
