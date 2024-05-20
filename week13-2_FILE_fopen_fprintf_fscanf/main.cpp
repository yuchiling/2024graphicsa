#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * handA = NULL;
GLMmodel * handB = NULL;
GLMmodel * upperA = NULL;
GLMmodel * lowerB = NULL;
GLMmodel * upperB = NULL;
GLMmodel * lowerA = NULL;
GLMmodel * body=NULL;
GLMmodel * leftshouder=NULL;
GLMmodel * rightshouder=NULL;
GLMmodel * head=NULL;
GLMmodel * righthend=NULL;
void drawBody(void)
{
    if (!body) {
	body = glmReadOBJ("data/body.obj");
	if (!body) exit(0);
	glmUnitize(body);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }
    glmDraw(body, GLM_SMOOTH | GLM_TEXTURE);
}

void drawLeftshouder(void)/////////////////////
{
    if (!leftshouder) {
	leftshouder = glmReadOBJ("data/leftshouder.obj");
	if (!leftshouder) exit(0);
	glmUnitize(leftshouder);
	glmFacetNormals(leftshouder);
	glmVertexNormals(leftshouder, 90.0);
    }
    glmDraw(leftshouder, GLM_SMOOTH | GLM_TEXTURE);
}
void drawRightshouder(void)/////////////////////
{
    if (!rightshouder) {
	rightshouder = glmReadOBJ("data/rightshouder.obj");
	if (!rightshouder) exit(0);
	glmUnitize(rightshouder);
	glmFacetNormals(rightshouder);
	glmVertexNormals(rightshouder, 90.0);
    }
    glmDraw(rightshouder, GLM_SMOOTH | GLM_TEXTURE);
}

void drawHead(void)
{
    if (!head) {
	head = glmReadOBJ("data/head.obj");
	if (!head) exit(0);
	glmUnitize(head);
	glmFacetNormals(head);
	glmVertexNormals(head, 90.0);
    }
    glmDraw(head, GLM_SMOOTH | GLM_TEXTURE);
}
void drawRighthend(void)
{
    if (!righthend) {
	righthend = glmReadOBJ("data/righthend.obj");
	if (!righthend) exit(0);
	glmUnitize(righthend);
	glmFacetNormals(righthend);
	glmVertexNormals(righthend, 90.0);
    }
    glmDraw(righthend, GLM_SMOOTH | GLM_TEXTURE);
}
void drawUpperA(void)
{
    if (!upperA) {
	upperA = glmReadOBJ("data/upperA.obj");
	if (!upperA) exit(0);
	glmUnitize(upperA);
	glmFacetNormals(upperA);
	glmVertexNormals(upperA, 90.0);
    }
    glmDraw(upperA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLowerA(void)
{
    if (!lowerA) {
	lowerA = glmReadOBJ("data/lowerA.obj");
	if (!lowerA) exit(0);
	glmUnitize(lowerA);
	glmFacetNormals(lowerA);
	glmVertexNormals(lowerA, 90.0);
    }
    glmDraw(lowerA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawUpperB(void)
{
    if (!upperB) {
	upperA = glmReadOBJ("data/upperB.obj");
	if (!upperB) exit(0);
	glmUnitize(upperB);
	glmFacetNormals(upperB);
	glmVertexNormals(upperB, 90.0);
    }
    glmDraw(upperB, GLM_SMOOTH | GLM_TEXTURE);
}
void drawLowerB(void)
{
    if (!lowerB) {
	lowerA = glmReadOBJ("data/lowerB.obj");
	if (!lowerB) exit(0);
	glmUnitize(lowerB);
	glmFacetNormals(lowerB);
	glmVertexNormals(lowerB, 90.0);
    }
    glmDraw(lowerB, GLM_SMOOTH | GLM_TEXTURE);
}
void drawmodel(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("data/Gundam.obj");
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE);
}
void drawHandA(void)
{
    if (!handA) {
	handA = glmReadOBJ("data/handA.obj");
	if (!handA) exit(0);
	glmUnitize(handA);
	glmFacetNormals(handA);
	glmVertexNormals(handA, 90.0);
    }
    glmDraw(handA, GLM_SMOOTH | GLM_TEXTURE);
}
void drawHandB(void)
{
    if (!handB) {
	handB = glmReadOBJ("data/handB.obj");
	if (!handB) exit(0);
	glmUnitize(handB);
	glmFacetNormals(handB);
	glmVertexNormals(handB, 90.0);
    }

    glmDraw(handB, GLM_SMOOTH | GLM_TEXTURE);
}
void myBody() { ///我的身體
	glPushMatrix(); ///備份矩陣
        glColor3f(1, 0, 0);///紅色的
        glutSolidCube(0.6);///myBody();
	glPopMatrix(); ///還原矩陣
}
///float angle = 0, da=1; ///加這行, 讓它轉動
float angle[20]={};///20個角度，都設成0
int angleID=0;///可以是角度0、角度1、角度2、...
int oldX=0, oldY=0;
#include <stdio.h>
FILE*fin=NULL;
FILE*fout=NULL;
void motion(int x, int y){///加入mouse motion對應的函式
    angle[angleID]+=y-oldY;
    oldX=x;
    oldY=y;
    glutPostRedisplay();///要重畫畫面
    if(fout==NULL) fout=fopen("angle.txt", "w+");
    for(int i=0; i<20; i++){
        printf("%.1f ", angle[i]);
        fprintf(fout, "%.1f ", angle[i]);
    }
    printf("\n");
    fprintf(fout, "\n");
}
void mouse(int button, int state, int x, int y)
{
    oldX=x;
    oldY=y;
}
void keyboard(unsigned char key, int x, int y){
    if(key=='r'){
        if(fin==NULL) fin=fopen("angle.txt", "r");
        for(int i=0; i<20; i++){
            fscanf(fin, "%f", & angle[i]);
        }
        glutPostRedisplay();
    }
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
    if(key=='4') angleID=4;
    if(key=='5') angleID=5;
    if(key=='6') angleID=6;
    if(key=='7') angleID=7;
    if(key=='8') angleID=8;
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);

    /*glPushMatrix();
        glRotatef(angle[0], 0, 1, 0);
        drawBody();
        ///glutSolidSphere(0.1, 30, 30);///圓球
        glEnable(GL_TEXTURE_2D);
        glColor3f(1,1,1);

        glPushMatrix();///左邊的手臂
            glTranslatef(-0.29,0.26,0);///掛在肩上
            glRotatef(angle[1], 0, 0, 1);
            glRotatef(angle[2], 1, 0, 0);
            glTranslatef(0, -0.08, 0);///旋轉軸
            drawLeftshouder();///(3)上手臂放好
        glPopMatrix();
        glPushMatrix(); ///右邊的手臂
            glTranslatef(0.29, 0.26, 0);
            glRotatef(angle[3], 0, 0, 1);///(2) z軸轉
            glRotatef(angle[4], 1, 0, 0);
            glTranslatef(0, -0.08, 0);///(1)
            drawRightshouder();///(0)
        glPopMatrix(); ///(0)

        glPushMatrix();///頭
            glTranslatef(0,0.43,0);///掛在肩上
            //glRotatef(angle[1], 0, 0, 1);
            //glRotatef(angle[2], 1, 0, 0);
            glRotatef(angle[5], 0, 0, 1);
            glRotatef(angle[6], 1, 0, 0);
            glTranslatef(0, 0.2, 0);///旋轉軸
            drawHead();///(3)上手臂放好
        glPopMatrix();*/
        glPushMatrix();///頭
            glTranslatef(0,0,0);///掛在肩上
            ///glTranslatef(0.1,0.5,0);///掛在肩上
            //glRotatef(angle[1], 0, 0, 1);
            //glRotatef(angle[2], 1, 0, 0);
            glRotatef(angle[7], 0, 0, 1);
            //glRotatef(angle[6], 1, 0, 0);
            glTranslatef(0, 0.05, 0);///旋轉軸
            drawRighthend();///(3)上手臂放好
        glPopMatrix();




    glPopMatrix();
    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///加這行, 讓它轉動

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week13");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///加這行, 讓它轉動
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);///week13-1新加的

    //myTexture("data/Diffuse.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
