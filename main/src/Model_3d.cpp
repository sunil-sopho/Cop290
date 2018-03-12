#include <Model_3d.h>
#include <algorithm>
// #include <Point.h>
void Model_3d::addEgde(Point src,Point dest){
	nodes[src.id].push_back(dest);
	nodes[dest.id].push_back(src);
	count=(count<src.id)?src.id?count;
	count=(count<dest.id)?dest.id?count;
}
OrthographicView Model_3d::GetOrthographic(Model_3d m){
	Projection top;
	for(int i=0;i<count;i++){
		vector<Point> v=nodes[i];
		for(int j=0;j<v.size();j++){
			Point p;
			p.x=v[j].x;
			p.y=0.0;
			p.z=v[j].z;
			top.addEgde()
		}
	}
}