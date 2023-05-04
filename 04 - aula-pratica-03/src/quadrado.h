
#include "gl_canvas2d.h"

class Quadrado{
public:
    float posicaoX[4];
    float posicaoY[4];
    float posicaoXc[4];
    float posicaoYc[4];
    float rotacao = 0 * (PI/180);

    float translacaoX, translacaoY;


    Quadrado(float x, float y, float largura, float altura){

        posicaoX[0] = x;
        posicaoY[0] = y;
        posicaoX[1] = x;
        posicaoY[1] = y+altura;
        posicaoX[2] = x+largura;
        posicaoY[2] = y+largura;
        posicaoX[3] = x+largura;
        posicaoY[3] = y;

        posicaoXc[0] = x;
        posicaoYc[0] = y+altura-(altura/4);
        posicaoXc[1] = x;
        posicaoYc[1] = y+altura;
        posicaoXc[2] = x+largura;
        posicaoYc[2] = y+largura;
        posicaoXc[3] = x+largura;
        posicaoYc[3] = y+altura-(altura/4);

    }
    void render(){
        CV::polygonFill(posicaoX, posicaoY, 4);
    }

    void rotaciona(float _rotacao){
        _rotacao = _rotacao * (PI/180);
        _rotacao = rotacao + _rotacao;
        rotacao = _rotacao;
        for(int i = 0;i < 4; i++){
            float xAux = posicaoX[i];
            posicaoX[i] = posicaoX[i] * cos(_rotacao) - posicaoY[i] * sin(_rotacao);
            posicaoY[i] = xAux * sin(_rotacao) + posicaoY[i] * cos(_rotacao);
            float xAuxc = posicaoXc[i];
            posicaoXc[i] = posicaoXc[i] * cos(_rotacao) - posicaoYc[i] * sin(_rotacao);
            posicaoYc[i] = xAuxc * sin(_rotacao) + posicaoYc[i] * cos(_rotacao);
        }
    }


    void translada(float x, float y){
        translacaoX = x;
        translacaoY = y;
        for(int i = 0; i<4; i++){
            posicaoX[i] = posicaoX[i] + x;
            posicaoY[i] = posicaoY[i] + y;
            posicaoXc[i] = posicaoXc[i] + x;
            posicaoYc[i] = posicaoYc[i] + y;

        }
    }

    void destranslada(){
        for(int i = 0; i<4; i++){
            posicaoX[i] = posicaoX[i] - translacaoX;
            posicaoY[i] = posicaoY[i] - translacaoY;
            posicaoXc[i] = posicaoXc[i] - translacaoX;
            posicaoYc[i] = posicaoYc[i] - translacaoY;
        }
    }

    void escala(float esc){
        for(int i = 0;i < 4; i++){
            posicaoX[i] *= esc;
            posicaoY[i] *= esc;
            posicaoXc[i] *= esc;
            posicaoYc[i] *= esc;
        }
    }
};
