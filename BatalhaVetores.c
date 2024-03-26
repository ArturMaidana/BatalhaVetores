// Alunos: Gustavo Capistrano e Artur Guilherme
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n_jogadores, m_rodadas;
  srand(time(NULL));

  printf("Quantos jogadores irão participar? (mínimo 2):");
  scanf("%d", &n_jogadores);
  printf("Quantas rodadas? (mínimo 3):");
  scanf("%d", &m_rodadas);

  if (m_rodadas < 3) {
    printf("Número de rodadas inválido");
    return 0;
  }
  if (n_jogadores < 2) {
    printf("Número de jogadores inválido");
    return 0;
  }

  char nomes[n_jogadores][50];
  for (int count = 0; count < n_jogadores; count++) {
    printf("Digite o nome do jogador %d:", count + 1);
    scanf("%s", nomes[count]);
  }

  int tabela[n_jogadores][m_rodadas];
  int total_jogador[n_jogadores];
  for (int cnt = 0; cnt < n_jogadores; cnt++) {
    total_jogador[cnt] = 0;
  }

  char c;
  int melhor = 0;
  for (int j = 0; j < m_rodadas; j++) {
    printf("Rodada %d: ", j);

    for (int i = 0; i < n_jogadores; i++) {

      tabela[i][j] = rand() % 10;
      total_jogador[i] += tabela[i][j];
      if (total_jogador[i] > melhor) {
        melhor = total_jogador[i];
      }
      printf("Jogador %s: %d, ", nomes[i], tabela[i][j]);
    }

    printf("\nTOTAL PARCIAL:");

    for (int w = 0; w < n_jogadores; w++) {
      printf("Jogador %s: %d, ", nomes[w], total_jogador[w]);
    }
    printf("\n\nDigite um caractere para continuar:");
    scanf("%c\n\n\n", &c); // estou utilizando isso ao invés do getchar
  }

  int aux;
  printf("\nTOTAL:");
  for (int z = 0; z < n_jogadores; z++) {
    if (total_jogador[z] == melhor) {
      printf("|Vencedor => Jogador %s: %d| ", nomes[z], total_jogador[z]);
    } else {
      printf("Jogador %s: %d, ", nomes[z], total_jogador[z]);
    }
  }

  return 0;
}