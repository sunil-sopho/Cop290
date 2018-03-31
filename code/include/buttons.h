#include<bits/stdc++.h>
#include<SOIL/SOIL.h>
using namespace std;
GLuint minusm,minusn;
unsigned char* image  = NULL;
		int width, height;
void loadbuttons()
{
	// try
	// {
	// minusm = SOIL_load_OGL_texture (
	// 	"home/sunil/Cop290/code/file.png",
	// 	SOIL_LOAD_AUTO,
	// 	SOIL_CREATE_NEW_ID,
	// 	SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA
	// 	);
	// minusn = SOIL_load_OGL_texture (
	// 	"../file.png",
	// 	SOIL_LOAD_AUTO,
	// 	SOIL_CREATE_NEW_ID,
	// 	SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA
	// 	);
	// }
	// if(minusn == 0)
	// 	std::cerr << "error:  " <<'\n';
	// catch


image = SOIL_load_image("file.png", &width, &height, 0, SOIL_LOAD_RGB);
// glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
              // GL_UNSIGNED_BYTE, image);
// SOIL_free_image_data(image);
if( image == NULL)
	cout << image << *image  <<": "<<minusm <<'\n';
}