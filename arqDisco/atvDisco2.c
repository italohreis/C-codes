#include <stdio.h>

int main(){
    
    int matrix[10][4];
    FILE *arquivo;

    arquivo = fopen("testmatriz.txt", "r");

    size_t dadosLidos = fread(matrix, sizeof(int), 10*4, arquivo);

    int i, j;

    fclose(arquivo);

    for(i = 0; i < 10; i++){
        for(j = 0; j < 4; j++){
            printf("[%d]\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
