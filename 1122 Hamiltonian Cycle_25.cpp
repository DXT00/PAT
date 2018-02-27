#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

int N,M,x,y,k;
std::vector<int> cur;
std::vector<vector<int> > v;

int main(int argc, char const *argv[])
{

	scanf("%d%d",&N,&M);
	cur.assign(N+1,0);
	v.assign(N+1,cur);
	for (int i = 0; i <M; ++i){
		scanf("%d%d",&x,&y);
		v[x][y]=v[y][x]=1;
	}
	scanf("%d",&k);
	std::vector<int> G;
	std::vector<int> Time;
	bool flag=true;
	for (int i = 0; i <k; ++i)
	{
		flag=true;
		scanf("%d",&x);
		G.assign(x,0);
		Time.assign(x,0);
		for (int i = 0; i <x ; ++i)
			scanf("%d",&G[i]);
	
		if(x!=N+1||G[0]!=G[x-1]){
			flag=false;
			
		}
		else{
			Time[G[0]]++;
			for (int i = 1; i <x; ++i){
				if(v[G[i-1]][G[i]]==0){
					flag=false;
					break;
				}
				Time[G[i]]++;
				if(i!=x-1&&Time[G[i]]>=2){
					flag=false;
					break;
				}
			}
		}

		if(!flag)printf("NO\n");
		else 
			printf("YES\n");

	}
	system("pause");
	return 0;
}