#include <stdio.h>
/* 1) Faça um programa que leia um valor de percentagem no formato decimal e faça uma função que retorne este valor em formato percentual.

2) Faça um programa que leia um valor de percentagem no formato decimal e faça um procedimento (não retorna valor) que transforme este mesmo valor em formato percentual.

3)Sobre os exercícios 1 e 2, compare suas respostas com estas abaixo. Em seguida explique cada código, linha a linha. Explique também qual é a diferença entre os dois códigos. */



float calcPorcentagem(float num){
    float porcentagem;

    porcentagem = num * 100;  

    return porcentagem;
}

int main(void){

    float num;

    printf("Digite um valor decimal --> ");
    scanf("%f", &num);

    printf("\nPorcentagem -->  %.2f%%\n", calcPorcentagem(num));



    return 0;
}