#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>
using namespace std;
int N, x, y;
vector<int> cur;
vector<vector<int> > v;

set<int>longest,res;
set<int>::iterator it;
int MAXlevel = -1,first;


std::vector<bool> visited;
void dfs(int x,int level){
	if(level>MAXlevel){
			MAXlevel=level;
			longest.clear();
			longest.insert(x);
		}
		else if(level==MAXlevel){
			longest.insert(x);
		}

	for (int i = 0; i <v[x].size(); ++i){
		if(visited[v[x][i]]==false){
			visited[v[x][i]]=true;
			dfs(v[x][i],level+1);
		}
	}
	
}
int liantong(){
	int lian=0;
	for (int i = 1; i <=N; ++i){
		if(visited[i]==false){
			visited[i]=true;
			dfs(i,0);
			lian++;
			if(i==1){
				it=longest.begin();
				first=*it;
				for (; it!=longest.end();it++)
					res.insert(*it);
				
			}
		}
	}
	return lian;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	v.assign(N + 1, cur);
	visited.assign(N+1,false);
	for (int i = 0; i <N - 1; ++i){
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int reslian=liantong();
	
	if(reslian!=1)
		printf("Error: %d components\n", reslian);
	else{
		visited.assign(N+1,false);
		longest.clear();
		MAXlevel=-1;
		visited[first]=true;
		dfs(first,0);
		for (it = longest.begin(); it != longest.end(); it++)
			res.insert(*it);
		for (it = res.begin(); it != res.end(); it++)
			printf("%d\n",*it );
	}
 
	system("pause");
	return 0;
}