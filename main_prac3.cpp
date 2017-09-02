//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//******** Alumno: ALVAREZ POCEROS ABRAHAM ARTURO ************//
//*************											******//
//*************											******//
//************************************************************//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
#include <stdio.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;
float R1 = 1.0f;	//CARA FRONTAL
float G1 = 0.0f;	//CARA FRONTAL
float B1 = 0.0f;	//CARA FRONTAL
float R2 = 0.0f;	//CARA DERECHA
float G2 = 1.0f;	//CARA DERECHA
float B2 = 0.0f;	//CARA DERECHA
float R3 = 0.0f;	//CARA DORSAL
float G3 = 0.0f;	//CARA DORSAL
float B3 = 1.0f;	//CARA DORSAL
float R4 = 1.0f;	//CARA IZQUIERDA
float G4 = 0.0f;	//CARA IZQUIERDA
float B4 = 1.0f;	//CARA IZQUIERDA
float R5 = 1.0f;	//CARA SUPERIOR
float G5 = 1.0f;	//CARA SUPERIOR
float B5 = 0.0f;	//CARA SUPERIOR
float R6 = 1.0f;	//CARA INFERIOR
float G6 = 1.0f;	//CARA INFERIOR
float B6 = 1.0f;	//CARA INFERIOR
float ALTURA = 0.5f;
float BASE = 0.5f;
float ANCHO = 0.5f;
int menu = 0;

void InitGL ( GLvoid )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{BASE ,-0.5, ANCHO},    //Coordenadas Vértice 0 V0	 ANCHO
				{-0.5 ,-0.5, ANCHO},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{ BASE ,-0.5, -0.5},    //Coordenadas Vértice 3 V3 ANCHO
				{ BASE ,ALTURA, ANCHO},    //Coordenadas Vértice 4 V4	 ANCHO
				{ BASE ,ALTURA, -0.5},    //Coordenadas Vértice 5 V5	 ANCHO
				{-0.5 ,ALTURA, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,ALTURA, ANCHO},    //Coordenadas Vértice 7 V7
				};


		glBegin(GL_POLYGON);	//Front
			glColor3f(R1,G1,B1);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(R2, G2, B2);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(R3, G3, B3);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(R4, G4, B4);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
	
		glColor3f(R5, G5, B5);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(R6, G6, B6);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		//Poner Código Aquí.
	


	glTranslatef(0.0 + transX, 0.0 + transY, -5.0 + transZ);			//traslada el objeto (-5 unidades en el plano Z)	glTranslatef(X, Y, Z);
	glRotatef(angleX,1.0,0.0,0.0);					//glRotatef(angleX, x, y, z)
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);

	prisma();

	
	if (menu != 1) {
		printf("\n\tZ: cambiar color cara frontal");
		printf("\n\tX: cambiar color cara derecha");
		printf("\n\tC: cambiar color cara dorsal");
		printf("\n\tV: cambiar color cara izquierda");
		printf("\n\tB: cambiar color cara superior");
		printf("\n\tN: cambiar color cara inferior");
		printf("\n\tP: cambiar tamaño de la base");
		printf("\n\tI: cambiar tamaño del ancho");
		printf("\n\tO: cambiar tamaño de la altura");
		printf("\n\tIngresa opcion:");
		menu = 1;
	}
	
		
  											

    glutSwapBuffers ( );
    //glFlush();
    // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum(-0.1, 0.1,-0.1, 0.1, 0.1, 10);			//traslada la vista
	//glFrustum (izq, der,inf, sup, cerca, lejos);
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{


	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;

		case 'q':
		case 'Q':
			transY -= 0.2f;
			
			break;
		case 'e':
		case 'E':
			transY += 0.2f;
	
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			break;
		case 'd':
		case 'D':
			transX +=0.2f;
			break;
		case 'r':
		case 'R':
			angleX += 10.0f;
			break;
		case 'F':
		case 'f':
			angleX -= 10.0f;
			break;
		case 't':
		case 'T':
			angleY += 10.0f;
			break;
		case 'g':
		case 'G':
			angleY -= 10.0f;
			break;
		case 'y':
		case 'Y':
			angleZ += 10.0f;
			break;
		case 'h':
		case 'H':
			angleZ -= 10.0f;
			break;
		

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
		case 'Z':
		case 'z':
			printf("\n\tCambiar los colores de la cara Frontal:");
			scanf_s("%f,%f,%f", &R1, &G1, &B1);
			break;
		case 'X':
		case 'x':
			printf("\n\tCambiar los colores de la cara Derecha:");
			scanf_s("%f,%f,%f", &R2, &G2, &B2);
			break;
		case 'C':
		case 'c':
			printf("\n\tCambiar los colores de la cara Dorsal:");
			scanf_s("%f,%f,%f", &R3, &G3, &B3);
			break;
		case 'v':
		case 'V':
			printf("\n\tCambiar los colores de la cara Izquierda:");
			scanf_s("%f,%f,%f", &R4, &G4, &B4);
			break;
		case 'b':
		case 'B':
			printf("\n\tCambiar los colores de la cara Superior:");
			scanf_s("%f,%f,%f", &R5, &G5, &B5);
			break;
		case 'n':
		case 'N':
			printf("\n\tCambiar los colores de la cara Inferior:");
			scanf_s("%f,%f,%f", &R6, &G6, &B6);
			break;
		case 'P':
		case 'p':
			printf("\n\tCambiar la base:");
			scanf_s("%f,%f,%f", &BASE);
			break;
		case 'o':
		case 'O':
			printf("\n\tCambiar la altura:");
			scanf_s("%f",&ALTURA);
			break;
		case 'i':
		case 'I':
			printf("\n\tCambiar el ancho:");
			scanf_s("%f", &ANCHO);
			break;
			
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
      //glutFullScreen ( ); // Full Screen Mode
      //break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
      //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
      //break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
	if (menu != 1) {
		printf("\n\tZ: cambiar color cara frontal");
		printf("\n\tX: cambiar color cara derecha");
		printf("\n\tC: cambiar color cara dorsal");
		printf("\n\tV: cambiar color cara izquierda");
		printf("\n\tB: cambiar color cara superior");
		printf("\n\tN: cambiar color cara inferior");
		printf("\n\tP: cambiar tamaño de la base");
		printf("\n\tI: cambiar tamaño del ancho");
		printf("\n\tO: cambiar tamaño de la altura");
		printf("\n\tIngresa opcion:");
		menu = 1;
	}

  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 
  
  return 0;
}



