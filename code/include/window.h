#ifndef WINDOW_H
#define WINDOW_H

#include "keys.h"
#include "standardHandler.h"
// SDL_GLContext context2;

// void establishMatrix4(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
// {
// 	glViewport(lx,ly,width,height);
// 	glMatrixMode(GL_PROJECTION);
// 	glLoadIdentity();
// 	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
// }

// void initGL4(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
// {
// 	establishMatrix4(lx,ly,width,height);

// 	glDisable(GL_SCISSOR_TEST);
// 	glClearColor(0.0f,1.0f,1.0f,1.0f);
// 	glScissor(lx,ly,width,height);
// 	glEnable(GL_SCISSOR_TEST);

// 	glClearColor(0.50f,0.90f,0.10f,1.0f);

// 	glEnable(GL_DEPTH_TEST);
// 	glDepthFunc(GL_LEQUAL);
// 	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
// 	glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
// }	

// void createWindow(){	
// 	SDL_CreateWindowAndRenderer(200,210, 0, &screen2, &rend2);
//  //    context2 = SDL_GL_CreateContext(screen2);
// 	// SDL_GL_MakeCurrent(screen2, context2);
// }

// void closeWindow()
// 	{
// 		// SDL_GL_DeleteContext(context2);
// 	SDL_DestroyRenderer(rend2);
// 	SDL_DestroyWindow(screen2);
// 	numScreen=0;
// }







class window
{
public:
		window();
		// create window
		bool init();

		void eventHandler(SDL_Event& e);

		void focus();
		void render();
		void free();
		int getWidth();
		int getHeight();

		bool mouseFocus();
		bool keyboadFocus();
		bool mini();
		void makeCurrent();
		void inGL();
		SDL_Window *screen;
private:
	
	SDL_Renderer* rend;
	SDL_GLContext context;
	int id;

		//Window dimensions
	int mWidth;
	int mHeight;

	//Window focus
	bool mMouseFocus;
	bool mKeyboardFocus;
	bool mFullScreen;
	bool mMinimized;
	bool mShow;
};

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


#endif