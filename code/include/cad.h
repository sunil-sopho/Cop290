#ifndef CAD_H
#define CAD_H

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
	bool n = false,esc = false;
	std::vector<node> v;
	SDL_Window *screen,*screen2;
	SDL_Rect rect1,rect2;
	SDL_Renderer *rend1,*rend2;
	SDL_Texture *text1, *text2;
	char *font_path = "FreeSans.ttf"; ;
	TTF_Font *font;
	int done = 0;
	GLfloat ScaleFactor = 1.0f;
	GLfloat cubeRotateY = 0.0f;
	GLfloat cubeRotateX = 0.0f;
	GLfloat lx=0,ly=0,lz=0;
const Uint8 *keys = NULL;
#include "standardHandler.h"
#include "window.h"
#include "keys.h"
#include <header.h>
#include "cube.h"
// #include "printtxt.h"
// #include "buttons.h"

#include "construct.h"
#include "project.h"


#include "draw.h"
#include "messNet.h"
#include "clicks.h"
// #include "Ltexture.h"

#endif