import java.awt.*;
import java.lang.*;
import java.awt.event.*;
import java.math.*;
import java.io.*;
import com.sun.image.codec.jpeg.*;
import java.awt.image.BufferedImage;
import javax.swing.*;
import javax.swing.event.*;


//classe para definicao de uma matriz de inteiros para representar imagens de qualquer tamanho
//no interio eh armazenado a componente R, G e B.
class Imagem
{
   int mat[][];
   int larg, alt;
   Imagem(int a, int l)
   {
      larg = l;
      alt = a;
      mat = new int[larg][alt];
   }

   void init(int val)
   {
      int x, y;
      for(x=0; x<larg; x++)
         for(y=0; y<alt; y++)
            mat[x][y] = val;
   }

   void init(int xi, int yi, int larg, int alt, int val)
   {
      int x, y;
      for(x=xi; x < xi+larg; x++)
         for(y=yi; y < yi+alt; y++)
            mat[x][y] = val;
   }

   public void print()
   {
      int x, y;
      System.out.println(" " );
      for(y=0; y<alt; y++)
         System.out.println(mat[0][y]+" "+mat[1][y]+" "+mat[2][y]+" "+mat[3][y]+" "+mat[4][y]+" "+mat[5][y]+" "+mat[6][y]+" "+mat[7][y] );
   }

   //copia a matriz para um bufferedImage
   void copy(BufferedImage bi)
   {
       int x, y;
       for(x=0; x<bi.getWidth() && x<larg; x++)
         for(y=0; y<bi.getHeight() && y<alt; y++)
         {
             mat[x][y] = bi.getRGB(x, y);
         }
   }

   //copia a matriz para outra matriz
   void copy(Imagem i)
   {
       int x, y;
       for(x=0; x<larg; x++)
         for(y=0; y<alt; y++)
         {
             mat[x][y] = i.getRGB(x, y);
         }
   }


   //copia um bufferedImage para a matriz
   void paste(BufferedImage bi)
   {
       int x, y;
       
       for(x=0; x<bi.getWidth() && x<larg; x++)
         for(y=0; y<bi.getHeight() && y<alt; y++)
         {
             bi.setRGB(x, y, mat[x][y]);
         }
   }

   //subtrai as compoentes R, G e B das duas matrizes
   void subtrai(Imagem src, Imagem dest)
   {
      int x, y;
      for(x=0; x<larg;x++)
         for(y=0; y<alt; y++)
         {
            setR(x, y, Math.abs(src.getR(x,y)-dest.getR(x,y)));
            setG(x, y, Math.abs(src.getG(x,y)-dest.getG(x,y)));
            setB(x, y, Math.abs(src.getB(x,y)-dest.getB(x,y)));
            //System.out.println(src.getR(x,y)-dest.getR(x,y));
         }
   }

   //subtrai as compoentes R, G e B das duas matrizes
   void multiplica(int val)
   {
      int x, y, R, G, B;
      for(x=0; x<larg;x++)
         for(y=0; y<alt; y++)
         {
            R = clamp(getR(x,y)*val);
            G = clamp(getG(x,y)*val); 
            B = clamp(getB(x,y)*val);
            setR(x, y, R );
            setG(x, y, G );
            setB(x, y, B );
         }
   }
   
   int clamp(int val)
   {
      if(val>255)
         return 255;
      return val;   
   }

   int getR(int x, int y)
   {
      if(x<larg && y<alt)
         return (mat[x][y]>>16)&255;
      return 0;
   }

   void getR(int x, int y, Imagem i)
   {
      int x1, y1, a, b;
      if(x+i.larg <= larg && y+i.alt <= alt)
      {
         for(x1=0,a=x; x1<i.larg; a++,x1++)
            for(y1=0,b=y; y1<i.alt; b++,y1++)
               i.mat[x1][y1] = getR(a, b);
      }
   }

   int getG(int x, int y)
   {
      if(x<larg && y<alt)
         return (mat[x][y]>>8)&255;
      return 0;
   }

   void getG(int x, int y, Imagem i)
   {
      int x1, y1, a, b;
      if(x+i.larg <= larg && y+i.alt <= alt)
      {
         for(x1=0,a=x; x1<i.larg; a++,x1++)
            for(y1=0,b=y; y1<i.alt; b++,y1++)
               i.mat[x1][y1] = getG(a, b);
      }
   }

   int getB(int x, int y)
   {
      if(x<larg && y<alt)
         return mat[x][y]&255;
      return 0;
   }

   void getB(int x, int y, Imagem i)
   {
      int x1, y1, a, b;
      if(x+i.larg <= larg && y+i.alt <= alt)
      {
         for(x1=0,a=x; x1<i.larg; a++,x1++)
            for(y1=0,b=y; y1<i.alt; b++,y1++)
               i.mat[x1][y1] = getB(a, b);
      }
   }

   int getRGB(int x, int y)
   {
      if(x<larg && y<alt)
         return mat[x][y];
      return 0;
   }

   void getRGB(int x, int y, Imagem i)
   {
      int x1, y1, a, b, val;
      if(x+i.larg <= larg && y+i.alt <= alt)
      {
         for(x1=0,a=x; x1<i.larg; a++,x1++)
            for(y1=0,b=y; y1<i.alt; b++,y1++)
            {
               val = getRGB(a, b);
               i.setRGB(x1, y1, val);
            }
      }
   }

   ///////////////////////////////////////////////////////////
   void setR(int x, int y, int r)
   {
      if(x<larg && y<alt)
         mat[x][y] = (mat[x][y]&65536)|(r<<16); //1111111111111111
      else
         mat[x][y] = 0;
   }

   void setR(int x, int y, Imagem i)
   {
      int x1, y1, a, b;
      if(x+i.larg <= larg && y+i.alt <= alt)
      {
         for(x1=0,a=x; x1<i.larg; a++,x1++)
            for(y1=0,b=y; y1<i.alt; b++,y1++)
               setR(a, b, i.mat[x1][y1]);
      }
   }

   void setG(int x, int y, int g)
   {
      if(x<larg && y<alt)
         mat[x][y] = (mat[x][y]&16711935)|(g<<8); //111111110000000011111111
      else
         mat[x][y] = 0;
   }

   void setG(int x, int y, Imagem i)
   {
      int x1, y1, a, b;
      if(x+i.larg <= larg && y+i.alt <= alt)
      {
         for(x1=0,a=x; x1<i.larg; a++,x1++)
            for(y1=0,b=y; y1<i.alt; b++,y1++)
               setG(a, b, i.mat[x1][y1]);
      }
   }

   void setB(int x, int y, int b)
   {
      if(x<larg && y<alt)
         mat[x][y] = (mat[x][y]&16776960)|(b); //111111111111111100000000
      else
         mat[x][y] = 0;
   }

   void setB(int x, int y, Imagem i)
   {
      int x1, y1, a, b;
      if(x+i.larg <= larg && y+i.alt <= alt)
      {
         for(x1=0,a=x; x1<i.larg; a++,x1++)
            for(y1=0,b=y; y1<i.alt; b++,y1++)
               setB(a, b, i.mat[x1][y1]);
      }
   }

   void setRGB(int x, int y, int rgb)
   {
      if(x<larg && y<alt)
         mat[x][y] = rgb;
      else
         mat[x][y] = 0;
   }

   void setRGB(int x, int y, Imagem i)
   {
      int x1, y1, a, b;
      if(x+i.larg <= larg && y+i.alt <= alt)
      {
         for(x1=0,a=x; x1<i.larg; a++,x1++)
            for(y1=0,b=y; y1<i.alt; b++,y1++)
               setRGB(a, b, i.getRGB(x1, y1));
      }
   }
}
