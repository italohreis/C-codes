#include <stdio.h>

    //Faça uma função que recebe um valor inteiro e verifica se o valor é par. A função deve retornar 1 se o número for par e 0 se for ímpar.

int numero(int);  //prototipo

int main(void){
    int numeros;
    printf("Digite um numero --> ");
    scanf("%d", &numeros);

    if(numero(numeros) == 1){
        printf("O numero %d é par\n", numeros);
    } else {
        printf("O numero %d é impar\n", numeros);
    }

}

    int numero (int num){

        if(num % 2 == 0){
            return 1;
        } else {
            return 0;
        }
    }