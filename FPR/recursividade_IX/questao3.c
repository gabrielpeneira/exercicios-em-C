#include <stdio.h>

void exibirMultiplo(int n, int v, int nf){
    
    if(n<=v){
        exibirMultiplo(n+nf,v,nf);
        printf("%i",n);
        printf("\n");
        
    }
}

int main(void)
{
    exibirMultiplo(5,40,5);

    return 0;
}