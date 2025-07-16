#include <stdio.h>
#define TAM 2

int testaSimetria(int tamanho,int M[tamanho][tamanho]);

int main(void)
{
    int M[TAM][TAM]={{1,2},{3,4}};
    
    int resp = testaSimetria(TAM,M);

    if (resp==1)
    {
        printf("a matriz eh simetrica");
    }else{
        printf("a matriz NAO eh simetrica");
    }
    
    
    return 0;
}

int testaSimetria(int tamanho,int M[tamanho][tamanho]){


    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0;j < tamanho; j++)
        {
            if (M[j][i]!=M[i][j])
            {
                return 0;
            }

        }
        
    }
    
    return 1;
}