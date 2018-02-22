/*
//不要漏了记录pathCnt[]-->到达每个节点的最短路径条数！！！
不是单纯的加1！！
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#define inf 99999999
using namespace std;
int N, M, D, S, k, le;
string str,str1,str2;
vector<int> v[20000];
int happy[20000];
int weight[20000][20000];
int change(string s){
	int res = 0, ten = 1;
	for (int i = 2; i >= 0; i--){
		res += ten*(s[i] - 'A');
		ten *= 26;
	}
	return res;
}
void Djistra(){
	bool visited[20000];
	int dist[20000], cnt[20000],hap[20000],path[20000],pathCnt[20000];
	int min = S;

	fill(visited, visited + 20000, false);
	fill(path, path + 20000, -1);
	fill(dist, dist + 20000, inf);
	dist[min] = 0;
	pathCnt[min]=1;
	hap[min] = 0;
	cnt[min] = 0;
	visited[min] = true;
	while (true){

		for (int i = 0; i <v[min].size(); ++i){
			int j = v[min][i];
			if (visited[j] == false){
				if (dist[min] + weight[min][j]<dist[j]){
					dist[j] = dist[min] + weight[min][j];
					hap[j] = happy[j] + hap[min];
					cnt[j] = cnt[min] + 1;
					pathCnt[j]=pathCnt[min];//不要漏了记录pathCnt[]-->到达每个节点的最短路径条数！！！
					path[j] = min;
				}
				else if (dist[min] + weight[min][j] == dist[j]){
					pathCnt[j]=pathCnt[j]+pathCnt[min];
					if (hap[min] + happy[j]>hap[j]){
						hap[j] = hap[min] + happy[j];
						cnt[j] = cnt[min] + 1;
						path[j] = min;
					}
					else if (hap[min] + happy[j] == hap[j]){
						if ((hap[min] + happy[j])/(cnt[min] + 1)>hap[j]/cnt[j]){
							cnt[j] = cnt[min] + 1;
							path[j] = min;
						}
					}
				}
			}
		}
		int MIN = inf, MIN_i;
		for (int i = 0; i <20000; ++i){
			if (visited[i] == false){
				if (dist[i]<MIN){
					MIN = dist[i];
					MIN_i = i;
				}
			}
		}
		min = MIN_i;
		visited[min] = true;
		if (min == D)break;

	}
	int cur = D;
	std::vector<int> res;
	while (cur != -1){
		res.push_back(cur);
		cur = path[cur];
	}
	cout << pathCnt[D] << " " << dist[D] << " " << hap[D] << " " << hap[D] / cnt[D] << endl;
	for (int i = res.size() - 1; i >= 0; i--){
		if (i != res.size() - 1)printf("->");
		printf("%c%c%c", res[i] / 26 / 26 + 'A', res[i] / 26 % 26 + 'A', res[i] % 26 + 'A');

	}
}
int main(int argc, char const *argv[])
{
	
	D = change("ROM");
	scanf("%d%d", &N, &M);
	cin>>str;
	S = change(str);
	happy[S] = 0;

	for (int i = 0; i <N - 1; ++i){
		cin>>str;
		scanf("%d",&k);
		happy[change(str)] = k;
	}
	for (int i = 0; i < M; ++i){
		cin>>str1>>str2;
		scanf("%d",  &le);
		int x = change(str1);
		int y = change(str2);
		v[x].push_back(y);
		v[y].push_back(x);
		weight[x][y] = weight[y][x] = le;
	}
	Djistra();
	system("pause");
	return 0;
}