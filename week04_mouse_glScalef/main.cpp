#include <GL/glut.h>
float angle=0;///���ਤ��
float s=1;///�Y�񪺤��
void display()
{
    glClearColor(1.0, 0.0, 0.9, 1.0);///�M�I�����H����
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///�M�I��
    glPushMatrix();
        ///glRotatef(angle, 0, 0, 1);
        glScalef(s, s, s);///�Y��
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void motion(int x, int y)
{
    ///angle =x;
    s=1+(x-150)/150.0;
    display();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 mouse glScalef");
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
}
