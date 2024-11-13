#include <stdio.h>

void preencher(float v[]){
    for(int i = 0; i < 7; i++){
        printf("Digite o valor do dia %d: ", i + 1);
        scanf("%f", &v[i]);
    }
}

float media(float v[]){
    float soma = 0;
    for(int i = 0; i < 7; i++){
        soma += v[i];
    }
    return soma / 7;
}

int conta(float v[], float m){
    int count = 0;
    for(int i = 0; i < 7; i++){
        if(v[i] > m){
            count++;
        }
    }
    return count;
}
int main(){
    float v[7];
    preencher(v);
    float m = media(v);
    printf("Media: %.1f %cC\n", m, 248);
    printf("Dias acima da media: %d\n", conta(v,m));
    return 0;
}