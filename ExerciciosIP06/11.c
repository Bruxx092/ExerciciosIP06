#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> 

#define SIZE 3

void clrscr() {
    system("cls");
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

int completa(char m[SIZE][SIZE], char c) {
    // Verificar linhas
    for (int i = 0; i < SIZE; i++) {
        if (m[i][0] == c && m[i][1] == c && m[i][2] == ' ') {
            m[i][2] = 'O';
            return 1;
        }
        if (m[i][0] == c && m[i][2] == c && m[i][1] == ' ') {
            m[i][1] = 'O';
            return 1;
        }
        if (m[i][1] == c && m[i][2] == c && m[i][0] == ' ') {
            m[i][0] = 'O';
            return 1;
        }
    }

    // Verificar colunas
    for (int j = 0; j < SIZE; j++) {
        if (m[0][j] == c && m[1][j] == c && m[2][j] == ' ') {
            m[2][j] = 'O';
            return 1;
        }
        if (m[0][j] == c && m[2][j] == c && m[1][j] == ' ') {
            m[1][j] = 'O';
            return 1;
        }
        if (m[1][j] == c && m[2][j] == c && m[0][j] == ' ') {
            m[0][j] = 'O';
            return 1;
        }
    }

    // Verificar diagonais
    if (m[0][0] == c && m[1][1] == c && m[2][2] == ' ') {
        m[2][2] = 'O';
        return 1;
    }
    if (m[0][0] == c && m[2][2] == c && m[1][1] == ' ') {
        m[1][1] = 'O';
        return 1;
    }
    if (m[1][1] == c && m[2][2] == c && m[0][0] == ' ') {
        m[0][0] = 'O';
        return 1;
    }
    if (m[0][2] == c && m[1][1] == c && m[2][0] == ' ') {
        m[2][0] = 'O';
        return 1;
    }
    if (m[0][2] == c && m[2][0] == c && m[1][1] == ' ') {
        m[1][1] = 'O';
        return 1;
    }
    if (m[1][1] == c && m[2][0] == c && m[0][2] == ' ') {
        m[0][2] = 'O';
        return 1;
    }

    return 0;
}

// Função computador aprimorada com ataque e defesa
void computador(char m[SIZE][SIZE]) {
    // Tenta atacar
    if (completa(m, 'O')) return;

    // Tenta defender
    if (completa(m, 'X')) return;

    // Se não conseguiu atacar nem defender, joga aleatoriamente
    int i, j;
    do {
        i = rand() % SIZE;
        j = rand() % SIZE;
    } while (m[i][j] != ' ');
    m[i][j] = 'O';
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
    int j = 0, e, s;
    char v;
    printf ("par (0) ou impar (1) ? ");
    scanf("%d", &e);
    srand(time(NULL));
    s = rand() % 2;
    printf("Sorteado: %d\n", s);
    if (e == s){
        puts("Voce comeca!");
    } else {
        puts ("Eu comeco!");
    }
    printf("Pressione enter...");
    _getch(); 
    do{
        exibe(m);
        if (e == s){
            usuario(m);
        } else {
            computador(m);
        }
        v = vencedor(m);
        s = !s;
    } while (++j <9 && v == ' ');
    exibe(m);
    switch(v){
        case ' ': puts("\nEmpate!\n"); break;
        case 'X': puts("\nVoce venceu!\n"); break;
        case 'O': puts("\nEu venci!\n"); break;
    }

    return 0;
}