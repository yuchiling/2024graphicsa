#include <GL/glut.h>
#include <mmsystem.h>///�[�W�n��
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
    glPushMatrix();///�k�b��
        glTranslatef(0.3, 0.3, 0);///(3)����ӤW
        glRotatef(angle, 0, 0, 1);///(2)���઺����
        glTranslatef(0.15, 0, 0);///(1)����઺���ߡA��b�e����������
        myArm();///�ڪ��k�W���u

        glPushMatrix();
            glTranslatef(0.15, 0, 0);///(3)�����y�W
            glRotatef(angle, 0, 0, 1);///(2)����
            glTranslatef(0.15, 0, 0);///(1)����઺���ߡA��b�e����������
            myArm();///�ڪ��k�U���u
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();///���b��
        glTranslatef(-0.3, 0.3, 0);///(3)����ӤW
        glRotatef(-angle, 0, 0, 1);///(2)���઺����
        glTranslatef(-0.15, 0, 0);///(1)����઺���ߡA��b�e����������
        myArm();///�ڪ����W���u

        glPushMatrix();
            glTranslatef(-0.15, 0, 0);///(3)�����y�W
            glRotatef(-angle, 0, 0, 1);///(2)����
            glTranslatef(-0.15, 0, 0);///(1)����઺���ߡA��b�e����������
            myArm();///�ڪ����U���u
        glPopMatrix();

    glPopMatrix();

	glutSwapBuffers();
}
void motion(int x, int y)///week10-7 �[�Wmouse motion
{
    angle=x;///week10-7 �[�Wmouse motion
    glutPostRedisplay();///�i�DGLUT�A�K�W�K�Q�K�A��GLUT���ŮɡA�N�n���e�e��
}
int main(int argc, char*argv[])
{
    PlaySound("C:/horse.wav", NULL, SND_ASYNC);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week10");

	glutDisplayFunc(display);
	glutMotionFunc(motion);///week10-7 �[�Wmouse motion
	glutIdleFunc(display);///���Ŧ�����

	glutMainLoop();
}
