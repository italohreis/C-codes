#include <stdio.h>

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
    momento. 
 */

    //prototipo das funcoes;
    void RelatorioGeral();
    void RelatorioCor();
    void RelatorioCodigo();
    void BuscaVeiculo();
    void InserirVeiculo();



int main(void){

    int numCodigo, numCor;
    int carro[25][3];                   //carro[][0] --> codigo do carro                                
    int car = 0;                        //carro[][1] --> cor do carro
    int somaQuant = 0;               //carro[][2] --> quantidade                                  
    for(car = 0; car < 25; car++){
        printf("\nCarro %d\n", car);

        printf("informe o codigo do carro -> ");
        scanf("%d", &carro[car][0]);                

        printf("\ninforme a cor do veiculo (1 - branco / 2 - preto / 3 - vermelho / 4 - cinza) --> ");
        scanf("%d", &carro[car][1]);

        quant:
        printf("\nInforme a quantidade --> ");
        scanf("%d", &carro[car][2]);

        somaQuant += carro[car][2];

        if(somaQuant > 150){
            printf("\nQuantidade maxima atingida.\n");

            somaQuant -= carro[car][2];

            goto quant;
        }

        printf("quant -> %d", somaQuant);



        int resp;
        printf("\nDeseja adicionar outro veiculo ? (1 - sim / 0 nao) --> ");
        scanf("%d", &resp);

        if(resp == 0){
            break;
        }




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
                printf("\nResposta invalida.\n");



        }
    }



    return 0;

}