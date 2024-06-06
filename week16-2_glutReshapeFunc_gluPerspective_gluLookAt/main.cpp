#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot( 0.3 );
    glutSwapBuffers();

}
void reshape(int w, int h){
    glViewport(0, 0, w, h);///�]�w�����|�ݨ쪺�ϰ�
    float ar= w/(float) h;///���e��B�e����
    glMatrixMode(GL_PROJECTION); ///������v�x�}
    glLoadIdentity();
    gluPerspective(60, ar, 0.01, 100);///�z����v

    glMatrixMode(GL_MODELVIEW);///����model view�x�}
    glLoadIdentity();
    gluLookAt(0, 0, -2, 0, 0, 0, 0, 1, 0);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(300, 600);///������j�p
    glutCreateWindow("week16-2");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
}




