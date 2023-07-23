#include "gl_canvas2d.h"

/*void printaCores(int screenWidth, int screenHeight){
    /*for(float r = 0, x = 0; r<1; r+=0.01){
        for(float g = 0; g<1; g+=0.01){
            for(float b = 0; b<1; b+=0.01, x+=1){
                CV::color(r,g, b);
                CV::rectFill(x, 0, x+1, screenWidth);
            }
        }
    }*
    int largura = 500;
    int x = 100;
    int y = 100;
    float div = 255.0f/largura;
    for(int i = 0; i < largura; i++){
         for(int j = 0; j < largura; j++){
            CV::color(((largura - j)* div)/255, ((largura - i)*div)/255, (i*div)/255);
            CV::point(x + j, y + i);
         }
      }
}*/

void printaCores(int screenWidth, int screenHeight){
   /*para x de 0 a 799:
    para y de 0 a 599:
        cor = (x, y, 0) # vermelho
        desenhar_ponto(x, y, cor)

        cor = (0, x, y) # verde
        desenhar_ponto(x, y, cor)

        cor = (y, 0, x) # azul
        desenhar_ponto(x, y, cor)
    */
    /*for(int y = 0; y<screenHeight; y+=tamanho_quadrado){
        for(int x = 0; x<screenWidth; x+=tamanho_quadrado){
            float x256 = x%255;
            float y256 = y%255;
            float xy256 = (x+y)%255;
            //printf("x = %f, y = %f, xy = %f\n", x256, y256, xy256);
            if((x/tamanho_quadrado)%2==((y/tamanho_quadrado)%2)){
                CV::color(float(x256/255),float(y256/255), float(xy256/255));
            }else{
                CV::color(float(y256/255),float(x256/255), float(xy256/255));
            }
            CV::rectFill(x,y,x+tamanho_quadrado,y+tamanho_quadrado);
        }
    }*/

    /*for(float y = 0; y<screenHeight; y+=1){
        for(float x = 0; x<screenWidth; x+=1){
                CV::color(float(x/255), float(y/255), z);
                CV::point(x,y);
        }
    }*/
    /*float altura = 200.0;
    float largura = 200.0;
    float incVert = 1.0/altura;
    float incHori = 1.0/largura;
    for(int y = 0; y < altura; y++) {
        float g = y * incVert;
        for(int x = 0; x < largura; x++) {
            float r = x * incHori;
            float b = 0;
            CV::color(r, g, b); // Substitua esta função por uma função que define uma cor RGB
            CV::point(x, y);
        }
    }*/


    /*while(x<screenWidth){

        for(;r<1;r+=incremento){
            CV::color(r,g,b);
            CV::rectFill(x,0,x+tam,screenHeight);
        x+=tam;
        }
        for(;g<1;g+=incremento){
            CV::color(r,g,b);
            CV::rectFill(x,0,x+tam,screenHeight);
            x+=tam;
        }
        for(;r>0;r-=incremento){
            CV::color(r,g,b);
            CV::rectFill(x,0,x+tam,screenHeight);
            x+=tam;
        }
        for(;b<1;b+=incremento){
            CV::color(r,g,b);
            CV::rectFill(x,0,x+tam,screenHeight);
            x+=tam;
        }
        for(;g>0;g-=incremento){
            CV::color(r,g,b);
            CV::rectFill(x,0,x+tam,screenHeight);
            x+=tam;
        }
        for(;r<1;r+=incremento){
            CV::color(r,g,b);
            CV::rectFill(x,0,x+tam,screenHeight);
            x+=tam;
        }
        for(;g<1;g+=incremento){
            CV::color(r,g,b);
            CV::rectFill(x,0,x+tam,screenHeight);
            x+=tam;
        }
    }*/
    int x = 0, tam=4;
    float incremento = 0.05;
    float r=0,g=0,b=0;
    while (x < screenWidth) {
        for (; r < 1; r += incremento) {
            CV::color(r, g, b);
            CV::rectFill(x, 0, x + tam, screenHeight);
            x += tam;
            if (x >= screenWidth) {
                break;
            }
        }
        if (x >= screenWidth) {
            break;
        }
        for (; g < 1; g += incremento) {
            CV::color(r, g, b);
            CV::rectFill(x, 0, x + tam, screenHeight);
            x += tam;
            if (x >= screenWidth) {
                break;
            }
        }
        if (x >= screenWidth) {
            break;
        }
        for (; r > 0; r -= incremento) {
            CV::color(r, g, b);
            CV::rectFill(x, 0, x + tam, screenHeight);
            x += tam;
            if (x >= screenWidth) {
                break;
            }
        }
        if (x >= screenWidth) {
            break;
        }
        for (; b < 1; b += incremento) {
            CV::color(r, g, b);
            CV::rectFill(x, 0, x + tam, screenHeight);
            x += tam;
            if (x >= screenWidth) {
                break;
            }
        }
        if (x >= screenWidth) {
            break;
        }
        for (; g > 0; g -= incremento) {
            CV::color(r, g, b);
            CV::rectFill(x, 0, x + tam, screenHeight);
            x += tam;
            if (x >= screenWidth) {
                break;
            }
        }
        if (x >= screenWidth) {
            break;
        }
        for (; r < 1; r += incremento) {
            CV::color(r, g, b);
            CV::rectFill(x, 0, x + tam, screenHeight);
            x += tam;
            if (x >= screenWidth) {
                break;
            }
        }
        if (x >= screenWidth) {
            break;
        }
        for (; g < 1; g += incremento) {
            CV::color(r, g, b);
            CV::rectFill(x, 0, x + tam, screenHeight);
            x += tam;
            if (x >= screenWidth) {
                break;
            }
        }
        if (x >= screenWidth) {
            break;
        }
    }




    /*for(float b = 0;b<1;b+=0.01){
        for(float g = 0;g<1;g+=0.01){
            for(float r = 0;r<1;r+=0.01){
                CV::color(r,g,b);
                CV::rectFill(x,0,x+1,screenHeight);
                x++;
            }
        }
    }*/
}

void RenderSelector(){
   int raio = 100;
   float r=120.0;
   float g=0.0;
   float b=0.0;
   float x, y, ang;
   float angInicial = 0;

   for(ang = angInicial; ang<((2*PI)/4); ang+=0.005){
        x = raio*cos(ang);
        y = raio*sin(ang);
            if(ang<=((2*PI/3)/4)){
               r--;
               g++;
            }else if((ang<=(4*PI/3)/4)){
               g--;
               b++;
            }else if((ang<=(2*PI)/4)){
               b--;
               r++;
            }
         CV::color(r/30,g/30,b/30);
         CV::translate(0,0);
         CV::line(0,0,x,y);
        }
    }


void segueMouse(int mouseX, int mouseY){
    char str[20];
    CV::translate(0,0);
    CV::color(1,0,0);
    float modulo = sqrt(pow(mouseX, 2)+pow(mouseY,2));
    float xNorm = 500*(mouseX/modulo);
    float yNorm = 500*(mouseY/modulo);
    CV::line(0,0,xNorm, yNorm);
    float anguloNorm = atan(yNorm/xNorm);
    anguloNorm = anguloNorm * (180/PI);
    sprintf(str, "Angulo = %f", anguloNorm);
    CV::text(100, 500, str);
}
