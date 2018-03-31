/*
Author - Sunil Kumar
gitid - sunil-sopho
Projectname - CAD
*/


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h> // image importing utilities>
#include "stdio.h"
#include "math.h" // for basic mathematic functions
#include "stdlib.h"
#include "string.h"
#include  <bits/stdc++.h>
#include <vector> 
#include "node.h"
using namespace std;
	std::vector<node> v;
	SDL_Window *screen,*screen2;
	SDL_Rect rect1,rect2;
	SDL_Renderer *rend1,*rend2;
	SDL_Texture *text1, *text2;
	char *font_path = "FreeSans.ttf"; ;
	TTF_Font *font;
	int done = 0;
const Uint8 *keys = NULL;
#include "standardHandler.h"
// #include "window.h"
#include "keys.h"
// #include "cube.h"
#include "printtxt.h"
#include "buttons.h"

#include "construct.h"
#include "project.h"


#include "draw.h"
#include "messNet.h"
#include "clicks.h"
#include "Ltexture.h"

std::vector<window> win(4);

LTexture gTexture;


void establishMatrix(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

// differnt matrix for different views 
void establishMatrix2(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL2(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

void establishMatrix3(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL3(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

void establishMatrix4(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL4(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

void establishMatrix5(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL5(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);




// main
int main(int argc, char ** argv)
{

	if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
	{
			cout <<"error\n"	;
	}
	
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);

	win[0].init();
    TTF_Init();
    font = TTF_OpenFont(font_path, 24);

 
	
	while(!done)
	{

		// main viewport for 2D
		// if(numScreen <= 0)
		// {
		win[0].makeCurrent();
			initGL(320,0,340,300);
			Drawscene();

			//viewport for 3D projection
			initGL2(320,320,680,300);
			Drawscene2();

			initGL3(680,0,320,300);
			Drawscene3();

			// sidebar 
			initGL4(20,0,280,610);
			Drawscene4();
			initGL5(1000,0,20,1);	
		if(numScreen == 1){
			win[1].makeCurrent();
			win[1].inGL();
			// initGL(320,0,340,300);
			// Drawscene();
			messinit();
		}
		
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{	
			if(event.type == SDL_KEYDOWN)
			{
				// cout << "was here keydown  pressed\n";
				if(event.key.keysym.sym == SDLK_ESCAPE)
				{				
					cout << "was here keydownesc\n";
					esc = true;
				}
				if(event.key.keysym.sym == SDLK_n){
					cout << "n \n";
					n = true;
				}
			}
			standardHandler(event,win);

			if(event.type = SDL_KEYUP)
			{
				cout << "was here keyup \n";
				if(event.key.keysym.sym == SDLK_ESCAPE && esc == true)
				{
					
					esc = false;
					if(numScreen == 1){
						win[numScreen].free();
						numScreen--;
					}
					else
					{
						done = 1;
					}
				}
				if(event.key.keysym.sym == SDLK_n && n == true)
				{
					cout << "N up\n";
					n = false;
					if(numScreen == 0)
					win[1].init();
					numScreen = 1;
				}
			}
			keys = SDL_GetKeyboardState(NULL);
			if(keys[SDL_SCANCODE_M])
 			{
 				// cout <<"M\n";
 				win[1].free();
 				numScreen=0;
 			}
		}
		for(int i=0;i<4;i++)
			win[i].render();
		// SDL_GL_SwapWindow(win[0].screen);
		if(checkKeys(keys))
			done = 1 ;
	}

	gTexture.free();
	TTF_CloseFont(font);
	// SDL_GL_DeleteContext(context);
	for(int i=0;i<win.size();i++)
		win[i].free();
	SDL_DestroyRenderer(rend1);
	SDL_DestroyWindow(screen);
	TTF_Quit();
	IMG_Quit();
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

void establishMatrix5(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
}

void initGL5(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
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
