#ifndef POINT_H
#define POINT_H
/*! Wrapper class to denote the point*/
class point {
		float x;/*! x-coordinate*/
		float y;/*! y-coordinate*/
		float z;/*! z-coordinate*/
	public:
		/*! Constructor to initialize a point at origin*/
		point(){
			this->x=0.0f;
			this->y=0.0f;
			this->z=0.0f;
		};
		/*! Returns a coordinate*/
		float getC(int val)
		{
			if(val ==0)
				return this->x;
			else if(val == 1)
				return this->y;
			else
				return this->z;
		}
		/*! Sets the coordinates of the point*/
		void setC(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		/*! Checks if two points are equal*/
		bool operator==(point p){
			return p.x==x && p.y==y && p.z==z;
		}

};

#endif