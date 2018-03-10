#include <Model_3d.h>
// #include <Projection.h>
// #include <Point2D.h>
// #include <Edge2D.h>
/*! This class contains functions to generate 3d model from the orthographic views
*/
class Two_d_to_Three_d{
public:
	/*! This method will generate a 3d graph given in the input 3 orthographic projection.*/
	Model_3d generate(OrthogarphicView view);
	/*! Creates 3d point from 2d point and add to 3d model.*/
	void createVertex(Projection p,Point2D point);
	/*! Creates 3d edge using 2d edge and 3d point and add to the 3d model.*/
	void createEdge(Edge2D edge,Projection p);
};
