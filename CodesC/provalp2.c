#include <stdio.h>

#define red_text "\x1b[31m"
#define reset_color "\x1b[0m"

int main(void)
{

    // Produtores de hortaliças de uma região do estado mantém uma cooperativa para a distribuição de
    // alface e repolho que abastecem os mercados da cidade. Semanalmente a cooperativa recebe
    // carregamentos de alface e repolho dos produtores associados (no máximo 50 produtores) e anota
    // o número de pés de alface e o número de pés repolho entregues por cada produtor. A cooperativa
    // quer fazer um levantamento sobre as hortaliças entregues nas últimas 15 semanas.

    // Faça um algoritmo que leia, para cada semana, o número de pés de alface e o número de pés
    // repolho entregues por cada produtor, após as leituras, mostre 1 destes relatórios:

    //- Relatório por semana: dado a semana, mostrar a quantidade de alface e de repolho entregues
    // nesta semana.

    //- Relatório por produtor: dado o produtor, mostrar a quantidade de alface e de repolho entregues
    // no período por este produtor.

    //- Relatório de análise de abastecimento: Mostre a quantidade total de alface e de repolho
    // entregues no período. Se a quantidade total de hortaliças for inferior a 500, emita um sinal de
    // “Risco de desabastecimento”, se a quantidade de alface for superior a 1300 ou a quantidade de
    // repolho for superior a 1200, emita um sinal de “Super produção”.Diga também se houve alguma
    // semana no período que não houve entregas.
    // Após imprimir um relatório, oferecer a opção para o usurário imprimir outro relatório se desejar.

    int semana, produtor, matriz[2][15][50] = {{{0}}}, resp;
    int somaProdutorAlface[50] = {0}, somaProdutorRepolho[50] = {0}, somaTotalAlface = 0, somaTotalRepolho = 0;
    int alfacesemana[15] = {0}, repolhosemana[15] = {0};
    int cSemanaSemEntrega = 0;

    for (semana = 0; semana < 15; semana++){
        printf("* Semana %d *\n", semana);

        for (produtor = 0; produtor < 50; produtor++){
            printf("\n\t< Produtor %d >\n", produtor);

            printf("\n\tDigite a quantidade de pes de alface entregues --> ");
            scanf("%d", &matriz[0][semana][produtor]);

            printf("\n\tDigite a quantidade de pes de repolho entregue --> ");
            scanf("%d", &matriz[1][semana][produtor]);

            alfacesemana[semana] += matriz[0][semana][produtor];  // soma a quantidade de alfaces entregues na semana
            repolhosemana[semana] += matriz[1][semana][produtor]; // soma a quantidade de repolhos entregues na semana

            somaTotalAlface += matriz[0][semana][produtor];  // soma a quantidade total de alfaces entregues no periodo
            somaTotalRepolho += matriz[1][semana][produtor]; // soma a quantidade total de repolhos entregues no periodo

            somaProdutorAlface[produtor] += matriz[0][semana][produtor];  // soma a quantidade de alface entregues por produtor
            somaProdutorRepolho[produtor] += matriz[1][semana][produtor]; // soma a quantidade de repolhos entregues por produtor

            resp = -1;

            while (resp != 1 && resp != 0){ // estrutura para verificar se a resposta do usuario é valida.
                printf("\n\tDeseja continuar para outro produtor? (1 - sim / 0 - nao) --> ");
                scanf(" %d", &resp);

                if (resp != 1 && resp != 0){
                    printf(red_text "\n\tResposta invalida, tente novamente.\n" reset_color);
                }
            }

            if (resp == 0){
                break;
            }
        }

        if ((alfacesemana[semana] == 0) && (repolhosemana[semana] == 0)){
            cSemanaSemEntrega++; // variavel contadora para verificar se possui alguma semana em que nao foram feitas entregas.
        }
        printf("\n");
    }

    int op;
    int numeroSemana, numeroProdutor;

    while (1){

        printf("\n\nO que deseja fazer?\n");
        printf(" 1 - Relatorio por semana.\n 2 - Relatorio por produtor.\n 3 - Relatorio de analise de abastecimento.\n 4 - finalizar\n");
        scanf(" %d", &op);

        switch (op){

        case 1:
            numeroSemana = -1;
            while (numeroSemana < 0 || numeroSemana > 14){
                printf("\nQual semana deseja consultar? --> ");
                scanf("%d", &numeroSemana); 

                if (numeroSemana < 0 || numeroSemana > 14){
                    printf(red_text "\nSemana invalida, tente novamente.\n" reset_color);
                }
            }

            printf("\nQuantidade de pes de alfaces entregues na semana %d -->  %d\n", numeroSemana, alfacesemana[numeroSemana]);
            printf("\nQuantidade de pes de repolho entregues na semana %d -->  %d\n", numeroSemana, repolhosemana[numeroSemana]);
            break;

        case 2:
            numeroProdutor = -1;
            while (numeroProdutor < 0 || numeroProdutor > 50){
                printf("\nQual produtor deseja consultar? --> ");
                scanf("%d", &numeroProdutor);

                if (numeroProdutor < 0 || numeroProdutor > 50){
                    printf(red_text "\nProdutor invalido, tente novamente.\n" reset_color);
                }
            }

            printf("\nQuantidade de pes de alface entregues pelo produtor %d -->  %d\n", numeroProdutor, somaProdutorAlface[numeroProdutor]);
            printf("Quantidade de pes de repolho entregues pelo produtor %d -->  %d\n", numeroProdutor, somaProdutorRepolho[numeroProdutor]);
            break;

        case 3:
            printf("\nQuantidade total de pes de alfaces entregues no periodo -->  %d\n", somaTotalAlface);
            printf("Quantidade total de pes de repolho entregues no periodo -->  %d\n", somaTotalRepolho);

            if (somaTotalAlface + somaTotalRepolho < 500){
                printf("\nRisco de desabastecimento.\n");
            }
            else if ((somaTotalAlface > 1300) || (somaTotalRepolho > 1200)){
                printf("\nSuper Producao.\n");
            }

            if (cSemanaSemEntrega > 0){
                printf("\nHouve alguma semana no periodo em que nao foram feitas entregas.\n");
            }
            break;

        case 4:
            printf("\n\nfim.\n\n");

            return 0;

        default:
            printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
            break;

        }   
    }

    return 0;
}
