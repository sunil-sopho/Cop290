// #include <Point.h>
#include <Edge.h>
//#include <Model_3d.h>
#include <OrthographicView.h>
// #include <Plane.h>
#include <vector>
using namespace std;
#ifndef Model_3d_h
#define Model_3d_h
/*!Wrapper class for representing a 3d model in the form of a graph.*/
class Model_3d{
public:
	/*! Array of 3d points for storing of all the vertices of the 3d model.*/
	vector<Point> nodes[50];
	int count;
	/*! Array of 3d edges for storing all the edges of the 3d model.*/
	// Edge edges;
	/*! Rotates the given 3d model around the auxiliary plane.*/
	Model_3d(){
		count=0;
	}
	Point search(int id);
	void addEdge(Point src,Point dest);
	void removeEgde(Point src,Point dest);

	Model_3d rotate(Plane p);
	/*! Gives the orthogarphic projection of a 3d model.*/
	OrthographicView GetOrthographic(Model_3d m);
	/*! Output the 3d model on the screen.*/
	void display();
};
#endif