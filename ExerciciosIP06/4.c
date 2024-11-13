#include <stdio.h>
#define MAX 8

void exibe(int m[MAX][MAX]){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            printf("%s", m[i][j] ? "\xDB\xDB" : " ");
        }
        puts("");
    }
}
int main (){
    int m[MAX][MAX] = {
        {1,1,1,1,1,1,1,1},
        {0,0,1,0,0,0,0,1},
        {1,0,1,0,1,0,1,1},
        {1,0,1,0,1,0,0,1},
        {1,0,0,0,1,1,0,1},
        {1,0,1,0,0,1,0,1},
        {1,0,1,0,1,1,0,0},
        {1,1,1,1,1,1,1,1}
    };
    exibe(m);
    return 0;
}