#include <Display.h>
#include<iostream>
using namespace std;
// void print(Projection p){
// 	cout<<p.nop<<"\n";
// 	for(int i=0;i<p.nop;i++)
// 		cout<<p.nodes[i].x<<" "<<p.nodes[i].y<<" "<<p.nodes[i].z<<endl;
// 	for(int i=0;i<p.nop;i++){
// 		vector<int> v=p.edges[i];
// 		cout<<i<<" ";
// 		for(int j=0;j<v.size();j++){
// 			cout<<v[j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// }
void Display::Display_2d(OrthographicView o){
	print(o.topView);
	print(o.frontView);
	print(o.sideView);
}