#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
int N,M,S,root,k;
using namespace std;
int weight[105];
vector<int> v[105];
vector<vector<int> > res;
bool cmp(int a,int b){return weight[a]>weight[b];}
void dfs(int root,vector<int>path,int sum){
	sum+=weight[root];
	path.push_back(weight[root]);
	if(v[root].size()==0&&sum==S){
		res.push_back(path);
		return;
	}
	for (int i = 0; i <v[root].size(); ++i)
		dfs(v[root][i],path,sum);
	
	sum-=weight[root];
	path.pop_back();
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&N,&M,&S);
	for (int i = 0; i <N; ++i)
		scanf("%d",&weight[i]);
	for (int i = 0; i <M; ++i){
		scanf("%d%d",&root,&k);
		vector<int> cur(k,0);
		for (int j = 0; j <k; ++j)
			scanf("%d",&cur[j]);
		sort(cur.begin(),cur.end(),cmp);
		v[root]=cur;
	}
	vector<int>path;
	dfs(0,path,0);
	for (int i = 0; i <res.size(); ++i){
		for (int j = 0; j <res[i].size(); ++j){
			if(j!=0)printf(" ");
			printf("%d",res[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}