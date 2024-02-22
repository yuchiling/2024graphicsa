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
    glutCreateWindow("20242電腦圖學的第01周");
    glutDisplayFunc(display);///148行，要用display()函式來畫圓

    glutMainLoop();///174行
}
