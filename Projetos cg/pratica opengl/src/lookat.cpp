/**
*   Programa para ilustrar:
*   - Uso da gluLookAt
*   - Pilha de transformacoes
*   - Projecao pespectiva
*   - Interacao com o mouse/teclado
*   - cullFace, frontFace

*   Autor: Cesar Tadeu Pozzer
*   UFSM - 15/06/2007
*
*   pozzer@inf.ufsm.br
*   pozzer3@gmail.com
*
**/

#include <GL/glut.h>


#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define SCREEN_X 500
#define SCREEN_Y 500

#define TAM 10

int   polygonMode = 1;

float rx = 0, rz = 0; //parametros de rotacao do objeto.

float abertura = 50.0;
float znear  = 1;
float zfar   = 23;
float aspect = 1;

float vetorY[TAM][TAM];

void init()
{

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity( );
   gluPerspective(abertura, aspect, znear, zfar);
   glMatrixMode(GL_MODELVIEW);

   glClearColor(0, 0, 0, 1);

   //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

   glEnable(GL_DEPTH_TEST);
}


////////////////////////////////////////////////////////////////////////////////////////
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   //printf("\n%f", abertura);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity( );
   //glOrtho(-1,1,-1,1,1,-1);

   //printMatrix(GL_PROJECTION_MATRIX);

   gluPerspective(abertura, aspect, znear, zfar);


   //printMatrix(GL_MODELVIEW_MATRIX);

   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity( );
   gluLookAt(0, 0, 10,  //from. Posicao onde a camera esta posicionada
             0, 0, 0,  //to. Posicao absoluta onde a camera esta vendo
             0, 1, 0); //up. Vetor Up.

   glRotatef ((GLfloat) rx, 0.0f, 1.0f, 0.0f);
   glRotatef ((GLfloat) rz, 1.0f, 0.0f, 0.0f);

   glTranslated(-TAM/2, 0, -TAM/2);

   //todos os objetos estao definidos na origem do sistema global fixo
   //e sao transladados para a posicao destino.
   glColor3f(1, 1, 1);
   glBegin(GL_TRIANGLES);
   for(int x = 0; x<TAM; x+=1){
      for(int z = 0; z<TAM; z+=1){
            //float y = vetorY[x+TAM/2][z+TAM/2];
            float yA = vetorY[x][z];
            float yB = vetorY[x+1][z];
            float yC = vetorY[x][z+1];

            float yD = vetorY[x+1][z+1];

            glVertex3f(x, yA, z);
            glVertex3f(x+1, yB, z);
            glVertex3f(x, yC, z+1);

            glVertex3f(x+1, yB, z);
            glVertex3f(x, yC, z+1);
            glVertex3f(x+1, yD, z+1);
      }
   }
   glEnd();




   glutSwapBuffers();
}


//faz a leitura da entrada do usuario
void keyboard(unsigned char key, int x, int y)
{
   //printf("%c", key);
   key = tolower(key);
   switch(key)
   {
      case 27:
	     exit(0);
	  break;

      case 'w': //wireframe
         if(polygonMode==1)
		 {
		    polygonMode=0;
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	     }
		 else
		 {
		    polygonMode=1;
		    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		 }
		break;
      case '+':
           abertura+=1;

   }
}

void MotionFunc(int x, int y)
{
//   float dx, dy;
   //printf("\nX = %d Y = %d", x, y);
   rx = x;
   rz = y;
}

void MouseFunc(int botao, int estado, int x, int y)
{
   //printf("\n%d %d %d %d", botao, estado, x, y);
}

////////////////////////////////////////////////////////////////////////////////////////
int main ()
{
   int  argc=0;
   //char *argv[1] = {"teste"};
   glutInit(&argc, NULL);

   for(int i = 0; i<TAM; i++){
      for(int j = 0; j<TAM; j++){
         vetorY[i][j] = (rand()%10)/10.0;
      }
   }

   //glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );

   glutInitWindowSize (SCREEN_X, SCREEN_Y);
   glutInitWindowPosition (450, 10);
   /* create window */
   glutCreateWindow ("GluLookAt Demo");
   init();
   printf("Digite W para mudar o modo de visualizacao: wireframe/fill");

   glutDisplayFunc(display);
   glutMotionFunc(MotionFunc);
   glutMouseFunc(MouseFunc);
   glutIdleFunc(display);
   glutKeyboardFunc(keyboard);

   glutMainLoop();
   return 0;
}
