// Programa de exemplo de uso de tela.h e tela.c
//
// Necessita os arquivos exemplo3.c (este), tela.h, tela.c e DejaVuSans.ttf
// Necessita ter instalado a biblioteca allegro5
//
// para compilar este programa manualmente em linux:
// gcc -Wall -o exemplo3 exemplo3.c tela.c -lallegro_font -lallegro_color -lallegro_ttf -lallegro_primitives -lallegro
//

// Este exemplo é um programa de colorir círculos na tela.
// Existem dois conjuntos de círculos desenhados na tela:
// - um fixo no topo da tela, que serve para escolher cores
// - um móvel, que podem ser coloridos
// Clicando em um dos círculos de cores se seleciona a cor corrente
// Clicando em um dos círculos móveis se altera a cor do círculo

#include "tela.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// definição dos tipos de dados
// -----------------------------

// tipo de dados que define um círculo
typedef struct {
  // coordenadas do centro do círculo e raio, em pixels
  float x;
  float y;
  float r;
  // velocidade do círculo, em pixels por segundo
  float vx;
  float vy;
  // cor do círculo
  int cor;
} circulo_t;

// tipo de dados com o estado da tela (tudo o que precisa pra desenhar a tela)
typedef struct {
  // os círculos fixos no topo da tela
  int n_circ_fixos;
  circulo_t *circ_fixos;
  // os círculos semexentes
  int n_circ_moveis;
  circulo_t *circ_moveis;
  // limites onde os círculos móveis podem se movimentar
  float min_x;
  float min_y;
  float max_x;
  float max_y;
  // cor selecionada
  int cor;
  // true se o programa deve terminar
  bool fim;
} jogo_t;



// declaração das funções principais
// ----------------------------------

void inicializa_jogo(jogo_t *j);
void desenha_tela(jogo_t *j);
void move_circulos(jogo_t *j);
void verifica_entradas(jogo_t *j);

// A função principal
int main(void)
{
  jogo_t j;
  inicializa_jogo(&j);

  // inicializa a tela gráfica
  tela_inicio(500, 500, "exemplo");

  // laço principal
  while (!j.fim) {

    // desenha a tela e faz aparecer o que foi desenhado
    desenha_tela(&j);
    tela_atualiza();

    // atualiza a posicao dos circulos
    move_circulos(&j);

    // processa as entradas
    verifica_entradas(&j);
  }

  // encerra a tela gráfica
  tela_fim();

  return 0;
}


// funções auxiliares
// -------------------

// abandona o programa
void badabum(char *msg)
{
  printf("erro interno: %s\n", msg);
  exit(1);
}

// gera um número aleatório
int aleat_entre(int m, int M)
{
  return rand()%(M-m+1)+m;
}


// inicialização
// --------------

// inicializa a estrutura do jogo
void inicializa_jogo(jogo_t *j)
{
  // cria os círculos fixos
  j->n_circ_fixos = 9;
  j->circ_fixos = malloc(j->n_circ_fixos * sizeof(circulo_t));
  if (j->circ_fixos == NULL) {
    badabum("falta memoria");
  }
  for (int i=0; i<j->n_circ_fixos; i++) {
    circulo_t *c = &(j->circ_fixos[i]);
    c->x = 40+i*30;
    c->y = 30;
    c->r = 10;
    c->vx = 0;
    c->vy = 0;
    c->cor = i+1;
  }
  
  // inicializa os limites de movimento
  j->min_x = 30;
  j->max_x = 470;
  j->min_y = 60;
  j->max_y = 470;

  // cria os círculos móveis
  j->n_circ_moveis = aleat_entre(5, 10);
  j->circ_moveis = malloc(j->n_circ_moveis * sizeof(circulo_t));
  if (j->circ_moveis == NULL) {
    badabum("falta memoria");
  }
  for (int i=0; i<j->n_circ_moveis; i++) {
    circulo_t *c = &(j->circ_moveis[i]);
    c->r = aleat_entre(5, 100);
    c->x = aleat_entre(j->min_x+c->r, j->max_x-c->r);
    c->y = aleat_entre(j->min_x+c->r, j->max_y-c->r);
    c->vx = aleat_entre(-200, 200);
    c->vy = aleat_entre(-200, 200);
    c->cor = transparente;
  }

  // inicializa a cor selecionada
  j->cor = preto;
  // o programa ainda nao termimou
  j->fim = false;
}



// movimentação (passagem do tempo)
// ---------------------------------

// movimenta o i-ésimo círculo
void move_circulo(jogo_t *j, int i)
{
  // faz um ponteiro apontar para o círculo a mover
  circulo_t *c = &(j->circ_moveis[i]);
  // altera a posição do círculo de acordo com a velocidade
  c->x += c->vx * SEGUNDOS_POR_QUADRO;
  c->y += c->vy * SEGUNDOS_POR_QUADRO;
  // inverte a velocidade se o círculo sair da tela
  //   deveria ajustar a posição também, pode dar problemas com vel muito alta
  if (c->x-c->r < j->min_x && c->vx < 0) c->vx *= -1;
  if (c->x+c->r > j->max_x && c->vx > 0) c->vx *= -1;
  if (c->y-c->r < j->min_y && c->vy < 0) c->vy *= -1;
  if (c->y+c->r > j->max_y && c->vy > 0) c->vy *= -1;
}

// movimenta os círculos móveis
void move_circulos(jogo_t *j)
{
  for (int i=0; i<j->n_circ_moveis; i++) {
    move_circulo(j, i);
  }
}


// desenho
// --------

// desenha um circulo
void desenha_circulo(circulo_t c)
{
  tela_circulo(c.x, c.y, c.r, 2, branco, c.cor);
}

// desenha a tela
void desenha_tela(jogo_t *j)
{
  // desenha o contorno da área de movimentação
  tela_retangulo(j->min_x, j->min_y, j->max_x, j->max_y, 5,
                 amarelo, transparente);

  // desenha os círculos fixos
  for (int i=0; i<j->n_circ_fixos; i++) {
    desenha_circulo(j->circ_fixos[i]);
  }
  // desenha os círculos moveis
  for (int i=0; i<j->n_circ_moveis; i++) {
    desenha_circulo(j->circ_moveis[i]);
  }

  // desenha um círculo na posição do mouse
  tela_circulo(tela_rato_x(), tela_rato_y(), 7, 1.5, branco, j->cor);
}



// processamento das entradas
// ---------------------------


// diz se o ponto está dentro do círculo
bool ponto_no_circulo(float x, float y, circulo_t c)
{
  float dx = x - c.x;
  float dy = y - c.y;
  float dx2 = dx*dx;
  float dy2 = dy*dy;
  float r2 = c.r*c.r;
  return dx2 + dy2 < r2;
}

// acha um circulo na coordenada dada
int acha_circulo_no_ponto(int n, circulo_t v[n], float x, float y)
{
  for (int i=0; i<n; i++) {
    if (ponto_no_circulo(x, y, v[i])) {
      return i;
    }
  }
  return -1;
}

void verifica_entradas(jogo_t *j)
{
  // sinaliza o fim do programa se algo foi digitado no teclado
  if (tela_tecla() != '\0') {
    j->fim = true;
  }

  // processa clique do mouse
  if (!tela_rato_clicado()) return;
  float x = tela_rato_x_clique();
  float y = tela_rato_y_clique();

  // ve se clicou em algum círculo fixo
  int c = acha_circulo_no_ponto(j->n_circ_fixos, j->circ_fixos, x, y);
  if (c != -1) {
    j->cor = j->circ_fixos[c].cor;
    return;
  }

  // vê se clicou em algum círculo semexente
  c = acha_circulo_no_ponto(j->n_circ_moveis, j->circ_moveis, x, y);
  if (c != -1) {
    j->circ_moveis[c].cor = j->cor;
    return;
  }
}
