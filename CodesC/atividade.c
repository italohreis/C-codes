#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

#define red_text "\x1b[31m"
#define reset_color "\x1b[0m"

    /* Uma loja de eletrÃ´nicos mantÃ©m o controle de seu estoque de produtos. A loja possui diversos produtos, 
    cada um com um cÃ³digo, descriÃ§Ã£o, preÃ§o e quantidade em estoque. 
    A loja deseja criar um programa para gerenciar esse estoque.
    Crie um programa em C que permita ao usuÃ¡rio realizar as seguintes operaÃ§Ãµes:

    Inserir um novo produto no estoque. O usuÃ¡rio deve fornecer o cÃ³digo, descriÃ§Ã£o, preÃ§o e quantidade em estoque do produto.

    Atualizar a quantidade em estoque de um produto existente. O usuÃ¡rio deve fornecer o cÃ³digo do produto e a quantidade a ser adicionada (ou subtraÃ­da) do estoque.

    Exibir o valor total em estoque de um determinado produto. O usuÃ¡rio deve fornecer o cÃ³digo do produto, 
    e o programa deve calcular o valor total em estoque considerando o preÃ§o e a quantidade em estoque.

    Exibir a lista de todos os produtos em estoque, incluindo cÃ³digo, descriÃ§Ã£o, preÃ§o e quantidade.

    Calcular e mostrar o valor total em estoque de todos os produtos da loja.   
    Sair do programa.

    O programa deve ser executado em um loop, permitindo ao usuÃ¡rio realizar as operaÃ§Ãµes acima quantas vezes desejar atÃ© que escolha sair.
    Lembre-se de validar as entradas do usuÃ¡rio e tratar possÃ­veis erros (por exemplo, produtos com o mesmo cÃ³digo nÃ£o devem ser inseridos).
    AlÃ©m disso, forneÃ§a uma interface amigÃ¡vel ao usuÃ¡rio com mensagens claras e instruÃ§Ãµes.*/
    //vamo tentar rodar primeiro
    //ver se ta tudo certo

 

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
    
    printf("\nDescriÃ§Ã£o do produto ? --> ");        //essas letras estranhas é assim msm, nao tira
    scanf(" %s", & produtos[codigo].desc);
    
    printf("\nQual o preÃ§o do produto ? --> ");
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
    for(int i = 1; i <= 100000; i++){
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

    float valorTotalGeralEmEstoque;
    for(int i = 1; i <= 100000; i++){
        if (produtos[i].preco > 0){
            valorTotalGeralEmEstoque += produtos[i].valorTotaldoProduto;
        }
    }
    printf("\n\n\tValor total em estoque --> R$ %.2f\n", valorTotalGeralEmEstoque);
    
}


int main(void){     
setlocale(LC_ALL, "Portuguese");

    int resp;
    while(true){

        printf("\n\n\no que deseja fazer ?\n 1 - Inserir um novo produto no estoque.\n 2 - Atualizar a quantidade em estoque de um produto.\n 3 - Exibir o valor total em estoque de um produto\n"
            " 4 - Exibir a lista de todos os produtos em estoque.\n 5 - Calcular e mostrar o valor total em estoque de todos os produtos da loja.\n 6 - Finalizar.\n");
        scanf("%d", &resp);

        switch(resp){
            int codigo;
            case 1:
                printf("\nQual o codigo do produto ? --> ");
                scanf("%d", & codigo);
                InserirProduto(codigo);

                break;

            case 2:
                printf("\nQual o codigo do produto ? --> ");
                scanf("%d", & codigo);
                AtualizarQuantidade(codigo);

                break; 

            case 3:
                printf("\nQual o codigo do produto --> ");
                scanf("%d", & codigo);
                ValorProdutoEmEstoque(codigo);
                
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
                printf(red_text "\nResposta invÃ¡lida, tente novamente.\n" reset_color);
   
        }
    }
    

}

