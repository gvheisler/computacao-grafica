Trabalho 1 de computação gráfica - Augusto Pagnossim Frigo

Implementações

- Inserir/excluir figura
- Cor da figura
- Editar tamanho da figura (via transformação linear)
- Editar orientação da figura (via transformação linear)
- Enviar para frente/trás (via selecionar figura)
- Salvar em arquivo e carregar de arquivo

Extras

- Inserção de figuras irregulares com o mouse (pode ser qualquer figura, os pontos vão estar na ordem em que você clicar no cenário).
- Inserção de qualquer figura regular com base na equação do círculo, e não limitado a quadrados, triângulos, círculos e afins. 
- Paleta de cores (não é muito complexa mas ficou bonitinha).
- Colisão para figuras irregulares quaisquer
- Algoritmo de fecho convexo de Graham (botão reduce).
- Sinalizar qual figura está selecionada (fica amarela)
- Rotacionar a figura em qualquer ângulo (via transformação linear) - O botão da matriz captura input do teclado, sendo funcional para números e funções trigonométricas ("-cos(1.57)", "sin(1.57)" "-4.32", "6.73").
- Concatenação de matrizes de transformação - As matrizes de transformação são guardadas em uma pilha e, posteriormente, aplicadas na ordem inversa.
- Concatenar duas figuras (Concatena os pontos e aplica o fecho convexo de Graham para gerar a nova figura)
- Preencher uma figura qualquer - na descrição o exemplo é círculo, triângulo, etc, mas o meu funciona para figuras bizarras com vários riscos (depende um pouco de como o algoritmo entende o que é "dentro da figura" nesses casos). 
- Preencher uma figura qualquer com imagem BMP (a imagem não escala conforme a figura, mas só é renderizada dentro dela).
- Aplicar criptografia no arquivo (cifra de cesar)
- Painel com label para cada figura (As figuras são mostradas em ordem de seleção, sendo 10 o limite).
- Escala de vermelho, verde, azul e cinza na imagem BMP
- Inversão de cores na imagem BMP
- Histograma da imagem BMP

Instruções de uso

Clique em uma cor qualquer na paleta de cores. Isso fará com que seu próximo desenho saia nessa cor. Você precisa clicar em uma cor antes de desenhar, a não ser que deseje um polígono invisível.

Botões:
!regular - Inicia a criação de uma figura irregular - Os próximos pontos em que você clicar serão adicionados sequencialmente à formação da figura. Pressione enter para encerrar a criação.
bmp - Insere uma figura BMP dentro da figura atualmente selecionada. (ela é renderizada a partir do centro da figura, se for muito larga nas bordas e pouco no centro, pode renderizar pouco)
save - salva as figuras (do modo como estão está sendo renderizadas atualmente, mas sem salvar o fill e a imagem BMP).
OBS: O save coloca as figuras no disco como estão, então, se você salvar uma figura e depois ler ela, a figura transformada passará a ser a original.
read - limpa a lista atual de figuras e lê um arquivo com figuras salvas anteriormente.
regular - Insere uma figura regular nova - note que há botões no teclado para controlar os parâmetros de geração dessa figura.
concat - Concatena 2 figuras, aplicando o fecho convexo para gerar o menor polígono possível a partir delas (por decisão de implementação, elas são concatenadas de onde estão). (não faz nada se não houver pelo menos 2 figuras).
delete - deleta a figura selecionada.
fill - preenche a figura selecionada.

-- Transformações lineares --

Para fazer uma transformação linear, use a matriz que está à direita dos botões. Ela está preenchida, a priori, com a matriz identidade. Clique nos campos e os edite para adicionar números à transformação. A matriz suporta as funções trigonométricas "sin(num)", "-sin(num), "cos(num)", "-cos(num)" e números reais, desde que num siga um padrão legível ("-3.1415", "3.1415", "3", "-3"). Os numeros da funcao trigonometrica sao recebidos em graus.
Após preencher a matriz com os números desejados, clique em "add". Isso adicionará a matriz à pilha de matrizes de transformação. Você pode adicionar quantas matrizes quiser, elas serão concatenadas (multiplicadas) na ordem inversa, para que depois seja aplicada a transformação sobre a imagem. Ou seja, se você quiser aplicar uma rotação e depois uma escala, coloque primeiro a matriz de rotação e depois a matriz de escala. As transformações são sempre aplicadas sobre os pontos originais, e nunca sobre os transformados, se você quiser aplicar transformações sucessivas apenas concatene as matrizes. 

Reduce: O botão reduce serve para aplicar o algoritmo de fecho convexo, para obter o menor poligono possivel. Note que o reduce é aplicado em cima da figura original, mas, ao transformar, é possível obter uma transformação em cima do polígono feito pelo algoritmo. Ou seja, se você quer aplicar o algoritmo de fecho convexo, utilize o botão reduce e, após, aplique a transformação linear. A ordem (transformação -> convexHull / convexHull -> transformação) não faz diferença porque não há suporte a translação. Ao "desaplicar" o algoritmo de fecho convexo, clicando novamente no reduce, a figura original será restaurada.

Teclado: (as letras precisam estar sem caps lock)
u: Aumenta o número de vértices da figura regular
j: Diminui o número de vértices da figura regular
i: Aumenta o raio x da figura regular em 50
k: Diminui o raio x da figura regular em 50
o: Aumenta o raio y da figura regular em 50
l: Diminui o raio y da figura regular em 50
c: aumenta o número de vértices da figura regular para 1000 (com intuito de aproximar um círculo).
p: restaura o número de vértices da figura regular para 5
enter: finaliza a criação da figura irregular

Teclado (para manipulação da figura bitmap - Bmp tem que estar carregado na figura selecionada para funcionar)

r: coloca a figura em escala de vermelho
g: coloca a figura em escala de verde
b: coloca a figura em escala de azul
v: coloca a figura em grayscale
f: inverte as cores da figura

Obs: as transformações lineares NÃO SÃO aplicadas ao BMP, mas ele se adapta à renderização da nova figura (ou seja, não sai das bordas).