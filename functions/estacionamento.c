#include <stdio.h>

#define RED_TEXTO  "\x1b[31m"
#define reset_color "\x1b[0m"

    //Uma garagem de estacionamento cobra $2,00 de taxa mínima para estacionar até
    //três horas. A garagem cobra um adicional de $0,50 por hora ou fração caso sejam
    //excedidas as três horas. A taxa máxima para qualquer período determinado de 24
    //horas é $10,00. Admita que nenhum carro fique estacionado por mais de 24 horas.
    //Escreva um programa que calcule e imprima as taxas de estacionamento para três
    //clientes que estacionaram ontem seus carros nessa garagem. Você deve fornecer as
    //horas que cada cliente ficou estacionado. Seu programa deve imprimir os
    //resultados organizados em um formato de tabela e deve calcular e imprimir o total
    //recebido no dia de ontem. O programa deve usar a função calcula-Taxas para
    //determinar o valor a ser cobrado de cada cliente. A saída de seu programa deve ter
    //o seguinte formato:

float calcTaxa(float horas){
    float taxa = 0;
    
    if(horas <= 3){
        taxa = 2;
    }else if(horas > 3 && horas <= 24){
        taxa = 2 + ((horas - 3) * 0.5);
    }
    if (taxa > 10){
        taxa = 10;
    }
    return taxa;
}

    typedef struct{
        float horas;
        float taxa;
        
    } cliente;
    cliente clientes[1000];
    

int main(){
    int cCliente = 0;
    int resp = 0;
    
    repetir:
    printf("\n");
    cCliente++;
    printf("* Cliente %d *\n", cCliente);

    printf("\tDigite a quantidade de horas que o carro ficou estacionado --> ");
    scanf(" %f", &clientes[cCliente].horas);
    
    clientes[cCliente].taxa = calcTaxa(clientes[cCliente].horas);

    resp = -1;
    while(resp != 0 && resp != 1){
        printf("\n\tDeseja continuar para outro cliente ? (1 - sim / 0  - nao) --> ");
        scanf("%d", &resp);
        if (resp != 0 && resp != 1){
            printf(RED_TEXTO"\nResposta invalida, tente novamente.\n"reset_color);
        }
            if (resp == 1){
                goto repetir;
            }
        }
    
    printf("\n\n");
    printf("Carro\t\tHoras\t\tTaxa\n");
    
    int i;
    for(i = 1; i <= cCliente; i++){
        printf("\n");
        printf("%d", i);
        printf("\t\t%.2f",  clientes[i].horas);
        printf("\t\t%.2f", clientes[i].taxa);   
    }
    printf("\n\n");
    return 0;
}
