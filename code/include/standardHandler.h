#ifndef STANDARDHANDLER_H
#define STANDARDHANDLER_H

#include "clicks.h"
#include <window.h>
#include <vector>
#include <SOIL/SOIL.h>

using namespace std;

bool standardHandler(SDL_Event& event, std::vector<window> win,std::vector<node> v,int *done,bool *save);

#endif