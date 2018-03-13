#include "construct.h"
void clicks(int x, int y)
{
	cout << x <<"  :  "<<y <<'\n';
	if(x>65 && x<105 && y<60 && y>20)
	{
		cout<<"button 1 pressed point\n";
		int x,y,z;
		cin >> x >> y >> z;
		node n ;
		n.setCode(1);
		n.setP(1,x,y,z);
		v.push_back(n);
	}
	if(x>230 && x < 270 && y < 60 && y > 20)
	{
		cout << "button 2 presed draw line\n";
		int x,y,z;
		cin >> x >> y >> z;
		node n ;
		n.setCode(2);
		n.setP(1,x,y,z);
		cin >> x >> y >> z;
		n.setP(2,x,y,z);
		v.push_back(n);
	}
	if(x>60 && x<105 && y<120 && y>75)
	{
		cout<<"button 3 pressed triangle\n";
		int x,y,z;
		cin >> x >> y >> z;
		node n ;
		n.setCode(3);
		n.setP(1,x,y,z);
		cin >> x >> y >> z;
		n.setP(2,x,y,z);
		cin >> x >> y >> z;
		n.setP(3,x,y,z);
		v.push_back(n);
	}
	if(x>230 && x < 270 && y <120 && y >75)
	{
		cout << "button 4 presed quad\n";
		int x,y,z;
		cin >> x >> y >> z;
		node n ;
		n.setCode(4);
		n.setP(1,x,y,z);
		cin >> x >> y >> z;
		n.setP(2,x,y,z);
		cin >> x >> y >> z;
		n.setP(3,x,y,z);
		cin >> x >> y >> z;
		n.setP(4,x,y,z);
		v.push_back(n);
	}
	if(x>60 && x<105 && y< 175 && y> 130)
	{
		cout<<"button 5 pressed rotate left\n";
	}
	if(x>230 && x < 270 && y < 175 && y >130)
	{
		cout << "button 6 presed rotate right\n";
	}
	if( x > 60 && x<105 && y< 235 && y > 190)
	{
		cout<<"button 7 pressed reset x rotation\n";
	}
	if(x>230 && x < 270 && y <235 && y > 190)
	{
		cout << "button 8 presed reset y rotation\n";
	}
	if(x> 65 && x<105 && y < 295 && y > 250)
	{
		cout<<"button 9 pressed \n";
	}
	if(x> 230 && x < 270 && y <295 && y > 250)
	{
		cout << "button 10 presed reset y rotation\n";
	}
	if(x > 325 && x <1000 &&y>0&&y<300)
	{
		// point *p = new point();
		// p.setC(x,y,0.0f);
		// addPoint(p);
		// node n ;
		// n.setCode(2);
		// n.setP(1,0.0,0.0,0.0);
		// n.setP(2,5.0,5.0,5.0);
		// v.push_back(n);

	}
}