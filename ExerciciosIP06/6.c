#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define MAX 15

void gotoxy(int x, int y){
    printf("\033[%d;%dH", y, x);
}
void mostra(char c, int i, int j) {
    gotoxy(2*j+i,i+1);
    printf("%c%c\b", c, c);
    sleep(1);
}
void limpar(int i, int j){
    gotoxy(2*j+i,i+1);
    printf("  ");
}
int sai(int m[MAX][MAX], int i, int j){
    m[i][j] = 2;
    mostra('\xB0',i,j);
    if(i == MAX -2 && j == MAX -1) return 1;
    if(m[i + 1][j] == 0  && sai(m, i + 1, j)) return 1;
    if(m[i][j+1] == 0 && sai (m,i,j + 1)) return 1;
    if(m[i - 1][j] == 0 && sai(m,i-1,j)) return 1;
    if(j>0 && m[i][j-1] == 0 && sai (m,i,j-1)) return 1;
    limpar(i,j);
    return 0;
}
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