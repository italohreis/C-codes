#include <stdio.h>
#include <stdbool.h>

#define red_text "\x1b[31m"
#define reset_color "\x1b[0m"

/* Uma empresa comercial possui um programa para controle das receitas e despesas em seus 10 projetos. 

Os projetos são numerados de 0 até 9. Faça um programa C que controle a entrada e saída de recursos dos projetos. 

O programa deverá ler um conjunto de informações contendo: Número do projeto, valor, tipo despesa ("R" - Receita e "D" - Despesa). 

O programa termina quando o valor do código do projeto for igual a -1. Sabe-se que Receita deve ser somada ao saldo do 
projeto e despesa subtraída do saldo do projeto. Ao final do programa, imprirmir o saldo final de cada projeto.

Dica: Usar uma estrutura do tipo vetor para controlar os saldos dos projetos. Usar o conceito de struct para agrupar as informações lidas. */


typedef struct{
    float valor;
    int tipoDespesa;
    float saldo;
    float ValorTotal;

} empresa;
empresa empresas[10];

    bool projeto_fornecido[10] = {false};

float CalcularSaldo(int projeto){
    
    if(empresas[projeto].tipoDespesa == 1){
        empresas[projeto].saldo += empresas[projeto].valor;
    } else if (empresas[projeto].tipoDespesa == 2){
        empresas[projeto].saldo -= empresas[projeto].valor;
        
    }

    return empresas[projeto].saldo;
}



int main(void){

    char resp[] = red_text "\n\tResposta invalida, tente novamente" reset_color;

   
    start:
    printf("\n");
    
    int projeto = -1;

    while(projeto < 0 || projeto > 9){
        printf("\n\tQual numero do projeto ? (Caso queira finalizar, digite -1) --> ");
        scanf("%d", &projeto);

        if(projeto == -1){
            goto action;
        } else if(projeto < 0 || projeto > 9){
            puts(resp);
        } 

    }

        if(projeto_fornecido[projeto] == true){
            printf(red_text"\n\tProjeto ja fornecido, tente novamente"reset_color);
            goto start;
        }

        projeto_fornecido[projeto] = true;
        
    printf("\n\tQual saldo do projeto %d ? --> ", projeto);
    scanf("%f", &empresas[projeto].saldo);

        
    printf("\n\tQual o valor da despesa ? --> ");
    scanf("%f", &empresas[projeto].valor);

    while(empresas[projeto].tipoDespesa != 1 && empresas[projeto].tipoDespesa != 2){
        printf("\n\tQual o tipo da despesa ? (1 - Receita / 2 - Despesa) --> ");
        scanf("%d", &empresas[projeto].tipoDespesa);

        if(empresas[projeto].tipoDespesa != 1 && empresas[projeto].tipoDespesa != 2){
                puts(resp);
        }
    }

    goto start;
    
    action:
    printf("\n\n");

    int project;
    
    for(project = 0; project < 10; project++){

        empresas[project].ValorTotal = CalcularSaldo(project);

        if(empresas[project].saldo > 0){
            printf("Valor do saldo final do projeto %d -->  R$ %.2f\n", project, empresas[project].ValorTotal);
        }
        
    }
    printf("\n\nfim\n\n");

    return 0;
}