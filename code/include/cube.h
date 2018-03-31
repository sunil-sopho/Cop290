// #include <GL/gl.h>
// #include <GL/glu.h>
// #include <GL/glut.h>
void updateView(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-10.0f);
	glScalef(ScaleFactor,ScaleFactor,ScaleFactor);
	glRotatef(cubeRotateY,0,1,0);
	glRotatef(cubeRotateX,1,0,0);
}

void cube(){

	updateView();
	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_CULL_FACE);

	glBegin(GL_QUADS);
	//TOP
	// glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,1.0f,1.0f);
	glVertex3f(1.0f,1.0f,1.0f);

	//BOTTOM
	// glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,1.0f);
	glVertex3f(1.0f,-1.0f,1.0f);

	//FRONT
	// glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(1.0f,1.0f,1.0f);
	glVertex3f(-1.0f,1.0f,1.0f);
	glVertex3f(-1.0f,-1.0f,1.0f);
	glVertex3f(1.0f,-1.0f,1.0f);

	//BACK
	// glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(1.0f,-1.0f,-1.0f);

	//LEFT
	// glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(-1.0f,1.0f,1.0f);
	glVertex3f(-1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,1.0f);

	//RIGHT
	// glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(1.0f,1.0f,1.0f);
	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(1.0f,-1.0f,-1.0f);


	glEnd();

}

void linec(){
	// updateView();
	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_CULL_FACE);

	glBegin(GL_LINES);
	glVertex3f(1.0f,1.0f,1.0f);
	glVertex3f(-1.0f,1.0f,1.0f);

	glVertex3f(1.0f,1.0f,1.0f);
	glVertex3f(1.0f,-1.0f,1.0f);

	glVertex3f(1.0f,1.0f,1.0f);
	glVertex3f(1.0f,1.0f,-1.0f);

	glVertex3f(-1.0f,1.0f,1.0f);
	glVertex3f(-1.0f,1.0f,-1.0f);

	glVertex3f(-1.0f,1.0f,1.0f);
	glVertex3f(-1.0f,-1.0f,1.0f);

	glVertex3f(-1.0f,-1.0f,1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);

	glVertex3f(-1.0f,-1.0f,1.0f);
	glVertex3f(1.0f,-1.0f,1.0f);

	glVertex3f(1.0f,1.0f,1.0f);
	glVertex3f(1.0f,1.0f,-1.0f);

	glVertex3f(1.0f,-1.0f,1.0f);
	glVertex3f(1.0f,-1.0f,-1.0f);

	glVertex3f(1.0f,1.0f,-1.0f);
	glVertex3f(1.0f,-1.0f,-1.0f);

	glVertex3f(1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,-1.0f,-1.0f);

	glVertex3f(-1.0f,-1.0f,-1.0f);
	glVertex3f(-1.0f,1.0f,-1.0f);

	glVertex3f(-1.0f,1.0f,-1.0f);
	glVertex3f(1.0f,1.0f,-1.0f);

	glEnd();
}

void addLine(){
	
}