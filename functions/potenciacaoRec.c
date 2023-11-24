#include <stdio.h>
#include <math.h>   

//potenciacao com recursividade

float CalcularPotencia(int base, int expoente); 

int main(){
    
    int base, expoente, resultado;

    printf("Digite a base --> ");
    scanf("%d", &base);

    printf("\nDigite o expoente --> ");
    scanf("%d", &expoente);

    CalcularPotencia(base, expoente);

    resultado = CalcularPotencia(base, expoente);

    printf("\nResultado: %d\n", resultado);

    return 0;
}


float CalcularPotencia(int base, int expoente){
    //recursividade
    if (expoente == 1) return base;

    return base * CalcularPotencia(base, expoente - 1);
}
