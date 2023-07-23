
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#include "gl_canvas2d.h"

class Imagem{
   int tipo, cor, preenche;
   int mX, mY;
   bool sobMouse;
   bool selecionada;
   int raio = 30;
   int div = 100;

//fazer herança pra cada tipo de img
// fazer função drag (arrastar imagem selecionada)
// mover imagem por meio do teclado

public:
   Imagem(int _tipo, int _cor, bool _preenche, int _mX, int _mY, bool _selecionada)
   {
      cor = _cor;
      preenche = _preenche;
      tipo = _tipo;
      selecionada = _selecionada;
      mX = _mX;
      mY = _mY;
   }
   //funcao para pegar coordenadas para img
   //clica inicio e solta fim matriz contendo a img
   //cria c botao esquerdo
   //seleciona c o batao direito
//bool selecao_img(int mouseX, int mouseY, int mb, int ms);
//void edita_img();
/*
      void seleciona_img();
      void edita(int cont);
      void deleta(int cont);
      void rotaciona();
*/

   void renderImg(){
      CV::color(1,0,0);
      switch(tipo)
         {
            case 1:
               //CV::line(xI,yI,xF,yF);
               break;
            case 2:
               if(preenche){
                  CV::rectFill(mX, mY, mX+raio, mY+raio);
                  break;
               }
               CV::rect(mX, mY, mX+raio, mY+raio);
               break;
            case 3:
               if(preenche){
                  //CV::circleFill(mX, mY, raio, div);
                  break;
               }
               //CV::circle(mX, mY, raio, div);
               break;
         }

        // if(selecao_img()){
          //     edita_img();
         //}
   }

/*   void edita_img(){
      while(selecionada && mState!=1){
                  mX = mouseX;
                  mY = mouseY;

   }


   bool selecao_img(int mouseX, int mouseY, int mb, int ms)
  {
      if( mouseX >= mX && mX <= (mX + raio) && mouseY >= mY && mouseY <= (mY + raio) )
      {
          sobMouse = true;
          CV::color(0, 1, 0);
          CV::rect(mX, mY, mX+raio, mY+raio);
          if(mb== 0 && ms == 0)
            {
               selecionada = true;
               CV::color(0,0,1);
               CV::rect(mX, mY, mX+raio, mY+raio);
               }
            } else {
               selecionada = false;
            }
          return true;
      }
      else{
        sobMouse = false;
      }
      return false;
  }*/

};
