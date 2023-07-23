
#include "gl_canvas2d.h"

#include <stdio.h>

class FormaGeometrica{
protected:
   int x, y, cor;
   float raio;
   float rotacao;
public:
   FormaGeometrica(int _x, int _y, int _cor, float _raio){
      x = _x,
      y = _y;
      cor = _cor;
      rotacao = 0;
      raio = _raio;
   }
   virtual void RenderForma(){};
   virtual void RenderCaixaSelecao(){};
   virtual bool ColisaoForma(int mouseX, int mouseY){};
   virtual void RotacionaFormaH(){};
   virtual void RotacionaFormaAH(){};
   void aumenta5(){
      raio+=5;
   }
   void diminui5(){
      raio-=5;
   }
};


class Quadrado : public FormaGeometrica{
public:
   Quadrado(int x, int y, int cor, float _largura):FormaGeometrica(x, y, cor, _largura){
      rotacao = 45 * (PI/180);
   }

   void RenderForma(){
      CV::color(cor);
      CV::circleFill(x, y, raio, 4, rotacao);
   }

   void RenderCaixaSelecao(){
      CV::color(cor+1);
      CV::circleFill(x, y, raio+5, 4, rotacao);
      //CV::circle(x, y, raio, 30, rotacao);
   }

   bool ColisaoForma(int mouseX, int mouseY){
      //if(rotacao==0||rotacao==90||rotacao==180||rotacao==270)
      /*int mXrot = mouseX * (cos(rotacao)) - y * (sin(rotacao));
      int mYrot = mouseX * (sin(rotacao)) + y * (cos(rotacao));*/
      /*int rotacaoAtual = rotacao * (PI/180);
      if(rotacaoAtual%45==0){
         if(mouseX>=(x-raio)&&mouseX<=(x+raio)&&mouseY>=(y-raio)&&mouseY<=(y+raio)){
            return true;
         }else{
            return false;
         }
      }*/
      if((pow((x - mouseX),2)+pow((y - mouseY),2)) < pow(raio,2)){
         return true;
      }else{
         return false;
      }
   }
   void RotacionaFormaH(){
      rotacao+=2*(PI/180);
   }
   void RotacionaFormaAH(){
      rotacao-=2*(PI/180);
   }
};

class Circulo : public FormaGeometrica{
public:
   Circulo(int x, int y, int cor, float _raio):FormaGeometrica(x, y, cor, _raio){
      rotacao = 0;
   }

   void RenderForma(){
      CV::color(cor);
      CV::circleFill(x, y, raio, 30, rotacao);
   }

   void RenderCaixaSelecao(){
      CV::color(cor+1);
      CV::circleFill(x, y, raio+5, 30, rotacao);
   }

   bool ColisaoForma(int mouseX, int mouseY){
      if((pow((x - mouseX),2)+pow((y - mouseY),2)) < pow(raio,2)){
         return true;
      }else{
         return false;
      }
   }
   void RotacionaFormaH(){
      rotacao+=2*(PI/180);
   }
   void RotacionaFormaAH(){
      rotacao-=2*(PI/180);
   }
};

class Triangulo : public FormaGeometrica{
public:
   Triangulo(int x, int y, int cor, float _raio):FormaGeometrica(x, y, cor, _raio){
      rotacao = 0;
   }

   void RenderForma(){
      CV::color(cor);
      CV::circleFill(x, y, raio, 3, rotacao);
   }

   void RenderCaixaSelecao(){
      CV::color(cor+1);
      CV::circleFill(x, y, raio+5, 3, rotacao);
   }

   bool ColisaoForma(int mouseX, int mouseY){
      if((pow((x - mouseX),2)+pow((y - mouseY),2)) < pow(raio,2)){
         return true;
      }else{
         return false;
      }
   }
   void RotacionaFormaH(){
      rotacao+=2*(PI/180);
   }
   void RotacionaFormaAH(){
      rotacao-=2*(PI/180);
   }
};


class NAgono : public FormaGeometrica{
      int lados = 5;
public:
   NAgono(int x, int y, int cor, float _raio, int _lados):FormaGeometrica(x, y, cor, _raio){
      rotacao = 0;
      lados = _lados;
   }

   void RenderForma(){
      CV::color(cor);
      CV::circleFill(x, y, raio, lados, rotacao);
   }

   void RenderCaixaSelecao(){
      CV::color(cor+1);
      CV::circleFill(x, y, raio+5, lados, rotacao);
   }

   bool ColisaoForma(int mouseX, int mouseY){
      if((pow((x - mouseX),2)+pow((y - mouseY),2)) < pow(raio,2)){
         return true;
      }else{
         return false;
      }
   }
   void RotacionaFormaH(){
      rotacao+=2*(PI/180);
   }
   void RotacionaFormaAH(){
      rotacao-=2*(PI/180);
   }
};
