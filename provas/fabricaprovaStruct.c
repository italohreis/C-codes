#include <stdio.h>


    #define red_text "\x1b[31m"
    #define reset_color "\x1b[0m"

 // Uma fábrica de argamassas vende 3 produtos: argamassa AC3 20kg, argamassa AC2 20kg e rejunte
    // 5kg. Suas entregas são feitas em Palmas ou Porto Nacional. Durante o último ano, esta fábrica
    // manteve registros de pedidos de 2 grandes clientes. Cada cliente fez um número indeterminado de
    // pedidos (no máximo 10), sendo que cada pedido tem o tipo do produto, a quantidade de pacotes e a
    // localidade da entrega.
    // Faça um programa em Linguagem C que leia os dados dos pedidos de cada cliente e imprima um
    // dos seguintes relatórios:

    //- Relatório por pedido: dado o número do cliente e do pedido, mostre o tipo e a quantidade do
    // produto, a localidade e o valor do frete.
    //- Relatório por cliente: dado o número do cliente mostre a média de peso dos seus pedidos e o
    // número de pedidos feitos no período.
    //- Relatório geral: mostre quantos kg de material foram vendidos no período e quais pedidos
    // tem menos de 1000kg.

    // Após imprimir um relatório, deve ser possível ao usuário imprimir outro caso queira.
    // Obs.:
    // Cálculo do frete: Se o pedido tem menos que 1000kg, o frete é grátis. Se tem de 1001kg a 2000kg, o
    // frete é R$ 100,00 para Palmas e 200,00 para Porto Nacional. Se tiver mais que 2000kg, o valor do
    // frete será 2 reais por pacote.


typedef struct{
    int tipo;
    int quantidade;
    int local;
} pedido;

typedef struct{
    pedido pedidos[10];
    int cProdutos;
} cliente;


int main(){
    cliente clientes[2];

    int cliente, resp;
    for(cliente = 0; cliente < 2; cliente++){
        clientes[cliente].cProdutos = 0;
        printf("\nCliente %d", cliente);

        do{
            printf("\n\tProduto %d\n", clientes[cliente].cProdutos);

            printf("\nInforme o tipo de produto (1 - Argamassa AC3 20kg / 2 - Argamassa AC2 20kg / 3 - Rejunte 5kg) --> ");
            scanf("%d", &clientes[cliente].pedidos[clientes[cliente].cProdutos].tipo);

            printf("\nInforme o local de entrega do pedido (1 - Palmas / 2 - Porto Nacional) --> ");
            scanf("%d", &clientes[cliente].pedidos[clientes[cliente].cProdutos].tipo);

            printf("\nInforme a quantidade de pacotes do pedido --> ");
            scanf("%d", &clientes[cliente].pedidos[clientes[cliente].cProdutos].quantidade);


            printf("\nDeseja continuar para outro pedido ? (1 - sim / 0 - nao) --> ");
            scannf("%d", &resp);

            clientes[cliente].cProdutos++;
        } while(resp == 1);
    }

    while(1){

        int op;
        printf("\nO que deseja fazer ?\n");
        printf("\n 1 - Relatorio por pedido.\n 2 - Relatorio por cliente.\n 3 - Relatorio Geral.\n 4 - Finalizar.\n");
        scanf("%d", &op);

        switch(op){

            case 1:
                RelatorioPedido(clientes);
                break;

            case 2:
                RelatorioCliente(clientes);
                break;

            case 3:
                RelatorioGeral(clientes);
                break;

            case 4:
                printf("\nFim.\n");
                return 0;

            default:
                printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
        }
    }


    return 0;
}


void RelatorioPedido(){

    int numCliente, numPedido;
    printf("\nQual cliente deseja consultar ? --> ");
    scanf("%d", &numCliente);

    printf("\nQual pedido deseja consultar ? --> ");
    scanf("%d", &numPedido);

    print



}


void RelatorioCliente(){


}

void RelatorioGeral(){




}


