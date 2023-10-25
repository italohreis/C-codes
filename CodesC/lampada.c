#include <stdio.h>
#include <math.h>

#define red_text "\x1b[31m"
#define reset_color "\x1b[0m"

/* Faça um programa C para calular o número de lâmpadas 60 watts necessárias para um determinado cômodo. 
O programa deverá ler um conjunto de informações, tais como: tipo, largura e comprimento do cômodo. 
O programa termina quando o tipo de cômodo for igual -1. A tabela abaixo mostra, para cada tipo de cômodo, 
a quantidade de watts por metro quadrado. 

Dica: Use uma estrutura struct para agrupar logicamente as informações de um comodo 
(int tipo de comodo, float largura e float altura). Usar uma função (float CalulaArea) 
para calcular a área do cômodo. Os atributos de entrada serão a largura e comprimento do cômodo.
 
Usar uma função (float Lampada) para calcular a quantidade de lâmpadas necesárias para o cômodo. 
Os atributos de entrada serão o tipo de cômodo e a metragem (em m2) do cômodo.

12 15 18 20 22

Obs: Utilize a função ceil(numero) em #include math.h para realizar o arrendondamento para cima. */

typedef struct {
    float largura;
    float altura;
    int tipo;
    float area;
    float potencia;
    float potenciaTotal;
    float lampada;
} Comodo;
Comodo Comodos[10];


int main(void){
    comodo:
    printComodo();

    printf("\nnumero do comodo --> ");
    int numComodo;
    scanf("%d", &numComodo);

    if(numComodo == -1){
        printf("\n\nfim\n\n");
        return 0;
    }
    
    printf("\n");
    Comodos[numComodo].tipo = -1;

    while(Comodos[numComodo].tipo < 1 || Comodos[numComodo].tipo > 5){
        printf("Digite o tipo de comodo --> ");
        scanf("%d", &Comodos[numComodo].tipo);

        if(Comodos[numComodo].tipo == -1){
            printf("\n\nfim\n\n");
            return 0;
        } else if (Comodos[numComodo].tipo < 1 || Comodos[numComodo].tipo > 5){
            printf(red_text "\nComodo invalido, tente novamente\n" reset_color);
        }
    }

    printf("\n");

    printf("Digite a largura do comodo --> ");
    scanf("%f", &Comodos[numComodo].largura);

    printf("\n");

    printf("Digite a altura do comodo --> ");
    scanf("%f", &Comodos[numComodo].altura);

    printf("\n");
    
    
    definePotencia(numComodo);
    defineArea(numComodo);
    defineLampada(numComodo);
    
    printf("\nA quantidade de lampadas necessarias para o comodo e --> %.0f\n", Comodos[numComodo].lampada);
        goto comodo;
    }

int definePotencia(int numComodo){
    switch(Comodos[numComodo].tipo) {
    case 1:
        Comodos[numComodo].potencia = 12;
        break;
    case 2:
        Comodos[numComodo].potencia = 15;
        break;
    case 3:
        Comodos[numComodo].potencia = 18;
        break;
    case 4:
        Comodos[numComodo].potencia = 20;
        break;
    case 5:
        Comodos[numComodo].potencia = 22;
        break;
    }
}

void defineArea(int numComodo){
    Comodos[numComodo].area = Comodos[numComodo].largura * Comodos[numComodo].altura;
}

void defineLampada(int numComodo){
    Comodos[numComodo].potenciaTotal = Comodos[numComodo].area * Comodos[numComodo].potencia;
    Comodos[numComodo].lampada = ceil(Comodos[numComodo].potenciaTotal / 60);
}

void printComodo(){
    printf("\nTipo Comodo    Potencia\n");
    
        printf("1\t\t 12W\n");
        printf("2\t\t 15W\n");
        printf("3\t\t 18W\n");
        printf("4\t\t 20W\n");
        printf("5\t\t 22W\n");
        

}