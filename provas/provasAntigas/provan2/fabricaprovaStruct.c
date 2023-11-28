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
    int pesoPedido;
} pedido;

typedef struct{
    pedido pedidos[10];
    float totalKgCliente;
    int cPedidos;
} cliente;

    //prototipo
    void RelatorioPedido(cliente *clientes);
    void RelatorioCliente(cliente *clientes);
    void RelatorioGeral(int totalkg, int cPedidosMenor1000);
    float CalcularFrete(cliente *clientes, int numCliente, int numPedido);


int main(){
    cliente clientes[2];
    //zerar struct
    int i, j;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 10; j++){
            clientes[i].pedidos[j].tipo = 0;
            clientes[i].pedidos[j].quantidade = 0;
            clientes[i].pedidos[j].local = 0;
            clientes[i].pedidos[j].pesoPedido = 0;
        }
    }

    int totalkg = 0, cPedidos = 0;
    int cliente, resp;
    int cPedidosMenor1000 = 0;

    for(cliente = 0; cliente < 2; cliente++){
        clientes[cliente].cPedidos = 0;
        clientes[cliente].totalKgCliente = 0;
        printf("\n* Cliente %d *\n", cliente);

        int request;
        for(request = 0; request < 10; request++){
            printf("\n\t< Pedido %d >\n", request);

            while(clientes[cliente].pedidos[request].tipo < 1 || clientes[cliente].pedidos[request].tipo > 3){
                printf("\n\tInforme o tipo de produto (1 - Argamassa AC3 20kg / 2 - Argamassa AC2 20kg / 3 - Rejunte 5kg) --> ");
                scanf("%d", &clientes[cliente].pedidos[request].tipo);

                if(clientes[cliente].pedidos[request].tipo < 1 || clientes[cliente].pedidos[request].tipo > 3){
                    printf(red_text "\n\tTipo de produto invalido, tente novamente.\n" reset_color);
                }
            }

            while(clientes[cliente].pedidos[request].local != 1 && clientes[cliente].pedidos[request].local != 2){
                printf("\n\tInforme o local de entrega do pedido (1 - Palmas / 2 - Porto Nacional) --> ");
                scanf("%d", &clientes[cliente].pedidos[request].local);

                if(clientes[cliente].pedidos[request].local != 1 && clientes[cliente].pedidos[request].local != 2){
                    printf(red_text "\n\tLocal de entrega invalido, tente novamente.\n" reset_color);
                }
            }

            printf("\n\tInforme a quantidade de pacotes do pedido --> ");
            scanf("%d", &clientes[cliente].pedidos[request].quantidade);


            if(clientes[cliente].pedidos[request].tipo == 1 || clientes[cliente].pedidos[request].tipo == 2){
                clientes[cliente].pedidos[request].pesoPedido = clientes[cliente].pedidos[request].quantidade * 20;

            } else{
                clientes[cliente].pedidos[request].pesoPedido = clientes[cliente].pedidos[request].quantidade * 5;
            }


            if(clientes[cliente].pedidos[request].pesoPedido < 1000){
                cPedidosMenor1000++;
            }

            totalkg += clientes[cliente].pedidos[request].pesoPedido;
            clientes[cliente].totalKgCliente += clientes[cliente].pedidos[request].pesoPedido;            

            clientes[cliente].cPedidos++;

            resp = -1;
            while(resp != 1 && resp != 0){
                printf("\n\tDeseja continuar para outro pedido ? (1 - sim / 0 - nao) --> ");
                scanf("%d", &resp);

                if(resp != 1 && resp != 0){
                    printf(red_text "\n\tResposta invalida, tente novamente.\n" reset_color);

                } else if(resp == 0){
                    break;
                }
                
            }

        }
    }

    while(1){

        int op;
        printf("\n\n\nO que deseja fazer ?\n");
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
                RelatorioGeral(totalkg, cPedidosMenor1000);
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


void RelatorioPedido(cliente *clientes){

    int numCliente = -1, numPedido;
    while(numCliente < 0 || numCliente > 1){
        printf("\nQual cliente deseja consultar ? --> ");
        scanf("%d", &numCliente);

        if(numCliente < 0 || numCliente > 1){
            printf(red_text "\nCliente invalido, tente novamente.\n" reset_color);
        }
    }

    while(numPedido < 0 || numPedido >= clientes[numCliente].cPedidos){
        printf("\nQual pedido deseja consultar ? --> ");
        scanf("%d", &numPedido);

        if(numPedido < 0 || numPedido >= clientes[numCliente].cPedidos){
            printf(red_text "\nPedido invalido, tente novamente.\n" reset_color);
        }
    }

    printf("\n\t-------------------------------------------------\n");
    

    printf("\n\tTipo de produto --> ");

    switch(clientes[numCliente].pedidos[numPedido].tipo){
        case 1:
            printf("Argamassa AC3 20kg\n");
            break;

        case 2:
            printf("Argamassa AC2 20kg\n");
            break;

        case 3:
            printf("Rejunte 5kg\n");
            break;
    }

    printf("\n\tQuantidade de pacotes --> %d\n", clientes[numCliente].pedidos[numPedido].quantidade);

    printf("\n\tLocal de entrega --> ");


    switch(clientes[numCliente].pedidos[numPedido].local){
        case 1:
            printf("Palmas\n");
            break;

        case 2:
            printf("Porto Nacional\n");
            break;
    }

    printf("\n\tValor do frete --> R$ %.2f\n", CalcularFrete(clientes, numCliente, numPedido));
    printf("\n\t-------------------------------------------------\n");

    return;
}
 

void RelatorioCliente(cliente *clientes){
    int numCliente = -1;

    while(numCliente < 0 || numCliente > 1){
        printf("\nQual cliente deseja consultar ? --> ");
        scanf("%d", &numCliente);

        if(numCliente < 0 || numCliente > 1){
            printf(red_text "\nCliente invalido, tente novamente.\n" reset_color);
        }
    }

    printf("\n\t-------------------------------------------------\n");
    printf("\n\tMedia de peso dos pedidos --> %.2f\n", clientes[numCliente].totalKgCliente / (float)clientes[numCliente].cPedidos);

    printf("\n\tQuantidade de pedidos feitos pelo cliente --> %d\n", clientes[numCliente].cPedidos);
    printf("\n\t-------------------------------------------------\n");

    return;
}

void RelatorioGeral(int totalkg, int cPedidosMenor1000){

    printf("\n\t---------------------------------------------------------------\n");

    printf("\n\tQuantidade total em kg de material vendido --> %d\n", totalkg);

    printf("\n\tQuantidade de pedidos que possuem menos que 1000kg --> %d\n", cPedidosMenor1000);
    printf("\n\t---------------------------------------------------------------\n");

    return;
}

float CalcularFrete(cliente *clientes, int numCliente, int numPedido){
    float frete;

    if(clientes[numCliente].pedidos[numPedido].pesoPedido < 1000){
        frete = 0;
        return frete;
    } else if(clientes[numCliente].pedidos[numPedido].pesoPedido >= 1000 && clientes[numCliente].pedidos[numPedido].pesoPedido <= 2000){
        if(clientes[numCliente].pedidos[numPedido].local == 1){
            frete = 100;
            return frete;
        } else{
            frete = 200;
            return frete;
        }

    } else{
        frete = clientes[numCliente].pedidos[numPedido].quantidade * 2;

        return frete;
    }
}
