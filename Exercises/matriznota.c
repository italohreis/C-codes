#include <stdio.h>
#include <string.h>

typedef struct{
    float nota;
} Aluno;

typedef struct {
    Aluno alunos[31];
    int cAlunos;
    float mediadaturma;
    float somanota;
    int Alunosacimadamedia;
} Turma;
Turma turmas[4];

float maiormedia;
int classe;

int main(void){
    

//Ler as notas finais de 3 turmas de no máximo 30 alunos (não perguntar o número de alunos).
//Disponibilizar as seguintes relatórios:
//- Nota individual: Dados número do aluno e número da turma, mostre a nota.
//- Média da turma: Dado número da turma, mostre a média de notas da turma.
//- Alunos acima da média: Dado número da turma, mostre quais alunos tiveram nota maior
//que a média de sua turma.
//- Maior média: Mostre a turma com maior média.

int i, j, k;
int qAlunos = 0;
    
    for (j = 1; j <=3; j++){
        for (k = 1; k <= 30; k++){
            turmas[j].alunos[k].nota = -1;
        }
    }
    printf("Insira as notas dos alunos, digite -1 caso queira seguir para a proxima turma.\n\n");
    for (i = 1; i <=3; i++){
    qAlunos=0;
    printf("* TURMA  %d *\n\n", i);
    do{
        qAlunos++;
        printf("\tAluno %d\n", qAlunos);
        printf("\tNota: ");
        scanf("%f", & turmas[i].alunos[qAlunos].nota);
        printf("\n");
        if (qAlunos >= 30){
            break;
        }

    }while (turmas[i].alunos[qAlunos].nota != -1);
}
     
    for (j = 1; j <=3; j++){
        for (k = 1; k <= 30; k++){
            if(turmas[j].alunos[k].nota >= 0){
                turmas[j].somanota += turmas[j].alunos[k].nota;
                turmas[j].cAlunos++;
                turmas[j].mediadaturma = (turmas[j].somanota/turmas[j].cAlunos);  
            }
            if(turmas[j].mediadaturma > maiormedia){
                maiormedia = turmas[j].mediadaturma;
                classe = j;
            }
        }
    }
        
    for (j = 1; j <=3; j++){
        for (k = 1; k <= 30; k++){
            if(turmas[j].alunos[k].nota > turmas[j].mediadaturma){
                turmas[j].Alunosacimadamedia++;
            }
        }
    }
        
    

    start:
    printf("\n");
    int action = 0;

    while (action > 4 || action < 1){
        printf("\no que deseja fazer ? \n");
        printf(" 1 - Ler nota individual. \n 2 - Imprimir a media da turma \n 3 - Mostrar quantos alunos estao acima da media\n 4 - finalizar.\n");
        scanf("%d", &action);
    }

    if (action == 1){
        int nTurma = 0;
        int nAlunos = 0;
        printf("numero da turma: ");
        scanf("%d", &nTurma);
        if(nTurma > 3){ 
            printf("\nTurma inexistente.\n"); 
            goto start;
        }
        printf("\nnumero do aluno: ");
        scanf(" %d", &nAlunos);
        if(turmas[nTurma].alunos[nAlunos].nota < 0){
            printf("\nAluno nao existe.\n");
            goto start;
        }

        printf("\nNOTA: %.2f", turmas[nTurma].alunos[nAlunos].nota);
        goto start;
    }
    if (action == 2){
        int nTurma = 0;
        printf("numero da turma: ");
        scanf("%d", &nTurma);
        if(nTurma > 3){
            printf("\nTurma inexistente.\n");
            goto start;
        }
        printf("\nMedia da turma: %.2f\n", turmas[nTurma].mediadaturma);
        goto start;
    }
    if (action == 3){
        int nTurma = 0;
        printf("\nNumero da turma: ");
        scanf("%d", &nTurma);
        if(nTurma > 3){
            printf("Turma inexistente.\n");
            goto start;
        }
        printf("\n%d Alunos possuem nota acima da media.\n", turmas[nTurma].Alunosacimadamedia);
        goto start;
    }
    else{
        goto fim;
    }
    
    fim:
        printf("\nA turma %d possui a maior media, com nota %.2f\n\n", classe, turmas[classe].mediadaturma);
        printf("fim.\n");

    return 0;
}
