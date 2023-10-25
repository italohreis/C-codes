#include <stdio.h>

#define RED_TEXT "\x1b[31m"
#define RESET_COLOR "\x1b[0m"

int main(void){

    //Uma empresa fará encomenda de uniformes para seus funcionários em suas 2 unidades.
    //Cada funcionário receberá 2 calças e 2 blusas de uniforme. 
    //A unidade 1 possui 2 setores e a unidade 2 possui 5 setores. Cada setor escolhe a cor da camiseta (branca, preta ou azul)
    //e o tecido da calça (tactel ou moletom).

    //Escreva um algoritmo que receba como entrada o número de funcionários de cada setor e as características do seu uniforme 
    //(cor da camiseta e tecido da calça).

    //Após as leituras, o algoritmo deve emitir um destes relatórios, de acordo com a escolha do usuário:
    //1- Total de funcionários da unidade (dado o número da unidade, 1 ou 2, mostre o total de funcionários da unidade)
    //2- Total de funcionários do setor (dado o número da unidade e do setor, mostre o total de funcionários deste setor)
    //3- Uniforme do setor (dado o número da unidade e do setor, mostre as características do uniforme deste setor)
    //4- Maior unidade (mostra a unidade que tem mais funcionários)
    //5- Total de encomendas (mostre as quantidades de peças que serão encomendadas: quantidade de camisetas brancas, de camisetas pretas,
    //de camisetas azuis, de calças de tactel e de calças de moletom).
    //Após a emissão de cada relatório, o programa deve perguntar se o usuário deseja emitir outro relatório ou se deseja finalizar o programa.


    int unidade, funcionario[2][5] = {{0}}, setor, camiseta[2][5] = {{0}}, tecido[2][5] = {{0}}, resp, numUnidade = 0, soma[2] = {0};
    int numSetor, cBranca = 0, cPreta = 0, cAzul = 0, cTactel = 0, cMoletom = 0;

    for(unidade = 0; unidade < 2; unidade++){
        printf("* UNIDADE %d *\n", unidade+1);
        
        for(setor = 0; setor < 5; setor++){
            if((unidade == 0) && (setor == 2)){
                break;               
            }

            printf("\n\t< Setor %d >\n", setor+1);
            printf("\tDigite a quantidade de funcionarios do setor --> "); 
            scanf(" %d", &funcionario[unidade][setor]);

            soma[unidade] += funcionario[unidade][setor];

            camiseta[unidade][setor] = -1;

            while(1){
                printf("\tInforme qual a cor da camiseta (1 para branca, 2 para preta ou 3 para azul) --> ");
                scanf("%d", &camiseta[unidade][setor]);

                if(camiseta[unidade][setor] == 1 || camiseta[unidade][setor] == 2 || camiseta[unidade][setor] == 3){
                    break;
                }
                else{
                    printf(RED_TEXT "\n\tResposta invalida, tente novamente.\n\n" RESET_COLOR);
                }

            }
      
            if(camiseta[unidade][setor] == 1){
                cBranca++;
            }
            else if(camiseta[unidade][setor] == 2){
                cPreta++;
            }
            else{
                cAzul++;
            }


            start:
            printf("\n");
            tecido[unidade][setor] = -1;

            while(tecido[unidade][setor] != 1 && tecido[unidade][setor] != 2){

                printf("\tInforme qual o tecido da calca (1 para tactel ou 2 para moletom) --> ");
                scanf("%d", &tecido[unidade][setor]);
                printf("\n");

                if(tecido[unidade][setor] != 1 && tecido[unidade][setor] != 2){
                    printf(RED_TEXT "\tResposta invalida, tente novamente.\n" RESET_COLOR);
                    goto start;
                }

                if(tecido[unidade][setor] == 1){
                    cTactel++;
                }
                else{
                    cMoletom++;
                }         
            }
        }
    }

    while(1){

        printf("\n\nO que deseja fazer?\n");
        printf(" 1 - Mostrar total de funcionarios da unidade.\n 2 - Mostrar total de funcionarios de um setor e unidade\n 3 - Mostrar uniforme de um setor e unidade.\n"
                " 4 - Mostrar unidade com mais funcionarios.\n 5 - total de encomendas.\n 6 - finalizar.\n");
        scanf("%d", &resp);
        
        switch(resp){

            case 1:
                printf("\nQual unidade deseja consultar? --> ");
                scanf("%d", &numUnidade);

                if(numUnidade > 2 || numUnidade < 1){
                    printf(RED_TEXT "\nUnidade inexistente, tente novamente.\n" RESET_COLOR);
                }
                else{
                printf("\nQuantidade de funcionarios da unidade %d -->  %d\n\n", numUnidade, soma[numUnidade-1]);
                }
                break;

            case 2: 
                printf("\nQual unidade ? --> ");
                scanf("%d", &numUnidade);

                if(numUnidade > 2 || numUnidade < 1){
                    printf(RED_TEXT "\nUnidade inexistente, tente novamente.\n" RESET_COLOR);
                    break;
                }

                printf("\nQual o numero do setor que deseja consultar? --> ");
                scanf("%d", &numSetor);
                
                if((numUnidade == 1) && (numSetor > 2 || numSetor < 1)){
                    printf(RED_TEXT "\nSetor inexistente, tente novamente.\n" RESET_COLOR);
                    break;
                }

                if((numUnidade == 2) && (numSetor > 5 || numSetor < 1)){
                    printf(RED_TEXT "\nSetor inexistente, tente novamente.\n" RESET_COLOR);
                    break;
                }

                printf("\nTotal de funcionarios do setor %d da unidade %d -->  %d\n\n", numSetor, numUnidade, funcionario[numUnidade-1][numSetor-1]);
                break;

            case 3:
                printf("\nQual unidade ? --> ");
                scanf("%d", &numUnidade);

                if(numUnidade > 2 || numUnidade < 1){
                    printf(RED_TEXT "\nUnidade inexistente, tente novamente.\n" RESET_COLOR);
                    break;
                }

                printf("\nQual setor deseja consultar o uniforme? --> ");
                scanf("%d", &numSetor);

                if((numUnidade == 1) && (numSetor > 2 || numSetor < 1)){
                    printf(RED_TEXT "\nSetor inexistente, tente novamente.\n" RESET_COLOR);
                    break;
                }

                if((numUnidade == 2) && (numSetor > 5 || numSetor < 1)){
                    printf(RED_TEXT "\nSetor inexistente, tente novamente.\n" RESET_COLOR);
                    break;
                }

                if(camiseta[numUnidade-1][numSetor-1] == 1){
                    printf("\nCor da camiseta -->  Branca.\n\n");
                }
                else if(camiseta[numUnidade-1][numSetor-1] == 2){
                    printf("\nCor da camiseta -->  Preta.\n\n");
                }
                else{
                    printf("\nCor da camiseta -->  Azul.\n\n");
                }

                if(tecido[numUnidade-1][numSetor-1] == 1){
                    printf("\nTecido da calca -->  Tactel.\n\n");
                }
                else{
                    printf("\nTecido da calca -->  Moletom.\n\n");
                }
                break;

            case 4:
                if(soma[0] > soma[1]){
                    printf("\nA unidade 1 possui mais funcionarios, com %d funcionarios.\n\n", soma[0]);
                }
                else if(soma[1] > soma[0]){
                    printf("\nA unidade 2 possui mais funcionarios, com %d funcionarios.\n\n", soma[1]);
                }
                else{
                    printf("\nAs duas unidades possuem a mesma quantidade de funcionarios.\n\n");
                }
                break;

            case 5: 
                printf("\nQuantidade de camisetas brancas encomendadas -->  %d\n", cBranca * 2);
                printf("\nQuantidade de camisetas pretas encomendadas -->  %d\n", cPreta * 2);
                printf("\nQuantidade de camisetas azuis encomendadas -->  %d\n", cAzul * 2);
                printf("\nQuantidade de calca tactel encomendadas -->  %d\n", cTactel * 2);
                printf("\nQuantidade de calca moletom encomendadas -->  %d\n\n", cMoletom * 2);
                break;
            
            case 6:
                printf("\n\nfim.\n\n");

            return 0;

            default:
                printf(RED_TEXT "\nOpcao invalida, tente novamente.\n" RESET_COLOR);
                break;
        }

    }

    return 0;

}