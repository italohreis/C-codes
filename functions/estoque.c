#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define red_text "\x1b[31m"
#define green_text "\x1b[32m"
#define reset_color "\x1b[0m"

/* Crie um programa em C para gerenciar o estoque de 10 lojas. O programa deve permitir:

Adicionar produtos ao estoque (cada produto terá um código único, nome, quantidade em estoque e preço).
Vender produtos, atualizando a quantidade em estoque e calculando o total da compra. 

Relatorio Geral: Listar todos os produtos de todas as lojas com suas informações.

Relatorio por loja: dado o numero da loja, listar todos os produtos da loja com as informações.

Relatorio por produto: dado o codigo do produto e a loja, mostrar suas informações 

Saldo de vendas da loja. */

//prototipo das funcoes
void Menu();
void RelatorioGeral();
void RelatorioLoja();
void RelatorioProduto();
void VenderProduto();
void SaldoVendas();

typedef struct{
    int codigo;
    char nome[30];
    int estoque;
    float preco;

} produto;


typedef struct{
    produto produtos[100];
    float saldoVendas;
} loja;
loja lojas[10];

int cProdutos[10] = {0}, cLojas = 0;  

int main(void){
    
    int loja;
    int resp;
    bool codigoExistente = false;

    printf("* Caso queira parar de inserir as lojas, digite -1 no codigo do produto *\n\n");

    for(loja = 0; loja < 10; loja++){
        printf("\n* Loja %d *\n", loja);

        do{
            printf("\n\t< Produto %d >\n", cProdutos[loja]);

            do{
                codigoExistente = false;
                printf("\n\tInforme o codigo do produto --> ");
                scanf("%d", &lojas[loja].produtos[cProdutos[loja]].codigo);

                int i;
                for(i = 0; i < cProdutos[loja]; i++){

                    if(lojas[loja].produtos[cProdutos[loja]].codigo == lojas[loja].produtos[i].codigo){
                        printf(red_text "\n\tCodigo ja existente, tente novamente.\n" reset_color);
                        codigoExistente = true;
                    }
                }
                
                if(lojas[loja].produtos[cProdutos[loja]].codigo == -1){
                    Menu();      
                }
            } while(codigoExistente == true);

            printf("\n\tQual o nome do produto ? --> ");
            scanf("%s", lojas[loja].produtos[cProdutos[loja]].nome);

            printf("\n\tInforme a quantidade em estoque do produto --> ");
            scanf("%d", &lojas[loja].produtos[cProdutos[loja]].estoque);

            printf("\n\tInforme o preco do produto --> ");
            scanf("%f", &lojas[loja].produtos[cProdutos[loja]].preco);

            cProdutos[loja]++;

            resp = -1;
            while(resp != 0 && resp != 1){
                printf("\n\tDeseja adicionar outro produto ? (1 - sim / 0 - nao) --> ");
                scanf("%d", &resp);

                if(resp != 0 && resp != 1){
                    printf(red_text "\n\tResposta invalida, tente novamente.\n" reset_color);
                }
            }

        } while(resp == 1);
        
        cLojas++;
    }

    Menu();

    return 0;
}



void Menu(){
    system("cls");      //limpa a tela
    while(1){

        int op;
        printf("\n\nO que deseja fazer ?\n");
        printf("\n 1 - Relatorio Geral.\n 2 - Relatorio por loja.\n 3 - Relatorio por produto.\n 4 - Vender produtos.\n 5 - Mostrar Saldo de vendas.\n 6 - finalizar.\n");
        scanf("%d", &op);

        switch(op){

            case 1:
                RelatorioGeral();
                break;

            case 2:
                RelatorioLoja();
                break;


            case 3:
                RelatorioProduto();
                break;

            case 4:
                VenderProduto();
                break;

            case 5:
                SaldoVendas();
                break;
                
            case 6:
                printf("\n\nFim.\n\n");
                exit(0);

            default:
                printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
                break;
        }
    }
}


void RelatorioGeral(){  //cProdutos declarado como um ponteiro para array de inteiros

    int loja, produto;
    for(loja = 0; loja < cLojas; loja++){
        printf("\n* Loja %d *\n", loja);
        for(produto = 0; produto < cProdutos[loja]; produto++){
            printf("\n\t--------------------------------------------------------------\n");
            printf("\n\t< Produto %d >\n", produto);

            printf("\n\t\tCodigo do produto --> %d", lojas[loja].produtos[produto].codigo);
            printf("\n\t\tNome do produto --> %s", lojas[loja].produtos[produto].nome);
            printf("\n\t\tQuantidade em estoque --> %d", lojas[loja].produtos[produto].estoque);
            printf("\n\t\tPreco do produto --> R$ %.2f\n", lojas[loja].produtos[produto].preco);

        }
        printf("\n\t--------------------------------------------------------------\n");

    }

    return;
}


void RelatorioLoja(){
    int numLoja, produto;
    
    numLoja = -1;
    while(numLoja < 0 || numLoja > cLojas - 1){
        printf("\nQual loja deseja consultar ? --> ");
        scanf("%d", &numLoja);

        if(numLoja < 0 || numLoja > cLojas - 1){
            printf(red_text "\nLoja nao encontrada, tente novamente.\n" reset_color);
        }
    }

    for(produto = 0; produto < cProdutos[numLoja]; produto++){
        printf("\n\t--------------------------------------------------------------\n");
        printf("\n\t< Produto %d >\n", produto);

        printf("\n\t\tCodigo do produto --> %d", lojas[numLoja].produtos[produto].codigo);
        printf("\n\t\tNome do produto --> %s", lojas[numLoja].produtos[produto].nome);
        printf("\n\t\tQuantidade em estoque --> %d", lojas[numLoja].produtos[produto].estoque);
        printf("\n\t\tPreco do produto --> R$ %.2f\n", lojas[numLoja].produtos[produto].preco);


    }
        printf("\n\t--------------------------------------------------------------\n");

    return;
}


void RelatorioProduto(){

    int numLoja, numProduto;

    numLoja = -1;
    while(numLoja < 0 || numLoja > cLojas - 1){

        printf("\nQual loja ? --> ");
        scanf("%d", &numLoja);

        if(numLoja < 0 || numLoja > cLojas - 1){
            printf(red_text "\nLoja nao encontrada, tente novamente.\n" reset_color);
        }
    }

    printf("\nQual o codigo do produto que deseja consultar ? --> ");
    scanf("%d", &numProduto);

    int loja, produto;
    for(loja = 0; loja < cLojas; loja++){
        for(produto = 0; produto < cProdutos[loja]; produto++){

            if(lojas[loja].produtos[produto].codigo == numProduto && loja == numLoja){
                printf("\n\t--------------------------------------------------------------\n");
                printf("\n\t< Produto %d >", produto);

                printf("\n\tCodigo do produto --> %d", lojas[loja].produtos[produto].codigo);
                printf("\n\tNome do produto --> %s", lojas[loja].produtos[produto].nome);
                printf("\n\tQuantidade em estoque --> %d", lojas[loja].produtos[produto].estoque);
                printf("\n\tPreco do produto --> R$ %.2f\n", lojas[loja].produtos[produto].preco);
                printf("\n\t--------------------------------------------------------------\n");

                return;
            }
        }
    }

    printf(red_text "\n\tProduto nao encontrado.\n" reset_color);   //caso o produto nao seja encontrado no loop for

    return;
}



void VenderProduto(){

    int numLoja, numProduto, quantidade;

    numLoja = -1;
    while(numLoja < 0 || numLoja > cLojas - 1){
        printf("\nQual a loja ? --> ");
        scanf("%d", &numLoja);

        if(numLoja < 0 || numLoja > cLojas - 1){
            printf(red_text "\nLoja nao encontrada, tente novamente.\n" reset_color);
        }
    }

    printf("\nQual codigo do produto que deseja vender ? --> ");
    scanf("%d", &numProduto);

    int produto;
    for(produto = 0; produto < cProdutos[numLoja]; produto++){

        if(lojas[numLoja].produtos[produto].codigo == numProduto){
            
            if(lojas[numLoja].produtos[produto].estoque == 0){
                printf(red_text "\n\tProduto esgotado.\n" reset_color);
                return;
            }

            printf("\n\t--------------------------------------------------------------\n");
            printf("\n\tProduto %d\n", produto);

            printf("\n\tCodigo do produto --> %d", lojas[numLoja].produtos[produto].codigo);
            printf("\n\tNome do produto --> %s", lojas[numLoja].produtos[produto].nome);
            printf("\n\tQuantidade em estoque --> %d", lojas[numLoja].produtos[produto].estoque);
            printf("\n\tPreco do produto --> R$ %.2f\n", lojas[numLoja].produtos[produto].preco);
            printf("\n\t--------------------------------------------------------------\n");

            quantidade = -1;
            while(quantidade > lojas[numLoja].produtos[produto].estoque || quantidade < 0){
                printf("\n\tQual a quantidade a ser vendida do produto ? --> ");
                scanf("%d", &quantidade);

                if(quantidade > lojas[numLoja].produtos[produto].estoque){
                    printf(red_text "\n\tQuantidade em estoque insuficiente, tente novamente.\n" reset_color);
                }
            }

            printf(green_text "\n\tVenda realizada com sucesso!\n" reset_color);
            printf(green_text "\n\tValor total da venda --> R$ %.2f\n" reset_color, quantidade * lojas[numLoja].produtos[produto].preco);

            lojas[numLoja].produtos[produto].estoque -= quantidade;

            lojas[numLoja].saldoVendas += quantidade * lojas[numLoja].produtos[produto].preco;
                
            return;
        }
    }

    printf(red_text "\n\tProduto nao encontrado.\n" reset_color);   //caso o produto nao seja encontrado no loop for
    return;
}


void SaldoVendas(){
    int numLoja;

    numLoja = -1;
    while(numLoja < 0 || numLoja > cLojas - 1){
        printf("\nQual loja deseja consultar o saldo de vendas ? -->");
        scanf("%d", &numLoja);

        if(numLoja > cLojas - 1 || numLoja < 0){
            printf(red_text "\nLoja nao encontrada, tente novamente.\n" reset_color);
        }
    }

    printf("\n\tSaldo de vendas da loja %d --> R$ %.2f\n", numLoja, lojas[numLoja].saldoVendas);

    return;
}