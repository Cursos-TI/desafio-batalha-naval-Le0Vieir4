#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[10][10] = {0};
    int x = 4;
    int y = 7;
    int i, j;
    char letras[1][10]; // Uma linha, quatro colunas
    int col = 0;
    
    // Definicão do index das colunas.
    printf("  ");
    for (i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            letras[0][j] = 'A'; // inicializa a matriz com o valor 'A'.
        }
    }
    for(int j = 0; j < 10; j++) {
        letras[0][j] = 'A' + j; // atualiza o valor da matriz. 
        if(j < 10) {
            printf(" %c", letras[0][j]); // printa a matriz com o valo atualizado.
        }
    }
    
    for( i = 0; i < 10; i++) {
        printf("\n%d", i + 1); // define o index da linha.
        if(i < 9) {
            printf(" "); // adiciona um espaço a mais nas linhas( excluindo a décima linha ). Para organização do mapa.  
        } 
        // controla em qual coluna ira começar e terminar, tambem define o tamanho do navio.
        for(j = 2; j < 5; j++) {
            tabuleiro[x][j] = 3; //define como o navio deve ser visualizado.
        }
        // controla em qual linha ira começar e terminar, tambem define o tamanho do navio.
        for(j = 4; j < 7; j++) {
            tabuleiro[j][y] = 3; // define como o navio deve ser visualizado.
        }
        for(j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]); // printa o mapa( matriz 10 x 10 ) com os valores de i e j
        }

    }
    printf("\n");    








    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
