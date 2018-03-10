#include <Model_3d.h>
#include <OrthographicView.h>
/*! This class contains functions to generate 2d views given a 3d model.
*/
class Three_d_to_Two_d{
public:
	/*! Returns two-dimensional views of the given three-dimensional model around the given auxiliary plane.*/
	OrthographicView GetOrthographic(Model_3d model);
	/*! Perform scaling to get coordinates of the vertices of 3d object.*/
	Model_3d scaling(Model_3d model);
	/*! Rotates	the 3d model to get 2d views aroung the auxiliary plane.*/
	Model_3d Rotate(Model_3d model);
};
