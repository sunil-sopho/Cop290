#include <iostream>
#include<vector>
using namespace std;

int graph[][2]=
     {
            {1, 2}, {1, 3}, {1, 4}, {2, 3},
            {3, 4}, {2, 6}, {4, 6}, {7, 8},
            {8, 9}, {9, 7}, {6, 9}, {3 ,7}
     };
vector<vector<int>> cycles;

int smallest(vector<int> path){
	int min=path[0];
	for(int i=0;i<path.size();i++){
		if(path[i]<min)
			min=path[i];
	}
	return min;
}

vector<int> normalize(vector<int> path){
	// for(int i=0;i<path.size();i++)
	// 	cout<<path[i]<<" ";
	// cout<<endl;
	int p[path.size()];
	// int p[l];
	int l=path.size();
	int x=smallest(path);
	int n;
	for(int i=0;i<l;i++)
		p[i]=path[i];
	while(p[0]!=x){
		n=p[0];
		for(int i=0;i<l-1;i++)
			p[i]=p[i+1];
		p[l-1]=n;
	}
	vector<int> v;
	for(int i=0;i<l;i++)
		v.push_back(p[i]);
	return v;
}

bool equals(vector<int> a,vector<int> b){
	bool ret=(a[0]==b[0]) && (a.size()==b.size());
	for(int i=1;ret && (i<a.size());i++){
		if(a[i]!=b[i])
			ret=false;
	}
	return ret;
}
vector<int> invert(vector<int> path){
	vector<int> v;
	// int p[l];
	for(int i=0;i<path.size();i++){
		v.push_back(path[path.size()-1-i]);
	}
	return normalize(v);
}

bool isNew(vector<int> path){
	bool ret=1;
	for(int i=0;i<cycles.size();i++){
		vector<int> v=cycles[i];

		if(equals(v,path)){
			ret=0;
			break;
		}
	}
	return ret;
}
bool visited(int n,vector<int> path){
	bool ret=0;
	for(int i=0;i<path.size();i++){
		if(path[i]==n){
			ret=1;
			break;
		}
	}
	return ret;
}

void findNewCycles(vector<int> path){
	int n=path[0];
	int x;
	vector<int> sub(path.size()+1);
	// int sub[l+1];
	for(int i=0;i<path.size();i++){
		// sub.push_back(path[i]);
		sub[i+1]=path[i];
	}

	for(int i=0;i<12;i++){
		for(int y=0;y<=1;y++){
			if(graph[i][y]==n){
				x=graph[i][(y+1)%2];
				if(!visited(x,path)){
					//sub.push_back(x);
					sub[0]=x;
					//for(int i=0;i<)
					findNewCycles(sub);
				}
				else if(path.size()>2 && x==path[path.size()-1]){
					vector<int> p=normalize(path);
					vector<int> inv=invert(p);
					if(isNew(p) && isNew(inv)){
						// vector<int> z;
						// for(int i=0;i<l;i++)
						// 	z.push_back(p[i]);
						cycles.push_back(p);
					}
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	for(int i=0;i<12;i++){
		for(int j=0;j<2;j++){
			// int x[]={graph[i][j]};
			vector<int> x;
			x.push_back(graph[i][j]);
			findNewCycles(x);
		}
	}

	for(int i=0;i<cycles.size();i++){
		vector<int> v=cycles[i];
		for(int j=0;j<v.size();j++){
			cout<<v[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}