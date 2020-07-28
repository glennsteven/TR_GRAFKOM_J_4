#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int a;
void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran (int, int);
void mouse (int button, int state, int x, int y);
void mouseMotion(int x, int y);
void timer(int value);

float gerak = 0.0f, gerak1 = 0.0f;
float gerakkali = 0.5f, gerakkali1 = 0.5f;
bool kanan = true, kiri = true;

double pin=0, tag=0;
float xrot = 0.0;
float yrot = 0.0;
float zrot = 0.0;
float xdiff = 0.0;
float ydiff = 0.0;
bool mouseDown = false;
int is_depth;
float x1=10.0;

void ngon(int n, float cx, float cy, float radius, float rotAngle){
    double angle, angleInc;
    int k;
    if(n<3) return;
    angle = rotAngle*3.14159265/180;
    angleInc = 2*3.14159265/n;

    glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
        for(k=0; k<n; k++){
            angle += angleInc;
            glVertex2f(radius*cos(angle)+cy, radius*sin(angle)+cy);
        }
}
void waktu(int i){
    a+=29;
	glutTimerFunc(700, waktu, 10);//mengatur waktu
	glutPostRedisplay();
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(950,650);
    glutInitWindowPosition(250,80);
    glutCreateWindow("Kelompok 4");
    init();
    waktu(10);//code untuk bergerak, 0-tak terhingga bisa tetap bergerak, kecuali tidak ada code ini dia berhenti
    glutDisplayFunc(tampil);
    glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutTimerFunc(0, timer, 0);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}
void timer(int value){
    glutPostRedisplay();
    glutTimerFunc(1000/30, timer, 0);
    if(gerak < 20.0 && kanan)
        gerak += gerakkali;
    else
        kanan = false;

    if(gerak > -10.5f && !kanan)
        gerak -= gerakkali;
    else
        kanan = true;


    if(gerak1 > -20.0 && kiri)
        gerak1 -= gerakkali1;
    else
        kiri = false;

    if(gerak1 < 10.5f && !kiri)
        gerak1 += gerakkali1;
    else
        kiri = true;
}
void pintu_atap(){
        //pintu kanan
        glBegin(GL_POLYGON);
        glColor3ub(140, 140, 140);
        glVertex3f(240.0,0.0,155);
        glColor3ub(255, 255, 255);
        glVertex3f(240.0,32.0,155);
        glVertex3f(255.0,32.0,142.0);
        glColor3ub(140, 140, 140);
        glVertex3f(255.0,0.0,142.0);
        glEnd();
        //atap kiri
        glBegin(GL_POLYGON);
        glColor3ub(204, 102, 0);
        glVertex3f(238.0,32.0,170);
        glVertex3f(249.0,45.0,164);
        glVertex3f(248.0,45.0,147.7);
        glVertex3f(237.0,32.0,156.5);
        glEnd();
        //atap kanan
        glBegin(GL_POLYGON);
        glColor3ub(204, 102, 0);
        glVertex3f(258.0,32.0,155);
        glVertex3f(249.0,45.0,164);
        glVertex3f(248.0,45.0,147.7);
        glVertex3f(257.0,32.0,140.5);
        glEnd();
        //atap depan
        glBegin(GL_TRIANGLES);
        glColor3ub(204, 102, 0);
        glVertex3f(238.0,32.0,170);
        glVertex3f(258.0,32.0,155);
        glVertex3f(249.0,45.0,164);
        glEnd();
        //atap bawah
        glBegin(GL_QUADS);
        glColor3ub(204, 102, 0);
        glVertex3f(238.0,32.0,170);
        glVertex3f(258.0,32.0,155);
        glVertex3f(257.0,32.0,140.5);
        glVertex3f(237.0,32.0,156.5);
        glEnd();

        //pintu kiri
        glBegin(GL_POLYGON);
        glColor3ub(140, 140, 140);
        glVertex3f(-240.0,0.0,155);
        glColor3ub(255, 255, 255);
        glVertex3f(-240.0,32.0,155);
        glVertex3f(-255.0,32.0,142.0);
        glColor3ub(140, 140, 140);
        glVertex3f(-255.0,0.0,142.0);
        glEnd();
        //atap kiri
        glBegin(GL_POLYGON);
        glColor3ub(204, 102, 0);
        glVertex3f(-238.0,32.0,170);
        glVertex3f(-249.0,45.0,164);
        glVertex3f(-248.0,45.0,147.7);
        glVertex3f(-237.0,32.0,156.5);
        glEnd();
        //atap kanan
        glBegin(GL_POLYGON);
        glColor3ub(204, 102, 0);
        glVertex3f(-258.0,32.0,155);
        glVertex3f(-249.0,45.0,164);
        glVertex3f(-248.0,45.0,147.7);
        glVertex3f(-257.0,32.0,140.5);
        glEnd();
        //atap depan
        glBegin(GL_TRIANGLES);
        glColor3ub(204, 102, 0);
        glVertex3f(-238.0,32.0,170);
        glVertex3f(-258.0,32.0,155);
        glVertex3f(-249.0,45.0,164);
        glEnd();
        //atap bawah
        glBegin(GL_QUADS);
        glColor3ub(204, 102, 0);
        glVertex3f(-238.0,32.0,170);
        glVertex3f(-258.0,32.0,155);
        glVertex3f(-257.0,32.0,140.5);
        glVertex3f(-237.0,32.0,156.5);
        glEnd();


}
void subgedung_kanan(){
    glBegin(GL_QUADS);
    //1
        glColor3ub(255, 247, 230);
        glVertex3f(132.0,150.0,10.0);
        glVertex3f(132.0,120.0,10.0);
        glVertex3f(220.0,120.0,170);
        glVertex3f(220.0,150.0,170);

            glVertex3f(132.0,80.0,10.0);
            glVertex3f(132.0,100.0,10.0);
            glVertex3f(220.0,100.0,170);
            glVertex3f(220.0,80.0,170);

            glVertex3f(132.0,40.0,10.0);
            glVertex3f(132.0,60.0,10.0);
            glVertex3f(220.0,60.0,170);
            glVertex3f(220.0,40.0,170);
            //
            glVertex3f(132.0,150.0,10.0);
            glVertex3f(132.0,20.0,10.0);
            glVertex3f(140.0,20.0,25.0);
            glVertex3f(140.0,150.0,25.0);

            glVertex3f(160.0,20.0,61);
            glVertex3f(160.0,150.0,61);
            glVertex3f(170.0,150.0,79.0);
            glVertex3f(170.0,20.0,79.0);

            glVertex3f(190.0,20.0,115.6);
            glVertex3f(190.0,150.0,115.6);
            glVertex3f(200.0,150.0,133.4);
            glVertex3f(200.0,20.0,133.4);

            glVertex3f(215.0,150.0,161);
            glVertex3f(215.0,20.0,161);
            glVertex3f(220.0,20.0,170);
            glVertex3f(220.0,150.0,170);
    //2
        glVertex3f(220.0,0.0,170);
        glVertex3f(220.0,150.0,170);
        glVertex3f(270.0,150.0,130.0);
        glVertex3f(270.0,0.0,130.0);

    //3
        glVertex3f(270.0,0.0,130.0);
        glVertex3f(270.0,125.0,130.0);
        glVertex3f(310.0,125.0,95.0);
        glVertex3f(310.0,0.0,95.0);
    //4
        glVertex3f(310.0,0.0,95.0);
        glVertex3f(310.0,125.0,95.0);
        glVertex3f(245.0,125.0,-60.0);
        glVertex3f(245.0,0.0,-60.0);
    //5
        glVertex3f(245.0,0.0,-60.0);
        glVertex3f(245.0,125.0,-60.0);
        glVertex3f(245.0,125.0,-100.0);
        glVertex3f(245.0,0.0,-100.0);
    //6
        glVertex3f(245.0,0.0,-100.0);
        glVertex3f(245.0,125.0,-100.0);
        glVertex3f(290.0,125.0,-200.0);
        glVertex3f(290.0,0.0,-200.0);
    //7
        glVertex3f(290.0,0.0,-200.0);
        glVertex3f(290.0,125.0,-200.0);
        glVertex3f(190.0,125.0,-260.0);
        glVertex3f(190.0,0.0,-260.0);
    //8
        glVertex3f(132.0,0.0,-190.0);
        glVertex3f(132.0,125.0,-190.0);
        glVertex3f(190.0,125.0,-260.0);
        glVertex3f(190.0,0.0,-260.0);

        //jendela
            glColor3ub(140, 140, 140);
            glVertex3f(140.0,120.0,25.0);
            glColor3ub(255, 255, 255);
            glVertex3f(140.0,100.0,25.0);
            glColor3ub(140, 140, 140);
            glVertex3f(160.0,100.0,61);
            glColor3ub(255, 255, 255);
            glVertex3f(160.0,120.0,61);

            glColor3ub(140, 140, 140);
            glVertex3f(170.0,120.0,79.0);
            glColor3ub(255, 255, 255);
            glVertex3f(170.0,100.0,79.0);
            glColor3ub(140, 140, 140);
            glVertex3f(190.0,100.0,115.6);
            glColor3ub(255, 255, 255);
            glVertex3f(190.0,120.0,115.6);

            glColor3ub(140, 140, 140);
            glVertex3f(200.0,120.0,133.4);
            glColor3ub(255, 255, 255);
            glVertex3f(200.0,100.0,133.4);
            glColor3ub(140, 140, 140);
            glVertex3f(215.0,100.0,161);
            glColor3ub(255, 255, 255);
            glVertex3f(215.0,120.0,161);
            //
            glColor3ub(140, 140, 140);
            glVertex3f(140.0,80.0,25.0);
            glColor3ub(255, 255, 255);
            glVertex3f(140.0,60.0,25.0);
            glColor3ub(140, 140, 140);
            glVertex3f(160.0,60.0,61);
            glColor3ub(255, 255, 255);
            glVertex3f(160.0,80.0,61);

            glColor3ub(140, 140, 140);
            glVertex3f(170.0,80.0,79.0);
            glColor3ub(255, 255, 255);
            glVertex3f(170.0,60.0,79.0);
            glColor3ub(140, 140, 140);
            glVertex3f(190.0,60.0,115.6);
            glColor3ub(255, 255, 255);
            glVertex3f(190.0,80.0,115.6);

            glColor3ub(140, 140, 140);
            glVertex3f(200.0,80.0,133.4);
            glColor3ub(255, 255, 255);
            glVertex3f(200.0,60.0,133.4);
            glColor3ub(140, 140, 140);
            glVertex3f(215.0,60.0,161);
            glColor3ub(255, 255, 255);
            glVertex3f(215.0,80.0,161);
            //
            glColor3ub(140, 140, 140);
            glVertex3f(140.0,40.0,25.0);
            glColor3ub(255, 255, 255);
            glVertex3f(140.0,20.0,25.0);
            glColor3ub(140, 140, 140);
            glVertex3f(160.0,20.0,61);
            glColor3ub(255, 255, 255);
            glVertex3f(160.0,40.0,61);

            glColor3ub(140, 140, 140);
            glVertex3f(170.0,40.0,79.0);
            glColor3ub(255, 255, 255);
            glVertex3f(170.0,20.0,79.0);
            glColor3ub(140, 140, 140);
            glVertex3f(190.0,20.0,115.6);
            glColor3ub(255, 255, 255);
            glVertex3f(190.0,40.0,115.6);

            glColor3ub(140, 140, 140);
            glVertex3f(200.0,40.0,133.4);
            glColor3ub(255, 255, 255);
            glVertex3f(200.0,20.0,133.4);
            glColor3ub(140, 140, 140);
            glVertex3f(215.0,20.0,161);
            glColor3ub(255, 255, 255);
            glVertex3f(215.0,40.0,161);
        //
        glColor3ub(204, 102, 0);
        glVertex3f(132.0,150.0,10.0);
        glVertex3f(132.0,165.0,10.0);
        glVertex3f(220.0,165.0,170);
        glVertex3f(220.0,150.0,170);

        glVertex3f(220.0,165.0,170);
        glVertex3f(220.0,150.0,170);
        glVertex3f(270.0,150.0,130.0);
        glVertex3f(270.0,165.0,130.0);

        glVertex3f(132.0,0.0,10.5);
        glVertex3f(132.0,20.0,10.5);
        glVertex3f(220.0,20.0,170.4);
        glVertex3f(220.0,0.0,170.4);

        //atap
        glColor3ub(230,230,230);
        glVertex3f(132.0,165.0,10.0);
        glVertex3f(220.0,165.0,170);
        glVertex3f(270.0,165.0,130.0);
        glVertex3f(190.0,165.0,-28.0);

        glVertex3f(270.0,165.0,130.0);
        glVertex3f(190.0,165.0,-28.0);
        glVertex3f(190.0,125.0,-28.0);
        glVertex3f(270.0,125.0,130.0);

        glVertex3f(270.0,125.0,130.0);
        glVertex3f(310.0,125.0,95.0);
        glVertex3f(245.0,125.0,-60.0);
        glVertex3f(190.0,125.0,-28.0);

        glVertex3f(245.0,125.0,-60.0);
        glVertex3f(245.0,125.0,-90.0);
        glVertex3f(178.0,125.0,-90.0);
        glVertex3f(190.0,125.0,-28.0);

        glVertex3f(245.0,125.0,-90.0);
        glVertex3f(245.0,125.0,-100.0);
        glVertex3f(190.0,125.0,-152.0);
        glVertex3f(178.0,125.0,-90.0);

        glVertex3f(190.0,125.0,-260.0);
        glVertex3f(290.0,125.0,-200.0);
        glVertex3f(245.0,125.0,-100.0);
        glVertex3f(132.0,125.0,-190.0);

    glEnd();
}
void subgedung_kiri(){
    glBegin(GL_QUADS);
    //1
        //1
        glColor3ub(255, 247, 230);
        glVertex3f(-132.0,150.0,10.0);
        glVertex3f(-132.0,120.0,10.0);
        glVertex3f(-220.0,120.0,170);
        glVertex3f(-220.0,150.0,170);

            glVertex3f(-132.0,80.0,10.0);
            glVertex3f(-132.0,100.0,10.0);
            glVertex3f(-220.0,100.0,170);
            glVertex3f(-220.0,80.0,170);

            glVertex3f(-132.0,40.0,10.0);
            glVertex3f(-132.0,60.0,10.0);
            glVertex3f(-220.0,60.0,170);
            glVertex3f(-220.0,40.0,170);
            //
            glVertex3f(-132.0,150.0,10.0);
            glVertex3f(-132.0,0.0,10.0);
            glVertex3f(-140.0,0.0,25.0);
            glVertex3f(-140.0,150.0,25.0);

            glVertex3f(-160.0,0.0,61);
            glVertex3f(-160.0,150.0,61);
            glVertex3f(-170.0,150.0,79.0);
            glVertex3f(-170.0,0.0,79.0);

            glVertex3f(-190.0,0.0,115.6);
            glVertex3f(-190.0,150.0,115.6);
            glVertex3f(-200.0,150.0,133.4);
            glVertex3f(-200.0,0.0,133.4);

            glVertex3f(-215.0,150.0,161);
            glVertex3f(-215.0,0.0,161);
            glVertex3f(-220.0,0.0,170);
            glVertex3f(-220.0,150.0,170);
    //2
        glVertex3f(-220.0,0.0,170);
        glVertex3f(-220.0,150.0,170);
        glVertex3f(-270.0,150.0,130.0);
        glVertex3f(-270.0,0.0,130.0);
    //3
        glVertex3f(-270.0,0.0,130.0);
        glVertex3f(-270.0,125.0,130.0);
        glVertex3f(-310.0,125.0,95.0);
        glVertex3f(-310.0,0.0,95.0);
    //4
        glVertex3f(-310.0,0.0,95.0);
        glVertex3f(-310.0,125.0,95.0);
        glVertex3f(-245.0,125.0,-60.0);
        glVertex3f(-245.0,0.0,-60.0);
    //5
        glVertex3f(-245.0,0.0,-60.0);
        glVertex3f(-245.0,125.0,-60.0);
        glVertex3f(-245.0,125.0,-100.0);
        glVertex3f(-245.0,0.0,-100.0);
    //6
        glVertex3f(-245.0,0.0,-100.0);
        glVertex3f(-245.0,125.0,-100.0);
        glVertex3f(-290.0,125.0,-200.0);
        glVertex3f(-290.0,0.0,-200.0);
    //7
        glVertex3f(-290.0,0.0,-200.0);
        glVertex3f(-290.0,125.0,-200.0);
        glVertex3f(-190.0,125.0,-260.0);
        glVertex3f(-190.0,0.0,-260.0);

    //7.5
        glVertex3f(-240.0,0.0,-230.0);
        glVertex3f(-240.0,165.0,-230.0);
        glVertex3f(-190.0,165.0,-260.0);
        glVertex3f(-190.0,0.0,-260.0);

    //8
        glVertex3f(-132.0,0.0,-190.0);
        glVertex3f(-132.0,165.0,-190.0);
        glVertex3f(-190.0,165.0,-260.0);
        glVertex3f(-190.0,0.0,-260.0);

        //jendela
            glColor3ub(140, 140, 140);
            glVertex3f(-140.0,120.0,25.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-140.0,100.0,25.0);
            glColor3ub(140, 140, 140);
            glVertex3f(-160.0,100.0,61);
            glColor3ub(255, 255, 255);
            glVertex3f(-160.0,120.0,61);

            glColor3ub(140, 140, 140);
            glVertex3f(-170.0,120.0,79.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-170.0,100.0,79.0);
            glColor3ub(140, 140, 140);
            glVertex3f(-190.0,100.0,115.6);
            glColor3ub(255, 255, 255);
            glVertex3f(-190.0,120.0,115.6);

            glColor3ub(140, 140, 140);
            glVertex3f(-200.0,120.0,133.4);
            glColor3ub(255, 255, 255);
            glVertex3f(-200.0,100.0,133.4);
            glColor3ub(140, 140, 140);
            glVertex3f(-215.0,100.0,161);
            glColor3ub(255, 255, 255);
            glVertex3f(-215.0,120.0,161);
            //
            glColor3ub(140, 140, 140);
            glVertex3f(-140.0,80.0,25.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-140.0,60.0,25.0);
            glColor3ub(140, 140, 140);
            glVertex3f(-160.0,60.0,61);
            glColor3ub(255, 255, 255);
            glVertex3f(-160.0,80.0,61);

            glColor3ub(140, 140, 140);
            glVertex3f(-170.0,80.0,79.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-170.0,60.0,79.0);
            glColor3ub(140, 140, 140);
            glVertex3f(-190.0,60.0,115.6);
            glColor3ub(255, 255, 255);
            glVertex3f(-190.0,80.0,115.6);

            glColor3ub(140, 140, 140);
            glVertex3f(-200.0,80.0,133.4);
            glColor3ub(255, 255, 255);
            glVertex3f(-200.0,60.0,133.4);
            glColor3ub(140, 140, 140);
            glVertex3f(-215.0,60.0,161);
            glColor3ub(255, 255, 255);
            glVertex3f(-215.0,80.0,161);
            //
            glColor3ub(140, 140, 140);
            glVertex3f(-140.0,40.0,25.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-140.0,20.0,25.0);
            glColor3ub(140, 140, 140);
            glVertex3f(-160.0,20.0,61);
            glColor3ub(255, 255, 255);
            glVertex3f(-160.0,40.0,61);

            glColor3ub(140, 140, 140);
            glVertex3f(-170.0,40.0,79.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-170.0,20.0,79.0);
            glColor3ub(140, 140, 140);
            glVertex3f(-190.0,20.0,115.6);
            glColor3ub(255, 255, 255);
            glVertex3f(-190.0,40.0,115.6);

            glColor3ub(140, 140, 140);
            glVertex3f(-200.0,40.0,133.4);
            glColor3ub(255, 255, 255);
            glVertex3f(-200.0,20.0,133.4);
            glColor3ub(140, 140, 140);
            glVertex3f(-215.0,20.0,161);
            glColor3ub(255, 255, 255);
            glVertex3f(-215.0,40.0,161);
        //
        glColor3ub(204, 102, 0);
        glVertex3f(-132.0,150.0,10.0);
        glVertex3f(-132.0,165.0,10.0);
        glVertex3f(-220.0,165.0,170);
        glVertex3f(-220.0,150.0,170);

        glVertex3f(-220.0,165.0,170);
        glVertex3f(-220.0,150.0,170);
        glVertex3f(-270.0,150.0,130.0);
        glVertex3f(-270.0,165.0,130.0);

        glVertex3f(-132.0,0.0,10.5);
        glVertex3f(-132.0,20.0,10.5);
        glVertex3f(-220.0,20.0,170.4);
        glVertex3f(-220.0,0.0,170.4);

        //atap
        glColor3ub(230,230,230);
        glVertex3f(-132.0,165.0,10.0);
        glVertex3f(-220.0,165.0,170);
        glVertex3f(-270.0,165.0,130.0);
        glVertex3f(-190.0,165.0,-28.0);

        glVertex3f(-270.0,165.0,130.0);
        glVertex3f(-190.0,165.0,-28.0);
        glVertex3f(-190.0,125.0,-28.0);
        glVertex3f(-270.0,125.0,130.0);

        glVertex3f(-270.0,125.0,130.0);
        glVertex3f(-310.0,125.0,95.0);
        glVertex3f(-245.0,125.0,-60.0);
        glVertex3f(-190.0,125.0,-28.0);

        glVertex3f(-245.0,125.0,-60.0);
        glVertex3f(-245.0,125.0,-90.0);
        glVertex3f(-178.0,125.0,-90.0);
        glVertex3f(-190.0,125.0,-28.0);

        glVertex3f(-245.0,125.0,-90.0);
        glVertex3f(-245.0,125.0,-100.0);
        glVertex3f(-190.0,125.0,-152.0);
        glVertex3f(-178.0,125.0,-90.0);


        glVertex3f(-240.0,125.0,-230.0);
        glVertex3f(-290.0,125.0,-200.0);
        glVertex3f(-245.0,125.0,-100.0);
        glVertex3f(-190.0,125.0,-152.0);

        glVertex3f(-190.0,165.0,-152.0);
        glVertex3f(-190.0,125.0,-152.0);
        glVertex3f(-240.0,125.0,-230.0);
        glVertex3f(-240.0,165.0,-230.0);

        glVertex3f(-190.0,165.0,-152.0);
        glVertex3f(-132.1,165.0,-190.0);
        glVertex3f(-190.0,165.0,-260.0);
        glVertex3f(-240.0,165.0,-230.0);

    glEnd();
}
void jendelaDANpintu_depan(){
    glBegin(GL_QUADS);//depan
    //jendela
    glColor3ub(140, 140, 140);
    glVertex3f(-90.0,200.0,-10.0);
    glColor3ub(255, 255, 255);
    glVertex3f(-110.0,200.0,-10.0);
    glColor3ub(140, 140, 140);
    glVertex3f(-110.0,180.0,-10.0);
    glColor3ub(255, 255, 255);
    glVertex3f(-90.0,180.0,-10.0);

        glColor3ub(140, 140, 140);
        glVertex3f(-80.0,180.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(-40.0,180.0,-10.0);
        glColor3ub(140, 140, 140);
        glVertex3f(-40.0,200.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(-80.0,200.0,-10.0);

        glColor3ub(140, 140, 140);
        glVertex3f(-20.0,180.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(20.0,180.0,-10.0);
        glColor3ub(140, 140, 140);
        glVertex3f(20.0,200.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(-20.0,200.0,-10.0);

        glColor3ub(140, 140, 140);
        glVertex3f(40.0,180.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(80.0,180.0,-10.0);
        glColor3ub(140, 140, 140);
        glVertex3f(80.0,200.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(40.0,200.0,-10.0);

        glColor3ub(140, 140, 140);
        glVertex3f(90.0,180.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(110.0,180.0,-10.0);
        glColor3ub(140, 140, 140);
        glVertex3f(110.0,200.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(90.0,200.0,-10.0);

    glColor3ub(140, 140, 140);
    glVertex3f(-90.0,160.0,-10.0);
    glColor3ub(255, 255, 255);
    glVertex3f(-110.0,160.0,-10.0);
    glColor3ub(140, 140, 140);
    glVertex3f(-110.0,140.0,-10.0);
    glColor3ub(255, 255, 255);
    glVertex3f(-90.0,140.0,-10.0);

        glColor3ub(140, 140, 140);
        glVertex3f(-80.0,140.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(-40.0,140.0,-10.0);
        glColor3ub(140, 140, 140);
        glVertex3f(-40.0,160.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(-80.0,160.0,-10.0);

        glColor3ub(140, 140, 140);
        glVertex3f(-20.0,140.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(20.0,140.0,-10.0);
        glColor3ub(140, 140, 140);
        glVertex3f(20.0,160.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(-20.0,160.0,-10.0);

        glColor3ub(140, 140, 140);
        glVertex3f(40.0,140.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(80.0,140.0,-10.0);
        glColor3ub(140, 140, 140);
        glVertex3f(80.0,160.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(40.0,160.0,-10.0);

        glColor3ub(140, 140, 140);
        glVertex3f(90.0,140.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(110.0,140.0,-10.0);
        glColor3ub(140, 140, 140);
        glVertex3f(110.0,160.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(90.0,160.0,-10.0);

    glColor3ub(140, 140, 140);
    glVertex3f(-90.0,120.0,-10.0);
    glColor3ub(255, 255, 255);
    glVertex3f(-110.0,120.0,-10.0);
    glColor3ub(140, 140, 140);
    glVertex3f(-110.0,100.0,-10.0);
    glColor3ub(255, 255, 255);
    glVertex3f(-90.0,100.0,-10.0);

        glColor3ub(140, 140, 140);
        glVertex3f(-80.0,100.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(-40.0,100.0,-10.0);
        glColor3ub(140, 140, 140);
        glVertex3f(-40.0,120.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(-80.0,120.0,-10.0);

        glColor3ub(140, 140, 140);
        glVertex3f(-20.0,100.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(20.0,100.0,-10.0);
        glColor3ub(140, 140, 140);
        glVertex3f(20.0,120.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(-20.0,120.0,-10.0);

        glColor3ub(140, 140, 140);
        glVertex3f(40.0,100.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(80.0,100.0,-10.0);
        glColor3ub(140, 140, 140);
        glVertex3f(80.0,120.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(40.0,120.0,-10.0);

        glColor3ub(140, 140, 140);
        glVertex3f(90.0,100.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(110.0,100.0,-10.0);
        glColor3ub(140, 140, 140);
        glVertex3f(110.0,120.0,-10.0);
        glColor3ub(255, 255, 255);
        glVertex3f(90.0,120.0,-10.0);

    //tembok
    glColor3ub(255, 247, 230);
    glVertex3f(-120.0,200.0,-10.1);
    glVertex3f(120.0,200.0,-10.1);
    glVertex3f(120.0,280.0,-10.1);
    glVertex3f(-120.0,280.0,-10.1);

    glVertex3f(-120.0,180.0,-10.0);
    glVertex3f(120.0,180.0,-10.0);
    glVertex3f(120.0,160.0,-10.0);
    glVertex3f(-120.0,160.0,-10.0);

    glVertex3f(-120.0,140.0,-10.0);
    glVertex3f(120.0,140.0,-10.0);
    glVertex3f(120.0,120.0,-10.0);
    glVertex3f(-120.0,120.0,-10.0);

    glVertex3f(-120.0,100.0,-10.0);
    glVertex3f(120.0,100.0,-10.0);
    glVertex3f(120.0,50.0,-10.0);
    glVertex3f(-120.0,50.0,-10.0);

    glVertex3f(-40.0,280.0,-10.0);
    glVertex3f(-20.0,280.0,-10.0);
    glVertex3f(-20.0,50.0,-10.0);
    glVertex3f(-40.0,50.0,-10.0);

    glVertex3f(40.0,280.0,-10.0);
    glVertex3f(20.0,280.0,-10.0);
    glVertex3f(20.0,50.0,-10.0);
    glVertex3f(40.0,50.0,-10.0);

    //kiri
    glVertex3f(-80.0,280.0,-10.0);
    glVertex3f(-90.0,280.0,-10.0);
    glVertex3f(-90.0,50.0,-10.0);
    glVertex3f(-80.0,50.0,-10.0);

    glVertex3f(-110.0,280.0,-10.0);
    glVertex3f(-120.0,280.0,-10.0);
    glVertex3f(-120.0,50.0,-10.0);
    glVertex3f(-110.0,50.0,-10.0);

    glColor3ub(217, 217, 217);
    glVertex3f(-35.0,0.0,-10.0);
    glColor3ub(217, 217, 217);
    glVertex3f(-132.0,0.0,-10.0);
    glColor3ub(255, 247, 230);
    glVertex3f(-132.0,50.0,-10.0);
    glColor3ub(255, 247, 230);
    glVertex3f(-35.0,50.0,-10.0);

    //kanan
    glColor3ub(255, 247, 230);
    glVertex3f(80.0,280.0,-10.0);
    glVertex3f(90.0,280.0,-10.0);
    glVertex3f(90.0,80.0,-10.0);
    glVertex3f(80.0,80.0,-10.0);

    glColor3ub(255, 247, 230);
    glVertex3f(110.0,280.0,-10.0);
    glVertex3f(120.0,280.0,-10.0);
    glVertex3f(120.0,80.0,-10.0);
    glVertex3f(110.0,80.0,-10.0);

    glColor3ub(217, 217, 217);
    glVertex3f(35.0,0.0,-10.0);
    glColor3ub(217, 217, 217);
    glVertex3f(132.0,0.0,-10.0);
    glColor3ub(255, 247, 230);
    glVertex3f(132.0,50.0,-10.0);
    glColor3ub(255, 247, 230);
    glVertex3f(35.0,50.0,-10.0);
    glEnd();
}
void tiang(){
    //TIANG DEPAN
    glBegin(GL_POLYGON);//pilar (kiri) bawah
    glColor3ub(204, 102, 0);
    glVertex3f(-50.0, 0.1, 5.0);
    glVertex3f(-35.0, 0.1, 5.0);
    glVertex3f(-35.0, 0.1, -9.9);
    glVertex3f(-50, 0.1, -9.9);
    glEnd();

    glBegin(GL_POLYGON);//pilar (kiri) atas
    glColor3ub(204, 102, 0);
    glVertex3f(-50.0, 6.0, 5.0);
    glVertex3f(-35.0, 6.0, 5.0);
    glVertex3f(-35.0, 6.0, -9.9);
    glVertex3f(-50, 6.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);//pilar (kiri) kiri
    glColor3ub(204, 102, 0);
    glVertex3f(-50.0, 0.1, 5.0);
    glVertex3f(-50.0, 0.1, -9.9);
    glVertex3f(-50.0, 6.0, -9.9);
    glVertex3f(-50, 6.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);//pilar (kiri) kanan
    glColor3ub(204, 102, 0);
    glVertex3f(-35.0, 0.1, 5.0);
    glVertex3f(-35.0, 0.1, -9.9);
    glVertex3f(-35.0, 6.0, -9.9);
    glVertex3f(-35, 6.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);//pilar (kiri) depan
    glColor3ub(204, 102, 0);
    glVertex3f(-50.0, 0.1, 5.0);
    glVertex3f(-35.0, 0.1, 5.0);
    glVertex3f(-35.0, 6.0, 5.0);
    glVertex3f(-50, 6.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);//pilar (kiri) belakang
    glColor3ub(204, 102, 0);
    glVertex3f(-50.0, 0.1, -9.9);
    glVertex3f(-35.0, 0.1, -9.9);
    glVertex3f(-35.0, 6.0, -9.9);
    glVertex3f(-50, 6.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);//pilar (kanan) bawah
    glColor3ub(204, 102, 0);
    glVertex3f(50.0, 0.1, 5.0);
    glVertex3f(35.0, 0.1, 5.0);
    glVertex3f(35.0, 0.1, -9.9);
    glVertex3f(50, 0.1, -9.9);
    glEnd();

    glBegin(GL_POLYGON);//pilar (kanan) atas
    glColor3ub(204, 102, 0);
    glVertex3f(50.0, 6.0, 5.0);
    glVertex3f(35.0, 6.0, 5.0);
    glVertex3f(35.0, 6.0, -9.9);
    glVertex3f(50, 6.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);//pilar (kanan) kiri
    glColor3ub(204, 102, 0);
    glVertex3f(50.0, 0.1, 5.0);
    glVertex3f(50.0, 0.1, -9.9);
    glVertex3f(50.0, 6.0, -9.9);
    glVertex3f(50, 6.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);//pilar (kanan) kanan
    glColor3ub(204, 102, 0);
    glVertex3f(35.0, 0.1, 5.0);
    glVertex3f(35.0, 0.1, -9.9);
    glVertex3f(35.0, 6.0, -9.9);
    glVertex3f(35, 6.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);//pilar (kanan) depan
    glColor3ub(204, 102, 0);
    glVertex3f(50.0, 0.1, 5.0);
    glVertex3f(35.0, 0.1, 5.0);
    glVertex3f(35.0, 6.0, 5.0);
    glVertex3f(50, 6.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);//pilar (kanan) belakang
    glColor3ub(204, 102, 0);
    glVertex3f(50.0, 0.1, -9.9);
    glVertex3f(35.0, 0.1, -9.9);
    glVertex3f(35.0, 6.0, -9.9);
    glVertex3f(50, 6.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);//pilar (KIRI_KECIL) depan
    glColor3ub(204, 102, 0);
    glVertex3f(-130.0, 0.1, 5.0);
    glVertex3f(-50.0, 0.1, 5.0);
    glVertex3f(-50.0, 3.0, 5.0);
    glVertex3f(-130, 3.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);//pilar (KIRI_KECIL) belakang
    glColor3ub(204, 102, 0);
    glVertex3f(-110.0, 0.1, -9.9);
    glVertex3f(-50.0, 0.1, -9.9);
    glVertex3f(-50.0, 3.0, -9.9);
    glVertex3f(-110, 3.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);//pilar (KIRI_KECIL) atas
    glColor3ub(204, 102, 0);
    glVertex3f(-130.0, 3.0, 5.0);
    glVertex3f(-50.0, 3.0, 5.0);
    glVertex3f(-50.0, 3.0, -9.9);
    glVertex3f(-119, 3.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);//pilar (KIRI_KECIL) bawah
    glColor3ub(204, 102, 0);
    glVertex3f(-119.0, 0.1, 5.0);
    glVertex3f(-50.0, 0.1, 5.0);
    glVertex3f(-50.0, 0.1, -9.9);
    glVertex3f(-119, 0.1, -9.9);
    glEnd();

    glBegin(GL_POLYGON);//pilar (KIRI_KECIL) kiri
    glColor3ub(204, 102, 0);
    glVertex3f(-129.0, 0.1, 5.0);
    glVertex3f(-119.0, 0.1, -9.9);
    glVertex3f(-119.0, 3.0, -9.9);
    glVertex3f(-129.0, 3.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);//pilar (KIRI_KECIL) kanan
    glColor3ub(204, 102, 0);
    glVertex3f(-50.1, 0.1, 5.0);
    glVertex3f(-50.1, 0.1, -9.9);
    glVertex3f(-50.1, 3.0, -9.9);
    glVertex3f(-50.1, 3.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);//pilar (KANAN_KECIL) depan
    glColor3ub(204, 102, 0);
    glVertex3f(129.0, 0.1, 5.0);
    glVertex3f(50.0, 0.1, 5.0);
    glVertex3f(50.0, 3.0, 5.0);
    glVertex3f(129, 3.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);//pilar (KANAN_KECIL) belakang
    glColor3ub(204, 102, 0);
    glVertex3f(110.0, 0.1, -9.9);
    glVertex3f(50.0, 0.1, -9.9);
    glVertex3f(50.0, 3.0, -9.9);
    glVertex3f(110, 3.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);//pilar (KANAN_KECIL) atas
    glColor3ub(204, 102, 0);
    glVertex3f(130.0, 3.0, 5.0);
    glVertex3f(50.0, 3.0, 5.0);
    glVertex3f(50.0, 3.0, -9.9);
    glVertex3f(119, 3.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);//pilar (KANAN_KECIL) bawah
    glColor3ub(204, 102, 0);
    glVertex3f(119.0, 0.1, 5.0);
    glVertex3f(50.0, 0.1, 5.0);
    glVertex3f(50.0, 0.1, -9.9);
    glVertex3f(119, 0.1, -9.9);
    glEnd();

    glBegin(GL_POLYGON);//pilar (KANAN_KECIL) kanan
    glColor3ub(204, 102, 0);
    glVertex3f(129.0, 0.1, 5.0);
    glVertex3f(119.0, 0.1, -9.9);
    glVertex3f(119.0, 3.0, -9.9);
    glVertex3f(129, 3.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);//pilar (KANAN_KECIL) kiri
    glColor3ub(204, 102, 0);
    glVertex3f(50.1, 0.1, 5.0);
    glVertex3f(50.1, 0.1, -9.9);
    glVertex3f(50.1, 3.0, -9.9);
    glVertex3f(50.1, 3.0, 5.0);
    glEnd();

    //TIANG
    glBegin(GL_QUADS);//depan (KIRI)
    glColor3ub(179, 119, 0);
    glVertex3f(-47.0, 6.1, 2.0);
    glVertex3f(-38.0, 6.1, 2.0);
    glVertex3f(-38.0, 50.0, 2.0);
    glVertex3f(-47.0, 50.0, 2.0);
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(179, 119, 0);
    glVertex3f(-47.0, 6.1, -7.0);
    glVertex3f(-38.0, 6.1, -7.0);
    glVertex3f(-38.0, 50.0, -7.0);
    glVertex3f(-47.0, 50.0, -7.0);
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(179, 119, 0);
    glVertex3f(-47.0, 6.1, 2.0);
    glVertex3f(-47.0, 6.1, -7.0);
    glVertex3f(-47.0, 50.0, -7.0);
    glVertex3f(-47.0, 50.0, 2.0);
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(179, 119, 0);
    glVertex3f(-38.0, 6.1, 2.0);
    glVertex3f(-38.0, 6.1, -7.0);
    glVertex3f(-38.0, 50.0, -7.0);
    glVertex3f(-38.0, 50.0, 2.0);

    glBegin(GL_QUADS);//depan (KANAN)
    glColor3ub(179, 119, 0);
    glVertex3f(47.0, 6.1, 2.0);
    glVertex3f(38.0, 6.1, 2.0);
    glVertex3f(38.0, 50.0, 2.0);
    glVertex3f(47.0, 50.0, 2.0);
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(179, 119, 0);
    glVertex3f(47.0, 6.1, -7.0);
    glVertex3f(38.0, 6.1, -7.0);
    glVertex3f(38.0, 50.0, -7.0);
    glVertex3f(47.0, 50.0, -7.0);
    //kiri
    glBegin(GL_QUADS);
    glColor3ub(179, 119, 0);
    glVertex3f(47.0, 6.1, 2.0);
    glVertex3f(47.0, 6.1, -7.0);
    glVertex3f(47.0, 50.0, -7.0);
    glVertex3f(47.0, 50.0, 2.0);
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(179, 119, 0);
    glVertex3f(38.0, 6.1, 2.0);
    glVertex3f(38.0, 6.1, -7.0);
    glVertex3f(38.0, 50.0, -7.0);
    glVertex3f(38.0, 50.0, 2.0);

    int y = 26;
    float a = 0.1;
    for (int i = 0; i<3; i++){
        glBegin(GL_QUADS);
        glColor3ub(179, 119, 0);
        if (i==0){
            //depan
            glVertex3f(-115.0, 3.1, -1.0);
            glVertex3f(-110.0, 3.1, -1.0);
            glVertex3f(-110.0, 50.0, -1.0);
            glVertex3f(-115.0, 50.0, -1.0);
            //belakang
            glVertex3f(-115.0, 3.1, -4.0);
            glVertex3f(-110.0, 3.1, -4.0);
            glVertex3f(-110.0, 50.0, -4.0);
            glVertex3f(-115.0, 50.0, -4.0);
            //kiri
            glVertex3f(-115.0, 3.1, -1.0);
            glVertex3f(-115.0, 3.1, -4.0);
            glVertex3f(-115.0, 50.0, -4.0);
            glVertex3f(-115.0, 50.0, -1.0);
            //kanan
            glVertex3f(-110.0, 3.1, -1.0);
            glVertex3f(-110.0, 3.1, -4.0);
            glVertex3f(-110.0, 50.0, -4.0);
            glVertex3f(-110.0, 50.0, -1.0);

        }else{
            //depan
            glVertex3f(-115.0+y-a, 3.1, -1.0);
            glVertex3f(-110.0+y-a, 3.1, -1.0);
            glVertex3f(-110.0+y-a, 50.0, -1.0);
            glVertex3f(-115.0+y-a, 50.0, -1.0);
            //belakang
            glVertex3f(-115.0+y-a, 3.1, -4.0);
            glVertex3f(-110.0+y-a, 3.1, -4.0);
            glVertex3f(-110.0+y-a, 50.0, -4.0);
            glVertex3f(-115.0+y-a, 50.0, -4.0);
            //kiri
            glVertex3f(-115.0+y-a, 3.1, -1.0);
            glVertex3f(-115.0+y-a, 3.1, -4.0);
            glVertex3f(-115.0+y-a, 50.0, -4.0);
            glVertex3f(-115.0+y-a, 50.0, -1.0);
            //kanan
            glVertex3f(-110.0+y-a, 3.1, -1.0);
            glVertex3f(-110.0+y-a, 3.1, -4.0);
            glVertex3f(-110.0+y-a, 50.0, -4.0);
            glVertex3f(-110.0+y-a, 50.0, -1.0);
            y+=26;
            a-=0.1;
        }
        glEnd();
    }
    for (int i = 0; i<3; i++){
        glBegin(GL_QUADS);
        glColor3ub(179, 119, 0);
        if (i==0){
            //depan
            glVertex3f(115.0, 3.1, -1.0);
            glVertex3f(110.0, 3.1, -1.0);
            glVertex3f(110.0, 50.0, -1.0);
            glVertex3f(115.0, 50.0, -1.0);
            //belakang
            glVertex3f(115.0, 3.1, -4.0);
            glVertex3f(110.0, 3.1, -4.0);
            glVertex3f(110.0, 50.0, -4.0);
            glVertex3f(115.0, 50.0, -4.0);
            //kiri
            glVertex3f(115.0, 3.1, -1.0);
            glVertex3f(115.0, 3.1, -4.0);
            glVertex3f(115.0, 50.0, -4.0);
            glVertex3f(115.0, 50.0, -1.0);
            //kanan
            glVertex3f(110.0, 3.1, -1.0);
            glVertex3f(110.0, 3.1, -4.0);
            glVertex3f(110.0, 50.0, -4.0);
            glVertex3f(110.0, 50.0, -1.0);

        }else{
            //depan
            glVertex3f(115.0-y+53+a, 3.1, -1.0);
            glVertex3f(110.0-y+53+a, 3.1, -1.0);
            glVertex3f(110.0-y+53+a, 50.0, -1.0);
            glVertex3f(115.0-y+53+a, 50.0, -1.0);
            //belakang
            glVertex3f(115.0-y+53+a, 3.1, -4.0);
            glVertex3f(110.0-y+53+a, 3.1, -4.0);
            glVertex3f(110.0-y+53+a, 50.0, -4.0);
            glVertex3f(115.0-y+53+a, 50.0, -4.0);
            //kiri
            glVertex3f(115.0-y+53+a, 3.1, -1.0);
            glVertex3f(115.0-y+53+a, 3.1, -4.0);
            glVertex3f(115.0-y+53+a, 50.0, -4.0);
            glVertex3f(115.0-y+53+a, 50.0, -1.0);
            //kanan
            glVertex3f(110.0-y+53+a, 3.1, -1.0);
            glVertex3f(110.0-y+53+a, 3.1, -4.0);
            glVertex3f(110.0-y+53+a, 50.0, -4.0);
            glVertex3f(110.0-y+53+a, 50.0, -1.0);
            y+=26;
            a-=0.1;
        }
        glEnd();
    }
}
void lambangSegitiga(){
    //Belakang Kiri
    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 26);
    glVertex3f(-50.0, 47.0, 5.0);
    glVertex3f(-35.0, 47.0, 5.0);
    glVertex3f(0.0, 120.0, 5.0);
    glVertex3f(0.0, 150.0, 5.0);
    glEnd();

    //Penutup Bawah Kiri
    glBegin(GL_POLYGON);
    glColor3ub(230, 230, 230);
    glVertex3f(-50.0, 47.0, 5.0+x1);
    glVertex3f(-35.0, 47.0, 5.0+x1);
    glVertex3f(-35.0, 47.0, 5.0);
    glVertex3f(-50, 47.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 26);
    glVertex3f(-50.0, 47.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0);
    glVertex3f(-50.0, 47.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(230, 230, 230);
    glVertex3f(-35.0, 47.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0);
    glVertex3f(-35.0, 47.0, 5.0);
    glEnd();

    //Depan Kiri
    glBegin(GL_POLYGON);//depan
    glColor3ub(255, 209, 26);
    glVertex3f(-50.0, 47.0, 5.0+x1);
    glVertex3f(-35.0, 47.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0+x1);
    glEnd();

    //Belakang Kanan
    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 26);
    glVertex3f(50.0, 47.0, 5.0);
    glVertex3f(35.0, 47.0, 5.0);
    glVertex3f(0.0, 120.0, 5.0);
    glVertex3f(0.0, 150.0, 5.0);
    glEnd();

    //Penutup Bawah Kanan
    glBegin(GL_POLYGON);
    glColor3ub(230, 230, 230);
    glVertex3f(50.0, 47.0, 5.0+x1);
    glVertex3f(35.0, 47.0, 5.0+x1);
    glVertex3f(35.0, 47.0, 5.0);
    glVertex3f(50, 47.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 209, 26);
    glVertex3f(50.0, 47.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0);
    glVertex3f(50.0, 47.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(230, 230, 230);
    glVertex3f(35.0, 47.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0);
    glVertex3f(35.0, 47.0, 5.0);
    glEnd();

    //Depan Kanan
    glBegin(GL_POLYGON);//depan
    glColor3ub(255, 209, 26);
    glVertex3f(50.0, 47.0, 5.0+x1);
    glVertex3f(35.0, 47.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0+x1);
    glEnd();
}
void papan_nama(){
    glBegin(GL_QUADS);//belakang
    glColor3ub(255, 255, 255);
    glVertex3f(-20.0, 50.0, 5.1);
    glVertex3f(20.0, 50.0, 5.1);
    glVertex3f(20.0, 76.0, 5.1);
    glVertex3f(-20.0, 76.0, 5.1);
    glEnd();

    glBegin(GL_QUADS);//depan
    glColor3ub(255, 255, 255);
    glVertex3f(-20.0, 50.0, 15.0);
    glVertex3f(20.0, 50.0, 15.0);
    glVertex3f(20.0, 76.0, 15.0);
    glVertex3f(-20.0, 76.0, 15.0);
    glEnd();

    glBegin(GL_QUADS);//bawah
    glColor3ub(255, 255, 255);
    glVertex3f(-20.0, 50.0, 5.1);
    glVertex3f(20.0, 50.0, 5.1);
    glVertex3f(20.0, 50.0, 15.0);
    glVertex3f(-20.0, 50.0, 15.0);
    glEnd();

    glBegin(GL_QUADS);//atas
    glColor3ub(255, 255, 255);
    glVertex3f(-20.0, 76.0, 5.1);
    glVertex3f(20.0, 76.0, 5.1);
    glVertex3f(20.0, 76.0, 15.0);
    glVertex3f(-20.0, 76.0, 15.0);
    glEnd();

    glBegin(GL_QUADS);//kiri
    glColor3ub(255, 255, 255);
    glVertex3f(-20.0, 50.0, 5.1);
    glVertex3f(-20.0, 50.0, 15.0);
    glVertex3f(-20.0, 76.0, 15.0);
    glVertex3f(-20.0, 76.0, 5.1);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3ub(255, 255, 255);
    glVertex3f(20.0, 50.0, 5.1);
    glVertex3f(20.0, 50.0, 15.0);
    glVertex3f(20.0, 76.0, 15.0);
    glVertex3f(20.0, 76.0, 5.1);
    glEnd();

}
void uksw(){
    glBegin(GL_LINES);//huruf U
    glColor3ub(179, 143, 0);
    glVertex3f(-17.0, 69.0, 15.1);
    glVertex3f(-17.0, 57.0, 15.1);
    glVertex3f(-17.0, 57.0, 15.1);
    glVertex3f(-11.0, 57.0, 15.1);
    glVertex3f(-11.0, 57.0, 15.1);
    glVertex3f(-11.0, 69.0, 15.1);
    glEnd();

    glBegin(GL_LINES);//huruf K
    glColor3ub(179, 143, 0);
    glVertex3f(-7.0, 69.0, 15.1);
    glVertex3f(-7.0, 57.0, 15.1);
    glVertex3f(-7.0, 63.0, 15.1);
    glVertex3f(-1.0, 69.0, 15.1);
    glVertex3f(-7.0, 63.0, 15.1);
    glVertex3f(-1.0, 57.0, 15.1);
    glEnd();

    glBegin(GL_LINES);//huruf S
    glColor3ub(179, 143, 0);
    glVertex3f(1.0, 69.0, 15.1);
    glVertex3f(7.0, 69.0, 15.1);
    glVertex3f(1.0, 69.0, 15.1);
    glVertex3f(1.0, 63.0, 15.1);
    glVertex3f(1.0, 63.0, 15.1);
    glVertex3f(7.0, 63.0, 15.1);
    glVertex3f(7.0, 63.0, 15.1);
    glVertex3f(7.0, 57.0, 15.1);
    glVertex3f(7.0, 57.0, 15.1);
    glVertex3f(1.0, 57.0, 15.1);
    glEnd();

    glBegin(GL_LINES);//huruf W
    glColor3ub(179, 143, 0);
    glVertex3f(11.0, 69.0, 15.1);
    glVertex3f(11.0, 57.0, 15.1);
    glVertex3f(11.0, 57.0, 15.1);
    glVertex3f(14.0, 63.0, 15.1);
    glVertex3f(14.0, 63.0, 15.1);
    glVertex3f(17.0, 57.0, 15.1);
    glVertex3f(17.0, 57.0, 15.1);
    glVertex3f(17.0, 69.0, 15.1);
    glEnd();
}
void poni(){
    //poni bangunan kiri
    glBegin(GL_POLYGON);//belakang
    glColor3ub(255, 255, 255);
    glVertex3f(-132.0,50.0,10.0);
    glVertex3f(-120.0,50.0,-10.0);
    glVertex3f(-120.0,70.0,-10.0);
    glVertex3f(-132.0,70.0,10.0);
    glEnd();

    glBegin(GL_POLYGON);//depan
    glColor3ub(230, 230, 230);
    glVertex3f(-117.0,50.0,25.0);
    glVertex3f(-105.0,50.0,5.0);
    glVertex3f(-105.0,70.0,5.0);
    glVertex3f(-117.0,70.0,25.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(204, 102, 0);
    glVertex3f(-117.0,70.0,25.0);
    glVertex3f(-105.0,70.0,5.0);
    glVertex3f(-120.0,70.0,-9.9);
    glVertex3f(-132.0,70.0,10.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(204, 102, 0);
    glVertex3f(-117.0,50.0,25.0);
    glVertex3f(-105.0,50.0,5.0);
    glVertex3f(-120.0,50.0,-9.9);
    glVertex3f(-132.0,50.0,10.0);
    glEnd();

    glBegin(GL_POLYGON);//kanan
    glColor3ub(230, 230, 230);
    glVertex3f(-132.0,50.0,10.0);
    glVertex3f(-117.0,50.0,25.0);
    glVertex3f(-117.0,70.0,25.0);
    glVertex3f(-132.0,70.0,10.0);
    glEnd();

    //poni bangunan tengah
    glBegin(GL_POLYGON);//belakang
    glColor3ub(230, 230, 230);
    glVertex3f(-120.0,50.0,-9.9);
    glVertex3f(120.0,50.0,-9.9);
    glVertex3f(120.0,70.0,-9.9);
    glVertex3f(-120.0,70.0,-9.9);
    glEnd();

    glBegin(GL_POLYGON);//depan
    glColor3ub(242, 242, 242);
    glVertex3f(-105.0,50.0,5.0);
    glVertex3f(105.0,50.0,5.0);
    glVertex3f(105.0,70.0,5.0);
    glVertex3f(-105.0,70.0,5.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(204, 102, 0);
    glVertex3f(-105.0,70.0,5.0);
    glVertex3f(105.0,70.0,5.0);
    glVertex3f(120.0,70.0,-9.9);
    glVertex3f(-120.0,70.0,-9.9);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(204, 102, 0);
    glVertex3f(-105.0,50.0,5.0);
    glVertex3f(105.0,50.0,5.0);
    glVertex3f(120.0,50.0,-9.9);
    glVertex3f(-120.0,50.0,-9.9);
    glEnd();

    //poni bangunan kanan
    glBegin(GL_POLYGON);//belakang
    glColor3ub(230, 230, 230);
    glVertex3f(132.0,50.0,10.0);
    glVertex3f(120.0,50.0,-10.0);
    glVertex3f(120.0,70.0,-10.0);
    glVertex3f(132.0,70.0,10.0);
    glEnd();

    glBegin(GL_POLYGON);//depan
    glColor3ub(230, 230, 230);
    glVertex3f(117.0,50.0,25.0);
    glVertex3f(105.0,50.0,5.0);
    glVertex3f(105.0,70.0,5.0);
    glVertex3f(117.0,70.0,25.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(204, 102, 0);
    glVertex3f(117.0,70.0,25.0);
    glVertex3f(105.0,70.0,5.0);
    glVertex3f(120.0,70.0,-9.9);
    glVertex3f(132.0,70.0,10.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(204, 102, 0);
    glVertex3f(117.0,50.0,25.0);
    glVertex3f(105.0,50.0,5.0);
    glVertex3f(120.0,50.0,-9.9);
    glVertex3f(132.0,50.0,10.0);
    glEnd();

    glBegin(GL_POLYGON);//kanan
    glColor3ub(230, 230, 230);
    glVertex3f(132.0,50.0,10.0);
    glVertex3f(117.0,50.0,25.0);
    glVertex3f(117.0,70.0,25.0);
    glVertex3f(132.0,70.0,10.0);
    glEnd();
}
void aspal(){
    //aspal depan
    glBegin(GL_QUADS);
    glColor3ub(191, 191, 191);
    glVertex3f(-70.0,0.0,450.0);
    glVertex3f(70.0,0.0,450.0);
    glVertex3f(70.0,0.0,400.0);
    glVertex3f(-70.0,0.0,400.0);
    glEnd();

    //aspal belakang
    glBegin(GL_POLYGON);
    glColor3ub(155, 180, 191);
    glVertex3f(70.0,0.0,400.0);
    glVertex3f(620.0,0.0,0.0);
    glVertex3f(350.0,0.0,-450.0);
    glVertex3f(-350.0,0.0,-450.0);
    glVertex3f(-620.0,0.0,0.0);
    glVertex3f(-70.0,0.0,400.0);
    glEnd();
}
void rumput(){
    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 0);
    glVertex3f(70.0,0.1,350.0);
    glColor3ub(102, 102, 0);
    glVertex3f(200.0,0.1,250.0);
    glColor3ub(0, 102, 0);
    glVertex3f(100.0,0.1,100.0);
    glColor3ub(153, 153, 0);
    glVertex3f(-100.0,0.1,100.0);
    glColor3ub(102, 102, 0);
    glVertex3f(-200.0,0.1,250.0);
    glColor3ub(31, 122, 31);
    glVertex3f(-70.0,0.1,350.0);
    glEnd();
}
void monumen1(){
    glBegin(GL_QUADS);
    //base
    glColor3ub(140,140,140);
    glVertex3f(95.0,0.1,235.0);
    glVertex3f(65.0,0.1,235.0);
    glVertex3f(65.0,0.1,265.0);
    glVertex3f(95.0,0.1,265.0);

    glColor3ub(140,140,140);
    glVertex3f(100.0,10.0,280.0);
    glVertex3f(60.0,10.0,280.0);
    glColor3ub(255,255,255);
    glVertex3f(65.0,0.1,265.0);
    glVertex3f(95.0,0.1,265.0);

    glColor3ub(255,255,255);
    glVertex3f(95.0,0.1,265.0);
    glVertex3f(95.0,0.1,235.0);
    glColor3ub(140,140,140);
    glVertex3f(100.0,10.0,220.0);
    glVertex3f(100.0,10.0,280.0);

    glColor3ub(140,140,140);
    glVertex3f(95.0,0.1,235.0);
    glVertex3f(65.0,0.1,235.0);
    glColor3ub(255,255,255);
    glVertex3f(60.0,10.0,220.0);
    glVertex3f(100.0,10.0,220.0);

    glColor3ub(255,255,255);
    glVertex3f(65.0,0.1,265.0);
    glVertex3f(65.0,0.1,235.0);
    glColor3ub(140,140,140);
    glVertex3f(60.0,10.0,220.0);
    glVertex3f(60.0,10.0,280.0);

    glColor3ub(255,255,255);
    glVertex3f(100.0,10.0,220.0);
    glColor3ub(140,140,140);
    glVertex3f(60.0,10.0,220.0);
    glColor3ub(255,255,255);
    glVertex3f(60.0,10.0,280.0);
    glColor3ub(140,140,140);
    glVertex3f(100.0,10.0,280.0);


    //tiang
    glColor3ub(255,255,255);
    glVertex3f(75.0,10.0,260.0);
    glColor3ub(140,140,140);
    glVertex3f(85.0,10.0,260.0);
    glColor3ub(255,255,255);
    glVertex3f(85.0,75.0,260.0);
    glColor3ub(140,140,140);
    glVertex3f(75.0,75.0,260.0);

    glColor3ub(140,140,140);
    glVertex3f(85.0,10.0,260.0);
    glColor3ub(255,255,255);
    glVertex3f(85.0,75.0,260.0);
    glColor3ub(140,140,140);
    glVertex3f(85.0,75.0,240.0);
    glColor3ub(255,255,255);
    glVertex3f(85.0,10.0,240.0);

    glColor3ub(255,255,255);
    glVertex3f(75.0,10.0,240.0);
    glColor3ub(140,140,140);
    glVertex3f(85.0,10.0,240.0);
    glColor3ub(255,255,255);
    glVertex3f(85.0,75.0,240.0);
    glColor3ub(140,140,140);
    glVertex3f(75.0,75.0,240.0);

    glColor3ub(140,140,140);
    glVertex3f(75.0,10.0,260.0);
    glColor3ub(255,255,255);
    glVertex3f(75.0,75.0,260.0);
    glColor3ub(140,140,140);
    glVertex3f(75.0,75.0,240.0);
    glColor3ub(255,255,255);
    glVertex3f(75.0,10.0,240.0);

    glColor3ub(140,140,140);
    glVertex3f(75.0,75.0,260.0);
    glColor3ub(255,255,255);
    glVertex3f(75.0,75.0,240.0);
    glColor3ub(140,140,140);
    glVertex3f(85.0,75.0,240.0);
    glColor3ub(255,255,255);
    glVertex3f(85.0,75.0,260.0);

    glEnd();
}
void monumen2(){
    glBegin(GL_QUADS);
    //base
    glColor3ub(140,140,140);
    glVertex3f(-95.0,0.1,235.0);
    glVertex3f(-65.0,0.1,235.0);
    glVertex3f(-65.0,0.1,265.0);
    glVertex3f(-95.0,0.1,265.0);

    glColor3ub(140,140,140);
    glVertex3f(-100.0,10.0,280.0);
    glVertex3f(-60.0,10.0,280.0);
    glColor3ub(255,255,255);
    glVertex3f(-65.0,0.1,265.0);
    glVertex3f(-95.0,0.1,265.0);

    glColor3ub(255,255,255);
    glVertex3f(-95.0,0.1,265.0);
    glVertex3f(-95.0,0.1,235.0);
    glColor3ub(140,140,140);
    glVertex3f(-100.0,10.0,220.0);
    glVertex3f(-100.0,10.0,280.0);

    glColor3ub(140,140,140);
    glVertex3f(-95.0,0.1,235.0);
    glVertex3f(-65.0,0.1,235.0);
    glColor3ub(255,255,255);
    glVertex3f(-60.0,10.0,220.0);
    glVertex3f(-100.0,10.0,220.0);

    glColor3ub(255,255,255);
    glVertex3f(-65.0,0.1,265.0);
    glVertex3f(-65.0,0.1,235.0);
    glColor3ub(140,140,140);
    glVertex3f(-60.0,10.0,220.0);
    glVertex3f(-60.0,10.0,280.0);

    glColor3ub(255,255,255);
    glVertex3f(-100.0,10.0,220.0);
    glColor3ub(140,140,140);
    glVertex3f(-60.0,10.0,220.0);
    glColor3ub(255,255,255);
    glVertex3f(-60.0,10.0,280.0);
    glColor3ub(140,140,140);
    glVertex3f(-100.0,10.0,280.0);

    //kaki kotak 1
    glColor3ub(140,140,140);
    glVertex3f(-90.0,10.0,265.0);
    glColor3ub(255,255,255);
    glVertex3f(-85.0,10.0,265.0);
    glColor3ub(140,140,140);
    glVertex3f(-85.0,15.0,265.0);
    glVertex3f(-90.0,15.0,265.0);

    glColor3ub(140,140,140);
    glVertex3f(-85.0,10.0,260.0);
    glColor3ub(255,255,255);
    glVertex3f(-85.0,10.0,265.0);
    glColor3ub(140,140,140);
    glVertex3f(-85.0,15.0,265.0);
    glVertex3f(-85.0,15.0,260.0);

    glColor3ub(140,140,140);
    glVertex3f(-90.0,10.0,260.0);
    glVertex3f(-85.0,10.0,260.0);
    glVertex3f(-85.0,15.0,260.0);
    glVertex3f(-90.0,15.0,260.0);

    glColor3ub(140,140,140);
    glVertex3f(-90.0,10.0,265.0);
    glVertex3f(-90.0,10.0,260.0);
    glVertex3f(-90.0,15.0,260.0);
    glVertex3f(-90.0,15.0,265.0);

    //kaki kotak 2
    glColor3ub(140,140,140);
    glVertex3f(-70.0,10.0,265.0);
    glColor3ub(255,255,255);
    glVertex3f(-75.0,10.0,265.0);
    glColor3ub(140,140,140);
    glVertex3f(-75.0,15.0,265.0);
    glVertex3f(-70.0,15.0,265.0);

    glColor3ub(140,140,140);
    glVertex3f(-75.0,10.0,260.0);
    glColor3ub(255,255,255);
    glVertex3f(-75.0,10.0,265.0);
    glColor3ub(140,140,140);
    glVertex3f(-75.0,15.0,265.0);
    glVertex3f(-75.0,15.0,260.0);

    glVertex3f(-70.0,10.0,260.0);
    glVertex3f(-75.0,10.0,260.0);
    glVertex3f(-75.0,15.0,260.0);
    glVertex3f(-70.0,15.0,260.0);

    glVertex3f(-70.0,10.0,265.0);
    glVertex3f(-70.0,10.0,260.0);
    glVertex3f(-70.0,15.0,260.0);
    glVertex3f(-70.0,15.0,265.0);

    //kaki kotak 3
    glColor3ub(255,255,255);
    glVertex3f(-70.0,10.0,235.0);
    glVertex3f(-75.0,10.0,235.0);
    glVertex3f(-75.0,15.0,235.0);
    glVertex3f(-70.0,15.0,235.0);

    glVertex3f(-75.0,10.0,240.0);
    glVertex3f(-75.0,10.0,235.0);
    glVertex3f(-75.0,15.0,235.0);
    glVertex3f(-75.0,15.0,240.0);

    glVertex3f(-70.0,10.0,240.0);
    glVertex3f(-75.0,10.0,240.0);
    glVertex3f(-75.0,15.0,240.0);
    glVertex3f(-70.0,15.0,240.0);

    glVertex3f(-70.0,10.0,235.0);
    glVertex3f(-70.0,10.0,240.0);
    glVertex3f(-70.0,15.0,240.0);
    glVertex3f(-70.0,15.0,235.0);

    //kaki kotak 4
    glColor3ub(255,255,255);
    glVertex3f(-90.0,10.0,235.0);
    glVertex3f(-85.0,10.0,235.0);
    glVertex3f(-85.0,15.0,235.0);
    glVertex3f(-90.0,15.0,235.0);

    glVertex3f(-85.0,10.0,240.0);
    glVertex3f(-85.0,10.0,235.0);
    glVertex3f(-85.0,15.0,235.0);
    glVertex3f(-85.0,15.0,240.0);

    glVertex3f(-90.0,10.0,240.0);
    glVertex3f(-85.0,10.0,240.0);
    glVertex3f(-85.0,15.0,240.0);
    glVertex3f(-90.0,15.0,240.0);

    glVertex3f(-90.0,10.0,235.0);
    glVertex3f(-90.0,10.0,240.0);
    glVertex3f(-90.0,15.0,240.0);
    glVertex3f(-90.0,15.0,235.0);

    //kotakbesar
    glColor3ub(140,140,140);
    glVertex3f(-90.0,15.0,235.0);
    glColor3ub(255,255,255);
    glVertex3f(-70.0,15.0,235.0);
    glColor3ub(140,140,140);
    glVertex3f(-70.0,15.0,265.0);
    glColor3ub(255,255,255);
    glVertex3f(-90.0,15.0,265.0);

    glColor3ub(255,255,255);
    glVertex3f(-70.0,15.0,265.0);
    glColor3ub(140,140,140);
    glVertex3f(-90.0,15.0,265.0);
    glColor3ub(255,255,255);
    glVertex3f(-90.0,35.0,265.0);
    glColor3ub(140,140,140);
    glVertex3f(-70.0,35.0,265.0);

    glColor3ub(140,140,140);
    glVertex3f(-90.0,15.0,265.0);
    glColor3ub(255,255,255);
    glVertex3f(-90.0,35.0,265.0);
    glColor3ub(140,140,140);
    glVertex3f(-90.0,35.0,235.0);
    glColor3ub(255,255,255);
    glVertex3f(-90.0,15.0,235.0);

    glColor3ub(255,255,255);
    glVertex3f(-70.0,15.0,265.0);
    glColor3ub(140,140,140);
    glVertex3f(-70.0,35.0,265.0);
    glColor3ub(255,255,255);
    glVertex3f(-70.0,35.0,235.0);
    glColor3ub(140,140,140);
    glVertex3f(-70.0,15.0,235.0);

    glColor3ub(140,140,140);
    glVertex3f(-70.0,15.0,235.0);
    glColor3ub(255,255,255);
    glVertex3f(-90.0,15.0,235.0);
    glColor3ub(140,140,140);
    glVertex3f(-90.0,35.0,235.0);
    glColor3ub(255,255,255);
    glVertex3f(-70.0,35.0,235.0);

    glColor3ub(255,255,255);
    glVertex3f(-90.0,35.0,235.0);
    glColor3ub(140,140,140);
    glVertex3f(-70.0,35.0,235.0);
    glColor3ub(255,255,255);
    glVertex3f(-70.0,35.0,265.0);
    glColor3ub(140,140,140);
    glVertex3f(-90.0,35.0,265.0);
    glEnd();
}
void gerbang(){
    //Sebelah kiri
    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-70.0, 0.0, 400.0);
    glVertex3f(-45.0, 0.0, 400.0);
    glVertex3f(-45.0, 36.5, 400.0);
    glVertex3f(-70.0, 15.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-70.0, 0.0, 420.0);
    glVertex3f(-45.0, 0.0, 420.0);
    glVertex3f(-45.0, 36.5, 420.0);
    glVertex3f(-70.0, 15.0, 420.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-70.0, 0.0, 420.0);
    glVertex3f(-70.0, 30.0, 420.0);
    glVertex3f(-70.0, 30.0, 400.0);
    glVertex3f(-70.0, 0.0, 400.0);
    glEnd();
    //Sebelah kiri
    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-45.0, 0.0, 420.0);
    glVertex3f(-45.0, 36.5, 420.0);
    glVertex3f(-45.0, 36.5, 400.0);
    glVertex3f(-45.0, 0.0, 400.0);
    glEnd();

    //Gerbang Segitiga kiri
    glBegin(GL_POLYGON);//belakang
    glColor3ub(204, 102, 0);
    glVertex3f(-70.0, 15.0, 400.0);
    glVertex3f(0.0, 75.0, 400.0);
    glVertex3f(0.0, 90.0, 400.0);
    glVertex3f(-70.0, 30.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);//depan
    glColor3ub(204, 102, 0);
    glVertex3f(-70.0, 15.0, 420.0);
    glVertex3f(0.0, 75.0, 420.0);
    glVertex3f(0.0, 90.0, 420.0);
    glVertex3f(-70.0, 30.0, 420.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(204, 102, 0);
    glVertex3f(-70.0, 30.0, 420.0);
    glVertex3f(0.0, 90.0, 420.0);
    glVertex3f(0.0, 90.0, 400.0);
    glVertex3f(-70.0, 30.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(204, 102, 0);
    glVertex3f(-45.0, 36.5, 420.0);
    glVertex3f(0.0, 75.0, 420.0);
    glVertex3f(0.0, 75.0, 400.0);
    glVertex3f(-45.0, 36.5, 400.0);
    glEnd();

    //Gerbang Segitiga Kanan
    glBegin(GL_POLYGON);//belakang
    glColor3ub(204, 102, 0);
    glVertex3f(70.0, 15.0, 400.0);
    glVertex3f(0.0, 75.0, 400.0);
    glVertex3f(0.0, 90.0, 400.0);
    glVertex3f(70.0, 30.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);//depan
    glColor3ub(204, 102, 0);
    glVertex3f(70.0, 15.0, 420.0);
    glVertex3f(0.0, 75.0, 420.0);
    glVertex3f(0.0, 90.0, 420.0);
    glVertex3f(70.0, 30.0, 420.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(204, 102, 0);
    glVertex3f(70.0, 30.0, 420.0);
    glVertex3f(0.0, 90.0, 420.0);
    glVertex3f(0.0, 90.0, 400.0);
    glVertex3f(70.0, 30.0, 400.0);
    glEnd();

     glBegin(GL_POLYGON);//bawah
    glColor3ub(204, 102, 0);
    glVertex3f(45.0, 36.5, 420.0);
    glVertex3f(0.0, 75.0, 420.0);
    glVertex3f(0.0, 75.0, 400.0);
    glVertex3f(45.0, 36.5, 400.0);
    glEnd();

    //Sebelah kanan
    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(70.0, 0.0, 400.0);
    glVertex3f(45.0, 0.0, 400.0);
    glVertex3f(45.0, 36.5, 400.0);
    glVertex3f(70.0, 15.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(70.0, 0.0, 420.0);
    glVertex3f(45.0, 0.0, 420.0);
    glVertex3f(45.0, 36.5, 420.0);
    glVertex3f(70.0, 15.0, 420.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(70.0, 0.0, 420.0);
    glVertex3f(70.0, 30.0, 420.0);
    glVertex3f(70.0, 30.0, 400.0);
    glVertex3f(70.0, 0.0, 400.0);
    glEnd();
    //Sebelah Kanan
    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(45.0, 0.0, 420.0);
    glVertex3f(45.0, 36.5, 420.0);
    glVertex3f(45.0, 36.5, 400.0);
    glVertex3f(45.0, 0.0, 400.0);
    glEnd();

    //palang atas gerbang
    glBegin(GL_POLYGON);//belakang
    glColor3ub(255, 247, 230);
    glVertex3f(-40.0, 65.0, 399.9);
    glVertex3f(0.0, 62.0, 399.9);
    glVertex3f(40.0, 65.0, 399.9);
    glVertex3f(35.0, 75.0, 399.9);
    glVertex3f(17.0, 68.0, 399.9);
    glVertex3f(-35.0, 75.0, 399.9);
    glEnd();

    glBegin(GL_POLYGON);//depan
    glColor3ub(255, 247, 230);
    glVertex3f(-40.0, 65.0, 420.1);
    glVertex3f(0.0, 62.0, 420.1);
    glVertex3f(40.0, 65.0, 420.1);
    glVertex3f(35.0, 75.0, 420.1);
    glVertex3f(17.0, 68.0, 420.1);
    glVertex3f(-35.0, 75.0, 420.1);
    glEnd();

    glBegin(GL_POLYGON);//atas kiri
    glColor3ub(255, 247, 230);
    glVertex3f(-35.0, 75.0, 420.1);
    glVertex3f(0.0, 70.0, 420.1);
    glVertex3f(0.0, 70.0, 399.9);
    glVertex3f(-35.0, 75.0, 399.9);
    glEnd();

    glBegin(GL_POLYGON);//atas kanan
    glColor3ub(255, 247, 230);
    glVertex3f(35.0, 75.0, 420.1);
    glVertex3f(0.0, 70.0, 420.1);
    glVertex3f(0.0, 70.0, 399.9);
    glVertex3f(35.0, 75.0, 399.9);
    glEnd();

    glBegin(GL_POLYGON);//bawah kiri
    glColor3ub(255, 247, 230);
    glVertex3f(-40.0, 65.0, 420.1);
    glVertex3f(0.0, 62.0, 420.1);
    glVertex3f(0.0, 62.0, 399.9);
    glVertex3f(-40.0, 65.0, 399.9);
    glEnd();

    glBegin(GL_POLYGON);//bawah kanan
    glColor3ub(255, 247, 230);
    glVertex3f(40.0, 65.0, 420.1);
    glVertex3f(0.0, 62.0, 420.1);
    glVertex3f(0.0, 62.0, 399.9);
    glVertex3f(40.0, 65.0, 399.9);
    glEnd();

    glBegin(GL_POLYGON);//tutup kiri
    glColor3ub(255, 247, 230);
    glVertex3f(-40.0, 65.0, 420.1);
    glVertex3f(-40.0, 65.0, 399.9);
    glVertex3f(-35.0, 75.0, 399.9);
    glVertex3f(-35.0, 75.0, 420.1);
    glEnd();

    glBegin(GL_POLYGON);//tutup kanan
    glColor3ub(255, 247, 230);
    glVertex3f(40.0, 65.0, 420.1);
    glVertex3f(40.0, 65.0, 399.9);
    glVertex3f(35.0, 75.0, 399.9);
    glVertex3f(35.0, 75.0, 420.1);
    glEnd();

    glPushMatrix();
        if(pin==1)
            glTranslated(-50, 0, 0);
    //GERBANG BARU KIRI
     int y = 5;
     int u = 5;
    for(int h=0; h<10; h++){
    glBegin(GL_LINES);
    glColor3ub(255,215,0);
        if(h==0){
    glLineWidth(10.0f);
    glVertex3f(-50.0, 30.0, 425.5);
    glVertex3f(-50.0, 0.0, 425.5);
        }else{
    glLineWidth(10.0f);
    glVertex3f(-50.0+y, 30.0, 425.5);
    glVertex3f(-50.0+y, 0.0, 425.5);
    y+=5;
        }
    }
    glEnd();

    int l = 7;
    for(int h=0; h<4; h++){
    glBegin(GL_LINES);
    glColor3ub(255,215,0);
        if(h==0){
    glLineWidth(10.0f);
    glVertex3f(-50.0, 5.0, 425.5);
    glVertex3f(0.0, 5.0, 425.);
        }else{
    glLineWidth(10.0f);
    glVertex3f(-50.0, 5.0+l, 425.5);
    glVertex3f(0.0, 5.0+l, 425.);
    l+=7;
        }
    }
    glEnd();
    glPopMatrix();

    //GERBANG BARU KANAN
    glPushMatrix();
        if(tag==1)
    glTranslated(50, 0, 0);
    int o = 5;
    for(int h=10; h>0; h--){
    glBegin(GL_LINES);
    glColor3ub(255,215,0);
        if(h==0){
    glLineWidth(10.0f);
    glVertex3f(55.0, 30.0, 425.5);
    glVertex3f(55.0, 0.0, 425.5);
        }else{
    glLineWidth(10.0f);
    glVertex3f(55.0-o, 30.0, 425.5);
    glVertex3f(55.0-o, 0.0, 425.5);
    o+=5;
        }
    }
    glEnd();

    int m = 7;
    for(int h=0; h<4; h++){
    glBegin(GL_LINES);
    glColor3ub(255,215,0);
        if(h==0){
    glLineWidth(10.0f);
    glVertex3f(50.0, 5.0, 425.5);
    glVertex3f(0.0, 5.0, 425.);
        }else{
    glLineWidth(10.0f);
    glVertex3f(50.0, 5.0+m, 425.5);
    glVertex3f(0.0, 5.0+m, 425.);
    m+=7;
        }
    }
    glEnd();
    glPopMatrix();
    //REL GERBANG
    glBegin(GL_LINES);
    glLineWidth(8.0f);
    glColor3ub(128,0,0);
    glVertex3f(-70.0, 0.0, 425.5);
    glVertex3f(70.0, 0.0, 425.5);
    glEnd();
    //papan nama gerbang
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex3f(-65.0, 8.0, 420.1);
    glVertex3f(-50.0, 8.0, 420.1);
    glVertex3f(-50.0, 22.0, 420.1);
    glVertex3f(-65.0, 22.0, 420.1);
    glEnd();
}
void jendelakutil(){
    int y = 30;
    float a = 0.1;
    for (int i = 0; i<7; i++){
        glBegin(GL_QUADS);
        if (i==0){
            glColor3ub(140, 140, 140);
            glVertex3f(-100.0, 255.0, 6.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-100.0, 230.0, 6.0);
            glColor3ub(140, 140, 140);
            glVertex3f(-80.0, 230.0, 6.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-80.0, 255.0, 6.0);
        }else{
            glColor3ub(140, 140, 140);
            glVertex3f(-100.0+y-a, 255.0, 6.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-100.0+y-a, 230.0, 6.0);
            glColor3ub(140, 140, 140);
            glVertex3f(-80.0+y-a, 230.0, 6.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-80.0+y-a, 255.0, 6.0);
            y+=30;
            a-=0.1;
        }
    }
    glEnd();
}
void sekatkaca(){
    int y = 30;
    float a = 0.1;
    for (int i = 0; i<6; i++){
        glBegin(GL_QUADS);
        glColor3ub(255, 247, 230);
        if (i==0){
           glVertex3f(-80.0, 255.0, 6.0);
           glVertex3f(-80.0, 230.0, 6.0);
           glVertex3f(-70.0, 230.0, 6.0);
           glVertex3f(-70.0, 255.0, 6.0);
        }else{
           glVertex3f(-80.0+y-a, 255.0, 6.0);
           glVertex3f(-80.0+y-a, 230.0, 6.0);
           glVertex3f(-70.0+y-a, 230.0, 6.0);
           glVertex3f(-70.0+y-a, 255.0, 6.0);
           y+=30;
           a-=0.1;
        }
    }
    glEnd();

    //PENUTUP BIAR GK MASUK ANGIN
    glBegin(GL_POLYGON);
    glColor3ub(255, 242, 230);
    glVertex3f(-100.0, 255.0, -9.9);
    glVertex3f(-100.0, 230.0, -9.9);
    glVertex3f(-100.0, 230.0, 6.0);
    glVertex3f(-100.0, 255.0, 6.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 242, 230);
    glVertex3f(100.0, 255.0, -9.9);
    glVertex3f(100.0, 230.0, -9.9);
    glVertex3f(100.0, 230.0, 6.0);
    glVertex3f(100.0, 255.0, 6.0);
    glEnd();
}
void kelas(){
    glBegin(GL_POLYGON);//sekat antara loby dan lantai 1
    glColor3ub(128, 128, 128);
    glVertex3f(-90.0,120.0,-90.0);
    glVertex3f(-120.0,120.0,-10.0);
    glVertex3f(120.0,120.0,-10.0);
    glVertex3f(90.0,120.0,-90.0);
    glVertex3f(120.0,120.0,-170.0);
    glVertex3f(-120.0,120.0,-170.0);
    glEnd();

    //kursi belakang
    glBegin(GL_QUADS);
        glColor3ub(90,132,220);
        glVertex3f(-30.0,120.0,-100.0);
        glVertex3f(-30.0,125.0,-100.0);
        glVertex3f(-30.0,125.0,-90.0);
        glVertex3f(-30.0,120.0,-90.0);

        glVertex3f(30.0,120.0,-100.0);
        glVertex3f(30.0,125.0,-100.0);
        glVertex3f(30.0,125.0,-90.0);
        glVertex3f(30.0,120.0,-90.0);

        glVertex3f(30.0,125.0,-100.0);
        glVertex3f(-30.0,125.0,-100.0);
        glVertex3f(-30.0,125.0,-90.0);
        glVertex3f(30.0,125.0,-90.0);

        glVertex3f(30.0,125.0,-100.0);
        glVertex3f(-30.0,125.0,-100.0);
        glVertex3f(-30.0,132.0,-102.0);
        glVertex3f(30.0,132.0,-102.0);

        //meja belakang
        glColor3ub(200,50,50);
        glVertex3f(-35.0,120.0,-85.0);
        glVertex3f(-35.0,131.0,-85.0);
        glVertex3f(-35.0,131.0,-75.0);
        glVertex3f(-35.0,120.0,-75.0);

        glVertex3f(35.0,120.0,-85.0);
        glVertex3f(35.0,131.0,-85.0);
        glVertex3f(35.0,131.0,-75.0);
        glVertex3f(35.0,120.0,-75.0);

        glVertex3f(35.0,131.0,-85.0);
        glVertex3f(-35.0,131.0,-85.0);
        glVertex3f(-35.0,131.0,-75.0);
        glVertex3f(35.0,131.0,-75.0);

        glColor3f(0.0,0.0,0.0);
        glVertex3f(-35.0,120.0,-75.0);
        glVertex3f(-35.0,131.0,-75.0);
        glVertex3f(35.0,131.0,-75.0);
        glVertex3f(35.0,120.0,-75.0);

        //kursi depan
        glColor3ub(90,132,220);
        glVertex3f(-30.0,120.0,-70.0);
        glVertex3f(-30.0,125.0,-70.0);
        glVertex3f(-30.0,125.0,-60.0);
        glVertex3f(-30.0,120.0,-60.0);

        glVertex3f(30.0,120.0,-70.0);
        glVertex3f(30.0,125.0,-70.0);
        glVertex3f(30.0,125.0,-60.0);
        glVertex3f(30.0,120.0,-60.0);

        glVertex3f(30.0,125.0,-70.0);
        glVertex3f(-30.0,125.0,-70.0);
        glVertex3f(-30.0,125.0,-60.0);
        glVertex3f(30.0,125.0,-60.0);

        glVertex3f(30.0,125.0,-70.0);
        glVertex3f(-30.0,125.0,-70.0);
        glVertex3f(-30.0,132.0,-72.0);
        glVertex3f(30.0,132.0,-72.0);

        //meja depan
        glColor3ub(200,50,50);
        glVertex3f(-35.0,120.0,-55.0);
        glVertex3f(-35.0,131.0,-55.0);
        glVertex3f(-35.0,131.0,-45.0);
        glVertex3f(-35.0,120.0,-45.0);

        glVertex3f(35.0,120.0,-55.0);
        glVertex3f(35.0,131.0,-55.0);
        glVertex3f(35.0,131.0,-45.0);
        glVertex3f(35.0,120.0,-45.0);

        glVertex3f(35.0,131.0,-55.0);
        glVertex3f(-35.0,131.0,-55.0);
        glVertex3f(-35.0,131.0,-45.0);
        glVertex3f(35.0,131.0,-45.0);

        glColor3f(0.0,0.0,0.0);
        glVertex3f(-35.0,120.0,-45.0);
        glVertex3f(-35.0,131.0,-45.0);
        glVertex3f(35.0,131.0,-45.0);
        glVertex3f(35.0,120.0,-45.0);
    glEnd();

    //LEMARI
    glBegin(GL_POLYGON);//depan
    glColor3ub(204, 102, 0);
    glVertex3f(56.0,123.0,-11.0);
    glVertex3f(90.0,123.0,-11.0);
    glVertex3f(90.0,160.0,-11.0);
    glVertex3f(56.0,160.0,-11.0);
    glEnd();

    glBegin(GL_POLYGON);//belakang
    glColor3ub(204, 102, 0);
    glVertex3f(56.0,123.0,-25.0);
    glVertex3f(90.0,123.0,-25.0);
    glVertex3f(90.0,160.0,-25.0);
    glVertex3f(56.0,160.0,-25.0);
    glEnd();

    glBegin(GL_POLYGON);//pintu kanannya
    glColor3ub(153, 153, 153);
    glVertex3f(57.0,125.0,-25.1);
    glVertex3f(72.0,125.0,-25.1);
    glVertex3f(72.0,158.0,-25.1);
    glVertex3f(57.0,158.0,-25.1);
    glEnd();

    glBegin(GL_POLYGON);//pegangan pintu kanan
    glColor3ub(0, 0, 0);
    glVertex3f(69.0,142.0,-25.2);
    glVertex3f(71.0,142.0,-25.2);
    glVertex3f(71.0,144.0,-25.2);
    glVertex3f(69.0,144.0,-25.2);
    glEnd();

    glBegin(GL_POLYGON);//pintu kirinya
    glColor3ub(153, 153, 153);
    glVertex3f(74.0,125.0,-25.1);
    glVertex3f(89.0,125.0,-25.1);
    glVertex3f(89.0,158.0,-25.1);
    glVertex3f(74.0,158.0,-25.1);
    glEnd();

    glBegin(GL_POLYGON);//pegangan pintu kiri
    glColor3ub(0, 0, 0);
    glVertex3f(77.0,142.0,-25.2);
    glVertex3f(75.0,142.0,-25.2);
    glVertex3f(75.0,144.0,-25.2);
    glVertex3f(77.0,144.0,-25.2);
    glEnd();

    glBegin(GL_POLYGON);//kiri
    glColor3ub(204, 102, 0);
    glVertex3f(56.0,123.0,-11.0);
    glVertex3f(56.0,123.0,-25.0);
    glVertex3f(56.0,160.0,-25.0);
    glVertex3f(56.0,160.0,-11.0);
    glEnd();

    glBegin(GL_POLYGON);//kanan
    glColor3ub(204, 102, 0);
    glVertex3f(90.0,123.0,-11.0);
    glVertex3f(90.0,123.0,-25.0);
    glVertex3f(90.0,160.0,-25.0);
    glVertex3f(90.0,160.0,-11.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(204, 102, 0);
    glVertex3f(56.0,160.0,-11.0);
    glVertex3f(90.0,160.0,-11.0);
    glVertex3f(90.0,160.0,-25.0);
    glVertex3f(56.0,160.0,-25.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(204, 102, 0);
    glVertex3f(56.0,123.0,-11.0);
    glVertex3f(90.0,123.0,-11.0);
    glVertex3f(90.0,123.0,-25.0);
    glVertex3f(56.0,123.0,-25.0);
    glEnd();

    //KAKI KIRI LEMARI
    glBegin(GL_POLYGON);//depan
    glColor3ub(0, 255, 0);
    glVertex3f(87.0,120.1,-14.0);
    glVertex3f(84.0,120.1,-14.0);
    glVertex3f(84.0,122.9,-14.0);
    glVertex3f(87.0,122.9,-14.0);
    glEnd();

    glBegin(GL_POLYGON);//belakang
    glColor3ub(0, 255, 0);
    glVertex3f(87.0,120.1,-22.0);
    glVertex3f(84.0,120.1,-22.0);
    glVertex3f(84.0,122.9,-22.0);
    glVertex3f(87.0,122.9,-22.0);
    glEnd();

    glBegin(GL_POLYGON);//kiri
    glColor3ub(255, 255, 0);
    glVertex3f(87.0,120.1,-14.0);
    glVertex3f(87.0,120.1,-22.0);
    glVertex3f(87.0,123.0,-22.0);
    glVertex3f(87.0,123.0,-14.0);
    glEnd();

    glBegin(GL_POLYGON);//kanan
    glColor3ub(255, 255, 0);
    glVertex3f(84.0,120.1,-14.0);
    glVertex3f(84.0,120.1,-22.0);
    glVertex3f(84.0,123.0,-22.0);
    glVertex3f(84.0,123.0,-14.0);
    glEnd();

    //KAKI KANAN LEMARI
    glBegin(GL_POLYGON);//depan
    glColor3ub(0, 255, 0);
    glVertex3f(60.0,120.1,-14.0);
    glVertex3f(63.0,120.1,-14.0);
    glVertex3f(63.0,122.9,-14.0);
    glVertex3f(60.0,122.9,-14.0);
    glEnd();

    glBegin(GL_POLYGON);//belakang
    glColor3ub(0, 255, 0);
    glVertex3f(60.0,120.1,-22.0);
    glVertex3f(63.0,120.1,-22.0);
    glVertex3f(63.0,122.9,-22.0);
    glVertex3f(60.0,122.9,-22.0);
    glEnd();

    glBegin(GL_POLYGON);//kiri
    glColor3ub(255, 255, 0);
    glVertex3f(60.0,120.1,-14.0);
    glVertex3f(60.0,120.1,-22.0);
    glVertex3f(60.0,123.0,-22.0);
    glVertex3f(60.0,123.0,-14.0);
    glEnd();

    glBegin(GL_POLYGON);//kanan
    glColor3ub(255, 255, 0);
    glVertex3f(63.0,120.1,-14.0);
    glVertex3f(63.0,120.1,-22.0);
    glVertex3f(63.0,123.0,-22.0);
    glVertex3f(63.0,123.0,-14.0);
    glEnd();

    //PAPAN TULIS
    glBegin(GL_POLYGON);//depan
    glColor3ub(204, 102, 0);
    glVertex3f(-20.0,125.0,-11.0);
    glVertex3f(20.0,125.0,-11.0);
    glVertex3f(20.0,150.0,-11.0);
    glVertex3f(-20.0,150.0,-11.0);
    glEnd();

    glBegin(GL_POLYGON);//belakang
    glColor3ub(255, 255, 255);
    glVertex3f(-20.0,125.0,-18.0);
    glVertex3f(20.0,125.0,-18.0);
    glVertex3f(20.0,150.0,-18.0);
    glVertex3f(-20.0,150.0,-18.0);
    glEnd();

    glBegin(GL_POLYGON);//kiri
    glColor3ub(204, 102, 0);
    glVertex3f(-20.0,125.0,-11.0);
    glVertex3f(-20.0,125.0,-18.0);
    glVertex3f(-20.0,150.0,-18.0);
    glVertex3f(-20.0,150.0,-11.0);
    glEnd();

    glBegin(GL_POLYGON);//kanan
    glColor3ub(204, 102, 0);
    glVertex3f(20.0,125.0,-11.0);
    glVertex3f(20.0,125.0,-18.0);
    glVertex3f(20.0,150.0,-18.0);
    glVertex3f(20.0,150.0,-11.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(204, 102, 0);
    glVertex3f(-20.0,150.0,-11.0);
    glVertex3f(20.0,150.0,-11.0);
    glVertex3f(20.0,150.0,-18.0);
    glVertex3f(-20.0,150.0,-18.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(204, 102, 0);
    glVertex3f(-20.0,125.0,-11.0);
    glVertex3f(20.0,125.0,-11.0);
    glVertex3f(20.0,125.0,-18.0);
    glVertex3f(-20.0,125.0,-18.0);
    glEnd();

    //KAKI KIRI PAPANTULIS
    glBegin(GL_POLYGON);//depan
    glColor3ub(0, 255, 0);
    glVertex3f(-13.0,120.1,-14.0);
    glVertex3f(-10.0,120.1,-14.0);
    glVertex3f(-10.0,124.9,-14.0);
    glVertex3f(-13.0,124.9,-14.0);
    glEnd();

    glBegin(GL_POLYGON);//belakang
    glColor3ub(0, 255, 0);
    glVertex3f(-13.0,120.1,-15.0);
    glVertex3f(-10.0,120.1,-15.0);
    glVertex3f(-10.0,124.9,-15.0);
    glVertex3f(-13.0,124.9,-15.0);
    glEnd();

    glBegin(GL_POLYGON);//kiri
    glColor3ub(255, 255, 0);
    glVertex3f(-13.0,120.1,-14.0);
    glVertex3f(-13.0,120.1,-15.0);
    glVertex3f(-13.0,125.0,-15.0);
    glVertex3f(-13.0,125.0,-14.0);
    glEnd();

    glBegin(GL_POLYGON);//kanan
    glColor3ub(255, 255, 0);
    glVertex3f(-10.0,120.1,-14.0);
    glVertex3f(-10.0,120.1,-15.0);
    glVertex3f(-10.0,125.0,-15.0);
    glVertex3f(-10.0,125.0,-14.0);
    glEnd();

    //KAKI KANAN PAPANTULIS
    glBegin(GL_POLYGON);//depan
    glColor3ub(0, 255, 0);
    glVertex3f(13.0,120.1,-14.0);
    glVertex3f(10.0,120.1,-14.0);
    glVertex3f(10.0,124.9,-14.0);
    glVertex3f(13.0,124.9,-14.0);
    glEnd();

    glBegin(GL_POLYGON);//belakang
    glColor3ub(0, 255, 0);
    glVertex3f(13.0,120.1,-15.0);
    glVertex3f(10.0,120.1,-15.0);
    glVertex3f(10.0,124.9,-15.0);
    glVertex3f(13.0,124.9,-15.0);
    glEnd();

    glBegin(GL_POLYGON);//kiri
    glColor3ub(255, 255, 0);
    glVertex3f(13.0,120.1,-14.0);
    glVertex3f(13.0,120.1,-15.0);
    glVertex3f(13.0,125.0,-15.0);
    glVertex3f(13.0,125.0,-14.0);
    glEnd();

    glBegin(GL_POLYGON);//kanan
    glColor3ub(255, 255, 0);
    glVertex3f(10.0,120.1,-14.0);
    glVertex3f(10.0,120.1,-15.0);
    glVertex3f(10.0,125.0,-15.0);
    glVertex3f(10.0,125.0,-14.0);
    glEnd();
}
void lobi(){
    //TV
    glBegin(GL_POLYGON);//depan
    glColor3ub(0, 0, 0);
    glVertex3f(-30.0,70.0,-108.0);
    glVertex3f(30.0,70.0,-108.0);
    glVertex3f(30.0,113.0,-100.0);
    glVertex3f(-30.0,113.0,-100.0);
    glEnd();

    glBegin(GL_POLYGON);//belakang
    glColor3ub(0, 0, 0);
    glVertex3f(-30.0,70.0,-110.0);
    glVertex3f(30.0,70.0,-110.0);
    glVertex3f(30.0,113.0,-102.0);
    glVertex3f(-30.0,113.0,-102.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(128, 128, 128);
    glVertex3f(-30.0,113.0,-100.0);
    glVertex3f(30.0,113.0,-100.0);
    glVertex3f(30.0,113.0,-102.0);
    glVertex3f(-30.0,113.0,-102.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(128, 128, 128);
    glVertex3f(-30.0,70.0,-108.0);
    glVertex3f(30.0,70.0,-108.0);
    glVertex3f(30.0,70.0,-110.0);
    glVertex3f(-30.0,70.0,-110.0);
    glEnd();

    glBegin(GL_POLYGON);//kiri
    glColor3ub(128, 128, 128);
    glVertex3f(-30.0,70.0,-110.0);
    glVertex3f(-30.0,70.0,-108.0);
    glVertex3f(-30.0,113.0,-102.0);
    glVertex3f(-30.0,113.0,-100.0);
    glEnd();

    glBegin(GL_POLYGON);//kanan
    glColor3ub(128, 128, 128);
    glVertex3f(30.0,70.0,-110.0);
    glVertex3f(30.0,70.0,-108.0);
    glVertex3f(30.0,113.0,-102.0);
    glVertex3f(30.0,113.0,-100.0);
    glEnd();

    glBegin(GL_POLYGON);//layar putih
    glColor3ub(217, 217, 217);
    glVertex3f(-28.0,73.0,-106.9);
    glVertex3f(28.0,73.0,-106.9);
    glVertex3f(28.0,110.0,-99.9);
    glVertex3f(-28.0,110.0,-99.9);
    glEnd();

    glBegin(GL_POLYGON);//antena kanan
    glColor3ub(0, 0, 0);
    glVertex3f(16.0,113.1,-102.0);
    glVertex3f(14.0,113.1,-102.0);
    glVertex3f(16.0,117.0,-100.0);
    glVertex3f(18.0,117.0,-100.0);
    glEnd();

    glBegin(GL_POLYGON);//antena kiri
    glColor3ub(0, 0, 0);
    glVertex3f(13.0,113.1,-102.0);
    glVertex3f(15.0,113.1,-102.0);
    glVertex3f(13,117.0,-100.0);
    glVertex3f(11.0,117.0,-100.0);
    glEnd();

    //kursi kanan
    glBegin(GL_QUADS);
    glColor3ub(100,100,255);
        glVertex3f(50.0,6.0,-80.0);
        glVertex3f(60.0,6.0,-80.0);
        glVertex3f(60.0,6.0,-40.0);
        glVertex3f(50.0,6.0,-40.0);

        glVertex3f(60.0,6.0,-80.0);
        glVertex3f(63.0,17.0,-80.0);
        glVertex3f(63.0,17.0,-40.0);
        glVertex3f(60.0,6.0,-40.0);

        glVertex3f(63.0,17.0,-80.0);
        glVertex3f(65.0,17.0,-80.0);
        glVertex3f(65.0,17.0,-40.0);
        glVertex3f(63.0,17.0,-40.0);

        glVertex3f(65.0,0.0,-80.0);
        glVertex3f(65.0,17.0,-80.0);
        glVertex3f(65.0,17.0,-40.0);
        glVertex3f(65.0,0.0,-40.0);

        glVertex3f(50.0,0.0,-80.0);
        glVertex3f(50.0,6.0,-80.0);
        glVertex3f(50.0,6.0,-40.0);
        glVertex3f(50.0,0.0,-40.0);
        //tutupan
        glColor3ub(150,150,150);
        glVertex3f(50.0,6.0,-80.0);
        glVertex3f(65.0,6.0,-80.0);
        glVertex3f(65.0,0.0,-80.0);
        glVertex3f(50.0,0.0,-80.0);

        glVertex3f(60.0,6.0,-80.0);
        glVertex3f(63.0,17.0,-80.0);
        glVertex3f(65.0,17.0,-80.0);
        glVertex3f(65.0,0.0,-80.0);

        glVertex3f(50.0,6.0,-40.0);
        glVertex3f(65.0,6.0,-40.0);
        glVertex3f(65.0,0.0,-40.0);
        glVertex3f(50.0,0.0,-40.0);

        glVertex3f(60.0,6.0,-40.0);
        glVertex3f(63.0,17.0,-40.0);
        glVertex3f(65.0,17.0,-40.0);
        glVertex3f(65.0,0.0,-40.0);

        //tangan
        glColor3ub(220,220,220);
        glVertex3f(50.0,0.0,-38.0);
        glVertex3f(50.0,8.0,-38.0);
        glVertex3f(50.0,8.0,-40.0);
        glVertex3f(50.0,0.0,-40.0);

        glVertex3f(50.0,8.0,-40.0);
        glVertex3f(65.0,8.0,-40.0);
        glVertex3f(65.0,8.0,-38.0);
        glVertex3f(50.0,8.0,-38.0);

        glVertex3f(65.0,0.0,-38.0);
        glVertex3f(65.0,0.0,-40.0);
        glVertex3f(65.0,8.0,-40.0);
        glVertex3f(65.0,8.0,-38.0);
        //
        glVertex3f(50.0,0.0,-82.0);
        glVertex3f(50.0,8.0,-82.0);
        glVertex3f(50.0,8.0,-80.0);
        glVertex3f(50.0,0.0,-80.0);

        glVertex3f(50.0,8.0,-80.0);
        glVertex3f(65.0,8.0,-80.0);
        glVertex3f(65.0,8.0,-82.0);
        glVertex3f(50.0,8.0,-82.0);

        glVertex3f(65.0,0.0,-82.0);
        glVertex3f(65.0,0.0,-80.0);
        glVertex3f(65.0,8.0,-80.0);
        glVertex3f(65.0,8.0,-82.0);
    glEnd();

    //meja kanan
    glBegin(GL_QUADS);
        glColor3ub(50,50,190);
        glVertex3f(38.0,8.0,-80.0);
        glVertex3f(38.0,8.0,-40.0);
        glVertex3f(25.0,8.0,-40.0);
        glVertex3f(25.0,8.0,-80.0);

        glColor3ub(220,220,220);
        glVertex3f(25.0,0.0,-38.0);
        glVertex3f(25.0,8.0,-38.0);
        glVertex3f(25.0,8.0,-40.0);
        glVertex3f(25.0,0.0,-40.0);

        glVertex3f(25.0,8.0,-40.0);
        glVertex3f(38.0,8.0,-40.0);
        glVertex3f(38.0,8.0,-38.0);
        glVertex3f(25.0,8.0,-38.0);

        glVertex3f(38.0,0.0,-38.0);
        glVertex3f(38.0,0.0,-40.0);
        glVertex3f(38.0,8.0,-40.0);
        glVertex3f(38.0,8.0,-38.0);
        ///
        glVertex3f(25.0,0.0,-82.0);
        glVertex3f(25.0,8.0,-82.0);
        glVertex3f(25.0,8.0,-80.0);
        glVertex3f(25.0,0.0,-80.0);

        glVertex3f(25.0,8.0,-80.0);
        glVertex3f(38.0,8.0,-80.0);
        glVertex3f(38.0,8.0,-82.0);
        glVertex3f(25.0,8.0,-82.0);

        glVertex3f(38.0,0.0,-82.0);
        glVertex3f(38.0,0.0,-80.0);
        glVertex3f(38.0,8.0,-80.0);
        glVertex3f(38.0,8.0,-82.0);
    glEnd();


    //kursi kiri
    glBegin(GL_QUADS);
    glColor3ub(100,100,255);
        glVertex3f(-50.0,6.0,-80.0);
        glVertex3f(-60.0,6.0,-80.0);
        glVertex3f(-60.0,6.0,-40.0);
        glVertex3f(-50.0,6.0,-40.0);

        glVertex3f(-60.0,6.0,-80.0);
        glVertex3f(-63.0,17.0,-80.0);
        glVertex3f(-63.0,17.0,-40.0);
        glVertex3f(-60.0,6.0,-40.0);

        glVertex3f(-63.0,17.0,-80.0);
        glVertex3f(-65.0,17.0,-80.0);
        glVertex3f(-65.0,17.0,-40.0);
        glVertex3f(-63.0,17.0,-40.0);

        glVertex3f(-65.0,0.0,-80.0);
        glVertex3f(-65.0,17.0,-80.0);
        glVertex3f(-65.0,17.0,-40.0);
        glVertex3f(-65.0,0.0,-40.0);

        glVertex3f(-50.0,0.0,-80.0);
        glVertex3f(-50.0,6.0,-80.0);
        glVertex3f(-50.0,6.0,-40.0);
        glVertex3f(-50.0,0.0,-40.0);
        //tutupan
        glColor3ub(150,150,150);
        glVertex3f(-50.0,6.0,-80.0);
        glVertex3f(-65.0,6.0,-80.0);
        glVertex3f(-65.0,0.0,-80.0);
        glVertex3f(-50.0,0.0,-80.0);

        glVertex3f(-60.0,6.0,-80.0);
        glVertex3f(-63.0,17.0,-80.0);
        glVertex3f(-65.0,17.0,-80.0);
        glVertex3f(-65.0,0.0,-80.0);

        glVertex3f(-50.0,6.0,-40.0);
        glVertex3f(-65.0,6.0,-40.0);
        glVertex3f(-65.0,0.0,-40.0);
        glVertex3f(-50.0,0.0,-40.0);

        glVertex3f(-60.0,6.0,-40.0);
        glVertex3f(-63.0,17.0,-40.0);
        glVertex3f(-65.0,17.0,-40.0);
        glVertex3f(-65.0,0.0,-40.0);

        //tangan
        glColor3ub(220,220,220);
        glVertex3f(-50.0,0.0,-38.0);
        glVertex3f(-50.0,8.0,-38.0);
        glVertex3f(-50.0,8.0,-40.0);
        glVertex3f(-50.0,0.0,-40.0);

        glVertex3f(-50.0,8.0,-40.0);
        glVertex3f(-65.0,8.0,-40.0);
        glVertex3f(-65.0,8.0,-38.0);
        glVertex3f(-50.0,8.0,-38.0);

        glVertex3f(-65.0,0.0,-38.0);
        glVertex3f(-65.0,0.0,-40.0);
        glVertex3f(-65.0,8.0,-40.0);
        glVertex3f(-65.0,8.0,-38.0);
        //
        glVertex3f(-50.0,0.0,-82.0);
        glVertex3f(-50.0,8.0,-82.0);
        glVertex3f(-50.0,8.0,-80.0);
        glVertex3f(-50.0,0.0,-80.0);

        glVertex3f(-50.0,8.0,-80.0);
        glVertex3f(-65.0,8.0,-80.0);
        glVertex3f(-65.0,8.0,-82.0);
        glVertex3f(-50.0,8.0,-82.0);

        glVertex3f(-65.0,0.0,-82.0);
        glVertex3f(-65.0,0.0,-80.0);
        glVertex3f(-65.0,8.0,-80.0);
        glVertex3f(-65.0,8.0,-82.0);
    glEnd();

    //meja kiri
    glBegin(GL_QUADS);
        glColor3ub(50,50,190);
        glVertex3f(-38.0,8.0,-80.0);
        glVertex3f(-38.0,8.0,-40.0);
        glVertex3f(-25.0,8.0,-40.0);
        glVertex3f(-25.0,8.0,-80.0);

        glColor3ub(220,220,220);
        glVertex3f(-25.0,0.0,-38.0);
        glVertex3f(-25.0,8.0,-38.0);
        glVertex3f(-25.0,8.0,-40.0);
        glVertex3f(-25.0,0.0,-40.0);

        glVertex3f(-25.0,8.0,-40.0);
        glVertex3f(-38.0,8.0,-40.0);
        glVertex3f(-38.0,8.0,-38.0);
        glVertex3f(-25.0,8.0,-38.0);

        glVertex3f(-38.0,0.0,-38.0);
        glVertex3f(-38.0,0.0,-40.0);
        glVertex3f(-38.0,8.0,-40.0);
        glVertex3f(-38.0,8.0,-38.0);
        //
        glVertex3f(-25.0,0.0,-82.0);
        glVertex3f(-25.0,8.0,-82.0);
        glVertex3f(-25.0,8.0,-80.0);
        glVertex3f(-25.0,0.0,-80.0);

        glVertex3f(-25.0,8.0,-80.0);
        glVertex3f(-38.0,8.0,-80.0);
        glVertex3f(-38.0,8.0,-82.0);
        glVertex3f(-25.0,8.0,-82.0);

        glVertex3f(-38.0,0.0,-82.0);
        glVertex3f(-38.0,0.0,-80.0);
        glVertex3f(-38.0,8.0,-80.0);
        glVertex3f(-38.0,8.0,-82.0);
    glEnd();

}
void kaca_gedungTinggi(){
    int y = 34;
    float a = 0.1;
    for (int i = 0; i<7; i++){
        glBegin(GL_QUADS);
        if (i==0){
            glColor3ub(140, 140, 140);
            glVertex3f(-129.0,307.0,6.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-120.5,307.0,-15.0);
            glColor3ub(140, 140, 140);
            glVertex3f(-120.5,320.0,-15.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-129.0,320.0,6.0);
        }else{
            glColor3ub(140, 140, 140);
            glVertex3f(-129.0,307.0-y,6.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-120.5,307.0-y,-10.0);
            glColor3ub(140, 140, 140);
            glVertex3f(-120.5,320.0-y,-10.0);
            glColor3ub(255, 255, 255);
            glVertex3f(-129.0,320.0-y,6.0);
            y+=34;
            a-=0.1;
        }
        glEnd();
    }
    for (int i = 0; i<7; i++){
        glBegin(GL_QUADS);
        glColor3ub(0, 0, 255);
        if (i==0){
            glColor3ub(140, 140, 140);
            glVertex3f(129.0,307.0,6.0);
            glColor3ub(255, 255, 255);
            glVertex3f(120.5,307.0,-15.0);
            glColor3ub(140, 140, 140);
            glVertex3f(120.5,320.0,-15.0);
            glColor3ub(255, 255, 255);
            glVertex3f(129.0,320.0,6.0);
        }else{
            glColor3ub(140, 140, 140);
            glVertex3f(129.0,307.0-y+205,6.0);
            glColor3ub(255, 255, 255);
            glVertex3f(120.5,307.0-y+205,-15.0);
            glColor3ub(140, 140, 140);
            glVertex3f(120.5,320.0-y+205,-15.0);
            glColor3ub(255, 255, 255);
            glVertex3f(129.0,320.0-y+205,6.0);
            y+=34;
            a-=0.1;
        }
        glEnd();
    }
}
void pintumasukUniv(){
    glBegin(GL_POLYGON);
    glColor3ub(0,255,255);
    glVertex3f(-55.0 + gerak, 0.0, -9.9);
    glVertex3f(-20.0 + gerak, 0.0, -9.9);
    glVertex3f(-20.0 + gerak, 50.0, -9.9);
    glVertex3f(-55 + gerak, 50.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,255,255);
    glVertex3f(55.0 + gerak1, 0.0, -9.9);
    glVertex3f(20.0 + gerak1, 0.0, -9.9);
    glVertex3f(20.0 + gerak1, 50.0, -9.9);
    glVertex3f(55 + gerak1, 50.0, -9.9);
    glEnd();
}
void matahari(){
    //bulat tengah
	glPushMatrix();
	glLineWidth(3.0f);
	glRotated(a, 0, 0, -1);
	glBegin(GL_POLYGON);
	if(a%2==0){
        glColor3ub(255, 140, 26);
        ngon(100, 300, 300, 15, 180);
	}
	else{
        glColor3ub(255, 255, 0);
        ngon(100, 300, 300, 15, 180);
	}
    glEnd();
	glPopMatrix();
    //sinarnya
	glPushMatrix();
	glRotated(a, 0, 0, -1);
	glLineWidth(8.0f);
	glBegin(GL_LINES);

    if(a%2==0){
        glColor3ub(255, 255, 0);
        glVertex2f(315,300);glVertex2f(325,310);
        glVertex2f(311.5,310);glVertex2f(325,310);
        glVertex2f(311,310);glVertex2f(315,321);
        glVertex2f(301,315);glVertex2f(315,321);

        glVertex2f(291,325);glVertex2f(301,315);
        glVertex2f(291,325);glVertex2f(291,312);
        glVertex2f(291,312);glVertex2f(275,312);
        glVertex2f(275,312);glVertex2f(285,304);

        glVertex2f(285,304);glVertex2f(274,291);
        glVertex2f(274,291);glVertex2f(288,292);
        glVertex2f(288,292);glVertex2f(287,278);
        glVertex2f(287,278);glVertex2f(297,285);

        glVertex2f(297,285);glVertex2f(308,276);
        glVertex2f(308,276);glVertex2f(310,288);
        glVertex2f(310,288);glVertex2f(321,287);
        glVertex2f(321,287);glVertex2f(315,300);
	}
	else{
        glColor3ub(255, 140, 26);
        glVertex2f(315,300);glVertex2f(325,310);
        glVertex2f(311.5,310);glVertex2f(325,310);
        glVertex2f(311,310);glVertex2f(315,321);
        glVertex2f(301,315);glVertex2f(315,321);

        glVertex2f(291,325);glVertex2f(301,315);
        glVertex2f(291,325);glVertex2f(291,312);
        glVertex2f(291,312);glVertex2f(275,312);
        glVertex2f(275,312);glVertex2f(285,304);

        glVertex2f(285,304);glVertex2f(274,291);
        glVertex2f(274,291);glVertex2f(288,292);
        glVertex2f(288,292);glVertex2f(287,278);
        glVertex2f(287,278);glVertex2f(297,285);

        glVertex2f(297,285);glVertex2f(308,276);
        glVertex2f(308,276);glVertex2f(310,288);
        glVertex2f(310,288);glVertex2f(321,287);
        glVertex2f(321,287);glVertex2f(315,300);
	}
	glEnd();
	glPopMatrix();
}
void pilarATASgedung(){
    int y = 26;
    float a = 0.1;
    for (int i = 0; i<7; i++){
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 153);
        if (i==0){
            glColor3ub(255, 229, 204);
            glVertex3f(-75.0,280.0,-15.0);
            glColor3ub(217, 217, 217);
            glVertex3f(-85.0,280.0,-15.0);
            glColor3ub(255, 229, 204);
            glVertex3f(-85.0,300.0,-15.0);
            glColor3ub(217, 217, 217);
            glVertex3f(-75.0,300.0,-15.0);
        }else{
            glColor3ub(255, 229, 204);
            glVertex3f(-75.0+y-a,280.0,-15.0);
            glColor3ub(217, 217, 217);
            glVertex3f(-85.0+y-a,280.0,-15.0);
            glColor3ub(255, 229, 204);
            glVertex3f(-85.0+y-a,300.0,-15.0);
            glColor3ub(217, 217, 217);
            glVertex3f(-75.0+y-a,300.0,-15.0);
            y+=26;
            a-=0.1;
        }
        glEnd();
    }
    glBegin(GL_QUADS);//atasnya
    glColor3ub(255, 229, 204);
    glVertex3f(-130.0,300.0,-15.0);
    glColor3ub(217, 217, 217);
    glVertex3f(130.0,300.0,-15.0);
    glColor3ub(255, 229, 204);
    glVertex3f(130.0,308.0,-15.0);
    glColor3ub(217, 217, 217);
    glVertex3f(-130.0,308.0,-15.0);
    glEnd();
}
void pilarATASgedungBELAKANG(){
    int y = 26;
    float a = 0.1;
    for (int i = 0; i<7; i++){
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 153);
        if (i==0){
            glColor3ub(255, 229, 204);
            glVertex3f(-75.0,280.0,-160.0);
            glColor3ub(217, 217, 217);
            glVertex3f(-85.0,280.0,-160.0);
            glColor3ub(255, 229, 204);
            glVertex3f(-85.0,300.0,-160.0);
            glColor3ub(217, 217, 217);
            glVertex3f(-75.0,300.0,-160.0);
        }else{
            glColor3ub(255, 229, 204);
            glVertex3f(-75.0+y-a,280.0,-160.0);
            glColor3ub(217, 217, 217);
            glVertex3f(-85.0+y-a,280.0,-160.0);
            glColor3ub(255, 229, 204);
            glVertex3f(-85.0+y-a,300.0,-160.0);
            glColor3ub(217, 217, 217);
            glVertex3f(-75.0+y-a,300.0,-160.0);
            y+=26;
            a-=0.1;
        }
        glEnd();
    }
    glBegin(GL_QUADS);//atasnya
    glColor3ub(255, 229, 204);
    glVertex3f(-130.0,300.0,-160.0);
    glColor3ub(217, 217, 217);
    glVertex3f(130.0,300.0,-160.0);
    glColor3ub(255, 229, 204);
    glVertex3f(130.0,308.0,-160.0);
    glColor3ub(217, 217, 217);
    glVertex3f(-130.0,308.0,-160.0);
    glEnd();
}
void coba(){
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(xrot,1,0,0);
	glRotatef(yrot,0,1,0);
}
void tampil(void){
    glPushMatrix();
    coba();
    glScalef(1.5, 1.5, 1.0);

    //Garis AB
    float ax=-300;
    float ay=300;
    float bx=-280;
    float by=301;

    //Garis CD
    float cx=-290;
    float cy=292;
    float dx=-291;
    float dy=308;

    //Garis EF
    float ex=-297;
    float ey=305;
    float fx=-282;
    float fy=295;

    //Garis GH
    float gx=-297;
    float gy=295;
    float hx=-285;
    float hy=305;

    float m1,c1,m2,c2,m3,c3,m4,c4,px,py;//p = variabel untuk mencari titik potong

    glBegin(GL_QUADS);//belakang
    glColor3ub(217, 217, 217);
    glVertex3f(-130.0,0.0,-170.0);
    glColor3ub(217, 217, 217);
    glVertex3f(130.0,0.0,-170.0);
    glColor3ub(255, 242, 230);
    glVertex3f(130.0,280.0,-170.0);
    glColor3ub(255, 242, 230);
    glVertex3f(-130.0,280.0,-170.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(128, 128, 128);
    glVertex3f(-100.0,0.1,-60.0);
    glVertex3f(-130.0,0.1,-10.0);
    glVertex3f(130.0,0.1,-10.0);
    glVertex3f(100.0,0.1,-60.0);
    glVertex3f(130.0,0.1,-110.0);
    glVertex3f(-130.0,0.1,-110.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(217, 217, 217);
    glVertex3f(-100.0,280.0,-90.0);
    glColor3ub(255, 247, 230);
    glVertex3f(-130.0,280.0,-10.0);
    glVertex3f(130.0,280.0,-10.0);
    glColor3ub(217, 217, 217);
    glVertex3f(100.0,280.0,-90.0);
    glColor3ub(255, 247, 230);
    glVertex3f(130.0,280.0,-170.0);
    glVertex3f(-130.0,280.0,-170.0);
    glEnd();

    glBegin(GL_QUADS);//kiri depan
    glColor3ub(255, 239, 204);
    glVertex3f(-120.0,0.1,-10.0);
    glVertex3f(-90.0,0.1,-90.0);
    glVertex3f(-90.0,280.0,-90.0);
    glVertex3f(-120.0,280.0,-10.0);
    glEnd();

    glBegin(GL_QUADS);//kiri belakang
    glColor3ub(255, 239, 204);
    glVertex3f(-120.0,0.1,-170.0);
    glVertex3f(-90.0,0.1,-90.0);
    glVertex3f(-90.0,280.0,-90.0);
    glVertex3f(-120.0,280.0,-170.0);
    glEnd();

    glBegin(GL_QUADS);//kanan depan
    glColor3ub(255, 239, 204);
    glVertex3f(120.0,0.1,-10.0);
    glVertex3f(90.0,0.1,-90.0);
    glVertex3f(90.0,280.0,-90.0);
    glVertex3f(120.0,280.0,-10.0);
    glEnd();

    glBegin(GL_QUADS);//kanan belakang
    glColor3ub(255, 239, 204);
    glVertex3f(120.0,0.1,-170.0);
    glVertex3f(90.0,0.1,-90.0);
    glVertex3f(90.0,280.0,-90.0);
    glVertex3f(120.0,280.0,-170.0);
    glEnd();

    //KUTIL BANGUNAN BAGIAN ATAS
    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-100.0, 270.0, -9.9);
    glVertex3f(-100.0, 255.0, -9.9);
    glVertex3f(100.0, 255.0, -9.9);
    glVertex3f(100.0, 270.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-100.0, 270.0, -9.9);
    glVertex3f(-100.0, 270.0, 0.0);
    glVertex3f(100.0, 270.0, 0.0);
    glVertex3f(100.0, 270.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-100.0, 270.0, 0.0);
    glVertex3f(-100.0, 255.0, 6.0);
    glVertex3f(100.0, 255.0, 6.0);
    glVertex3f(100.0, 270.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-100.0, 255.0, -9.9);
    glVertex3f(-100.0, 255.0, 6.0);
    glVertex3f(100.0, 255.0, 6.0);
    glVertex3f(100.0, 255.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-100.0, 270.0, -9.9);
    glVertex3f(-100.0, 255.0, -9.9);
    glVertex3f(-100.0, 255.0, 6.0);
    glVertex3f(-100.0, 270.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(100.0, 270.0, -9.9);
    glVertex3f(100.0, 255.0, -9.9);
    glVertex3f(100.0, 255.0, 6.0);
    glVertex3f(100.0, 270.0, 0.0);
    glEnd();

    //KUTIL BANGUNAN BAGIAN BAWAH
    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-100.0, 230.0, -9.9);
    glVertex3f(-100.0, 215.0, -9.9);
    glVertex3f(100.0, 215.0, -9.9);
    glVertex3f(100.0, 230.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-100.0, 215.0, -9.9);
    glVertex3f(-100.0, 215.0, 0.0);
    glVertex3f(100.0, 215.0, 0.0);
    glVertex3f(100.0, 215.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-100.0, 230.0, 6.0);
    glVertex3f(-100.0, 215.0, 0.0);
    glVertex3f(100.0, 215.0, 0.0);
    glVertex3f(100.0, 230.0, 6.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-100.0, 230.0, -9.9);
    glVertex3f(-100.0, 230.0, 6.0);
    glVertex3f(100.0, 230.0, 6.0);
    glVertex3f(100.0, 230.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(-100.0, 230.0, -9.9);
    glVertex3f(-100.0, 215.0, -9.9);
    glVertex3f(-100.0, 215.0, 0.0);
    glVertex3f(-100.0, 230.0, 6.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex3f(100.0, 230.0, -9.9);
    glVertex3f(100.0, 215.0, -9.9);
    glVertex3f(100.0, 215.0, 0.0);
    glVertex3f(100.0, 230.0, 6.0);
    glEnd();

    //BANGUNAN TINGGI KURUS KIRI
    glBegin(GL_POLYGON);//depan kanan
    glColor3ub(255, 242, 230);
    glVertex3f(-132.1,0.0,10.0);
    glVertex3f(-90.0,0.0,-90.0);
    glVertex3f(-90.0,330.0,-90.0);
    glVertex3f(-132.1,330.0,10.0);
    glEnd();

    glBegin(GL_QUADS);//depan kiri
    glColor3ub(217, 217, 217);
    glVertex3f(-190.0,0.0,-28.0);
    glColor3ub(255, 242, 230);
    glVertex3f(-132.1,0.0,10.0);
    glVertex3f(-132.1,330.0,10.0);
    glColor3ub(217, 217, 217);
    glVertex3f(-190.0,330.0,-28.0);
    glEnd();

    //penangkal PETIR kiri
    glBegin(GL_QUADS);
    glColor3ub(204, 102, 0);
    glVertex3f(-175.0,310.0,-17.0);
    glVertex3f(-155.1,310.0,-5.0);
    glVertex3f(-155.1,340.0,-5.0);
    glVertex3f(-175.0,340.0,-17.0);
    glEnd();

    //penangkal PETIR kanan
    glBegin(GL_QUADS);
    glColor3ub(204, 102, 0);
    glVertex3f(175.0,310.0,-17.0);
    glVertex3f(155.1,310.0,-5.0);
    glVertex3f(155.1,340.0,-5.0);
    glVertex3f(175.0,340.0,-17.0);
    glEnd();

    glBegin(GL_QUADS);//samping kiri depan
    glColor3ub(255, 242, 230);
    glVertex3f(-190.0,0.0,-28.0);
    glVertex3f(-178.0,0.0,-90.0);
    glVertex3f(-178.0,330.0,-90.0);
    glVertex3f(-190.0,330.0,-28.0);
    glEnd();

    glBegin(GL_QUADS);//samping kiri belakang
    glColor3ub(255, 242, 230);
    glVertex3f(-190.0,0.0,-152.0);
    glVertex3f(-178.0,0.0,-90.0);
    glVertex3f(-178.0,330.0,-90.0);
    glVertex3f(-190.0,330.0,-152.0);
    glEnd();

    glBegin(GL_QUADS);//belakang kiri
    glColor3ub(255, 242, 230);
    glVertex3f(-190.0,0.0,-152.0);
    glVertex3f(-132.1,0.0,-190.0);
    glVertex3f(-132.1,330.0,-190.0);
    glVertex3f(-190.0,330.0,-152.0);
    glEnd();

    glBegin(GL_QUADS);//belakang kanan
    glColor3ub(255, 242, 230);
    glVertex3f(-132.1,0.0,-190.0);
    glVertex3f(-90.0,0.0,-90.0);
    glVertex3f(-90.0,330.0,-90.0);
    glVertex3f(-132.1,330.0,-190.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(191, 191, 191);
    glVertex3f(-178.0,0.1,-90.0);
    glVertex3f(-190.0,0.1,-28.0);
    glVertex3f(-132.1,0.1,10.0);
    glVertex3f(-90.0,0.1,-90.0);
    glVertex3f(-132.1,0.1,-190.0);
    glVertex3f(-190.0,0.1,-152.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(230, 230, 230);
    glVertex3f(-178.0,330.0,-90.0);
    glVertex3f(-190.0,330.0,-28.0);
    glVertex3f(-132.1,330.0,10.0);
    glVertex3f(-90.0,330.0,-90.0);
    glVertex3f(-132.1,330.0,-190.0);
    glVertex3f(-190.0,330.0,-152.0);
    glEnd();

    //BANGUNAN TINGGI KURUS KANAN
    glBegin(GL_QUADS);//depan kiri
    glColor3ub(255, 242, 230);
    glVertex3f(132.1,0.0,10.0);
    glVertex3f(90.0,0.0,-90.0);
    glVertex3f(90.0,330.0,-90.0);
    glVertex3f(132.1,330.0,10.0);
    glEnd();

    glBegin(GL_QUADS);//depan kanan
    glColor3ub(217, 217, 217);
    glVertex3f(190.0,0.0,-28.0);
    glColor3ub(255, 242, 230);
    glVertex3f(132.1,0.0,10.0);
    glVertex3f(132.1,330.0,10.0);
    glColor3ub(217, 217, 217);
    glVertex3f(190.0,330.0,-28.0);
    glEnd();

    glBegin(GL_QUADS);//samping kanan depan
    glColor3ub(255, 242, 230);
    glVertex3f(190.0,0.0,-28.0);
    glVertex3f(178.0,0.0,-90.0);
    glVertex3f(178.0,330.0,-90.0);
    glVertex3f(190.0,330.0,-28.0);
    glEnd();

    glBegin(GL_QUADS);//samping kanan belakang
    glColor3ub(255, 242, 230);
    glVertex3f(190.0,0.0,-152.0);
    glVertex3f(178.0,0.0,-90.0);
    glVertex3f(178.0,330.0,-90.0);
    glVertex3f(190.0,330.0,-152.0);
    glEnd();

    glBegin(GL_QUADS);//belakang kanan
    glColor3ub(255, 242, 230);
    glVertex3f(190.0,0.0,-152.0);
    glVertex3f(132.1,0.0,-190.0);
    glVertex3f(132.1,330.0,-190.0);
    glVertex3f(190.0,330.0,-152.0);
    glEnd();

    glBegin(GL_QUADS);//belakang kiri
    glColor3ub(255, 242, 230);
    glVertex3f(132.1,0.0,-190.0);
    glVertex3f(90.0,0.0,-90.0);
    glVertex3f(90.0,330.0,-90.0);
    glVertex3f(132.1,330.0,-190.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(191, 191, 191);
    glVertex3f(178.0,0.1,-90.0);
    glVertex3f(190.0,0.1,-28.0);
    glVertex3f(132.1,0.1,10.0);
    glVertex3f(90.0,0.1,-90.0);
    glVertex3f(132.1,0.1,-190.0);
    glVertex3f(190.0,0.1,-152.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(230, 230, 230);
    glVertex3f(178.0,330.0,-90.0);
    glVertex3f(190.0,330.0,-28.0);
    glVertex3f(132.1,330.0,10.0);
    glVertex3f(90.0,330.0,-90.0);
    glVertex3f(132.1,330.0,-190.0);
    glVertex3f(190.0,330.0,-152.0);
    glEnd();

    int y = 26;
    float a = 0.1;
    for (int i = 0; i<4; i++){
        glBegin(GL_LINES);
        glColor3ub(255, 255, 153);
        if (i==0){
            glVertex2f(ax,ay);
            glVertex2f(bx,by);

            glVertex2f(cx,cy);
            glVertex2f(dx,dy);

            glVertex2f(ex,ey);
            glVertex2f(fx,fy);

            glVertex2f(gx,gy);
            glVertex2f(hx,hy);
        }else{
            glVertex2f(ax+y-a,ay+y);
            glVertex2f(bx+y-a,by+y);

            glVertex2f(cx+y-a,cy+y);
            glVertex2f(dx+y-a,dy+y);

            glVertex2f(ex+y-a,ey+y);
            glVertex2f(fx+y-a,fy+y);

            glVertex2f(gx+y-a,gy+y);
            glVertex2f(hx+y-a,hy+y);
            y+=26;
            a-=0.1;
        }
        glEnd();
    }
    //Menentukan Persamaan Garis
        //AB
        m1 = (by-ay)/(bx-ax);
        c1 = ay - (m1*ax);

        //CD
        m2 = (dy-cy)/(dx-cx);
        c2 = cy - (m2*cx);

        //EF
        m3 = (fy-ey)/(fx-ex);
        c3 = ey - (m3*ex);

        //GH
        m4 = (hy-gy)/(hx-gx);
        c4 = gy - (m4*gx);

    //Menentukan Titik Potong
        px = (c2-c1)/(m1-m2);
        py = (m1*px) + c1;
            glPointSize(8);

        glBegin(GL_POINTS);
        glColor3f(0,1,0);
            glVertex2f(px,py);
        glEnd();

    subgedung_kanan();
    subgedung_kiri();
    pintu_atap();
    jendelaDANpintu_depan();
    tiang();
    rumput();
    monumen1();
    monumen2();
    aspal();
    poni();
    gerbang();
    lambangSegitiga();
    papan_nama();
    uksw();
    jendelakutil();
    sekatkaca();
    kelas();
    lobi();
    kaca_gedungTinggi();
    pintumasukUniv();
    matahari();
    pilarATASgedung();
    pilarATASgedungBELAKANG();
    glFlush();
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x-yrot;
        ydiff = -y + xrot;
    }else{
        mouseDown = false;
    }
    glutPostRedisplay();
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}
void keyboard (unsigned char key, int x, int y){
    switch (key)
    {
        //GESER KE KIRI
    case 'a':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case 'A':
        glTranslatef(-1.0, 0.0, 0.0);
        break;
        //GESER KE KANAN
    case 'd':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 'D':
        glTranslatef(2.0, 0.0, 0.0);
        break;
        //GESER KE ATAS
    case 'w':
        glTranslatef(0.0, 1.5, 0.0);
        break;
    case 'W':
        glTranslatef(0.0, 5.0f, 0.0);
        break;
        //GERAL KE BAWAH
    case 's':
        glTranslatef(0.0, -1.5f, 0.0);
        break;
    case 'S':
        glTranslatef(0.0, -5.0f, 0.0);
        break;
        //GERAK KE DEPAN
    case 'z':
        glTranslatef(0.0, 0.0, 3.0f);
        break;
    case 'Z':
        glTranslatef(0.0, 0.0, 5.5);
        break;
        //GERAK KE BELAKANG
    case 'x':
        glTranslatef(0.0, 0.0, -1.5f);
        break;
    case 'X':
        glTranslatef(0.0, 0.0, -3.5f);
        break;
        //ROTATE KE KIRI
    case '4':
        glRotatef(1.0, 0.0, -5.0, 0.0);
        break;
    case 'K':
        glRotatef(5.0, 0.0, -5.0, 0.0);
        break;
        //ROTATE KE KANAN
    case '6':
        glRotatef(1.0, 0.0, 5.0, 0.0);
        break;
    case '/':
        glRotatef(2.0, 0.0, 5.0, 0.0);
        break;

    case '5':
        if(is_depth){
            is_depth=0;
            glDisable(GL_DEPTH_TEST);
        }
        else{
            is_depth=1;
            glEnable(GL_DEPTH_TEST);
        }
        break;
    	//rotate ke samping kanan
		//case '9':
			//glRotatef(2.0, 0.0, 0.0, -5.0);
			//break;
		case '3':
			glRotatef(1.0, 0.0, 0.0, -5.0);
			break;
			//rotate ke samping kiri
		case '1':
			glRotatef(1.0, 0.0, 0.0, 5.0);
			break;
		case 'i':
			glRotatef(5.0, 0.0, 0.0, 5.0);
			break;
			//rotate ke atas
		case '8':
			glRotatef(1.0, -5.0, 0.0, 0.0);
			break;
		case 'u':
			glRotatef(5.0, -5.0, 0.0, 0.0);
			break;
			//rotate ke bawah
		case '2':
			glRotatef(1.0, 5.0, 0.0, 0.0);
			break;
		case 'l':
			glRotatef(5.0, 5.0, 0.0, 0.0);
			break;
        case 'p':
            if(pin==0)
                pin=1;
            else
                pin=0;
            break;
        case 't':
            if(tag==0)
                tag=1;
            else
                tag=0;
            break;
    }
    tampil();
}
void ukuran(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, aspect,5.0,900.0);
    glTranslatef(0.0,-100.0,-590.0);
    glMatrixMode(GL_MODELVIEW);
}
