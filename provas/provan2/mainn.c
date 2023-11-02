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



int main(void) {
    int i, j;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 20; j++){
            dias[i].clientes[j].encOqProcurava = -1;
            dias[i].clientes[j].ficSatisfeito = -1;
        }
    }


    int cNao1 = 0, cSim1 = 0;
    int cNao2 = 0, cSim2 = 0;

    int dia, cliente, resp;
    int somaClientes = 0;

    int cEncProcurava5 = 0;
    int cClienteNao = 0;

    for (dia = 0; dia < 5; dia++){
        printf("\n\nDia %d\n", dia);

        for(cliente = 0; cliente < 20; cliente++){
            dias[dia].cCliente++;
            somaClientes++;

            printf("\n\tCliente %d", cliente);

            while(dias[dia].clientes[cliente].encOqProcurava != 0 && dias[dia].clientes[cliente].encOqProcurava != 1){

                printf("\n\tEncontrou o que procurava ? (1 - sim / 0 - nao) --> ");
                scanf("%d", &dias[dia].clientes[cliente].encOqProcurava);

                if(dias[dia].clientes[cliente].encOqProcurava != 0 && dias[dia].clientes[cliente].encOqProcurava != 1){
                    printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
                }
            }

            if(dias[dia].clientes[cliente].encOqProcurava == 1){
                cSim1++;
                if(dia == 4){
                    cEncProcurava5++;
                }
            } else{
                cNao1++;
            }

            while(dias[dia].clientes[cliente].ficSatisfeito != 0 && dias[dia].clientes[cliente].ficSatisfeito != 1){

                printf("\n\tFicou satisfeito ? (1 - sim / 0 nao) --> ");
                scanf("%d", &dias[dia].clientes[cliente].ficSatisfeito);

                if(dias[dia].clientes[cliente].ficSatisfeito != 0 && dias[dia].clientes[cliente].ficSatisfeito != 1){
                    printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
                }
            }
            
            if(dias[dia].clientes[cliente].ficSatisfeito == 1){
                cSim2++;
            } else{
                cNao2++;
            }

            if((dias[dia].clientes[cliente].encOqProcurava == 0) && (dias[dia].clientes[cliente].ficSatisfeito == 0)){
                cClienteNao++;
            }
            
            resp = -1;
            while(resp != 0 && resp != 1){
                printf("\n\tDeseja continuar para outro cliente? (1 - sim / 0 - nao) --> ");
                scanf("%d", &resp);

                if(resp != 0 && resp != 1){
                    printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
                }
            }

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
                relatorioGeral(somaClientes, cSim2, cClienteNao, cEncProcurava5);
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