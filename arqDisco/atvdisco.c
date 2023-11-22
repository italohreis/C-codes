#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Observe o exemplo dado na aula do dia 01/11 e faça um programa que leia uma matriz 10x4 de números inteiros e salve esta matriz
em um arquivo binário chamado testmatriz. 
Faça então outro programa que abra o arquivo testmatriz e coloque os valores contidos nele em uma outra matriz 10x4.  */


int main(void){

    int matriz[10][4];

    FILE *testmatriz;

    testmatriz = fopen("testmatriz.txt", "wb");

    //generate rand numbers in matriz[10][4]

    int i, j;
    srand(time(NULL));
    for(i = 0; i < 10; i++){
        for(j = 0; j < 4; j++){
            matriz[i][j] = rand() % 20;
        }
    }

    fwrite(matriz, sizeof(int), 10*4, testmatriz);

    fclose(testmatriz);

}