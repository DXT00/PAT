/*
用dfs的话要用set,而且会超时，所以还是用bfs！！
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int N, L, k, x, Q, num;
vector<int> v[1005];
void bfs(int y){
	int level[1005];
	bool visited[1005];
	fill(visited,visited+1005,false);
	int x=y,cnt=0;;
	level[x]=0;
	visited[x]=true;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int w=q.front();
		if(level[w]<=L)cnt++;
		//else break;
		q.pop();
		for (int i = 0; i <v[w].size(); ++i)
		{
			int j=v[w][i];
			if(visited[j]==false){
				visited[j]=true;
				level[j]=level[w]+1;
				q.push(j);
			}
		}
	}
	cout<<cnt-1<<endl;

}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &L);

	for (int i = 1; i <= N; ++i){
		scanf("%d", &k);
		for (int j = 0; j <k; ++j){
			scanf("%d", &x);
			v[x].push_back(i);
		}
	}
	scanf("%d", &Q);
	for (int i = 0; i <Q; ++i){
		scanf("%d", &x);
		bfs(x);
	}
	system("pause");
	return 0;
}
