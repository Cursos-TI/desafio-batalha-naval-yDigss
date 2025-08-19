#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define NAVIO_TAM 3
#define HSIZE 5
#define EFEITO 5

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[HSIZE][HSIZE], int origemLinha, int origemColuna);
void inicializarTabuleiro(int tabuleiro[TAM][TAM]);
void exibirTabuleiro(int tabuleiro[TAM][TAM]);

int main() {
    int tabuleiro[TAM][TAM];

    // Matrizes de habilidade
    int cone[HSIZE][HSIZE];
    int cruz[HSIZE][HSIZE];
    int octaedro[HSIZE][HSIZE];

    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (j >= HSIZE/2 - i && j <= HSIZE/2 + i) { cone[i][j] = 1; } else { cone[i][j] = 0; }
        }
    }
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if(i == HSIZE/2 || j == HSIZE/2) { cruz[i][j] = 1; } else { cruz[i][j] = 0; }
        }
    }
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if(abs(i - HSIZE/2) + abs(j - HSIZE/2) <= HSIZE/2) { octaedro[i][j] = 1; } else { octaedro[i][j] = 0; }
        }
    }

    printf("--- Tabuleiro Original ---\n");
    inicializarTabuleiro(tabuleiro);
    exibirTabuleiro(tabuleiro);

    printf("\n\n--- Aplicando Habilidade: CONE na posicao (1, 4) ---\n");
    aplicarHabilidade(tabuleiro, cone, 1, 4);
    exibirTabuleiro(tabuleiro);

    printf("\n\n--- Aplicando Habilidade: CRUZ na posicao (5, 5) ---\n");
    inicializarTabuleiro(tabuleiro);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    exibirTabuleiro(tabuleiro);

    printf("\n\n--- Aplicando Habilidade: OCTAEDRO na posicao (7, 2) ---\n");
    inicializarTabuleiro(tabuleiro);
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);
    exibirTabuleiro(tabuleiro);

    return 0;
}

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            tabuleiro[i][j] = 0;
        }
    }
    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;
    int linhaD1 = 4, colunaD1 = 4;
    int linhaD2 = 7, colunaD2 = 9;
    if(colunaH + NAVIO_TAM <= TAM){ for(int i = 0; i < NAVIO_TAM; i++){ tabuleiro[linhaH][colunaH + i] = 3; } }
    if(linhaV + NAVIO_TAM <= TAM){ for(int i = 0; i < NAVIO_TAM; i++){ tabuleiro[linhaV + i][colunaV] = 3; } }
    if(linhaD1 + NAVIO_TAM <= TAM && colunaD1 + NAVIO_TAM <= TAM){ for (int i = 0; i < NAVIO_TAM; i++){ tabuleiro[linhaD1 + i][colunaD1 + i] = 3; } }
    if(linhaD2 + NAVIO_TAM <= TAM && colunaD2 - NAVIO_TAM >= -1){ for (int i = 0; i < NAVIO_TAM; i++){ if (linhaD2 + i < TAM) { tabuleiro[linhaD2 + i][colunaD2 - i] = 3; } } }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    char coluna[10] = {'A','B','C','D','E','F','G','H','I','J'};
    printf("   ");
    for(int j = 0; j < TAM; j++){
        printf(" %c", coluna[j]);
    }
    printf("\n");

    for(int i = 0; i < TAM; i++){
        printf("%2d ", i);
        for(int j = 0; j < TAM; j++){
            switch(tabuleiro[i][j]) {
                case 0:
                    printf(" 0");
                    break;
                case 3:
                    printf(" N");
                    break;
                case EFEITO:
                    printf(" *");
                    break;
                default:
                    printf(" ?");
            }
        }
        printf("\n");
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[HSIZE][HSIZE], int origemLinha, int origemColuna) {
    int centroHabilidade = HSIZE / 2;
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaNoTabuleiro = origemLinha + i - centroHabilidade;
                int colunaNoTabuleiro = origemColuna + j - centroHabilidade;
                if (linhaNoTabuleiro >= 0 && linhaNoTabuleiro < TAM && colunaNoTabuleiro >= 0 && colunaNoTabuleiro < TAM) {
                    tabuleiro[linhaNoTabuleiro][colunaNoTabuleiro] = EFEITO;
                }
            }
        }
    }
}
