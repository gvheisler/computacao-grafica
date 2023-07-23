
#include "gl_canvas2d.h"

#include <stdio.h>

class FormaGeometrica{
public:
   int x, y, cor;
   float raio;
   float rotacao;

   FormaGeometrica(int _x, int _y, int _cor, float _raio){
      x = _x,
      y = _y;
      cor = _cor;
      rotacao = 0;
      raio = _raio;
   }
   FormaGeometrica(int _x, int _y, int _cor, float _raio, float _rotacao){
      x = _x,
      y = _y;
      cor = _cor;
      rotacao = _rotacao;
      raio = _raio;
   }
   virtual void RenderForma(){};
   virtual void RenderCaixaSelecao(){};
   virtual bool ColisaoForma(int mouseX, int mouseY){};
   virtual void RotacionaFormaH(){};
   virtual void RotacionaFormaAH(){};
   virtual void atualizaCor(int rgb){};
   void aumenta5(){
      raio+=5;
   }
   void diminui5(){
      raio-=5;
   }
   void moverComMouse(int mouseX, int mouseY, int distanciaX, int distanciaY){
      x = mouseX-distanciaX;
      y = mouseY-distanciaY;
   }
};


class Quadrado : public FormaGeometrica{
public:
   Quadrado(int x, int y, int cor, float _largura):FormaGeometrica(x, y, cor, _largura){
      rotacao = 45 * (PI/180);
   }

   Quadrado(int x, int y, int cor, float _largura, float _rotacao):FormaGeometrica(x, y, cor, _largura, _rotacao){
      rotacao = _rotacao;
   }


   void RenderForma(){
      CV::color(cor);
      CV::circleFill(x, y, raio, 4, rotacao);
   }

   void RenderCaixaSelecao(){
      CV::color(cor+1);
      CV::circleFill(x, y, raio+5, 4, rotacao);
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
   void atualizaCor(int rgb){
      cor = rgb;
   }
};

class Circulo : public FormaGeometrica{
public:
   Circulo(int x, int y, int cor, float _raio):FormaGeometrica(x, y, cor, _raio){
      rotacao = 0;
   }
   Circulo(int x, int y, int cor, float _raio, float _rotacao):FormaGeometrica(x, y, cor, _raio, _rotacao){
      rotacao = _rotacao;
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
   void atualizaCor(int rgb){
      cor = rgb;
   }
};

class Triangulo : public FormaGeometrica{
public:
   Triangulo(int x, int y, int cor, float _raio):FormaGeometrica(x, y, cor, _raio){
      rotacao = 0;
   }
   Triangulo(int x, int y, int cor, float _raio, float _rotacao):FormaGeometrica(x, y, cor, _raio, _rotacao){
      rotacao = _rotacao;
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
   void atualizaCor(int rgb){
      cor = rgb;
   }
};


class NAgono : public FormaGeometrica{
public:
   int lados = 5;
   NAgono(int x, int y, int cor, float _raio, int _lados):FormaGeometrica(x, y, cor, _raio){
      rotacao = 0;
      lados = _lados;
   }
   NAgono(int x, int y, int cor, float _raio, float _rotacao, int _lados):FormaGeometrica(x, y, cor, _raio, _rotacao){
      rotacao = _rotacao;
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
   void atualizaCor(int rgb){
   cor = rgb;
   }
};
