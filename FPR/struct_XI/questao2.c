#include <stdio.h>
#include <string.h>
#define TAM 5

/*Questão 02:
Suponha a existência de um vetor de tamanho
TAM, cada posição armazenando o nome da
pessoa e a sua data de aniversário
(representada por um struct do tipo TData,
contendo os campos dia e mes). Pede-se o
desenvolvimento das seguintes funções:
 Determinar a quantidade de pessoas que
fazem aniversário no mês M;
 Exibir os nomes de todas pessoas que fazem
aniversário entre as datas d1 e d2, ambas
do tipo TData.*/

struct TData
{

    char nome[30];
    int dia;
    int mes;
};

int qtdAniversario(int m, int tamanho, struct TData pessoa[tamanho])
{

    int cont = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (pessoa[i].mes == m)
        {
            cont++;
        }
    }
    return cont;
}
void exibeNome(int dia1, int dia2, int mes1, int mes2, int tamanho, struct TData pessoa[tamanho])
{

    for (int i = 0; i < tamanho; i++)
    {
        if (mes1 <= pessoa[i].mes && mes2 > pessoa[i].mes)
        {
            printf("aniversariante:%s", pessoa[i].nome);

            if (dia1 <= pessoa[i].dia && dia2 >= pessoa[i].dia)
            {
                printf("aniversariante:%s", pessoa[i].nome);
            }
        }
    }
}

int main(void)
{

    int m, n, dia1, dia2, mes1, mes2;

    struct TData pessoa[TAM] = {{"gabriel", 8, 8},
                                {"felipe", 20, 2},
                                {"davi", 30, 10},
                                {"cristiane", 29, 5},
                                {"eli", 31, 12}};

    do
    {
        printf("digite 1:consulta mes\ndigite 2:exibe nome.\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("digite o mes a ser consultado:\n");
            scanf("%i", &m);
            printf("total de aniversariantes nesse mes:%d\n", qtdAniversario(m, TAM, pessoa));
            break;

        case 2:
            printf("digite um intervalo entre duas datas\ndia e mes 1:\n");
            scanf("%d %d", &dia1, &mes1);
            printf("dia e mes 2:\n");
            scanf("%d %d", &dia2, &mes2);
            exibeNome(dia1, dia2, mes1, mes2, TAM, pessoa);

            break;

        default:
            break;
        }
    } while (n != 3);
}
