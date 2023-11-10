#include <stdio.h>
#include <stdbool.h>

#define red_text "\x1b[31m"
#define green_text "\x1b[32m"
#define reset_color "\x1b[0m"

/* Uma concessionária de veículos mantêm o cadastro de seus veículos desta forma:
    código do veículo (número inteiro),
    código da cor (número inteiro, 1 para branco, 2 para preto, 3 para vermelho e 4 para cinza),
    quantidade.

    A capacidade máxima de armazenagem nas suas garagens é de 150 veículos. Não permita que
    sejam cadastrados mais veículos do que a capacidade.

    Faça um programa que inicialmente leia os dados dos vários veículos que estão atualmente na
    concessionária. Serão cadastrados, no máximo 25 tipos de veículos. Não permita código do veículo
    com mesma cor em linhas diferentes.

    Após esta leitura inicial, ofereça ao vendedor, sempre que desejar, a possibilidade de consultar um
    destes relatórios: Relatório geral (mostre todos os veículos e seus dados, a quantidade total de
    veículos e a percentagem de ocupação das garagens), relatório por cor (dada a cor, mostre a
    quantidade total e todos os veículos desta cor), relatório por código (dado o código, mostre a
    quantidade total e todos os veículos com o código e seus dados), busca por veículo (Dados o
    código do veículo e sua cor, mostre a quantidade. Se o veículo for encontrado, a busca deve ser
    interrompida). Pode ocorrer a necessidade de cadastrar um veículo que tenha sido adquirido
    esporadicamente, então o programa deve ser capaz de inserir um veículo (apenas 1) a qualquer
    momento.  */



typedef struct {
    int codigo;
    int cor;
    int quantidadeCarro;
} carro;

//prototipos das funcoes
void QuantidadeCarros(carro *carros, int code, int color, int *QuantidadeTotal, int *cCarros);

void RelatorioGeral(carro *carros, int QuantidadeTotal, int cCarros);
void RelatorioCor(carro *carros, int color, int cCarros);
void RelatorioCodigo(carro *carros, int code, int cCarros);
void BuscaVeiculo(carro *carros, int code, int color, int cCarros);


int main(void){
    carro carros[25];    

    int i;
    for (i = 0; i < 25; i++){   
        carros[i].codigo = 0;
    }

    int QuantidadeTotal = 0;
    int numCor, numCodigo;
    int code, color;
    int resp, cCarros = 0;    

    do{
        printf("\n---------------------------------------------------------------------------------\n");
        printf("\nDigite o codigo do carro --> ");
        scanf("%d", &code);

        color = 0;
        while(color < 1 || color > 4){          
            printf("\nDigite a cor do carro (1 - branco / 2 - preto / 3 - vermelho / 4 - cinza) --> ");
            scanf("%d", &color);

            if(color < 1 || color > 4){
                printf(red_text "\nCor invalida, tente novamente.\n" reset_color);
            }
        }

        QuantidadeCarros(carros, code, color, &QuantidadeTotal, &cCarros);  

        resp = -1;
        while(resp != 0 && resp != 1){
            printf("\nDeseja inserir mais carros ? (1 - sim / 0 - nao) --> ");
            scanf("%d", &resp);

            if(resp != 0 && resp != 1){
                printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
            }
        }                                                 
        
        if(cCarros == 25){
            printf(red_text "\nLimite de carros atingido.\n" reset_color);
            break;
        }

    } while (resp == 1);


    int op;
    while (1){
        printf("\n\nO que deseja fazer ?\n\n");
        printf(" 1 - relatorio geral.\n 2 - relatorio por cor.\n 3 - relatorio por codigo.\n 4 - busca por veiculo.\n" 
        " 5 - inserir um veiculo.\n 6 - finalizar.\n");
        scanf("%d", &op);

        switch (op){
            case 1:
                RelatorioGeral(carros, QuantidadeTotal, cCarros);
                break;

            case 2:
                printf("\nQual cor deseja consultar ? --> ");
                scanf("%d", &numCor);
                
                RelatorioCor(carros, numCor, cCarros);
                break;

            case 3:
                printf("\nQual codigo do veiculo que deseja consultar ? --> ");
                scanf("%d", &numCodigo);
                
                RelatorioCodigo(carros, numCodigo, cCarros);

                break;

            case 4:
                printf("\nQual o codigo do veiculo ? --> ");
                scanf("%d", &numCodigo);
                printf("\nQual cor do veiculo ? --> ");
                scanf("%d", &numCor);
                
                BuscaVeiculo(carros, numCodigo, numCor, cCarros);

                break;

            case 5:

                if(QuantidadeTotal == 150){
                    printf(red_text "\nLimite de carros atingido, nao e possivel adicionar um veiculo.\n" reset_color);
                    break;
                }

                
                
                
                printf("\nQual o codigo do veiculo ? --> ");
                scanf("%d", &numCodigo);

                numCor = 0;
                while(numCor < 1 || numCor > 4){
                    printf("\nQual cor do veiculo ? (1 - branco / 2 - preto / 3 - vermelho / 4 - cinza)--> ");
                    scanf("%d", &numCor);

                    if(numCor < 1 || numCor > 4){
                        printf(red_text "\nCor invalida, tente novamente.\n" reset_color);
                    }
                }

                int i;
                for(i = 0; i < cCarros; i++){
                    if(carros[i].codigo == numCodigo && carros[i].cor == numCor){
                        carros[i].quantidadeCarro += 1;
                        QuantidadeTotal += 1;

                        printf(green_text "\nVeiculo inserido com sucesso.\n" reset_color);
                        break;
                    }
                }

                if(i == cCarros){

                    if(cCarros == 25){
                        printf("\nLimite de tipos de veiculos atingido, nao e possivel adicionar um veiculo.\n");
                        break;
                    }

                    carros[i].codigo = numCodigo;
                    carros[i].cor = numCor;
                    carros[i].quantidadeCarro = 1;
                    QuantidadeTotal += 1;

                    cCarros += 1;

                    printf(green_text "\nVeiculo inserido com sucesso.\n" reset_color);
                    break;
                }

                break;
            case 6:
                printf("\nfim.\n");
                return 0;

            default:
                printf(red_text "\nResposta inválida, tente novamente.\n" reset_color);
        }
    }

    return 0;
}


void QuantidadeCarros(carro *carros, int code, int color, int *QuantidadeTotal, int *cCarros){
    int quantidade;
    printf("\nDigite a quantidade de carros --> ");
    scanf("%d", &quantidade);

    int i;
    for (i = 0; i < cCarros; i++){

        if (code == carros[i].codigo && color == carros[i].cor) {
            carros[i].quantidadeCarro += quantidade;
            *QuantidadeTotal += quantidade;

            if (*QuantidadeTotal > 150){
                printf(red_text "\nLimite de carros atingido.\n" reset_color);

                *QuantidadeTotal -= quantidade;

                carros[i].quantidadeCarro -= quantidade;
            }
            return; 
        }
        
        if (carros[i].codigo == 0){
            *cCarros += 1;
            carros[i].codigo = code;
            carros[i].cor = color;
            carros[i].quantidadeCarro = quantidade;
            *QuantidadeTotal += quantidade;

            if (*QuantidadeTotal > 150){
                printf(red_text "\nLimite de carros atingido.\n" reset_color);

                *QuantidadeTotal -= quantidade;
                *cCarros -= 1;

                carros[i].codigo = 0;
                carros[i].cor = 0;
                carros[i].quantidadeCarro = 0;
            }
            return; 
        }
    }
}

void RelatorioGeral(carro *carros, int QuantidadeTotal, int cCarros){
    float porcentagem;

    porcentagem = ((float) QuantidadeTotal * 100) / 150;

    printf("\n\t< Relatorio geral >\n");

    printf("\n\tQuantidade total de carros: %d\n", QuantidadeTotal);
    printf("\n\tPorcentagem de ocupacao da garagem --> %.2f%%\n", porcentagem);
    
    int i;
    for (i = 0; i < cCarros; i++) {

        if (carros[i].codigo != 0) {
            printf("\n\tCodigo do carro: %d\n", carros[i].codigo);
            printf("\tCor do carro: --> ");

            switch (carros[i].cor){
                case 1:
                    printf("Branco\n");
                    break;
                case 2:
                    printf("Preto\n");
                    break;
                case 3:
                    printf("Vermelho\n");
                    break;
                case 4:
                    printf("Cinza\n");
                    break;
            }
            
        }
    }
    return;
}

void RelatorioCor(carro *carros, int color, int cCarros){
    int quantidade = 0;
    printf("\n< Relatorio por cor >\n");
    printf("\n\tCor dos carros --> ");
    switch(color){
        case 1:
            printf("Branco\n");
            break;
        case 2:
            printf("Preto\n");
            break;
        case 3:
            printf("Vermelho\n");
            break;
        case 4:
            printf("Cinza\n");
            break;
    }

    int i;
    for (i = 0; i < cCarros; i++) {
        if (carros[i].cor == color){
            printf("\n\tCodigo do carro: %d\n", carros[i].codigo);

            quantidade += carros[i].quantidadeCarro;
        }
    }
    
    printf("\n\tQuantidade total de carros da cor -->  %d\n", quantidade);
    return;
}

void RelatorioCodigo(carro *carros, int code, int cCarros){
    int quantidade = 0;
    printf("\n< Relatorio por codigo >\n");

    int i;
    for (i = 0; i < cCarros; i++){        
        if (carros[i].codigo == code) {
            printf("\n\tQuantidade de veiculos --> %d\n", carros[i].quantidadeCarro);
            printf("\tCor do carro --> ");

            switch (carros[i].cor){
                case 1:
                    printf("branco\n");
                    break;
                case 2:
                    printf("preto\n");
                    break;
                case 3:
                    printf("vermelho\n");
                    break;
                case 4:
                    printf("cinza\n");
                    break;
            }
            quantidade += carros[i].quantidadeCarro;
        }
    }
    printf("\n\tQuantidade total de veiculos do codigo fornecido-->  %d\n", quantidade);
    return;
}

void BuscaVeiculo(carro *carros, int code, int color, int cCarros){
    int i;

    for(i = 0; i < cCarros; i++){
        if((carros[i].codigo == code) && (carros[i].cor == color)){
            
            printf("\n\tQuantidade de veiculos --> %d\n", carros[i].quantidadeCarro);
            return;
        } 
    }

    printf(red_text "\nVeiculo nao encontrado.\n" reset_color);
    return;
}