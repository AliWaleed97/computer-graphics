#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include <cmath>
#include <GL/glut.h>
float upperbody=-90;
int sceneplay = 1;
int mickeyplay = 1;
int minion1play=1;
int minion2play=1;
int robinplay=1;
int gruplay=1;
int spongeplay=1;
int top = 1;
bool sponge = true;
float translateSpongebob = 0;
float angleGru = -90;
float robinx = 0.0;
float robiny = 0.0;
float minion1x = 0.0;
float minion1y = 0.0;
float minion2x = 0.0;
float minion2y = 0.0;
float armMickeyRight =0.0;
float armMickeyLeft=0.0;
bool mickeyRight = true;
bool mickeyLeft =true;
float t = 1;
float M1 =1;
float M2 =1;
// angle of rotation for the camera direction
float angle = 0.0;
// XZ position of the camera
float x = 0.0f, z = 18.0f; 

void bezierRobin(float t, int* p0,int* p1,int* p2,int* p3)
{
    //robin
    robinx=pow((1-t),3)*p0[0]+3*t*pow((1-t),2)*p1[0]+3*pow(t,2)*(1-t)*p2[0]+pow(t,3)*p3[0];
    robiny=pow((1-t),3)*p0[1]+3*t*pow((1-t),2)*p1[1]+3*pow(t,2)*(1-t)*p2[1]+pow(t,3)*p3[1];
}
void bezierMinion1(float t, int* p0, int* p1, int* p2, int* p3){
        // minion1
    minion1x=pow((1-t),3)*p0[0]+3*t*pow((1-t),2)*p1[0]+3*pow(t,2)*(1-t)*p2[0]+pow(t,3)*p3[0];
    minion1y=pow((1-t),3)*p0[1]+3*t*pow((1-t),2)*p1[1]+3*pow(t,2)*(1-t)*p2[1]+pow(t,3)*p3[1];
}
void bezierMinion2(float t, int* p0, int* p1, int* p2, int* p3){
        //minion2
    minion2x=pow((1-t),3)*p0[0]+3*t*pow((1-t),2)*p1[0]+3*pow(t,2)*(1-t)*p2[0]+pow(t,3)*p3[0];
    minion2y=pow((1-t),3)*p0[1]+3*t*pow((1-t),2)*p1[1]+3*pow(t,2)*(1-t)*p2[1]+pow(t,3)*p3[1];
}
void Anim(){
    if(sceneplay){
    //rotateCamera
            float radius = 18.0f;
            angle -= 0.05f;
            x = radius * sin(angle);
            z = radius * cos(angle);
        if(minion1play){
            upperbody+=3;
    //minion1
    int m3[]={6,5};
    int m2[]={0,4};
    int m1[]={9,1};
    int m0[]={2,1};
    bezierMinion1(M1, m0, m1, m2, m3);
    M1-=0.03;
        if(M1<=0){
            M1=1;
        }
    }else{

    }
    if(minion2play){
    //minion2
    int x3[]={0,3};
    int x2[]={2,0};
    int x1[]={1,5};
    int x0[]={2,2};
    bezierMinion2(M2, x0, x1, x2, x3);
    M2-=0.03;
        if(M2<=0){
            M2=1;
        }
    }else{

    }
    if(robinplay){
    //Robin
    int s3[]={-10,1};
    int s1[]={0,5};
    int s2[]={-10,3};
    int s0[]={20,2};
    bezierRobin(t, s0, s1, s2, s3);
    t-=0.03;
        if(t<=0){
            t=1;
        }
        }else{

        }
        if(gruplay){
    //Gru
    angleGru+=2;
    }else{

    }
    if(spongeplay){
    //spongeBob
    if(sponge)
    translateSpongebob+=0.5;
    if(!sponge)
    translateSpongebob-=0.5;
    if(translateSpongebob<=0)
        sponge = true;
    if(translateSpongebob>5)
        sponge=false;
}else{

}
    if(mickeyplay){
    //Mickey
    if(mickeyRight)
    armMickeyRight+=0.5;
    if(!mickeyRight)
    armMickeyRight-=0.5;
    if(armMickeyRight<=0)
        mickeyRight = true;
    if(armMickeyRight>5)
        mickeyRight=false;

    if(mickeyLeft)
    armMickeyLeft-=0.5;
    if(!mickeyLeft)
    armMickeyLeft+=0.5;
    if(armMickeyLeft<=-5)
        mickeyLeft = false;
    if(armMickeyLeft>=0)
        mickeyLeft=true;
}else{

}
}else{

}
    glutPostRedisplay();
}

void drawWall(){
    //front wall
    glPushMatrix();

    glPushMatrix();
    glColor3d(1,0,0);
    glScaled(20,20,1);
    glTranslated(0,0,-50);
    glutSolidCube(5);
    glPopMatrix();
    //leftwall
    glPushMatrix();
    glColor3d(0,0,0);
    glScaled(1,20,50);
    glTranslated(-50,0,0);
    glutSolidCube(5);
    glPopMatrix();
    //rearwall
    glPushMatrix();
    glColor3d(1,0,0);
    glScaled(20,20,1);
    glTranslated(0,0,50);
    glutSolidCube(5);
    glPopMatrix();
    //rightwall
    glPushMatrix();
    glColor3d(0,0,0);
    glScaled(1,20,50);
    glTranslated(50,0,0);
    glutSolidCube(5);
    glPopMatrix();


    glPopMatrix();

}
void drawMinion1(){
    //Minion1
    glPushMatrix();
    glTranslated(8,-1.3,0.0);  
    glRotated(90,1,0,0);
    //anime
    glPushMatrix();
    glRotated(upperbody,0,0,1);
    //== Body ==//
    glPushMatrix();
    glColor3f(255,255,0);
    glTranslated(0.0, 0.0, 0.0);
    glScaled(0.6,0.65,0.3);
    glutSolidCylinder(2.0,10.0,20,20);
    glPopMatrix();
    //== head ==//
    glPushMatrix();
    glColor3f(255,255,0);
    glTranslated(0.0, 0.0, 0.0);
    glScaled(0.6,0.65,0.6);
    glutSolidSphere(2.0,20,20);
    glPopMatrix();
    //hair
    glPushMatrix();
    glColor3f(255,255,255);
    glTranslated(-0.5, 0.0, -1.0);
    glScaled(0.01,0.65,0.6);
    glutSolidCube(1.0);
    glPopMatrix();
    //hair
    glPushMatrix();
    glColor3f(255,255,255);
    glTranslated(0.0, 0.0, -1.0);
    glScaled(0.01,0.65,0.6);
    glutSolidCube(1.0);
    glPopMatrix();
    //hair
    glPushMatrix();
    glColor3f(255,255,255);
    glTranslated(0.5, 0.0, -1.0);
    glScaled(0.01,0.65,0.6);
    glutSolidCube(1.0);
    glPopMatrix();
    //right eye
    //goggles
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(0.5, 1.05, 0.4);
    glScaled(0.1,0.12,0.1);
    glutSolidSphere(4.0, 100, 100);
    glPopMatrix();
    // Eye
    glPushMatrix();
    glScaled(1.3,1.3,1.3);
    glTranslated(0.4, -0.8, 0.0);
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(0, 1.8, 0.3);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(3.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glScaled(0.02,0.02,0.04);
    glTranslated(0, 105, 6.5);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    //pop eye
    glPopMatrix();
    //left eye
    //goggles
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(-0.5, 1.05, 0.4);
    glScaled(0.1,0.12,0.1);
    glutSolidSphere(4.0, 100, 100);
    glPopMatrix();
    // Eye
    glPushMatrix();
    glScaled(1.3,1.3,1.3);
    glTranslated(-0.4, -0.8, 0.0);
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(0, 1.8, 0.3);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(3.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glScaled(0.02,0.02,0.04);
    glTranslated(0, 105, 6.5);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    //pop eye
    glPopMatrix();
    //mouth
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glScaled(0.3,0.11,0.3);
    glTranslated(0, 10, 7);
    glRotated(-90,0, 1, 0);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    //teeth
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glScaled(0.15,0.2,0.22);
    glTranslated(0, 5.7, 9);
    glutSolidCube(2.0);
    glPopMatrix();
    // Right Arm Upper
    glPushMatrix();
    glColor3d(255,255,0);
    glTranslated(-1.5, 0.3, 1.0);
    glScaled(1,0.3,0.15);
    glutSolidCube(2.0);
    glPopMatrix();
    // Left Arm Upper
    glPushMatrix();
    glColor3d(255,255,0);
    glTranslated(1.5, 0.3, 1.0);
    glScaled(1,0.3,0.15);
    glutSolidCube(2.0);
    glPopMatrix();
    //Right Leg
    glPushMatrix();
    glColor3d(0,0,1);
    glTranslated(0.5, 0, 4);
    glRotated(90,1,0,0);
    glScaled(0.2,0.9,0.2);
    glutSolidCube(2.0);
    glPopMatrix();
    //left leg
    glPushMatrix();
    glColor3d(0,0,1);
    glTranslated(-0.5, 0, 4);
    glRotated(90,1,0,0);
    glScaled(0.2,0.9,0.2);
    glutSolidCube(2.0);
    glPopMatrix();
    //==footer==//
    glPushMatrix();
    glColor3f(0,0,1);
    glScaled(0.6,0.65,0.5);
    glTranslated(0.0, 0.0, 6.0);
    glutSolidSphere(2.0,20,20);
    glPopMatrix();
    //anime pop
    glPopMatrix();
    //===//
    glPopMatrix();
    //END MINION1
    //===========================//
        //Minion2
    

}
void drawRobin(){
    // main matrix
    glPushMatrix();
    glScaled(0.7,0.7,0.7);
    glTranslated(-6,0,0);
     //headupper
    glPushMatrix();
    glColor3d(234,192,134);
    glScaled(2.4,0.5,3);
    glTranslated(-9.5, 10.9, 1.0);
    glutSolidCube(2);
    glPopMatrix();
    //Mask
    glPushMatrix();
    glColor3d(0,1,0);
    glScaled(2.4,0.7,3);
    glTranslated(-9.5, 6.0, 1.0);
    glutSolidCube(2);
    glPopMatrix();
    //headlower
    glPushMatrix();
    glColor3d(234,192,134);
    glScaled(2.4,1.4,3);
    glTranslated(-9.5, 1.6, 1.0);
    glutSolidCube(2);
    glPopMatrix();
    //right eye
    glPushMatrix();
    glColor3d(234,192,134);
    glScaled(2,1,1);
    glTranslated(-10.8, 4.3, 6.4);
    glutSolidSphere(0.3,1000,10);
    glPopMatrix();
     //left eye
    glPushMatrix();
    glColor3d(234,192,134);
    glScaled(2,1,1);
    glTranslated(-12, 4.3, 6.4);
    glutSolidSphere(0.3,1000,10);
    glPopMatrix();
    //hair
    glPushMatrix();
    glColor3d(0,0,0);
    glScaled(2.4,0.5,3);
    glTranslated(-9.5, 12.5, 1.0);
    glutSolidCube(2);
    glPopMatrix();
    //body
    glPushMatrix();
    glColor3d(1,0,0);
    glScaled(2.9,2,3);
    glTranslated(-7.9, -0.6, 1.0);
    glutSolidCube(2);
    glPopMatrix();
    //right arm
    glPushMatrix();
    glColor3d(0,1,0);
    glScaled(2,0.5,0.5);
    glTranslated(-9, -0.6, 6);
    glutSolidCube(2);
    glPopMatrix();
     //left arm
    glPushMatrix();
    glColor3d(0,1,0);
    glScaled(2,0.5,0.5);
    glTranslated(-14, -0.6, 6);
    glutSolidCube(2);
    glPopMatrix();
    //cape
    glPushMatrix();
    glColor3d(255,255,0);
    glScaled(2,0.5,0.5);
    glTranslated(-11.5, 0.1, 0.2);
    glRotated(90,1,0,0);
    glutSolidCone(2,10,100,100);
    glPopMatrix();
    //left leg
    glPushMatrix();
    glColor3d(0,1,0);
    glScaled(0.5,2,0.5);
    glTranslated(-48, -2.5, 6);
    glutSolidCube(2);
    glPopMatrix();
    //right leg
    glPushMatrix();
    glColor3d(0,1,0);
    glScaled(0.5,2,0.5);
    glTranslated(-43, -2.5, 6);
    glutSolidCube(2);
    glPopMatrix();
    //pop main
    glPopMatrix();
}
void drawMinion2(){
    glPushMatrix();
    glTranslated(3.5, -2.0,0.0);  
    glScaled(0.7,0.7,0.7);
    glRotated(90,90,1,0);
    //anime
    glPushMatrix();
    glRotated(upperbody,1,0,0);
    //== Body ==//
    glPushMatrix();
    glColor3f(255,255,0);
    glTranslated(0.0, 0.0, 0.0);
    glScaled(0.6,0.65,0.3);
    glutSolidCylinder(2.0,10.0,20,20);
    glPopMatrix();
    //== head ==//
    glPushMatrix();
    glColor3f(255,255,0);
    glTranslated(0.0, 0.0, 0.0);
    glScaled(0.6,0.65,0.6);
    glutSolidSphere(2.0,20,20);
    glPopMatrix();
    //hair
    glPushMatrix();
    glColor3f(255,255,255);
    glTranslated(-0.5, 0.0, -1.0);
    glScaled(0.01,0.65,0.6);
    glutSolidCube(1.0);
    glPopMatrix();
    //hair
    glPushMatrix();
    glColor3f(255,255,255);
    glTranslated(0.0, 0.0, -1.0);
    glScaled(0.01,0.65,0.6);
    glutSolidCube(1.0);
    glPopMatrix();
    //hair
    glPushMatrix();
    glColor3f(255,255,255);
    glTranslated(0.5, 0.0, -1.0);
    glScaled(0.01,0.65,0.6);
    glutSolidCube(1.0);
    glPopMatrix();
    //goggles
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glTranslated(0, 1.05, 0.4);
    glScaled(0.1,0.12,0.1);
    glutSolidSphere(4.0, 100, 100);
    glPopMatrix();
    // Eye
    glPushMatrix();
    glScaled(1.3,1.3,1.3);
    glTranslated(00.0, -0.8, 0.0);
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(0, 1.8, 0.3);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(3.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glScaled(0.02,0.02,0.04);
    glTranslated(0, 105, 6.5);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    //pop eye
    glPopMatrix();
    //mouth
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glScaled(0.3,0.11,0.3);
    glTranslated(0, 10, 7);
    glRotated(-90,0, 1, 0);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    //teeth
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glScaled(0.15,0.2,0.22);
    glTranslated(0, 5.7, 9);
    glutSolidCube(2.0);
    glPopMatrix();
    // Right Arm Upper
    glPushMatrix();
    glColor3d(255,255,0);
    glTranslated(-1.5, 0.3, 1.0);
    glScaled(1,0.3,0.15);
    glutSolidCube(2.0);
    glPopMatrix();
    // Left Arm Upper
    glPushMatrix();
    glColor3d(255,255,0);
    glTranslated(1.5, 0.3, 1.0);
    glScaled(1,0.3,0.15);
    glutSolidCube(2.0);
    glPopMatrix();
    //Right Leg
    glPushMatrix();
    glColor3d(1, 0, 0);
    glTranslated(0.5, 0, 4);
    glRotated(90,1,0,0);
    glScaled(0.2,0.9,0.2);
    glutSolidCube(2.0);
    glPopMatrix();
    //left leg
    glPushMatrix();
    glColor3d(1, 0, 0);
    glTranslated(-0.5, 0, 4);
    glRotated(90,1,0,0);
    glScaled(0.2,0.9,0.2);
    glutSolidCube(2.0);
    glPopMatrix();
    //==footer==//
    glPushMatrix();
    glColor3f(1,0,0);
    // glRotated(-90,90,1,0);
    glScaled(0.6,0.65,0.5);
    glTranslated(0.0, 0.0, 6.0);
    glutSolidSphere(2.0,20,20);
    glPopMatrix();
     //anime pop
    glPopMatrix();
    //===//
    glPopMatrix();
    //END MINION2
}
void drawSpongeBob(){
    //main matrix
    glPushMatrix();
    glTranslated(translateSpongebob,0,0);
    //head
    glPushMatrix();
    glColor3d(255,255,0);
    glScaled(1.5,1.7,1.5);
    glTranslated(15, 2.7, 0);
    glutSolidCube(4);
    glPopMatrix();
    //shirt
    glPushMatrix();
    glColor3d(1,1,1);
    glScaled(1.5,0.3,1.5);
    glTranslated(15, 2, 0);
    glutSolidCube(4);
    glPopMatrix();
    //trousers
    glPushMatrix();
    glColor3d(1,0,0);
    glScaled(1.5,0.3,1.5);
    glTranslated(15, -0.7, 0);
    glutSolidCube(4);
    glPopMatrix();
    //left eye
    glPushMatrix();
    glColor3d(1,1,1);
    glScaled(1.5,1.5,1.5);
    glTranslated(14, 4, 2);
    glutSolidSphere(1,1000,100);
    glPopMatrix();
    //right eye
    glPushMatrix();
    glColor3d(1,1,1);
    glScaled(1.5,1.5,1.5);
    glTranslated(16, 4, 2);
    glutSolidSphere(1,1000,100);
    glPopMatrix();
    //left pupil
    glPushMatrix();
    glColor3d(0,0,1);
    glScaled(1,1,1);
    glTranslated(21, 6, 4);
    glutSolidSphere(1,1000,100);
    glPopMatrix();
    //right pupil
    glPushMatrix();
    glColor3d(0,0,1);
    glScaled(1,1,1);
    glTranslated(24, 6, 4);
    glutSolidSphere(1,1000,100);
    glPopMatrix();
    //right shoulder
    glPushMatrix();
    glColor3d(1,1,1);
    glScaled(1,1,1);
    glTranslated(27, 5, 1);
    glRotated(-90,0,1,0);
    glutSolidCone(1,2,1000,100);
    glPopMatrix();
    //left shoulder
    glPushMatrix();
    glColor3d(1,1,1);
    glScaled(1,1,1);
    glTranslated(18, 5, 1);
    glRotated(90,0,1,0);
    glutSolidCone(1,2,1000,100);
    glPopMatrix();
    //right arm
    glPushMatrix();
    glColor3d(255,255,0);
    glScaled(3,0.5,0.5);
    glTranslated(9.5, 10, 1.5);
    glutSolidCube(1);
    glPopMatrix();
    //leftarm
    glPushMatrix();
    glColor3d(255,255,0);
    glScaled(3,0.5,0.5);
    glTranslated(5.5, 10, 1.5);
    glutSolidCube(1);
    glPopMatrix();

    //pop main
    glPopMatrix();
}
void drawGru(){
    //Main Matrix
    glPushMatrix();
    glTranslated(-3,3,0);
    glRotated(90,1,0,0);
    glRotated(angleGru,0,0,1);

    //
    //Head
    glPushMatrix();
    glColor3d(0.858824 , 0.576471, 0.439216);
    glTranslated(0.0, 0.0, 0.0);
    glScaled(0.9,0.9,0.9);
    glutSolidSphere(3,50,50);
    glPopMatrix();
    //Body
    glPushMatrix();
    glColor3d(0,0,0);
    glTranslated(0.0, 0.0, 0.0);
    glScaled(0.9,0.9,0.9);
    glutSolidCone(4,10,10,10);
    glPopMatrix();
    //Right eye
    glPushMatrix();
    glScaled(1.3,1.3,1.3);
    glTranslated(0.8, -0.3, -1.5);
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(0, 1.8, 0.3);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(3.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glScaled(0.02,0.02,0.04);
    glTranslated(0, 105, 6.5);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    //pop eye
    glPopMatrix();
    //left eye
    glPushMatrix();
    glScaled(1.3,1.3,1.3);
    glTranslated(-0.8, -0.3, -1.5);
    // white
    glPushMatrix();
    glColor3d(1.0, 1.0, 1.0);
    glTranslated(0, 1.8, 0.3);
    glScaled(0.08,0.08,0.08);
    glutSolidSphere(3.0, 100, 100);
    glPopMatrix();
    // pupil
    glPushMatrix();
    glColor3d(0.0, 0.0, 0.0);
    glScaled(0.02,0.02,0.04);
    glTranslated(0, 105, 6.5);
    glutSolidSphere(2.0, 100, 100);
    glPopMatrix();
    //pop eye
    glPopMatrix();
    //right brow
    glPushMatrix();
    glColor3d(255,173,96);
    glScaled(0.3,0.1,0.02);
    glTranslated(3, 16, -110);
    glutSolidCube(3.0);
    glPopMatrix();
    //Left brow
    glPushMatrix();
    glColor3d(255,173,96);
    glScaled(0.3,0.1,0.02);
    glTranslated(-3, 16, -110);
    glutSolidCube(3.0);
    glPopMatrix();
    //nose
    glPushMatrix();
    glColor3d(0.858824 , 0.576471, 0.439216);
    glTranslated(0.0, 1.5, -1.0);
    glScaled(0.9,0.9,0.9);
    glRotated(-90,1,0,0);
    glutSolidCone(1,2,100,100);
    glPopMatrix();
    //left arm
    glPushMatrix();
    glColor3d(0,0,0);
    glTranslated(-2.9, -0.5, 4.0);
    glScaled(0.3,0.3,3);
    glutSolidCube(2);
    glPopMatrix();
    //Right arm
    glPushMatrix();
    glColor3d(0,0,0);
    glTranslated(2.9, -0.5, 4.0);
    glScaled(0.3,0.3,3);
    glutSolidCube(2);
    glPopMatrix();
    //
    //floor
    glPushMatrix();
    glColor3d(1 ,0 , 0);
    glTranslated(0, 0, 9.0);
    glScaled(20,20,0);
    glutSolidSphere(4,200,200);
    glPopMatrix();
    //Pop Main Matrix
    glPopMatrix();
    //
}
void drawMickey(){
    //main matrix
    glPushMatrix();
    glTranslated(-6,-2,-3);
    //head
    glPushMatrix();
    glColor3d(234/255.0,192/255.0,134/255.0);
    glTranslated(-10, 5, 4.0);
    glScaled(0.5,0.5,0.5);
    glutSolidSphere(4,200,200);
    glPopMatrix();
    //left ear
    glPushMatrix();
    glColor3d(0 ,0 , 0);
    glTranslated(-12, 7.5, 4.0);
    glScaled(0.3,0.3,0.3);
    glutSolidSphere(4,200,200);
    glPopMatrix();
    //Right ear
    glPushMatrix();
    glColor3d(0 ,0 , 0);
    glTranslated(-8, 7.5, 4.0);
    glScaled(0.3,0.3,0.3);
    glutSolidSphere(4,200,200);
    glPopMatrix();
    //body
    glPushMatrix();
    glColor3d(0 ,0 , 0);
    glTranslated(-10, 2.3, 4);
    glScaled(0.22,0.25,0.2);
    glutSolidCube(9);
    glPopMatrix();
    //bottom
    glPushMatrix();
    glColor3d(1 ,0 , 0);
    glTranslated(-10, 0.5, 4);
    glScaled(0.8,0.8,0.8);
    glutSolidCube(3);
    glPopMatrix();
    //left button
    glPushMatrix();
    glColor3d(255 ,255 , 0);
    glTranslated(-10.5, 1, 5.2);
    glScaled(0.2,0.5,0.2);
    glutSolidSphere(1,100,100);
    glPopMatrix();
    //right button
    glPushMatrix();
    glColor3d(255 ,255 , 0);
    glTranslated(-9.5, 1, 5.2);
    glScaled(0.2,0.5,0.2);
    glutSolidSphere(1,100,100);
    glPopMatrix();
    //right leg
    glPushMatrix();
    glColor3d(0,0,0);
    glTranslated(-9.5, -1, 4);
    glScaled(0.2,0.5,0.2);
    glutSolidCube(2);
    glPopMatrix();
    //left leg
    glPushMatrix();
    glColor3d(0,0,0);
    glTranslated(-10.5, -1, 4);
    glScaled(0.2,0.5,0.2);
    glutSolidCube(2);
    glPopMatrix();
    //left shoes
    glPushMatrix();
    glColor3d(255 ,255 , 0);
    glTranslated(-10.5, -2, 5.2);
    glScaled(0.19,0.2,0.5);
    glutSolidCube(5);
    glPopMatrix();
    //right shoes
    glPushMatrix();
    glColor3d(255 ,255 , 0);
    glTranslated(-9.5, -2, 5.2);
    glScaled(0.19,0.2,0.5);
    glutSolidCube(5);
    glPopMatrix();
  //LEFT arm
    glPushMatrix();
    glTranslated(armMickeyLeft,0,0);
    glPushMatrix();
    glColor3d(0 ,0 , 0);
    glTranslated(-12, 3, 3.5);
    glScaled(1,0.2,0.01);
    glutSolidCylinder(2,100,100,100);
    glPopMatrix();
    //LEFT paw
    glPushMatrix();
    glColor3d(1 ,1 , 1);
    glTranslated(-14, 3, 4);
    glScaled(0.4,0.4,0.55);
    glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();
     //RIGHT arm

        glPushMatrix();
    glTranslated(armMickeyRight,0,0);
    glPushMatrix();
    glColor3d(0 ,0 , 0);
    glTranslated(-8, 3, 3.5);
    glScaled(1,0.2,0.01);
    glutSolidCylinder(2,100,100,100);
    glPopMatrix();
    //right paw
    glPushMatrix();
    glColor3d(1 ,1 , 1);
    glTranslated(-6.3, 3, 4);
    glScaled(0.4,0.4,0.55);
    glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();
    //right eye
    glPushMatrix();
    glColor3d(1 ,1 , 1);
    glTranslated(-9, 5.5, 5.8);
    glScaled(0.8,1.5,0.5);
    glutSolidSphere(0.5,100,100);
    glPopMatrix();
    //right pupil
    glPushMatrix();
    glColor3d(0 ,0 , 0);
    glTranslated(-8.9, 5.5, 6);
    glScaled(0.5,0.5,0.5);
    glutSolidSphere(0.5,100,100);
    glPopMatrix();
    //left eye
    glPushMatrix();
    glColor3d(1 ,1 , 1);
    glTranslated(-10, 5.5, 6);
    glScaled(0.8,1.5,0.5);
    glutSolidSphere(0.5,100,100);
    glPopMatrix();
    //left pupil
    glPushMatrix();
    glColor3d(0 ,0 , 0);
    glTranslated(-9.9, 5.5, 6.2);
    glScaled(0.5,0.5,0.5);
    glutSolidSphere(0.5,100,100);
    glPopMatrix();
    //nose
    glPushMatrix();
    glColor3d(0 ,0 , 0);
    glTranslated(-9.4, 4.3, 6.2);
    glScaled(1,1,1);
    glutSolidSphere(0.5,100,100);
    glPopMatrix();
    
    //pop main
    glPopMatrix();
}
void Reshape(int w, int h)
{

    // Prevent a divide by zero, when window is too short
    if (h == 0)
        h = 1;
    float ratio = 1.0 * w / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45, ratio, 1, 1000);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void SetupLights()
{
    GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7, 1.0f};
    GLfloat mat_diffuse[] = {0.6f, 0.6f, 0.6, 1.0f};
    GLfloat mat_specular[] = {1.0f, 1.0f, 1.0, 1.0f};
    GLfloat mat_shininess[] = {50};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    //set the light source properties
    GLfloat lightIntensity[] = {0.7f, 0.7f, 1, 1.0f};
    GLfloat light_position[] = {-7.0f, 6.0f, 3.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}

void setupCamera()
{
    if(top==1){
    gluLookAt(x, 1.0f, z,
              0.0f, 1.0f, 0.0f,
              0.0, 1.0f, 0.0);
}
else{
       gluLookAt(0, 20.0f, 1,
              0.0f, 1.0f, 0.0f,
              0.0, 1.0f, 0.0);
}
}

void Key(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(EXIT_SUCCESS);
    if(key == 'w'){
        top = 1-top;
    }
    if(key == 's'){
        sceneplay=1-sceneplay;
    }
       if(key == 'm'){
        mickeyplay=1-mickeyplay;
    }
       if(key == 'r'){
        robinplay=1-robinplay;
    }
        if(key=='b'){
            spongeplay=1-spongeplay;
        }
       if(key == 'g'){
        gruplay=1-gruplay;
    }
       if(key == '1'){
        minion1play=1-minion1play;
    }
       if(key == '2'){
        minion2play=1-minion2play;
    }


    // ask OpenGL to recall the display function to reflect the changes on the window
    glutPostRedisplay();
}

void SpecialKeys(int key, int xx, int yy)
{
    float radius = 18.0f;
    switch (key)
    {
    case GLUT_KEY_LEFT:
        angle -= 0.05f;
        x = radius * sin(angle);
        z = radius * cos(angle);
        break;
    case GLUT_KEY_RIGHT:
        angle += 0.05f;
        x = radius * sin(angle);
        z = radius * cos(angle);
        break;
    }

    // ask OpenGL to recall the display function to reflect the changes on the window
    glutPostRedisplay();
}

void Display(void)
{
    //start drawing
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // Setup light
    SetupLights();
    //set the camera
    setupCamera();
    //wall
    drawWall();
    //Models
    glPushMatrix();
    glScaled(0.3, 0.3, 0.3);
    //bezier minion1
    glPushMatrix();
    glTranslated(minion1x,minion1y,0);
    drawMinion1();
    glPopMatrix();
    //bezier minion2
    glPushMatrix();
    glTranslated(minion2x,minion2y,0);
    drawMinion2();
    glPopMatrix();
    drawGru();
    drawMickey();
    //Bezier Robin
    glPushMatrix();
    glTranslated(robinx,robiny+3,0);
    glRotated(90,0,1,0);
    glRotated(60,1,0,0);
    // glRotated(upperbody,0,0,1);
    drawRobin();
    glPopMatrix();

    drawSpongeBob();
    glPopMatrix();

    // glPushMatrix();
    // glTranslated(0,0,-0.3);
    // glScaled(0.35,0.3,0.3);
    // modelMarge();
    // glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    // Initialization
    glutInit(&argc, argv);

    glutInitWindowPosition(50, 50);
    glutInitWindowSize(1980, 1080);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Minions");

    // glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearColor(1, 0, 0, 0.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);

    // Calbacks
    glutDisplayFunc(Display);
    glutKeyboardFunc(Key);
    glutIdleFunc(Anim);
    glutReshapeFunc(Reshape);
    glutSpecialFunc(SpecialKeys);

    glutMainLoop();

    return 0;
}