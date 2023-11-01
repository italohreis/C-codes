#include <stdio.h>


    //Escreva uma função "calcula" que receba como parâmetros duas variáveis inteiras, X e Y, retorne em X a soma de X e Y, retorne em Y a subtração de X e Y. 

int main() {
 
    int x, y;

    printf("Digite o valor de x --> ");
    scanf("%d", &x);

    printf("Digite o valor de y --> ");
    scanf("%d", &y);

    Calculo(&x, &y);

    printf("\nX -->  %d\n", x);
    printf("\ny -->  %d\n", y);

    return 0;
}


int Calculo(int *x, int *y){
    int temp;
    temp = *x + *y;

    *y = *x - *y;

    *x = temp;
}