#include <stdio.h>

#define green_text "\x1b[32m"
#define red_text "\x1b[31m"
#define reset_color "\x1b[0m"

/* Faça um programa que controle os estoque de 5 produtos em 5 armazéns de um supermercado, conforme figura abaixo:
O programa deverá ler o número da linha e da coluna, correspondente ao produto no armazém, 
e a quantidade a ser retirada do estoque. Caso a quantidade solicitada for menor ou igual a 
quantidade em estoque, o programa deverá emitir uma mensagem de atendimento e dar baixa no estoque. 
Do contrário, emitir mensagem, "Estoque com quantidade insuficiente para atender ao pedido". 
O programa termina quando o número da linha for igual a -1.  */


typedef struct{
    int qtdEstoque;
} Produto;
typedef struct{
    Produto produtos[6];
} Armazem;
Armazem armazens[6];



void printArmazens(){
    //print table
    printf("\n\t     Produto 1\t     Produto 2\t      Produto 3\t     Produto 4\t     Produto 5\n");    
    int armazem, produto;
      
    for(armazem = 1; armazem <= 5; armazem++){
        printf("\nArmazem %d\t", armazem);
        for (produto = 1; produto <= 5; produto++){
            printf("%d\t\t", armazens[armazem].produtos[produto].qtdEstoque);
        }
    }
}



int main(){             
    printf("\n");
    int armazem, produto, qtd;
    //define random numbers for qtdEstoque;
    srand(time(NULL));
    for(armazem = 1; armazem <= 5; armazem++){
        for (produto = 1; produto <= 5; produto++){
            armazens[armazem].produtos[produto].qtdEstoque = rand() % 500;
        }
    }
    printf("\n\n* Caso queira finalizar, digite -1 *\n\n");
    printArmazens();

    start:
    
    printf("\n");
    armazem = -1;

    while(armazem < 1 || armazem > 5){
        printf("\nQual armazem deseja alterar o estoque ? --> ");
        scanf("%d", &armazem);
            if(armazem == -1){
                printf("\n\nfim\n\n");
                return 0;

            } else if(armazem < 1 || armazem > 5){
                printf(red_text"\nArmazem inexistente, tente novamente.\n" reset_color);
            }
    }
    produto = -1;
    while(produto < 1 || produto > 5){
        printf("\nQual produto deseja alterar o estoque ? -->  ");
        scanf("%d", &produto);
        if(produto == -1){
            printf("\n\nfim\n\n");
            return 0;

        } else if(produto < 1 || produto > 5){
            printf(red_text"\nProduto inexistente, tente novamente.\n" reset_color);
        }
    }
    
    
    printf("\nQual a quantidade a ser retirada do estoque ? --> ");
    scanf("%d", &qtd);

        if(qtd == -1){
            printf("\n\nfim\n\n");
            return 0;
        }
            
        if(armazens[armazem].produtos[produto].qtdEstoque > qtd){
            printf(green_text "\nAtendimento realizado com sucesso!\n\n\n" reset_color);
            armazens[armazem].produtos[produto].qtdEstoque -= qtd;
        }else{ 
            printf(red_text "\nEstoque com quantidade insuficiente para atender ao pedido\n" reset_color);
        }

    printArmazens();
    goto start;

    return 0;
}

