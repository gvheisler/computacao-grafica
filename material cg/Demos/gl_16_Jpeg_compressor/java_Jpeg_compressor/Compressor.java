//classe para compressao
class Compressor
{
   DCT dct;
   Imagem i;
   Matriz m;
   int cont;
   Compressor()
   {
      dct = new DCT();
      i = new Imagem(8,8);
      m = new Matriz(8,8);
   }

   public void comprimir(Imagem src, Imagem dest, Imagem coef, int min, int max, int threshold)
   {
      int x, y;
      for(x=0; x<src.larg; x+=8)
         for(y=0; y<src.alt; y+=8)
         {
            cont = 0;
            src.getR (x, y, i);
            m = dct.fdct(i);
            cont += zigzag(m, min, max, threshold);
            i = dct.idct(m);
            dest.setR(x, y, i);
            
            if( x==0 && y==0)
            {
                src.getR (x, y, i);
                System.out.println("\nPixels do primeiro bloco 8x8 da imagem");
                i.print();
                System.out.println("\nCoeficientes da DCT");
                m.printInt();
                System.out.println("\n");
            }

            src.getG (x, y, i);
            m = dct.fdct(i);
            cont += zigzag(m, min, max, threshold);
            i = dct.idct(m);
            dest.setG(x, y, i);


            src.getB (x, y, i);
            m = dct.fdct(i);
            cont += zigzag(m, min, max, threshold);
            i = dct.idct(m);
            dest.setB(x, y, i);
            
            //copia para a matriz de coeficientes
            coef.init(x, y, 8, 8, cont);
         }
   }

   public void descomprimir(Imagem src, Imagem dest, Imagem coef, int min, int max, int threshold)
   {
      int x, y;
      //int px=10, py=64;
      for(x=0; x<src.larg; x+=8)
         for(y=0; y<src.alt; y+=8)
         {
            cont = 0;
            src.getR (x, y, i);
            m = dct.fdct(i);
            cont += zigzag(m, min, max, threshold);
            i = dct.idct(m);
            dest.setR(x, y, i);


            src.getG (x, y, i);
            m = dct.fdct(i);
            cont += zigzag(m, min, max, threshold);
            i = dct.idct(m);
            dest.setG(x, y, i);


            src.getB (x, y, i);
            m = dct.fdct(i);
            cont += zigzag(m, min, max, threshold);
            i = dct.idct(m);
            dest.setB(x, y, i);
            
            //copia para a matriz de coeficientes
            coef.init(x, y, 8, 8, cont);
         }
   }


   //funcao que faz o zig-zag para remocao dos coeficientes. 
   //Nao zera apenas os coeficientes entre min e max
   int zigzag(Matriz m, int min, int max, int threshold)
   {
      int x=0, y=0, cont=0;
      double val;

      while(y<8)
      {
         while(true)
         {
            if(cont<min || cont>max)
               m.mat[x][y] = 0;
            cont++;
            if(y==0)
            {
               x++; break;   
            }
            if(x==7)
            {
               y++; break;
            }
            x++;
            y--;
         }           
         while(y<8)
         {
            if(cont<min || cont>max)
               m.mat[x][y] = 0;
            cont++;
            if(y==7)
            {
               x++; break;   
            }
            if(x==0)
            {
               y++; break;
            }
            x--;
            y++;
         }           
      }
      //contagem do numero de coeficientes iguais a zero ou menores que o threshold
      cont = 0;
      for(x=0; x<8; x++)
         for(y=0; y<8; y++)
         {
            val = Math.abs(m.mat[x][y]);
            if(val < threshold || val < 0.001)
            {
               cont++;
               m.mat[x][y] = 0.0;
            }
         }
      return cont;
   }
}

