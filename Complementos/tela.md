### Arquivos para manipular a tela gráfica

Os arquivos (tela.h) e (tela.c) implementam um conjunto mínimo de funções para manipular a tela gráfica.
Para isso, eles fazem uso da biblioteca [allegro 5](https://github.com/liballeg/allegro5).
Para desenhar letras na tela gráfica, eles usam um arquivo com desenhos de letras (DejaVuSans.ttf).

O arquivo tela.h tem uma descrição das funções disponilizadas.

Um exemplo de uso está no arquivo (exemplo.c).
Para compilar esse programa com o compilador gcc, pode-se usar o comando:
```
gcc -Wall -o exemplo exemplo.c tela.c -lallegro_font -lallegro_color -lallegro_ttf -lallegro_primitives -lallegro
```
