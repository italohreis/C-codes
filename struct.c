#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

float f = 1;

int main(void){

    //Durante 6 meses, 30 funcionários de um shopping participaram de um programa de exercícios
    //ocupacionais. Durante o programa foram registrados, para cada funcionário, sua idade, medições
    //mensais de frequência cardíaca e várias medições do peso corporal. Elabore um algoritmo que,
    //para cada funcionário, mostre seu peso médio e a maior frequência cardíaca registrada durante o
    //programa. No final mostre ainda a percentagem de funcionários que tiveram sua maior frequência
    //cardíaca ultrapassando 105 bpm e quantos tiveram o peso médio maior que seu peso final,
    //quantos tiveram o peso médio menor que seu peso final e quantos forram iguais.
    //obs.: Na leitura das medições do peso, utilize o valor -1 para indicar que a sequência de medições
    //finalizou (o valor -1 na entrada é o código para a parada da estrutura de repetição e não deve ser
    //processado). Considere que os valores de peso e frequência cardíaca são valores reais.
    
    typedef struct{
        int idade;
        float peso[1001];
        float frequencia[7];
        float mediapeso;
        float maiorfrequencia;
        float ultimopeso;
        bool lido;
    } funcionario;
    funcionario funcionarios[33];  

    LerFuncionario:
    printf("\n");

    int funcionarioLido;
    printf("Digite o numero do funcionario --> ");
    scanf(" %d", &funcionarioLido);

    if(funcionarios[funcionarioLido].lido == true){
            printf("\nFuncionario ja processado, escolha outro funcionario.\n");
            goto LerFuncionario;
        }

        funcionarios[funcionarioLido].lido = true;

    printf("\n* FUNCIONARIO %d *\n", funcionarioLido);
    int mes;
    for(mes = 1; mes <=6; mes ++){
        printf("\tDigite a frequencia cardiaca do funcionario %d no mes %d --> ", funcionarioLido, mes);
        scanf(" %f", &funcionarios[funcionarioLido].frequencia[mes]);

        if(funcionarios[funcionarioLido].frequencia[mes] > funcionarios[funcionarioLido].maiorfrequencia){
            funcionarios[funcionarioLido].maiorfrequencia = funcionarios[funcionarioLido].frequencia[mes];
        }
    }
    int i = 1;
    do{
        printf("\n\tDigite os pesos medidos do funcionario %d --> ", funcionarioLido);
        int pesolido;
        scanf(" %d", &pesolido);
        if(pesolido < 0){
            funcionarios[funcionarioLido].ultimopeso = funcionarios[funcionarioLido].peso[i-1];
            break;
        } else{
            funcionarios[funcionarioLido].peso[i] = pesolido;
        }
        i++;
        }while(true);

    printf("\n\tDigite a idade do funcionario %d --> ", funcionarioLido);
    scanf(" %d", &funcionarios[funcionarioLido].idade);
    
    float somapeso = 0;
    int j;
    for(j = 1; j <= i; j++){
        somapeso += funcionarios[funcionarioLido].peso[j];
    }
    funcionarios[funcionarioLido].mediapeso = somapeso / (i - 1);

    printf("\n\t----------------------------------------------------------------\n");

    printf("\t< Relatorio do funcionario %d >", funcionarioLido);

    printf("\n\n\tMedia de peso do funcionario %d --> %.2f\n", funcionarioLido, funcionarios[funcionarioLido].mediapeso);
    printf("\n\tMaior frequencia cardiaca do funcionario %d --> %.2f\n", funcionarioLido, funcionarios[funcionarioLido].maiorfrequencia);

    printf("\n\t----------------------------------------------------------------\n");
    int leroutro;

    while(1){
        printf("\n\nDeseja ler outro funcionario? (1 - Sim / 0 - Nao) --> ");
        scanf(" %d", &leroutro);
        
        if(leroutro == 1 || leroutro == 0){
            break;
        }
        else{
            printf("\nResposta invalida, tente novamente.\n");
        }
    }
        if(leroutro == 1){
            f++;
            goto LerFuncionario;     
        }    

    int mediaMenorQuePeso = 0;
    int mediaMaiorQuePeso = 0;
    int mediaIgualPeso = 0;

    for (i = 1; i <= 30; i++){
        if(funcionarios[i].mediapeso != 0){
            if(funcionarios[i].mediapeso > funcionarios[i].ultimopeso){
                mediaMaiorQuePeso++;
            }
            if (funcionarios[i].mediapeso < funcionarios[i].ultimopeso){
                mediaMenorQuePeso++;
            } 
            if (funcionarios[i].mediapeso == funcionarios[i].ultimopeso) {
                mediaIgualPeso++;
            }
        }
    }

    printf("\n\n------------------------------------------------------------------------\n");

    printf("\nRelatorio final.\n");
    printf("\nFuncionarios com peso medio maior que o peso final -->  %d\n\n", mediaMaiorQuePeso);
    printf("Funcionarios com peso medio menor que o peso final -->  %d\n\n", mediaMenorQuePeso);
    printf("Funcionarios com peso medio igual ao peso final -->  %d\n\n", mediaIgualPeso);
    
    int maiorQue105 = 0;
    for (i = 1; i <= 30; i++){
        if(funcionarios[i].maiorfrequencia > 105){
            maiorQue105++;
        }
    }
    maiorQue105 = (maiorQue105 * 100) / f;

    printf("Porcentagem de funcionarios com frequencia cardiaca maior que 105 --> %d%%\n\n", maiorQue105);
    printf("------------------------------------------------------------------------\n\n");
    
    return 0;
}
