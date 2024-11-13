#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15

void gera(int m[MAX][MAX]){
    int i, j;
    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            m[i][j] = 0;
        }
    }
    for (int i = 0; i < MAX; i++){
        m[0][i] = 1;
        m[MAX - 1][i] = 1;
        m[i][0] = 1;
        m[i][MAX - 1] = 1;
    }
    m[1][0] = 0;
    m[MAX - 2][MAX - 1] = 0;

    int centerX, centerY;
    do {
        centerX = rand() % MAX;
        centerY = rand() % MAX;
    } while ((centerX == 1 && centerY == 0) || (centerX == 1 && centerY == 0));
    
    int count = 0;
    while (count < 56){
        int i = rand() % MAX;
        int j = rand() % MAX;

        if(m[i][j] == 0 && !(i == 1 && j == 0) && !(i == centerX && j == centerY)){
            m[i][j] = 1;
            count++;
        }
    }
}
void exibe(int m[MAX][MAX]){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            printf("%s", m[i][j] ? "\xDB\xDB" : "  ");
        }
        puts("");
    }
}

int main(){
    int m[MAX][MAX];
    srand(time(NULL));
    gera(m);
    exibe(m);
    return 0;
}