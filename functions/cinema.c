#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//programa de matriz de cadeiras de cinema em forma visual
//o programa mostra aleatoriamente cadeiras já ocupadas
//usuario escolhe a cadeira com base na linha e coluna.
//e o programa marca a cadeira como ocupada.
    
#define RED_TEXT "\x1b[31m"
#define BLUE_TEXT "\x1b[34m"
#define YELLOW_TEXT "\x1b[33m"
#define PINK_TEXT "\x1b[35m"
#define GREEN_TEXT "\x1b[32m"
#define RESET_COLOR "\x1b[0m"
#define SQUARE "\u25A0"
int cadeiras[10][10] = {0};

void PrintMatrix();
void SelecionarCadeira();


int main() {
    
    //definir as cadeiras ocupadas de forma aleatoria
    int i;
    for (i = 0; i < 10; i++) {
        int j;
        for (j = 0; j < 10 ; j++) {
            cadeiras[i][j] = rand() % 2;
        }
    }   

    PrintMatrix();
    SelecionarCadeira();
        
    return 0;
}

void PrintMatrix(){
    printf(RESET_COLOR);
    printf("----------MAPA DE CADEIRAS----------\n");
    printf("\n");
    printf("     1  2  3  4  5  6  7  8  9  10\n");

    int i;
    for (i = 1; i <= 10; i++) {
        printf(RESET_COLOR);
        if (i < 10) {
            printf(" ");
        }
        printf("%d   ", i);

        int j;
        for (j = 1; j <= 10 ; j++){
            if (cadeiras[i][j] == 0) {
                printf(GREEN_TEXT SQUARE "", RESET_COLOR);
            } else {
                printf(RED_TEXT SQUARE "", RESET_COLOR);
            }
            printf("  ");
        }
        printf("\n");        
    }
}

void SelecionarCadeira(){
    printf("\n");
    int linha, coluna;
    printf("\n");
    printf(RESET_COLOR);
    
    printf("Reserve seu assento!\n\n");
    
    printf("Qual a linha da cadeira que deseja reservar? -->  ");
    scanf("%d", &linha);

    printf("\nQual a coluna da cadeira que deseja reservar? -->  ");
    scanf("%d", &coluna);

    if (cadeiras[linha][coluna] == 0) {
        cadeiras[linha][coluna] = 1;
        printf(BLUE_TEXT "\nCadeira reservada com sucesso!\n" RESET_COLOR);
    } else {
        printf(RED_TEXT "\nCadeira já reservada, por favor escolha outra.\n" RESET_COLOR);
        SelecionarCadeira();
    }
    printf("\n");

    PrintMatrix();

    int resp;
    printf("\n");
    printf(RESET_COLOR);

    printf("Deseja selecionar outra cadeira? (1 - Sim / 0 - nao) --> ");
    scanf("%d", &resp);

    if (resp == 1){
        SelecionarCadeira();
    } else{
        return;
        printf("\n");
    }
}