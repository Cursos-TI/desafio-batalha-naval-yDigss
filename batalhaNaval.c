#include <stdio.h>
#define TAM 10
#define NAVIO 3

int main() {
    char coluna[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[TAM][TAM];

    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            tabuleiro[i][j] = 0;
        }
    }

    int barcoH[NAVIO] = {3, 3, 3};
    int barcoV[NAVIO] = {3, 3, 3};

    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;

    if(colunaH + NAVIO <= TAM){
        for(int i = 0; i < NAVIO; i++){
            if(tabuleiro[linhaH][colunaH + i] == 0){
                tabuleiro[linhaH][colunaH + i] = barcoH[i];
            } else{
                printf("Erro: Sobreposicao detectada no barco horizontal! \n");
            }
        }
    } else{
        printf("Erro: Barco horizontal fora do tabuleiro");
    }

    if(linhaV + NAVIO <= TAM){  
    for(int i = 0; i < NAVIO; i++){
        if(tabuleiro[linhaV + i][colunaV] == 0){
            tabuleiro[linhaV + i][colunaV] = barcoV[i];
        } else{
            printf("Erro: Sobreposicao detectada no barco vertical!\n");
        }
    }
    } else{
    printf("Erro: Barco vertical fora do tabuleiro\n");
    }


    printf("  ");
    for(int j = 0; j < TAM; j++){
        printf("%2c", coluna[j]);
    }

    printf("\n");

    for(int i = 0; i < TAM; i++){
        printf("%2d ", i);
        for(int j = 0; j < TAM; j++){
            printf("%2d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
