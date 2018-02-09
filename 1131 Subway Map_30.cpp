
/*
Dijstra算法每次都要找最小的dist-->即每次都要遍历10000次，速度太慢！！超时了！！
所以->用dfs
统计路径上的交换节点数方法：
	先用color[10000][10000]记录每两个节点间的路线号
	只要前两个节点的路线号与后两个节点的路线号不同-->中间那个必然是交换


*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define inf 99999999

int N, M, x, num, pre, start, endd;
std::vector<int> v[10000];
int color[10000][10000];
int visited[10000];
std::vector<int> path;

int transfer(vector<int> a){
	int precolor, curcolor;
	int transCnt = 0;
	for (int i = 1; i <a.size(); ++i)	{
		if (i == 1)precolor = color[a[i]][a[i - 1]];
		else{
			curcolor = color[a[i]][a[i - 1]];
			if (curcolor != precolor)transCnt++;
			precolor = curcolor;
		}
	}
	return transCnt;
}
int min_cnt;
int min_trans;
std::vector<int> resPath;
void dfs(int start, int endd, vector<int>path, int cnt){
	if (start == endd){
		if (cnt<min_cnt || (cnt == min_cnt&&transfer(path)<min_trans)){
			min_cnt = cnt;
			min_trans = transfer(path);
			resPath = path;
		}
	}
	for (int i = 0; i <v[start].size(); ++i){
		if (visited[v[start][i]] == 0){
			visited[v[start][i]] = 1;
			path.push_back(v[start][i]);
			dfs(v[start][i], endd, path, cnt + 1);
			path.pop_back();
			visited[v[start][i]] = 0;

		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i){
		scanf("%d", &x);
		for (int j = 0; j <x; ++j){
			scanf("%d", &num);
			m[num].insert(i);
			if (j == 0)pre = num;
			else{
				v[pre].push_back(num);
				v[num].push_back(pre);
				color[pre][num] = color[num][pre] = i;
				pre = num;
			}
		}
	}
	scanf("%d", &M);
	for (int i = 0; i <M; ++i)
	{
		scanf("%d%d", &start, &endd);

		min_cnt = inf;
		min_trans = inf;
		visited[start] = 1;
		path.push_back(start);
		dfs(start, endd, path, 0);
		path.pop_back();
		visited[start] = 0;

		cout << min_cnt << endl;
		int preStatin = start, curStation;
		int prec = color[resPath[0]][resPath[1]], curc;
		for (int i = 1; i + 1<resPath.size(); ++i){
			curc = color[resPath[i]][resPath[i + 1]];
			curStation = resPath[i];
			if (curc != prec){
				printf("Take Line#%d from %04d to %04d.\n", prec, preStatin, curStation);
				preStatin = curStation;
				prec = curc;
			}
		}printf("Take Line#%d from %04d to %04d.\n", prec, preStatin, endd);
	}
	system("pause");
	return 0;
}


// void Dijstra(int start, int endd){
// 	std::vector<bool> visited(10000, false);
// 	std::vector<int> dist(10000, inf);
// 	std::vector<int> trans(10000, inf);
// 	std::vector<int> path(10000, -1);
// 	int min = start;
// 	dist[min] = 0;
// 	trans[min] = (m[min].size()>1) ? 1 : 0;
// 	visited[min] = true;
// 	while (true){
// 		for (int i = 0; i <v[min].size(); ++i)
// 		{
// 			int j = v[min][i];
// 			if (visited[j] == false){
// 				if (dist[min] + 1<dist[j]){
// 					dist[j] = dist[min] + 1;
// 					path[j] = min;

// 					trans[j] = (m[j].size()>1) ? (trans[min] + 1) : trans[min];
// 				}
// 				else if (dist[min] + 1 == dist[j]){
// 					int cur_trans = (m[j].size()>1) ? (trans[min] + 1) : trans[min];
// 					if (cur_trans<trans[j]){
// 						trans[j] = cur_trans;
// 						path[j] = min;
// 					}
// 				}
// 			}
// 		}
// 		int MIN = inf, MIN_i;
// 		for (int i = 0; i <dist.size(); ++i)
// 		{
// 			if (visited[i] == false){
// 				if (dist[i]<MIN){
// 					MIN = dist[i];
// 					MIN_i = i;
// 				}
// 			}
// 		}
// 		min = MIN_i;
// 		visited[min] = true;
// 		if (min == endd)break;

// 	}
// 	cout << dist[endd] << endl;

// 	std::vector<int> res;
// 	std::vector<int> res_color;
// 	std::vector<bool> exist(N + 1, false);
// 	res.push_back(endd);

// 	int pre_i = endd;
// 	int i = path[endd];
// 	int transfer, cur_color;
// 	int pre_color = color[i][pre_i];
// 	res_color.push_back(pre_color);
// 	while (path[i] != -1){
// 		pre_i = i;
// 		i = path[i];
// 		cur_color = color[i][pre_i];
// 		if (cur_color != pre_color){
// 			res.push_back(pre_i);
// 			res_color.push_back(cur_color);
// 		}
// 		pre_color = cur_color;

// 	}
// 	res.push_back(start);

// 	for (int i = res.size() - 1,k=res_color.size()-1; i >= 1; i--,k--){
// 		printf("Take Line#%d from %04d to %04d.\n", res_color[k], res[i], res[i - 1]);
// 	}

// }