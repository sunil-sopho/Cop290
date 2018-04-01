#include <construct.h>

void addPoint(point* p,int view)
{

	// glEnable(GL_COLOR_MATERIAL);
	// glDisable(GL_CULL_FACE);
	// adding a point
// cout << p[0].getC(0) <<" : "<<p[0].getC(1)<<" : "<<p[0].getC(2)<<'\n';
	glBegin(GL_POINTS);

	// glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(p[0].getC(0),p[0].getC(1),p[0].getC(2));

	glEnd();
}

void addLine(point* p,int view){


	// glEnable(GL_COLOR_MATERIAL);
	// glDisable(GL_CULL_FACE);

	// adds line
	glBegin(GL_LINES);	
	glColor3f(250.0f,250.0f,250.0f);
	for(int i=0; i<2;i++)
	{
		glVertex3f(p[i].getC(0),p[i].getC(1),p[i].getC(2));
	}

	glEnd();

}

void addTri(point* p,int view){

	// glEnable(GL_COLOR_MATERIAL);
	// glDisable(GL_CULL_FACE);

	// adds line

	if(!view){
		glBegin(GL_TRIANGLES);	

		glColor3f(250.0f,250.0f,250.0f);
		for(int i=0; i<3;i++)
		{
			glVertex3f(p[i].getC(0),p[i].getC(1),p[i].getC(2));
		}

		glEnd();
	}

		glBegin(GL_LINES);
		if(view)
		glColor3f(250.0f,250.0f,250.0f);
		else
		glColor3f(0,0,0);

		for(int i=0; i<3;i++)
		{
			glVertex3f(p[i].getC(0),p[i].getC(1),p[i].getC(2));
			glVertex3f(p[(i+1)%3].getC(0),p[(i+1)%3].getC(1),p[(i+1)%3].getC(2));
		}

		glEnd();
}

void addPlane(point* p,int view){

	// glEnable(GL_COLOR_MATERIAL);
	// glDisable(GL_CULL_FACE);

	// adds line
	if(!view){
		glBegin(GL_QUADS);	
		glColor3f(250.0f,250.0f,250.0f);
		for(int i=0; i<4;i++)
		{
			glVertex3f(p[i].getC(0),p[i].getC(1),p[i].getC(2));
		}
		glEnd();
	}
	
		glBegin(GL_LINES);
		if(view)
		glColor3f(250.0f,250.0f,250.0f);
		else
		glColor3f(0,0,0);

		for(int i=0; i<4;i++)
		{
			glVertex3f(p[i].getC(0),p[i].getC(1),p[i].getC(2));
			glVertex3f(p[(i+1)%4].getC(0),p[(i+1)%4].getC(1),p[(i+1)%4].getC(2));
		}

		glEnd();
	
}
