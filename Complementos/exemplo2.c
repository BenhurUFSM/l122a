#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "tela.h"

typedef struct {
  float x;
  float y;
} ponto;

typedef struct {
  ponto cse;
  ponto cid;
} retangulo;

typedef struct {
  ponto centro;
  float raio;
} circulo;

retangulo botao_de_desiste;

bool ponto_no_retangulo(ponto p, retangulo r)
{
  return p.x >= r.cse.x && p.x < r.cid.x
      && p.y >= r.cse.y && p.y < r.cid.y;
}

float distancia_entre_pontos(ponto p1, ponto p2)
{
  float c1 = p1.x - p2.x;
  float c2 = p1.y - p2.y;
  return sqrt(c1*c1 + c2*c2);
}

bool ponto_no_circulo(ponto p, circulo c)
{
  return distancia_entre_pontos(p, c.centro) <= c.raio;
}

bool circulos_intersectam(circulo c1, circulo c2)
{
  return distancia_entre_pontos(c1.centro, c2.centro) <= (c1.raio + c2.raio);
}

bool retangulos_intersectam(retangulo r1, retangulo r2)
{
  if (r1.cse.x > r2.cid.x) return false;
  if (r2.cse.x > r1.cid.x) return false;
  if (r1.cse.y > r2.cid.y) return false;
  if (r2.cse.y > r1.cid.y) return false;
  return true;
}



// implementa a funcao abaixo, que retorna true se a interseccao entre
// o retangulo e o circulo nao for vazia
// pega o programa em 
//   https://github.com/BenhurUFSM/l122a/blob/main/Complementos/exemplo2.c
bool retangulo_e_circulo_intersectam(retangulo r, circulo c)
{
  return false;
}




void desenha_circulo(circulo c, int co)
{
  tela_circulo(c.centro.x, c.centro.y, c.raio, 2, preto, co);
}

void desenha_retangulo(retangulo r, int co)
{
  tela_retangulo(r.cse.x, r.cse.y, r.cid.x, r.cid.y, 2, preto, co);
}

int main()
{
  tela_inicio(500, 500, "teste");
  retangulo r1 = { { 250, 250 }, { 300, 350} };
  circulo c1 = { { 100, 100 }, 50 };
  while (true) {
    c1.centro.x = tela_rato_x();
    c1.centro.y = tela_rato_y();
    desenha_retangulo(r1, verde);
    if (retangulo_e_circulo_intersectam(r1, c1)) {
      desenha_circulo(c1, azul);
    } else {
      desenha_circulo(c1, vermelho);
    }
    tela_atualiza();
  }
  tela_fim();
}


