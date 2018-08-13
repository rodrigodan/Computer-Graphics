#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>


//---------------------------------------------------------------
void free_mem(void)
{
	std::clog << "Exiting...\n";
}

//---------------------------------------------------------------
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glRotatef(0.01f, 0, 0, 1);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f( 0.5f, -0.5f, 0.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f( 0.0f,  0.5f, 0.0f);

    glEnd();
    glutSwapBuffers();
    glutPostRedisplay();
}

//---------------------------------------------------------------
int main(int argc, char **argv)
{
	std::clog << "Begin...\n";

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL: Getting Started");

	glutDisplayFunc(display);

	atexit(free_mem);

	glClearColor(0.0, 0.0, 0.3f, 1.0);

	glutMainLoop();

	return 0;
}
