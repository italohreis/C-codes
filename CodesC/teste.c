#include <stdio.h>

int main(void){

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

float ph[30], media, soma, temperatura[30][24];
int numerodia, nDias, i, resp, alertaph = 0, phacimade8 = 0, acimade110 = 0, cDiasmedia = 0;

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
        else if (temperatura[nDias][i] > 95){
            cDiasmedia++;
        }
    }
    media = soma / 24;
    printf("\nMedia do dia %d: %.2f\n\n", nDias, media);

    printf("Deseja continuar? (1 - Sim / 2 - Nao) --> ");
    scanf("%d", &resp);
    printf("\n\n");

}while(resp == 1);

printf("Numero de dias do periodo: %d\n", nDias);
printf("Quantas vezes um sinal de aleta foi emitido por causa do PH acima de 8,0: %d\n", phacimade8);
printf("Quantas vezes um sinal de aleta foi emitido por causa da temperatura acima de 110°C: %d\n", acimade110);
printf("Quantos dias tiveram temperatura média acima de 95°C: %d\n", cDiasmedia);


    return 0;
}