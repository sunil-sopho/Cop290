#include <Projection.h>
void Projection::addEdge(Point src,Point dest){
	nodes[src.id].push_back(dest);
	nodes[dest.id].push_back(src);
	count=(count<src.id)?src.id?count;
	count=(count<dest.id)?dest.id?count;
}