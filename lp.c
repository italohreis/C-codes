#include <stdio.h>

int main(void){

int phacimade8, acimade110, cDiasmedia, nDias, i, resp, alertaph = 0;
float ph[30], media, soma, temperatura[30][24];
int numerodia;
nDias = 0;
cDiasmedia = 0;
phacimade8 = 0;
acimade110 = 0;

//Escreva um algoritmo que, para cada dia de auditoria, receba como entrada o PH e as medidas de
//temperaturas. Caso o PH esteja fora do desejável, deve-se emitir um sinal de alerta. Caso a
//temperatura esteja acima do normal e até 110°C, emita uma solicitação de resfriamento. Caso a
//temperatura ultrapasse 110°C, emita um sinal de alerta.
//No final de um dia de auditoria, mostre a temperatura média deste dia e pergunte ao auditor se
//quer continuar a auditoria por mais um dia.
//Ao final do período de auditoria, mostre o seguinte relatório:
//Número de dias do período;
//Quantas vezes um sinal de aleta foi emitido por causa do PH acima de 8,0;
//Quantas vezes um sinal de aleta foi emitido por causa da temperatura acima de 110°C;
//Quantos dias tiveram temperatura média acima de 95°C;
//Emitir a mensagem “Aprovado” caso não tenha ocorrido nenhum sinal de alerta.

//Dado o dia da auditoria, mostre o PH e as medidas de temperaturas aferidas neste dia.
//Após, forneça ao usuário a opção de consultar um outro dia, se ele desejar.


    do{
        nDias++;
        soma = 0;
        media = 0;

        printf("* Dia %d da auditoria *\n\n", nDias);
        printf("Digite o valor do PH: ");
        scanf("%f", &ph[nDias]);

        if(ph[nDias] < 6 || ph[nDias] > 8){
            printf("\nAlerta!\n\n");
            alertaph++;
        }
        else{
            printf("\nPH normal.\n\n");
        }
        if(ph[nDias] > 8){
         phacimade8++;
        }

        for(i = 0; i <= 23; i++){
            printf("Digite a temperatura %d: ", i+1);
            scanf(" %f", &temperatura[nDias][i]);
            soma = soma + temperatura[nDias][i];

            if(temperatura[nDias][i] <= 90){
            printf("\nTemperatura nomal.\n\n");
            }
            else if (temperatura[nDias][i] > 110){
                printf("\nAlerta!\n\n");
                acimade110++;
            }
            else{
                printf("\nSolicitacao de resfriamento.\n\n");
            }

        }   

            media = soma/24;
            printf("\nTemperatura media do dia: %.2f\n", media);
            if(media > 95){
                cDiasmedia++;
            }

            resp = -1;

            while(resp != 1 && resp != 0){
            printf("\nDeseja continuar? Digite '1' para sim '0' para nao --> ");
            scanf(" %d", &resp);
            printf("\n\n");
            }

    }while(resp == 1);

        start:
        printf("\n");
        do{
        printf("Informe o numero do dia que deseja consultar(caso queira finalizar digite 0) --> ");
        scanf("%d", &numerodia);
        if(numerodia < 1){
            goto relatorio;
        }
        if(numerodia > nDias){
            printf("\nDia inexistente.\n\n");
        }
        }while(numerodia > nDias);
        
        printf("\n\n< INFORMACOES AFERIDAS NO DIA %d >\n\n", numerodia);
        printf("PH: %.2f\n", ph[numerodia]);

        for(i = 0; i<=23; i++){
            printf("\nTemperatura %d: %.2f\n", i+1, temperatura[numerodia][i]);
        }
        goto start;

    relatorio:

    printf("\n-------------------------------------------------------------------------------------\n");
    printf("\nRelatorio:\n");
    printf("\nNumero de dias do periodo: %d\n", nDias);
    printf("Quantidade de sinais de alerta por conta de ph acima de 8,0: %d\n", phacimade8);
    printf("Quantidade de sinais de alerta por conta da temperatura acima de 110 graus: %d\n", acimade110);
    printf("Numero de dias que tiveram temperatura media acima de 95 graus: %d\n", cDiasmedia);

    if ((alertaph == 0) && (acimade110 == 0)){
        printf("\n\nAprovado!\n\n");
    }

    return 0;
}
