import java.awt.*;
import java.lang.*;
import java.awt.event.*;
import com.sun.image.codec.jpeg.*;
import java.awt.image.BufferedImage;


class Componentes extends Frame implements ItemListener 
{
   compress app;
   Checkbox R, G, B, Y;
   Label lbR, lbG, lbB;
   BufferedImage bi_rgb;
   Imagem rgb, dest, tmp;
   
   Componentes(compress hist, String titulo)
   {
      super(titulo);
      app = hist;
      setLayout(new FlowLayout(FlowLayout.LEFT));
      setSize(235,270);
      setLocation(245,345);
      setResizable(false);      
      setBackground(Color.white);
      
      bi_rgb = new BufferedImage(200,200,BufferedImage.TYPE_3BYTE_BGR); 
      rgb    = new Imagem(200,200);
      dest   = new Imagem(200,200);
      tmp    = new Imagem(200,200);
      
      R = new Checkbox("R", true);
      R.addItemListener(this);
      add(R);
      
      G = new Checkbox("G", true);
      G.addItemListener(this);
      add(G);
      
      B = new Checkbox("B", true);
      B.addItemListener(this);
      add(B);
      
      Y = new Checkbox("Y", false);
      Y.addItemListener(this);
      add(Y);
      
      addWindowListener(new WindowAdapter() {
         public void windowClosing(WindowEvent e) {
             hide();
         }
      });
   }

   public void itemStateChanged(ItemEvent e) 
   {
      int i = e.getStateChange();
      String choice = (String) e.getItem();
      if(choice.equals("Y"))
      {
         R.setState(false);
         G.setState(false);
         B.setState(false);
		}
		else
		{
         Y.setState(false);
		}
      repaint();
   }

   public void atualiza_componentes()
   {
      dest.init(0);
      rgb.copy(app.bi_src);
      
      if(Y.getState()==true)
      {
         int r, g, b, x, y;
         int lumin = 0;
		   for(x=0; x<200; x++)
			   for(y=0; y<200; y++)
			   {
				   r = rgb.getR(x, y);
				   g = rgb.getG(x, y);
				   b = rgb.getB(x, y);
         		lumin = (int)(r*0.299 + g*0.5876 + b*0.114);
         		lumin = lumin | lumin<<8 | lumin<<16;
         		dest.setRGB(x,y, lumin);
         	}
      }
      if(R.getState()==true)
      {
         rgb.getR (0,0, tmp);
         dest.setR(0,0, tmp);
      }
      if(G.getState()==true)
      {
         rgb.getG (0,0, tmp);
         dest.setG(0,0, tmp);
      }
      if(B.getState()==true)
      {
         rgb.getB (0,0, tmp);
         dest.setB(0,0, tmp);
      }
      dest.paste(bi_rgb);
   }
   
   public void paint(Graphics g)
   {
      atualiza_componentes();
      g.setColor(Color.white);
      g.fillRect(0,0,2000,2000);

      if(app.bi_src_flag==1)
         g.drawImage(bi_rgb, 15,  60, this);
   }
}
