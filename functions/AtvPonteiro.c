#include <stdio.h>


/* Observe os seguintes problemas e responda: A passagem dos parâmetros para  cada função deve ser por valor ou por referência? Após implemente-os em linguagem C.

1) Fazer uma função que receba 3 números como parâmetros: A, B e C. Então Ordene de tal forma que, ao final da função, A contenha o menor número e C o maior. 
Fazer um programa que receba 3 números do usuário, chame a função e mostre os números ordenados.

2) Escreva uma função "calcula" que receba como parâmetros duas variáveis inteiras, X e Y, retorne em X a soma de X e Y, retorne em Y a subtração de X e Y. 

3) Implementar a função
float power (float base, float expoente)
que retorna o valor de base elevado a expoente. Considere que o expoente deve ser um inteiro não negativo.

4) Escreva uma função que calcule e retorne a distância, em um plano cartesiano, entre dois pontos (x1, y1) e (x2, y2). 

5) Escreva o código fonte de um programa, na linguagem C, que manipule um vetor de inteiros com dez elementos. O programa deve possuir uma função responsável pela inicialização do vetor, 
outra função que efetue a impressão do vetor na saída padrão e outra para ler o vetor através do teclado.

6) Fazer o algoritmo para deslocamento de um elemento em vetor para a direita e o algoritmo para deslocamento de um elemento em vetor para a esquerda.  */


int FuncaoPonteiro(int *a, int *b, int *c);

int main(void){

int a, b, c;

    printf("Digite o numero A --> ");
    scanf("%d", &a);

    printf("Digite o numero B --> ");
    scanf("%d", &b);

    printf("Digite o numero C --> ");
    scanf("%d", &c);

    FuncaoPonteiro(&a, &b, &c);

    printf("\n A: %d\n B: %d\n C: %d\n", a, b, c);

    return 0;
}

int FuncaoPonteiro(int *a, int *b, int *c){         

    int temp;
    if(*a > *b){
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c){
        
        temp = *a;
        *a = *c;
        *c = temp;
    } 
    if (*b > *c){
        
        temp = *b;
        *b = *c;
        *c = temp;
    }

    
}