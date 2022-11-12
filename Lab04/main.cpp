#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
# define PI 3.14159265358979323846

int posx = 0;
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);  // Set display window colour to white

    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);		// Set projection parameters
    gluOrtho2D(0.0, 120.0, 0.0, 140.0);

}

///sun
void circle(float a, float b, float r)
{

    int i;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    GLfloat x=a;
    GLfloat y=b;
    GLfloat radius =r;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}


void sun()
{
    glColor3f(1.99, 0.58, 0.15);
    circle(1,1,1);

}

///cloud1
void cloud()
{
    glColor3f(1,1,1);
    circle(.8,.8,.8);
    circle(2,1,.8);
    circle(1.5,1.6,.8);
}

///cloud2
void cloud2()
{
    glColor3f(1,1,1);
    circle(.8,.8,.8);
    circle(2,1,.8);
    circle(1.5,1.6,.8);
}


///cloud3
void cloud3()
{
    glColor3f(1,1,1);
    circle(.8,.8,.8);
    circle(2,1,.8);
    circle(1.5,1.6,.8);
}


///cloud4
void cloud4()
{
    glColor3f(1,1,1);
    circle(.8,.8,.8);
    circle(2,1,.8);
    circle(1.5,1.6,.8);
}

///cloud5
void cloud5()
{
    glColor3f(1,1,1);
    circle(.8,.8,.8);
    circle(2,1,.8);
    circle(1.5,1.6,.8);
}




void line_drawing(float a, float b, float c, float d)
{
    // Draw an outlined triangle
    glBegin(GL_LINES);

    glVertex2f(a, b);
    glVertex2f(c, d);


    glEnd();
}

void quads(float a, float b, float c, float d, float e, float f, float g, float h)
{

    glBegin(GL_QUADS); //Begin quadrilateral coordinates

    //Trapezoid
    glVertex2f(a, b);
    glVertex2f(c,d);
    glVertex2f(e, f);
    glVertex2f(g, h);

    glEnd(); //End quadrilateral coordinates


}

void triangle(float a, float b, float c, float d, float e, float f)
{
    glBegin(GL_TRIANGLES);
    //Triangle
    glVertex2f(a, b);
    glVertex2f(c, d);
    glVertex2f(e, f);

    glEnd();//End triangle coordinates

}

void pentagon(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r)
{
    glBegin(GL_TRIANGLES); //Begin triangle coordinates

    //Pentagon
    glVertex2i(a, b);
    glVertex2i(c, d);
    glVertex2i(e, f);

    glVertex2i(g, h);
    glVertex2i(i, j);
    glVertex2i(k, l);

    glVertex2i(m, n);
    glVertex2i(o, p);
    glVertex2i(q, r);

    glEnd();//End triangle coordinates
}



///river
void river()
{
    glColor3f(0.0352941176470588, 0.5098039215686275, 0.9568627450980392);
    glBegin(GL_POLYGON);

    glVertex3i(14, 0, 0);
    glVertex3i(12, 40, 0);
    glVertex3i(30, 40, 0);
    glVertex3i(49, 0, 0);


    glEnd();



}

void boat()
{

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);


    glVertex3i(19,12,0);
    glVertex3i(16,16,0);
    glVertex3i(30,16,0);
    glVertex3i(26,12,0);
    glEnd();

    glColor3f(0.0,0.1,0.8);
    glBegin(GL_POLYGON);


    glVertex3i(18,16,0);
    glVertex3i(18,20,0);
    glVertex3i(28,20,0);
    glVertex3i(28,16,0);
    glEnd();

    glColor3f(0.2,0.3,0.7 );
    glBegin(GL_TRIANGLES);

    glVertex3i(18,20,0);
    glVertex3i(18,16,0);
    glVertex3i(16,16,0);
    glEnd();

    glColor3f(0.2,0.3,0.7);
    glBegin(GL_TRIANGLES);

    glVertex3i(28,16,0);
    glVertex3i(28,20,0);
    glVertex3i(30,16,0);

    glEnd();




}

void update(int value)
{

    if(posx>=15)
    {
        posx=0;
    }
    else
    {
        posx++;
    }
    glutPostRedisplay();
    glutTimerFunc(300, update, 0);
}

void tree()
{
    ///tree1
    glColor3f(0.6, 0.2, 0.1);

    glBegin(GL_POLYGON);

    glVertex3i(5, 12, 0);
    glVertex3i(7, 12, 0);


    glVertex3i(7, 30, 0);
    glVertex3i(5, 30, 0);

    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(1, 30, 0);
    glVertex3i(11, 30, 0);


    glVertex3i(6, 40, 0);

    glEnd();
    glBegin(GL_POLYGON);


    glVertex3i(1, 33, 0);
    glVertex3i(10, 33, 0);


    glVertex3i(6, 40, 0);



    glEnd();



}

//sun Animtion
GLfloat sunT=-10.0f;
GLfloat sunA=0.01f;

void sunTR(int value){

    if(sunT > 122)
        sunT=-10;
        sunT+=sunA;
        glutPostRedisplay();
        glutTimerFunc(10,sunTR,0);

}

///cloud animation
GLfloat cloudT=-5.0f;
GLfloat cloudA=0.05f;

void cloudTR(int value){

    if(cloudT > 120)
        cloudT=-5;
        cloudT+=cloudA;
        glutPostRedisplay();
        glutTimerFunc(10,cloudTR,0);

}


///cloud4 animation
GLfloat cloudT4=-5.0f;
GLfloat cloudA4=0.02f;

void cloudTR4(int value){

    if(cloudT4 > 120)
        cloudT4=-5;
        cloudT4+=cloudA4;
        glutPostRedisplay();
        glutTimerFunc(10,cloudTR4,0);

}


///cloud5 animation
GLfloat cloudT5=-10.0f;
GLfloat cloudA5=0.03f;

void cloudTR5(int value){

    if(cloudT5 > 120)
        cloudT5=-10;
        cloudT5+=cloudA5;
        glutPostRedisplay();
        glutTimerFunc(10,cloudTR5,0);

}

void drawShapes(void)
{
    glClear(GL_COLOR_BUFFER_BIT);	// Clear display window

    // glColor3f(0.0f, 0.1f, 0.0f);//Forest Green
    glColor3f(0.1,0.9,0.1);//Green



    quads(0.0,0.0,0.0,40.0,120,40.0,120,0.0); //


    glColor3f(0.0f, 1.0f, 1.0f);
    //sky
    glColor3f(0.0,0.9,0.9);
    quads(0.0,40.0,0.0,140,140,140,140,40.0);

    // glColor3f(0.0, 0.60, 1.0);

    ///Pahar
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(0,40, 0);
    glVertex3i(5, 40, 0);


    glVertex3i(4,43, 0);

    glEnd();




    glColor3f(0.3,0.9,0);
    glBegin(GL_POLYGON);

    glVertex3i(2,40, 0);
    glVertex3i(10, 40, 0);


    glVertex3i(9,45, 0);

    glEnd();

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(3,40, 0);
    glVertex3i(8, 40, 0);


    glVertex3i(6,44, 0);

    glEnd();


    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(7,40, 0);
    glVertex3i(12, 40, 0);


    glVertex3i(11,44, 0);

    glEnd();


    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(30,40, 0);
    glVertex3i(40, 40, 0);


    glVertex3i(38,46, 0);

    glEnd();


    glColor3f(0.3,0.9,0);
    glBegin(GL_POLYGON);

    glVertex3i(32,40, 0);
    glVertex3i(43, 40, 0);


    glVertex3i(42,48, 0);

    glEnd();


    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(38,40, 0);
    glVertex3i(44, 40, 0);


    glVertex3i(44,46, 0);

    glEnd();

    glColor3f(0.3,0.9,0);
    glBegin(GL_POLYGON);

    glVertex3i(38,40, 0);
    glVertex3i(50, 40, 0);


    glVertex3i(50,48, 0);

    glEnd();

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(44,40, 0);
    glVertex3i(53, 40, 0);

    glVertex3i(52,46, 0);


    glEnd();


    glColor3f(0.3,0.9,0);
    glBegin(GL_POLYGON);

    glVertex3i(44,40, 0);
    glVertex3i(60, 40, 0);


    glVertex3i(59,48, 0);

    glEnd();


    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(55,40, 0);
    glVertex3i(67, 40, 0);


    glVertex3i(62,46, 0);

    glEnd();


    glColor3f(0.3,0.9,0);
    glBegin(GL_POLYGON);

    glVertex3i(58,40, 0);
    glVertex3i(70, 40, 0);


    glVertex3i(69,48, 0);

    glEnd();


    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(62,40, 0);
    glVertex3i(77, 40, 0);


    glVertex3i(74,46, 0);

    glEnd();


    glColor3f(0.3,0.9,0);
    glBegin(GL_POLYGON);

    glVertex3i(70,40, 0);
    glVertex3i(85, 40, 0);


    glVertex3i(84,48, 0);

    glEnd();



    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(75,40, 0);
    glVertex3i(90, 40, 0);


    glVertex3i(85,46, 0);

    glEnd();



    glColor3f(0.3,0.9,0);
    glBegin(GL_POLYGON);

    glVertex3i(80,40, 0);
    glVertex3i(95, 40, 0);


    glVertex3i(93,48, 0);

    glEnd();


    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(90,40, 0);
    glVertex3i(100, 40, 0);


    glVertex3i(98,46, 0);

    glEnd();
    ///

    glColor3f(0.3,0.9,0);
    glBegin(GL_POLYGON);

    glVertex3i(90,40, 0);
    glVertex3i(110, 40, 0);


    glVertex3i(107,48, 0);

    glEnd();
    ///

    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);

    glVertex3i(100,40, 0);
    glVertex3i(115, 40, 0);


    glVertex3i(114,48, 0);

    glEnd();


    glColor3f(0.3,0.9,0);
    glBegin(GL_POLYGON);

    glVertex3i(100,40, 0);
    glVertex3i(120, 40, 0);


    glVertex3i(119,45, 0);

    glEnd();



    ///Rasta

    glColor3f(0.23, 0.26, 0.23);
    glBegin(GL_POLYGON);

    glVertex3i(74, 0, 0);
    glVertex3i(82, 25, 0);
    glVertex3i(86, 25, 0);
    glVertex3i(82, 0, 0);


    glEnd();

    ///rastar dag
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);

    glVertex3i(77.8, 0, 0);
    glVertex3i(83.9, 24, 0);
    glVertex3i(84, 24, 0);
    glVertex3i(78, 0, 0);

    glEnd();



    glColor3f(0.23, 0.26, 0.23);
    glBegin(GL_POLYGON);

    glVertex3i(82, 25, 0);
    glVertex3i(60, 35, 0);
    glVertex3i(70, 35, 0);
    glVertex3i(86, 25, 0);


    glEnd();

///ghor 1
    //tin
    glColor3f(0.7,0.0,0.1);
    triangle(53.0,30.0,65.0,41.0,76,30.0);
    glColor3f(0.5411764705882353, 0.0, 0.5411764705882353);

    //boundary
    glColor3f(1.0f, 1.89f, 0.89f);
    glColor3f(1.0,0.8,0.6);
    quads(55.0,12.0,55.0,30.0,75.0,30.0,75.0,12.0);


    ///dorja
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.1);

    glVertex2f(62,12);
    glVertex2f(62,20);
    glVertex2f(66,20);
    glVertex2f(66,12);

    glEnd();
    glPopMatrix();

//left janala
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0,0.0,0.0);

    glVertex2f(56,20);
    glVertex2f(56,24);
    glVertex2f(59,24);
    glVertex2f(59,20);

    glEnd();
    glPopMatrix();

///right janala
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0,0.0,0.0);

    glVertex2f(71,20);
    glVertex2f(71,24);
    glVertex2f(74,24);
    glVertex2f(74,20);

    glEnd();
    glPopMatrix();



    ///ghor2

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0 );

    glVertex2f(40,20);
    glVertex2f(52,20);

    glVertex2f(52,35);
    glVertex2f(40,35);

    glEnd();
    glPopMatrix();

    ///tin
    glColor3f(0.5,0,0.1);
    triangle(39.0,35.0,53,35,46,41);
    glColor3f(0.5411764705882353, 0.0, 0.5411764705882353);

    ///dorja

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.1 );

    glVertex2f(48,20);
    glVertex2f(50,20);

    glVertex2f(50,28);
    glVertex2f(48,28);

    glEnd();
    glPopMatrix();

    ///janala

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0,0.0,0.0);

    glVertex2f(41,26);
    glVertex2f(41,30);

    glVertex2f(44,30);
    glVertex2f(44,26);



    glEnd();
    glPopMatrix();



    ///ghor3

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.4,0.1,0.5  );

    glVertex2f(87,30);
    glVertex2f(87,38);

    glVertex2f(97,38);
    glVertex2f(97,30);

    glEnd();
    glPopMatrix();


    ///tin
    glColor3f(0.3,0,0.1);
    triangle(86.0,38.0,98,38,92,42);
    glColor3f(0.5411764705882353, 0.0, 0.5411764705882353);

    ///dorja

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.1 );

    glVertex2f(93,30);
    glVertex2f(95,30);

    glVertex2f(95,35);
    glVertex2f(93,35);

    glEnd();
    glPopMatrix();


    ///janala

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0,0.0,0.0 );

    glVertex2f(88,33);
    glVertex2f(88,36);

    glVertex2f(90,36);
    glVertex2f(90,33);

    glEnd();
    glPopMatrix();


    ///ghor 4

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.8,0,0.8 );

    glVertex2f(102,10);
    glVertex2f(102,30);

    glVertex2f(118,30);
    glVertex2f(118,10);

    glEnd();
    glPopMatrix();


    ///dorja

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.1 );

    glVertex2f(108,10);
    glVertex2f(108,20);

    glVertex2f(112,20);
    glVertex2f(112,10);

    glEnd();
    glPopMatrix();


    ///janala

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0 );

    glVertex2f(103,16);
    glVertex2f(103,20);

    glVertex2f(106,20);
    glVertex2f(106,16);

    glEnd();
    glPopMatrix();



    ///janala

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0 );

    glVertex2f(114,16);
    glVertex2f(114,20);

    glVertex2f(117,20);
    glVertex2f(117,16);

    glEnd();
    glPopMatrix();


    ///tin
    glColor3f(0,0,1);
    triangle(100.0,30.0,120,30,110,40);
    glColor3f(0.5411764705882353, 0.0, 0.5411764705882353);




    tree();

    river();

    //sun
    glPushMatrix();
    glTranslatef(sunT,100,0);
    glScalef(7,7.5,0);
    sun();
    glPopMatrix();


    ///cloud
    glPushMatrix();
    glTranslatef(cloudT,80,0);
    glScalef(7,7.5,0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudT,75,0);
    glScalef(7,7.5,0);
    cloud();
    glPopMatrix();

    ///cloud3
    glPushMatrix();
    glTranslatef(0,90,0);
    glScalef(7,7.5,0);
    cloud();
    glPopMatrix();


    ///cloud2
    glPushMatrix();
    glTranslatef(60,110,0);
    glScalef(7,7.5,0);
    cloud2();
    glPopMatrix();

    ///cloud4
    glPushMatrix();
    glTranslatef(cloudT4,115,0);
    glScalef(7,7.5,0);
    cloud4();
    glPopMatrix();



    ///cloud5
    glPushMatrix();
    glTranslatef(cloudT5,65,0);
    glScalef(7,7.5,0);
    cloud5();
    glPopMatrix();





    // pentagon();

    glPushMatrix();
    glTranslatef(posx,-1,-1);
    boat();
    glPopMatrix();







///tree3

    glColor3f(0.6, 0.2, 0.1);

    glBegin(GL_POLYGON);

    glVertex3i(2, 12, 0);
    glVertex3i(3, 12, 0);


    glVertex3i(3, 22, 0);
    glVertex3i(2, 22, 0);

    glEnd();



    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_POLYGON);


    glVertex3i(0, 22, 0);
    glVertex3i(6, 22, 0);


    glVertex3i(3, 26, 0);
    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(0, 24, 0);
    glVertex3i(6, 24, 0);


    glVertex3i(3,28, 0);

    glEnd();


    ///tree4
    glColor3f(0.6, 0.2, 0.1);

    glBegin(GL_POLYGON);

    glVertex3i(1, 6, 0);
    glVertex3i(2, 6, 0);


    glVertex3i(2, 14, 0);
    glVertex3i(1, 14, 0);

    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(0, 14, 0);
    glVertex3i(3, 14, 0);


    glVertex3i(1.5,20, 0);

    glEnd();

    glBegin(GL_POLYGON);


    glVertex3i(0, 16, 0);
    glVertex3i(3, 16, 0);


    glVertex3i(1.5, 21, 0);



    glEnd();



    ///tree5
    glColor3f(0.6, 0.2, 0.1);

    glBegin(GL_POLYGON);

    glVertex3i(10, 10, 0);
    glVertex3i(12,10, 0);


    glVertex3i(12, 27, 0);
    glVertex3i(10, 27, 0);

    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(8,27, 0);
    glVertex3i(14, 27, 0);


    glVertex3i(11,35, 0);

    glEnd();

    glBegin(GL_POLYGON);


    glVertex3i(8,30, 0);
    glVertex3i(14, 30, 0);


    glVertex3i(11,36, 0);

    glEnd();


    ///tree6

    glColor3f(0.6, 0.2, 0.1);

    glBegin(GL_POLYGON);

    glVertex3i(80, 30, 0);
    glVertex3i(81, 30, 0);


    glVertex3i(81, 36, 0);
    glVertex3i(80, 36, 0);

    glEnd();


    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(77, 36, 0);
    glVertex3i(83, 36, 0);


    glVertex3i(81,40, 0);

    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(77, 38, 0);
    glVertex3i(83, 38, 0);


    glVertex3i(81,42, 0);

    glEnd();



    ///tree7

    glColor3f(0.6, 0.2, 0.1);

    glBegin(GL_POLYGON);

    glVertex3i(85, 30, 0);
    glVertex3i(86, 30, 0);


    glVertex3i(86, 37, 0);
    glVertex3i(85, 37, 0);

    glEnd();


    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(84, 37, 0);
    glVertex3i(87, 37, 0);


    glVertex3i(85,41, 0);

    glEnd();


    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(84, 39, 0);
    glVertex3i(87, 39, 0);


    glVertex3i(85,43, 0);

    glEnd();


    ///tree8

    glColor3f(0.6, 0.2, 0.1);

    glBegin(GL_POLYGON);

    glVertex3i(75, 33, 0);
    glVertex3i(76, 33, 0);


    glVertex3i(76, 37, 0);
    glVertex3i(75, 37, 0);

    glEnd();


    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(74, 37, 0);
    glVertex3i(77, 37, 0);


    glVertex3i(75,40, 0);

    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(74, 38, 0);
    glVertex3i(77, 38, 0);


    glVertex3i(75,41, 0);

    glEnd();



    ///tree 9

    glColor3f(0.6, 0.2, 0.1);

    glBegin(GL_POLYGON);

    glVertex3i(54, 33, 0);
    glVertex3i(55, 33, 0);


    glVertex3i(55, 37, 0);
    glVertex3i(54, 37, 0);

    glEnd();


    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(53, 37, 0);
    glVertex3i(56, 37, 0);


    glVertex3i(54,40, 0);

    glEnd();

    glColor3f(0.0, 0.5, 0.0);

    glBegin(GL_POLYGON);

    glVertex3i(53, 38, 0);
    glVertex3i(56, 38, 0);


    glVertex3i(54,41, 0);

    glEnd();


    glFlush();	// Process all OpenGL routines
}



int main(int argc, char* argv[])
{
    glutInit(&argc, argv);						     // Initalise GLUT
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	     // Set display mode

    glutInitWindowPosition(50, 100);				// Set window position
    glutInitWindowSize(600, 600);					// Set window size
    glutCreateWindow("Village View");// Create display window
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);


    init();							// Execute initialisation procedure
    glutDisplayFunc(drawShapes);
    glutTimerFunc(0, update, 0);
    glutTimerFunc(10,sunTR,0);
    glutTimerFunc(10,cloudTR,0);
    glutTimerFunc(10,cloudTR4,0);
    glutTimerFunc(10,cloudTR5,0);
    glutMainLoop();					// Display everything and wait

    return 0;
}
