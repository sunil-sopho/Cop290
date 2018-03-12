/*
Author - Sunil Kumar
gitid - sunil-sopho
Projectname - CAD
*/


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h> // image importing utilities>
#include "stdio.h"
#include "math.h" // for basic mathematic functions
#include "stdlib.h"
#include "string.h"
#include  <bits/stdc++.h>
#include "node.h"
#include "keys.h"
// #include "cube.h"
#include "printtxt.h"
#include "buttons.h"
#include <vector> 
#include "construct.h"
#include "project.h"
using namespace std;
	std::vector<node> v;
	SDL_Window *screen;
	SDL_Rect rect1,rect2;
	SDL_Renderer *rend1;
	SDL_Texture *text1, *text2;
	char *font_path = "FreeSans.ttf"; ;
	TTF_Font *font;
#include "draw.h"
#include "clicks.h"
// void Drawscene();
// void Drawscene2();
// void Drawscene3();
// void Drawscene4();

void establishMatrix(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

// differnt matrix for different views 
void establishMatrix2(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL2(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

void establishMatrix3(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL3(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

void establishMatrix4(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL4(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

const Uint8 *keys = NULL;
int x,y;
// main
int main(int argc, char ** argv)
{
	// loadbuttons();
	if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
		{
			cout <<"error\n"	;
		}
		///cout <<"1\n";
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);

	// strcpy(font_path ,"FreeSans.ttf".c_str());


	SDL_CreateWindowAndRenderer(1024, 610, 0, &screen, &rend1);
    TTF_Init();
    font = TTF_OpenFont(font_path, 24);

   
	// screen = SDL_CreateWindow("CAD", 200,200,1024,610,SDL_WINDOW_OPENGL);
	
	// SDL_GLContext context = SDL_GL_CreateContext(screen);
	// SDL_GL_MakeCurrent(screen, context);

	int done = 0;
	while(!done)\
	{
		
		// main viewport for 2D
		initGL(320,0,340,300);
		Drawscene();

		//viewport for 3D projection
		initGL2(320,320,680,300);
		Drawscene2();

		initGL3(680,0,340,300);
		Drawscene3();

		// // sidebar 
		initGL4(20,0,280,610);
		Drawscene4();
 // printo(rend, 199, 20, "--|--|", font, &text1, &rect1);
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{	
			if (event.type == SDL_QUIT)
			{
				// cout << event <<'\n' << event.type;
				cout <<"quiting was here";
				done =1 ;
			}
			if(event.type == SDL_MOUSEMOTION)
			{
				SDL_GetMouseState(&x,&y);
			}
			if(event.type == SDL_MOUSEBUTTONDOWN)
			{
				clicks(x,y);
			}
			if(save)
			{
				int height = 610;
				int width = 1024;

				std::vector<unsigned char> v(width*height*3);

				glPixelStorei(GL_PACK_ALIGNMENT,1);
				for(int i=0;i<height;i++)
				glReadPixels(0,height-1- i,width,1,GL_RGB,GL_UNSIGNED_BYTE,&v[i*width*3]);

				// reverse(v.begin(),v.end());

				int err = SOIL_save_image(
					"mycad.bmp",
					SOIL_SAVE_TYPE_BMP ,
					width,
					height,
					3,
					&v[0]
					);
				save = false;
				// done = 1;
			}
			keys = SDL_GetKeyboardState(NULL);

			SDL_SetRenderDrawColor(rend1, 0, 0, 0, 0);
	        SDL_RenderClear(rend1);
	        /* Use TTF textures. */
	        SDL_RenderCopy(rend1, text1, NULL, &rect1);
	        SDL_RenderCopy(rend1, text2, NULL, &rect2);
	        SDL_RenderPresent(rend1);
		}
		SDL_GL_SwapWindow(screen);

		if(checkKeys(keys))
			done = 1 ;
	}
	// SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(screen);
	SDL_Quit();
	return 0;
}

void establishMatrix(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
	glOrtho(-3.0,3.0,-3.0,3.0,-3.0,200.0);
}

void initGL(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.80f,0.70f,0.90f,1.0f);

	// glEnable(GL_DEPTH_TEST);
	// glDepthFunc(GL_LEQUAL);
	// glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	// glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}	





void establishMatrix2(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
}

void initGL2(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix2(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.00f,0.70f,0.20f,1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}	

void establishMatrix3(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
}

void initGL3(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix3(lx,ly,width,height);

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

void establishMatrix4(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
}

void initGL4(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix4(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.50f,0.90f,0.10f,1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}	

