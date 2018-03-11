void clicks(int x, int y)
{
	cout << x <<"  :  "<<y <<'\n';
	if(x>80 && x<130 && y<70 && y>20)
	{
		cout<<"button 1 pressed draw line\n";
	}
	if(x>200 && x < 250 && y < 70 && y > 20)
	{
		cout << "button 2 presed draw rectangle\n";
	}
	if(x>80 && x<130 && y<150 && y>100)
	{
		cout<<"button 3 pressed rotate up\n";
	}
	if(x>200 && x < 250 && y <150 && y >100)
	{
		cout << "button 4 presed rotate down\n";
	}
	if(x>80 && x<130 && y<230 && y>180)
	{
		cout<<"button 5 pressed rotate left\n";
	}
	if(x>200 && x < 250 && y <230 && y >180)
	{
		cout << "button 6 presed rotate right\n";
	}
	if(x>80 && x<130 && y<310 && y>260)
	{
		cout<<"button 7 pressed reset x rotation\n";
	}
	if(x>200 && x < 250 && y <310 && y > 260)
	{
		cout << "button 8 presed reset y rotation\n";
	}
	if(x>80 && x<130 && y<390 && y>340)
	{
		cout<<"button 9 pressed \n";
	}
	if(x>200 && x < 250 && y <390 && y > 340)
	{
		cout << "button 10 presed reset y rotation\n";
	}
}