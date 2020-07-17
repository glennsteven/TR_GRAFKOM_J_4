#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void tampil(void);

void keyboard(unsigned char, int, int);
void ukuran (int, int);

int is_depth;
float x1=10.0;
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(950,650);
    glutInitWindowPosition(250,80);
    glutCreateWindow("Kelompok 4");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
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
        glVertex3f(132.0,0.0,10.0);
        glVertex3f(132.0,165.0,10.0);
        glVertex3f(220.0,165.0,170);
        glVertex3f(220.0,0.0,170);
    //2
        glVertex3f(220.0,0.0,170);
        glVertex3f(220.0,165.0,170);
        glVertex3f(270.0,165.0,130.0);
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

        glVertex3f(245.0,125.0,-80.0);
        glVertex3f(290.0,125.0,-200.0);
        glVertex3f(190.0,125.0,-260.0);
        glVertex3f(132.0,125.0,-130.0);

    glEnd();
}

void subgedung_kiri(){
    glBegin(GL_QUADS);
    //1
        glColor3ub(255,255,255);
        glVertex3f(-132.0,0.0,10.0);
        glVertex3f(-132.0,165.0,10.0);
        glVertex3f(-220.0,165.0,170);
        glVertex3f(-220.0,0.0,170);
    //2
        glVertex3f(-220.0,0.0,170);
        glVertex3f(-220.0,165.0,170);
        glVertex3f(-270.0,165.0,130.0);
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

void lambangSegitiga(){
    //Belakang Kiri
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(-75.0, 40.0, 5.0);
    glVertex3f(-55.0, 40.0, 5.0);
    glVertex3f(0.0, 120.0, 5.0);
    glVertex3f(0.0, 150.0, 5.0);
    glEnd();

    //Penutup Bawah Kiri
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
    glVertex3f(-75.0, 40.0, 5.0+x1);
    glVertex3f(-55.0, 40.0, 5.0+x1);
    glVertex3f(-55.0, 40.0, 5.0);
    glVertex3f(-75, 40.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
    glVertex3f(-75.0, 40.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0);
    glVertex3f(-75.0, 40.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
    glVertex3f(-55.0, 40.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0);
    glVertex3f(-55.0, 40.0, 5.0);
    glEnd();

    //Depan Kiri
    glBegin(GL_POLYGON);//depan
    glColor3ub(255,0,0);
    glVertex3f(-75.0, 40.0, 5.0+x1);
    glVertex3f(-55.0, 40.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0+x1);
    glEnd();

    //Belakang Kanan
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex3f(75.0, 40.0, 5.0);
    glVertex3f(55.0, 40.0, 5.0);
    glVertex3f(0.0, 120.0, 5.0);
    glVertex3f(0.0, 150.0, 5.0);
    glEnd();

    //Penutup Bawah Kanan
    glBegin(GL_POLYGON);
    glColor3ub(0,255,0);
    glVertex3f(75.0, 40.0, 5.0+x1);
    glVertex3f(55.0, 40.0, 5.0+x1);
    glVertex3f(55.0, 40.0, 5.0);
    glVertex3f(75, 40.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
    glVertex3f(75.0, 40.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0);
    glVertex3f(75.0, 40.0, 5.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,255);
    glVertex3f(55.0, 40.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0);
    glVertex3f(55.0, 40.0, 5.0);
    glEnd();

    //Depan Kanan
    glBegin(GL_POLYGON);//depan
    glColor3ub(255,0,0);
    glVertex3f(75.0, 40.0, 5.0+x1);
    glVertex3f(55.0, 40.0, 5.0+x1);
    glVertex3f(0.0, 120.0, 5.0+x1);
    glVertex3f(0.0, 150.0, 5.0+x1);
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
    glColor3ub(255,0,0);
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
    glVertex3f(-45.0, 30.0, 400.0);
    glVertex3f(-70.0, 15.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(-70.0, 0.0, 420.0);
    glVertex3f(-45.0, 0.0, 420.0);
    glVertex3f(-45.0, 30.0, 420.0);
    glVertex3f(-70.0, 15.0, 420.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(-70.0, 0.0, 420.0);
    glVertex3f(-70.0, 40.0, 420.0);
    glVertex3f(-70.0, 40.0, 400.0);
    glVertex3f(-70.0, 0.0, 400.0);
    glEnd();
    //Sebelah kiri
    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(-45.0, 0.0, 420.0);
    glVertex3f(-45.0, 30.0, 420.0);
    glVertex3f(-45.0, 30.0, 400.0);
    glVertex3f(-45.0, 0.0, 400.0);
    glEnd();

    //Gerbang Segitiga kiri
    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(-70.0, 15.0, 400.0);
    glVertex3f(0.0, 55.0, 400.0);
    glVertex3f(0.0, 80.0, 400.0);
    glVertex3f(-70.0, 40.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(-70.0, 15.0, 420.0);
    glVertex3f(0.0, 55.0, 420.0);
    glVertex3f(0.0, 80.0, 420.0);
    glVertex3f(-70.0, 40.0, 420.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(-70.0, 40.0, 420.0);
    glVertex3f(0.0, 80.0, 420.0);
    glVertex3f(0.0, 80.0, 400.0);
    glVertex3f(-70.0, 40.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(-45.0, 30.0, 420.0);
    glVertex3f(0.0, 55.0, 420.0);
    glVertex3f(0.0, 55.0, 400.0);
    glVertex3f(-45.0, 30.0, 400.0);
    glEnd();

    //Gerbang Segitiga Kanan
    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(70.0, 15.0, 400.0);
    glVertex3f(0.0, 55.0, 400.0);
    glVertex3f(0.0, 80.0, 400.0);
    glVertex3f(70.0, 40.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(70.0, 15.0, 420.0);
    glVertex3f(0.0, 55.0, 420.0);
    glVertex3f(0.0, 80.0, 420.0);
    glVertex3f(70.0, 40.0, 420.0);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(45.0, 30.0, 420.0);
    glVertex3f(0.0, 55.0, 420.0);
    glVertex3f(0.0, 55.0, 400.0);
    glVertex3f(45.0, 30.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(70.0, 40.0, 420.0);
    glVertex3f(0.0, 80.0, 420.0);
    glVertex3f(0.0, 80.0, 400.0);
    glVertex3f(70.0, 40.0, 400.0);
    glEnd();


    //Sebelah kanan
    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(70.0, 0.0, 400.0);
    glVertex3f(45.0, 0.0, 400.0);
    glVertex3f(45.0, 30.0, 400.0);
    glVertex3f(70.0, 15.0, 400.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(70.0, 0.0, 420.0);
    glVertex3f(45.0, 0.0, 420.0);
    glVertex3f(45.0, 30.0, 420.0);
    glVertex3f(70.0, 15.0, 420.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(70.0, 0.0, 420.0);
    glVertex3f(70.0, 40.0, 420.0);
    glVertex3f(70.0, 40.0, 400.0);
    glVertex3f(70.0, 0.0, 400.0);
    glEnd();
    //Sebelah Kanan
    glBegin(GL_POLYGON);
    glColor3ub(153, 102, 51);
    glVertex3f(45.0, 0.0, 420.0);
    glVertex3f(45.0, 30.0, 420.0);
    glVertex3f(45.0, 30.0, 400.0);
    glVertex3f(45.0, 0.0, 400.0);
    glEnd();
}
void tampil(void){
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    //bangunan besar tengah
    glBegin(GL_QUADS);//depan
    glColor3ub(255, 247, 230);
    glVertex3f(-120.0,50.0,-10.0);
    glVertex3f(120.0,50.0,-10.0);
    glVertex3f(120.0,280.0,-10.0);
    glVertex3f(-120.0,280.0,-10.0);
    glEnd();

    glBegin(GL_QUADS);//belakang
    glColor3ub(255, 247, 230);
    glVertex3f(-120.0,50.0,-110.0);
    glVertex3f(120.0,50.0,-110.0);
    glVertex3f(120.0,280.0,-110.0);
    glVertex3f(-120.0,280.0,-110.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(255, 247, 230);
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
    glVertex3f(-178.0,0.0,-60.0);
    glVertex3f(-190.0,0.0,-28.0);
    glVertex3f(-132.1,0.0,10.0);
    glVertex3f(-90.0,0.0,-60.0);
    glVertex3f(-132.1,0.0,-130.0);
    glVertex3f(-190.0,0.0,-92.0);
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
    glVertex3f(178.0,0.0,-60.0);
    glVertex3f(190.0,0.0,-28.0);
    glVertex3f(132.1,0.0,10.0);
    glVertex3f(90.0,0.0,-60.0);
    glVertex3f(132.1,0.0,-130.0);
    glVertex3f(190.0,0.0,-92.0);
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
    rumput();
    aspal();
    poni();
    gerbang();
    lambangSegitiga();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y){
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0,0.0,3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0,0.0,0.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0,0.0,-3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0,0.0,0.0);
        break;
    case '7':
        glTranslatef(0.0,3.0,0.0);
        break;
    case '9':
        glTranslatef(0.0,-3.0,0.0);
        break;
    case '2':
        glRotatef(2.0,1.0,0.0,0.0);
        break;
    case '8':
        glRotatef(-2.0,1.0,0.0,0.0);
        break;
    case '6':
        glRotatef(2.0,0.0,1.0,0.0);
        break;
    case '4':
        glRotatef(-2.0,0.0,1.0,0.0);
        break;
    case '1':
        glRotatef(2.0,0.0,0.0,1.0);
        break;
    case '3':
        glRotatef(-2.0,0.0,0.0,1.0);
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
    }
    tampil();
}

void ukuran(int lebar,int tinggi)
{
    if (tinggi==0)tinggi=1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, lebar/tinggi,5.0,900.0);
    glTranslatef(0.0,-100.0,-590.0);
    glMatrixMode(GL_MODELVIEW);
}
