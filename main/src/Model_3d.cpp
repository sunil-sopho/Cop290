#include <Model_3d.h>
#include <algorithm>
// #include <Point.h>
void Model_3d::addEgde(Point src,Point dest){
	nodes[src.id].push_back(dest);
	nodes[dest.id].push_back(dest);
}
// void Model_3d::removeEgde(Point src,Point dest){
// 	std::vector<Point>::iterator pos=std::find(nodes[src].begin(),nodes[src].end(),dest);
// 	if(pos!=nodes[src].end())
// 		nodes[src].erase(pos);
// }
