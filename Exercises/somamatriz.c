#include <stdio.h>

int main(void){

//Faça um programa que permita ao usuário entrar com uma matriz de 3 x 3 números
//inteiros. Em seguida, gere um vetor pela soma dos números de cada coluna da
//matriz e mostrar na tela esse vetor. Por exemplo, a matriz:

int i, j, matriz[3][3], soma[3];

for(i=0; i<3; i++){
    soma[i] = 0;
}

for(i=0; i<3; i++){
    for(j=0; j<3; j++){
        printf("Digite o numero da linha %d coluna %d --> ", i, j);
        scanf(" %d", &matriz[i][j]);

    
    }
}
printf("\n");
for(i=0; i<3; i++){
    for(j=0; j<3; j++){
        printf("[%d]\t", matriz[i][j]);
    }
    printf("\n");
}

for(i=0; i<3; i++){
    for(j=0; j<3; j++){
    soma[i] += matriz[j][i];
    }
}
printf("\n\n");
for(i=0; i<3; i++){
    printf("Soma da coluna %d: %d\n", i, soma[i]);
}

}