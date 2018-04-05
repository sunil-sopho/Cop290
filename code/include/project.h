#ifndef PROJECT_H
#define PROJECT_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "point.h"
#include "node.h"
#include "construct.h"
#include <vector>

/*! Function to project the object on the screen*/
void Project(std::vector<node> v,int view);

#endif