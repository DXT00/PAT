#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define inf 99999999
int N, M, S, D, x, y, co, di;
vector<int> v[502];
int cost[502][502], len[502][502],dist[502], costt[502], path[502];
bool visited[502];
void Dijstra(){

	int min = S;
	fill(dist, dist + 502, inf);
	fill(costt, costt + 502, inf);
	fill(path, path + 502,-1);
	fill(visited, visited + 502, false);
	dist[min] = 0;
	costt[min] = 0;
	visited[min] = true;
	while (true){
		for (int i = 0; i <v[min].size(); ++i){
			int j = v[min][i];
			if (visited[j] == false){
				if (dist[min] + len[min][j]<dist[j]){
					dist[j] = dist[min] + len[min][j];
					costt[j] = costt[min] + cost[min][j];
					path[j] = min;
				}
				else if (dist[min] + len[min][j] == dist[j]){
					if (costt[min] + cost[min][j]<costt[j]){
						costt[j] = costt[min] + cost[min][j];
						path[j] = min;
					}
				}
			}
		}
		int MIN = inf, MIN_i;
		for (int i = 0; i <N; ++i){
			if (visited[i] == false && dist[i]<MIN){
				MIN = dist[i];
				MIN_i = i;
			}
		}
		min = MIN_i;
		visited[min] = true;
		if (min == D)break;
	}
	 vector<int>res;
	 int cur=D;
	 while(cur!=-1){
	 	res.push_back(cur);
	 	cur=path[cur];
	 }
	 for (int i = res.size()-1; i>=0;i--){
	 	if(i!=res.size()-1)printf(" ");
	 	printf("%d",res[i]);
	 }
	printf(" %d %d\n", dist[D], costt[D]);

}
int main(int argc, char const *argv[]){
	scanf("%d%d%d%d", &N, &M, &S, &D);
	for (int i = 0; i <M; ++i){
		scanf("%d%d%d%d", &x, &y, &di, &co);
		v[x].push_back(y);
		v[y].push_back(x);
		len[x][y] = len[y][x] = di;
		cost[x][y] = cost[y][x] = co;
	}
	Dijstra();
	system("pause");
	return 0;
}