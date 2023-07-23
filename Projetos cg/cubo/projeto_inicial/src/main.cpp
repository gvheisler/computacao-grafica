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

int x1 = 100;
int y1 = 100;

int x2 = 150;
int y2 = 150;

int largura = 100;
int altura = 100;

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
	//DrawMouseScreenCoords();

	CV::color(1,1,1);
    CV::line(x1, y1,x1, y1+altura);
    CV::line(x1, y1,x1+largura, y1);
    CV::line(x1, y1+altura,x1+largura, y1+altura);
    CV::line(x1+largura, y1+altura,x1+largura, y1);

    CV::line(x2, y2,x2, y2+altura);
    CV::line(x2, y2,x2+largura, y2);
    CV::line(x2, y2+altura,x2+largura, y2+altura);
    CV::line(x2+largura, y2+altura,x2+largura, y2);

    CV::line(x1, y1,x2, y2);
    CV::line(x1+largura, y1,x2+largura, y2);
    CV::line(x1, y1+altura,x2, y2+altura);
    CV::line(x1+largura, y1+altura,x2+largura, y2+altura);
}

void keyboard(int key){
	//printf("\nTecla: %d" , key);
}

void keyboardUp(int key){
	printf("\nLiberou: %d" , key);
	switch(key){
        case 201:
            x2+=5;
            y2+=5;
            break;
        case 203:
            x2-=5;
            y2-=5;
            break;
        case 202:
            largura+=5;
            altura+=5;
            break;
        case 200:
            largura-=5;
            altura-=5;
            break;
        case 97:
            x1-=5;
            x2+=5;
            break;
        case 100:
            x1+=5;
            x2-=5;
            break;
        case 119:
            y1+=5;
            y2-=5;
            break;
        case 115:
            y1-=5;
            y2+=5;
            break;
    }
}

void mouse(int button, int state, int wheel, int direction, int x, int y){
	mouseX = x;
	mouseY = y;

	//printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);
}

int main(void){
	CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
	CV::run();
}
