#ifndef __BOTAO_H__
#define __BOTAO_H__

#include "gl_canvas2d.h"

#include <functional>

class Botao{
  float altura, largura, x, y;
  char label[100];
  int corB, corT;
  bool clicado, sobMouse;
  int cont;

  std::function<void()> funcao;
  //gerencia botoes selecionados em um vetor(?) contador de bottoes é posição dele e 1 é selecionado

public:
  Botao(float _x, float _y, float _larg, float _alt, int _corB, int _corT, char *_label, std::function<void()> _funcao)
  {
     altura  = _alt;
     largura = _larg;
     x = _x;
     y = _y;
     corB = _corB;
     corT = _corT;
     strcpy(label, _label);
     clicado = false;
     sobMouse = false;
     funcao = _funcao;
  }

  void Render(int mx, int my, int mb, int ms) //receber lista c os botoes
  {
      if(!Colidiu(mx, my, mb, ms)){
        CV::color(corB);
        CV::rectFill(x, y, x + largura, y + altura);
        CV::color(corT);
        CV::text(x+5, y+altura/2, label);
      }
      else{
        CV::color(1,1,1);
        CV::rectFill(x, y, x + largura, y + altura);
        CV::color(corB);
        CV::text(x+5, y+altura/2, label);
      }
      if(clicado){
        CV::color(1,0,0);
        CV::rectFill(x, y, x + largura, y + altura);
      }
  }

  //recebe as coordenadas do mouse para tratar clique ou detectar quando o mouse esta em cima do botao
   bool Colidiu(int mx, int my, int mb, int ms)
  {
      if( mx >= x && mx <= (x + largura) && my >= y && my <= (y + altura) )
      {
          sobMouse = true;
          if(mb == 0 && ms == 0)
            {
               clicado = true;
            } else {
               clicado = false;
            }
          return true;
      }
      else{
        sobMouse = false;
      }
      return false;
  }

  void Clicou(int mx, int my, int mb, int ms)
  {
      if( mx >= x && mx <= (x + largura) && my >= y && my <= (y + altura))
      {
          if(mb == 0 && ms == 0)
            {
               funcao();
            }
      }
  }

};
#endif
