#include <stdio.h>

int main(void){

    //10 atletas foram monitorados por 8 semanas. Para cada atleta foram registrados sua idade e
    //medições semanais de frequência cardíaca e do nível de oxigênio no sangue. Elabore um
    //algoritmo que, dado o número de um atleta, mostre um relatório com seus dados, seu nível
    //médio de oxigênio no sangue e a maior frequência cardíaca registrada durante o período de
    //monitoramento.
    //Após cada relatório, permitir que o usuário peça outro, caso queira.

    int atleta, idade[10], numeroAtleta, semana, resp, frequencia[10][8], maiorFrequencia[10] = {0};
    float oxigenio[10][8], media[10] = {0}, soma[10] = {0};

    for(atleta = 0; atleta < 10; atleta++){
        printf("* ATLETA %d *\n", atleta);

        printf("Digite sua idade --> ");
        scanf("%d", &idade[atleta]);

        for(semana = 0; semana < 8; semana++){
            printf("\n\t< Semana %d >\n", semana);

            printf("\tInsira a frequencia cardiaca --> ");
            scanf("%d", &frequencia[atleta][semana]);

            if(frequencia[atleta][semana] > maiorFrequencia[atleta]){
                maiorFrequencia[atleta] = frequencia[atleta][semana];
            }

            printf("\tInsira o nivel de oxigenio no sangue --> ");
            scanf("%f", &oxigenio[atleta][semana]);
            soma[atleta] += oxigenio[atleta][semana];
        }
        media[atleta] = (soma[atleta]/8);
        printf("\n");
    }
        
    start:
    printf("\n");
    do{

    printf("\n\nDigite o numero do atleta que deseja consultar(caso queira finalizar digite -1) --> ");
    scanf("%d", &numeroAtleta);

    if(numeroAtleta > 9 || numeroAtleta < 0){
        printf("\nAtleta invalido, tente novamente.\n");
        goto start;
    }

    printf("\n\nRELATORIO DO ATLETA %d\n\n", numeroAtleta);

    printf("Idade do atleta %d -->  %d\n\n", numeroAtleta, idade[numeroAtleta]);

        for(semana = 0; semana < 8; semana++){
            printf("< Semana %d >\n", semana);
            
            printf("\tFrequencia cardiaca aferida -->  %d.\n", frequencia[numeroAtleta][semana]);
            printf("\tNivel de oxigenio no sangue aferido -->  %.2f.\n\n", oxigenio[numeroAtleta][semana]);
        }

            printf("\nMaior frequencia cardiaca aferida -->  %d bpm.\n", maiorFrequencia[numeroAtleta]);
            printf("Media do nivel de oxigenio no sangue --> %.2f", media[numeroAtleta]);

    printf("\n\nDeseja consultar outro atleta ? (1 para sim ou 0 para nao) --> ");
    scanf("%d", &resp);

    }while(resp == 1);

    printf("\n\nfim.\n");

    return 0;
}