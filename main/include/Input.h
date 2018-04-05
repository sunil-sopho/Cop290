/*! \mainpage Engineering Drawing Software
	<B>Welcome to Engineering Drawing Software source documentation!</B>\n\n
	We hope you'll find it a convenient tool to explore, understand and experiment with the internals of the program.\n\n
	Being generated from the actual state of the code, this documentation is by no means a well structured corpus or a textbook, but more an utility to browse through the sources.\n\n
	Don't hesitate to rebuild an up to date doc from source as often as needed.\n\n
	You can find the source code <a href="https://github.com/sunil-sopho/Cop290">here</a>.
*/
#include <OrthographicView.h>
#include <Model_3d.h>
#include<Model_3d.h>
#include <string>
#include<fstream>
/*! Contains functions for taking input from file.*/
#ifndef Input_h
#define Input_h
class Input{
public:
	/*! Reads the file and return the orthographid views in the form of 2d graph.*/
	OrthographicView readFromOrthoFile(string file);
	/*! Reads the file and returns 3d model in the form of 3d graph.*/
	Model_3d readFrom3DFile(string file);
};
#endif
