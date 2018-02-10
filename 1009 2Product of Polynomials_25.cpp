#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
struct Node
{
	int ex;
	double cof;
};
std::map<int, double> m;
std::map<int, double>::iterator it;
int N,M,x,y;
int main(int argc, char const *argv[])
{	
	
		scanf("%d",&N);
		vector<Node> v1(N,Node());
		for (int i = 0; i < N; ++i)
			scanf("%d%lf",&v1[i].ex,&v1[i].cof);
		
		scanf("%d",&M);
		vector<Node> v2(M,Node());
		for (int i = 0; i < M; ++i)
			scanf("%d%lf",&v2[i].ex,&v2[i].cof);
		
		for (int i = 0; i <N; ++i){
			for (int j = 0; j < M; ++j)
			{
				m[v1[i].ex+v2[j].ex]+=v1[i].cof*v2[j].cof;
				if(m[v1[i].ex+v2[j].ex]==0){
					it=m.find(v1[i].ex+v2[j].ex);
					if(it!=m.end())
						m.erase(it);
				}
			}
		}
	cout<<m.size();
	it=m.end();it--;
	for (;it!=m.begin();it--){
		printf(" %d %.1lf",it->first,it->second);
	}printf(" %d %.1lf",it->first,it->second);

	system("pause");
	return 0;
}