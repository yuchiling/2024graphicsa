#include <GL/glut.h>///

void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("20242�q���ϾǪ���01�P");
    glutDisplayFunc(display);///148��A�n��display()�禡�ӵe��

    glutMainLoop();///174��
}
