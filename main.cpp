#include<windows.h>
#include <GL/glut.h>

void init(void);
void tampil(void);

void tempat_tidur(void);
void lemari(void);
void meja(void);
void tv(void);
void kursi(void);

void keyboard(unsigned char, int, int);
void ukuran (int, int);


int is_depth;
int x1=5,a=-10,z1=10,z2=10;
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250,80);
    glutCreateWindow("Yohan's Banjarnahor - 672018356");
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
void tampil(void){
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    //aspal depan
    glBegin(GL_QUADS);
    glColor3ub(191, 191, 191);
    glVertex3f(-70.0,49.9,450.0);
    glVertex3f(70.0,49.9,450.0);
    glVertex3f(70.0,49.9,400.0);
    glVertex3f(-70.0,49.9,400.0);
    glEnd();

    //aspal belakang
    glBegin(GL_POLYGON);
    glColor3ub(191, 191, 191);
    glVertex3f(70.0,49.9,400.0);
    glVertex3f(620.0,49.9,0.0);
    glVertex3f(350.0,49.9,-450.0);
    glVertex3f(-350.0,49.9,-450.0);
    glVertex3f(-620.0,49.9,0.0);
    glVertex3f(-70.0,49.9,400.0);
    glEnd();

    //

    //bangunan besar tengah
    glBegin(GL_QUADS);//depan
    glColor3ub(255, 247, 230);
    glVertex3f(-120.0,50.0,-10.0);
    glVertex3f(120.0,50.0,-10.0);
    glVertex3f(120.0,230.0,-10.0);
    glVertex3f(-120.0,230.0,-10.0);
    glEnd();

    glBegin(GL_QUADS);//belakang
    glColor3ub(255, 247, 230);
    glVertex3f(-120.0,50.0,-110.0);
    glVertex3f(120.0,50.0,-110.0);
    glVertex3f(120.0,230.0,-110.0);
    glVertex3f(-120.0,230.0,-110.0);
    glEnd();

    glBegin(GL_QUADS);//bawah
    glColor3ub(255, 223, 153);
    glVertex3f(-120.0,50.0,-10.0);
    glVertex3f(120.0,50.0,-10.0);
    glVertex3f(120.0,50.0,-110.0);
    glVertex3f(-120.0,50.0,-110.0);
    glEnd();

    glBegin(GL_QUADS);//atas
    glColor3ub(255, 223, 153);
    glVertex3f(-120.0,230.0,-10.0);
    glVertex3f(120.0,230.0,-10.0);
    glVertex3f(120.0,230.0,-110.0);
    glVertex3f(-120.0,230.0,-110.0);
    glEnd();

    glBegin(GL_QUADS);//kiri
    glColor3ub(255, 239, 204);
    glVertex3f(-120.0,50.0,-10.0);
    glVertex3f(-120.0,50.0,-110.0);
    glVertex3f(-120.0,230.0,-110.0);
    glVertex3f(-120.0,230.0,-10.0);
    glEnd();

    glBegin(GL_QUADS);//kanan
    glColor3ub(255, 239, 204);
    glVertex3f(120.0,50.0,-10.0);
    glVertex3f(120.0,50.0,-110.0);
    glVertex3f(120.0,230.0,-110.0);
    glVertex3f(120.0,230.0,-10.0);
    glEnd();

    //BANGUNAN TINGGI KURUS KIRI
    glBegin(GL_QUADS);//depan kanan
    glColor3ub(255, 255, 255);
    glVertex3f(-140.0,50.0,10.0);
    glVertex3f(-120.0,50.0,-10.0);
    glVertex3f(-120.0,280.0,-10.0);
    glVertex3f(-140.0,280.0,10.0);
    glEnd();

    glBegin(GL_QUADS);//depan kiri
    glColor3ub(230, 230, 230);
    glVertex3f(-210.0,50.0,-50.0);
    glVertex3f(-140.0,50.0,10.0);
    glVertex3f(-140.0,280.0,10.0);
    glVertex3f(-210.0,280.0,-50.0);
    glEnd();

    glBegin(GL_QUADS);//samping kiri
    glColor3ub(255, 255, 255);
    glVertex3f(-210.0,50.0,-50.0);
    glVertex3f(-210.0,50.0,-70.0);
    glVertex3f(-210.0,280.0,-70.0);
    glVertex3f(-210.0,280.0,-50.0);
    glEnd();

    glBegin(GL_QUADS);//belakang kiri
    glColor3ub(230, 230, 230);
    glVertex3f(-210.0,50.0,-70.0);
    glVertex3f(-140.0,50.0,-130.0);
    glVertex3f(-140.0,280.0,-130.0);
    glVertex3f(-210.0,280.0,-70.0);
    glEnd();

    glBegin(GL_QUADS);//belakang kanan
    glColor3ub(255, 255, 255);
    glVertex3f(-140.0,50.0,-130.0);
    glVertex3f(-120.0,50.0,-110.0);
    glVertex3f(-120.0,280.0,-110.0);
    glVertex3f(-140.0,280.0,-130.0);
    glEnd();

    glBegin(GL_QUADS);//samping kanan
    glColor3ub(230, 230, 230);
    glVertex3f(-120.1,50.0,-10.0);
    glVertex3f(-120.1,50.0,-110.0);
    glVertex3f(-120.1,280.0,-110.0);
    glVertex3f(-120.1,280.0,-10.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(255, 255, 255);
    glVertex3f(-210.0,50.0,-50.0);
    glVertex3f(-140.0,50.0,10.0);
    glVertex3f(-120.0,50.0,-10.0);
    glVertex3f(-120.0,50.0,-110.0);
    glVertex3f(-140.0,50.0,-130.0);
    glVertex3f(-210.0,50.0,-70.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(204, 204, 204);
    glVertex3f(-210.0,280.0,-50.0);
    glVertex3f(-140.0,280.0,10.0);
    glVertex3f(-120.0,280.0,-10.0);
    glVertex3f(-120.0,280.0,-110.0);
    glVertex3f(-140.0,280.0,-130.0);
    glVertex3f(-210.0,280.0,-70.0);
    glEnd();

    //BANGUNAN TINGGI KURUS KANAN
    glBegin(GL_QUADS);//depan kiri
    glColor3ub(255, 255, 255);
    glVertex3f(120.0,50.0,-10.0);
    glVertex3f(140.0,50.0,10.0);
    glVertex3f(140.0,280.0,10.0);
    glVertex3f(120.0,280.0,-10.0);
    glEnd();

    glBegin(GL_QUADS);//depan kanan
    glColor3ub(230, 230, 230);
    glVertex3f(140.0,50.0,10.0);
    glVertex3f(210.0,50.0,-50.0);
    glVertex3f(210.0,280.0,-50.0);
    glVertex3f(140.0,280.0,10.0);
    glEnd();

    glBegin(GL_QUADS);//samping kanan
    glColor3ub(255, 255, 255);
    glVertex3f(210.0,50.0,-50.0);
    glVertex3f(210.0,50.0,-70.0);
    glVertex3f(210.0,280.0,-70.0);
    glVertex3f(210.0,280.0,-50.0);
    glEnd();

    glBegin(GL_QUADS);//belakang kanan
    glColor3ub(230, 230, 230);
    glVertex3f(140.0,50.0,-130.0);
    glVertex3f(210.0,50.0,-70.0);
    glVertex3f(210.0,280.0,-70.0);
    glVertex3f(140.0,280.0,-130.0);
    glEnd();

    glBegin(GL_QUADS);//belakang kiri
    glColor3ub(255, 255, 255);
    glVertex3f(120.0,50.0,-110.0);
    glVertex3f(140.0,50.0,-130.0);
    glVertex3f(140.0,280.0,-130.0);
    glVertex3f(120.0,280.0,-110.0);
    glEnd();

    glBegin(GL_QUADS);//samping kiri
    glColor3ub(230, 230, 230);
    glVertex3f(120.1,50.0,-10.0);
    glVertex3f(120.1,50.0,-110.0);
    glVertex3f(120.1,280.0,-110.0);
    glVertex3f(120.1,280.0,-10.0);
    glEnd();

    glBegin(GL_POLYGON);//bawah
    glColor3ub(255, 255, 255);
    glVertex3f(210.0,50.0,-50.0);
    glVertex3f(140.0,50.0,10.0);
    glVertex3f(120.0,50.0,-10.0);
    glVertex3f(120.0,50.0,-110.0);
    glVertex3f(140.0,50.0,-130.0);
    glVertex3f(210.0,50.0,-70.0);
    glEnd();

    glBegin(GL_POLYGON);//atas
    glColor3ub(204, 204, 204);
    glVertex3f(210.0,280.0,-50.0);
    glVertex3f(140.0,280.0,10.0);
    glVertex3f(120.0,280.0,-10.0);
    glVertex3f(120.0,280.0,-110.0);
    glVertex3f(140.0,280.0,-130.0);
    glVertex3f(210.0,280.0,-70.0);
    glEnd();


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
