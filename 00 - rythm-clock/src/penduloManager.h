#ifndef __PENDULO__MANAGER__H__
#define __PENDULO__MANAGER__H__

#include "pendulo.h"
#include <vector>

class PenduloManager{
public:
    int x, y;
    std::vector<Pendulo *> vetor;

    PenduloManager(int _x, int _y){
        x = _x;
        y = _y;
    }

    void addPendulo(float raio){
        vetor.push_back(new Pendulo(x, y, raio));
    }

    void render(){
        for(p : vetor){
            p->render();
        }
    }



};

#endif // __PENDULO__MANAGER__H__
