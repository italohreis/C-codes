#include <stdio.h>
#include <stdbool.h>


#define red_text "\x1b[31m"
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

    //prototipo das funcoes;

    void RelatorioGeral();
    void RelatorioCor();
    void RelatorioCodigo();
    void BuscaVeiculo();
    void InserirVeiculo();



typedef struct{
    int codigo;
    int cor;
    int quantidadeCarro;
} carro;
    carro carros[4];



int main(void){
    int numCor, numCodigo;
    int cCarro = 0;
    int code, cores;
    int quantidadeTotal;

    InserirVeiculo();

    int i;
    for(i = 0; i< 25; i++){
        quantidadeTotal += carros[i].quantidadeCarro;

    }

    int op;
    printf("\nO que deseja fazer ?\n");
    printf("1 - relatorio geral.\n 2 - relatorio por cor.\n 3 - relatorio por codigo.\n 4 - busca por veiculo.\n 5 - inserir um veiculo.\n 6 - finalizar.");
    scanf("%d", &op);


    while(1){

        switch(op){

            case 1:
                

            case 2:
                printf("\nQual cor deseja consultar ? --> ");
                scanf("%d", &numCor);
                break;
                

            case 3:
                
                printf("\nQual codigo do veiculo que deseja consultar ? --> ");
                scanf("%d", &numCodigo);

               
                
                break;

            case 4:

                printf("Qual o codigo do veiculo ? --> ");
                scanf("%d", &numCodigo);

                int numCor;
                printf("\nQual cor do veiculo ? --> ");
                scanf("%d", &numCor);
                break;
                

            case 5:
                printf("\nqual codigo do veiculo ? --> ");
                scanf("%d", &numCodigo);

                printf("\nqual cor do veiculo --> ");
                scanf("%d", &numCor);
                break;

            case 6:
                printf("\nfim.\n");
                return 0;
                break;

            default:
                printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);



        }
    }

    

    
}





void VerificarCarro(int code, int cores, int quantidade){

    int i;
    for(i = 0; i < 4; i++){    //se codigo e cor igual, soma a quantidade de carros do tipo do carro, e nao adiciona um novo carro
        
        if((code == carros[i].codigo) && (cores == carros[i].cor)){
            carros[i].quantidadeCarro += quantidade;

        } else{
            carros[i].codigo = code;
            carros[i].cor = cores;
            carros[i].quantidadeCarro = quantidade;

      
        }
    }
    printf("\nquantidade de carros %d\n", carros[i].quantidadeCarro);

    return;

}   



    int QuantidadeCarros(int codes, int color, int car) {
        int quantidade, QuantidadeTotal;

        if(QuantidadeTotal == 0){
            QuantidadeTotal = 0;
        }

        printf("\nDigite a quantidade de carros --> ");
        scanf("%d", &quantidade);

        int codeFuncao = codes, corFuncao = color, carFuncao = car;
                
        VerificarCarro(codes, color, quantidade);

        QuantidadeTotal += carros[car].quantidadeCarro;
                
        if(QuantidadeTotal > 150){
            printf("\nQuantidade total de carros %d\n", QuantidadeTotal); //testando
            printf(red_text "\nQuantidade maxima de carros atingida.\n" reset_color);
                    
            QuantidadeTotal -= carros[car].quantidadeCarro;
            QuantidadeCarros(codeFuncao, corFuncao, carFuncao); //recursividade
        } else{
            InserirVeiculo();
        }
        
}

void InserirVeiculo(){
    int car, code, cores;

    for(car = 0; car < 25; car++){
        printf("\nDigite o codigo do carro --> ");
        scanf("%d", &code);

        printf("\nDigite a cor do carro (1 - branco / 2 - preto / 3 - vermelho / 4 - cinza) --> ");
        scanf("%d", &cores);

        
        QuantidadeCarros(code, cores, car);


        int resp;
        printf("\nDeseja adicionar outro veiculo ? (1 - sim / 0 - nao) --> ");
        scanf("%d", &resp);

        if (resp == 0){
            break;
        }

    }
}

