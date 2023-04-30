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
#include "penduloManager.h"

int screenWidth = 500, screenHeight = 500;

int mouseX, mouseY;

PenduloManager * pendulos = NULL;

void render(){
    CV::clear(0.7,0.7,0.7);
    CV::translate(screenWidth/2, screenHeight/2);
    CV::color(0,0,0);
    CV::rectFill(-1,0,1,-screenHeight);
    pendulos->render();
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
    pendulos = new PenduloManager(0,0);
    for(int i = 15; i<150; i+=15){
        pendulos->addPendulo(i);
    }

    CV::run();
}
