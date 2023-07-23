#include "Botao.h"

#include <functional>

// manager de botoes
class ManagerBt{

   int Xi, Yi, intervaloBt;
   std::vector<Botao*> vetor = {};
   bool coluna;

   int alturaBt = 12;
   int larguraBt = 75;
   int borda = 4;
   int corB, corT;

public:
   ManagerBt(bool _coluna, int _Xi, int _Yi, int _corB, int _corT){
      coluna = _coluna;
      Xi = _Xi;
      Yi = _Yi;
      corB = _corB;
      corT = _corT;
      intervaloBt = alturaBt + (alturaBt/2);
   }

   ManagerBt(int _Xi, int _Yi, int _corB, int _corT){
      coluna = false;
      Xi = _Xi;
      Yi = _Yi;
      corB = _corB;
      corT = _corT;
      intervaloBt = larguraBt + (larguraBt/2);
   }

   void addBotao(char * label, std::function<void()> funcao){
      if(coluna == true){
         vetor.push_back(new Botao(Xi, Yi+(intervaloBt*vetor.size()), larguraBt, alturaBt, corB, corT, label, funcao));
      }else{
         vetor.push_back(new Botao(Xi, Yi+(alturaBt*vetor.size()), larguraBt, alturaBt, corB, corT, label, funcao));
      }


   }

   void renderMngB(int mx, int my, int mb, int ms){
      for(Botao * b : vetor){
         b->Render(mx, my, mb, ms);
      }
   }

   void cliqueMngB(int mx, int my, int mb, int ms){
      for(Botao * b : vetor){
         b->Clicou(mx, my, mb, ms);
      }
   }


////


};

// cria pro menu lat (formas)
// seleciona
// linha, retangulo, ciruclo
// livre
// cores

// cria pro menu sup (limpa, novo, salva, ...)
// abrir, salvar, limpar tela*/



