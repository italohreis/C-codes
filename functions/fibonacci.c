#include <stdio.h>
#include <math.h>

//serie de fibonacci

int fibonacci(int valor);

int main() {
    
    int valor;

    printf("\nDigite a serie de fibonacci --> ");
    scanf("%d", &valor);

    for(int i = 0; i < valor; i++){
        printf("%d ", fibonacci(i));
    }

    return 0;
}


int fibonacci(int valor){
    //recursividade
    if (valor <= 1) return 1;

    return fibonacci(valor - 1) + fibonacci(valor - 2); 

}
