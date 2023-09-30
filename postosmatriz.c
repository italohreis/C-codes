#include <stdio.h>

int main(void){

//Considere uma cidade pequena que tem 5 postos de saúde, numerados como 0, 1, 2, 3 e 4. Estes
//postos aplicaram vacinas para covid durantes os vinte primeiros dias do mês de janeiro e
//registraram o número de vacinas aplicadas a cada dia.
//Faça um programa em linguagem C que leia o número de vacinas aplicadas a cada dia nos 5 postos
//e mostre um dos seguintes relatórios:
//- Por posto: dado o número do posto, mostre o número total de vacinas aplicadas neste posto.
//- Por dia: dado o dia, mostre o número total de vacinas aplicadas neste dia.
//- Por mês: mostre o número total de vacinas aplicadas no mês de janeiro.
//Depois, perguntar ao usuário se deseja imprimir outro relatório. 

int vacina[5][20] = {{0}}, dia, posto, resp, numeroposto, numerodia, cVacina[5] = {0}, cVacinadia[20] = {0}, cVacinatotal = 0;

    for(posto = 0; posto <5; posto++){
        printf("* POSTO %d *\n", posto);

            for(dia=0; dia<20; dia++){
            printf("\n\tDIA %d\n", dia);

            vacina[posto][dia] = -1;
            
            while(vacina[posto][dia] != 1 && vacina[posto][dia] != 0){
            printf("\tDigite 1 se a vacina foi aplicada ou digite 0 se nao foi aplicada --> ");
            scanf(" %d", &vacina[posto][dia]);
            printf("\n");        
            }

            if(vacina[posto][dia] == 1){
                cVacina[posto]++;
                cVacinadia[dia]++;
                cVacinatotal++;
            }   
        }
    }

    while(1){

        printf("\n\nO que deseja fazer ?\n");
        printf(" 1 - Mostrar numero total de vacina aplicadas em um posto\n 2 - Mostrar o total de vacinas aplicadas em um dia\n"
            " 3 - Mostrar o numero total de vacinas aplicadas no mes\n 4 - finalizar.\n");
        scanf("%d", &resp);

            switch(resp){

                case 1: 

                printf("Qual posto deseja verificar? --> ");
                scanf("%d", &numeroposto);
                if(numeroposto > 4 || numeroposto < 0){
                    printf("\nPosto invalido, tente novamente.\n");       
                }   
                else{
                    printf("\n\nNumero total de vacinas aplicadas no posto %d -->  %d\n\n", numeroposto, cVacina[numeroposto]);
                }
                break;
                
                case 2:

                printf("Qual dia deseja verificar? --> ");
                scanf("%d", &numerodia);
                if(numerodia > 19 || numerodia < 0){
                    printf("Dia invalido, tente novamente.\n");
                }    
                else{
                printf("\nQuantidade de vacinas aplicadas no dia %d -->  %d\n", numerodia, cVacinadia[numerodia]);
                }       
                break;
                
                case 3:
                printf("\nNumero total de vacinas aplicadas no mes de janeiro -->  %d\n", cVacinatotal);
                break;  

                case 4:
                printf("\nfim.\n");

                return 0;
            }                          
        }
    
    return 0;
}
