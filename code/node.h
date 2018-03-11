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
	point p4;	
public:
		node(int val){
			this->code = val;
		}
		int getCode(){
			return this->code;
		}
		point getP(int val){
			if(val == 1)
				return this->p1;
			else if(val == 2)
				return this->p2;
			else if(val == 3)
				return this->p3;
			else if(val == 4)
				return this->p4;
		}
};