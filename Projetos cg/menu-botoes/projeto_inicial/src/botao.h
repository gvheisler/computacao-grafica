#include "gl_canvas2d.h"

#include <functional>

class Botao{
    int x, y, largura, altura;
    char txt[30];
    std::function<void()> funcao;
public:
    Botao(int _x, int _y, int _largura, int _altura, char * _txt, std::function<void()> _funcao){
        x = _x;
        y = _y;
        largura = _largura;
        altura = _altura;
        strcpy(txt, _txt);
        funcao = _funcao;
    }

    void render(int mouseX, int mouseY, int mouseS){
        CV::color(0,0,0);
        CV::rectFill(x, y, (x+largura), (y+altura));
        if(colidiu(mouseX, mouseY)){
            CV::color(1,0,0);
        }else{
            CV::color(0.7,0,0);
        }
        CV::rectFill(x+5, y+5, (x+largura)-5, (y+altura)-5);
    }

    bool colidiu(int mouseX, int mouseY){
        if(mouseX>=x&&mouseX<=(x+largura)&&mouseY>=y&&mouseY<=(y+altura)){
            return true;
        }
        return false;
    }
    bool clicado(int mouseX, int mouseY, int mouseS){
        if(colidiu(mouseX, mouseY)&&mouseS==1){
            printf("Funcao\n");
            if(funcao){
                funcao();
            }

        }
    }
};

