// #include "cube.h"

void messinit()
{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// cube();
		// updateView();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-10.0f);
	glScalef(ScaleFactor,ScaleFactor,ScaleFactor);
	glRotatef(cubeRotateY,0,1,0);
	glRotatef(cubeRotateX,1,0,0);

	// cout << cubeRotateX <<" : "<<cubeRotateY <<" : "<<ScaleFactor<<'\n';// 12 -41 0.34
		glBegin(GL_LINES);
		for(int i=0;i<100;i++)
		{
			glVertex3f(i,0,0);
			glVertex3f(i,100.0f,0);

			glVertex3f(i,0,0);
			glVertex3f(i,0,100);

			glVertex3f(0,i,0);
			glVertex3f(0,i,100);

			glVertex3f(0,i,0);
			glVertex3f(100,i,0);

			glVertex3f(0,0,i);
			glVertex3f(100,0,i);

			glVertex3f(0,0,i);
			glVertex3f(0,100,i);

		}
		glEnd();

			glBegin(GL_QUADS);
	//TOP
	// glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(0.10f+lx,0.10f+ly,-0.10f+lz);
	glVertex3f(-0.10f+lx,0.10f+ly,-0.10f+lz);
	glVertex3f(-0.10f+lx,0.10f+ly,0.10f+lz);
	glVertex3f(0.10f+lx,0.10f+ly,0.10f+lz);

	//BOTTOM
	// glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(0.10f+lx,-0.10f+ly,-0.10f+lz);
	glVertex3f(-0.10f+lx,-0.10f+ly,-0.10f+lz);
	glVertex3f(-0.10f+lx,-0.10f+ly,0.10f+lz);
	glVertex3f(0.10f+lx,-0.10f+ly,0.10f+lz);

	//FRONT
	// glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(0.10f+lx,0.10f+ly,0.10f+lz);
	glVertex3f(-0.10f+lx,0.10f+ly,0.10f+lz);
	glVertex3f(-0.10f+lx,-0.10f+ly,0.10f+lz);
	glVertex3f(0.10f+lx,-0.10f+ly,0.10f+lz);

	//BACK
	// glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(0.10f+lx,0.10f+ly,-0.10f+lz);
	glVertex3f(-0.10f+lx,0.10f+ly,-0.10f+lz);
	glVertex3f(-0.10f+lx,-0.10f+ly,-0.10f+lz);
	glVertex3f(0.10f+lx,-0.10f+ly,-0.10f+lz);

	//LEFT
	// glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(-0.10f+lx,0.10f+ly,0.10f+lz);
	glVertex3f(-0.10f+lx,0.10f+ly,-0.10f+lz);
	glVertex3f(-0.10f+lx,-0.10f+ly,-0.10f+lz);
	glVertex3f(-0.10f+lx,-0.10f+ly,0.10f+lz);

	//RIGHT
	// glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(0.10f+lx,0.10f+ly,0.10f+lz);
	glVertex3f(0.10f+lx,0.10f+ly,-0.10f+lz);
	glVertex3f(-0.10f+lx,-0.10f+ly,-0.10f+lz);
	glVertex3f(0.10f+lx,-0.10f+ly,-0.10f+lz);


	glEnd();
		glTranslatef(0,0,-100.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

	// glPushMatrix();
	
		// glPopMatrix();
	// glFlush();
}