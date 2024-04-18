#include <GL/glut.h>
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();///備份矩陣
        glTranslatef(-0.5, +0.3, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glPushMatrix();///備份矩陣
        glTranslatef(+0.0, +0.3, 0);
        glutSolidCube(0.3);
    glPopMatrix();///還原矩陣
    glPushMatrix();///備份矩陣
        glTranslatef(+0.5, +0.3, 0);
        glutSolidSphere(0.3, 30, 30);
    glPopMatrix();///還原矩陣

    glPushMatrix();///備份矩陣
        glTranslatef(-0.5, -0.3, 0);
        glutWireTeapot(0.3);
    glPopMatrix();///還原矩陣
    glPushMatrix();///備份矩陣
        glTranslatef(+0.0, -0.3, 0);
        glutWireCube(0.3);
    glPopMatrix();///還原矩陣
    glPushMatrix();///備份矩陣
        glTranslatef(+0.5, -0.3, 0);
        glutWireSphere(0.3, 30, 30);
    glPopMatrix();///還原矩陣


	glutSwapBuffers();
}
int main(int argc, char*argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week09 Microsoft Visual Studio");
	glutDisplayFunc(display);
	glutMainLoop();
}
