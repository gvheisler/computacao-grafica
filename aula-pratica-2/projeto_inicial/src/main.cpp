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
#include <math.h>

#include "gl_canvas2d.h"

int screenWidth = 1000, screenHeight = 600;
int mouseX, mouseY;

float raio = 100;
float ang = 0;

float x, y, x1, y1;

float angInicial = 0;

void espiral(){

    CV::translate(screenWidth/2,screenHeight/2);
    CV::color(1,0,0);
    //CV::line(0,0, x, y);
    //printf("x = %f, y = %f\n", x, y);
    raio = 0;

    for(ang = angInicial; ang<10*PI; ang+=0.01){
        raio=raio+0.1;
        x = raio*cos(ang);
        y = raio*sin(ang);
        CV::circleFill(x,y,2,5);
    }
    angInicial+=0.01;
}

void espiralContrario(){

    CV::translate(screenWidth/2,screenHeight/2);
    CV::color(0,1,1);
    raio = 0;
    angInicial = 10*PI;
    for(ang = 10*PI; ang>0; ang-=0.01){
        raio=raio+0.1;
        x = raio*cos(ang);
        y = raio*sin(ang);
        CV::circleFill(x,y,2,5);
    }
    angInicial-=0.01;
}

void ponteiros(){

    CV::translate(screenWidth/2,screenHeight/2);
    CV::color(1,0,0);

    for(ang = angInicial; ang<2*PI; ang+=PI/6){
        x1 = (raio-20)*cos(ang);
        y1 = (raio-20)*sin(ang);
        x = raio*cos(ang);
        y = raio*sin(ang);
        CV::line(x1,y1,x,y);
    }
}


void circulo(){
    CV::translate(screenWidth/2,screenHeight/2);
    CV::color(1,0,0);

    for(ang = angInicial; ang<2*PI; ang+=0.01){
        x = raio*cos(ang);
        y = raio*sin(ang);
        CV::circleFill(x, y, 2, 5);
    }
}

float modulo;
float xNorm, yNorm;
float anguloNorm;

char str[20];
void segueMouse(){
    CV::translate(0,0);
    CV::color(1,0,0);
    //CV::line(0,0,mouseX, mouseY);
    modulo = sqrt(pow(mouseX, 2)+pow(mouseY,2));
    xNorm = 500*(mouseX/modulo);
    yNorm = 500*(mouseY/modulo);
    CV::line(0,0,xNorm, yNorm);
    anguloNorm = atan(yNorm/xNorm);
    anguloNorm = anguloNorm * (180/PI);
    sprintf(str, "Angulo = %f", anguloNorm);
    CV::text(100, 500, str);
}

void segueMouseMeio(){
    CV::translate(screenWidth/2,screenHeight/2);
    CV::color(1,0,0);
    //CV::line(0,0,mouseX, mouseY);
    modulo = sqrt(pow(mouseX, 2)+pow(mouseY,2));
    if(mouseX<screenWidth/2){
        xNorm = 100*(-mouseX/modulo);
    }else{
        xNorm = 100*(mouseX/modulo);
    }
    if(mouseY<screenHeight/2){
        yNorm = 100*(-mouseY/modulo);
    }else{
        yNorm = 100*(mouseY/modulo);
    }

    CV::line(0,0,xNorm, yNorm);
    anguloNorm = atan(yNorm/xNorm);
    anguloNorm = anguloNorm * (180/PI);
    sprintf(str, "Angulo = %f", anguloNorm);

    CV::text(-50, 100, str);
}

void render(){
	CV::clear(0,0,0);
    circulo();
    ponteiros();
    segueMouse();
    //segueMouseMeio();
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
	CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
	CV::run();

}
