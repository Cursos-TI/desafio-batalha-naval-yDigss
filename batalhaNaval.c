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
    int barcoD1[NAVIO] = {3, 3, 3};
    int barcoD2[NAVIO] = {3, 3, 3};

    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;
    int linhaD1 = 4, colunaD1 = 4;
    int linhaD2 = 7, colunaD2 = 9;

    // navio horizontal
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

    // navio vertical
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

    // navio Diagonal 1
    if(linhaD1 + NAVIO <= TAM && colunaD1 + NAVIO <= TAM){
        for (int i = 0; i < NAVIO; i++)
        {
            if(tabuleiro[linhaD1 + i] [colunaD1 + i] == 0){
                tabuleiro[linhaD1 + i] [colunaD1 + i] = barcoD1[i];
            } else{
                printf("Erro: Sobreposicao encontrada no barco Diagonal!\n");
            }
        }        
    } else{
        printf("Erro: Barco Diagonal fora do tabuleiro!\n");
    }

    // navio Diagonal 2
    if(linhaD2 + NAVIO <= TAM && colunaD2 - NAVIO >= -1){
        for (int i = 0; i < NAVIO; i++)
        {
            if(tabuleiro[linhaD2 + i] [colunaD2 - i] == 0){
                tabuleiro[linhaD2 + i] [colunaD2 - i] = barcoD2[i];
            } else{
                printf("Erro: Sobreposicao encontrada no barco diagonal 2!\n");
            }
        }
        
    } else{
        printf("Erro: Barco Diagonal 2 fora do tabuleiro!\n");
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
