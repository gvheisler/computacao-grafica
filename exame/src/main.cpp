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
#include "frames.h"

Frames * frames = NULL;

int screenWidth = 500, screenHeight = 500;

int mouseX, mouseY;

float raio = 100, raio2 = 120;

int divisoes = 20;

float angInicial = 0;

float fps;

float velocidade = 1;

float angulo_inicial = 0.0;

std::vector<Vector2> pontos;

void render(){
    CV::clear(1,1,1);
    CV::translate(screenWidth/2, screenHeight/2);
    fps = frames->getFrames();
    CV::color(0,1,0);
    pontos.clear();
    for(float ang = angInicial; ang<PI_2+angInicial; ang+=PI_2/divisoes){
        Vector2 p;
        p.x = raio * cos(ang);
        p.y = raio * sin(ang);
        pontos.push_back(p);
        p.x = raio2 * cos(ang);
        p.y = raio2 * sin(ang);
        pontos.push_back(p);
    }
    angInicial-=velocidade * (1/fps);
    for(int i = 0; i<pontos.size()-1; i++){
        CV::line(pontos[i].x, pontos[i].y, pontos[i+1].x, pontos[i+1].y);
    }
    CV::line(pontos[pontos.size()-1].x, pontos[pontos.size()-1].y, pontos[0].x, pontos[0].y);
   }



void keyboard(int key){
    //printf("\nTecla: %d" , key);
    switch(key){
    case 43:
        velocidade+=0.1;
        break;
    case 45:
        velocidade-=0.1;
        break;
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
    frames = new Frames();
    CV::run();
}
