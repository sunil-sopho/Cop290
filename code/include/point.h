#ifndef POINT_H
#define POINT_H
class point {
		float x;
		float y;
		float z;
	public:
		// int id;
		point(){
			this->x=0.0f;
			this->y=0.0f;
			this->z=0.0f;
		};
		float getC(int val)
		{
			if(val ==0)
				return this->x;
			else if(val == 1)
				return this->y;
			else
				return this->z;
		}
		void setC(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		bool operator==(point p){
			return p.x==x && p.y==y && p.z==z;
		}
<<<<<<< HEAD

=======
	
>>>>>>> 6412f52f19f6a14cf87e15b6219608097dee1370
};

#endif