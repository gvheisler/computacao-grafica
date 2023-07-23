//classe para a transformada cosseno
class DCT
{
   Matriz m;
   Imagem i;
   DCT()
   {
      m = new Matriz(8,8);
      i = new Imagem(8,8);
   }

   Matriz fdct(Imagem i) //forward discrete cosine transform
   {
      int u, v, x, y;
      double pix;
      double pi = Math.PI;
      for(u=0; u<8; u++)
      {
         for(v=0; v<8; v++)
         {
            pix = 0.0;
            for(x=0; x<8; x++)
            {
               for(y=0; y<8; y++)
               {
                  pix += i.mat[x][y] * Math.cos(((2.0*x+1.0)*pi*u)/16.0) * Math.cos(((2.0*y+1.0)*pi*v)/16.0);
               }
            }
            m.mat[u][v] = (pix/4.0)*C(u)*C(v);
         }
      }
      return m;
   }

   Imagem idct(Matriz m) //inverse discrete cosine transform
   {
      int u, v, x, y;
      double pix;
      double pi = Math.PI;
      for(x=0; x<8; x++)
      {
         for(y=0; y<8; y++)
         {
            pix = 0.0;
            for(u=0; u<8; u++)
            {
               for(v=0; v<8; v++)
               {
                  pix += C(u)*C(v)*m.mat[u][v] * Math.cos(((2.0*x+1)*pi*u)/16.0) * Math.cos(((2.0*y+1)*pi*v)/16.0);
               }
            }
            int pixel = (int)Math.round(pix/4.0);
            if(pixel < 0)
               i.mat[x][y] = 0;
            else if(pixel > 255)
               i.mat[x][y] = 255;
            else
               i.mat[x][y] = pixel;
         }
      }
      return i;
   }

   double C(int w)
   {
      if(w==0)
         return 0.707106781186;  /* 1/sqrt(2) */
      return 1.0;
   }
}
