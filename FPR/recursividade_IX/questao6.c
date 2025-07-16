#include <stdio.h>

/*Questão 06:
Dada uma string s, desenvolver uma função
recursiva que determine se s é ou não um
palíndromo.*/
int ehPalindromo(int i, int j, char s[]);

int main(void) {
    char s[] = "arara"; 
    printf("%d\n", ehPalindromo(0, 4, s));
}

int ehPalindromo(int i, int j, char s[]) {
    if (i >= j) {
        return 1;
    }

    
    if (s[i] != s[j]) {
        return 0; 
    }

    return ehPalindromo(i + 1, j - 1, s);
}