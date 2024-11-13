#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> 
#include <windows.h> 

#define SIZE 3

void clrscr() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void exibe(char m[SIZE][SIZE]) {
    clrscr();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", m[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
}

void usuario(char m[SIZE][SIZE]) {
    int i, j;
    do {
        printf("\nJogador, digite as coordenadas da jogada (linha e coluna): ");
        scanf("%d %d", &i, &j);
        i--; j--; 
    } while (i < 0 || i >= SIZE || j < 0 || j >= SIZE || m[i][j] != ' ');
    m[i][j] = 'X';
}

void computador(char m[SIZE][SIZE]) {
    int i, j;
    do {
        i = rand() % SIZE; 
        j = rand() % SIZE; 
    } while (m[i][j] != ' '); 
    m[i][j] = 'O'; 
}

char vencedor(char m[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (m[i][0] == m[i][1] && m[i][1] == m[i][2] && m[i][0] != ' ')
            return m[i][0];
        if (m[0][i] == m[1][i] && m[1][i] == m[2][i] && m[0][i] != ' ')
            return m[0][i];
    }
    // Verifica diagonais
    if (m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[0][0] != ' ')
        return m[0][0];
    if (m[0][2] == m[1][1] && m[1][1] == m[2][0] && m[0][2] != ' ')
        return m[0][2];

    return ' ';
}

int main() {
    char m[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int j = 0, e, s;
    char v;
    printf("Par (0) ou ímpar (1)? ");
    scanf("%d", &e);
    srand(time(NULL));
    s = rand() % 2;
    printf("Sorteado: %d\n", s);
    if (e == s) {
        puts("Você começa!");
    } else {
        puts("Eu começo!");
    }
    printf("Pressione enter...");
    _getch(); 
    do {
        exibe(m);
        if (e == s) {
            usuario(m);
        } else {
            computador(m);
        }
        v = vencedor(m);
        s = !s;
    } while (++j < 9 && v == ' ');
    
    exibe(m);
    switch (v) {
        case ' ': puts("\nEmpate!\n"); break;
        case 'X': puts("\nVocê venceu!\n"); break;
        case 'O': puts("\nEu venci!\n"); break;
    }
    
    return 0;
}