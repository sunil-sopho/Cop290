#include "point.h"
// typedef struct node 
// {
// 	int code;
// 	point::point p1 ;//= new point();
// 	point::point p2 ;//= new point();
// 	point::point p3 ;//= new point();
	
// };
class node {
	int code;
	point p1;
	point p2;
	point p3;
public:
		node(int val){
			this->code = val;
		}

};