#include<GL/Glut.h> //includes the opengl, glu, and glut header files
#include<stdlib.h> //includes the standard library header file
#include<iostream>
#include<cmath>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
float vertices[] =
{
	0.5, 0.5,
	0, 0.5,
	0, 0, 
	0.5, 0
	
};
void draw(void)
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);
	//glBegin(GL_POLYGON);
	//glutSwapBuffers();
	glVertex2f(vertices[0], vertices[1]);
	glVertex2f(vertices[2], vertices[3]);
	glVertex2f(vertices[4], vertices[5]);
	glVertex2f(vertices[6], vertices[7]);
	glEnd();
	glFlush();
}
void Display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1, .25, .75, 1);
	draw();
}
void rotate(float th)
{
	vertices[0] = vertices[0] * cos(th*(M_1_PI/180)) - vertices[1] * sin(th*(M_1_PI / 180));
	vertices[2]= vertices[2] * cos(th*(M_1_PI / 180)) - vertices[3] * sin(th*(M_1_PI / 180));
	vertices[4]= vertices[4] * cos(th*(M_1_PI / 180)) - vertices[5] * sin(th*(M_1_PI / 180));
	vertices[6]= vertices[6] * cos(th*(M_1_PI / 180)) - vertices[7] * sin(th*(M_1_PI / 180));

	vertices[1]= vertices[0] * sin(th*(M_1_PI / 180))+ vertices[1] * cos(th*(M_1_PI / 180));
	vertices[3]= vertices[2] * sin(th*(M_1_PI / 180))+ vertices[3] * cos(th*(M_1_PI / 180));
	vertices[5]= vertices[4] * sin(th*(M_1_PI / 180))+ vertices[5] * cos(th*(M_1_PI / 180));
	vertices[7]= vertices[6] * sin(th*(M_1_PI / 180))+ vertices[7] * cos(th*(M_1_PI / 180));

	draw();

}
void changeY(float x)
{
	vertices[0] += x;
	vertices[2] += x;
	vertices[4] += x;
	vertices[6] += x;
	/*cout << vertices[0] << endl;
	cout << vertices[2] << endl;
	cout << vertices[4] << endl;
	cout << vertices[6] << endl;*/
	draw();
}
void changeX(float x)
{
	vertices[1] += x;
	vertices[3] += x;
	vertices[5] += x;
	vertices[7] += x;
	/*cout << vertices[1] << endl;
	cout << vertices[3] << endl;
	cout << vertices[5] << endl;
	cout << vertices[7] << endl;*/
	draw();
}
void scale(float x)
{
	for(int i = 0 ; i < 8 ; i++)
	vertices[i] *= x;
	
}
void keyPressed(unsigned char key, int x, int y) {
	
	switch (key)
	{
	case 'B':
	case 'b':
		scale(1.2);
		cout << "Scale Big" << endl;
		break;
	case 'S':
	case 's':
		scale(0.8);
		cout << "Scale Small" << endl;
		break;
	case 'L':
	case 'l':
		rotate(-5);
		cout << "Rotate left" << endl;
		break;
	case 'R':
	case 'r':
		rotate(5);
		cout << "Rotate Right" << endl;
		break;
	/*case 'W':
	case 'w':
		changeX(0.1);
		cout << "UP"<<endl;
		break;
	case 'S':
	case 's':
		changeX(-0.1);
		cout << "DOWN" << endl;
		break;
	case 'A':
	case 'a':
		changeY(-0.1);
		cout << "LEFT"<< endl;
		break;
	case 'D':
	case 'd':
		changeY(0.1);
		cout << "RIGHT" << endl;
		break;*/
	}
}
void keypressSpecial(int key, int x, int y)
{
	//glutSetKeyRepeat(0);

	if (key == GLUT_KEY_UP) {
		changeX(0.1);
		//do something here
		cout << "up " << endl;
	}

	if (key == GLUT_KEY_DOWN) {
		changeX(-0.1);
		cout << "down" << endl;
	}

	if (key == GLUT_KEY_RIGHT) {
		changeY(0.1);
		cout << "right" << endl;
	}

	if (key == GLUT_KEY_LEFT) {
		changeY(-0.1);
		cout << "left" << endl;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 640);   //sets the width and height of the window in pixels
	glutInitWindowPosition(100, 50);//sets the position of the window in pixels from top left corner 
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//creates a single frame buffer of RGB color capacity.
	glutCreateWindow("DDA Line Drawing");//creates the window as specified by the user as above.
	glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed  
	glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
	//gluOrtho2D(-100, 100, -100, 100);
	glClearColor(1, 1, 1, 0); // sets the backgraound color to white light
	glClear(GL_COLOR_BUFFER_BIT); // clears the frame buffer and set values defined in glClearColor() function call 

	glutDisplayFunc(Display);//links the display event with the display event handler(display)
	glutIdleFunc(Display);
	glutSpecialFunc(keypressSpecial);
	//glutMouseFunc(mouse);//keyboard event handler

	glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses  
	glutMainLoop();//loops the current event
}

//void mouse(int button, int state, int mousex, int mousey)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		check = true;
//
//		x = mousex;
//		y = 480 - mousey;
//
//		r = (rand() % 9) / 8;
//		g = (rand() % 9) / 8;
//		b = (rand() % 9) / 8;
//
//		if (first)
//		{
//			lineVertices[0] = x;
//			lineVertices[1] = y;
//			lineVertices[3] = x;
//			lineVertices[4] = y;
//			first = false;
//			glutPostRedisplay();
//			return;
//		}
//		lineVertices[0] = lineVertices[3];
//		lineVertices[1] = lineVertices[4];
//		lineVertices[3] = x;
//		lineVertices[4] = y;
//	}
//
//	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)//undo(clear)the drawing
//	{
//		glClearColor(1, 1, 1, 0);
//		glClear(GL_COLOR_BUFFER_BIT);
//		check = false;
//	}
//	glutPostRedisplay();
//}
//
//void display(void)
//{
//	glColor3f(r, g, b); // sets the current drawing (foreground) color to blue 
//	glPointSize(50); // sets the size of points to be drawn (in pixels)
//
//	glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
//	glLoadIdentity();//multiply the current matrix by identity matrix
//	gluOrtho2D(0.0, 640.0, 0.0, 480.0);//sets the parallel(orthographic) projection of the full frame buffer 
//
//	if (check)
//	{
//		glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
//							//glVertex2i(x, y);   // sets vertex
//
//		glEnd();
//	}
//
//	glEnable(GL_LINE_SMOOTH);
//	//glEnable(GL_LINE_STIPPLE);
//	glPushAttrib(GL_LINE_BIT);
//	glLineWidth(10);
//	glLineStipple(1, 0x00FF);
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glVertexPointer(3, GL_FLOAT, 0, lineVertices);
//	glDrawArrays(GL_LINES, 0, 2);
//	glDisableClientState(GL_VERTEX_ARRAY);
//	glPopAttrib();
//	//glDisable(GL_LINE_STIPPLE);
//	glDisable(GL_LINE_SMOOTH);
//
//	glFlush();     // flushes the frame buffer to the screen
//}