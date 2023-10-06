#include <stdio.h>

int main(void){

        //Uma fábrica de argamassas vende 3 produtos: argamassa AC3 20kg, argamassa AC2 20kg e rejunte
        //5kg. Suas entregas são feitas em Palmas ou Porto Nacional. Durante o último ano, esta fábrica
        //manteve registros de pedidos de 2 grandes clientes. Cada cliente fez um número indeterminado de
        //pedidos (no máximo 10), sendo que cada pedido tem o tipo do produto, a quantidade de pacotes e a
        //localidade da entrega.
        //Faça um programa em Linguagem C que leia os dados dos pedidos de cada cliente e imprima um
        //dos seguintes relatórios:

        //- Relatório por pedido: dado o número do cliente e do pedido, mostre o tipo e a quantidade do
        //produto, a localidade e o valor do frete.
        //- Relatório por cliente: dado o número do cliente mostre a média de peso dos seus pedidos e o
        //número de pedidos feitos no período.
        //- Relatório geral: mostre quantos kg de material foram vendidos no período e quais pedidos
        //tem menos de 1000kg.

        //Após imprimir um relatório, deve ser possível ao usuário imprimir outro caso queira.
        //Obs.:
        //Cálculo do frete: Se o pedido tem menos que 1000kg, o frete é grátis. Se tem de 1001kg a 2000kg, o
        //frete é R$ 100,00 para Palmas e 200,00 para Porto Nacional. Se tiver mais que 2000kg, o valor do
        //frete será 2 reais por pacote.

    int pedidocliente[3][10][2], resp;
    int pedido, Clientes, frete[2];
    int cPedidos[2] = {0};
    float totalkg[2], mediapeso[2] = {0}, totalgeral;


    for(Clientes = 0; Clientes < 2; Clientes++){
        printf("* CLIENTE %d *\n", Clientes);
        for(pedido = 0; pedido < 10; pedido++){
            cPedidos[Clientes]++;

            printf("\n\tPedido %d\n", pedido);

            produto:
            printf("\n\tInforme qual o tipo do produto (1 - Argamassa AC3 20KG / 2 - Argamassa AC2 20KG / 3 - Rejunte 5KG ) --> ");
            scanf("%d", &pedidocliente[0][pedido][Clientes]);

            if(pedidocliente[0][pedido][Clientes] != 1 && pedidocliente[0][pedido][Clientes] != 2 && pedidocliente[0][pedido][Clientes] != 3){
                printf("\n\tResposta invalida, tente novamente.\n");
                goto produto;
            }

            printf("\n\tInforme a quantidade do produto -->  ");
            scanf("%d", &pedidocliente[1][pedido][Clientes]);

            local:
            printf("\n\tQual o local de entrega (1 - Palmas / 2 - Porto Nacional) --> ");
            scanf("%d", &pedidocliente[2][pedido][Clientes]);
            if(pedidocliente[2][pedido][Clientes] != 1 && pedidocliente[2][pedido][Clientes] != 2){
                printf("\n\tResposta invalida, tente novamente.\n");
                goto local;
            }

            if(pedidocliente[0][pedido][Clientes] == 1){
                totalkg[Clientes] += pedidocliente[1][pedido][Clientes] * 20;          
            }       
            else if(pedidocliente[0][pedido][Clientes] == 2){
                totalkg[Clientes] += pedidocliente[1][pedido][Clientes] * 20;
            }
            else{
                totalkg[Clientes] += pedidocliente[1][pedido][Clientes] * 5;
            }    

            
            while(1){
                printf("\n\n\tDeseja informar outro pedido ? Digite 1 para sim ou 0 para nao --> ");
                scanf("%d", &resp);
                if(resp == 1 || resp == 0){
                    break;
                }
                else{
                    printf("\n\tResposta invalida, tente novamente.\n");
                }
            }
            printf("\n");

            if(resp == 0){
                break;
            }
        }

        totalgeral += totalkg[Clientes];

        mediapeso[Clientes] = (float)totalkg[Clientes] / cPedidos[Clientes]; 

        if(totalkg[Clientes] < 1000){
            frete[Clientes] = 0;
        }
        else if(totalkg[Clientes] > 2000){
            frete[Clientes] = pedidocliente[1][pedido][Clientes] * 2;
        }
        else{
            if(pedidocliente[2][pedido][Clientes] == 1){
                frete[Clientes] = 100;
            }
            else{
                frete[Clientes] = 200;                
            }
        }
    }

        int numcliente, numpedido;
        int op;

        while(1){

            printf("\n\nO que deseja fazer ?\n");
            printf("1 - Relatorio por pedido: Mostrar tipo, quantidade do produto, localidade e valor do frete.\n" 
                   "2 - Relatorio por cliente: Mostrar media dos pesos dos pedidos e o numero de pedidos de um cliente.\n"
                   "3 - Relatorio geral: mostre quantos kg de material foram vendidos no periodo e quais pedidos tem menos de 1000kg.\n"
                   "4 - finalizar.\n");
            scanf("%d", &op);

            switch(op){

                case 1:
                    printf("\nQual cliente deseja consultar? --> ");
                    scanf("%d", &numcliente);

                        if(numcliente < 0 || numcliente > 1){
                            printf("\nCliente inexistente, tente novamente.\n");
                            break;
                        }

                    printf("\nQual pedido do cliente %d deseja consultar? --> ", numcliente);
                    scanf("%d", &numpedido);

                        if(numpedido >= cPedidos[numcliente]){
                            printf("\nPedido inexistente, tente novamente.\n");
                            break;
                        }

                    printf("\n\n\tTipo do produto -->  ");

                        if(pedidocliente[0][numpedido][numcliente] == 1){
                            printf("Argamassa AC3.\n");
                        }
                            else if(pedidocliente[0][numpedido][numcliente] == 2){
                                printf("Argamassa AC2.\n");
                            }
                                else{
                                    printf("Rejunte.\n");
                                }

                    printf("\tQuantidade de produtos -->  %d\n", pedidocliente[1][numpedido][numcliente]);
                    printf("\tLocal de entrega -->  ");
                        
                        if(pedidocliente[2][numpedido][numcliente] == 1){
                            printf("Palmas.\n");
                        }
                        else{
                            printf("Porto Nacional.\n");
                        }

                    printf("\tValor do frete --> R$ %d\n", frete[numcliente]);
                    break;

                case 2:
                    printf("\nQual cliente deseja consultar? --> ");
                    scanf("%d", &numcliente);

                        if(numcliente < 0 || numcliente > 1){
                            printf("\nCliente inexistente, tente novamente.\n");
                            break;
                        }

                    printf("\n\tMedia dos pesos dos pedidos -->  %.2f kg\n", mediapeso[numcliente]);

                    printf("\tNumero de pedidos feitos pelo cliente %d -->  %d\n", numcliente, cPedidos[numcliente]);
                    break;

                case 3:
                    printf("\n\tQuantidade total de kg vendidos no periodo -->  %.1f kg\n", totalgeral);
                    break;

                case 4:
                    printf("\n\nfim.\n\n");

                return 0;
            }
                      

        }  
     
    return 0;

}
