#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran (int, int);
void mouse (int button, int state, int x, int y);
void mouseMotion(int x, int y);

float xrot = 0.0;
float yrot = 0.0;
float zrot = 0.0;
float xdiff = 0.0;
float ydiff = 0.0;
bool mouseDown = false;
int is_depth;
float x1=10.0;
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(950,650);
    glutInitWindowPosition(250,80);
    glutCreateWindow("Kelompok 4");
    init();
    glutDisplayFunc(tampil);
    glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glDepthFunc(GL_LEQUAL);
   glShadeModel(GL_SMOOTH);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}

void subgedung_kanan(){
    glBegin(GL_QUADS);
    //1
        glColor3ub(255,255,255);
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
        glVertex3f(245.0,125.0,-40.0);
        glVertex3f(245.0,0.0,-40.0);
    //5
        glVertex3f(245.0,0.0,-40.0);
        glVertex3f(245.0,125.0,-40.0);
        glVertex3f(245.0,125.0,-80.0);
        glVertex3f(245.0,0.0,-80.0);
    //6
        glVertex3f(245.0,0.0,-80.0);
        glVertex3f(245.0,125.0,-80.0);
        glVertex3f(290.0,125.0,-200.0);
        glVertex3f(290.0,0.0,-200.0);
    //7
        glVertex3f(290.0,0.0,-200.0);
        glVertex3f(290.0,125.0,-200.0);
        glVertex3f(190.0,125.0,-260.0);
        glVertex3f(190.0,0.0,-260.0);
    //8
        glVertex3f(132.0,0.0,-130.0);
        glVertex3f(132.0,125.0,-130.0);
        glVertex3f(190.0,125.0,-260.0);
        glVertex3f(190.0,0.0,-260.0);

        ///jendela

        glColor3ub(100,100,240);
            glVertex3f(140.0,120.0,25.0);
            glVertex3f(140.0,100.0,25.0);
            glVertex3f(160.0,100.0,61);
            glVertex3f(160.0,120.0,61);

            glVertex3f(170.0,120.0,79.0);
            glVertex3f(170.0,100.0,79.0);
            glVertex3f(190.0,100.0,115.6);
            glVertex3f(190.0,120.0,115.6);

            glVertex3f(200.0,120.0,133.4);
            glVertex3f(200.0,100.0,133.4);
            glVertex3f(215.0,100.0,161);
            glVertex3f(215.0,120.0,161);
            ///
            glVertex3f(140.0,80.0,25.0);
            glVertex3f(140.0,60.0,25.0);
            glVertex3f(160.0,60.0,61);
            glVertex3f(160.0,80.0,61);

            glVertex3f(170.0,80.0,79.0);
            glVertex3f(170.0,60.0,79.0);
            glVertex3f(190.0,60.0,115.6);
            glVertex3f(190.0,80.0,115.6);

            glVertex3f(200.0,80.0,133.4);
            glVertex3f(200.0,60.0,133.4);
            glVertex3f(215.0,60.0,161);
            glVertex3f(215.0,80.0,161);
            ///
            glVertex3f(140.0,40.0,25.0);
            glVertex3f(140.0,20.0,25.0);
            glVertex3f(160.0,20.0,61);
            glVertex3f(160.0,40.0,61);

            glVertex3f(170.0,40.0,79.0);
            glVertex3f(170.0,20.0,79.0);
            glVertex3f(190.0,20.0,115.6);
            glVertex3f(190.0,40.0,115.6);

            glVertex3f(200.0,40.0,133.4);
            glVertex3f(200.0,20.0,133.4);
            glVertex3f(215.0,20.0,161);
            glVertex3f(215.0,40.0,161);

        glColor3ub(240,90,30);
        glVertex3f(132.0,150.0,10.0);
        glVertex3f(132.0,165.0,10.0);
        glVertex3f(220.0,165.0,170);
        glVertex3f(220.0,150.0,170);

        glVertex3f(220.0,165.0,170);
        glVertex3f(220.0,150.0,170);
        glVertex3f(270.0,150.0,130.0);
        glVertex3f(270.0,165.0,130.0);

        glVertex3f(132.0,0.0,10.0);
        glVertex3f(132.0,20.0,10.0);
        glVertex3f(220.0,20.0,170);
        glVertex3f(220.0,0.0,170);

        ///atap
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
        glVertex3f(245.0,125.0,-40.0);
        glVertex3f(190.0,125.0,-28.0);

        glVertex3f(245.0,125.0,-40.0);
        glVertex3f(245.0,125.0,-60.0);
        glVertex3f(178.0,125.0,-60.0);
        glVertex3f(190.0,125.0,-28.0);

        glVertex3f(245.0,125.0,-60.0);
        glVertex3f(245.0,125.0,-80.0);
        glVertex3f(190.0,125.0,-92.0);
        glVertex3f(178.0,125.0,-60.0);

        glVertex3f(245.0,125.0,-60.0);
        glVertex3f(245.0,125.0,-80.0);
        glVertex3f(190.0,125.0,-92.0);
        glVertex3f(132.1,125.0,-130.0);

        glVertex3f(245.0,125.0,-60.0);
        glVertex3f(290.0,125.0,-200.0);
        glVertex3f(190.0,125.0,-260.0);
        glVertex3f(132.0,125.0,-130.0);

    glEnd();
}
void subgedung_kiri(){
    glBegin(GL_QUADS);
    //1
        //1
        glColor3ub(255,255,255);
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
        glVertex3f(-245.0,125.0,-40.0);
        glVertex3f(-245.0,0.0,-40.0);
    //5
        glVertex3f(-245.0,0.0,-40.0);
        glVertex3f(-245.0,125.0,-40.0);
        glVertex3f(-245.0,125.0,-80.0);
        glVertex3f(-245.0,0.0,-80.0);
    //6
        glVertex3f(-245.0,0.0,-80.0);
        glVertex3f(-245.0,125.0,-80.0);
        glVertex3f(-290.0,125.0,-200.0);
        glVertex3f(-290.0,0.0,-200.0);
    //7
        glVertex3f(-290.0,0.0,-200.0);
        glVertex3f(-290.0,125.0,-200.0);
        glVertex3f(-240.0,125.0,-230.0);
        glVertex3f(-240.0,0.0,-230.0);

    //7.5
        glVertex3f(-240.0,0.0,-230.0);
        glVertex3f(-240.0,165.0,-230.0);
        glVertex3f(-190.0,165.0,-260.0);
        glVertex3f(-190.0,0.0,-260.0);
    //8
        glVertex3f(-132.0,0.0,-130.0);
        glVertex3f(-132.0,165.0,-130.0);
        glVertex3f(-190.0,165.0,-260.0);
        glVertex3f(-190.0,0.0,-260.0);

        ///jendela

        glColor3ub(100,100,240);
            glVertex3f(-140.0,120.0,25.0);
            glVertex3f(-140.0,100.0,25.0);
            glVertex3f(-160.0,100.0,61);
            glVertex3f(-160.0,120.0,61);

            glVertex3f(-170.0,120.0,79.0);
            glVertex3f(-170.0,100.0,79.0);
            glVertex3f(-190.0,100.0,115.6);
            glVertex3f(-190.0,120.0,115.6);

            glVertex3f(-200.0,120.0,133.4);
            glVertex3f(-200.0,100.0,133.4);
            glVertex3f(-215.0,100.0,161);
            glVertex3f(-215.0,120.0,161);
            ///
            glVertex3f(-140.0,80.0,25.0);
            glVertex3f(-140.0,60.0,25.0);
            glVertex3f(-160.0,60.0,61);
            glVertex3f(-160.0,80.0,61);

            glVertex3f(-170.0,80.0,79.0);
            glVertex3f(-170.0,60.0,79.0);
            glVertex3f(-190.0,60.0,115.6);
            glVertex3f(-190.0,80.0,115.6);

            glVertex3f(-200.0,80.0,133.4);
            glVertex3f(-200.0,60.0,133.4);
            glVertex3f(-215.0,60.0,161);
            glVertex3f(-215.0,80.0,161);
            ///
            glVertex3f(-140.0,40.0,25.0);
            glVertex3f(-140.0,0.0,25.0);
            glVertex3f(-160.0,0.0,61);
            glVertex3f(-160.0,40.0,61);

            glVertex3f(-170.0,40.0,79.0);
            glVertex3f(-170.0,0.0,79.0);
            glVertex3f(-190.0,0.0,115.6);
            glVertex3f(-190.0,40.0,115.6);

            glVertex3f(-200.0,40.0,133.4);
            glVertex3f(-200.0,0.0,133.4);
            glVertex3f(-215.0,0.0,161);
            glVertex3f(-215.0,40.0,161);

        glColor3ub(240,90,30);
        glVertex3f(-132.0,150.0,10.0);
        glVertex3f(-132.0,165.0,10.0);
        glVertex3f(-220.0,165.0,170);
        glVertex3f(-220.0,150.0,170);

        glVertex3f(-220.0,165.0,170);
        glVertex3f(-220.0,150.0,170);
        glVertex3f(-270.0,150.0,130.0);
        glVertex3f(-270.0,165.0,130.0);

        ///atap
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
        glVertex3f(-245.0,125.0,-40.0);
        glVertex3f(-190.0,125.0,-28.0);

        glVertex3f(-245.0,125.0,-40.0);
        glVertex3f(-245.0,125.0,-60.0);
        glVertex3f(-178.0,125.0,-60.0);
        glVertex3f(-190.0,125.0,-28.0);

        glVertex3f(-245.0,125.0,-60.0);
        glVertex3f(-245.0,125.0,-80.0);
        glVertex3f(-190.0,125.0,-92.0);
        glVertex3f(-178.0,125.0,-60.0);

        glVertex3f(-245.0,125.0,-60.0);
        glVertex3f(-245.0,125.0,-80.0);
        glVertex3f(-190.0,125.0,-92.0);
        glVertex3f(-132.1,125.0,-130.0);

        glVertex3f(-132.0,165.0,-130.0);
        glVertex3f(-190.0,165.0,-92.0);
        glVertex3f(-240.0,165.0,-230.0);
        glVertex3f(-190.0,165.0,-260.0);

        glVertex3f(-245.0,125.0,-80.0);
        glVertex3f(-290.0,125.0,-200.0);
        glVertex3f(-240.0,125.0,-230.0);
        glVertex3f(-190.0,125.0,-92.0);

        glVertex3f(-240.0,165.0,-230.0);
        glVertex3f(-190.0,165.0,-92.0);
        glVertex3f(-190.0,125.0,-92.0);
        glVertex3f(-240.0,125.0,-230.0);

    glEnd();
}

void jendela_depan(){
    glBegin(GL_QUADS);//depan
    ///jendela
    glColor3ub(100, 100, 230);
    glVertex3f(-90.0,200.0,-10.0);
    glVertex3f(-110.0,200.0,-10.0);
    glVertex3f(-110.0,180.0,-10.0);
    glVertex3f(-90.0,180.0,-10.0);

        glVertex3f(-80.0,180.0,-10.0);
        glVertex3f(-40.0,180.0,-10.0);
        glVertex3f(-40.0,200.0,-10.0);
        glVertex3f(-80.0,200.0,-10.0);

        glVertex3f(-20.0,180.0,-10.0);
        glVertex3f(20.0,180.0,-10.0);
        glVertex3f(20.0,200.0,-10.0);
        glVertex3f(-20.0,200.0,-10.0);

        glVertex3f(40.0,180.0,-10.0);
        glVertex3f(80.0,180.0,-10.0);
        glVertex3f(80.0,200.0,-10.0);
        glVertex3f(40.0,200.0,-10.0);

        glVertex3f(90.0,180.0,-10.0);
        glVertex3f(110.0,180.0,-10.0);
        glVertex3f(110.0,200.0,-10.0);
        glVertex3f(90.0,200.0,-10.0);

    glVertex3f(-90.0,140.0,-10.0);
    glVertex3f(-110.0,140.0,-10.0);
    glVertex3f(-110.0,160.0,-10.0);
    glVertex3f(-90.0,160.0,-10.0);

        glVertex3f(-80.0,140.0,-10.0);
        glVertex3f(-40.0,140.0,-10.0);
        glVertex3f(-40.0,160.0,-10.0);
        glVertex3f(-80.0,160.0,-10.0);

        glVertex3f(-20.0,140.0,-10.0);
        glVertex3f(20.0,140.0,-10.0);
        glVertex3f(20.0,160.0,-10.0);
        glVertex3f(-20.0,160.0,-10.0);

        glVertex3f(40.0,140.0,-10.0);
        glVertex3f(80.0,140.0,-10.0);
        glVertex3f(80.0,160.0,-10.0);
        glVertex3f(40.0,160.0,-10.0);

        glVertex3f(90.0,140.0,-10.0);
        glVertex3f(110.0,140.0,-10.0);
        glVertex3f(110.0,160.0,-10.0);
        glVertex3f(90.0,160.0,-10.0);

    glVertex3f(-90.0,120.0,-10.0);
    glVertex3f(-110.0,120.0,-10.0);
    glVertex3f(-110.0,100.0,-10.0);
    glVertex3f(-90.0,100.0,-10.0);

        glVertex3f(-80.0,100.0,-10.0);
        glVertex3f(-40.0,100.0,-10.0);
        glVertex3f(-40.0,120.0,-10.0);
        glVertex3f(-80.0,120.0,-10.0);

        glVertex3f(-20.0,100.0,-10.0);
        glVertex3f(20.0,100.0,-10.0);
        glVertex3f(20.0,120.0,-10.0);
        glVertex3f(-20.0,120.0,-10.0);

        glVertex3f(40.0,100.0,-10.0);
        glVertex3f(80.0,100.0,-10.0);
        glVertex3f(80.0,120.0,-10.0);
        glVertex3f(40.0,120.0,-10.0);

        glVertex3f(90.0,100.0,-10.0);
        glVertex3f(110.0,100.0,-10.0);
        glVertex3f(110.0,120.0,-10.0);
        glVertex3f(90.0,120.0,-10.0);

    glVertex3f(-80.0,0.0,-10.0);
    glVertex3f(80.0,0.0,-10.0);
    glVertex3f(80.0,80.0,-10.0);
    glVertex3f(-80.0,80.0,-10.0);

    ///tembok
    glColor3ub(255, 247, 230);
    glVertex3f(-120.0,200.0,-10.0);
    glVertex3f(120.0,200.0,-10.0);
    glVertex3f(120.0,280.0,-10.0);
    glVertex3f(-120.0,280.0,-10.0);

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
    glVertex3f(120.0,80.0,-10.0);
    glVertex3f(-120.0,80.0,-10.0);

    glVertex3f(-40.0,280.0,-10.0);
    glVertex3f(-20.0,280.0,-10.0);
    glVertex3f(-20.0,80.0,-10.0);
    glVertex3f(-40.0,80.0,-10.0);

    glVertex3f(40.0,280.0,-10.0);
    glVertex3f(20.0,280.0,-10.0);
    glVertex3f(20.0,80.0,-10.0);
    glVertex3f(40.0,80.0,-10.0);

    //kiri
    glVertex3f(-80.0,280.0,-10.0);
    glVertex3f(-90.0,280.0,-10.0);
    glVertex3f(-90.0,80.0,-10.0);
    glVertex3f(-80.0,80.0,-10.0);

    glVertex3f(-110.0,280.0,-10.0);
    glVertex3f(-120.0,280.0,-10.0);
    glVertex3f(-120.0,80.0,-10.0);
    glVertex3f(-110.0,80.0,-10.0);

    glVertex3f(-80.0,0.0,-10.0);
    glVertex3f(-132.0,0.0,-10.0);
    glVertex3f(-132.0,80.0,-10.0);
    glVertex3f(-80.0,80.0,-10.0);

    //kanan
    glVertex3f(80.0,280.0,-10.0);
    glVertex3f(90.0,280.0,-10.0);
    glVertex3f(90.0,80.0,-10.0);
    glVertex3f(80.0,80.0,-10.0);

    glVertex3f(110.0,280.0,-10.0);
    glVertex3f(120.0,280.0,-10.0);
    glVertex3f(120.0,80.0,-10.0);
    glVertex3f(110.0,80.0,-10.0);

    glVertex3f(80.0,0.0,-10.0);
    glVertex3f(132.0,0.0,-10.0);
    glVertex3f(132.0,80.0,-10.0);
    glVertex3f(80.0,80.0,-10.0);

    glEnd();
}


void lambangSegitiga(){
    //Belakang Kiri
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
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
    glColor3ub(255, 255, 153);
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
    glColor3ub(255, 255, 153);
    glVertex3f(-50.0, 47.0, 5.0+x1);
    glVertex3f(-35.0, 47.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0+x1);
    glEnd();

    //Belakang Kanan
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 153);
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
    glColor3ub(255, 255, 153);
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
    glColor3ub(255, 255, 153);
    glVertex3f(50.0, 47.0, 5.0+x1);
    glVertex3f(35.0, 47.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0+x1);
    glEnd();
}
void papan_nama(void){
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
void uksw(void){
    glBegin(GL_LINES);//huruf U
    glColor3ub(255, 215, 0);
    glVertex3f(-17.0, 69.0, 15.1);
    glVertex3f(-17.0, 57.0, 15.1);
    glVertex3f(-17.0, 57.0, 15.1);
    glVertex3f(-11.0, 57.0, 15.1);
    glVertex3f(-11.0, 57.0, 15.1);
    glVertex3f(-11.0, 69.0, 15.1);
    glEnd();

    glBegin(GL_LINES);//huruf K
    glColor3ub(255, 215, 0);
    glVertex3f(-7.0, 69.0, 15.1);
    glVertex3f(-7.0, 57.0, 15.1);
    glVertex3f(-7.0, 63.0, 15.1);
    glVertex3f(-1.0, 69.0, 15.1);
    glVertex3f(-7.0, 63.0, 15.1);
    glVertex3f(-1.0, 57.0, 15.1);
    glEnd();

    glBegin(GL_LINES);//huruf S
    glColor3ub(255, 215, 0);
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
    glColor3ub(255, 215, 0);
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
void poni(void){
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
    glColor3ub(230, 230, 230);
    glVertex3f(-117.0,70.0,25.0);
    glVertex3f(-105.0,70.0,5.0);
    glVertex3f(-120.0,70.0,-9.9);
    glVertex3f(-132.0,70.0,10.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(230, 230, 230);
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
    glColor3ub(230, 230, 230);
    glVertex3f(-105.0,70.0,5.0);
    glVertex3f(105.0,70.0,5.0);
    glVertex3f(120.0,70.0,-9.9);
    glVertex3f(-120.0,70.0,-9.9);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(230, 230, 230);
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
    glColor3ub(230, 230, 230);
    glVertex3f(117.0,70.0,25.0);
    glVertex3f(105.0,70.0,5.0);
    glVertex3f(120.0,70.0,-9.9);
    glVertex3f(132.0,70.0,10.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(230, 230, 230);
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
void aspal(void){
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
void rumput(void){
    //rumput segi 6 belum, ini bagian terakhir
}
void gerbang(){
    //Sebelah kiri
    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(-70.0, 0.0, 400.0);
    glVertex3f(-45.0, 0.0, 400.0);
    glVertex3f(-45.0, 36.5, 400.0);
    glVertex3f(-70.0, 15.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(-70.0, 0.0, 420.0);
    glVertex3f(-45.0, 0.0, 420.0);
    glVertex3f(-45.0, 36.5, 420.0);
    glVertex3f(-70.0, 15.0, 420.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(-70.0, 0.0, 420.0);
    glVertex3f(-70.0, 30.0, 420.0);
    glVertex3f(-70.0, 30.0, 400.0);
    glVertex3f(-70.0, 0.0, 400.0);
    glEnd();
    //Sebelah kiri
    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(-45.0, 0.0, 420.0);
    glVertex3f(-45.0, 36.5, 420.0);
    glVertex3f(-45.0, 36.5, 400.0);
    glVertex3f(-45.0, 0.0, 400.0);
    glEnd();

    //Gerbang Segitiga kiri
    glBegin(GL_POLYGON);//belakang
    glColor3ub(153, 102, 51);
    glVertex3f(-70.0, 15.0, 400.0);
    glVertex3f(0.0, 75.0, 400.0);
    glVertex3f(0.0, 90.0, 400.0);
    glVertex3f(-70.0, 30.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);//depan
    glColor3ub(153, 102, 51);
    glVertex3f(-70.0, 15.0, 420.0);
    glVertex3f(0.0, 75.0, 420.0);
    glVertex3f(0.0, 90.0, 420.0);
    glVertex3f(-70.0, 30.0, 420.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(153, 102, 51);
    glVertex3f(-70.0, 30.0, 420.0);
    glVertex3f(0.0, 90.0, 420.0);
    glVertex3f(0.0, 90.0, 400.0);
    glVertex3f(-70.0, 30.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(153, 102, 51);
    glVertex3f(-45.0, 36.5, 420.0);
    glVertex3f(0.0, 75.0, 420.0);
    glVertex3f(0.0, 75.0, 400.0);
    glVertex3f(-45.0, 36.5, 400.0);
    glEnd();

    //Gerbang Segitiga Kanan
    glBegin(GL_POLYGON);//belakang
    glColor3ub(153, 102, 51);
    glVertex3f(70.0, 15.0, 400.0);
    glVertex3f(0.0, 75.0, 400.0);
    glVertex3f(0.0, 90.0, 400.0);
    glVertex3f(70.0, 30.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);//depan
    glColor3ub(153, 102, 51);
    glVertex3f(70.0, 15.0, 420.0);
    glVertex3f(0.0, 75.0, 420.0);
    glVertex3f(0.0, 90.0, 420.0);
    glVertex3f(70.0, 30.0, 420.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(153, 102, 51);
    glVertex3f(70.0, 30.0, 420.0);
    glVertex3f(0.0, 90.0, 420.0);
    glVertex3f(0.0, 90.0, 400.0);
    glVertex3f(70.0, 30.0, 400.0);
    glEnd();

     glBegin(GL_POLYGON);//bawah
    glColor3ub(153, 102, 51);
    glVertex3f(45.0, 36.5, 420.0);
    glVertex3f(0.0, 75.0, 420.0);
    glVertex3f(0.0, 75.0, 400.0);
    glVertex3f(45.0, 36.5, 400.0);
    glEnd();

    //Sebelah kanan
    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(70.0, 0.0, 400.0);
    glVertex3f(45.0, 0.0, 400.0);
    glVertex3f(45.0, 36.5, 400.0);
    glVertex3f(70.0, 15.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(70.0, 0.0, 420.0);
    glVertex3f(45.0, 0.0, 420.0);
    glVertex3f(45.0, 36.5, 420.0);
    glVertex3f(70.0, 15.0, 420.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(70.0, 0.0, 420.0);
    glVertex3f(70.0, 30.0, 420.0);
    glVertex3f(70.0, 30.0, 400.0);
    glVertex3f(70.0, 0.0, 400.0);
    glEnd();
    //Sebelah Kanan
    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(45.0, 0.0, 420.0);
    glVertex3f(45.0, 36.5, 420.0);
    glVertex3f(45.0, 36.5, 400.0);
    glVertex3f(45.0, 0.0, 400.0);
    glEnd();

    //palang atas gerbang
    glBegin(GL_POLYGON);//belakang
    glColor3ub(255, 217, 179);
    glVertex3f(-40.0, 65.0, 399.9);
    glVertex3f(0.0, 62.0, 399.9);
    glVertex3f(40.0, 65.0, 399.9);
    glVertex3f(35.0, 75.0, 399.9);
    glVertex3f(17.0, 68.0, 399.9);
    glVertex3f(-35.0, 75.0, 399.9);
    glEnd();

    glBegin(GL_POLYGON);//depan
    glColor3ub(255, 217, 179);
    glVertex3f(-40.0, 65.0, 420.1);
    glVertex3f(0.0, 62.0, 420.1);
    glVertex3f(40.0, 65.0, 420.1);
    glVertex3f(35.0, 75.0, 420.1);
    glVertex3f(17.0, 68.0, 420.1);
    glVertex3f(-35.0, 75.0, 420.1);
    glEnd();

    glBegin(GL_POLYGON);//atas kiri
    glColor3ub(255, 217, 179);
    glVertex3f(-35.0, 75.0, 420.1);
    glVertex3f(0.0, 70.0, 420.1);
    glVertex3f(0.0, 70.0, 399.9);
    glVertex3f(-35.0, 75.0, 399.9);
    glEnd();

    glBegin(GL_POLYGON);//atas kanan
    glColor3ub(255, 217, 179);
    glVertex3f(35.0, 75.0, 420.1);
    glVertex3f(0.0, 70.0, 420.1);
    glVertex3f(0.0, 70.0, 399.9);
    glVertex3f(35.0, 75.0, 399.9);
    glEnd();

    glBegin(GL_POLYGON);//bawah kiri
    glColor3ub(255, 217, 179);
    glVertex3f(-40.0, 65.0, 420.1);
    glVertex3f(0.0, 62.0, 420.1);
    glVertex3f(0.0, 62.0, 399.9);
    glVertex3f(-40.0, 65.0, 399.9);
    glEnd();

    glBegin(GL_POLYGON);//bawah kanan
    glColor3ub(255, 217, 179);
    glVertex3f(40.0, 65.0, 420.1);
    glVertex3f(0.0, 62.0, 420.1);
    glVertex3f(0.0, 62.0, 399.9);
    glVertex3f(40.0, 65.0, 399.9);
    glEnd();

    glBegin(GL_POLYGON);//tutup kiri
    glColor3ub(255, 217, 179);
    glVertex3f(-40.0, 65.0, 420.1);
    glVertex3f(-40.0, 65.0, 399.9);
    glVertex3f(-35.0, 75.0, 399.9);
    glVertex3f(-35.0, 75.0, 420.1);
    glEnd();

    glBegin(GL_POLYGON);//tutup kanan
    glColor3ub(255, 217, 179);
    glVertex3f(40.0, 65.0, 420.1);
    glVertex3f(40.0, 65.0, 399.9);
    glVertex3f(35.0, 75.0, 399.9);
    glVertex3f(35.0, 75.0, 420.1);
    glEnd();

    //palang kiri
    glBegin(GL_QUADS);//depan
    glColor3ub(255, 255, 0);
    glVertex3f(-40.0, 0.0, 420.0);
    glVertex3f(-35.0, 0.0, 420.0);
    glVertex3f(-35.0, 16.0, 420.0);
    glVertex3f(-40.0, 16.0, 420.0);
    glEnd();

    glBegin(GL_QUADS);//belakang
    glColor3ub(255, 255, 0);
    glVertex3f(-40.0, 0.0, 418.0);
    glVertex3f(-35.0, 0.0, 418.0);
    glVertex3f(-35.0, 16.0, 418.0);
    glVertex3f(-40.0, 16.0, 418.0);
    glEnd();

    glBegin(GL_QUADS);//atas
    glColor3ub(255, 255, 0);
    glVertex3f(-40.0, 16.0, 420.0);
    glVertex3f(-35.0, 16.0, 420.0);
    glVertex3f(-35.0, 16.0, 418.0);
    glVertex3f(-40.0, 16.0, 418.0);
    glEnd();

    glBegin(GL_QUADS);//bawah
    glColor3ub(255, 255, 0);
    glVertex3f(-40.0, 0.0, 420.0);
    glVertex3f(-35.0, 0.0, 420.0);
    glVertex3f(-35.0, 0.0, 418.0);
    glVertex3f(-40.0, 0.0, 418.0);
    glEnd();

    glBegin(GL_QUADS);//kiri
    glColor3ub(255, 255, 0);
    glVertex3f(-40.0, 0.0, 420.0);
    glVertex3f(-40.0, 0.0, 418.0);
    glVertex3f(-40.0, 16.0, 418.0);
    glVertex3f(-40.0, 16.0, 420.0);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3ub(255, 255, 0);
    glVertex3f(-35.0, 0.0, 420.0);
    glVertex3f(-35.0, 0.0, 418.0);
    glVertex3f(-35.0, 16.0, 418.0);
    glVertex3f(-35.0, 16.0, 420.0);
    glEnd();

    //palang kanan
    glBegin(GL_QUADS);//depan
    glColor3ub(255, 255, 0);
    glVertex3f(40.0, 0.0, 420.0);
    glVertex3f(35.0, 0.0, 420.0);
    glVertex3f(35.0, 16.0, 420.0);
    glVertex3f(40.0, 16.0, 420.0);
    glEnd();

    glBegin(GL_QUADS);//belakang
    glColor3ub(255, 255, 0);
    glVertex3f(40.0, 0.0, 418.0);
    glVertex3f(35.0, 0.0, 418.0);
    glVertex3f(35.0, 16.0, 418.0);
    glVertex3f(40.0, 16.0, 418.0);
    glEnd();

    glBegin(GL_QUADS);//atas
    glColor3ub(255, 255, 0);
    glVertex3f(40.0, 16.0, 420.0);
    glVertex3f(35.0, 16.0, 420.0);
    glVertex3f(35.0, 16.0, 418.0);
    glVertex3f(40.0, 16.0, 418.0);
    glEnd();

    glBegin(GL_QUADS);//bawah
    glColor3ub(255, 255, 0);
    glVertex3f(40.0, 0.0, 420.0);
    glVertex3f(35.0, 0.0, 420.0);
    glVertex3f(35.0, 0.0, 418.0);
    glVertex3f(40.0, 0.0, 418.0);
    glEnd();

    glBegin(GL_QUADS);//kiri
    glColor3ub(255, 255, 0);
    glVertex3f(40.0, 0.0, 420.0);
    glVertex3f(40.0, 0.0, 418.0);
    glVertex3f(40.0, 16.0, 418.0);
    glVertex3f(40.0, 16.0, 420.0);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3ub(255, 255, 0);
    glVertex3f(35.0, 0.0, 420.0);
    glVertex3f(35.0, 0.0, 418.0);
    glVertex3f(35.0, 16.0, 418.0);
    glVertex3f(35.0, 16.0, 420.0);
    glEnd();

    //palang tengah kiri
    glBegin(GL_QUADS);//depan
    glColor3ub(255, 204, 153);
    glVertex3f(-35.1, 12.0, 419.5);
    glVertex3f(-2.0, 12.0, 419.5);
    glVertex3f(-2.0, 15.0, 419.5);
    glVertex3f(-35.1, 15.0, 419.5);
    glEnd();

    glBegin(GL_QUADS);//belakang
    glColor3ub(255, 204, 153);
    glVertex3f(-35.1, 12.0, 418.5);
    glVertex3f(-2.0, 12.0, 418.5);
    glVertex3f(-2.0, 15.0, 418.5);
    glVertex3f(-35.1, 15.0, 418.5);
    glEnd();

    glBegin(GL_QUADS);//atas
    glColor3ub(255, 204, 153);
    glVertex3f(-35.1, 15.0, 419.5);
    glVertex3f(-2.0, 15.0, 419.5);
    glVertex3f(-2.0, 15.0, 418.5);
    glVertex3f(-35.1, 15.0, 418.5);
    glEnd();

    glBegin(GL_QUADS);//atas
    glColor3ub(255, 204, 153);
    glVertex3f(-35.1, 12.0, 419.5);
    glVertex3f(-2.0, 12.0, 419.5);
    glVertex3f(-2.0, 12.0, 418.5);
    glVertex3f(-35.1, 12.0, 418.5);
    glEnd();

    glBegin(GL_QUADS);//kiri
    glColor3ub(255, 204, 153);
    glVertex3f(-35.1, 12.0, 419.5);
    glVertex3f(-35.1, 12.0, 418.5);
    glVertex3f(-35.1, 15.0, 418.5);
    glVertex3f(-35.1, 15.0, 419.5);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3ub(255, 204, 153);
    glVertex3f(-2.0, 12.0, 419.5);
    glVertex3f(-2.0, 12.0, 418.5);
    glVertex3f(-2.0, 15.0, 418.5);
    glVertex3f(-2.0, 15.0, 419.5);
    glEnd();

    //palang tengah kanan
    glBegin(GL_QUADS);//depan
    glColor3ub(255, 204, 153);
    glVertex3f(35.1, 12.0, 419.5);
    glVertex3f(2.0, 12.0, 419.5);
    glVertex3f(2.0, 15.0, 419.5);
    glVertex3f(35.1, 15.0, 419.5);
    glEnd();

    glBegin(GL_QUADS);//belakang
    glColor3ub(255, 204, 153);
    glVertex3f(35.1, 12.0, 418.5);
    glVertex3f(2.0, 12.0, 418.5);
    glVertex3f(2.0, 15.0, 418.5);
    glVertex3f(35.1, 15.0, 418.5);
    glEnd();

    glBegin(GL_QUADS);//atas
    glColor3ub(255, 204, 153);
    glVertex3f(35.1, 15.0, 419.5);
    glVertex3f(2.0, 15.0, 419.5);
    glVertex3f(2.0, 15.0, 418.5);
    glVertex3f(35.1, 15.0, 418.5);
    glEnd();

    glBegin(GL_QUADS);//atas
    glColor3ub(255, 204, 153);
    glVertex3f(35.1, 12.0, 419.5);
    glVertex3f(2.0, 12.0, 419.5);
    glVertex3f(2.0, 12.0, 418.5);
    glVertex3f(35.1, 12.0, 418.5);
    glEnd();

    glBegin(GL_QUADS);//kiri
    glColor3ub(255, 204, 153);
    glVertex3f(35.1, 12.0, 419.5);
    glVertex3f(35.1, 12.0, 418.5);
    glVertex3f(35.1, 15.0, 418.5);
    glVertex3f(35.1, 15.0, 419.5);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3ub(255, 204, 153);
    glVertex3f(2.0, 12.0, 419.5);
    glVertex3f(2.0, 12.0, 418.5);
    glVertex3f(2.0, 15.0, 418.5);
    glVertex3f(2.0, 15.0, 419.5);
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
void coba(){
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(xrot,1,0,0);
	glRotatef(yrot,0,1,0);
}
void jendelakutil(){
    int y = 30;
    float a = 0.1;
    for (int i = 0; i<7; i++){
        glBegin(GL_QUADS);
        glColor3ub(0,255,255);
        if (i==0){
           glVertex3f(-100.0, 255.0, 6.0);
           glVertex3f(-100.0, 230.0, 6.0);
           glVertex3f(-80.0, 230.0, 6.0);
           glVertex3f(-80.0, 255.0, 6.0);
        }else{
           glVertex3f(-100.0+y-a, 255.0, 6.0);
           glVertex3f(-100.0+y-a, 230.0, 6.0);
           glVertex3f(-80.0+y-a, 230.0, 6.0);
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
        glColor3ub(128,128,128);
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
    glColor3ub(128,128,128);
    glVertex3f(-100.0, 255.0, -9.9);
    glVertex3f(-100.0, 230.0, -9.9);
    glVertex3f(-100.0, 230.0, 6.0);
    glVertex3f(-100.0, 255.0, 6.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(128,128,128);
    glVertex3f(100.0, 255.0, -9.9);
    glVertex3f(100.0, 230.0, -9.9);
    glVertex3f(100.0, 230.0, 6.0);
    glVertex3f(100.0, 255.0, 6.0);
    glEnd();
}
void tampil(void){

    glPushMatrix();
    coba();
    glScalef(1.5, 1.5, 1.0);

    //bangunan besar tengah
//    glBegin(GL_QUADS);//depan
//    glColor3ub(255, 247, 230);
//    glVertex3f(-120.0,0.0,-10.0);
//    glVertex3f(120.0,0.0,-10.0);
//    glVertex3f(120.0,280.0,-10.0);
//    glVertex3f(-120.0,280.0,-10.0);
//    glEnd();

    //KUTIL BANGUNAN BAGIAN ATAS
    glBegin(GL_POLYGON);
    glColor3ub(255, 128,0);
    glVertex3f(-100.0, 270.0, -9.9);
    glVertex3f(-100.0, 255.0, -9.9);
    glVertex3f(100.0, 255.0, -9.9);
    glVertex3f(100.0, 270.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 128,0);
    glVertex3f(-100.0, 270.0, -9.9);
    glVertex3f(-100.0, 270.0, 0.0);
    glVertex3f(100.0, 270.0, 0.0);
    glVertex3f(100.0, 270.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
    glVertex3f(-100.0, 270.0, 0.0);
    glVertex3f(-100.0, 255.0, 6.0);
    glVertex3f(100.0, 255.0, 6.0);
    glVertex3f(100.0, 270.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-100.0, 255.0, -9.9);
    glVertex3f(-100.0, 255.0, 6.0);
    glVertex3f(100.0, 255.0, 6.0);
    glVertex3f(100.0, 255.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex3f(-100.0, 270.0, -9.9);
    glVertex3f(-100.0, 255.0, -9.9);
    glVertex3f(-100.0, 255.0, 6.0);
    glVertex3f(-100.0, 270.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex3f(100.0, 270.0, -9.9);
    glVertex3f(100.0, 255.0, -9.9);
    glVertex3f(100.0, 255.0, 6.0);
    glVertex3f(100.0, 270.0, 0.0);
    glEnd();

    //KUTIL BANGUNAN BAGIAN BAWAH
    glBegin(GL_POLYGON);
    glColor3ub(255, 128,0);
    glVertex3f(-100.0, 230.0, -9.9);
    glVertex3f(-100.0, 215.0, -9.9);
    glVertex3f(100.0, 215.0, -9.9);
    glVertex3f(100.0, 230.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 128,0);
    glVertex3f(-100.0, 215.0, -9.9);
    glVertex3f(-100.0, 215.0, 0.0);
    glVertex3f(100.0, 215.0, 0.0);
    glVertex3f(100.0, 215.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
    glVertex3f(-100.0, 230.0, 6.0);
    glVertex3f(-100.0, 215.0, 0.0);
    glVertex3f(100.0, 215.0, 0.0);
    glVertex3f(100.0, 230.0, 6.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,0,150);
    glVertex3f(-100.0, 230.0, -9.9);
    glVertex3f(-100.0, 230.0, 6.0);
    glVertex3f(100.0, 230.0, 6.0);
    glVertex3f(100.0, 230.0, -9.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex3f(-100.0, 230.0, -9.9);
    glVertex3f(-100.0, 215.0, -9.9);
    glVertex3f(-100.0, 215.0, 0.0);
    glVertex3f(-100.0, 230.0, 6.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex3f(100.0, 230.0, -9.9);
    glVertex3f(100.0, 215.0, -9.9);
    glVertex3f(100.0, 215.0, 0.0);
    glVertex3f(100.0, 230.0, 6.0);
    glEnd();

    glBegin(GL_QUADS);//belakang
    glColor3ub(255, 247, 230);
    glVertex3f(-120.0,0.0,-110.0);
    glVertex3f(120.0,0.0,-110.0);
    glVertex3f(120.0,280.0,-110.0);
    glVertex3f(-120.0,280.0,-110.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(128, 128, 128);
    glVertex3f(-90.0,50.0,-60.0);
    glVertex3f(-120.0,50.0,-10.0);
    glVertex3f(120.0,50.0,-10.0);
    glVertex3f(90.0,50.0,-60.0);
    glVertex3f(120.0,50.0,-110.0);
    glVertex3f(-120.0,50.0,-110.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(255, 247, 230);
    glVertex3f(-90.0,280.0,-60.0);
    glVertex3f(-120.0,280.0,-10.0);
    glVertex3f(120.0,280.0,-10.0);
    glVertex3f(90.0,280.0,-60.0);
    glVertex3f(120.0,280.0,-110.0);
    glVertex3f(-120.0,280.0,-110.0);
    glEnd();

    glBegin(GL_QUADS);//kiri depan
    glColor3ub(255, 239, 204);
    glVertex3f(-120.0,50.0,-10.0);
    glVertex3f(-90.0,50.0,-60.0);
    glVertex3f(-90.0,280.0,-60.0);
    glVertex3f(-120.0,280.0,-10.0);
    glEnd();

    glBegin(GL_QUADS);//kiri belakang
    glColor3ub(255, 239, 204);
    glVertex3f(-120.0,50.0,-110.0);
    glVertex3f(-90.0,50.0,-60.0);
    glVertex3f(-90.0,280.0,-60.0);
    glVertex3f(-120.0,280.0,-110.0);
    glEnd();

    glBegin(GL_QUADS);//kanan depan
    glColor3ub(255, 239, 204);
    glVertex3f(120.0,50.0,-10.0);
    glVertex3f(90.0,50.0,-60.0);
    glVertex3f(90.0,280.0,-60.0);
    glVertex3f(120.0,280.0,-10.0);
    glEnd();

    glBegin(GL_QUADS);//kanan belakang
    glColor3ub(255, 239, 204);
    glVertex3f(120.0,50.0,-110.0);
    glVertex3f(90.0,50.0,-60.0);
    glVertex3f(90.0,280.0,-60.0);
    glVertex3f(120.0,280.0,-110.0);
    glEnd();

    //BANGUNAN TINGGI KURUS KIRI
    glBegin(GL_POLYGON);//depan kanan
    glColor3ub(255, 255, 255);
    glVertex3f(-132.1,0.0,10.0);
    glVertex3f(-90.0,0.0,-60.0);
    glVertex3f(-90.0,330.0,-60.0);
    glVertex3f(-132.1,330.0,10.0);
    glEnd();

    glBegin(GL_QUADS);//depan kiri
    glColor3ub(230, 230, 230);
    glVertex3f(-190.0,0.0,-28.0);
    glVertex3f(-132.1,0.0,10.0);
    glVertex3f(-132.1,330.0,10.0);
    glVertex3f(-190.0,330.0,-28.0);
    glEnd();

    glBegin(GL_QUADS);//samping kiri depan
    glColor3ub(255, 255, 255);
    glVertex3f(-190.0,0.0,-28.0);
    glVertex3f(-178.0,0.0,-60.0);
    glVertex3f(-178.0,330.0,-60.0);
    glVertex3f(-190.0,330.0,-28.0);
    glEnd();

    glBegin(GL_QUADS);//samping kiri belakang
    glColor3ub(255, 255, 255);
    glVertex3f(-190.0,0.0,-92.0);
    glVertex3f(-178.0,0.0,-60.0);
    glVertex3f(-178.0,330.0,-60.0);
    glVertex3f(-190.0,330.0,-92.0);
    glEnd();

    glBegin(GL_QUADS);//belakang kiri
    glColor3ub(230, 230, 230);
    glVertex3f(-190.0,0.0,-92.0);
    glVertex3f(-132.1,0.0,-130.0);
    glVertex3f(-132.1,330.0,-130.0);
    glVertex3f(-190.0,330.0,-92.0);
    glEnd();

    glBegin(GL_QUADS);//belakang kanan
    glColor3ub(255, 255, 255);
    glVertex3f(-132.1,0.0,-130.0);
    glVertex3f(-90.0,0.0,-60.0);
    glVertex3f(-90.0,330.0,-60.0);
    glVertex3f(-132.1,330.0,-130.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(191, 191, 191);
    glVertex3f(-178.0,0.1,-60.0);
    glVertex3f(-190.0,0.1,-28.0);
    glVertex3f(-132.1,0.1,10.0);
    glVertex3f(-90.0,0.1,-60.0);
    glVertex3f(-132.1,0.1,-130.0);
    glVertex3f(-190.0,0.1,-92.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(230, 230, 230);
    glVertex3f(-178.0,330.0,-60.0);
    glVertex3f(-190.0,330.0,-28.0);
    glVertex3f(-132.1,330.0,10.0);
    glVertex3f(-90.0,330.0,-60.0);
    glVertex3f(-132.1,330.0,-130.0);
    glVertex3f(-190.0,330.0,-92.0);
    glEnd();

    //BANGUNAN TINGGI KURUS KANAN
    glBegin(GL_QUADS);//depan kiri
    glColor3ub(255, 255, 255);
    glVertex3f(132.1,0.0,10.0);
    glVertex3f(90.0,0.0,-60.0);
    glVertex3f(90.0,330.0,-60.0);
    glVertex3f(132.1,330.0,10.0);
    glEnd();

    glBegin(GL_QUADS);//depan kanan
    glColor3ub(230, 230, 230);
    glVertex3f(190.0,0.0,-28.0);
    glVertex3f(132.1,0.0,10.0);
    glVertex3f(132.1,330.0,10.0);
    glVertex3f(190.0,330.0,-28.0);
    glEnd();

    glBegin(GL_QUADS);//samping kanan depan
    glColor3ub(255, 255, 255);
    glVertex3f(190.0,0.0,-28.0);
    glVertex3f(178.0,0.0,-60.0);
    glVertex3f(178.0,330.0,-60.0);
    glVertex3f(190.0,330.0,-28.0);
    glEnd();

    glBegin(GL_QUADS);//samping kanan belakang
    glColor3ub(255, 255, 255);
    glVertex3f(190.0,0.0,-92.0);
    glVertex3f(178.0,0.0,-60.0);
    glVertex3f(178.0,330.0,-60.0);
    glVertex3f(190.0,330.0,-92.0);
    glEnd();

    glBegin(GL_QUADS);//belakang kanan
    glColor3ub(230, 230, 230);
    glVertex3f(190.0,0.0,-92.0);
    glVertex3f(132.1,0.0,-130.0);
    glVertex3f(132.1,330.0,-130.0);
    glVertex3f(190.0,330.0,-92.0);
    glEnd();

    glBegin(GL_QUADS);//belakang kiri
    glColor3ub(255, 255, 255);
    glVertex3f(132.1,0.0,-130.0);
    glVertex3f(90.0,0.0,-60.0);
    glVertex3f(90.0,330.0,-60.0);
    glVertex3f(132.1,330.0,-130.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(191, 191, 191);
    glVertex3f(178.0,0.1,-60.0);
    glVertex3f(190.0,0.1,-28.0);
    glVertex3f(132.1,0.1,10.0);
    glVertex3f(90.0,0.1,-60.0);
    glVertex3f(132.1,0.1,-130.0);
    glVertex3f(190.0,0.1,-92.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(230, 230, 230);
    glVertex3f(178.0,330.0,-60.0);
    glVertex3f(190.0,330.0,-28.0);
    glVertex3f(132.1,330.0,10.0);
    glVertex3f(90.0,330.0,-60.0);
    glVertex3f(132.1,330.0,-130.0);
    glVertex3f(190.0,330.0,-92.0);
    glEnd();

    subgedung_kanan();
    subgedung_kiri();
    jendela_depan();
    rumput();
    aspal();
    poni();
    gerbang();
    lambangSegitiga();
    papan_nama();
    uksw();
    jendelakutil();
    sekatkaca();
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
		case '9':
			glRotatef(2.0, 0.0, 0.0, -5.0);
			break;
		case ',':
			glRotatef(5.0, 0.0, 0.0, -5.0);
			break;
			//rotate ke samping kiri
		case '7':
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
