#include <SDL2/SDL.h>
#include <GL/glut.h>
//#include "soil.h" // image importing utilities>
#include "stdio.h"
#include "math.h" // for basic mathematic functions
#include "stdlib.h"
#include "string.h"

SDL_Window *screen;

int main(int argc, char ** argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_CreateWindow("CAD", 200,200,1024,610,SDL_WINDOW_OPENGL);
	
	SDL_GLContext context = SDL_GL_CreateContext(screen);
	SDL_GL_MakeCurrent(screen, context);

	int done = 0;
	while(!done)\
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{	
			if (event.type = SDL_QUIT)
			{
				done =1 ;
			}
		}
		SDL_GL_SwapWindow(screen);
	}
	SDL_DestroyWindow(screen);
	SDL_Quit();
	return 0;
}	
