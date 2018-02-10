/*
此题dfs、bfs都可以做，下面分别列出两种方法：
*/
/*方法一：dfs*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N,M,ro,x,y;
std::vector<int> v[105];
int level[100];
int MAX_level=-1;
void dfs(int root,int le){
	if(le>MAX_level)MAX_level=le;
	if(v[root].size()==0){
		level[le]++;
		return;
	}
	for (int i = 0; i <v[root].size(); ++i)
		dfs(v[root][i],le+1);
	
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	for (int i = 0; i <M; ++i){
		scanf("%d%d",&ro,&x);
		for (int j = 0; j <x; ++j){
			scanf("%d",&y);
			v[ro].push_back(y);
		}
	}
	dfs(1,0);
	for (int i = 0; i <=MAX_level; ++i)
	{
		if(i!=0)printf(" ");
		printf("%d",level[i]);
	}
	system("pause");
	return 0;
}

/*
方法二：bfs:
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <stdio.h>
using namespace std;
int N,M;

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	std::vector<int> res(100,0);//记录每一层的叶子结点数
	std::vector<int> level(N,0);//记录每个节点所在的层数
	std::vector<vector<int> > v(100);
	int node,k,x,maxlevel=-1;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d",&node,&k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&x);
			v[node].push_back(x);		
		}
	}
	cout<<v[1][0]<<endl;
	//bfs
	queue<int> q;
	level[1]=0;
	q.push(1);
	while(!q.empty()){
		int w=q.front();
		q.pop();
		maxlevel=max(maxlevel,level[w]);
		if(v[w].size()==0){res[level[w]]++;}
		else{
			for (int j = 0; j <v[w].size(); ++j)
			{
				q.push(v[w][j]);
				level[v[w][j]]=level[w]+1;
			}
		}
	}
	cout<<res[0];
	for (int i = 1; i <=maxlevel; ++i)
	{
		cout<<" "<<res[i];
	}cout<<endl;
	getchar();
	system("pause");
	return 0;
}

*/



