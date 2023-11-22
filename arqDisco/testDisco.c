#include <stdio.h>

int main(void){

    FILE *arquivo;
    char texto[100];

    arquivo = fopen("tes.txt", "a");

    printf("Digite o texto que deseja escrever no arquivo: ");
    fgets(texto, 100, stdin);

    fprintf(arquivo, "%s", texto);

    printf("\nDados salvo com successo!\n");

    fclose(arquivo);

    return 0;
}