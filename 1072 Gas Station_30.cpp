#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#define inf 99999999
using namespace std;
int N, M, K, Ds, le, x, y;
string p1, p2;
int len[1050][1050];
vector<int> v[1050];
double avg[1050];
int Dijstra(int start){
	int MINLEN = inf, total = 0, min = start;
	vector<bool> visited(N + M + 1, false);
	vector<int> dist(N + M + 1, inf);
	visited[min] = true;
	dist[min] = 0;
	while (true){
		for (int i = 0; i <v[min].size(); ++i){
			int j = v[min][i];
			if (visited[j] == false){
				if (dist[min] + len[min][j]<dist[j]){
					dist[j] = dist[min] + len[min][j];
				}
			}
		}
		int MIN = inf, MIN_i;
		for (int i = 1; i <dist.size(); ++i){
			if (visited[i] == false){
				if (dist[i]<MIN){
					MIN = dist[i];
					MIN_i = i;
				}
			}
		}
		if (MIN == inf)break;//遍历完毕
		min = MIN_i;
		visited[min] = true;
		if (min >= 1 && min <= N){
			if(dist[min]>Ds)return -1;
			if (dist[min]<MINLEN)MINLEN = dist[min];
				total += dist[min];
		}	
	}
	avg[start] = (double)total / N;
	return MINLEN;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d", &N, &M, &K, &Ds);
	for (int i = 0; i <K; ++i){
		cin >> p1 >> p2 >> le;
		x = (p1[0] == 'G') ? (stoi(p1.substr(1)) + N) : (stoi(p1));
		y = (p2[0] == 'G') ? (stoi(p2.substr(1)) + N) : (stoi(p2));
		v[x].push_back(y);
		v[y].push_back(x);
		len[x][y] = len[y][x] = le;
	}
	int cur,res_dist = -1,res_i;
	double res_avg = inf;
	for (int i = N + 1; i <= N + M; ++i){
		cur = Dijstra(i);
		if (cur == -1)continue;//超出Ds了
		else{
			if (cur>res_dist){
				res_dist = cur;
				res_avg = avg[i];
				res_i = i;
			}
			else if (cur == res_dist){
				if (avg[i]<res_avg){
					res_avg = avg[i];
					res_i = i;
				}
			}
		}
	}
	if (res_dist == -1)printf("No Solution\n");
	else{
		cout << "G" << res_i - N << endl;
		printf("%.1lf %.1lf\n", (double)res_dist, res_avg);
	}
	system("pause");
	return 0;
}
