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
//
Implementado:
1- Inserir figuras.
2- Excluir figuras.
3- Editar tamanho da figura.
4- Editar orientação da figura (giros horários e anti-horários de 2 graus).
5- Enviar para frente/traz.
6- Editar cor da figura.
7- Sinaliza qual figura está selecionada.
8- Rotacionar figura em qualquer ângulo. (Descrito no item 4)
9- Permitir inserir polígonos quaisquer. (Usando botões "lados" como descrito no README)
10- Salvar em arquivo e carregar de arquivo.
// *********************************************************************/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>
#include <fstream>

#include "gl_canvas2d.h"
#include "gerenciadorDeBotoes.h"
#include "formas.h"
#include "auxiliar.h"

#define borda 40
#define menu 140

void desenha_figura();

//variavel global para selecao do que sera exibido na canvas.
int opcao  = 50;
int screenWidth = 1200, screenHeight = 640; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY, mouseB, mouseS; //variaveis globais do mouse para poder exibir dentro da render().
std::vector<FormaGeometrica*> vetorImg = {};

int figuraSelecionada = -1;

int tamPadraoFigura = 40;

FormaGeometrica *img = NULL;
ManagerBt * MngBt = NULL;
ManagerBt * MBtForm = NULL;

bool segurandoMouse = false;

int distanciaMouseX = 0;
int distanciaMouseY = 0;



//inicializa as bordas e menu de botoes
void inicializa_interface(){
   CV::color(0.2, 0.5, 0.3);
   //Bordas superior e esquerda
   CV::rectFill(0,0,screenWidth,menu-borda);
   CV::rectFill(0,0,menu,screenHeight);
   // bordas inferior e direita
   CV::rectFill(0,screenHeight-borda,screenWidth,screenHeight);
   CV::rectFill(screenWidth-borda,0,screenWidth,screenHeight);
   //botoes
   // cria menu superior
   MngBt->renderMngB(mouseX,mouseY,mouseB,mouseS);
   // cria menu esquerdo
   MBtForm->renderMngB(mouseX,mouseY,mouseB,mouseS);
   //titulo
   CV::color(1,1,1);
   CV::text(borda,borda/2,"T1 - Editor de Imagens Vetoriais");
}

// funcao para selecionar imagem da tela
void selecionaForma(){
   int contador = 0;
   for(FormaGeometrica * i:vetorImg){
      if(i->ColisaoForma(mouseX, mouseY)){
         figuraSelecionada=contador;
      }
      contador++;
   }
   if(figuraSelecionada!=-1){
      distanciaMouseX = mouseX-vetorImg[figuraSelecionada]->x;
      distanciaMouseY = mouseY-vetorImg[figuraSelecionada]->y;
   }
   segurandoMouse=true;
}

//Todos os comandos para desenho na canvas devem ser chamados dentro da render().
//Deve-se manter essa funcao com poucas linhas de codigo.
void render(){
   CV::clear(1, 1, 1);
   desenha_figura();
   inicializa_interface();
   if(figuraSelecionada!=-1&&segurandoMouse==true){
      vetorImg[figuraSelecionada]->moverComMouse(mouseX, mouseY, distanciaMouseX, distanciaMouseY);

   }
}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key){
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
      case 114:
         vetorImg[figuraSelecionada]->atualizaCor(2);
         break;
      case 103:
         vetorImg[figuraSelecionada]->atualizaCor(3);
         break;
      case 98:
         vetorImg[figuraSelecionada]->atualizaCor(4);
         break;
   }
}
void keyboardUp(int key){
   return;
}

//funcao para desenhar as figuras e suas bordas de selecao
void desenha_figura(){
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
void mouse(int button, int state, int wheel, int direction, int x, int y){
   mouseX = x; //guarda as coordenadas do mouse para exibir dentro da render()
   mouseY = y;
   mouseB = button;
   mouseS = state;

   //testa clique nos botoes
   MngBt->cliqueMngB(mouseX,mouseY,mouseB,mouseS);
   MBtForm->cliqueMngB(mouseX,mouseY,mouseB,mouseS);

   // verifica os cliques do mouse para selecao e criacao de figuras
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
      }if(state==1){
        segurandoMouse=false;
      }
   }
}

//funcao para deletar todas as imagens da tela
void limparTela(){
   vetorImg.clear();
}

//funcao que deleta a imagem selecionada
void excFigura(){
   if(figuraSelecionada!=-1)
   {
      vetorImg.erase(vetorImg.begin()+figuraSelecionada);
      figuraSelecionada=-1;
   }
}

//funcao que sobrepoe a figura as demais ja criadas
void mudaOrdemCima(){
   if(figuraSelecionada<vetorImg.size()-1){
      auto aux = vetorImg[figuraSelecionada];
      vetorImg[figuraSelecionada]= vetorImg[figuraSelecionada+1];
      vetorImg[figuraSelecionada+1] = aux;
      figuraSelecionada=figuraSelecionada+1;
   }
}
//funcao que bota a figura selecionada atras das figuras ja criadas
void mudaOrdemBaixo(){
   if(figuraSelecionada!=0){
      auto aux = vetorImg[figuraSelecionada];
      vetorImg[figuraSelecionada]= vetorImg[figuraSelecionada-1];
      vetorImg[figuraSelecionada-1] = aux;
      figuraSelecionada=figuraSelecionada-1;
   }
}

//funcao que aumenta o tamanho da figura selecionada
void aumentarTamanho(){
   if(figuraSelecionada!=-1){
      vetorImg[figuraSelecionada]->aumenta5();
   }
}

//funcao que aumenta o tamanho da figura selecionada
void diminuirTamanho(){
   if(figuraSelecionada!=-1){
      vetorImg[figuraSelecionada]->diminui5();
   }
}

//salva figuras da tela em arquivo (cria novo se não houver)
void salvaArquivo(){
    std::ofstream arquivo("./Trab1Josiane/figuras.gr", std::ios::out);
    if (arquivo.is_open()) {
        for(auto imagem : vetorImg){
            if (dynamic_cast<Quadrado*>(imagem)) {
                auto f = dynamic_cast<Quadrado*>(imagem);
                arquivo << "1" << " " << f->x << " " << f->y << " " << f->cor << " " << f->raio << " " << f->rotacao <<"\n";
            }
            if (dynamic_cast<Circulo*>(imagem)) {
                auto f = dynamic_cast<Circulo*>(imagem);
                arquivo << "2" << " " << f->x << " " << f->y << " " << f->cor << " " << f->raio << " " << f->rotacao <<"\n";
            }
            if (dynamic_cast<Triangulo*>(imagem)) {
                auto f = dynamic_cast<Triangulo*>(imagem);
                arquivo << "3" << " " << f->x << " " << f->y << " " << f->cor << " " << f->raio << " " << f->rotacao <<"\n";
            }
            if (dynamic_cast<NAgono*>(imagem)) {
                auto f = dynamic_cast<NAgono*>(imagem);
                arquivo << "4" << " " << f->x << " " << f->y << " " << f->cor << " " << f->raio << " " << f->rotacao << " " << f->lados <<"\n";
            }

        }
        arquivo.close();
    } else {
        printf("Erro ao abrir o arquivo!\n");
    }
}

//carrega arquivo pre-existente
void carregaArquivo(){
    std::ifstream arquivo_carregado("./Trab1Josiane/figuras.gr");
    if (arquivo_carregado.is_open()) {
        limparTela();
        int tipo;
        int x, y, cor;
        float raio, rotacao;
        while (arquivo_carregado >> tipo) {
            switch (tipo) {
                case 1:
                    arquivo_carregado >> x >> y >> cor >> raio >> rotacao;
                    vetorImg.push_back(new Quadrado(x, y, cor, raio, rotacao));
                    break;
                case 2:
                    arquivo_carregado >> x >> y >> cor >> raio >> rotacao;
                    vetorImg.push_back(new Circulo(x, y, cor, raio, rotacao));
                    break;
                case 3:
                    arquivo_carregado >> x >> y >> cor >> raio >> rotacao;
                    vetorImg.push_back(new Triangulo(x, y, cor, raio, rotacao));
                    break;
               case 4:
                    int lados;
                    arquivo_carregado >> x >> y >> cor >> raio >> rotacao >> lados;
                    vetorImg.push_back(new NAgono(x, y, cor, raio, rotacao, lados));
                    break;
              default:
                    printf("Erro no tipo de forma\n");
                    break;
            }

        }
    } else {
        printf("Erro ao abrir o arquivo!\n");
    }
}

int main(void){

   //gerenciador de botoes do menu superior onde fica botões de acao
   MngBt = new ManagerBt(20, 50, 7, 14);
   //gerenciador de botoes do menu esquerdo onde fica a selecao de formas
   MBtForm = new ManagerBt(true, 20, 100, 6, 14);

   //adicao de todos os botoes a serem usados
   MngBt->addBotao("Limpar", limparTela);
   MngBt->addBotao("Selecionar", selFigura);
   MBtForm->addBotao("Carregar", carregaArquivo);
   MBtForm->addBotao("Salvar", salvaArquivo);
   MBtForm->addBotao("Circulo", selCirculo);
   MBtForm->addBotao("Triangulo", selTriangulo);
   MBtForm->addBotao("Quadrado", selQuadrado);
   MBtForm->addBotao("Pentagono", selPentagono);
   MBtForm->addBotao("Hexagono", selHexagono);
   MngBt->addBotao("Lados ++", incLados);
   MngBt->addBotao("Lados --", decLados);
   MngBt->addBotao("Excluir", excFigura);
   MngBt->addBotao("Sobrepor", mudaOrdemCima);
   MngBt->addBotao("Subpor", mudaOrdemBaixo);
   MngBt->addBotao("Aumentar", aumentarTamanho);
   MngBt->addBotao("Diminuir", diminuirTamanho);

   //inicia o programa
   CV::init(&screenWidth, &screenHeight, "Josiane C Aggens");
   CV::run();
}

