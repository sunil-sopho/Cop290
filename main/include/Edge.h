#include <Point.h>
/*! Wrapper class for denoting a edge between two points in 3d space.*/
#ifndef Edge_h
#define Edge_h
class Edge{
public:
	/*! \var Point start*/
	Point start/*! Starting point*/;
	/*! \var Point end*/
	Point end/*! Ending point*/;
};
#endif
