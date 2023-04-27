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
// *********************************************************************/

#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "gl_canvas2d.h"
#include "quadrado.h"

int screenWidth = 500, screenHeight = 500;

int mouseX, mouseY;

Quadrado * figura = NULL;
Quadrado * figuraOriginal = NULL;

void render(){
    CV::clear(0.7,0.7,0.7);
    CV::translate(100,100);
    //Sistema cartesiano
    CV::color(0,0,1);
    CV::line(0,0,0,300);
    CV::line(0,0,300,0);
    CV::circleFill(0,0,5,10);
    //////////////////////////

    CV::color(1,1,0);
    figuraOriginal->render();
    CV::color(1,0,0);
    figura->render();
}

void keyboard(int key){
    //printf("\nTecla: %d" , key);
    if(key == 200){
        figura->rotaciona(60);
    }
    if(key == 203){
        figura->escala(0.6);
    }
}

void keyboardUp(int key){
    //printf("\nLiberou: %d" , key);
}

void mouse(int button, int state, int wheel, int direction, int x, int y){
    mouseX = x;
    mouseY = y;

    //printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);
}

int main(void){
    CV::init(&screenWidth, &screenHeight, "Programa demo");
    figuraOriginal = new Quadrado(100,100,100,100);

    figura = new Quadrado(100,100,100,100);
    figura->translada(-100,-100);
    figura->escala(0.6);
    figura->rotaciona(150);
    figura->destranslada();
    CV::run();
}
