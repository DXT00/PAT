#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
//找连通分量
int N, M, K, x, y, q;
vector<int>cur;
vector<vector<int> >v;
void dfs(int x, vector<bool>&visited){//记得加引用，或者还可以直接把visited变为全局变量！
	for (int i = 0; i <v[x].size(); ++i){
		if (visited[v[x][i]] == false){
			visited[v[x][i]] = true;
			dfs(v[x][i], visited);
		}
	}
	return;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &N, &M, &K);
	v.assign(N + 1, cur);
	for (int i = 0; i <M; ++i){
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 0; i <K; ++i){
		vector<bool> visited(N + 1, false);
		scanf("%d", &q);
		visited[q] = true;
		int cnt = 0;
		for (int i = 1; i <= N; ++i){
			if (visited[i] == false){
				visited[i] = true;
				dfs(i, visited);
				cnt++;
			}
		}
		printf("%d\n",cnt-1 );
	}
	system("pause");
	return 0;
}