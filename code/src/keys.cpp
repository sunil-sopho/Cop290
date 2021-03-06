#include <keys.h>
#include <header.h>


int mode = 1,counter =0;
node nod = node(4);

// GLboolean checkKeys(const Uint8* keys,GLfloat *lx, GLfloat* ly, GLfloat *lz,GLfloat* ScaleFactor,GLfloat* cubeRotateX,GLfloat* cubeRotateY )
GLboolean checkKeys(unsigned char const* keys,std::vector<node> &v)
{

	const GLfloat speed = 1.0f;

 	if(keys[SDL_SCANCODE_ESCAPE])
 	{
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
 		if(ScaleFactor >= 0.0000001)
 		ScaleFactor -= 0.01;
 	}
 	if(keys[SDL_SCANCODE_P]){
 		save = true;
 	}
 	if(keys[SDL_SCANCODE_U])
 	{
 		lx += 0.01;
 	} 	
 	if(keys[SDL_SCANCODE_J])
 	{
 		lx -= 0.01;
 	}
 	if(keys[SDL_SCANCODE_I])
 	{
 		ly += 0.01;
 	}
  	if(keys[SDL_SCANCODE_K])
 	{
 		ly -= 0.01;
 	}   
 	if(keys[SDL_SCANCODE_O])
 	{
 		lz += 0.01;
 	}
 	if(keys[SDL_SCANCODE_L])
 	{
 		lz -= 0.01;
 	}
 	if(keys[SDL_SCANCODE_1])
 	{
 		mode = 1;
 	} 
  	if(keys[SDL_SCANCODE_2])
 	{
 		mode = 2;
 	} 
 	 	if(keys[SDL_SCANCODE_3])
 	{
 		// cout << "3";
 		mode = 3;
 	}
 	if(keys[SDL_SCANCODE_4])
 	{
 		mode = 4;
 	}
 	if(keys[SDL_SCANCODE_RETURN])
 	{
 		cout << mode <<" : "<< counter<<'\n';
		
		if(counter == 0){
			nod.setCode(mode);
			counter++;
		}

		if(counter == mode +1){
			cout << nod.getCode() << " is this right\n";
			v.push_back(nod);
			cout << "vsize here is: "<<v.size()<<endl;
			counter =0;
		}

 	}
 	if(keys[SDL_SCANCODE_KP_1])
 	{
 		if(counter == 1){
			nod.setP(1,lx,ly,lz);
			counter++;
		}
 	}
 	 if(keys[SDL_SCANCODE_KP_2])
 	{
 		if(counter == 2){
			counter++;
			nod.setP(2,lx,ly,lz);
		}
 	}  	
 	if(keys[SDL_SCANCODE_KP_3])
 	{
 		if(counter == 3){
			counter++;
			nod.setP(3,lx,ly,lz);
		}
 	}  	
 	if(keys[SDL_SCANCODE_KP_4])
 	{
 		if(counter == 4){
			counter++;
			nod.setP(4,lx,ly,lz);
		}
 	}  	  	
//=======================================================================
//========== specialised functions ======================================
//=======================================================================
 	if(keys[SDL_SCANCODE_X])
 	{
 		cubeRotateX = 0.0f;
 	}
 	if(keys[SDL_SCANCODE_Y])
 	{
 		cubeRotateY = 0.0f;
 	}
 	if(keys[SDL_SCANCODE_Z])
 	{
 		// cubeRotateZ = 0.0f;
 	}
 	if(keys[SDL_SCANCODE_T]){
 		cout <<"pressed T\n";
 		ofstream file;

 		file.open("output.txt");
 		// freopen("output1.txt","w",stdout);
 		file <<v.size()<<endl;
 		for(int i=0;i<v.size();i++){
 			int n=v[i].getCode();
 			file <<n<<" ";
 			for(int j=0;j<n;j++){
 				point p=v[i].getP(j+1);
 				file <<"("<<p.getC(0)<<", "<<p.getC(1)<<", "<<p.getC(2)<<") ";
 			}
 			file<<endl;
 		}
 		file.close();

 		cout << "escaped T\n";
 	}
 	return false;

}
