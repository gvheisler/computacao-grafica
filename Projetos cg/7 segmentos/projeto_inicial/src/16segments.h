#include "gl_canvas2d.h"

void desenhaSegA1();
void desenhaSegA2();
void desenhaSegB();
void desenhaSegC();
void desenhaSegD1();
void desenhaSegD2();
void desenhaSegE();
void desenhaSegF();
void desenhaSegG1();
void desenhaSegG2();
void desenhaSegH();
void desenhaSegI();
void desenhaSegJ();
void desenhaSegK();
void desenhaSegL();
void desenhaSegM();

int tam = 3;
int gap = tam/10;
int halfGap = gap * 0.5 ;
int side = tam*6 + halfGap;

int linha = 3; // quanto maior mais fina a linha
int pontiagudez = tam/3; // quanto maior o divisor maenos pontiagudo

float x_h[6] = {0, pontiagudez, (tam*6)-pontiagudez, tam*6, (tam*6)-pontiagudez, pontiagudez };
float y_h[6] = {0, tam/linha, tam/linha, 0, -tam/linha, -tam/linha};
float x_v[6] = {0, -tam/linha, -tam/linha, 0, tam/linha, tam/linha };
float y_v[6] = {0, pontiagudez, (tam*6)-pontiagudez, tam*6, (tam*6)-pontiagudez, pontiagudez};


float x_h_half[6] = {0, pontiagudez, (tam*3)-pontiagudez, tam*3, (tam*3)-pontiagudez, pontiagudez };

float x_diag_dir[4] = {0,tam*3,(tam*3)+pontiagudez,pontiagudez};
float y_diag_dir[6] = {0,tam*6, (tam*6)-pontiagudez, -pontiagudez};

float x_diag_esq[4] = {0,-(tam*3),-((tam*3)+pontiagudez),-(pontiagudez)};
float y_diag_esq[4] = {0,tam*6, (tam*6)-pontiagudez, -pontiagudez};

float pontoInicialX = 0;
float pontoInicialY = 0;

int vetor[] = {0xFFFF, 0xFF0C, 0x3008, 0xEEC0, 0xFC40, 0x31C0, 0xDDC0, 0xDFC0, 0xF040, 0xFFC0, 0xFDC0, 0xF3C0, 0xFC52,
0xCF00, 0xFC12, 0xCFC0, 0xC3C0, 0xDF40, 0x33C0, 0x12, 0xCA12, 0x1B, 0xF00, 0x3328, 0x3321, 0xFF00, 0xE3C0,0xFF01,
0xE3C1, 0xDDC0, 0xC012, 0x3F00, 0x3021, 0x3305, 0x2D, 0x21C2, 0xCC0C};

void displaySevSeg(int posicaoX, int posicaoY, int posicao);

void printaFraseSevSeg(){
    displaySevSeg(100,100,0);


}

void printaTudo(){
    int pX = 50;

    for(int i = 0; i<10; i++){
        displaySevSeg(pX, 50, i);
        pX+=100;
    }
    pX = 50;
    for(int i = 10; i<20; i++){
        displaySevSeg(pX, 150, i);
        pX+=100;
    }
    pX = 50;
    for(int i = 20; i<30; i++){
        displaySevSeg(pX, 250, i);
        pX+=100;
    }
    pX = 50;
    for(int i = 30; i<36; i++){
        displaySevSeg(pX, 350, i);
        pX+=100;
    }
}

void displaySevSeg(int posicaoX, int posicaoY, int posicao){
    pontoInicialX = posicaoX;
    pontoInicialY = posicaoY;
    CV::color(1,0,0);
    if((vetor[posicao]>>15 & 1)==1)
        desenhaSegA1();
    if((vetor[posicao]>>14 & 1)==1)
        desenhaSegA2();
    if((vetor[posicao]>>13 & 1)==1)
        desenhaSegB();
    if((vetor[posicao]>>12 & 1)==1)
        desenhaSegC();
    if((vetor[posicao]>>11 & 1)==1)
        desenhaSegD1();
    if((vetor[posicao]>>10 & 1)==1)
        desenhaSegD2();
    if((vetor[posicao]>>9 & 1)==1)
        desenhaSegE();
    if((vetor[posicao]>>8 & 1)==1)
        desenhaSegF();
    if((vetor[posicao]>>7 & 1)==1)
        desenhaSegG1();
    if((vetor[posicao]>>6 & 1)==1)
        desenhaSegG2();
    if((vetor[posicao]>>5 & 1)==1)
        desenhaSegH();
    if((vetor[posicao]>>4 & 1)==1)
        desenhaSegI();
    if((vetor[posicao]>>3 & 1)==1)
    desenhaSegJ();
    if((vetor[posicao]>>2 & 1)==1)
        desenhaSegK();
    if((vetor[posicao]>>1 & 1)==1)
        desenhaSegL();
    if((vetor[posicao]>>0 & 1)==1)
        desenhaSegM();



}

void desenhaSegA1(){
    CV::translate(pontoInicialX,pontoInicialY);
    CV::polygonFill(x_h_half, y_h, 6);
}
void desenhaSegA2(){
    CV::translate(pontoInicialX+(side/2),pontoInicialY);
    CV::polygonFill(x_h_half, y_h, 6);
}
void desenhaSegB(){
    CV::translate(pontoInicialX+side,pontoInicialY+halfGap);
    CV::polygonFill(x_v, y_v, 6);
}
void desenhaSegC(){
    CV::translate(pontoInicialX+side,pontoInicialY+side+halfGap);
    CV::polygonFill(x_v, y_v, 6);
}
void desenhaSegD1(){
    CV::translate(pontoInicialX,pontoInicialY+side+side+halfGap);
    CV::polygonFill(x_h_half, y_h, 6);
}
void desenhaSegD2(){
    CV::translate(pontoInicialX+(side/2),pontoInicialY+side+side+halfGap);
    CV::polygonFill(x_h_half, y_h, 6);
}
void desenhaSegE(){
    CV::translate(pontoInicialX-halfGap,pontoInicialY+side+halfGap);
    CV::polygonFill(x_v, y_v, 6);
}
void desenhaSegF(){
    CV::translate(pontoInicialX-halfGap,pontoInicialY+halfGap);
    CV::polygonFill(x_v, y_v, 6);
}
void desenhaSegG1(){
    CV::translate(pontoInicialX,pontoInicialY+side+(halfGap*0.5));
    CV::polygonFill(x_h_half, y_h, 6);
}
void desenhaSegG2(){
    CV::translate(pontoInicialX+(side/2),pontoInicialY+side+(halfGap*0.5));
    CV::polygonFill(x_h_half, y_h, 6);
}
void desenhaSegH(){
    CV::translate(pontoInicialX+halfGap,pontoInicialY+gap+gap);
    CV::polygonFill(x_diag_dir, y_diag_dir, 4);
}
void desenhaSegI(){
    CV::translate(pontoInicialX+(side/2),pontoInicialY+halfGap);
    CV::polygonFill(x_v, y_v, 6);
}
void desenhaSegJ(){
    CV::translate(pontoInicialX+side+halfGap,pontoInicialY+gap+gap);
    CV::polygonFill(x_diag_esq, y_diag_esq, 4);
}
void desenhaSegK(){
    CV::translate(pontoInicialX+(side/2)+gap,pontoInicialY+side+gap);
    CV::polygonFill(x_diag_esq, y_diag_esq, 4);
}
void desenhaSegL(){
    CV::translate(pontoInicialX+(side/2),pontoInicialY+side+halfGap);
    CV::polygonFill(x_v, y_v, 6);
}
void desenhaSegM(){
    CV::translate(pontoInicialX+(side/2),pontoInicialY+side+gap);
    CV::polygonFill(x_diag_dir, y_diag_dir, 4);
}

