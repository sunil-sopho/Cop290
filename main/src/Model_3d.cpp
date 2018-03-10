#include <Model_3d.h>
// #include <Point.h>
void Model_3d::addEgde(Point src,Point dest,Model_3d m){
	m.nodes[src.id].push_back(dest);
	m.nodes[dest.id].push_back(dest);
};