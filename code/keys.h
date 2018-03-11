
GLfloat ScaleFactor = 1.0f;
GLfloat cubeRotateY = 0.0f;
GLfloat cubeRotateX = 0.0f;
bool save = false;

GLboolean checkKeys(const Uint8* keys){

	const GLfloat speed = 1.0f;

 	if(keys[SDL_SCANCODE_ESCAPE])
 	{
 		return true;
 	}
 	if(keys[SDL_SCANCODE_LEFT])
 	{
 		cubeRotateY -= speed;
 	}
 	if(keys[SDL_SCANCODE_RIGHT])
 	{
 		cubeRotateY += speed;
 	}
 	if(keys[SDL_SCANCODE_UP])
 	{
 		cubeRotateX -= speed;
 	}
 	if(keys[SDL_SCANCODE_DOWN])
 	{
 		cubeRotateX += speed;
 	}

 	if(keys[SDL_SCANCODE_S])
 	{
 		ScaleFactor += 0.01;
 	}
 	if(keys[SDL_SCANCODE_W])
 	{
 		ScaleFactor -= 0.01;
 	}
 	if(keys[SDL_SCANCODE_J]){
 		save = true;
 	}
 	return false;

}