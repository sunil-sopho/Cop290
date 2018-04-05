#ifndef CONSTRUCT_H
#define CONSTRUCT_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "node.h"

/*! This function adds a point in the object*/
void addPoint(point* p,int view);

/*! This function adds a line in the object*/
void addLine(point* p,int view);

/*! This function adds a triangle in the object*/
void addTri(point* p,int view);

/*! This function adds a quadrilaterals in the object*/
void addPlane(point* p,int view);

#endif