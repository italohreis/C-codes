#include <stdio.h>
#include <math.h>

#define red_text  "\x1b[31m"
#define reset_color "\x1b[0m"

 //faça um programa em linguagem C para encontrar as raízes de uma equação do 2° grau com a fórmula de Bháskara. 

int main(void){

    float a, b, c, delta, x1, x2;

    a = 0;
    while(a == 0){
        printf("Digite o valor de a: ");
        scanf("%f", &a);

        if(a == 0){
            printf("\nValor invalido, tente novamente\n");
        }
    }

    printf("Digite o valor de b: ");
    scanf("%f", &b);

    printf("Digite o valor de c: ");
    scanf("%f", &c);

    delta = pow(b, 2) - (4*a*c);

    if(delta < 0){
        printf("Nao existe raiz real");
    } else if(delta == 0){
        x1 = (-b + sqrt(delta)) / (2*a);
        printf("A raiz e: %.2f", x1);
    } else {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        printf("As raizes sao: %.2f e %.2f", x1, x2);
    }

    return 0;

}