#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "point.h"
#include "node.h"
#include "construct.h"
#include <vector>
 void Project(std::vector<node> v){
	for(int i=0; i < v.size() ;i++ )
	{
		int code = v[i].getCode();

		point p[code];
		for(int j=0; j<code ;j++)
		{
			p[j] = v[i].node::getP(j+1);
		}

		if(code == 1)
			addPoint(p);
		else if(code == 2)
			addLine(p);
		else if(code == 3)
			addTri(p);
		else
			addPlane(p);
	}
	cout << "out of here\n";
}