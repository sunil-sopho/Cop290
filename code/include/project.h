#ifndef PROJECT_H
#define PROJECT_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "point.h"
#include "node.h"
#include "construct.h"
#include <vector>

// view =0 for 3d ,, view = 1 for ortho

 void Project(std::vector<node> v,int view);

#endif