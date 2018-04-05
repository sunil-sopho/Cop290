#include <standardHandler.h>

bool standardHandler(SDL_Event& event, std::vector<window> win,std::vector<node> v,int *done,bool *save)
{
	int x1,y1;
		if (event.type == SDL_QUIT)
		{
			// if(numScreen == 0)
				*done = 1 ;
			// else
			// 	closeWindow();
		}
		if(event.type == SDL_MOUSEMOTION)
		{
			SDL_GetMouseState(&x1,&y1);
		}
		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			clicks(x1,y1,v);
		}
		if(*save)
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
			*save = false;
			// done = 1;
		}
}