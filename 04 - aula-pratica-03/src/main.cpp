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

float xInicial = 100;
float yInicial = 100;

typedef struct point{
    float x, y;
}Point;

Point arrPontos[4];
Point arrPontosRotacionados[4];


int screenWidth = 500, screenHeight = 500;

int mouseX, mouseY;

void atualizaPontos(){
    arrPontos[0].x = xInicial;
    arrPontos[0].y = yInicial;
    arrPontos[1].x = xInicial+larg;
    arrPontos[1].y = yInicial;
    arrPontos[2].x = xInicial+larg;
    arrPontos[2].y = yInicial+alt;
    arrPontos[3].x = xInicial;
    arrPontos[3].y = yInicial+alt;
}

void desenhaQuadrado(){
    CV::color(1,0,0);
    for(int i=0; i<3; i++){
        CV::line(arrPontos[i].x, arrPontos[i].y, arrPontos[i+1].x, arrPontos[i+1].y);
    }
    CV::line(arrPontos[3].x, arrPontos[3].y, arrPontos[0].x, arrPontos[0].y);
}

void giraQuadrado15AH(){
    float grau = 0.261799;
    for(int i = 0; i<4; i++){
        float x = arrPontos[i].x;
        float y = arrPontos[i].y;
        arrPontos[i].x = (x * cos(grau)) - (y * sin(grau));
        arrPontos[i].y = (x * sin(grau)) + (y * cos(grau));
    }
}

void giraQuadrado15H(){
    float grau = 0.261799;
    for(int i = 0; i<4; i++){
        float x = arrPontos[i].x;
        float y = arrPontos[i].y;
        arrPontos[i].x = -(x * cos(grau)) + (y * sin(grau));
        arrPontos[i].y = -(x * sin(grau)) - (y * cos(grau));
    }
}

void render(){
    CV::clear(0.7,0.7,0.7);
    CV::translate(100,100);

    //Sistema cartesiano
    CV::color(0,0,1);
    CV::line(0,0,0,300);
    CV::line(0,0,300,0);
    CV::circleFill(0,0,5,10);
    //////////////////////////

    desenhaQuadrado();
}

void keyboard(int key){
    printf("\nTecla: %d" , key);
    if(key == 200){
        giraQuadrado15AH();
    }
    if(key == 202){
        giraQuadrado15H();
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
    CV::init(&screenWidth, &screenHeight, "Questao do quadrado");
    atualizaPontos();
    CV::run();
}
