#ifndef KEYS_H
#define KEYS_H
extern bool save;
extern int numScreen;
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "window.h"
// #include <cad.h>
#include "construct.h"
#include <vector>
#include <iostream>
#include <fstream>
// #include <header.h>
using namespace std;
// #include "standardHandler.h"



GLboolean checkKeys(unsigned char const* keys,std::vector<node> v);


#endif