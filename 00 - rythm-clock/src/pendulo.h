#ifndef __PENDULO__H__
#define __PENDULO__H__

class Pendulo{
public:
    int x, y;
    float ang = 270 * (PI/180), raio;
    bool antiHorario = true;
    Pendulo(int _x, int _y, float _raio){
        x = _x;
        y = _y;
        raio = _raio;
    }

    render(){
        float xN = raio * cos(ang);
        float yN = raio * sin(ang);
        CV::line(x, y, xN, yN);
        if(xN >-0.05 && xN<0.05 && yN < 0){
            antiHorario = !antiHorario;
        }
        antiHorario ? (ang += (1/(raio/5)) * (PI/180)) : (ang -= (1/(raio/5)) * (PI/180));
        CV::circleFill(xN,yN,3,10);
    }


};


#endif // __PENDULO__H__
