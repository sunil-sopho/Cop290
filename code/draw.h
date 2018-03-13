// #include <GL/gl.h>
// #include <GL/glu.h>
#include "cube.h"
// Draw scene for all viewports
void Drawscene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// cube();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0,0,-10.0f);

updateView();
	linec();

	// cube();
	glPopMatrix();
	glFlush();
}
void Drawscene2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// cube();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	cube();
	glFlush();
}
void Drawscene3()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0,0,-10.0f);

	// cube();
	updateView();
	Project(v);
	glPopMatrix();
	glFlush();
}

// const int font1 = (int)GLUT_BITMAP_9_BY_15;
// void output(char *s)
// {
// 	char *c;
// 	glColor3f(255,0,0);
// 	glRasterPos2f(1.4,0);
// 	// char *s = (char*)malloc(sizeof(char)*10);
// 	// s = "hithere";
// 	for(c=s;*c !='\0';c++)
// 	{
// 		glutBitmapCharacter((void*)font1,*c);
// 	} 
// }

int Drawscene4()
{
	glEnable(GL_COLOR_MATERIAL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
 // printo(rend, 199, 20, "--|--|", font, &text1, &rect1);
	glPushMatrix();
	glTranslatef(2.4f,7.0f,-20.0f);

	// char s[] = {'s','u','n','i','l','k','u','m','\0'};

	// output("hithere\0");
	// glBindTexture(GL_TEXTURE_2D, minusm);
	// glEnable(GL_TEXTURE_2D);
	// glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
 //              GL_UNSIGNED_BYTE, image);
// cout << minusm <<'\n';
	glBegin(GL_QUADS);

	glColor3f(100.0f,100.0f,100.0f);
	glTexCoord2d(0,0);
	glVertex3f(0.6f,0.6f,0.6f);
	glTexCoord2d(1,0);
	glVertex3f(-0.6f,0.6f,0.6f);
	glTexCoord2d(1,1);
	glVertex3f(-0.6f,-0.6f,0.6f);
	glTexCoord2d(0,1);
	glVertex3f(0.6f,-0.6f,0.6f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.4f, 5.5f,-20.0f);

	// glBindTexture(GL_TEXTURE_2D, minusm);
	// glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	glColor3f(100.0f,100.0f,100.0f);
	glTexCoord2d(0,0);
	glVertex3f(0.6f,0.6f,0.6f);
	glTexCoord2d(1,0);
	glVertex3f(-0.6f,0.6f,0.6f);
	glTexCoord2d(1,1);
	glVertex3f(-0.6f,-0.6f,0.6f);
	glTexCoord2d(0,1);
	glVertex3f(0.6f,-0.6f,0.6f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.4f,4.0f,-20.0f);

	// glBindTexture(GL_TEXTURE_2D, minusm);
	// glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	glColor3f(100.0f,100.0f,100.0f);
	glTexCoord2d(0,0);
	glVertex3f(0.6f,0.6f,0.6f);
	glTexCoord2d(1,0);
	glVertex3f(-0.6f,0.6f,0.6f);
	glTexCoord2d(1,1);
	glVertex3f(-0.6f,-0.6f,0.6f);
	glTexCoord2d(0,1);
	glVertex3f(0.6f,-0.6f,0.6f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.4f,2.5f,-20.0f);

	// glBindTexture(GL_TEXTURE_2D, minusm);
	// glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	glColor3f(100.0f,100.0f,100.0f);
	glTexCoord2d(0,0);
	glVertex3f(0.6f,0.6f,0.6f);
	glTexCoord2d(1,0);
	glVertex3f(-0.6f,0.6f,0.6f);
	glTexCoord2d(1,1);
	glVertex3f(-0.6f,-0.6f,0.6f);
	glTexCoord2d(0,1);
	glVertex3f(0.6f,-0.6f,0.6f);
	glEnd();
	glPopMatrix();

// button
	glPushMatrix();
	glTranslatef(-2.0f,7.0f,-20.0f);

	// glBindTexture(GL_TEXTURE_2D, minusm);
	// glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	glColor3f(100.0f,100.0f,100.0f);
	glTexCoord2d(0,0);
	glVertex3f(0.6f,0.6f,0.6f);
	glTexCoord2d(1,0);
	glVertex3f(-0.6f,0.6f,0.6f);
	glTexCoord2d(1,1);
	glVertex3f(-0.6f,-0.6f,0.6f);
	glTexCoord2d(0,1);
	glVertex3f(0.6f,-0.6f,0.6f);
	glEnd();
	glPopMatrix();


//button 
	glPushMatrix();
	glTranslatef(-2.0f,5.5f,-20.0f);

	// glBindTexture(GL_TEXTURE_2D, minusm);
	// glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	glColor3f(100.0f,100.0f,100.0f);
	glTexCoord2d(0,0);
	glVertex3f(0.6f,0.6f,0.6f);
	glTexCoord2d(1,0);
	glVertex3f(-0.6f,0.6f,0.6f);
	glTexCoord2d(1,1);
	glVertex3f(-0.6f,-0.6f,0.6f);
	glTexCoord2d(0,1);
	glVertex3f(0.6f,-0.6f,0.6f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.0f,4.0f,-20.0f);

	// glBindTexture(GL_TEXTURE_2D, minusm);
	// glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	glColor3f(100.0f,100.0f,100.0f);
	glTexCoord2d(0,0);
	glVertex3f(0.6f,0.6f,0.6f);
	glTexCoord2d(1,0);
	glVertex3f(-0.6f,0.6f,0.6f);
	glTexCoord2d(1,1);
	glVertex3f(-0.6f,-0.6f,0.6f);
	glTexCoord2d(0,1);
	glVertex3f(0.6f,-0.6f,0.6f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.0f,2.5f,-20.0f);

	// glBindTexture(GL_TEXTURE_2D, minusm);
	// glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	glColor3f(100.0f,100.0f,100.0f);
	glTexCoord2d(0,0);
	glVertex3f(0.6f,0.6f,0.6f);
	glTexCoord2d(1,0);
	glVertex3f(-0.6f,0.6f,0.6f);
	glTexCoord2d(1,1);
	glVertex3f(-0.6f,-0.6f,0.6f);
	glTexCoord2d(0,1);
	glVertex3f(0.6f,-0.6f,0.6f);
	glEnd();
	glPopMatrix();

}