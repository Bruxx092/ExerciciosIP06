#include <stdio.h>

void binario(int n){
    int v[10];
    for (int i = 0; i < 10; i++){
        v[i] = n % 2;
        n = n / 2;
    }
    int firstOneFound = 0;
    for(int i = 9; i >= 0; i--){
        if(v[i] == 1){
            firstOneFound = 1;
        }
        if(firstOneFound){
            printf("%d", v[i]);
        }
    }
    if (!firstOneFound){
        printf("0");
    }
}
int main(){
    int n;
    printf("Numero até 1000 que deseja converter para binário? ");
    scanf("%d", &n);
    binario(n);
    return 0;
}