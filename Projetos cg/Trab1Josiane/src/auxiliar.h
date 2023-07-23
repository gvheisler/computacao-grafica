// funcao dos botoes de selecao de forma geometrica

int lados = 1;

void selCirculo(){
   lados = 30;
}
void selTriangulo(){
   lados = 3;
}
void selQuadrado(){
   lados = 4;
}
void selPentagono(){
   lados = 5;
}
void selHexagono(){
   lados = 6;
}
void incLados(){
   lados += 1;
}
void decLados(){
   if(lados!=3){
      lados -= 1;
   }
}
void selFigura(){
   lados = 1;
}
