//classe para definicao de matriz de double de qualquer tamanho.
class Matriz
{
   double mat[][];
   int larg, alt;
   Matriz(int l, int a)
   {
      larg = l;
      alt = a;
      mat = new double[larg][alt];
   }
   
   void init(double val)
   {
      int x, y;
      for(x=0; x<larg; x++)
         for(y=0; y<alt; y++)
            mat[x][y] = val;
   }

   //impressao na tela no formato inteiro
   public void printInt()
   {
      int x, y;
      System.out.println(" " );
      for(y=0; y<alt; y++)
         System.out.println((int)mat[0][y]+" "+(int)mat[1][y]+" "+(int)mat[2][y]+" "+(int)mat[3][y]+" "+(int)mat[4][y]+" "+(int)mat[5][y]+" "+(int)mat[6][y]+" "+(int)mat[7][y] );
   }

   public void printDouble()
   {
      int x, y;
      System.out.println(" " );
      for(y=0; y<alt; y++)
         System.out.println(mat[0][y]+" "+mat[1][y]+" "+mat[2][y]+" "+mat[3][y]+" "+mat[4][y]+" "+mat[5][y]+" "+mat[6][y]+" "+mat[7][y] );
   }
}

