#include <GL/glut.h>
void myBody()///�ڪ�����
{
    glPushMatrix();///�ƥ��x�}
        glColor3f(1, 0, 0);///���⪺
        glutWireCube(0.6);///myBody();
    glPopMatrix();///�٭�x�}
}
void myArm()
{
    glPushMatrix();
        glColor3f(0, 1, 0);///��⪺
        glScalef(1, 0.4, 0.4);///myArm();
        glutWireCube(0.3);
    glPopMatrix();
}
float angle=0;///���઺����
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    myBody();///�ڪ�����
    glPushMatrix();
        glRotatef(angle++, 0, 0, 1);///���઺����
        glTranslatef(0.15, 0, 0);///(�k��)����઺���ߡA��b�e����������
        myArm();///�ڪ����u
    glPopMatrix();

	glutSwapBuffers();
}
int main(int argc, char*argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week10");
	glutDisplayFunc(display);
	glutIdleFunc(display);///���Ŧ�����
	glutMainLoop();
}
