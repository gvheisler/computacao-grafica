//package client.CSVLib.ui;

import java.awt.*;    
import java.awt.event.*;
import javax.swing.*;


public class JMDialog extends JDialog implements ActionListener, WindowListener {

    public static final String     ACTION_OK = "OK";
    public static final String     ACTION_CANCEL = "Cancel";
    public static final String     ACTION_CLOSE = "Close";
    public static final String     ACTION_OPEN = "Open";
    public static final String     ACTION_SAVE = "Save";
    public static final String     ACTION_YES = "Yes";
    public static final String     ACTION_NO = "No";

    protected JFrame        frameOwner = null;
    private String          strAction = ACTION_CANCEL;
    private boolean         boolFirstTimeVisible = true;


    public JMDialog ( JFrame frame, String strTitle, boolean boolModal ) {
        super ( frame, strTitle, boolModal );

        frameOwner = frame;
    }

    public JMDialog ( Frame frame, String strTitle, boolean boolModal ) {
        super ( frame, strTitle, boolModal );

        frameOwner = new JFrame();
        frameOwner.getContentPane().add(frame);
    }

    public void addNotify () {
	    this.setBackground ( Color.lightGray );
        this.addWindowListener ( this );

        super.addNotify ();
        autoPosition ();
    }

    public void setVisible ( boolean boolVisible ) {

        if ( boolVisible == true  &&  !this.isVisible()  &&  boolFirstTimeVisible == true ) {
            boolFirstTimeVisible = false;
            autoPosition ();
        }
        super.setVisible ( boolVisible );
    }

    public void autoPosition () {
        Dimension       dim;
        Dimension       dimFrame;
        Dimension       dimDialog;
        Dimension       dimScreen;
        Point           point;
        Insets          insets;

        if ( frameOwner != null  &&  frameOwner.isShowing() ) {
            point = frameOwner.getLocationOnScreen ();
            if ( this.isModal() ) {
                insets = frameOwner.getInsets ();
                point.x += insets.left;
                point.y += insets.top;
            }
            else {
                dimFrame = frameOwner.getSize ();
                point.y += dimFrame.height;
            }
            dim = this.getPreferredSize ();
            dimDialog = this.getSize ();
            dimDialog.width = Math.max ( dim.width, dimDialog.width );
            dimDialog.height = Math.max ( dim.height, dimDialog.height );
            dimScreen = Toolkit.getDefaultToolkit().getScreenSize();
            if ( point.x + dimDialog.width > dimScreen.width )
                point.x = dimScreen.width - dimDialog.width;
            if ( point.y + dimDialog.height > dimScreen.height )
                point.y = dimScreen.height - dimDialog.height;
            this.setLocation ( point );
        }
        else {
            setLocationCenter ();
        }
    }

    public void setLocationCenter () {
        Dimension       dimDialog;
        Dimension       dimScreen;
        Point           point;

        dimDialog = this.getSize ();
        dimScreen = Toolkit.getDefaultToolkit().getScreenSize();
        point = new Point ( (dimScreen.width - dimDialog.width) / 2,
                                (dimScreen.height - dimDialog.height) / 2 );
        this.setLocation ( point );
    }

    public String getAction () {
        return ( strAction );	
    }

    protected void setAction ( String strAction ) {
        this.strAction = strAction;
    }

    protected JFrame getOwnerFrame () {
        return ( frameOwner );
    }

    protected JMPanel createButtonPanel ( String[] arrActions ) {
        int         i;
        int         nCount;
        JMPanel     panelButtons;
        JButton     button;

        panelButtons  = new JMPanel();
        nCount = arrActions.length;
        for ( i=0;  i < nCount;  i++ ) {
            button = new JButton ( arrActions[i] );
            button.addActionListener ( this );
            panelButtons.add ( button );
        }
        return ( panelButtons );
    }

    public void actionPerformed ( ActionEvent event ) {
		System.out.println("clicou");

    }

    public void windowOpened ( WindowEvent event ) {
    }

    public void windowClosing ( WindowEvent event ) {
        this.dispose ();
    }

    public void windowClosed ( WindowEvent event ) {
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


