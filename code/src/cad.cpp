/*
Author - Sunil Kumar
gitid - sunil-sopho
Projectname - CAD
*/
#include <cad.h>
#include <kiss_sdl.h>
#include <fstream>

std::vector<window> win(4);

// LTexture gTexture;


void establishMatrix(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

// differnt matrix for different views 
void establishMatrix2(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL2(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

void establishMatrix3(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL3(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

void establishMatrix4(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL4(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

void establishMatrix5(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL5(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

void establishMatrix6(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL6(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

void establishMatrix7(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL7(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

void establishMatrix8(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL8(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);

void establishMatrix9(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
void initGL9(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height);
			
			int np,ne;
			vector<point> top_vertex,front_vertex,side_vertex;
			vector<point> answer;
			vector<vector<int>> top_adj,front_adj,side_adj;
			vector<vector<int>> ans_adj;

void generate_points(){
	for(int i=0;i<np;i++){
		point p=top_vertex[i];
		point q=front_vertex[i];
		point r=side_vertex[i];
		point s;
		s.setC(p.getC(0),q.getC(1),p.getC(2));
		answer.push_back(s);
	}
}
bool connected1(int i,int j){
	point p=top_vertex[i];
	point q=top_vertex[j];
	if(p==q) return 1;
	return find(top_adj[i].begin(),top_adj[i].end(),j)!=top_adj[i].end();
}
bool connected2(int i,int j){
	point p=front_vertex[i];
	point q=front_vertex[j];
	if(p==q) return 1;
	return find(front_adj[i].begin(),front_adj[i].end(),j)!=front_adj[i].end();
}
bool connected3(int i,int j){
	point p=side_vertex[i];
	point q=side_vertex[j];
	if(p==q) return 1;
	return find(side_adj[i].begin(),side_adj[i].end(),j)!=side_adj[i].end();
}
void generate_edges(){
	int e=0;
	// vector<vector<int>> adj;
	vector<int> v;
	for(int i=0;i<answer.size();i++)
		ans_adj.push_back(v);
	for(int i=0;i<answer.size();i++){
		for(int j=i+1;j<answer.size();j++){
			if(connected1(i,j) && connected2(i,j) && connected3(i,j)){
				ans_adj[i].push_back(j);
				ans_adj[j].push_back(i);
				e++;
			}
		}
	}
}
// main
int main(int argc, char ** argv)
{

	if(argc==2){

		const char *filename=argv[1];
		// freopen(filename,"r",stdin);

		ifstream file;
		file.open(filename);
		int type;
		file>>type;
		if(type==0){
			int n,m;
			float x,y,z;
			char c;
			file>>n;

			for(int i=0;i<n;i++){
				file>>m;

				node no(m);
				for(int j=0;j<m;j++){
					file>>c>>x>>c>>y>>c>>z>>c;

					no.setP(j+1,x,y,z);
				}

				v.push_back(no);

			}
		}
		else{
			float x,y,z;
			vector<int> vi;
			file>>np;
			int n1,n2;
			for(int i=0;i<np;i++){
				file>>x>>y>>z;
				point p;
				// p.id=id;
				p.setC(x,y,z);
				top_vertex.push_back(p);
			}
			file>>ne;
			for(int i=0;i<np;i++)
				top_adj.push_back(vi);
			for(int i=0;i<ne;i++){
				file>>n1>>n2;
				top_adj[n1].push_back(n2);
				top_adj[n2].push_back(n1);
			}

			file>>np;
			for(int i=0;i<np;i++){
				file>>x>>y>>z;
				point p;
				// p.id=id;
				p.setC(x,y,z);
				front_vertex.push_back(p);
			}
			file>>ne;
			for(int i=0;i<np;i++)
				front_adj.push_back(vi);
			for(int i=0;i<ne;i++){
				file>>n1>>n2;
				front_adj[n1].push_back(n2);
				front_adj[n2].push_back(n1);
			}

			file>>np;
			for(int i=0;i<np;i++){
				file>>x>>y>>z;
				point p;
				// p.id=id;
				p.setC(x,y,z);
				side_vertex.push_back(p);
			}
			file>>ne;
			for(int i=0;i<np;i++)
				side_adj.push_back(vi);
			for(int i=0;i<ne;i++){
				file>>n1>>n2;
				side_adj[n1].push_back(n2);
				side_adj[n2].push_back(n1);
			}

			generate_points();
			generate_edges();
			// for(int i=0;i<answer.size();i++){
			// 	cout<<answer[i].getC(0)<<" "<<answer[i].getC(1)<<" "<<answer[i].getC(2)<<endl;
			// }
			// 	return 0;
			for(int i=0;i<np;i++){
				point p1=answer[i];
				for(int j=0;j<ans_adj[i].size();j++){
					int k=ans_adj[i][j];
					point p2=answer[k];
					node nod(2);
					nod.setP(1,p1.getC(0),p1.getC(1),p1.getC(2));
					nod.setP(2,p2.getC(0),p2.getC(1),p2.getC(2));
					v.push_back(nod);
				}
			}
		}
		// fclose(stdin);
		file.close(); 		

	}
	if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
	{
			cout <<"error\n"	;
	}

	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);

	win[0].init();
    TTF_Init();
    font = TTF_OpenFont(font_path, 24);




    //kiss window for input
    kiss_array objects;
    kiss_window win1;
    kiss_label coord1 = {0},coord2 = {0},coord3 = {0},coord4={0},disp={0};
    kiss_button ok = {0}, cancel ={0};
    kiss_entry  entry[12];
 	
	
 //    rend1 = kiss_init("cad",&objects,1020,610,screen);
	// //kiss_window
	// kiss_window_new(&win1, NULL, 1, 0, 0, 1020,610);

	win1.visible = 1;

	int scre = 0;


	while(!done)
	{

		// main viewport for 2D
		// if(numScreen <= 0)
		// {
		win[0].makeCurrent();

			//ortho view
			initGL(340,0,320,300);
			Drawscene();

			//viewport for 3D projection
			initGL2(320,320,680,300);
			Drawscene2();

			//orthoview
			initGL3(680,0,320,300);
			Drawscene3();

			// sidebar 
			initGL4(20,320,280,300);
			Drawscene4();

			//orthoview
			initGL6(20,0,300,300);
			Drawscene6();

			//straight line horizontal
			initGL7(0,300,1020,20);
			Drawscene7();

			// staright line vertical 1
			initGL8(320,0,20,300);
			Drawscene8();

			// staright line vertical 2
			initGL9(640,0,20,300);
			Drawscene9();

			initGL5(1000,0,20,1);	
		if(numScreen == 1){
			win[1].makeCurrent();
			win[1].inGL();
			// initGL(320,0,340,300);
			// Drawscene();
			messinit();
		}

		// kiss_window_draw(&win1, win[1].rend);
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{	
			if(event.type == SDL_KEYDOWN)
			{
				// cout << "was here keydown  pressed\n";
				if(event.key.keysym.sym == SDLK_ESCAPE)
				{				
					// cout << "was here keydownesc\n";
					esc = true;
				}
				if(event.key.keysym.sym == SDLK_n){
					cout << "n \n";
					n = true;
				}
			}
			//standardHandler(event,win);

			if(event.type = SDL_KEYUP)
			{
				// cout << "was here keyup \n";
				if(event.key.keysym.sym == SDLK_ESCAPE && esc == true)
				{
					
					esc = false;
					if(numScreen == 1){
						win[numScreen].free();
						numScreen--;
					}
					else
					{
						done = 1;
					}
				}
				if(event.key.keysym.sym == SDLK_n && n == true)
				{
					// cout << "N up\n";
					n = false;
					if(numScreen == 0)
					win[1].init();
					numScreen = 1;
				}
			}
			keys = SDL_GetKeyboardState(NULL);
			if(keys[SDL_SCANCODE_M])
 			{
 				// cout <<"M\n";
 				win[1].free();
 				numScreen=0;
 			}
		}
		for(int i=0;i<4;i++)
			win[i].render();
		// SDL_GL_SwapWindow(win[0].screen);

		// kiss_window_draw(&win1, rend1);
		// SDL_RenderPresent(rend1);
		// SDL_SetRenderDrawColor( rend1, 0xFF, 0xFF, 0xFF, 0xFF );
		// SDL_GL_SwapWindow(screen);

		if(checkKeys(keys))
			done = 1 ;
	}

	// gTexture.free();
	TTF_CloseFont(font);
	// SDL_GL_DeleteContext(context);
	for(int i=0;i<win.size();i++)
		win[i].free();
	SDL_DestroyRenderer(rend1);
	SDL_DestroyWindow(screen);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	return 0;
}

// ortho 1

void establishMatrix(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
	glOrtho(-3.0,3.0,-3.0,3.0,-3.0,200.0);
}

void initGL(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.00f,0.00f,0.00f,1.0f);

	// glEnable(GL_DEPTH_TEST);
	// glDepthFunc(GL_LEQUAL);
	// glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	// glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}	





void establishMatrix2(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
}

void initGL2(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix2(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.00f,0.00f,0.00f,1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}	

// void establishMatrix3(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
// {
// 	glViewport(lx,ly,width,height);
// 	glMatrixMode(GL_PROJECTION);
// 	glLoadIdentity();
// 	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
// }

// void initGL3(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
// {
// 	establishMatrix3(lx,ly,width,height);

// 	glDisable(GL_SCISSOR_TEST);
// 	glClearColor(0.0f,1.0f,1.0f,1.0f);
// 	glScissor(lx,ly,width,height);
// 	glEnable(GL_SCISSOR_TEST);

// 	glClearColor(0.80f,0.70f,0.90f,1.0f);

// 	glEnable(GL_DEPTH_TEST);
// 	glDepthFunc(GL_LEQUAL);
// 	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
// 	glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
// }	

void establishMatrix4(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
}

void initGL4(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix4(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.50f,0.50f,0.50f,1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}	

void establishMatrix3(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
	glOrtho(-3.0,3.0,-3.0,3.0,-3.0,200.0);
}

void initGL3(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix3(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.00f,0.00f,0.00f,1.0f);

	// glEnable(GL_DEPTH_TEST);
	// glDepthFunc(GL_LEQUAL);
	// glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	// glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}	

void establishMatrix6(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
	glOrtho(-3.0,3.0,-3.0,3.0,-3.0,200.0);
}

void initGL6(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix6(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.00f,0.00f,0.00f,1.0f);

	// glEnable(GL_DEPTH_TEST);
	// glDepthFunc(GL_LEQUAL);
	// glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	// glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}	

void establishMatrix7(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
	glOrtho(-3.0,3.0,-3.0,3.0,-3.0,200.0);
}

void initGL7(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix7(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.00f,0.00f,0.00f,1.0f);

	// glEnable(GL_DEPTH_TEST);
	// glDepthFunc(GL_LEQUAL);
	// glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	// glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}	


void establishMatrix8(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
	glOrtho(-3.0,3.0,-3.0,3.0,-3.0,200.0);
}

void initGL8(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix8(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.00f,0.00f,0.00f,1.0f);

	// glEnable(GL_DEPTH_TEST);
	// glDepthFunc(GL_LEQUAL);
	// glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	// glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}	


void establishMatrix9(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
	glOrtho(-3.0,3.0,-3.0,3.0,-3.0,200.0);
}

void initGL9(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix9(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.00f,0.00f,0.00f,1.0f);

	// glEnable(GL_DEPTH_TEST);
	// glDepthFunc(GL_LEQUAL);
	// glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	// glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}	


void establishMatrix5(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	glViewport(lx,ly,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
}

void initGL5(GLsizei lx, GLsizei ly, GLsizei width, GLsizei height)
{
	establishMatrix4(lx,ly,width,height);

	glDisable(GL_SCISSOR_TEST);
	glClearColor(0.0f,1.0f,1.0f,1.0f);
	glScissor(lx,ly,width,height);
	glEnable(GL_SCISSOR_TEST);

	glClearColor(0.50f,0.90f,0.10f,1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_PERSPECTIVE_CORRECTION_HINT);
}	
