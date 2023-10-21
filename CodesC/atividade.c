#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

#define red_text "\x1b[31m"
#define reset_color "\x1b[0m"


/*Uma loja de eletr�nicos mant�m o controle de seu estoque de produtos. 
A loja possui diversos produtos, cada um com um c�digo, descri��o, pre�o e quantidade em estoque.
 A loja deseja criar um programa para gerenciar esse estoque.

Crie um programa em C que permita ao usu�rio realizar as seguintes opera��es:

Inserir um novo produto no estoque. O usu�rio deve fornecer o c�digo, descri��o, pre�o e quantidade em estoque do produto.

Atualizar a quantidade em estoque de um produto existente. O usu�rio deve fornecer o c�digo do produto e 
a quantidade a ser adicionada (ou subtra�da) do estoque.

Exibir o valor total em estoque de um determinado produto. O usu�rio deve fornecer o c�digo do produto, 
e o programa deve calcular o valor total em estoque considerando o pre�o e a quantidade em estoque.

Exibir a lista de todos os produtos em estoque, incluindo c�digo, descri��o, pre�o e quantidade.

Calcular e mostrar o valor total em estoque de todos os produtos da loja.

Sair do programa.
O programa deve ser executado em um loop, permitindo ao usu�rio realizar as opera��es acima quantas vezes desejar at� que escolha sair.
Lembre-se de validar as entradas do usu�rio e tratar poss�veis erros (por exemplo, produtos com o mesmo c�digo n�o devem ser inseridos). */
 

typedef struct {
    int codigoProduto;
    char desc[100];
    float preco;
    float estoque;
    float valorTotaldoProduto;
}produto;
produto produtos[100000];
 
int InserirProduto(int codigo){
    produtos[codigo].codigoProduto = codigo;
    
    printf("\nDescricao do produto ? --> ");        
    scanf(" %s", & produtos[codigo].desc);
    
    printf("\nQual o preco do produto ? --> ");
    scanf("%f", & produtos[codigo].preco);

    printf("\nQual o estoque do produto ? --> ");
    scanf("%f", & produtos[codigo].estoque);

    produtos[codigo].valorTotaldoProduto = produtos[codigo].preco * produtos[codigo].estoque;
    
}

int AtualizarQuantidade(int codigo){
    printf("\nQuantidade atual em estoque -->  ");
    printf("%.2f" , produtos[codigo].estoque);

    printf("\n");
    
    printf("\nDigite a nova quantidade em estoque -->  ");
    scanf("%f", & produtos[codigo].estoque);

    produtos[codigo].valorTotaldoProduto = produtos[codigo].preco * produtos[codigo].estoque;
}

int ValorProdutoEmEstoque(int codigo){
    printf("\nValor total do produto %d em estoque -->  R$ %.2f" , produtos[codigo].codigoProduto, produtos[codigo].valorTotaldoProduto);
    
}

void ListaDeProdutosEmEstoque(){  
    int i;
    for(i = 1; i <= 100000; i++){
        if (produtos[i].preco > 0){
            printf("\n\n\tCodigo do produto --> %d\n", produtos[i].codigoProduto);
            printf("\tDescricao do produto --> %s\n", produtos[i].desc);
            printf("\tPreco do produto --> R$ %.2f\n", produtos[i].preco);
            printf("\tEstoque do produto --> %.2f\n", produtos[i].estoque);
            printf("\tValor total do produto em estoque --> R$ %.2f\n", produtos[i].valorTotaldoProduto); 
            
        }
    }
}

void ValorTotalEmEstoque(){ 

    float valorTotalGeralEmEstoque = 0;
    int i;
    for(i = 1; i <= 100000; i++){
        if (produtos[i].preco > 0){
            valorTotalGeralEmEstoque += produtos[i].valorTotaldoProduto;
        }
    }
    printf("\n\n\tValor total em estoque --> R$ %.2f\n", valorTotalGeralEmEstoque);
    
}


int main(void){     
    setlocale(LC_ALL, "Portuguese_Brazil");

    int resp;
    while(true){

        printf("\n\n\no que deseja fazer ?\n 1 - Inserir um novo produto no estoque.\n 2 - Atualizar a quantidade em estoque de um produto.\n 3 - Exibir o valor total em estoque de um produto\n"
            " 4 - Exibir a lista de todos os produtos em estoque.\n 5 - Calcular e mostrar o valor total em estoque de todos os produtos da loja.\n 6 - Finalizar.\n");
        scanf("%d", &resp);

        switch(resp){
            int codigo;
            case 1:

                    printf("\nInsira o codigo do produto --> ");    //Lembre-se de validar as entradas do usu�rio e tratar poss�veis erros            
                    scanf("%d", & codigo);                           //(por exemplo, produtos com o mesmo c�digo n�o devem ser inseridos)
                    if(produtos[codigo].codigoProduto == codigo){
                        printf(red_text "\nCodigo ja existente, tente novamente.\n" reset_color);
                        break;
                    }
                    else{
                        InserirProduto(codigo);
                    }

                break;

            case 2:
                printf("\nQual o codigo do produto ? --> ");
                scanf("%d", & codigo);
                if(produtos[codigo].codigoProduto != codigo){
                    printf(red_text "\nCodigo inexistente, tente novamente.\n" reset_color);
                    break;
                }
                else{
                AtualizarQuantidade(codigo);
                }

                break; 

            case 3:
                printf("\nQual o codigo do produto --> ");
                scanf("%d", & codigo);

                if(produtos[codigo].codigoProduto != codigo){
                    printf(red_text "\nCodigo inexistente, tente novamente.\n" reset_color);
                    break;
                }
                else{
                ValorProdutoEmEstoque(codigo);
                }
                break;
                
            case 4:
                ListaDeProdutosEmEstoque();
                
                break;
            
            case 5:
                ValorTotalEmEstoque();
                
                break;
            
            case 6:
                printf("\n\nfim.\n\n");
                return 0;

            default:
                printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
   
        }
    }
    
    return 0;
}

