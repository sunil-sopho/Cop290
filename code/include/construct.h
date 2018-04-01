#ifndef CONSTRUCT_H
#define CONSTRUCT_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "node.h"

void addPoint(point* p,int view);

void addLine(point* p,int view);

void addTri(point* p,int view);

void addPlane(point* p,int view);

#endif