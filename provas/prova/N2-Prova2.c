#include <stdio.h>

#define red_text "\x1b[31m"
#define green_text "\x1b[32m"
#define orange_text "\x1b[33m"
#define reset_color "\x1b[0m"


    /* Uma escola de idiomas mantém 3 turmas de no máximo 30 alunos em cada. Os alunos recebem 2
    notas ao longo do ano, a média aritmética destas notas consiste na média final do aluno e a média
    para aprovação é no mínimo 7,0 pontos. O aluno deve ter também no máximo 10 faltas, caso
    contrário será reprovado por falta. Se o aluno tiver média final abaixo de 5,0 também será
    reprovado. O aluno que não foi aprovado, nem reprovado, terá a chance de fazer uma prova
    substitutiva. Elabore um programa em linguagem C que leia para cada aluno, seu nome, suas 2
    notas, sua frequência e mostre os seguintes relatórios:

    - Consulta por aluno:
    Dado o número do aluno e de sua turma, mostre seu nome, suas notas, sua média final, sua
    frequência e uma das mensagens: “Reprovado por falta”, “Reprovado por nota”, “Aprovado” ou
    “Fará substitutiva”.

    - Consulta por turma:
    Dado o número da turma, mostre quantos alunos a turma tem, quantos tiveram média final acima de
    8, quantos alunos tiveram algum zero em suas notas, quantos farão prova substitutiva e qual é a
    média de notas geral da turma.
    Após imprimir um relatório, deve ser possível ao usuário imprimir outro caso queira. */


typedef struct{
    float mediaAluno;
    float nota1;
    float nota2;
    int frequencia;
    char nome[30];
}aluno;
    
typedef struct{
    aluno alunos[30]; 

    float mediaTurma;
    int cAlunosTurma;
    int cMediaMaior8;
    int cAlunosZero;
    int cProvaSubst;
}turma;
    turma turmas[3];

    //prototipo

    void RelatorioAluno();
    void RelatorioTurma();
    void Menu();


int main(void){

    int class, student;
    for(class = 0; class < 3; class++){
        float somaNota = 0;
        printf("\nTurma %d\n", class);

        for(student = 0; student < 30; student++){
            printf("\n\tAluno %d\n", student);
            turmas[class].cAlunosTurma++;    //conta a quantidade de alunos por turma;

            printf("\n\tDigite o nome do aluno --> ");
            scanf("%s", turmas[class].alunos[student].nome);

            printf("\n\tDigite a primeira nota do aluno --> ");
            scanf("%f", &turmas[class].alunos[student].nota1);
            

            printf("\n\tDigite a segunda nota do aluno --> ");
            scanf("%f", &turmas[class].alunos[student].nota2);

            printf("\n\tInforme a quantidade de faltas do aluno --> ");
            scanf("%d", &turmas[class].alunos[student].frequencia);

            
            turmas[class].alunos[student].mediaAluno =  (turmas[class].alunos[student].nota1 +  turmas[class].alunos[student].nota2) / (float) 2; //media final do aluno;

            somaNota += turmas[class].alunos[student].mediaAluno;

            if(turmas[class].alunos[student].mediaAluno > 8){
                turmas[class].cMediaMaior8++;

            } 

            if(turmas[class].alunos[student].frequencia < 10){

                if(turmas[class].alunos[student].mediaAluno > 5 && turmas[class].alunos[student].mediaAluno < 7){
                    turmas[class].cProvaSubst++;
                }
            }


            if(turmas[class].alunos[student].nota1 == 0 || turmas[class].alunos[student].nota2 == 0){
                turmas[class].cAlunosZero++;    //quantidade de alunos por turma que tiraram zero nas duas provas
            }

            int resp;
            printf("\n\tDeseja continuar para outro aluno ? (1 - sim / 0 - nao) --> ");
            scanf("%d", &resp);

            if(resp != 0 && resp != 1){
                printf("\nResposta invalida, tente novamente.\n");

            } else if(resp == 0){
                break;
            }
        }

        turmas[class].mediaTurma = somaNota / (float) turmas[class].cAlunosTurma;       //media geral por turma
    }

    Menu();

    return 0;
}


void Menu(){

    while(1){

        printf("\n\n\nO que deseja fazer ?\n");

        int op;
        printf("\n 1 - Relatorio por aluno.\n 2 - Relatorio por turma.\n 3 - Finalizar\n");
        scanf("%d", &op);

        switch(op){

            case 1:
                RelatorioAluno();
                break;
            case 2:

                RelatorioTurma();
                break;
            case 3:
                printf("\n\nFinalizando..\n\n");
                return;

            default:
                printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
                break;
        }

    }



}

void RelatorioAluno(){
    int numTurma = -1, numAluno;

    while(numTurma < 0 || numTurma > 2){
        printf("\n\nQual turma do aluno ? --> ");
        scanf("%d", &numTurma);

        if(numTurma < 0 || numTurma > 2){
            printf(red_text "\nTurma invalida.\n" reset_color);
        }
    }

   
    printf("\nQual aluno deseja consultar --> ");
    scanf("%d", &numAluno);

       

    printf("\nNome do aluno --> %s\n", turmas[numTurma].alunos[numAluno].nome);

    printf("\n\tNota 1 do aluno --> %.2f", turmas[numTurma].alunos[numAluno].nota1);
    printf("\n\tNota 2 do aluno --> %.2f", turmas[numTurma].alunos[numAluno].nota2);

    printf("\n\tMedia final do aluno --> %.2f", turmas[numTurma].alunos[numAluno].mediaAluno);

    printf("\n\tQuantidade de faltas do aluno --> %d\n", turmas[numTurma].alunos[numAluno].frequencia);

    //verificar status do aluno

    if(turmas[numTurma].alunos[numAluno].frequencia > 10){
        printf(red_text "\n\tReprovado por falta.\n" reset_color);
    } else{
        
        if(turmas[numTurma].alunos[numAluno].mediaAluno > 7){
            printf(green_text "\n\tAprovado por nota\n" reset_color);

        } else if(turmas[numTurma].alunos[numAluno].mediaAluno < 5){
            printf(red_text "\n\tReprovado por nota.\n" reset_color);

        } else{
            printf(orange_text "\n\tFara prova substitutiva\n" reset_color);
        }
    }

    return;
}

void RelatorioTurma(){
    int numTurma = -1;

    while(numTurma < 0 || numTurma > 2){
        printf("\n\nQual turma deseja consultar --> ");
        scanf("%d", &numTurma);

        if(numTurma < 0 || numTurma > 2){
            printf(red_text "\nTurma invalida.\n" reset_color);
        }

    }
    printf("\n\tQuantidade de alunos na turma %d --> %d\n", numTurma, turmas[numTurma].cAlunosTurma);

    printf("\n\tQuantidade de alunos que tiverem media acima de 8 na turma %d --> %d\n", numTurma, turmas[numTurma].cMediaMaior8);
    
    printf("\n\tQuantidade de alunos que tiraram zero em alguma das notas na turma %d --> %d\n", numTurma, turmas[numTurma].cAlunosZero);

    printf("\n\tQuantidade de alunos que farao prova substitutiva na turma %d --> %d\n", numTurma, turmas[numTurma].cProvaSubst);

    printf("\n\tMedia geral da turma %d --> %.2f\n", numTurma, turmas[numTurma].mediaTurma);

    return;
}