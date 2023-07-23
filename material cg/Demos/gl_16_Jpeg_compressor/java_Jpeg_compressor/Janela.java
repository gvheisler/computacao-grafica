import java.awt.*;
import java.lang.*;
import java.awt.event.*;

class Janela extends Frame
{
   compress app;
   Janela(compress hist, String titulo)
   {
      super(titulo);
      app = hist;
      setSize(500,520);
      setLocation(45,45);
      setResizable(false);      
      setBackground(Color.white);
      
      addWindowListener(new WindowAdapter() {
         public void windowClosing(WindowEvent e) {
             hide();
         }
      });
   }

   public void paint(Graphics g)
   {
      int x, y;
      for(x=0; x<8; x++)
        for(y=0; y<8; y++)
            base(x, y, g);
   }

   void base(double u, double v, Graphics g)
   {
      int x, y;
      double pix;
      double pi = Math.PI;
      int TAM = 6;
      int ESP = TAM*10;
      int cor;
      for(x=0; x<8; x++)
         for(y=0; y<8; y++)
         {
            pix = Math.cos(((2*x+1)*pi*u)/16.0) * Math.cos(((2*y+1)*pi*v)/16.0);
            cor = valor(pix);
            g.setColor(new Color(cor, cor, cor));
            g.fillRect((int)(x*TAM + u*ESP)+15, (int)(y*TAM + v*ESP)+30, TAM, TAM );
         }
   }

   int valor(double pix)
   {
      double tmp;
      tmp = pix+1; //normaliza entre 0 e 2
      tmp = tmp*127; //normaliza entre 0 e 255
      return (int)tmp;
   }

}
