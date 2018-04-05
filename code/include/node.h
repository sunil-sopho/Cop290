#ifndef NODE_H
#define NODE_H

#include "point.h"
/* Wrapper class to store basic shapes (i.e., point,line,triangle and quadrilateral)*/
class node {
	int code; /*! Represents if the shape is point,line,triangle or quadrilateral*/
	point p1; /*! First point*/
	point p2; /*! Second point*/
	point p3; /*! Third point*/ 
	point p4; /*! Fourth point*/	
public:
		node(){
			
		}
		/*! Constructor to create a shape of given type*/
		node(int val){
			this->code = val;
		}
		/*! Return the type of shape*/
		int getCode(){
			return this->code;
		}
		/*! Returns the asked point of the shape*/
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
		/*! Sets a point of the shape*/
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
		/*! Function to set the type of shape*/
		void setCode(int val)
		{
			this->code = val;
		}
};

#endif