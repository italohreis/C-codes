#include <stdio.h>


int numero(int num){
    
    if(num > 0){
        return 1;

    } else if(num < 0){
        return -1;

    } else {
        return 0;
    }

}

int main(void){

    int num;

    printf("Digite um numero --> ");
    scanf("%d", &num);

    printf("\n");

    if(numero(num) == 1){
        printf("O numero e positivo.\n");
    } else if(numero(num) == -1){
        printf("\nO numero e negativo\n");
    } else{
        printf("\nO numero e igual a 0.\n");
    }
    

}