#include <stdio.h>
#include <math.h>

int main(void){

  //programa que calcula a raiz de um numero.

    float numero, raiz;

    printf("Digite um numero: ");
    scanf("%f", &numero);

    raiz = sqrt(numero);

    printf("A raiz de %.2f é %.2f", numero, raiz);



    return 0;
}