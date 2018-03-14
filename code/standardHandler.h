#ifndef STANDARDHANDLER_H
#define STANDARDHANDLER_H

#include "clicks.h"
#include "window.h"
#include <vector>
int x,y;
bool n = false,esc = false;
bool standardHandler(SDL_Event& event, std::vector<window> win)
{
		if (event.type == SDL_QUIT)
		{
			// if(numScreen == 0)
				done = 1 ;
			// else
			// 	closeWindow();
		}
		if(event.type == SDL_MOUSEMOTION)
		{
			SDL_GetMouseState(&x,&y);
		}
		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			clicks(x,y);
		}
		// if(event.type == SDL_KEYDOWN)
		// {cout << "was here keydownesc";
		// 	if(event.key.keysym.sym == SDLK_ESCAPE){
		// 		cout << "was here keydownesc";
		// 		esc = true;
		// 	}
		// 	if(event.key.keysym.sym == SDLK_n)
		// 		n = true;
		// }
		// if(event.type = SDL_KEYUP)
		// {
		// 	if(event.key.keysym.sym == SDLK_ESCAPE && esc == true)
		// 	{
		// 		cout << "was here keyupesc";
		// 		esc = false;
		// 		win[numScreen].free();
		// 		numScreen--;
		// 	}
		// 	if(event.key.keysym.sym == SDLK_n && n == true)
		// 	{

		// 		esc = false;
		// 		win[numScreen+1].init();
		// 		numScreen++;
		// 	}
		// }
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
}

#endif