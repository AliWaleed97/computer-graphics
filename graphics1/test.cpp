
#include <GL/glut.h>
#include <GL/gl.h>
#include <cstdio>
#include <random>
#include <string.h>
#include <stdio.h>


bool up = true;
bool down = false;
int keyX = 800;
int keyY = 600;
int angle = 0;
int keyC = 0;
int zigzag = 800;
int touched = 0;
int speX=0;
int speY=0;
int speC=0;
int transX=2010;
float powX = 1500;
int powY = rand() % 800 + 200;
float obsX=1900;
int obsY=rand() % 800 + 200;
float obs1X = 2000;
int obs1Y = rand() % 800 + 200;
float obs2X = 2000;
int obs2Y = rand() % 800 + 200;
int counter =0;
int move = 0;
int p0[] = {6, 326};
int p1[] = {31, 560};
int p2[] = {356, 0};
int p3[] = {700, 104};
int O0[] = {110, 920};
int O1[] = {980, -1760};
int O2[] = {800, 2810};
int O3[] = {1770,-20};
float t = 1.0f;

void bezier(float t, int* p0,int* p1,int* p2,int* p3){
	obs1X=pow((1-t),3)*p0[0]+3*t*pow((1-t),2)*p1[0]+3*pow(t,2)*(1-t)*p2[0]+pow(t,3)*p3[0];
	obs1Y=pow((1-t),3)*p0[1]+3*t*pow((1-t),2)*p1[1]+3*pow(t,2)*(1-t)*p2[1]+pow(t,3)*p3[1];
	powX=pow((1-t),3)*O0[0]+3*t*pow((1-t),2)*O1[0]+3*pow(t,2)*(1-t)*O2[0]+pow(t,3)*O3[0];
	powY=pow((1-t),3)*O0[1]+3*t*pow((1-t),2)*O1[1]+3*pow(t,2)*(1-t)*O2[1]+pow(t,3)*O3[1];

}
void translateObsX(){	
	if(zigzag>=400){
		zigzag--;
		obs2Y++;
		if(obs2Y>=1200){
			obs2Y--;
		}
	}else if(zigzag!=0){
		zigzag--;
		obs2Y--;
		if(obs2Y<=0){
			obs2Y++;
		}
	}
	obs2X-=0.5;
	if(zigzag==0){
		zigzag=800;
		
	}
	obsX-=0.6;
	obs1X-=0.3;
	powX-=0.3;
	if(transX<-4000)
		transX = 2000;
	transX--;
	//OBS1
	if (obsX<=0){
		if(counter<4){
		obsX= -1000;
		obsY=rand() % 1000 + 200;
		}else{
			counter=0;
			obsX=1900;
			obsY=rand() % 1000 + 200;
		}
	}
	if (obsY<=keyY+400 && obsY >=keyY){
			if(obsX+150<=keyX+225 && obsX >= keyX+60){
				// sndPlaySound("sound filename.extension",SND_ASYNC);
				keyX += 300;
	 			obsX = -1000;
	 			obsY = rand() % 1000 + 200;
	 		}
		}
		// end OBS1
	// if (powX<=0){
	// 	counter++;
	// 	powX= 1900;
	// 	powY=rand() % 1000 + 200;
	// }
	if(t > 0) {
		bezier(t, O0, O1, O2, O3);
		t-=0.00001;
	} else {
		t = 8;	
		counter++;
	}
	if ( powY<=keyY+400 && powY >=keyY){
		if( powX+150<=keyX+255 && powX >= keyX+60){
			keyX -= 300; 
			counter++;
			t=8;
			powX = 1900;
			powY = rand() % 1000 + 200;
		}
	}

	if(t > 0) {
		bezier(t, p0, p1, p2, p3);
		t-=0.0006;
	} else {
		counter++;
		t = 6;	
	}
	if ( obs1Y<=keyY+400 && obs1Y >=keyY){
		if( obs1X+150<=keyX+255 && obs1X >= keyX+60){
			counter++;
			keyX -= 300;
			t = 6;
		}
	}
		if (obs2X<=0){
			counter++;
			obs2X= 3500;
			obs2Y=rand() % 1000 + 200;
	}

	if ( obs2Y<=keyY+400 && obs2Y >=keyY){
		if( obs2X+150<=keyX+255 && obs2X >= keyX+60){
			counter++;
			keyX -= 300; 
			obs2X = 3500;
			obs2Y = rand() % 1000 + 200;
		}
	}
	glutPostRedisplay();//redisplay to update the screen with the changes
}
//keyboard function, takes 3 parameters
// k is the key pressed from the keyboard
// x and y are mouse postion when the key was pressed.
void key(unsigned char k, int x,int y){
	if(k=='w')//if the letter w is pressed, then the object will be translated in the y axis by 10. (moving upwords)
		if(keyY+410>1200){
		}else{
		keyY+=10;
		angle+=30;
	}
	if(k=='s')//if the letter w is pressed, then the object will be translated in the y axis by -10. (moving downwords)
		if(keyY<=0){
		}else{
		keyY-=10;
		angle-=30;
}
	glutPostRedisplay();//redisplay to update the screen with the changes
}
// keyboard special key function takes 3 parameters	
// int k: is the special key pressed such as the keyboard arrows the f1,2,3 and so on
void spe(int k, int x,int y){
	//if the up arrow is pressed, then the object will be translated in the y axis by 10. (moving upwords)
	if(k==GLUT_KEY_UP)
		speY+=20;
	if(k==GLUT_KEY_DOWN)//if the down arrow is pressed, then the object will be translated in the y axis by -10. (moving downwords)
		speY-=20;
	glutPostRedisplay();//redisplay to update the screen with the changes
}

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(1,1,10);
	glTranslated(transX,0,0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(2000.0f, 1300.0f, 0.0f);
	glVertex3f(2000.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1300.0f, 0.0f);
	glEnd();
	glPopMatrix();

	  glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(1,0,0);
	glTranslated(transX,0,0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(100.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 800.0f, 0.0f);
	glVertex3f(200.0f, 800.0f, 0.0f);
	glVertex3f(200.0f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(1,0,0);
	glTranslated(transX,0,0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(700.0f, 1200.0f, 0.0f);
	glVertex3f(700.0f, 800.0f, 0.0f);
	glVertex3f(800.0f, 800.0f, 0.0f);
	glVertex3f(800.0f, 1200.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(1,0,0);
	glTranslated(transX,0,0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(1200.0f, 0.0f, 0.0f);
	glVertex3f(1200.0f, 800.0f, 0.0f);
	glVertex3f(1300.0f, 800.0f, 0.0f);
	glVertex3f(1300.0f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(1,0,0);
	glTranslated(transX,0,0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(1700.0f, 1200.0f, 0.0f);
	glVertex3f(1700.0f, 800.0f, 0.0f);
	glVertex3f(1800.0f, 800.0f, 0.0f);
	glVertex3f(1800.0f, 1200.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(1,1,1);
	glTranslated(transX,0,0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(2300.0f, 1200.0f, 0.0f);
	glVertex3f(2300.0f, 800.0f, 0.0f);
	glVertex3f(2400.0f, 800.0f, 0.0f);
	glVertex3f(2400.0f, 1200.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(1,1,1);
	glTranslated(transX,0,0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(3500.0f, 0.0f, 0.0f);
	glVertex3f(3500.0f, 800.0f, 0.0f);
	glVertex3f(3600.0f, 800.0f, 0.0f);
	glVertex3f(3600.0f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();

		glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(1,1,1);
	glTranslated(transX,0,0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(4000.0f, 1200.0f, 0.0f);
	glVertex3f(4000.0f, 800.0f, 0.0f);
	glVertex3f(4100.0f, 800.0f, 0.0f);
	glVertex3f(4100.0f, 1200.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(1,keyC,1);
	glTranslated(keyX,keyY,0);
  	glBegin(GL_LINES); // GL_LINE_STRIP, GL_LINE_LOOP
  	glColor3f(0.0f, 0.0f, 0.0f);
  	glVertex3f(100.0f, 220.0f, 0.0f);
  	glVertex3f(75.0f, 220.0f, 0.0f);
    glVertex3f(100.0f, 180.0f, 0.0f);
  	glVertex3f(75.0f, 180.0f, 0.0f);
  	glEnd();
  
	  glBegin(GL_POLYGON);
	  glColor3f(0.0f, 0.0f, 0.0f);
	  glVertex3f(100.0f, 100.0f, 0.0f);
	  glVertex3f(100.0f, 300.0f, 0.0f);
	  glVertex3f(150.0f, 300.0f, 0.0f);
	  glVertex3f(200.0f, 250.0f, 0.0f);
	  glVertex3f(200.0f, 150.0f, 0.0f);
	  glVertex3f(150.0f, 100.0f, 0.0f);
	  glEnd();


	  glBegin(GL_TRIANGLES); // GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
	  glColor3f(0.0f, 0.0f, 0.0f);
	  glVertex3f(200.0f, 250.0f, 0.0f);
	  glVertex3f(200.0f, 210.0f, 0.0f);
	  glVertex3f(225.0f, 230.0f, 0.0f);

	  glVertex3f(200.0f, 150.0f, 0.0f);
	  glVertex3f(200.0f, 190.0f, 0.0f);
	  glVertex3f(225.0f, 170.0f, 0.0f);

	  glVertex3f(100.0f, 300.0f, 0.0f);
	  glVertex3f(125.0f, 400.0f, 0.0f);
	  glVertex3f(150.0f, 300.0f, 0.0f);
	  
	  glVertex3f(100.0f, 100.0f, 0.0f);
	  glVertex3f(125.0f, 0.0f, 0.0f);
	  glVertex3f(150.0f, 100.0f, 0.0f);
	  
	  glVertex3f(75.0f, 150.0f, 0.0f);
	  glVertex3f(75.0f, 250.0f, 0.0f);
	  glVertex3f(60.0f, 200.0f, 0.0f);
	  glEnd();

	  glBegin(GL_LINES); // GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN
	  glColor3f(1.0f, 0.0f, 0.0f);
	  glVertex3f(62.0f, 210.0f, 0.0f);
	  glVertex3f(40.0f, 210.0f, 0.0f);
	   glVertex3f(62.0f, 190.0f, 0.0f);
	  glVertex3f(40.0f, 190.0f, 0.0f);
	  glEnd();
  	  glPopMatrix();

	glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(0.30,0.50,0);
	glTranslated(obsX,0,0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(100.0f, obsY, 0.0f);
	glVertex3f(100.0f, obsY+50, 0.0f);
	glVertex3f(120.0f, obsY+50, 0.0f);
	glVertex3f(120.0f, obsY, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(1,1,0);
	glTranslated(obs1X,0,0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(100.0f, obs1Y, 0.0f);
	glVertex3f(100.0f, obs1Y+50, 0.0f);
	glVertex3f(120.0f, obs1Y+50, 0.0f);
	glVertex3f(120.0f, obs1Y, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(1,1,0);
	glTranslated(obs2X,0,0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(100.0f, obs2Y, 0.0f);
	glVertex3f(100.0f, obs2Y+50, 0.0f);
	glVertex3f(120.0f, obs2Y+50, 0.0f);
	glVertex3f(120.0f, obs2Y, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(1,1,0);
	glTranslated(powX,0,0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(100.0f, powY, 0.0f);
	glVertex3f(100.0f, powY+50, 0.0f);
	glVertex3f(120.0f, powY+50, 0.0f);
	glVertex3f(120.0f, powY, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(0,1,0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(1900.0f, 0.0f, 0.0f);
	glVertex3f(1900.0f, 1200.0f, 0.0f);
	glVertex3f(2000.0f, 1200.0f, 0.0f);
	glVertex3f(2000.0f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();

	if(keyX==-100){
    glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(2000.0f, 1300.0f, 0.0f);
	glVertex3f(2000.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1300.0f, 0.0f);
	glEnd();
	glPopMatrix();
  }
    if(keyX==1700){
   	glPushMatrix();  //draws a magenta pixel @ 10,120
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_QUADS); // GL_QUAD_STRIP
	glVertex3f(2000.0f, 1300.0f, 0.0f);
	glVertex3f(2000.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1300.0f, 0.0f);
	glEnd();
	glPopMatrix();
    }

    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(2000, 1200);
    glutInitWindowPosition(300, 50);
    glutCreateWindow("Willy's Game");
    glClearColor(1.0f,0.0f,0.0f,0.0f);
    glutDisplayFunc(displayMe);
    glutKeyboardFunc(key);				
    glutIdleFunc(translateObsX);				
    gluOrtho2D(0.0, 2000.0, 0.0, 1200.0);
    glutMainLoop();
    return 0;
}
