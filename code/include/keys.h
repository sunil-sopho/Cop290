#ifndef KEYS_H
#define KEYS_H
extern bool save;
extern int numScreen;
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "window.h"
#include "construct.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


/*! Detects which key is pressed */
GLboolean checkKeys(unsigned char const* keys,std::vector<node> &v);


#endif