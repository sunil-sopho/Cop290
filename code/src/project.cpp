#include <project.h>

 void Project(std::vector<node> v,int view)
 {
	for(int i=0; i < v.size() ;i++ )
	{
		int code = v[i].getCode();

		point p[code];
		for(int j=0; j<code ;j++)
		{
			p[j] = v[i].node::getP(j+1);
		}

		if(code == 1)
			addPoint(p,view);
		else if(code == 2)
			addLine(p,view);
		else if(code == 3)
			addTri(p,view);
		else
			addPlane(p,view);
	}
	//cout << "out of here\n";
}