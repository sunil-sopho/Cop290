#include <Model_3d.h>
#include<OrthographicView.h>
#include <algorithm>
// #include <Point.h>
void Model_3d::addEdge(Point src,Point dest){
	nodes[src.id].push_back(dest);
	nodes[dest.id].push_back(src);
	count=(count<src.id)?src.id:count;
	count=(count<dest.id)?dest.id:count;
}
Point Model_3d::search(int id){
	vector<Point> v=nodes[id];
	int f=v[0].id;
	vector<Point> v1=nodes[f];
	for(int i=0;i<v1.size();i++){
		if(v1[i].id==f) return v1[i];
	}
}
OrthographicView Model_3d::GetOrthographic(Model_3d m){
	Projection top,front,side;
	for(int i=0;i<count;i++){
		vector<Point> v=nodes[i];
		for(int j=0;j<v.size();j++){
			Point t,f,s;
			t.id=v[i].id;
			t.x=v[j].x;
			t.y=0.0;
			t.z=v[j].z;
			
			f.id=v[j].id;
			f.x=v[j].x;
			f.y=v[j].y;
			f.z=0.0;
			
			s.id=v[j].id;
			s.x=0.0;
			s.y=v[j].y;
			s.z=v[j].z;
			top.nodes[i].push_back(t);
			front.nodes[i].push_back(f);
			side.nodes[i].push_back(s);
		}
	}
	OrthographicView ortho;
	ortho.topView=top;
	ortho.frontView=front;
	ortho.sideView=side;
	return ortho;
}