#include <stdio.h>
#include <string.h>

/* Questão 01:
Implementar uma função que, dada uma string
s, determine a quantidade de caracteres
distintos em s. */

int distintos(int tam, char s[tam]);

int main(void){

  char s[30]="gabriel";

  printf("%d",distintos(30,s));
  
}
int distintos(int tam, char s[tam]){

  int j,len,contador;
  char distintos[tam];
  distintos[0]='\0';
  for(int i =0;s[i];i++){

    contador=0;
      
    for(j=0;distintos[j] && distintos[0]!='\0';j++){

      if(s[i]!=distintos[j]){

        contador++;
      }
      len=strlen(distintos);
      if(contador==len || len==0){

        distintos[j]=s[i];
        distintos[j+1]='\0';
      }
    }
  }
  return strlen(distintos);
}