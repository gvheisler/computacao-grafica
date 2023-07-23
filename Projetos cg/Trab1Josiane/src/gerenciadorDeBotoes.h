#include "Botao.h"

#include <functional>

// manager de botoes
class ManagerBt{

   int Xi, Yi, intervaloBt;
   std::vector<Botao*> vetor = {};
   bool coluna;

   int alturaBt = 30;
   int larguraBt = 100;
   int borda = 4;
   int corB, corT;

public:
   //cria botoes em coluna
   ManagerBt(bool _coluna, int _Xi, int _Yi, int _corB, int _corT){
      coluna = _coluna;
      Xi = _Xi;
      Yi = _Yi;
      corB = _corB;
      corT = _corT;
      intervaloBt = alturaBt + (alturaBt/4);
   }
   //cria botoes lateralmente
   ManagerBt(int _Xi, int _Yi, int _corB, int _corT){
      coluna = false;
      Xi = _Xi;
      Yi = _Yi;
      corB = _corB;
      corT = _corT;
      intervaloBt = larguraBt + (larguraBt/4);
   }

   //adiciona novo botao
   void addBotao(char * label, std::function<void()> funcao){
      if(coluna == true){
         vetor.push_back(new Botao(Xi, Yi+(intervaloBt*vetor.size()), larguraBt, alturaBt, corB, corT, label, funcao));
      }else{
         vetor.push_back(new Botao(Xi+(intervaloBt*vetor.size()), Yi, larguraBt+10, alturaBt, corB, corT, label, funcao));
      }


   }

   //funcao para renderizar todos os botoes
   void renderMngB(int mx, int my, int mb, int ms){
      for(Botao * b : vetor){
         b->Render(mx, my, mb, ms);
      }
   }

   // checa o clique em cada botão do gerenciador
   void cliqueMngB(int mx, int my, int mb, int ms){
      for(Botao * b : vetor){
         b->Clicou(mx, my, mb, ms);
      }
   }

};


