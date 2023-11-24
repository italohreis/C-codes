#include <stdio.h>

// Série de Fibonacci com estrutura de repetição

void fibonacci(int valor);

int main() {
    int valor;

    printf("\nDigite a série de Fibonacci --> ");
    scanf("%d", &valor);

    fibonacci(valor);

    return 0;
}

void fibonacci(int valor) {
    int primeiro = 0, segundo = 1, proximo;

    printf("Série de Fibonacci até o %dº termo: ", valor);

    for (int i = 0; i < valor; i++) {
        if (i <= 1) {
            proximo = i;
        } else {
            proximo = primeiro + segundo;
            primeiro = segundo;
            segundo = proximo;
        }
        printf("%d ", proximo);
    }
    printf("\n");
}
