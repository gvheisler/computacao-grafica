/*********************************************************************
// Canvas para desenho, criada sobre a API OpenGL. Nao eh necessario conhecimentos de OpenGL para usar.
//  Autor: Cesar Tadeu Pozzer
//         05/2020
//
//  Pode ser utilizada para fazer desenhos, animacoes, e jogos simples.
//  Tem tratamento de mouse e teclado
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp
//
//  Versao 2.0
//
//  Instruções:
//	  Botão esquerdo cria imagem
// *********************************************************************/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>

#include "gl_canvas2d.h"
#include "gerenciadorDeBotoes.h"
#include "imagem.h"
#include "formas.h"
#include "auxiliar.h"


#define borda 20
#define menu 100

void desenha_figura();

//variavel global para selecao do que sera exibido na canvas.
int opcao  = 50;
int screenWidth = 600, screenHeight = 500; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY, mouseB, mouseS; //variaveis globais do mouse para poder exibir dentro da render().
std::vector<FormaGeometrica*> vetorImg = {};

int figuraSelecionada = -1;

int tamPadraoFigura = 40;

FormaGeometrica *img = NULL;
ManagerBt * MngBt = NULL;

void teste(){
    printf("zizizii\n");
}

//inicializar toda a ap c botoes
void inicializa_interface()
{
   CV::color(0.2, 0.5, 0.3);
   //menu sup esq
   CV::rectFill(0,0,screenWidth,menu);
   CV::rectFill(0,0,menu,screenHeight);
   // bordas inf dir
   CV::rectFill(0,screenHeight-borda,screenWidth,screenHeight);
   CV::rectFill(screenWidth-borda,0,screenWidth,screenHeight);
   //botoes
   // cria menu superior
   MngBt->renderMngB(mouseX,mouseY,mouseB,mouseS);
   // cria menu esquerdo

   //titulo
   CV::color(1,1,1);
   CV::text(borda,borda,"T1 - Editor de Imagens Vetoriais");
}

void selecionaForma(){
   int contador = 0;
   for(FormaGeometrica * i:vetorImg){
      if(i->ColisaoForma(mouseX, mouseY)){
         figuraSelecionada=contador;
      }
      contador++;
   }
}

void DrawMouseScreenCoords()
{
    char str[100];
    sprintf(str, "Mouse: (%d,%d)", mouseX, mouseY);
    CV::text(10,screenHeight, str);
}

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis globais
//Todos os comandos para desenho na canvas devem ser chamados dentro da render().
//Deve-se manter essa função com poucas linhas de codigo.
void render()
{
   CV::clear(1, 1, 1);
   desenha_figura();
   inicializa_interface();
   //DrawMouseScreenCoords();
}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
   printf("\nTecla: %d" , key);


   switch(key)
   {
      case 27:
	     exit(0);
        break;
      case 200:
         vetorImg[figuraSelecionada]->RotacionaFormaAH();
         break;
      case 202:
         vetorImg[figuraSelecionada]->RotacionaFormaH();
         break;
   }
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou: %d" , key);
}

void desenha_figura()
{
   int contador = 0;
   for(FormaGeometrica * i:vetorImg){
      if(contador==figuraSelecionada)
      {
         i->RenderCaixaSelecao();
      }

      i->RenderForma();
      contador++;
   }
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   mouseX = x; //guarda as coordenadas do mouse para exibir dentro da render()
   mouseY = y;
   mouseB = button;
   mouseS = state;

   MngBt->cliqueMngB(mouseX,mouseY,mouseB,mouseS);

   if((mouseX > menu && mouseX < screenWidth-borda) && (mouseY > menu && mouseY < screenHeight-borda)){
      if (state==0){
            figuraSelecionada=-1;
            switch(lados){
            case 1:
               selecionaForma();
               break;
            case 30:
               img = new Circulo(mouseX, mouseY, 3, tamPadraoFigura);
               vetorImg.push_back(img);
               break;
            case 3:
               img = new Triangulo(mouseX, mouseY, 4, tamPadraoFigura);
               vetorImg.push_back(img);
               break;
            case 4:
               img = new Quadrado(mouseX, mouseY, 5, tamPadraoFigura);
               vetorImg.push_back(img);
               break;
            default:
               img = new NAgono(mouseX, mouseY, 6, tamPadraoFigura, lados);
               vetorImg.push_back(img);
               break;
            }
      }
   }
   //printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);
}

void excFigura(){
   if(figuraSelecionada!=-1)
   {
      vetorImg.erase(vetorImg.begin()+figuraSelecionada);
      figuraSelecionada=-1;
   }
}

void mudaOrdemCima(){
   if(figuraSelecionada<vetorImg.size()-1){
      auto aux = vetorImg[figuraSelecionada];
      vetorImg[figuraSelecionada]= vetorImg[figuraSelecionada+1];
      vetorImg[figuraSelecionada+1] = aux;
      figuraSelecionada=figuraSelecionada+1;
   }
}

void mudaOrdemBaixo(){
   if(figuraSelecionada!=0){
      auto aux = vetorImg[figuraSelecionada];
      vetorImg[figuraSelecionada]= vetorImg[figuraSelecionada-1];
      vetorImg[figuraSelecionada-1] = aux;
      figuraSelecionada=figuraSelecionada-1;
   }
}

void aumentarTamanho(){
   if(figuraSelecionada!=-1){
      vetorImg[figuraSelecionada]->aumenta5();
   }
}
void diminuirTamanho(){
   if(figuraSelecionada!=-1){
      vetorImg[figuraSelecionada]->diminui5();
   }
}

int main(void)
{
   MngBt = new ManagerBt(true, 25,25,1,2);
   MngBt->addBotao("Selecionar figura", selFigura);
   MngBt->addBotao("Circulo", selCirculo);
   MngBt->addBotao("Triangulo", selTriangulo);
   MngBt->addBotao("Quadrado", selQuadrado);
   MngBt->addBotao("Pentagono", selPentagono);
   MngBt->addBotao("Hexagono", selHexagono);
   MngBt->addBotao("Aumentar lados", incLados);
   MngBt->addBotao("Diminuir lados", decLados);
   MngBt->addBotao("Excluir figura", excFigura);
   MngBt->addBotao("Enviar para cima", mudaOrdemCima);
   MngBt->addBotao("Enviar para baixo", mudaOrdemBaixo);
   MngBt->addBotao("Aumentar", aumentarTamanho);
   MngBt->addBotao("Diminuir", diminuirTamanho);

   CV::init(&screenWidth, &screenHeight, "Josiane C Aggens");
   CV::run();
}
