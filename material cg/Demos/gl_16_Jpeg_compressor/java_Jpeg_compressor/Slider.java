import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;

class Slider extends Dialog
{
   JSlider escala;  
	Slider(Frame f, compress compr) 
	{
		super(f,"Selecao de Componentes");
		setSize(250,100);
      //setLayout(new FlowLayout(FlowLayout.LEFT));
      setLayout(new BorderLayout());
		setResizable(false);
        
      escala = new JSlider(JSlider.HORIZONTAL, -100, 100, 70);
      escala.addChangeListener(new SliderListener(compr));
 
      escala.setMajorTickSpacing(25);
      escala.setMinorTickSpacing(25);
      escala.setPaintTicks(true);
      escala.setPaintLabels(true);
 
      add(escala);
		//setVisible(true);
		
      addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                hide();
            }  
      });
   }
}

class SliderListener implements ChangeListener 
{
    //crono11 app;
    SliderListener(compress compr)
    {
         super();
         //app = crono;
    }  
    public void stateChanged(ChangeEvent e) 
    {
       JSlider source = (JSlider)e.getSource();
       //app.setEscala((int)source.getValue());
     }
}    
 

