#include <stdio.h>

#define JOGADOR_X 'X'
#define JOGADOR_O 'O'
#define EMPATE 'E'
#define VAZIO '-'

#define LINHAS 3
#define COLUNAS 3

/*
  Layout do jogo:

  1 2 3
  4 5 6
  7 8 9

*/

int main()
{
  // Variáveis
  int l, c, pos;
  int contador = 0;
  int placarX = 0;
  int placarO = 0;
  int empate = 0;
  char tabela[LINHAS][COLUNAS];
  char jogador, ganhador, escolha;

  // Reiniciar variáveis no reinicio do jogo
  do {
    jogador = JOGADOR_X;
    ganhador = EMPATE;

    for (l = 0; l < LINHAS; l++) {
      for (c = 0; c < COLUNAS; c++) {
        tabela[l][c] = VAZIO;
      }
    }

    printf("\nO jogo começou!\n");

    while (1) {

      // Imprimir a tabela e o placar
      printf("\n===== PLACAR =====\n");
      printf("Jogador X: %d\n", placarX);
      printf("Jogador O: %d\n", placarO);
      printf("Empates  : %d\n", empate);
      printf("==================\n\n");

      for (l = 0; l < LINHAS; l++) {
        for (c = 0; c < COLUNAS; c++) {
          printf("%c \t", tabela[l][c]);
        }
        printf("\n\n");
      }

      // Verificar se o usuário digitou alguma letra.
      printf("\nÉ a vez do jogador %c, digite sua posição: ", jogador);
      while (scanf("%d", &pos) != 1)
      {
        printf("Digite apenas números de 1 a 9. Tente novamente!");
        while (getchar() != '\n');
        printf("\nÉ a vez do jogador %c, digite sua posição: ", jogador);
      }

      // Colocar posições e verificação de posição já preenchida
      if (pos < 1 || pos > 9) {
        printf("Posição invalida, tente novamente.\n");
        continue;
      }

      int linha = (pos - 1) / 3; 
      int coluna = (pos - 1) % 3; 
      
      if (tabela[linha][coluna] != VAZIO) { 
        printf("Posição preenchida, tente novamente.\n"); 
        continue; 
      }

      tabela[linha][coluna] = jogador;

      // Condições para vitória de cada jogador

      for (l = 0; l < LINHAS; l += 1) {
        if (tabela[l][0] == jogador && tabela[l][1] == jogador && tabela[l][2] == jogador) {
          ganhador = jogador;
        }
      }

      for (c = 0; c < COLUNAS; c += 1) {
        if (tabela[0][c] == jogador && tabela[1][c] == jogador && tabela[2][c] == jogador) {
          ganhador = jogador;
        }
      }

      if (tabela[0][0] == jogador && tabela[1][1] == jogador && tabela[2][2] == jogador) {
        ganhador = jogador;
      } else if (tabela[0][2] == jogador && tabela[1][1] == jogador && tabela[2][0] == jogador) {
        ganhador = jogador;
      }

      if (ganhador != EMPATE) {
        break;
      }

      // Verificar empate 
      int cheio = 1; 
      for (l = 0; l < LINHAS; l++) {
        for (c = 0; c < COLUNAS; c++) {
          if (tabela[l][c] == VAZIO) {
            cheio = 0;
          }
        }
      }
          
      if (cheio) {
        break;
      }
      
      jogador = (jogador == JOGADOR_X ? JOGADOR_O : JOGADOR_X); 
    }

      // Resultado final
      if (ganhador == JOGADOR_X) {
        placarX++;
        printf("\n-----------------------------------------------\n");
        printf("---O jogo terminou! O vencedor é o Jogador %c!---", ganhador);
        printf("\n-----------------------------------------------\n");
      } else if (ganhador == JOGADOR_O) {
        placarO++;
        printf("\n-----------------------------------------------\n");
        printf("---O jogo terminou! O vencedor é o Jogador %c!---", ganhador);
        printf("\n-----------------------------------------------\n");
      } else {
        empate++;
        printf("\n-----------------------------------------------\n");
        printf("--------------- O jogo empatou! ----------------");
        printf("\n-----------------------------------------------\n\n");
      }

    // Imprimir tabela após o fim do jogo
    for (l = 0; l < LINHAS; l++) {
      for (c = 0; c < COLUNAS; c++) {
        printf("%c \t", tabela[l][c]);
      }
      printf("\n\n");
    }

    // Opção de reinicio por escolha do usuário
    do {
      printf("Você deseja jogar novamente? (S/N)\n");
      scanf(" %c", &escolha);

      if (escolha != 'S' && escolha != 's' && escolha != 'N' && escolha != 'n') {
        printf("Opção invalida, digite novamente!\n");
      }
    } 
    while (escolha != 'S' && escolha != 's' && escolha != 'N' && escolha != 'n');
  } while (escolha == 'S' || escolha == 's');

  // Mensagem final.
  if (escolha == 'N' || escolha == 'n')
  {
    printf("\nObrigado! Bom jogo\n");
  }
  return 0;
}