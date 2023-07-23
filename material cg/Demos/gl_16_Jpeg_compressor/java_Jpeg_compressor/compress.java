import java.awt.*;
import java.lang.*;
import java.awt.event.*;
import java.math.*;
import java.io.*;
import com.sun.image.codec.jpeg.*;
import java.awt.image.BufferedImage;
import javax.swing.*;
import javax.swing.event.*;


class compress extends JFrame implements WindowListener, ActionListener
{
   Janela jan1;
   Componentes comp1;
   Controles ctr;
   Slider    slider;
   MenuBar    MBAR;      //Define o menu de opcoes

   Menu  FILE, OPCOES, HELP; //componentes do menu de opcoes

   BufferedImage bi_src, bi_dest, bi_dif, bi_coef;
   Imagem imgSrc, imgDest, imgDif, imgCoef, imgTmp;
   Compressor compressor;
   int bi_src_flag, bi_dest_flag, bi_dif_flag; //indica se ja tem imagem carregada nos bi`s.

   compress()
   {
      super ("DCT");
      
      setSize(450,510);
      setLocation(355,1);
      
      getContentPane().setLayout(new BorderLayout());
      ctr = new Controles(this);
      getContentPane().add("North", ctr);
      
      jan1 = new Janela(this,"Bases");
      comp1 = new Componentes(this,"Componentes RGB Y");
      //slider = new Slider(this, this);
      //slider.setVisible(true);

      MBAR = new MenuBar();
      setMenuBar(MBAR);
     
      FILE = new Menu("Arquivo");
      FILE.addActionListener ( this );
      FILE.add(new MenuItem("Abrir"));
      FILE.add(new MenuItem("-"));
      FILE.add(new MenuItem("Salvar DCT"));
      FILE.add(new MenuItem("Salvar Diferenca"));
      FILE.add(new MenuItem("Salvar Coeficientes"));
      FILE.add(new MenuItem("-"));
      FILE.add(new MenuItem("Exit"));
      MBAR.add(FILE);
      
      OPCOES = new Menu("Exibir");
      OPCOES.addActionListener ( this );
      OPCOES.add(new MenuItem("Componentes RGB Y"));
      OPCOES.add(new MenuItem("Funcoes basicas"));
      MBAR.add(OPCOES);
      
      HELP = new Menu("Help");
      HELP.addActionListener ( this );
      HELP.add(new MenuItem("Help"));
      MBAR.add(HELP);
      
      setBackground(Color.white);
      
      addWindowListener(this);
      
      bi_src  = new BufferedImage(200,200,BufferedImage.TYPE_3BYTE_BGR); 
      bi_dest = new BufferedImage(200,200,BufferedImage.TYPE_3BYTE_BGR); 
      bi_dif  = new BufferedImage(200,200,BufferedImage.TYPE_3BYTE_BGR); 
      bi_coef = new BufferedImage(200,200,BufferedImage.TYPE_3BYTE_BGR); 
      imgSrc     = new Imagem(200,200);
      imgDest    = new Imagem(200,200);
      imgDif     = new Imagem(200,200); //guarda a diferenca entre duas imagens
      imgCoef    = new Imagem(200,200); //guarda os coeficientes que formam zerados
      imgTmp     = new Imagem(200,200); //guarda os coeficientes que formam zerados
      compressor = new Compressor();
      
      bi_src_flag = bi_dest_flag = bi_dif_flag = 0;//nao tem imagem carregada
      															//nos buffered images
      
      setVisible(true);
   }

   public void paint(Graphics g)
   {
      g.setColor(Color.white);
      g.fillRect(0,0,2000,2000);

      if(bi_src_flag==1)
         g.drawImage(bi_src, 15,  85, this);
      
      if(bi_dest_flag==1)
         g.drawImage(bi_dest, 235,  85, this);

      if(bi_dif_flag==1)
      {
         g.drawImage(bi_dif,  15,  300, this);
         g.drawImage(bi_coef, 235,  300, this);
      }
   }

   void componentes()
   {
      if(bi_src_flag==0)
         AbreImagem();
      if(bi_src_flag==1)
      {
         imgSrc.copy(bi_src);
         
         imgDest.init(0);
         imgSrc.getR (0,0, imgTmp);
         imgDest.setR(0,0, imgTmp);
         imgDest.paste(bi_dest);

         imgDif.init(0);
         imgSrc.getG(0,0, imgTmp);
         imgDif.setG(0,0, imgTmp);
         imgDif.paste(bi_dif);

         imgCoef.init(0);
         imgSrc.getB (0,0, imgTmp);
         imgCoef.setB(0,0, imgTmp);
         imgCoef.paste(bi_coef);
         
         bi_dest_flag = 1;
         bi_dif_flag  = 1;
      }
      repaint();
   }

   void dct()
   {
      int min, max, mult, soma, threshold, x, y;
      min       = Integer.parseInt(ctr.tfmin.getText());
      max       = Integer.parseInt(ctr.tfmax.getText());
      mult      = Integer.parseInt(ctr.tfmult.getText());
      threshold = Integer.parseInt(ctr.tfthresh.getText());
      
      //se nao tem imagem carregada, deve carregar uma.
      if(bi_src_flag==0)
         AbreImagem();
      
      if(bi_src_flag==1)
      {
         imgSrc.copy(bi_src);
         //realiza a compressao passando o intervalo de coeficientes que devem permanecer 
         //inalterados. Retorna em imgDest a imagem reconstruida e em imgCoef o numero de 
         //coeficinetes removidos em (R+G+B)
         compressor.comprimir(imgSrc, imgDest, imgCoef, min, max, threshold);
         imgDest.paste(bi_dest);
         bi_dest_flag = 1;
         bi_dif_flag  = 1;
         
         //calcula a diferenca entre a original e a transformada
         imgDif.subtrai(imgSrc, imgDest);
         imgDif.multiplica(mult);       
         imgDif.paste(bi_dif);   

         //encontra o maior e menor coeficiente. No zigzag, eh calculado o numero de coeficientes=0 de cada bloco.
         max = 0;
         min = 192; 
         soma = 0;
         for(x=0; x<imgCoef.larg; x+=8)
            for(y=0; y<imgCoef.alt; y+=8)
            {
               if(imgCoef.mat[x][y] > max)
                  max = imgCoef.mat[x][y];
               if(imgCoef.mat[x][y] < min)
                  min = imgCoef.mat[x][y];
               //soma o numero total de coeficientes=0
               soma += imgCoef.mat[x][y];
            }
         System.out.println("Largura:"+imgCoef.larg);
         System.out.println("Conpressao maxima: "+ max+" coeficientes");
         System.out.println("Conpressao minima: "+ min+" coeficientes");
         System.out.println("Total de coeficientes zerados: "+ soma+" de 120000 coeficientes");
         System.out.println("Taxa de compressao: "+ (int)((soma/120000.0)*100) +" %" );

         //cria a imagem dos coeficientes.
         int intensidade;
         int val;
        
         for(x=0; x<imgCoef.larg; x++)
            for(y=0; y<imgCoef.alt; y++)
            {
               val = (int)imgCoef.mat[x][y];
               intensidade = val | val<<8 | val<<16;
               bi_coef.setRGB(x, y,intensidade);
            }
         
      }
      repaint();
   }

   void AbreImagem()
   {
      String file,directory;
   
      FileDialog OpenDialog = new FileDialog(this,"Open Image...",FileDialog.LOAD);
      OpenDialog.setFile("*.jpg");
      OpenDialog.setVisible(true );
      directory = OpenDialog.getDirectory();
      file = OpenDialog.getFile();
      if(file==null)
         return;
      try {
            File arq = new File(directory, file);
            FileInputStream in = new FileInputStream(arq);
            JPEGImageDecoder decoder = JPEGCodec.createJPEGDecoder(in);
            bi_src = decoder.decodeAsBufferedImage();
            bi_src_flag=1;
            comp1.repaint(); //repinta a janela das componentes
      } catch (Exception ex){
            System.out.println("erro para abrir imagem:"+directory+file);
            bi_src_flag=0;
      }
      bi_dest_flag=0;
      bi_dif_flag=0;
      repaint();
   }

   void SalvaImagem(BufferedImage bi)
   {
      String file,directory;
		FileDialog SaveDialog = new FileDialog(this,"Save Image as...",FileDialog.SAVE);
		SaveDialog.setFile("*.jpg");
		SaveDialog.setVisible(true );
		directory = SaveDialog.getDirectory();
		file	= SaveDialog.getFile();

		if(file!=null)
		{
			try {
				FileOutputStream out = new FileOutputStream(directory+file);
				JPEGImageEncoder encoder = JPEGCodec.createJPEGEncoder(out);
				JPEGEncodeParam param = encoder.getDefaultJPEGEncodeParam(bi);
				param.setQuality(1.0f, false); // 1.0 indica grande qualidade
				encoder.setJPEGEncodeParam(param);
				encoder.encode(bi);
			} catch (Exception ex){
				System.out.println("erro para salvar imagem:"+directory+file);
			}
		}
      repaint();
   }

   
   //trata enventos do menu
   //public boolean action(Event event, Object o)
   public void actionPerformed(ActionEvent e)
   {
      String s = e.getActionCommand();
		//System.out.println(s);
		
      if(s.equals("Exit"))
         System.exit(0);
      else if(s.equals("Abrir"))
         AbreImagem();
      else if(s.equals("Help"))
         Help();
      else if(s.equals("Componentes RGB Y"))
      {
         componentes();
         comp1.setVisible(true);
      }
      else if(s.equals("Funcoes basicas"))
      {
         jan1.setVisible(true);
      }
      else  if(s.equals("Salvar DCT"))
         SalvaImagem(bi_dest);
      else  if(s.equals("Salvar Diferenca"))
         SalvaImagem(bi_dif);
      else  if(s.equals("Salvar Coeficientes"))
         SalvaImagem(bi_coef);

      //return true;
   }
   
   public void Help()
   {
      System.out.println("");
      System.out.println("HELP");
      System.out.println("");
      System.out.println("Entrada: O programa trabalha com imagens de 200x200 pixels, no formato JPG");
      System.out.println("");
      System.out.println("Saida: Sao gerados 3 tipos de imagens na DCT:");
      System.out.println("   - A imagem reconstruida - a direita");
      System.out.println("   - A imagem da subtracao da original com a reconstruida, multiplicada por");
      System.out.println("     um fator MULT");
      System.out.println("   - Uma imagem mostrando o grau de compressao obtido por regiao. Regioes mais ");
      System.out.println("     claras tem maior compressao");
      System.out.println("   - O programa tambem tem opcao para exibicao das componentes R,G,B,Y da imagem");
      System.out.println("");
      System.out.println("Coeficientes: Dos 192 coeficientes que determinam a DCT (64 em R, 64 em G e");
      System.out.println("   64 em B), pode-se remove-los de duas maneiras:");
      System.out.println("   1) Usando MIN e MAX pode-se determinar qual intervalo [0-63] de coeficientes");
      System.out.println("      serao usados na reconstrucao. Se MIN=0 e MAX=20, todos os coeficientes");
      System.out.println("      acima de 20, no zig-zag, serao zerados. ");
      System.out.println("   2) Pelo threshold. Neste caso, todos os valores de coeficientes menores que");
      System.out.println("      o threshold em modulo sao zerados.");
      System.out.println("");
      System.out.println("Funcoes Basicas: apresenta graficamente as 64 funcoes basicas usadas na DCT");
      System.out.println("");
      System.out.println("Programa desenvolvido por Cesar Tadeu Pozzer ");
      System.out.println("Disciplina de Fundamentos de Sistemas Multimidia");
      System.out.println("PUC-Rio - 2001");
   }

	
   public void windowClosing(WindowEvent e)
   {
      dispose();
      System.exit(0);
   }

   public void windowClosed(WindowEvent e){}
   public void windowActivated(WindowEvent e) {}
   public void windowDeactivated(WindowEvent e) {}
   public void windowDeiconified(WindowEvent e) {}
   public void windowIconified(WindowEvent e) {}
   public void windowOpened(WindowEvent e){}
   
   public static void main(String args[])
   {
      new compress();
   }

   
}