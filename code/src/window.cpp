#include <iostream>
#include <string>

using namespace std;

#include <include.h>
#include <window.h>


window::window()
{
	rend = NULL;
	screen = NULL;
	context = NULL;
	mMouseFocus = false;
	mKeyboardFocus = false;
	id = -1;
	mHeight = 0;
	mWidth = 0;
	mShow = false;
}

bool window::init()
{
	SDL_CreateWindowAndRenderer(1020,610, 0, &screen, &rend);
	mMouseFocus = true;
	mKeyboardFocus = true;
	mMinimized = false;
	mWidth = 1020;
	mHeight = 610;
// initialize renderer color
	SDL_SetRenderDrawColor( rend, 0xFF, 0xFF, 0xFF, 0xFF );
	id = SDL_GetWindowID( screen );
	context = SDL_GL_CreateContext(screen);
	SDL_GL_MakeCurrent(screen, context);
	return true;
}

void window::eventHandler(SDL_Event& e)
{
	// standardHandler(e,t);
}

void window::focus()
{
	if(!mShow)
		SDL_ShowWindow( screen );
	SDL_RaiseWindow(screen);
}

void window::render()
{
	if(!mMinimized)
	{
		SDL_SetRenderDrawColor( rend, 0xFF, 0xFF, 0xFF, 0xFF );
		// SDL_RenderClear( rend );

		// //Update screen
		// SDL_RenderPresent( rend );
		SDL_GL_SwapWindow(screen);
	}
}
void window::makeCurrent(){
	SDL_GL_MakeCurrent(screen, context);
}
void window::free()
{
	if( screen != NULL)
	{
		SDL_DestroyWindow(screen);
		SDL_DestroyRenderer(rend);	
	}
}

bool window::mini(){
	return mMinimized;
}

bool window::mouseFocus()
{
	return mMouseFocus;
}

bool window::keyboadFocus()
{
	return mKeyboardFocus;
}

int window::getHeight()
{
	return mHeight;
}
int window::getWidth()
{
	return mWidth;
}

void establishModelMatrix(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
}

void initGLWindow(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishModelMatrix(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.00f,0.00f,0.00f,1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}

void window::inGL(){
	initGLWindow(0,0,mWidth,mHeight);
}
