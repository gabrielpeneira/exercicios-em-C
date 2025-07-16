// Gabriel Pereira da Silva Barbosa
// Guilherme Azevedo Villas boas

#include <stdio.h>
#define MAX 100

struct insumos
{
    int idCurso;
    float notaEnade;
    float idd;
    float doutores;
    float mestres;
    float regimeTrab;
    float organizDP;
    float infraestrutura;
    float oportinidade;
    int qtdAlunos;
};

struct insumos dados[MAX];
int totalCursos = 0;

float calculaCPC(struct insumos c)
{
    return 0.20f * c.notaEnade +
           0.35f * c.idd +
           0.15f * c.doutores +
           0.075f * c.mestres +
           0.075f * c.regimeTrab +
           0.075f * c.organizDP +
           0.05f * c.infraestrutura +
           0.025f * c.oportinidade;
}

int faixaCPC(float cpc)
{
    if (cpc < 0.945f)
        return 1;
    else if (cpc < 1.945f)
        return 2;
    else if (cpc < 2.945f)
        return 3;
    else if (cpc < 3.945f)
        return 4;
    else
        return 5;
}

char *classificacao(int faixa)
{
    if (faixa >= 3)
    {
        return "Satisfatorio";
    }
    else
    {
        return "Insatisfatorio";
    }
}

int incluiArquivo(struct insumos dados[], char nomeArq[])
{
    FILE *arq = fopen(nomeArq, "r");
    if (!arq)
        return -1;

    while (fscanf(arq, "%d|%f|%f|%f|%f|%f|%f|%f|%f|%d",
                  &dados[totalCursos].idCurso,
                  &dados[totalCursos].notaEnade,
                  &dados[totalCursos].idd,
                  &dados[totalCursos].doutores,
                  &dados[totalCursos].mestres,
                  &dados[totalCursos].regimeTrab,
                  &dados[totalCursos].organizDP,
                  &dados[totalCursos].infraestrutura,
                  &dados[totalCursos].oportinidade,
                  &dados[totalCursos].qtdAlunos) == 10)
    {
        totalCursos++;
    }

    fclose(arq);
    return totalCursos;
}

void incluirManual()
{
    if (totalCursos >= MAX)
    {
        printf("Limite de cursos atingido.\n");
        return;
    }

    struct insumos c;
    printf("Digite os dados do curso no formato: \n");
    printf("idCurso notaEnade idd doutores mestres regimeTrab organizDP infraestrutura oportinidade qtdAlunos\n");
    scanf("%d %f %f %f %f %f %f %f %f %d",
          &c.idCurso, &c.notaEnade, &c.idd, &c.doutores,
          &c.mestres, &c.regimeTrab, &c.organizDP,
          &c.infraestrutura, &c.oportinidade, &c.qtdAlunos);

    dados[totalCursos++] = c;
}

void processarDados()
{
    float somaPonderada = 0, totalPesos = 0;
    int faixaCont[6] = {0};

    printf("\nRELATORIO DE CURSOS:\n");
    for (int i = 0; i < totalCursos; i++)
    {
        float cpc = calculaCPC(dados[i]);
        int faixa = faixaCPC(cpc);
        faixaCont[faixa]++;
        printf("Curso %d | CPC: %.2f | Faixa: %d | %s\n",
               dados[i].idCurso, cpc, faixa, classificacao(faixa));
        somaPonderada += cpc * dados[i].qtdAlunos;
        totalPesos += dados[i].qtdAlunos;
    }

    printf("\nCURSOS POR FAIXA:\n");
    for (int f = 1; f <= 5; f++)
    {
        printf("Faixa %d: %d curso(s)\n", f, faixaCont[f]);
    }

    if (totalPesos > 0)
    {
        float igc = somaPonderada / totalPesos;
        int faixaIGC = faixaCPC(igc);
        printf("\nIGC: %.2f | Faixa: %d | %s\n", igc, faixaIGC, classificacao(faixaIGC));
    }
}

int main()
{
    char nomeArq[] = "teste.txt";
    int opcao;

    incluiArquivo(dados, nomeArq);

    do
    {
        printf("\nMENU:\n");
        printf("1 - Incluir novo curso manualmente\n");
        printf("2 - Processar dados\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            incluirManual();
            break;
        case 2:
            processarDados();
            break;
        case 3:
            printf("Encerrando...\n");
            break;
        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 3);

    return 0;
}