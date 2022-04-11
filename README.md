# l122a - Laboratório I de Programação

ELC1065 DLSC/CT/UFSM\
turmas SI2 e CC2, primeiro semestre 2022\
professor: Benhur Stein 
([benhur+l122a@inf.ufsm.br](mailto:benhur%2bl122a@inf.ufsm.br))\
terças e quintas, 14h30\
sala 334, prédio 7 (principal do CT)

## Desenvolvimento da disciplina

Os canais de comunicação entre o professor e os alunos são as aulas presenciais, esta página (<https://github.com/BenhurUFSM/l122a>), e-mail (ver acima). Caso queira conversar fora desses canais, manda um mail que marcamos.

O e-mail pode ser usado para o envio de perguntas, exercícios, reclamações, sugestões, críticas e o que mais for, durante todo o período em que durar a disciplina.

Esta página concentrará os assuntos vistos em aula, a descrição de exercícios e trabalhos, avaliações, etc. Ela estará sendo aumentada/atualizada durante todo o semestre. Ela é o canal mais oficial de informações sobre a disciplina.

A disciplina de laboratório I de Programação é bastante prática, e exige que os alunos se dediquem bastante e desenvolvam trabalhos práticos.
O objetivo da disciplina, aprender a programar computadores, envolve conceitos que podem levar um tempo razoável para serem adquiridos.
A prática de programação tem se mostrado essencial nesse aprendizado.
Para realizar essa prática, é necessário acesso a um computador e a um ambiente de desenvolvimento de programas.
A universidade dispõe de laboratórios com computadores para acesso aos alunos, com todo o software necessário instalado; consulte o NCC caso necessite.

Em um computador pessoal, pode-se instalar um ambiente de desenvolvimento localmente ou usar um dos vários que existem gratuitamente online.
O que se necessita como ambiente de desenvolvimento para a disciplina é o mais básico, basta um editor de textos e um compilador da linguagem "C".
Exemplos de ambiente gratuito online: [onlineGDB](https://www.onlinegdb.com), [replit](https://www.replit.com).
Os exercícios e trabalhos da disciplinas podem ser desenvolvidos nesses ambientes.

Meu ambiente pessoal de trabalho é no sistema linux, e nesse sistema posso auxiliá-los na instalação e uso de um compilador.
Não tenho nenhuma experiência pessoal gratificante com windows, não vou poder auxiliá-lo com problemas diretamente relacionados ao uso desse ambiente.

Por ser uma disciplina prática, a principal forma de avaliação dos alunos será através de exercícios, principalmente o desenvolvimento de pequenos programas de computador, a serem enviados para o professor. No final do semestre, deve ser desenvolvido um trabalho final um pouco mais complexo.
A descrição desses exercícios e programas, bem como a forma de entrega dos mesmos será disponibilizada nesta página.

Os trabalhos entregues não serão pontuados, mas comentados de forma individual ou coletiva.
Espera-se que esses comentários sejam aproveitados para gerar novas e melhores versões dos programas, como forma de aprendizagem. 
Os programas podem ser alterados e reenviados ao professor, caso restem dúvidas.

A avaliação será realizada no final do semestre. Para isso, cada aluno deverá entregar a versão final de um subconjunto dos trabalhos desenvolvidos (a ser definido), juntamente com uma auto-avaliação descrevendo o seu desenvolvimento durante o semestre, contendo uma sugestão de nota.

Para quem não alcançar a nota suficiente (7), haverá uma prova escrita de recuperação (chamada exame).

Não deixem dúvidas acumularem.
Quanto mais cedo conseguirmos nos comunicar para apontar problemas, expor sugestões, melhores vão ser nossas chances de sucesso.

##  Aulas 

Os assuntos vistos em aula serão listados aqui.

|    N |   data | assunto
| ---: | :----: | :--------
|    1 |  12abr | introdução

<!--
|    N |   data | assunto
| ---: | :----: | :--------
|    1 |  18mai | [introdução](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/01.Intro.md)
|    2 |  20mai | [primeiro programa C](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/02.p1.c.md)
|    3 |  25mai | [variáveis, entrada de dados](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/03.md)
|    4 |  27mai | [tipos de dados em ponto flutuante](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/04.md)
|    5 |   1jun | [funções](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/05.md)
|    6 |   8jun | [seleção `if`, operadores de comparação](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/06.md)
|    7 |  10jun | [operadores lógicos, seleção múltipla com `if`s aninhados](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/07.md)
|    8 |  15jun | [comando de repetição `for`](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/08.md)
|    9 |  17jun | [comandos de repetição `while` e `do .. while`](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/09.md)
|   10 |  24jun | [comando de seleção `switch`; vetores](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/10.md)
|   11 |  29jun | [vetores, cont](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/11.md)
|   12 |   1jul | [strings](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/12.md)
|   13 |   6jul | [exercícios de string; sscanf, sprintf](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/13.md)
|   14 |   8jul | [passagem de parâmetros por referência](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/14.md)
|   15 |  13jul | [arquivos](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/15.md)
|   16 |  15jul | [exercícios](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/16.md)
|   17 |  20jul | [registros](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/17.md)
|   18 |  22jul | [exercícios](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/18.md)
|   19 |  27jul | [exercícios](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/18.md)
|   20 |  29jul | [alocação dinâmica de memória](https://github.com/BenhurUFSM/l121a/blob/main/Assuntos/20.md)
-->

## Exercícios, trabalhos, provas

|     N |    prazo | assunto
| ----: | -------: | :-----------

## Ementa

Ver [aqui](https://www.ufsm.br/ementario/disciplinas/elc1065/).

## Material Auxiliar

[Apostila de C da UFPR](http://www.inf.ufpr.br/cursos/ci067/Docs/NotasAula.pdf)

[Curso de programação C da UFMG](http://www2.dcc.ufmg.br/disciplinas/pc/source/introducao_c_renatocm_deeufmg.pdf)

[Apostila de programação da UFPR](http://www.inf.ufpr.br/cursos/ci055/apostila.pdf)

Ajude o robozinho a iluminar o mundo (ajuda no desenvolvimento de lógica de programação, fundamental para o conteúdo da disciplina) [lightbot](http://lightbot.com).

Ajude o passarinho a detonar o porco (semelhante ao anterior) [code.org](http://studio.code.org/hoc/1)

Os grupos PET geralmente oferecem tópicos de apoio a disciplinas iniciais.

## Avaliações etc

Veja a [planilha](https://docs.google.com/spreadsheets/d/1dYZhhmr0av8yhr5fJFQJtmm7k2YVAXMw-r_wpBOPbuE/edit?usp=sharing).
