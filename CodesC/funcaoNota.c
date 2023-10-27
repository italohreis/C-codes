 #include <stdio.h>
 #include <stdbool.h>

#define red_text  "\x1b[31m"
#define green_text  "\x1b[32m"
#define orange_text  "\x1b[33m"
#define reset_color "\x1b[0m"

#define nAulas 40

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
    notasBimestre notaBimestral[4];
    float notaFinal;
    int presenca;
    float porcentagemPresenca;
} Aluno;
Aluno Alunos[20];

    bool aluno_existente[20] = {false};     // vetor para verificar se o aluno ja foi cadastrado


    float CalcularPresenca(int numAluno);   // prototipo da funcao CalcularPresenca
    void StatusAluno(int numAluno);         // prototipo da funcao StatusAluno

    
 int main(){

    printf("\n");

    int keep;
    do{
        int aluno;
        printf("\nInsira o numero do aluno --> ");
        scanf("%d", &aluno);

        if(aluno_existente[aluno] == true){
            printf(red_text "\nAluno ja cadastrado, tente novamente.\n" reset_color);
            continue;       // volta para o inicio do loop
        }

        aluno_existente[aluno] = true;

        printf("\n\nAluno %d", aluno);
        printf("\n");

        for(int i=0; i<4; i++){
            printf("\n");
            Alunos[aluno].notaBimestral[i].prova = -1;

            while(Alunos[aluno].notaBimestral[i].prova < 0 || Alunos[aluno].notaBimestral[i].prova > 10){
                printf("\tInsira a nota da prova %d --> ", i+1);
                scanf("%f", &Alunos[aluno].notaBimestral[i].prova);

                if(Alunos[aluno].notaBimestral[i].prova < 0 || Alunos[aluno].notaBimestral[i].prova > 10){
                    printf(red_text "\n\tNota invalida, tente novamente.\n" reset_color);
                }
            }

            Alunos[aluno].notaBimestral[i].trabalho = -1;
            while(Alunos[aluno].notaBimestral[i].trabalho < 0 || Alunos[aluno].notaBimestral[i].trabalho > 10){
                printf("\tInsira a nota do trabalho %d --> ", i+1);
                scanf("%f", &Alunos[aluno].notaBimestral[i].trabalho);

                if(Alunos[aluno].notaBimestral[i].trabalho < 0 || Alunos[aluno].notaBimestral[i].trabalho > 10){
                    printf(red_text "\n\tNota invalida, tente novamente.\n" reset_color);
                }
            }

                Alunos[aluno].notaBimestral[i].notaFinalBimestral = (((Alunos[aluno].notaBimestral[i].prova * 6) + (Alunos[aluno].notaBimestral[i].trabalho * 4)) / 10);
                Alunos[aluno].notaFinal += Alunos[aluno].notaBimestral[i].notaFinalBimestral;
            
        }
                Alunos[aluno].notaFinal = Alunos[aluno].notaFinal / 4;
        
        CalcularPresenca(aluno);
    
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
        printf("\n\nQual aluno deseja consultar ? (Caso queira finalizar digite -1) --> ");
        int numAluno;
        scanf("%d", &numAluno);

        if(numAluno == -1){
            printf("\n\nfim.\n\n");
            return 0;
        }

        if(aluno_existente[numAluno] == false){
            printf(red_text "\nAluno nao cadastrado, tente novamente.\n" reset_color);
            continue;
        }


        StatusAluno(numAluno);

    }
    
    printf("\n\nfim.\n\n");
    return 0;

 }


 

float CalcularPresenca(int numAluno){

    do{
        printf("\n\tDigite o numero de presenca do aluno --> ");
        scanf("%d", &Alunos[numAluno].presenca);

        if(Alunos[numAluno].presenca > nAulas){
            printf(red_text "\n\tNumero de presenca maior que o numero de aulas, tente novamente.\n" reset_color);
        }

    }while(Alunos[numAluno].presenca > nAulas);


    Alunos[numAluno].porcentagemPresenca = ((float)Alunos[numAluno].presenca / nAulas) * 100;

    return Alunos[numAluno].porcentagemPresenca;
}



 
void StatusAluno(int numAluno){
    int j;
    for(j = 0; j < 4; j++){
        printf("\n\tNota bimestral %d --> %.2f\n", j + 1, Alunos[numAluno].notaBimestral[j].notaFinalBimestral);

    }
    printf("\n\tNota final --> %.2f\n", Alunos[numAluno].notaFinal);
            

    if(Alunos[numAluno].porcentagemPresenca < 75){
        printf(red_text "\n\tReprovado por falta\n" reset_color);
        return;         
    }
        
    else{
            
        if(Alunos[numAluno].notaFinal >= 7){   
                
            printf(green_text"\n\tAprovado\n"reset_color);       
            
        } else if(Alunos[numAluno].notaFinal < 5){
                
            printf(red_text "\n\tReprovado por nota\n" reset_color);
            
        } else{
                
            printf(orange_text "\n\tFara recuperacao\n" reset_color);
            
        }
    }
}