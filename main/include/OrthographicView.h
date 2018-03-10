#include <Projection.h>
/*! Represents orthographic projections of a 3d model.*/
class OrthographicView{
public:
	Projection topView/*! Top view of 3d model*/,frontView/*! Front view of model*/,sideView/*! Side view of 3d model*/;
	void display()/*! Output the orthographic views on the screen.*/;
};
