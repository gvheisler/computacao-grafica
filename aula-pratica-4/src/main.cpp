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

int screenWidth = 500, screenHeight = 500;

int mouseX, mouseY;

float posNave = 0.0f;

Vector2 vetorPontos[4];

bool frente, tras;

void plotaBlendingBSpline(){
    CV::color(0,0,1);
    CV::rect(0,0, 200,200);
    float asix = (1.0f/6.0f);
    for(float t = 0; t<1; t+=0.01){
        float y = asix*((1.0f-t)*(1.0f-t)*(1.0f-t));
        //float y = asix*(1.0f-(t*t*t));
        CV::circleFill(t*200, y*200, 1, 5);
    }
    for(float t = 0; t<1; t+=0.01){
        float y = asix * ((3*(t*t*t))-(6*(t*t))+4);
        CV::circleFill(t*200, y*200, 1, 5);
    }
    for(float t = 0; t<1; t+=0.01){
        float y = asix * ((-3*(t*t*t)) + (3*(t*t)) + (3*t) + 1 );
        CV::circleFill(t*200, y*200, 1, 5);
    }
    for(float t = 0; t<1; t+=0.01){
        float y = asix * (t*t*t);
        CV::circleFill(t*200, y*200, 1, 5);
    }
}

void plotaBlendingBezier(){
    CV::color(1,0,0);
    CV::rect(0,0, 200,200);
    for(float t = 0; t<1; t+=0.01){
        float y = (1-t)*(1-t)*(1-t);
        CV::circleFill(t*200, y*200, 1, 5);
    }
    for(float t = 0; t<1; t+=0.01){
        float y = (3*t)*((1-t)*(1-t));
        CV::circleFill(t*200, y*200, 1, 5);
    }
    for(float t = 0; t<1; t+=0.01){
        float y = 3 * (t*t) *(1-t);
        CV::circleFill(t*200, y*200, 1, 5);
    }
    for(float t = 0; t<1; t+=0.01){
        float y = t*t*t;
        CV::circleFill(t*200, y*200, 1, 5);
    }
}

void plotaPontosControle(){
    for(int i = 0; i<4; i++){
        CV::color(0,0,1);
        CV::circleFill(vetorPontos[i].x, vetorPontos[i].y, 5, 10);
        if(i<3)
            CV::line(vetorPontos[i].x, vetorPontos[i].y, vetorPontos[i+1].x, vetorPontos[i+1].y);
    }
    CV::line(vetorPontos[3].x, vetorPontos[3].y, vetorPontos[0].x, vetorPontos[0].y);
}

void plotaCurva3(){
    for(float t = 0; t<1; t+=0.01){
        CV::color(0,0.5,0);
        float xt = (vetorPontos[0].x * (1 - (t*t))) + (vetorPontos[1].x * (2*t * (1-t))) + (vetorPontos[2].x * (t*t));
        float yt = (vetorPontos[0].y * (1 - (t*t))) + (vetorPontos[1].y * (2*t * (1-t))) + (vetorPontos[2].y * (t*t));
        CV::circleFill(xt, yt, 1, 5);
    }
}

void plotaCurva4(){
    for(float t = 0; t<1; t+=0.01){
        CV::color(0,0.5,0);
        float xt = (vetorPontos[0].x * ((1-t)*(1-t)*(1-t))) + (vetorPontos[1].x * (3*t * ((1-t)*(1-t)))) + (vetorPontos[2].x * (3*(t*t))*(1-t)) + (vetorPontos[3].x * (t*t*t));
        float yt = (vetorPontos[0].y * ((1-t)*(1-t)*(1-t))) + (vetorPontos[1].y * (3*t * ((1-t)*(1-t)))) + (vetorPontos[2].y * (3*(t*t))*(1-t)) + (vetorPontos[3].y * (t*t*t));
        CV::circleFill(xt, yt, 1, 5);
    }
}

Vector2 avaliaBezier(float t){
    float xt = (vetorPontos[0].x * ((1-t)*(1-t)*(1-t))) + (vetorPontos[1].x * (3*t * ((1-t)*(1-t)))) + (vetorPontos[2].x * (3*(t*t))*(1-t)) + (vetorPontos[3].x * (t*t*t));
    float yt = (vetorPontos[0].y * ((1-t)*(1-t)*(1-t))) + (vetorPontos[1].y * (3*t * ((1-t)*(1-t)))) + (vetorPontos[2].y * (3*(t*t))*(1-t)) + (vetorPontos[3].y * (t*t*t));
    return Vector2(xt, yt);
}

void desenhaNave(){
    Vector2 p1 = avaliaBezier(posNave);
    Vector2 p2 = avaliaBezier(posNave+0.01);
    Vector2 p3 = p2-p1;
    p3.normalize();
    CV::color(0,0,1);
    Vector2 p4 = p3*30;
    p4 = p1+p4;
    CV::line(p1.x, p1.y, p4.x, p4.y);

}

void render(){
    if(frente){
        posNave+=0.001;
    }
    if(tras){
        posNave-=0.001;
    }

    CV::clear(0.7,0.7,0.7);
    CV::translate(100,100);
    //plotaPontosControle();
    plotaCurva4();
    desenhaNave();
    //plotaBlendingBSpline();
    //plotaBlendingBezier();
}

void keyboard(int key){
    //printf("\nTecla: %d" , key);
    switch(key){
    case 202:
        frente = true;
        break;
    case 200:
        tras = true;
        break;
    }
}

void keyboardUp(int key){
    //printf("\nLiberou: %d" , key);
    switch(key){
    case 202:
        frente = false;
        break;
    case 200:
        tras = false;
        break;
    }
}

void mouse(int button, int state, int wheel, int direction, int x, int y){
    mouseX = x;
    mouseY = y;

    //printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);
}

int main(void){
    CV::init(&screenWidth, &screenHeight, "Aula pratica 4");
    vetorPontos[0] = Vector2(50,0);
    vetorPontos[1] = Vector2(0,100);
    vetorPontos[2] = Vector2(200,100);
    vetorPontos[3] = Vector2(300,0);
    CV::run();
}
