#include<bits/stdc++.h>
#include<SOIL/SOIL.h>
using namespace std;
GLuint minusm,minusn;
unsigned char* image  = NULL;
		int width, height;
void loadbuttons()
{

	image = SOIL_load_image("file.png", &width, &height, 0, SOIL_LOAD_RGB);
	if( image == NULL)
		cout << image << *image  <<": "<<minusm <<'\n';
}