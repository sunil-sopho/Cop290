#include <Input.h>
using namespace std;
Model_3d Input::readFrom3DFile(string file){
	ifstream read(file);
	int id1,id2,x1,x2,y1,y2,z1,z2;
	Point p1,p2;
	Model_3d m;
	while(read>>id1>>x1>>y1>>z1>>id2>>x2>>y2>>z2){
		p1.id=id1;
		p1.x=x1;
		p1.y=y1;
		p1.z=z1;

		p2.id=id2;
		p2.x=x2;
		p2.y=y2;
		p2.z=z2;
		m.addEdge(p1,p2);
	}
	return m;
}
