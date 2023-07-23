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

#include "gl_canvas2d.h"

int screenWidth = 500, screenHeight = 500;

int mouseX, mouseY;

float angInicial = 0.0;
void render(){
    CV::translate(screenWidth/2,screenHeight/2);
    CV::clear(0.7,0.7,0.7);
    CV::color(1,0,0);
    float raio = 0;
    float ang = 0;
    for(int i = 0; i<2000; i++){
        float x = raio * cos(ang+angInicial);
        float y = raio * sin(ang+angInicial);
        CV::circleFill(x,y, 2, 5);
        raio+=0.1;
        ang -= 0.01;
    }
    angInicial-=0.01;
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

    //printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);
}

int main(void){
    CV::init(&screenWidth, &screenHeight, "Programa demo");
    CV::run();
}
