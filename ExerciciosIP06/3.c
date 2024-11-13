#include <stdio.h>

void preencher(float v[]) {
    for (int i = 0; i < 7; i++) {
        printf("Digite o valor do dia %d (0 a 50): ", i + 1);
        scanf("%f", &v[i]);
        // Validação da temperatura
        while (v[i] < 0 || v[i] > 50) {
            printf("Temperatura inválida. Digite novamente (0 a 50): ");
            scanf("%f", &v[i]);
        }
    }
}

float media(float v[]) {
    float soma = 0;
    for (int i = 0; i < 7; i++) {
        soma += v[i];
    }
    return soma / 7;
}

void histograma(float v[], float m) {
    char caracteres = '\xDB';
    printf("Histograma:\n");
    
    for (int i = 0; i < 7; i++) {
        if (v[i] < m) {
            printf("\033[34m"); // Azul
        } else if (v[i] > m) {
            printf("\033[31m"); // Vermelho
        } else {
            printf("\033[32m"); // Verde
        }

        printf("Dia %d: ", i + 1);
        for (int j = 0; j < (int)v[i]; j++) {
            printf("%c", caracteres);
        }
        printf(" (%.1f°C)\n", v[i]);
        
        // Resetar a cor
        printf("\033[0m");
    }
}

int main() {
    float v[7];
    preencher(v);
    float m = media(v);
    printf("Média da temperatura: %.1f°C\n", m);
    histograma(v, m);
    return 0;
}