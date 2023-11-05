#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define red_text "\x1b[31m"
#define green_text "\x1b[32m"
#define reset_color "\x1b[0m"
#define orange_text "\x1b[33m"


    /* Uma escola de idiomas ministrará um curso intensivo de 1 ano. Serão abertas 2 turmas de no
    máximo 5 alunos em cada. Os alunos recebem 3 notas ao longo do ano, a média aritmética destas
    notas consiste na média final do aluno e a nota para receber o certificado é no mínimo 7,0 pontos. O
    aluno deve ter também no máximo 10 faltas, caso contrário será reprovado por falta. Se o aluno
    tiver média final abaixo de 5,0 também será reprovado. O aluno que não foi aprovado, nem
    reprovado, terá a chance de fazer uma prova substitutiva. Elabore um programa em linguagem C
    que leia para cada aluno, seu nome, suas 3 notas, sua frequência e mostre um dos os seguintes
    relatórios:

    - Consulta por aluno:
    Dado o número do aluno e de sua turma, mostre seu nome, suas notas, sua média final, sua
    frequência e uma das mensagens: “Reprovado por falta”, “Reprovado por nota”, “Certificado
    Liberado” ou “Fará substitutiva”.

    - Consulta por turma:
    Dado o número da turma, mostre quantos alunos tem a turma, quantos tiveram média final acima de
    8, quantos alunos tiveram algum zero em suas notas, quantos farão prova substitutiva e qual é a
    média de notas geral da turma.

    Após imprimir um relatório, deve ser possível ao usuário imprimir outro caso queira.
    Obs.: Implementar pelo menos uma função que receba como parâmetros média final e frequência de
    um aluno e retorne 0 se foi reprovado por falta, 1 se reprovado por nota, 2 se o certificado foi
    liberado ou 3 se fará prova substitutiva */

   int StatusAluno(int numTurma, int numAluno);

    int frequencia[2][5];
    float media[2][5];

int main(void){

    float Notas[2][5][3];
    char nome[2][5][30];
    int cAlunos[2] = {0};
    int cMediaMaior8[2] = {0}, cSubst[2] = {0};
    int cZero[2] = {0};

    int i, j, k;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 5; j++){
            for(k = 0; k < 3; k++){
                Notas[i][j][k] = -1;
            }
        }
    }

    float soma[2][5] = {{0}};
    float somaGeral[2] = {0};
    float MediaGeral[2] = {0};
    int turma, aluno, nota;

    for(turma = 0; turma < 2; turma++){
        printf("\nTurma %d\n", turma);

        for(aluno = 0; aluno < 5; aluno++){
            cAlunos[turma]++;
            printf("\n\t* Aluno %d *\n", aluno);

            printf("\n\tDigite o nome do aluno --> ");
            scanf("%s", &nome[turma][aluno]);

            printf("\n\tInforme a quantidade de faltas do aluno --> ");
            scanf("%d", &frequencia[turma][aluno]);

            for(nota = 0; nota < 3; nota++){

                while(Notas[turma][aluno][nota] < 0 || Notas[turma][aluno][nota] > 10){
                    printf("\n\tDigite a nota %d do aluno --> ", nota);
                    scanf("%f", &Notas[turma][aluno][nota]);

                    if(Notas[turma][aluno][nota] < 0 || Notas[turma][aluno][nota] > 10){
                        printf(red_text "\n\tNota invalida, tente novamente.\n" reset_color);
                    }
                }

                soma[turma][aluno] += Notas[turma][aluno][nota];

                if((frequencia[turma][aluno] < 10) && (Notas[turma][aluno][nota] > 5 && Notas[turma][aluno][nota] < 7)){
                    cSubst[turma]++;
                }

            }
            

            media[turma][aluno] = soma[turma][aluno] / 3;
            somaGeral[turma] += media[turma][aluno];

            if(media[turma][aluno] > 8){
                cMediaMaior8[turma]++;
            }
            

            int resp = -1;
            while(resp != 0 && resp != 1){
                printf("\n\tDeseja continuar para outro aluno ? (1 - sim / 0 - nao) --> ");
                scanf(" %d", &resp);

                if(resp != 0 && resp != 1){
                    printf(red_text "\n\tResposta invalida, tente novamente.\n" reset_color);

                }
            }

            if(resp == 0){
                break;
            }
            printf("\n");
        }

            MediaGeral[turma] = (float) somaGeral[turma] / (float) cAlunos[turma];
    }

    while(1){
        int op;
        int numAluno, numTurma;

        printf("\n\nO que deseja fazer ?\n");
        printf(" 1 - Consulta por aluno\n 2 - Consulta por turma.\n 3 - Finalizar.\n");
        scanf("%d", &op);

        switch(op){

            case 1:
                numTurma = -1;
                while(numTurma != 0 && numTurma != 1){
                    printf("\nQual turma pertence o aluno ? --> ");
                    scanf(" %d", &numTurma);

                    if(numTurma != 0 && numTurma != 1){
                        printf(red_text "\nTurma invalida, tente novamente.\n" reset_color);
                    }
                }

                numAluno = 6;
                while(numAluno > cAlunos[numTurma] - 1){
                    printf("\nQual aluno deseja consultar ? --> ");
                    scanf("%d", &numAluno);

                    if(numAluno > cAlunos[numTurma] - 1){
                        printf(red_text "\nAluno inexistente, tente novamente.\n" reset_color);
                    }
                }

                
                StatusAluno(numTurma, numAluno);

                printf("\n\tNome do aluno --> %s\n", nome[numTurma][numAluno]);

                int i;
                for(i = 0; i < 3; i++){
                    printf("\n\tNota %d -->  %.2f\n", i, Notas[numTurma][numAluno][i]);
                }

                printf("\n\tMedia final do aluno -->  %.2f\n", media[numTurma][numAluno]);

                printf("\n\tQuantidade de faltas do aluno --> %d\n", frequencia[numTurma][numAluno]);

                int numero;
                numero = StatusAluno(numTurma, numAluno);

                if(numero == 0){
                    printf(red_text "\n\tReprovado por falta.\n" reset_color);

                } else if(numero == 1){
                    printf(red_text "\n\tReprovado por nota.\n" reset_color);

                } else if (numero == 2){
                    printf(green_text "\n\tCertificado liberado.\n" reset_color);

                } else{
                    printf(orange_text "\n\tFara prova substitutiva.\n" reset_color);
                }
                break;

            case 2:
                numTurma = -1;
                while(numTurma != 0 && numTurma != 1){
                    printf("\nQual turma deseja consultar ? --> ");
                    scanf("%d", &numTurma);

                    if(numTurma != 0 && numTurma != 1){
                        printf(red_text "\nTurma invalida, tente novamente.\n" reset_color);
                    }
                }

                printf("\n\tQuantidade de alunos na turma %d -->  %d\n", numTurma, cAlunos[numTurma]);

                printf("\n\tQuantidade de alunos com media final maior que 8 -->  %d\n", cMediaMaior8[numTurma]);

                int k, j;
                for(k = 0; k < 5; k++){
                    for(j = 0; j < 3; j++){
                        if(Notas[numTurma][k][j] == 0){
                            cZero[numTurma]++;
                            break;
                        }
                    }
                }

                printf("\n\tQuantidade de alunos que tiverem alguma nota com 0 -->  %d\n", cZero[numTurma]);

                printf("\n\tQuantidade de alunos que farao prova substitutiva --> %d\n", cSubst[numTurma]);

                printf("\n\tMedia geral da turma -->  %.2f\n", MediaGeral[numTurma]);
                break;

            case 3:
                printf("\n\nfim.\n\n");
                return 0;

            default:
                printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
                break;


        }
    }


    return 0;
}




int StatusAluno(int numTurma, int numAluno){

        if (frequencia[numTurma][numAluno] > 10){
            return 0;
        }
        else{

            if(media[numTurma][numAluno] < 5){
                return 1;

            } else if(media[numTurma][numAluno] >= 7){
                return 2;

            } else{
                return 3;
            }
        }

}