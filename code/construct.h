#include "point.h"

void addPoint(point* p)
{
	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_CULL_FACE);
	// adding a point

	glBegin(GL_POINTS);

	glColor3f(0.0f,0.0f,0.0f);
	glVertex(p[0].getC[0],p[0].getC[1],p[0].getC[2]);

	glEnd();
}

void addLine(point* p){

	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_CULL_FACE);

	// adds line
	glBegin(GL_LINES);	
	glColor3f(0.0f,0.0f,0.0f);
	for(int i=0; i<2;i++)
	{
		glVertex(p[i].getC[0],p[i].getC[1],p[i].getC[2]);
	}

	glEnd();

}

void addTri(point* p){

	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_CULL_FACE);

	// adds line
	glBegin(GL_TRIANGLES);	

	glColor3f(0.0f,0.0f,0.0f);
	for(int i=0; i<3;i++)
	{
		glVertex(p[i].getC[0],p[i].getC[1],p[i].getC[2]);
	}

	glEnd();
}

void addPlane(point* p){

	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_CULL_FACE);

	// adds line
	glBegin(GL_QUADS);	
	glColor3f(0.0f,0.0f,0.0f);
	for(int i=0; i<4;i++)
	{
		glVertex(p[i].getC[0],p[i].getC[1],p[i].getC[2]);
	}
	glEnd();
}