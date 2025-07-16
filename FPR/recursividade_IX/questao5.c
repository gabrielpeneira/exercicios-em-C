#include <stdio.h>

void pg(int n,int v, int nf);

int main()
{
    pg(5,5,5);

    return 0;
}
void pg(int n,int v, int nf){
    
  if(v>0){
      
      pg(n*nf,v-1,nf);
      printf("%d",n);
      printf("\n");
      
  }  
}