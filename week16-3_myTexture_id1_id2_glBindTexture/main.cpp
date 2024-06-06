///week05_rotating_earth �M��
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * quad = NULL; ///todo: �n���@������
int id1, id2;///�n�ǳƨ�Ӿ�ƥΨӦs�K�Ϫ��N��id
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
///�A�K�W10��GLUT�{�� (���n�K��誺�{��)
float angle = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glBindTexture(GL_TEXTURE_2D, id2);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f(-1, +1);
        glTexCoord2f(0, 1); glVertex2f(-1, -1);
        glTexCoord2f(1, 1); glVertex2f(+1, -1);
        glTexCoord2f(1, 0); glVertex2f(+1, +1);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, id1);///�a�y
    glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glRotatef(angle++, 0, 0, 1);
        gluSphere(quad, 0.5, 30, 30); ///glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    id2=myTexture("c:/background.jpg");
    id1=myTexture("c:/earth.jpg");
    quad = gluNewQuadric(); ///todo:��o������,���n
    gluQuadricTexture(quad, 1);///todo: ���n�a�y���K��
    glutMainLoop();
}
