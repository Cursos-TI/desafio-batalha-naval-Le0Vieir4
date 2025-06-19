#include <stdio.h>
int tabuleiro[10][10] = {0}; // inicia a matriz 10 x 10.
int error = 0; // variavel pra controle e gerenciamento de error.

// Novato
void desenharLinha() {
    int centro = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int coluna = j;
            int linha = centro;
            if(linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10) {
                printf("Posição invalida!");
                printf("\n");
                error = 1;
                break;
            }
            tabuleiro[linha][coluna] = 3;
        }
        if(error) break;
    }
}

void desenharColuna() {
    int centro = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 1; j++) {
            int coluna = centro ;
            int linha = i ;
            if(linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10) {
                printf("Posição invalida!");
                printf("\n");
                error = 1;
                break;
            }
            tabuleiro[linha][coluna] = 3;
        }
        if(error) break;
    }
}

// Aventureiro
void desenharDiagonal() {
    // Diagonal para esquerda
    for(int i = 0; i < 3; i++) {
        int centro = 0;
        for(int j = 0; j < 3; j++) {
            int coluna = centro + j;
            int linha = j + 1;
            if(linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10) {
                printf("Posição invalida!");
                printf("\n");
                error = 1;
                break;
            }
            tabuleiro[linha][coluna] = 3;
        }
        if(error) break;
    }

    // Diagonal para direita
    for(int i = 0; i < 3; i++) {
       int centro = 3; // controla em qual coluna ficara o centro do navio;
        for(int j = -1; j <= 1; j++) {
            int coluna = centro - j;
            int linha = j + 1; // controla a linha onde começará o navio.
            // if para controlar as bordar do tabuleiro, caso o valor ultrapasse as bordar será retornado um erro.
            if(linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10) {
                printf("Posição invalida!");
                printf("\n");
                error = 1;
                break;
            }
            tabuleiro[linha][coluna] = 3; // atualiza o tabuleiro com o navio marcado.
        }
        if(error) break;
    }
    
}

// Mestre
void desenharCone() {
    int centro = 7; // controla a coluna baseado no centro.
    for(int i = 0; i < 3; i++) {
        for(int j = -i; j <= i; j++) {
            int coluna = centro + j;
            int linha = i; // controla a linha de inicio.
            // verifica se o elemento esta dentro do tabuleiro, se não estiver, dispara um error e encerra o loop interno.
            if(linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10 || centro < 2 || centro > 7 ) {
                printf("Posição invalida!");
                printf("\n");
                error = 1;
                break;
            }
            tabuleiro[linha][coluna] = 3;
        }
        if(error) break; // encerra o loop externo em caso de erro.
    }
}

void desenharOcta() {
    int centro = 1;
    for(int i = 0; i < 3; i++) {
        for(int j = -i; j <= i; j++) {
            int coluna = centro + j;
            int linha = i ;
            if(linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10 || centro < 2 || centro > 7 ) {
                printf("Posição invalida!");
                printf("\n");
                error = 1;
                break;
            }
            tabuleiro[linha][coluna] = 2;
            tabuleiro[4 - linha][coluna] = 2;
        }
        if(error) break;
    }
}

void desenharCruz() {
    int centro = 0;
    for(int i = 0; i < 3; i++) {
        int linha = centro + 2;
        int coluna = centro + 2;
        for(int j = 0; j < 3; j++){
            if(linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10) {
                printf("Posição invalida!");
                printf("\n");
                error = 1;
                break;
            }
            tabuleiro[linha][coluna] = 1; // exibe o valor 1 no centro da cruz.
            tabuleiro[linha - 1][coluna] = 1; // valor 1 acima do centro.
            tabuleiro[linha + 1][coluna] = 1; // valor 1 abaixo do centro.
            tabuleiro[linha][coluna - 1] = 1; // valor 1 a esquerda do centro.
            tabuleiro[linha][coluna + 1] = 1; // valor 1 a direita do centro.
        }
        if(error) break;
    }
}

void desenharTabuleiro() {
    char letras[1][10]; // Uma linha, quatro colunas

    printf("    ");
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            letras[0][j] = 'A'; // inicializa a matriz com o valor 'A'.
        }
    }
    for(int j = 0; j < 10; j++) {
        letras[0][j] = 'A' + j; // atualiza o valor da matriz. 
        if(j < 10) {
            printf(" %c", letras[0][j]); // printa a matriz com o valo atualizado.
        }
    }

    printf("\n");

    for(int i = 0; i < 10; i++) {
        printf(" ");
        printf("%d | ", i );
        
        for(int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Desafio Novato
    desenharLinha();
    desenharColuna();
    
    // Desafio Aventureiro
    desenharDiagonal();
    
    // Desafio Mestre
    desenharCone();
    desenharOcta();
    desenharCruz();

    desenharTabuleiro();
    printf("\n");    
    return 0;
}
