#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheAleatorio(int linha, int coluna, int M[linha][coluna], int limite);

// a
int totalVendido(int linha, int coluna, int M[linha][coluna]);

// b
void mesUsuario(int coluna, int M[][coluna]);

// c
void funcUsu(int linha, int coluna, int M[linha][coluna], int funcionario);

// d
int mesRecord(int linha, int coluna, int M[linha][coluna]);

// e
int funLanterna(int linha, int coluna, int M[linha][coluna]);

int main(void)
{
    srand(time(NULL));
    int M[12][10], funcionario;

    preencheAleatorio(12, 10, M, 100);

    printf("o total vendido foi : R$ %d\n", totalVendido(12, 10, M));

    mesUsuario(10, M);

    printf("quero saber o faturamento do funcionario :");
    scanf("%d", &funcionario);

    funcUsu(12, 10, M, funcionario);

    printf("o mes com maior faturamento foi : %d\n", (mesRecord(12, 10, M) + 1));

    printf("o funcionario com menor faturamento foi: %d\n", (funLanterna(12,10,M) + 1));
    
    return 0;
}
void preencheAleatorio(int linha, int coluna, int M[linha][coluna], int limite)
{

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            M[i][j] = rand() % limite;
        }
    }
}

int totalVendido(int linha, int coluna, int M[linha][coluna])
{

    int total = 0;
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            total += M[i][j];
        }
    }
    return total;
}
void mesUsuario(int coluna, int M[][coluna])
{

    int mes, total = 0;
    printf("quero saber o faturamento do mes :\n");
    scanf("%d", &mes);
    mes--;
    for (int i = 0; i < coluna; i++)
    {
        total += M[mes][i];
    }

    printf("o total do mes %d eh :%d\n", (mes + 1), total);
}
void funcUsu(int linha, int coluna, int M[linha][coluna], int funcionario)
{

    int total = 0;
    funcionario--;
    for (int i = 0; i < linha; i++)
    {
        total += M[i][funcionario];
    }

    printf("o total do funcionario %d eh : %d\n", (funcionario + 1), total);
}
int mesRecord(int linha, int coluna, int M[linha][coluna])
{

    int i, j, maiorNum = 0, totalMes, indice;

    for (i = 0; i < linha; i++)
    {
        totalMes = 0;

        for (j = 0; j < coluna; j++)
        {
            totalMes += M[i][j];
        }

        if (maiorNum < totalMes)
        {
            maiorNum = totalMes;
            indice = i;
        }
    }
    return indice;
}
int funLanterna(int linha, int coluna, int M[linha][coluna]){

    int i, j, indice=0,menorNum=1000,total;
        
    
        for (j = 0; j < coluna; j++)
        {
            total=0;
            for (i = 0; i < linha; i++)
            {
                total+=M[i][j];

            }
            if (menorNum>total)
            {
                menorNum=total;
                indice=j;
            }
            
        }
    
    return indice;
}