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

#include "gl_canvas2d.h"

int screenWidth = 500, screenHeight = 500;
int mouseX, mouseY;

void DrawMouseScreenCoords(){
	 char str[100];
	 sprintf(str, "Mouse: (%d,%d)", mouseX, mouseY);
	 CV::text(10,300, str);
	 sprintf(str, "Screen: (%d,%d)", screenWidth, screenHeight);
	 CV::text(10,320, str);
}

void render(){
	CV::clear(0,0,0);
	CV::text(20,500,"Programa Demo Canvas2D");
	DrawMouseScreenCoords();
}

void keyboard(int key){
	printf("\nTecla: %d" , key);
}

void keyboardUp(int key){
	printf("\nLiberou: %d" , key);
}

void mouse(int button, int state, int wheel, int direction, int x, int y){
	mouseX = x;
	mouseY = y;

	printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);
}

int main(void){
	CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
	CV::run();
}
