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
#include "Vector3.h"
#include "Vector2.h"

int screenWidth = 500, screenHeight = 500;

int mouseX, mouseY;

Vector3 v[8];

float d = 50;

Vector2 pontos2d[8];

float rot = 0;

void render(){
    CV::clear(0.7,0.7,0.7);
    CV::translate(screenWidth/2, screenHeight/2);
    CV::color(1,0,0);

    for(int i = 0; i<8; i++){
      float x = (v[i].x * d)/v[i].z;
      float y = (v[i].y * d)/v[i].z;
      Vector2 aux;
      aux.x = x;
      aux.y = y;
      pontos2d[i] = aux;
      CV::circleFill(x, y, 3, 10);
    }
   CV::color(0,0,0);
    for(int i = 0; i<8; i++){
      for(int j = 0; j<8; j++){
         int var = 0;
         if(v[i].x==v[j].x){
            var++;
         }
         if(v[i].y==v[j].y){
            var++;
         }
         if(v[i].z==v[j].z){
            var++;
         }
         if(var==2){
            CV::color(i);
            CV::line(pontos2d[i].x, pontos2d[i].y, pontos2d[j].x, pontos2d[j].y);
         }
      }
    }

}

void keyboard(int key){
    printf("\nTecla: %d" , key);
    switch(key){
      case 115:
         d-=10;
         break;
      case 119:
         d+=10;
         break;
      case 97:
         rot+= 10 *(PI/180);
         break;
      case 100:
         rot+= 10 * (PI/180);
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
    v[0].set(-1,1,1);
    v[1].set(1,1,1);
    v[2].set(1,-1,1);
    v[3].set(-1,-1,1);
    v[4].set(-1,1,-1);
    v[5].set(1,1,-1);
    v[6].set(1,-1,-1);
    v[7].set(-1,-1,-1);
    for(int i = 0; i<8; i++){
      v[i] = v[i]*100;
    }
    for(int i = 0; i<8; i++){
      v[i].z += 200;
    }
    CV::run();
}
