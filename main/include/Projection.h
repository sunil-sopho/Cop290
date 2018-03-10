// #include <Point2D.h>
#include <Edge2D.h>
// #include <Projection.h>
#include <Plane.h>
/*! Wrapper Class for representing a 2d projection of a given 3d model in a 2d graph format. Also provides funcions for adding edge and vertex and checking correctness of projections*/
class Projection{
public:
	Point2D nodes[50]/*! Array of 2d points denoting projection of all the vertices of the 3d model on the given projection plane*/;
	Edge2D edge[20]/*! Array of 2d edges denoting all the edges of the projection of 3d model.*/;
	/*! projection plane*/
	Plane plane;	
	void addEdge(Edge2D edge)/*! Function for adding a edge between two 2d points.*/;
	void addVertex(Point2D point)/*! Function for adding a vertex.*/;
	/*! Takes the correct projection as input and checks if the current (generated) projection is valid.*/
	bool checkValid(Projection proj);
};
