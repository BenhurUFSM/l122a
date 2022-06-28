// Programa de exemplo de uso de tela.h e tela.c
//
// Necessita os arquivos exemplo.c (este), tela.h, tela.c e DejaVuSans.ttf
// Necessita ter instalado a biblioteca allegro5
//
// para compilar este programa manualmente em linux:
// gcc -Wall -o exemplo exemplo.c tela.c -lallegro_font -lallegro_color -lallegro_ttf -lallegro_primitives -lallegro
//

#include "tela.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// A função principal
int main(void)
{
  // inicializa a tela gráfica
  tela_inicio(500, 500, "exemplo");

  // laço principal
  while (true) {
    // sai do laço quando algo for digitado no teclado
    if (tela_tecla() != '\0') {
      break;
    }
  }

  // encerra a tela gráfica
  tela_fim();

  return 0;
}

