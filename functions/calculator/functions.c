#include <math.h>



float CalcAdicao(float num1, float num2){
    float soma;
    soma = (num1 + num2);

    return soma;
}


float CalcSubtracao(float num1, float num2){
    float subtracao;

    subtracao = num1 - num2;

    return subtracao;
}


float CalcDivisao(float num1, float num2){
    float divisao;

    divisao = num1 / num2;

    return divisao;
}


float CalcMultiplicacao(float num1, float num2){
    float multiplicacao;

    multiplicacao = num1 * num2;

    return multiplicacao;
}


float CalcPotencia(float num1, float num2){
    float potencia;

    potencia = pow(num1, num2);

    return potencia;

}

float CalcRadiciacao(float num){
    float radiciacao;

    radiciacao = sqrt(num);

    return radiciacao;

}