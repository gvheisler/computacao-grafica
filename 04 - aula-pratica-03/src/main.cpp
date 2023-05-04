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

float larg = 100;
float alt = 100;

float x = 100;
float y = 100;

typedef struct point{
    float x, y;
}Point;

Point arrPontos[4];
Point arrPontosRotacionados[4];


int screenWidth = 500, screenHeight = 500;

int mouseX, mouseY;

void atualizaPontos(){
    arrPontos[0].x = x;
    arrPontos[0].y = y;
    arrPontos[1].x = x+larg;
    arrPontos[1].y = y;
    arrPontos[2].x = x+larg;
    arrPontos[2].y = y+alt;
    arrPontos[3].x = x;
    arrPontos[3].y = y+alt;
}

void desenhaQuadrado(){
    CV::color(1,0,0);
    for(int i=0; i<3; i++){
        CV::line(arrPontos[i].x, arrPontos[i].y, arrPontos[i+1].x, arrPontos[i+1].y);
    }
    CV::line(arrPontos[3].x, arrPontos[3].y, arrPontos[0].x, arrPontos[0].y);
}

void render(){
    CV::clear(0.7,0.7,0.7);
    CV::translate(100,100);
    atualizaPontos();
    //Sistema cartesiano
    CV::color(0,0,1);
    CV::line(0,0,0,300);
    CV::line(0,0,300,0);
    CV::circleFill(0,0,5,10);
    //////////////////////////

    desenhaQuadrado();
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
    CV::init(&screenWidth, &screenHeight, "Questao do quadrado");
    CV::run();
}
