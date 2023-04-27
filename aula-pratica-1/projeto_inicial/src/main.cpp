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

#include <vector>

#include "gl_canvas2d.h"

#include "circulo.h"

std::vector<Circulo*> vetor = {};

Circulo * cir = NULL;

int screenWidth = 500, screenHeight = 500;
int mouseX, mouseY;

int seleciona = 0;

int distX, distY;

int funcao = 1;

int keyUp;

bool esquerda = false, direita = false, cima = false, baixo = false;

int xC, yC;

void renderizaCirculos(){
    for(c : vetor){
        c->render();
    }
}

void DrawMouseScreenCoords(){
	 char str[100];
	 sprintf(str, "Mouse: (%d,%d)", mouseX, mouseY);
	 CV::text(10,300, str);
	 sprintf(str, "Screen: (%d,%d)", screenWidth, screenHeight);
	 CV::text(10,320, str);
}

void render(){
	CV::clear(0,0,0);
	//CV::text(20,200,"Aula pratica 01");
	//DrawMouseScreenCoords();
	renderizaCirculos();
	if(esquerda){
        vetor[0]->x--;
	}
	if(direita){
        vetor[0]->x++;
	}
	if(cima){
        vetor[0]->y++;
	}
	if(baixo){
        vetor[0]->y--;
	}
}

void keyboard(int key){
	printf("\nTecla: %d" , key);
    if(key == 200){
        esquerda = true;
	}
    if(key == 201){
        cima = true;
	}
	if(key == 202){
        direita = true;
	}
	if(key == 203){
        baixo = true;
	}
}

void keyboardUp(int key){
	//printf("\nLiberou: %d" , key);
	keyUp = key;
	if(key == 200){
        esquerda = false;
	}
    if(key == 201){
        cima = false;
	}
	if(key == 202){
        direita = false;
	}
	if(key == 203){
        baixo = false;
	}
}

void mouse(int button, int state, int wheel, int direction, int x, int y){
	mouseX = x;
	mouseY = y;
	if(funcao == 1){
        if(state==1){
            cir = new Circulo(x, y, 100);
            vetor.push_back(cir);
            funcao = 2;
        }
	}
	else if(funcao != 1){
        if((pow((vetor[0]->x - x),2)+pow((vetor[0]->y - y),2)) < pow(vetor[0]->raio,2)&&state==0){
            distX = vetor[0]->x - x;
            distY = vetor[0]->y - y;
            seleciona = 1;
        }
        if(state==1){
            seleciona = 0;
        }
	}
	if(seleciona == 1){
        vetor[0]->x = x + distX;
        vetor[0]->y = y + distY;
	}
	//printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);
}

int main(void){
	CV::init(&screenWidth, &screenHeight, "Aula pratica 01");
	CV::run();
}
