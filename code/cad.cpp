#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
//#include "soil.h" // image importing utilities>
#include "stdio.h"
#include "math.h" // for basic mathematic functions
#include "stdlib.h"
#include "string.h"
#include  <bits/stdc++.h>
using namespace std;

SDL_Window *screen;

void Drawscene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

void establishMatrix(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);


int main(int argc, char ** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);

	screen = SDL_CreateWindow("CAD", 200,200,1024,610,SDL_WINDOW_OPENGL);
	
	SDL_GLContext context = SDL_GL_CreateContext(screen);
	SDL_GL_MakeCurrent(screen, context);

	int done = 0;
	while(!done)\
	{
		// done++;
		initGL(0,0,1024,610);
		Drawscene();
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{	
			if (event.type == SDL_QUIT)
			{
				// cout << event <<'\n' << event.type;
				cout <<"quiting was here";
				done =1 ;
			}
		}
		SDL_GL_SwapWindow(screen);
	}
	SDL_DestroyWindow(screen);
	SDL_Quit();
	return 0;
}

void establishMatrix(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
}

void initGL(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.80f,0.70f,0.90f,1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}	
