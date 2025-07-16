#include <stdio.h>

/*Questão 08:
Desenvolver uma função recursiva que, dada
uma string, exiba-a invertida.*/

void contrario(int i,char s[]);
int main(void){

    char s[20]="gabriel";

    contrario(0,s);
    
}
void contrario(int i,char s[]){

    if(s[i]!='\0'){

        contrario(i+1,s);
        printf("%c",s[i]);
    }
}