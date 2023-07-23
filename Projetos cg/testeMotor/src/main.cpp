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

/*float meioX = 0, meioY = 0;

float raio = 25;

float angulo = 0;

float tamlinha = 100;*/

float distanciaEuclidiana(float x1, float y1, float x2, float y2){
    float d = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    return d;
}


/*void render(){
    CV::translate(screenWidth/2, screenHeight/2);
    CV::clear(0.7,0.7,0.7);
    CV::color(0,0,0);
    CV::circle(meioX,meioY,raio,50);

    float xC = meioX + (raio * 2 * cos(angulo));
    float yC = meioY + (raio * 2 * sin(angulo));

    CV::color(1,0,0);
    CV::circleFill(xC, yC, raio/10, 20);
    CV::circle(xC, yC, raio, 20);
    CV::color(0,0,1);

    float xT = meioX;
    float yT = meioY + sqrt((100*100)-((cos(angulo)*(raio*2))*(cos(angulo)*(raio*2)))) + (sin(angulo)*(raio*2));

    CV::line(xC, yC, xT, yT);
    angulo+= 0.5 * (PI/180);

    printf("Distancia = %.2f\n", distanciaEuclidiana(xC, yC, xT, yT));


}*/

float raio = 15;

float angAtual = 0;

void render(){
    CV::translate(screenWidth/2, screenHeight/2);
    CV::clear(0.7,0.7,0.7);
    CV::color(0,0,0);
    CV::circle(0,0,raio, 50);
    CV::color(0,0,1);
    float xManivela = (raio*2) * cos(angAtual);
    float yManivela = (raio*2) * sin(angAtual);
    CV::circleFill(xManivela, yManivela, 3, 15);
    CV::circle(xManivela, yManivela, raio, 50);
    angAtual += 0.1 * (PI/180);

    float xFinal = 0;
    float yFinal = 0 + sqrt((100*100)-((cos(angAtual)*(raio*2))*(cos(angAtual)*(raio*2)))) + (sin(angAtual)*(raio*2));




    CV::line(xManivela, yManivela, xFinal, yFinal);
    CV::line(xFinal-20, yFinal, xFinal+20 ,yFinal);

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
