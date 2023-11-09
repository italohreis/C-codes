#include <stdbool.h>
#include <stdio.h>

#define red_text "\x1b[31m"
#define green_text "\x1b[32m"
#define reset_color "\x1b[0m"

typedef struct {
    int codigo;
    int cor;
    int quantidadeCarro;
} carro;
    carro carros[25];


void QuantidadeCarros(int code, int color, int *QuantidadeTotal, int *cCarros){
    int quantidade;
    printf("\nDigite a quantidade de carros --> ");
    scanf("%d", &quantidade);

    for (int i = 0; i < 25; i++){
        if (code == carros[i].codigo && color == carros[i].cor) {
            carros[i].quantidadeCarro += quantidade;
            *QuantidadeTotal += quantidade;

            if (*QuantidadeTotal > 150){
                printf(red_text "\nLimite de carros atingido.\n" reset_color);

                *QuantidadeTotal -= quantidade;

                carros[i].quantidadeCarro -= quantidade;

            }
            printf("Quant -> %d\n", carros[i].quantidadeCarro);
            return; 
        }

        if (carros[i].codigo == 0){
            *cCarros += 1;
            carros[i].codigo = code;
            carros[i].cor = color;
            carros[i].quantidadeCarro = quantidade;
            *QuantidadeTotal += quantidade;


            if (*QuantidadeTotal > 150){
                printf(red_text "\nLimite de carros atingido.\n" reset_color);

                *QuantidadeTotal -= quantidade;
                *cCarros -= 1;

                carros[i].codigo = 0;
                carros[i].cor = 0;
                carros[i].quantidadeCarro = 0;

            }
            return; // Saia da função após a inserção.
        }
    }
}

void RelatorioGeral(int QuantidadeTotal){
    float porcentagem;
    printf("\n\t< Relatorio geral >\n");
    printf("\n\tQuantidade total de carros: %d\n", QuantidadeTotal);

    for (int i = 0; i < 25; i++) {
        if (carros[i].codigo != 0) {
            printf("\n\tCodigo do carro: %d\n", carros[i].codigo);
            printf("\tCor do carro: --> ");

            switch (carros[i].cor){
                case 1:
                    printf("Branco\n");
                    break;
                case 2:
                    printf("Preto\n");
                    break;
                case 3:
                    printf("Vermelho\n");
                    break;
                case 4:
                    printf("Cinza\n");
                    break;
            }
            
        }
    }
    porcentagem = ((float) QuantidadeTotal * 100) / 150;

    printf("\n\tPorcentagem de ocupacao da garagem --> %.2f%%\n", porcentagem);
    return;
}

void RelatorioCor(int color){
    int quantidade = 0;
    printf("\n< Relatorio por cor >\n");
    printf("\n\tCor dos carros --> ");
    switch(color){
        case 1:
            printf("Branco\n");
            break;
        case 2:
            printf("Preto\n");
            break;
        case 3:
            printf("Vermelho\n");
            break;
        case 4:
            printf("Cinza\n");
            break;
    }

    for (int i = 0; i < 25; i++) {
        if (carros[i].cor == color){
            printf("\n\tCodigo do carro: %d\n", carros[i].codigo);

            quantidade += carros[i].quantidadeCarro;
        }
    }
    
    printf("\nQuantidade total de carros da cor -->  %d\n", quantidade);
    return;
}

void RelatorioCodigo(int code){
    int quantidade = 0;
    printf("\n< Relatorio por codigo >\n");

    for (int i = 0; i < cCarro; i++) {
        if (carros[i].codigo == code) {
            printf("\tCor do carro --> ");

            switch (carros[i].cor){
                case 1:
                    printf("branco\n");
                    break;
                case 2:
                    printf("preto\n");
                    break;
                case 3:
                    printf("vermelho\n");
                    break;
                case 4:
                    printf("cinza\n");
                    break;
            }
            quantidade += carros[i].quantidadeCarro;
        }
    }
    printf("\n\tQuantidade total de veiculos do codigo fornecido-->  %d\n", quantidade);
    return;
}

void BuscaVeiculo(int code, int color, int cCarros){
    int i;

    for(i = 0; i < cCarros; i++){
        if((carros[i].codigo == code) && (carros[i].cor == color)){
            
            printf("\n\tQuantidade de veiculos --> %d\n", carros[i].quantidadeCarro);
            return;
        } 
    }

    printf(red_text "\nVeiculo nao encontrado.\n" reset_color);
    return;
}