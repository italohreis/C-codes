#include <stdio.h>

#define RED_TEXT "\x1b[31m"
#define RESET_COLOR "\x1b[0m"

int main(void){

    //Considere uma cidade pequena que tem 5 postos de saúde, numerados como 0, 1, 2, 3 e 4. Estes
    //postos aplicaram vacinas para covid durantes os vinte primeiros dias dos meses de janeiro à abril, e
    //registraram o número de vacinas aplicadas a cada dia.
    //Faça um programa em linguagem C que leia o número de vacinas aplicadas a cada dia e mostre um
    //dos seguintes relatórios:
    //- Por posto: dado o número do posto, mostre o número total de vacinas aplicadas neste posto.
    //- Por dia: dado o dia e o mês, mostre o número total de vacinas aplicadas neste dia.
    //- Por mês: mostre o número total de vacinas aplicadas no mês.
    //Depois, perguntar ao usuário se deseja imprimir outro relatório. 

    int vacina[5][20][4] = {{{0}}}, dia, mes, posto, resp;
    int numeromes, numeroposto, numerodia;
    int somaposto[5] = {0}, somaDiaMes[4][20] = {{0}}, somaMes[4] = {0};
    
    for(mes = 0; mes < 4; mes++){
        printf("* MES %d *\n", mes);

        for(posto = 0; posto < 5; posto++){
            printf("\t< POSTO %d >\n", posto);

            for(dia = 0; dia < 20; dia++){
                
                printf("\n");

                printf("\t\tDIA %d\n", dia);
                printf("\t\tDigite a quantidade de vacinas aplicadas --> ");   
                scanf("%d", &vacina[posto][dia][mes]);

                somaDiaMes[mes][dia] += vacina[posto][dia][mes]; //soma a quantidade de vacinas aplicadas no dia e mes
                somaMes[mes] += vacina[posto][dia][mes];        //soma a quantidade de vacinas aplicadas no mes
                somaposto[posto] += vacina[posto][dia][mes];    //soma a quantidade de vacinas aplicadas no posto
                
            }
        }
    }

    while(1){    //loop para o usuario escolher qual relatorio deseja ver
    printf("\n\nO que deseja fazer?\n\n");
    printf(" 1 - Mostrar quantidade de vacinas aplicadas em um posto.\n 2 - Mostrar quantidade de vacina aplicada em um dia e mes.\n"
           " 3 - Mostrar quantidade total de vacinas aplicadas em um mes.\n 4 - finalizar.\n");
    scanf("%d", &resp);

        switch(resp){
            
            case 1:
                printf("\nQual posto deseja verificar? --> ");
                scanf("%d", &numeroposto);
                if(numeroposto > 4 || numeroposto < 0){        //caso o usuario digite um numero de posto invalido
                    printf(RED_TEXT "\nPosto invalido, tente novamente.\n\n" RESET_COLOR);
                }

                else{
                printf("\nQuantidade de vacinas aplicadas no posto %d -->  %d\n\n", numeroposto, somaposto[numeroposto]);
                }
                break;

            case 2:
                printf("\nQual dia deseja verificar? --> ");
                scanf("%d", &numerodia);

                if(numerodia > 20 || numerodia < 0){    //caso o usuario digite um numero de dia invalido
                    printf(RED_TEXT "\nDia invalido, tente novamente.\n\n" RESET_COLOR);
                    break;
                }

                printf("\nQual mes? --> ");    //caso o usuario digite um numero de mes invalido 
                scanf("%d", &numeromes);

                if(numeromes > 3 || numeromes < 0){
                    printf(RED_TEXT "\nMes invalido, tente novamente.\n\n" RESET_COLOR);
                    break;
                }

                else{
                    printf("\nQuantidade de vacinas aplicadas no dia %d do mes %d -->  %d\n\n", numerodia, numeromes, somaDiaMes[numeromes][numerodia]);
                }
                break;

            case 3:
                printf("\nQual mes deseja verificar? --> ");
                scanf("%d", &numeromes);

                if(numeromes > 3 || numeromes < 0){       //caso o usuario digite um numero de mes invalido
                    printf(RED_TEXT "\nMes invalido, tente novamente.\n\n" RESET_COLOR);
                }

                else{
                printf("\nQuantidade de vacinas aplicadas no mes %d -->  %d\n\n", numeromes, somaMes[numeromes]);
                }
                break;
                
                
                case 4:
                printf("\nfim.\n");

                return 0;

                default:
                printf(RED_TEXT "\nResposta invalida, tente novamente.\n\n" RESET_COLOR);
        }
    }

    return 0;    
}
