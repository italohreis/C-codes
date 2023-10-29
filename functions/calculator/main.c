#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "functions.h"


#define red_text "\x1b[31m"
#define reset_color "\x1b[0m"
#define green_text "\x1b[32m"



int main(void){
    printf(reset_color);

    setlocale(LC_ALL, "Portuguese");

    int resp;
    float num1, num2;

    float base;
    float expoente;

    float multpl1, multpl2;

    float numero;

    while(1){
        printf("\n\nO que deseja fazer ?\n\n");
        printf(" 1 - Adi��o.\n 2 - Subtra��o.\n 3 - Divis�o.\n 4 - Multiplica��o.\n 5 - Potencia��o.\n 6 - Raiz Quadrada.\n 7 - Finalizar.\n");
        scanf("%d", &resp);

        printf("\n");

        switch(resp){

            case 1:
                printf("\n\tDigite os n�meros que deseja somar:\n");
                printf("\n\tNumero 1 --> ");
                scanf("%f", &num1);
                
                printf("\n\tNumero 2 --> ");
                scanf("%f", &num2);

                float ResultadoSoma;
                ResultadoSoma = CalcAdicao(num1, num2);

                printf(green_text "\n\n\tResultado da soma %.1f + %.1f =  %.1f.\n" reset_color, num1, num2, ResultadoSoma);
                break;

            case 2:
                printf("\n\tDigite os n�meros que deseja subtrair:\n");

                float numero1, numero2;

                printf("\n\tNumero 1 --> ");
                scanf("%f", &numero1);

                printf("\n\tNumero 2 --> ");
                scanf("%f", &numero2);

                float ResultadoSubtracao;
                ResultadoSubtracao = CalcSubtracao(numero1, numero2);

                printf(green_text "\n\n\tResultado da subtra��o %.1f - %.1f =  %.1f\n" reset_color, numero1, numero2, ResultadoSubtracao );
                break;

            case 3:
                printf("\n\tDigite os n�meros que deseja dividir:\n");

                float div1, div2;

                printf("\n\tNumero 1 --> ");
                scanf("%f", &div1);

                printf("\n\tNumero 2 --> ");
                scanf("%f", &div2);

                float ResultadoDivisao;
                ResultadoDivisao = CalcDivisao(div1, div2);

                printf(green_text"\n\n\tResultado da divis�o %.1f / %.1f =  %.1f\n" reset_color, div1, div2, ResultadoDivisao);
                break;

            case 4:

                printf("\n\tDigite os n�meros que deseja multiplicar:\n");

                printf("\n\tNumero 1 --> ");
                scanf("%f", &multpl1);

                printf("\n\tNumero 2 --> ");
                scanf("%f", &multpl2);

                float ResultadoMultiplicacao;
                ResultadoMultiplicacao = CalcMultiplicacao(multpl1, multpl2);

                printf(green_text "\n\n\tResultado da multiplica��o %.1f * %.1f =  %.1f\n" reset_color, multpl1, multpl2, ResultadoMultiplicacao);
                break;

            case 5:

                printf("\n\tDigite a base --> ");
                scanf("%f", &base);

                printf("\n\tDigite o expoente --> ");
                scanf("%f", &expoente);

                float ResultadoPotencia;

                ResultadoPotencia = CalcPotencia(base, expoente);
        
                printf(green_text "\n\n\tResultado de %.1f elevado a %.1f =  %.0f" reset_color, base, expoente, ResultadoPotencia);
                break;

            case 6:
                printf("\n\tDigite o n�mero que deseja calcular a raiz quadrada --> ");
                scanf("%f", &numero);

                float ResultadoRadiciacao;

                ResultadoRadiciacao = CalcRadiciacao(numero);

                printf(green_text "\n\n\tResultado da raiz quadrada de %.1f =  %.2f" reset_color, numero, ResultadoRadiciacao);
                break;

            case 7:
                printf("\n\nFim.\n\n");
                return 0;

            default:
                printf(red_text "\nResposta inv�lida, tente novamente.\n" reset_color);
                break;

        }


    }




}



