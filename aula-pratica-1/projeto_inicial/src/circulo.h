
#include "gl_canvas2d.h"


class Circulo{
    public:
    int x, y, raio;

    Circulo(int _x, int _y, int _raio){
        x = _x;
        y = _y;
        raio = _raio;
    }
    void render(){
        CV::color(1,0,0);
        CV::circleFill(x, y, raio, 50);
    }
};
