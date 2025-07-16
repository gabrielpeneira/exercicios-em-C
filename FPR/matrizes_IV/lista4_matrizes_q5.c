#include <stdlib.h> // necessário p/ as funções rand() e srand()
#include <stdio.h>
#include <time.h> //necessário p/ função time()

void preencheMatriz(int linha, int coluna, int M[linha][coluna], int limite);

void zeraVetor(int linha, int V[linha]);

void preencheVetor(int linha, int coluna, int M[linha][coluna], int V[linha]);

void exibeVetor(int linha, int V[linha]);
int main(void)
{
    srand(time(NULL));
    int linha = 2, coluna = 3;
    int M[linha][coluna];
    int V[linha];

    preencheMatriz(linha, coluna, M, 100);

    zeraVetor(linha, V);

    preencheVetor(linha, coluna, M, V);

    exibeVetor(linha, V);
    return 0;
}
void zeraVetor(int linha, int V[linha])
{

    for (int i = 0; i < linha; i++)
    {
        V[i] = 0;
    }
}

void exibeVetor(int linha, int V[linha])
{

    for (int i = 0; i < linha; i++)
    {
        printf("%d ", V[i]);
    }
}

void preencheVetor(int linha, int coluna, int M[linha][coluna], int V[linha])
{

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            V[i] += M[i][j];
        }
    }
}

void preencheMatriz(int linha, int coluna, int M[linha][coluna], int limite)
{

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            M[i][j] = rand() % limite;
        }
    }
}