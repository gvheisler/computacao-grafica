import java.awt.*;
import java.lang.*;
import java.awt.event.*;
import com.sun.image.codec.jpeg.*;
import java.awt.image.BufferedImage;
import javax.swing.*;

class Controles extends Panel implements ActionListener
{
   compress app;
   Button DCT, funcoes;
   TextField tfmin, tfmax, tfmult, tfthresh;
   Label labmin, labmax, labmult, labthresh;
   
   public Controles(compress hist)
   {
      app = hist;
      setSize(160,230);
      setLayout(new FlowLayout(FlowLayout.LEFT));
      
      DCT = new Button("DCT");
      DCT.addActionListener(this);
      DCT.setSize(60,30);
      add(DCT);
      
      labmin = new Label("Min");
      add(labmin);
      tfmin = new TextField("0", 1);
      add(tfmin);
      
      labmax = new Label("Max");
      add(labmax);
      tfmax = new TextField("60", 1);
      add(tfmax);
      
      labmult = new Label("Mult");
      add(labmult);
      tfmult = new TextField("20", 1);
      add(tfmult);
      
      labthresh = new Label("Threshold");
      add(labthresh);
      tfthresh = new TextField("0", 1);
      add(tfthresh);
   }
   
   public void actionPerformed(ActionEvent e)
   {
      String arg = e.getActionCommand();
      
      if ("Funções".equals(arg))
      {
          app.jan1.setVisible(true);
      }
      if("DCT".equals(arg))
      {
      	 //JFrame f = new JFrame();
      	 PopupWait p = new PopupWait(app, "Processando a DFCT");
      	 p.setVisible(true);
          app.dct();
          p.dispose();
      }
   }
}

