#include <stdio.h>
#include <stdbool.h>

#define red_text "\x1b [31m"
#define reset_color "\x1b [0m"


    /* Uma loja fará uma consulta de opinião com seus clientes por 5 dias. A cada dia no máximo 20
    clientes serão questionados (não receber o número de clientes como entrada):

        1. Encontrou o que procurava?
        2. Ficou satisfeito?

        Faça um programa em linguagem C que leia as respostas dos clientes e, após as leituras, mostre 1
        destes relatórios:

        - Relatório por dia: dado o dia, mostrar todas as respostas deste dia.

        - Relatório por pergunta: dada a pergunta, mostre a percentagem de respostas “sim” e a
        percentagem de respostas “não”.

        - Relatório por cliente: dados o número do cliente e o dia, mostre as respostas;

        - Relatório geral: mostre quantos clientes foram consultados, quantos responderam “não” para a
        duas questões, quantos estão satisfeitos, a percentagem de clientes que encontraram o que
        procuravam no 5° dia de pesquisa.
        
    Após imprimir um relatório, oferecer a opção para o usurário imprimir outro relatório se desejar */

typedef struct{
    bool encOqProcurava;
    bool ficSatisfeito;
    float PorcSim;
    float PorcNao;
    
} cliente;

typedef struct{
    cliente clientes[20];
} dia;
dia dias[5];



void relatorioDia(){
    int numDia;
    printf("Qual dia deseja consultar ? --> ");
    scanf("%d", &numDia);

    int cliente;

    printf("Dia %d\n", numDia);
    for(cliente = 0; cliente < 20; cliente++){
        printf("\n\tCliente %d: ");

        printf("\n\tEncontrou o que procurava ? --> ");
        
        if(dias[numDia].clientes[cliente].encOqProcurava == true){
            printf("Sim\n");

        } else{
            printf("Nao.\n");
        }

        printf("\n\tFicou satisfeito ? --> ");

        if(dias[numDia].clientes[cliente].ficSatisfeito == true){
            printf("Sim.\n");
        } else{
            printf("Nao.\n");
        }
    }   
}


float relatorioPergunta(){
    printf("qual pergunta ? 1 - ""Encontrou o que procurava?""  2 - ""Ficou satisfeito ?"" ");
    int resp;
    scanf("%d", & resp);
    switch{
        case 1 :
            cSim1;
                        
            
    }

    
    }




void relatorioCliente(){
    int numCliente;
    int numDia;

    printf("Qual cliente deseja consultar ? --> ");
    scanf("%d", &numCliente);

    printf("Qual dia do cliente %d deseja consultar ? --> ");
    scanf("%d", &numDia);
    
    printf("Encontrou o que procurava ? --> ");

    if(dias[numDia].clientes[numCliente].encOqProcurava == true){
        printf("Sim\n");

    } else{
        printf("Nao.\n");
    }

    printf("\n\tFicou satisfeito ? --> ");

    if(dias[numDia].clientes[numCliente].ficSatisfeito == true){
        printf("Sim.\n");
            
    } else{
        printf("Nao.\n");
    }
    

}

float relatorioGeral(){



}



int cNao1;
int cSim1;

int cNao2;
int cSim2;

int main() {
    int dia;
    int cliente;
    int resp;

    

    for (dia = 0; dia < 5; dia++){
        printf("Dia %d\n", dia);

        for(cliente = 0; cliente < 20; cliente++){
            if(cliente > 20){
                break;
            }

            printf("\n\tCliente %d", cliente);

            printf("\n\tEncontrou o que procurava ? (1 - sim / 0 - nao) --> ");
            scanf("%d", &dias[dia].clientes[cliente].encOqProcurava);

            if(dias[dia].clientes[cliente].encOqProcurava == true){
                cSim1;
            } else{
                cNao2;
            }


            printf("\n\tFicou satisfeito ? (1 - sim / 0 nao) --> ");
            scanf("%d", &dias[dia].clientes[cliente].ficSatisfeito);
            
            if(dias[dia].clientes[cliente].encOqProcurava == true){
                cSim2;
            } else{
                cNao2;
            }
            
            printf("Deseja continuar para outro cliente? (1 - sim / 0 - nao) --> ");
            scanf("%d", &resp);

            if(resp == 0){
                break;
            }
        }
    }
    int op;
    printf("\nO que deseja fazer ?\n");
    printf(" 1 - Relatorio por dia.\n 2 - Relatorio por pergunta.\n 3 - Relatorio por cliente.\n 4 - Relatorio Geral.\n 5 - Finalizar\n");
    scanf("%d", &op);

    while(1){

        switch(op){

            case 1:
                relatorioDia();



            case 2:
                relatorioPergunta();


            case 3:
                relatorioCliente();

            case 4:
                relatorioGeral();

            case 5:
                printf("\n\nfim\n\n");

                return 0;

            default:
                printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
                break;
        }



    }





    return 0;
}
