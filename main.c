#include <stdio.h>

#define JOGADOR_X 'X'
#define JOGADOR_O 'O'
#define EMPATE 'E'
#define VAZIO '_'

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
  int l;
  int c;
  int pos;
  int contador = 0;
  char tabela[LINHAS][COLUNAS];
  char jogador = JOGADOR_X;
  char ganhador = EMPATE;
  char escolha;

  // linhas e colunas
  for (l = 0; l < LINHAS; l++)
  {
    for (c = 0; c < COLUNAS; c++)
      tabela[l][c] = VAZIO;
  }

  printf("\nO jogo começou!\n");

  while (1)
  {
    // Imprimir a tabela
    printf("\n");
    for (l = 0; l < LINHAS; l++)
    {
      for (c = 0; c < COLUNAS; c++)
      {
        printf("%c ", tabela[l][c]);
      }
      printf("\n");
    }
    printf("\nAgora é a vez do jogador %c, digite sua posição: ", jogador);
    scanf("%d", &pos);

    // Colocar posições e verificação de posição já preenchida
    if (pos < 1 || pos > 9)
    {
      printf("Posição invalida, tente novamente.\n");
      continue;
    }

    if (pos >= 1 && pos <= 3)
    {
      if (tabela[0][pos - 1] != VAZIO)
      {
        printf("Posição preenchida, tente novamente.\n");
        continue;
      }
      tabela[0][pos - 1] = jogador;
    }
    else if (pos >= 4 && pos <= 6)
    {
      if (tabela[1][pos - 4] != VAZIO)
      {
        printf("Posição preenchida, tente novamente.\n");
        continue;
      }
      tabela[1][pos - 4] = jogador;
    }
    else if (pos >= 7 && pos <= 9)
    {
      if (tabela[2][pos - 7] != VAZIO)
      {
        printf("Posição preenchida, tente novamente.\n");
        continue;
      }
      tabela[2][pos - 7] = jogador;
    }

    // Condições para vitória do JOGADOR_X

    for (l = 0; l < LINHAS; l += 1)
    {
      if (tabela[l][0] == JOGADOR_X && tabela[l][1] == JOGADOR_X && tabela[l][2] == JOGADOR_X)
      {
        ganhador = JOGADOR_X;
        break;
      }
    }

    for (c = 0; c < COLUNAS; c += 1)
    {
      if (tabela[0][c] == JOGADOR_X && tabela[1][c] == JOGADOR_X && tabela[2][c] == JOGADOR_X)
      {
        ganhador = JOGADOR_X;
        break;
      }
    }

    if (tabela[0][0] == JOGADOR_X && tabela[1][1] == JOGADOR_X && tabela[2][2] == JOGADOR_X)
    {
      ganhador = JOGADOR_X;
    }
    else if (tabela[0][2] == JOGADOR_X && tabela[1][1] == JOGADOR_X && tabela[2][0] == JOGADOR_X)
    {
      ganhador = JOGADOR_X;
    }

    // Condições para vitória do JOGADOR_O

    for (l = 0; l < LINHAS; l += 1)
    {
      if (tabela[l][0] == JOGADOR_O && tabela[l][1] == JOGADOR_O && tabela[l][2] == JOGADOR_O)
      {
        ganhador = JOGADOR_O;
        break;
      }
    }

    for (c = 0; c < COLUNAS; c += 1)
    {
      if (tabela[0][c] == JOGADOR_O && tabela[1][c] == JOGADOR_O && tabela[2][c] == JOGADOR_O)
      {
        ganhador = JOGADOR_O;
        break;
      }
    }

    if (tabela[0][0] == JOGADOR_O && tabela[1][1] == JOGADOR_O && tabela[2][2] == JOGADOR_O)
    {
      ganhador = JOGADOR_O;
    }
    else if (tabela[0][2] == JOGADOR_O && tabela[1][1] == JOGADOR_O && tabela[2][0] == JOGADOR_O)
    {
      ganhador = JOGADOR_O;
    }

    // Condição para garantir que o jogo rode até o final
    if (ganhador != EMPATE)
    {
      break;
    }

    // Condição de empate
    int cheio = 1;
    for (l = 0; l < LINHAS; l++)
    {
      for (c = 0; c < COLUNAS; c++)
      {
        if (tabela[l][c] == VAZIO)
        {
          cheio = 0;
          break;
        }
      }
    }
    if (cheio && ganhador == EMPATE)
    {
      break;
    }

    // Contador para verificar a ordem dos jogadores
    contador += 1;
    if (contador % 2 == 0)
    {
      jogador = JOGADOR_X;
    }
    else
    {
      jogador = JOGADOR_O;
    }
  }

  // Imprimir texto de vencedor e empate após o fim do jogo
  if (ganhador != EMPATE)
  {
    printf("\n-----------------------------------------------\n");
    printf("O jogo terminou! O vencedor é o Jogador %c!", ganhador);
    printf("\n-----------------------------------------------\n");
  }
  else
  {
    printf("\n-----------------------------------------------\n");
    printf("O jogo empatou! Deseja jogar novamente?");
    printf("\n-----------------------------------------------\n");
  }

  // Imprimir tabela após o fim do jogo
  for (l = 0; l < LINHAS; l++)
  {
    for (c = 0; c < COLUNAS; c++)
    {
      printf("%c ", tabela[l][c]);
    }
    printf("\n\n");
  }

  return 0;
}