#include <stdio.h>

/* 1) Faça um programa que leia um valor de percentagem no formato decimal e faça uma função que retorne este valor em formato percentual.

2) Faça um programa que leia um valor de percentagem no formato decimal e faça um procedimento (não retorna valor) que transforme este mesmo valor em formato percentual.

3)Sobre os exercícios 1 e 2, compare suas respostas com estas abaixo. Em seguida explique cada código, linha a linha. Explique também qual é a diferença entre os dois códigos. */

//a diferença é que o segundo codigo não tem valor de retorno.


void CalcPorcentagem(float* num){
    *num = *num * 100;
}
            
int main(void){

    float num;
    int i;
    for(i = 0; i<5; i++){

        printf("Digite um valor decimal --> ");
        scanf("%f", &num);

        CalcPorcentagem(&num);

        printf("%.2f%%\n", num);
    }

    
    return 0;

}

