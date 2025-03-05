#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

// Posições com 0 é água
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++)
        for (int j = 0; j < TAMANHO; j++) 
			tabuleiro[i][j] = 0;
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++)
            printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }
}

int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char orientacao) {

    if ((orientacao == 'H' && coluna + tamanho > TAMANHO) || (orientacao == 'V' && linha + tamanho > TAMANHO))
        return 0;
    
    for (int i = 0; i < tamanho; i++) {
        int x = linha + (orientacao == 'V' ? i : 0);
        int y = coluna + (orientacao == 'H' ? i : 0);
        if (tabuleiro[x][y] != 0) return 0;
    }
    
    // Posiciona o navio (3) no tabuleiro
    for (int i = 0; i < tamanho; i++) {
        int x = linha + (orientacao == 'V' ? i : 0);
        int y = coluna + (orientacao == 'H' ? i : 0);
        tabuleiro[x][y] = NAVIO;
    }
    return 1;
}

int main() {
	
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    if (!posicionarNavio(tabuleiro, 1, 1, 3, 'H'))
        printf("Erro ao posicionar o navio horizontal!\n");
    if (!posicionarNavio(tabuleiro, 6, 4, 3, 'V'))
        printf("Erro ao posicionar o navio vertical!\n");

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval em C | Fernando Lucas:\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
