#ifndef NODE_H
#define NODE_H

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
		node(){
			
		}
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
		void setP(int val,float x, float y , float z)
		{
			if(val == 1)
			{
				// if(p1 == NULL)
				// {
				// 	p1 = new point();
				// }
				p1.setC(x,y,z);
			}
			if(val == 2)
			{
				// if(p2 == NULL)
				// {
				// 	p2 = new point();
				// }
				p2.setC(x,y,z);
			}
			if(val == 3)
			{
				// if(p3 == NULL)
				// {
				// 	p3 = new point();
				// }
				p3.setC(x,y,z);
			}
			if(val == 4)
			{
				// if(p4 == NULL)
				// {
				// 	p4 = new point();
				// }
				p4.setC(x,y,z);
			}
		}
		void setCode(int val)
		{
			this->code = val;
		}
};

#endif