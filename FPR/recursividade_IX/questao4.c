#include <stdio.h>

/*Questão 04:
Fazer uma função recursiva que, dado um
número inteiro N, exiba o mesmo na base 2
(binária).*/

void binario(int n){
    
    if(n>0){
        binario(n/2);
        printf("%i",n%2);
        
    }
}

int main()
{
    binario(10);
    
    return 0;
}
