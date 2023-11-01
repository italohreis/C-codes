#include <stdio.h>
#include <stdbool.h>

#define red_text "\x1b[31m"
#define reset_color "\x1b[0m"


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
    int encOqProcurava;
    int ficSatisfeito;
    float PorcSim;
    float PorcNao;
    
} cliente;

typedef struct{
    cliente clientes[20];
    int cCliente;
} dia;
dia dias[5];



void relatorioDia(){

    int numDia = -1;
    while(numDia < 0 || numDia > 4){
        printf("\nQual dia deseja consultar ? --> ");
        scanf("%d", &numDia);

        if(numDia < 0 || numDia > 4){
            printf(red_text "\nDia invalido, tente novamente.\n" reset_color);
        }
    }

    int cliente;
    for(cliente = 0; cliente < 20; cliente++){

        if(dias[numDia].clientes[cliente].encOqProcurava < 0 && dias[numDia].clientes[cliente].ficSatisfeito < 0 ){
            continue;
        }
        printf("\n\tCliente %d:\n", cliente);

        printf("\n\tEncontrou o que procurava ? --> ");
        
        if(dias[numDia].clientes[cliente].encOqProcurava == 1){
            printf("Sim.");

        } else{
            printf("Nao.");
        }

        printf("\n\tFicou satisfeito ? --> ");

        if(dias[numDia].clientes[cliente].ficSatisfeito == 1){
            printf("Sim.\n");
        } else{
            printf("Nao.\n");
        }
    }   
}


float relatorioPergunta(int cSim1, int cNao1, int cSim2, int cNao2){

    int resp = 0;
    while(resp != 1 && resp != 2){
        printf("Qual pergunta deseja verificar ? (1 - Encontrou o que procurava? / 2 - Ficou satisfeito ? ) --> ");
        scanf("%d", & resp);

        if(resp != 1 && resp != 2){
            printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
        }
    }

    float PorcentagemSim = 0;
    float PorcentagemNao = 0;

    float PorcentagemSim2 = 0;
    float PorcentagemNao2 = 0;

    switch(resp){

        case 1:

            PorcentagemSim =  ((float) cSim1 / (float) (cSim1 + cNao1)) * 100;

            PorcentagemNao =  ((float) cNao1 / (float) (cSim1 + cNao1)) * 100;
            
            printf("\nPorcentagem de respostas 'sim' -->  %.2f%%\n", PorcentagemSim);
            printf("\nPorcentagem de respostas 'nao' -->  %.2f%%\n", PorcentagemNao);
            break;

        case 2:                        

            PorcentagemSim2 = ((float) cSim2 / (float) (cSim2 + cNao2)) * 100;

            PorcentagemNao2 = ((float) cNao2 / (float) (cSim2 + cNao2)) * 100;
            
            printf("\nPorcentagem de respostas 'sim' -->  %.2f%%\n", PorcentagemSim2);
            printf("\nPorcentagem de respostas 'nao' -->  %.2f%%\n", PorcentagemNao2);

            break;

    }
    
}




void relatorioCliente(){
    

    int numDia = -1;
    while(numDia < 0 || numDia > 4){
        printf("\nQual dia do cliente deseja consultar ? --> ");
        scanf("%d", &numDia);

        if(numDia < 0 || numDia > 5){
            printf(red_text "\nDia invalido, tente novamente.\n" reset_color);
        }
    }

    int numCliente = -1;
    while(numCliente > dias[numDia].cCliente -1 || numCliente < 0){
        printf("\nQual cliente deseja consultar ? --> ");
        scanf("%d", &numCliente);

        if(numCliente > dias[numDia].cCliente -1 || numCliente < 0){
            printf(red_text "\nCliente invalido, tente novamente.\n" reset_color);
        }
    }

    
    printf("\n\tEncontrou o que procurava ? --> ");

    if(dias[numDia].clientes[numCliente].encOqProcurava == 1){
        printf("Sim\n");

    } else{
        printf("Nao.\n");
    }

    printf("\n\tFicou satisfeito ? --> ");

    if(dias[numDia].clientes[numCliente].ficSatisfeito == 1){
        printf("Sim.\n");
            
    } else{
        printf("Nao.\n");
    }
    

}

float relatorioGeral(int somaClientes){

    printf("\nQuantidade de clientes consultados -->  %d\n", somaClientes);


}




int main(void) {
    int cNao1 = 0, cSim1 = 0;

    int cNao2 = 0, cSim2 = 0;

    int dia, cliente, resp;

    int somaClientes = 0;

    for (dia = 0; dia < 5; dia++){
        printf("\n\nDia %d\n", dia);

        for(cliente = 0; cliente < 20; cliente++){
            dias[dia].cCliente++;
            somaClientes++;

            if(cliente > 20){
                break;
            }

            printf("\n\tCliente %d", cliente);

            dias[dia].clientes[cliente].encOqProcurava = -1;

            printf("\n\tEncontrou o que procurava ? (1 - sim / 0 - nao) --> ");
            scanf("%d", &dias[dia].clientes[cliente].encOqProcurava);

            if(dias[dia].clientes[cliente].encOqProcurava == 1){
                cSim1++;
            } else{
                cNao1++;
            }


            printf("\n\tFicou satisfeito ? (1 - sim / 0 nao) --> ");
            scanf("%d", &dias[dia].clientes[cliente].ficSatisfeito);
            
            if(dias[dia].clientes[cliente].ficSatisfeito == 1){
                cSim2++;
            } else{
                cNao2++;
            }
            
            printf("\n\tDeseja continuar para outro cliente? (1 - sim / 0 - nao) --> ");
            scanf("%d", &resp);

            if(resp == 0){
                break;
            }
        }
    }

    while(1){
        int op;
        printf("\n\nO que deseja fazer ?\n");
        printf(" 1 - Relatorio por dia.\n 2 - Relatorio por pergunta.\n 3 - Relatorio por cliente.\n 4 - Relatorio Geral.\n 5 - Finalizar\n");
        scanf("%d", &op);

        switch(op){

            case 1:
                relatorioDia();
                break;

            case 2:
                relatorioPergunta(cSim1, cNao1, cSim2, cNao2);
                break;


            case 3:
                relatorioCliente();
                break;

            case 4:
                relatorioGeral(somaClientes);
                break;

            case 5:
                printf("\n\nfim\n\n");

                return 0;

            default:
                printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
        }

    }


    return 0;
}
