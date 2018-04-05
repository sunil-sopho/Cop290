#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

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
		SDL_Renderer* rend;
private:
	
	
	SDL_GLContext context;
	int id;
	int mWidth;
	int mHeight;
	bool mMouseFocus;
	bool mKeyboardFocus;
	bool mFullScreen;
	bool mMinimized;
	bool mShow;
};

void establishModelMatrix(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGLWindow(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
#endif