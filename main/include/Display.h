#include <Model_3d.h>
// #include <OrthogarphicView.h>
/*! Displays output on the screen*/
class Display{
public:
	/*! Displays 3d model on the screen and returns the output in file.*/
	string Display_3d(Model_3d m);
	/*! Displays 2d views on the screen and returns the output in file.*/
	string Display_2d(OrthogarphicView o);
};