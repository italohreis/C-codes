#include <stdio.h>

#define red_text "\x1b[31m"
#define reset_color "\x1b[0m"

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

        if((dias[numDia].clientes[cliente].encOqProcurava == -1) && (dias[numDia].clientes[cliente].ficSatisfeito == -1)){
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

        if(numDia < 0 || numDia > 4){
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



float relatorioGeral(int somaClientes, int cSim2, int cClienteNao, int cEncProcurava5){

    printf("\nQuantidade de clientes consultados -->  %d\n", somaClientes);

    printf("\nQuantidade de clientes que responderam 'nao' para as duas perguntas -->  %d\n", cClienteNao);

    printf("\nQuantidade de clientes que estao satisfeitos -->  %d\n", cSim2);

    float porcentagem;
    porcentagem = ((float) cEncProcurava5 / (float) somaClientes) * 100;

    printf("\nPorcentagem de clientes que encontraram o que procuravam no dia 5 da pesquisa -->  %.2f%%\n", porcentagem);

}