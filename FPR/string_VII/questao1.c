#include <stdio.h>
/*Questão 01:
Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.*/

//strlen
int medeString(int tam, char string[tam]);
//strcpy
void copiaString(int tam, char string2[tam],char string1[tam]);
//strcat
void concatena(int tam,char string1[tam],int tam2,char string2[tam2]);
//strcmp
int compara(int tam,char string1[tam],int tam2,char string2[tam2]);

int main(void)
{
    char nome[30]="gabriel pereira";
    char copiaNome[30]="gabrieL";
    int numero;
do
{
    printf("digite:\n1-strlen\n2-strcpy\n3-strcat\n4-strcmp");
    scanf("%d",&numero);

    switch (numero)
{
case 1:
    printf("a string 'nome' tem %d caracteres\n",medeString(30, nome));
    break;
case 2:
    copiaString(30, copiaNome,nome);
    printf("a copia de 'nome' e: %s\n",copiaNome);
    break;
case 3:  
    concatena(30,nome,30,copiaNome);
    printf("concatenaçao de ' nome' e 'copiaNome':%s\n",nome);
    break;
case 4:
    printf("%d\n",compara(30,nome,30,copiaNome));
    break;
default:
printf(" numero invalido!!!");
    break;
}
} while (numero!=0);


    return 0;
}
int medeString(int tam, char string[tam]){

    int acum=0;

    for (int i = 0; string[i]; i++)
    {
        acum++;
    }
    return acum;
}
void copiaString(int tam, char string2[tam],char string1[tam]){
int i;
    for (i = 0; string1[i]; i++)
    {
        string2[i]=string1[i];
    }
    string2[i]='\0';

}
void concatena(int tam,char string1[tam],int tam2,char string2[tam2]){

    int i,tamanho = medeString(tam, string1);

    for (i = 0; string2[i]; i++)
    {
        string1[tamanho+i]=string2[i];
    }
    string1[tamanho+i+1]='\0';
    
}
int compara(int tam,char string1[tam],int tam2,char string2[tam2]){
int resultado=0;
    for (int i = 0; string1[i]; i++)
    {
        if (string1[i]!=string2[i])
        {
            resultado=string1[i]-string2[i];
            return resultado;
        }
        
    }
    return resultado;
}