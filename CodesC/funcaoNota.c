 #include <stdio.h>

#define red_text  "\x1b[31m"
#define reset_color "\x1b[0m"

    /* Faça um programa que informe as 4 notas bimestrais de um aluno, sua nota final e se este aluno foi aprovado, reprovado ou fará recuperação. 
    Considere que cada nota bimestral é composta por uma prova com peso 6 e um trabalho com peso 4, que serão recebidas como entrada. 
    A nota final é a média aritmética das 4 notas bimestrais. O aluno que não alcançar 75% de presenças, será reprovado. 
    Para ser aprovado, além da frequência mínima, o aluno deve ter nota final no mínimo 7,0.
    O aluno que alcançou a frequência mínima e a nota final está entre 5,0 e 7,0 tem o direito de fazer a recuperação.

    Dividir em subproblemas:

    - Calcular nota do 1° bimestre

    - Calcular nota do 2° bimestre

    - Calcular nota do 3° bimestre

    - Calcular nota do 4° bimestre

    - Calcular nota final

    - Calcular porcentagem de presenças

    - Verificar o status do aluno

    Fazer o mesmo procedimento para outros alunos, caso o usuário solicite.  */

typedef struct {
    float prova;
    float trabalho;
    float notaFinalBimestral;
} notasBimestre;

typedef struct{
    notasBimestre notaBimestral[5];
    float notaFinal;
    float presenca;
} Aluno;
Aluno Alunos[100];

 int main(){

    printf("\n");

    int keep;
do{
    int aluno;
    printf("Insira o numero do aluno --> ");
    scanf("%d", &aluno);

    printf("\n\nAluno %d", aluno);
    printf("\n");
        for(int i=0; i<4; i++){
            printf("\n");
            printf("Insira a nota da prova %d --> ", i+1);
            scanf("%f", &Alunos[aluno].notaBimestral[i+1].prova);
                
            printf("Insira a nota do trabalho %d --> ", i+1);
            scanf("%f", &Alunos[aluno].notaBimestral[i+1].trabalho);
            
                Alunos[aluno].notaBimestral[i+1].notaFinalBimestral = (((Alunos[aluno].notaBimestral[i+1].prova * 6) + (Alunos[aluno].notaBimestral[i+1].trabalho * 4)) / 10);
                Alunos[aluno].notaFinal += Alunos[aluno].notaBimestral[i+1].notaFinalBimestral;
        }

    Alunos[aluno].notaFinal = Alunos[aluno].notaFinal / 4;
        
    printf("\nInsira a porcentagem de presenca dele:\n");
    scanf("%f", &Alunos[aluno].presenca);
    
    keep = -1;
    while(keep != 0 && keep != 1){
        printf("\n\nDeseja ler outro aluno ? (1 - Sim / 0 - Nao) --> ");
        scanf("%d", & keep);

        if(keep != 0 && keep != 1){
            printf(red_text "\nResposta invalida, tente novamente.\n" reset_color);
        }
    }
    
    }while(keep == 1);
        //consultar notas.
        while(1){
        printf("Qual aluno deseja consultar ? (Caso queira finalizar digite -1) --> ");
        int numAluno;
        scanf("%d", &numAluno);

        if(numAluno == -1){
            printf("\n\nfim.\n\n");
            return 0;
        }

        printf("\nAluno %d\n", numAluno);
        
        int j;
        for(j = 1; j <= 4; j++){
            printf("Nota bimestral %d --> %.2f\n", j, Alunos[numAluno].notaBimestral[j].notaFinalBimestral);

        }
        printf("Nota final --> %.2f\n", Alunos[numAluno].notaFinal);
        
        if(Alunos[numAluno].presenca < 75){
            printf("Reprovado por faltas.\n");
        }

        if(Alunos[numAluno].notaFinal >= 7){
            printf("\nAprovado.\n");    

        } else if(Alunos[numAluno].notaFinal < 5){
            printf("\nReprovado por nota.\n");

        } else{
            printf("\nFara Recuperacao.\n");
        }
    }
    printf("\n\nfim.\n\n");
    return 0;
 }