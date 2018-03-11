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

	cube();
	glPopMatrix();
	glFlush();
}

int Drawscene4()
{
	glEnable(GL_COLOR_MATERIAL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(0.4f,1.8f,-5.0f);
 // printo(rend, 0, 0, "hello", font, &text1, &rect1);
	// glBindTexture(GL_TEXTURE_2D, minusX)
	// glEnable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);

	glColor3f(100.0f,100.0f,100.0f);
	glTexCoord2d(0,0);
	glVertex3f(0.15f,0.15f,0.15f);
	glTexCoord2d(1,0);
	glVertex3f(-0.15f,0.15f,0.15f);
	glTexCoord2d(1,1);
	glVertex3f(-0.15f,-0.15f,0.15f);
	glTexCoord2d(0,1);
	glVertex3f(0.15f,-0.15f,0.15f);
	glEnd();
	glPopMatrix();

	// glPushMatrix();

}