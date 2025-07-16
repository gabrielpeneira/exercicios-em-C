/*Questão 01:
Uma loja de automóveis mantém os carros à
venda sob a forma de um vetor de structs
contendo as seguintes informações, para cada
veículo: placa, modelo, marca, cor,
quilometragem, ano modelo/fabricação (deve
ser um struct), valor e tipo (usado ou 0 km,
conforme o valor do campo quilometragem).
Pede-se a declaração de uma variável que
represente o estoque de veículos da loja,
incluindo todas as declarações de tipos que
possam ser necessárias.
Além disso, implementar as seguintes funções:
i. Exibir todos os carros do modelo m, ano de
fabricação entre a1 e a2 (inclusive), com
valor não superior a x reais;
ii. Reajustar os valores de todos os carros 0
km, considerando um aumento de p %;
iii. Retirar do estoque um determinado veículo,
dada a sua placa.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct automovel
{

    char placa[8];
    char modelo[10];
    char marca[10];
    char cor[10];
    float km;
    int ano;
    float valor;
    char tipo[10];
};


    char modelos[5][10] = {{"Corolla"},
                           {"Blazer"},
                           {"Dodge"},
                           {"Compass"},
                           {"Spider"}};

    char marcas[5][10] = {{"toyota"},
                          {"chevrolet"},
                          {"RAM"},
                          {"jeep"},
                          {"ferrari"}};

    char cores[5][10] = {{"azul"},
                         {"vermelho"},
                         {"preto"},
                         {"branco"},
                         {"prata"}};

    char tipos[2][10] = {{"usado"}, {"zeroKm"}};

void preencheStruct(int estoque, struct automovel carro[estoque])
{  

    for (int i = 0; i < estoque; i++)
    {
        int randon = rand() % 5;

        for (int j = 0; j < 7; j++)
        {
            if (j < 4)
            {
                carro[i].placa[j] = 65 + rand() % 26;
            }
            else
            {
                carro[i].placa[j] = 48 + rand() % 10;
            }
        }
        carro[i].placa[7] = '\0';

        strcpy(carro[i].modelo, modelos[randon]);

        strcpy(carro[i].marca, marcas[randon]);

        strcpy(carro[i].cor, cores[rand() % 5]);

        carro[i].valor = 100000 + rand() % 100000;
        carro[i].ano = 2000 + rand() % 25;

        if (rand() % 2 == 1)
        {
            strcpy(carro[i].tipo, tipos[1]);
            carro[i].km =0;
        }
        else
        {
            strcpy(carro[i].tipo, tipos[0]);
            carro[i].km = rand() % 10000;
        }
    }
}
void exibe(int m,int a1, int a2,int x,int estoque, struct automovel carro[estoque]){

    m--;
    for (int i = 0; i < estoque; i++)
    {
        if (strcmp(carro[i].modelo,modelos[m])==0)
        {
        
            if (carro[i].ano>=a1 && carro[i].ano<=a2)
            {
                if (carro[i].valor<x)
                {
                    printf("\n");
                    printf("%s \n", carro[i].placa);
                    printf("%s \n", carro[i].modelo);
                    printf("%s \n", carro[i].marca);
                    printf("%s \n", carro[i].cor);
                    printf("%.2f \n", carro[i].km);
                    printf("%i \n", carro[i].ano);
                    printf("%.2f \n", carro[i].valor);
                    printf("%s \n", carro[i].tipo);
                    printf("\n");
                }
                
            }
            
           }
           
        }
        }
void mudaValor(int p, int estoque,struct automovel carro[estoque]){

    for (int i = 0; i < estoque; i++)
    {
        if (carro[i].km==0)
        {
            carro[i].valor+=carro[i].valor/p;
        }
        
    }
    
}
void retiraCarro(char placaN[], int *estoque,struct automovel carro[*estoque]){

    int j=*(estoque)-1;
    for (int i = 0; i < *(estoque); i++)
    {
        if (strcmp(carro[i].placa,placaN)==0)
        {
            strcpy(carro[i].placa,carro[j].placa);
            strcpy(carro[i].modelo,carro[j].modelo);
            strcpy(carro[i].marca,carro[j].marca);
            strcpy(carro[i].cor,carro[j].cor);
            carro[i].km=carro[j].km;
            carro[i].ano=carro[j].ano;
            carro[i].valor=carro[j].valor;
            strcpy(carro[i].tipo,carro[j].tipo);

            (*estoque)--;
        }
        
    }
    

}
int main(void)
{

     srand(time(NULL));

    int estoque = 5;
    int m,a1,a2,x,p,n;
    char placaN[8];

    struct automovel carro[estoque];

    preencheStruct(estoque, carro);
do{
    printf("1-ver estoque de carros\n2-funçao 1,encontrar carro\n3-funçao 2,aumentar valor\n4-funçao 3,excluir carro\n5-sair");
    scanf("%i",&n);
    switch (n)
    {
    case 1:
        for (int i = 0; i < estoque; i++)
{
    printf("%s \n", carro[i].placa);
    printf("%s \n", carro[i].modelo);
    printf("%s \n", carro[i].marca);
    printf("%s \n", carro[i].cor);
    printf("%.2f \n", carro[i].km);
    printf("%i \n", carro[i].ano);
    printf("%.2f \n", carro[i].valor);
    printf("%s \n", carro[i].tipo);
    printf("\n");   
}
        break;
    
    case 2:

    printf("digite um numero de 1 a 5 correspondetente ao modelo:\n");
    scanf("%i",&m);
    printf("digite uma janela de anos:\nano 1:\n");
    scanf("%i",&a1);
    printf("ano2:\n");
    scanf("%i",&a2);
    printf("digite o valor maximo:\n");
    scanf("%i",&x);

    exibe(m,a1,a2,x,estoque,carro);

        break;

    case 3:

    printf("digite a porcentagem do desconto");
    scanf("%i",&p);
    mudaValor(p,estoque,carro);

        break;

    case 4:

    printf("digite a placa de um carro do estoque:");
    scanf("%s",placaN);
    retiraCarro(placaN,&estoque,carro);   
    
        break;

    default:

    printf("numero invalido!");
        break;
    }

}while(n!=5);
}

