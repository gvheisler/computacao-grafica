/*********************************************************************
// Canvas para desenho, criada sobre a API OpenGL. Nao eh necessario conhecimentos de OpenGL para usar.
//  Autor: Cesar Tadeu Pozzer
//			05/2020
//
//  Pode ser utilizada para fazer desenhos, animacoes, e jogos simples.
//  Tem tratamento de mouse e teclado
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp
//
//  Versao 2.0
//
//  Instruções:
//	  Para alterar a animacao, digite numeros entre 1 e 3
// *********************************************************************/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <vector>

#include "gl_canvas2d.h"
#include "managerBotao.h"
#include "sevSeg.h"

int screenWidth = 1200, screenHeight = 600;
int mouseX, mouseY, mouseS;

ManagerBotoes * mBotoes = NULL;



void render(){
	CV::clear(0.7,0.7,0.7);
    //mBotoes->renderBotoes(mouseX, mouseY, mouseS);
    //displaySevSeg(100,100, 'A');
    printaFraseSevSeg();
}

void keyboard(int key){
	//printf("\nTecla: %d" , key);
}

void keyboardUp(int key){
	//printf("\nLiberou: %d" , key);
}

void mouse(int button, int state, int wheel, int direction, int x, int y){
	mouseX = x;
	mouseY = y;
	mouseS = state;
    mBotoes->cliqueBotoes(mouseX, mouseY, mouseS);
	//printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);
}

void teste(){
    printf("\n\nDeu certo\n\n");

}

int main(void){
	CV::init(&screenWidth, &screenHeight, "Demo button manager");
    mBotoes = new ManagerBotoes(25, 100, true);
    /*mBotoes->addBotao("abc");
    mBotoes->addBotao("abc");*/
    mBotoes->addBotao("abc", teste);
	CV::run();
}
