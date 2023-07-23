
//package client.CSVLib.ui;

import java.util.*;
import java.awt.*;    
import java.awt.event.*;
import javax.swing.*;


public class JMFrame extends JFrame implements WindowListener {

    protected JFrame         frameOwner = null;
    private boolean         boolFirstTimeVisible = true;
    private Vector          vectorChildFrames = new Vector ();


    public JMFrame () {
        this ( null, "JMFrame" );
    }

    public JMFrame ( String strTitle ) {
        this ( null, strTitle );
    }

    public JMFrame ( JFrame frameOwner ) {
        this ( frameOwner, "JMFrame" );
    }

    public JMFrame ( JFrame frameOwner, String strTitle ) {
        super ( strTitle );
        //System.out.println("JMFrame do JMFrame: "+ strTitle); 
        this.frameOwner = frameOwner;
        initFrame ();
    }


    protected void initFrame () {
        this.addWindowListener ( this );
    }

    public void addNotify () {
        super.addNotify ();   // <---- Retirar por recomendacao do jdk1.4 doc !!!
        autoPosition ();
    }

    public void setVisible ( boolean boolVisible ) {
        if ( boolVisible == true  &&  !this.isVisible()  &&  boolFirstTimeVisible == true ) {
            boolFirstTimeVisible = false;
            autoPosition ();
            if ( frameOwner != null  &&  frameOwner instanceof JMFrame ) {
                ((JMFrame)frameOwner).vectorChildFrames.addElement ( this );
            }
        }
        super.setVisible ( boolVisible );
    }

    public void autoPosition () {
        autoPosition ( this, frameOwner );
    }

    public static void autoPosition ( JFrame frame, JFrame frameOwner ) {
        Dimension       dim;
        Dimension       dimOwner;
        Dimension       dimFrame;
        Dimension       dimScreen;
        Point           point;
        Insets          insets;
        JFrame           framePrevSibling = null;

        if ( frame == null  ||  frameOwner == null  ||  !frameOwner.isShowing() )
            return;

        if ( frameOwner instanceof JMFrame  &&  ((JMFrame)frameOwner).vectorChildFrames.size() > 0 ) {
            framePrevSibling = (JFrame) ((JMFrame)frameOwner).vectorChildFrames.lastElement();
        }

        if ( framePrevSibling != null  &&  framePrevSibling.isShowing() ) {
            point = framePrevSibling.getLocationOnScreen();
            point.x += 20;
            point.y += 20;
        }
        else {
            point = frameOwner.getLocationOnScreen ();
            dimOwner = frameOwner.getSize ();
            point.y += dimOwner.height;
        }

        dim = frame.getPreferredSize ();
        dimFrame = frame.getSize ();
        dimFrame.width = Math.max ( dim.width, dimFrame.width );
        dimFrame.height = Math.max ( dim.height, dimFrame.height );
        dimScreen = Toolkit.getDefaultToolkit().getScreenSize();

        if ( point.x + dimFrame.width > dimScreen.width )
            point.x = dimScreen.width - dimFrame.width;
        if ( point.y + dimFrame.height > dimScreen.height )
            point.y = dimScreen.height - dimFrame.height;
        frame.setLocation ( point );
    }

    public void windowOpened ( WindowEvent event ) {
    }

    public void windowClosing ( WindowEvent event ) {
        //System.out.println("windowClosing em JMFrame"); 
        this.dispose ();
    }

    public void windowClosed ( WindowEvent event ) 
    {
        //System.out.println("windowClosed em JMFrame"); 
        if ( frameOwner != null  &&  frameOwner instanceof JMFrame
                    &&  ((JMFrame)frameOwner).vectorChildFrames.contains(this) ) {
            ((JMFrame)frameOwner).vectorChildFrames.removeElement ( this );
        }
    }

    public void windowIconified ( WindowEvent event ) {
    }

    public void windowDeiconified ( WindowEvent event ) {
    }

    public void windowActivated ( WindowEvent event ) {
    }

    public void windowDeactivated ( WindowEvent event ) {
    }

}


