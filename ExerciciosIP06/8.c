#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void clrscr() {
    printf("\033[H\033[J");
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

int vencedor(char m[SIZE][SIZE]) {
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

    srand(time(NULL));
    
    while (1) {
        exibe(m); 
        usuario(m); 
        exibe(m);
        if (vencedor(m) == 'X') {
            exibe(m);
            printf("\nVencedor: Jogador X!\n");
            break;
        }

        int cheio = 1;
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (m[i][j] == ' ') cheio = 0;

        if (cheio) {
            exibe(m);
            printf("\nEmpate!\n");
            break;
        }
    }

    return 0;
}