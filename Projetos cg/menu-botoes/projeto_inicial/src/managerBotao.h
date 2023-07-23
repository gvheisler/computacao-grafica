#include "botao.h"

#include <functional>

class ManagerBotoes{
    int espacamentoBotao, alturaBotao, larguraBotao;
    std::vector<Botao*> vetor = {};
    Botao * bt = NULL;

    int xInicial = 100;
    bool vertical;
public:
    ManagerBotoes(int _espacamentoBotao, int _xInicial, bool _vertical){
        espacamentoBotao = _espacamentoBotao;
        alturaBotao = espacamentoBotao*4;
        larguraBotao = espacamentoBotao*8;
        xInicial = _xInicial;
        vertical = _vertical;
    }

    void addBotao(char * txt, std::function<void()> funcao){
        bt = new Botao(xInicial, (espacamentoBotao*(vetor.size()+1))+(alturaBotao*vetor.size()), larguraBotao, alturaBotao, txt, funcao);
        vetor.push_back(bt);
    }

    void renderBotoes(int mouseX, int mouseY, int mouseS){
        for(auto b : vetor){
            b->render(mouseX, mouseY, mouseS);
        }
    }

    void cliqueBotoes(int mouseX, int mouseY, int mouseS){
        for(auto b : vetor){
            b->clicado(mouseX, mouseY, mouseS);
        }
    }
};
