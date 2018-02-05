#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
int N, M, K, Ds;
struct Node
{
	double avg;
	double res_min;//理解好题意，排序的时候res_min大的优先！！
	int start;
	Node(double avg, int res_min, int start) :avg(avg), res_min(res_min), start(start){}
};
std::vector<int> cur;
std::vector<vector<int> > v;
std::vector<int> cur1;
std::vector<vector<int> > len;
std::vector<Node> res;
bool bfs(int start){
	std::vector<bool> visited(N + M + 1, false);
	std::vector<int> dist(N + M + 1, 1000000);
	int min = start;
	visited[start] = true;
	dist[start] = 0;
	while (true){
		for (int i = 0; i <v[min].size(); ++i)
		{
			int j = v[min][i];
			if (visited[j] == false){
				if (dist[min] + len[min][j]<dist[j])
				{
					dist[j] = dist[min] + len[min][j];
				}
			}
		}

		int MIN = 1000000, MIN_i;
		bool find = false;
		for (int i = 1; i <dist.size(); ++i)
		{
			if (visited[i] == false){
				if (dist[i]<MIN){
					MIN = dist[i];
					MIN_i = i;
					find = true;
				}
			}
		}
		if (find == false) break;
		min = MIN_i;
		visited[min] = true;
		if (min <= N&&dist[min]>Ds)return false;

	}
	int sum = 0, res_min = 1000000;
	for (int i = 1; i <= N&&i <dist.size(); ++i)
	{
		if (dist[i]<res_min)
			res_min = dist[i];
		sum += dist[i];
	}

	res.push_back(Node((double)sum / N, res_min, start - N));
	return true;

}
bool cmp(Node a,Node b){
	if (a.res_min != b.res_min)return a.res_min > b.res_min;
	else
	{
		if (a.avg != b.avg)return a.avg < b.avg;
		else
			return a.start < b.start;
	}
	
}
int main(int argc, char const *argv[])
{
	

	scanf("%d%d%d%d", &N, &M, &K, &Ds);
	v.assign(N + M + 1, cur);
	cur1.assign(N + M + 1, 0);
	len.assign(N + M + 1, cur1);

	for (int i = 0; i < K; ++i)
	{
		string p1, p2;
		int le;
		cin >> p1 >> p2 >> le;
		int x, y;

		x = (p1[0] == 'G') ? (stoi(p1.substr(1)) + N) : (stoi(p1));
		y = (p2[0] == 'G') ? (stoi(p2.substr(1)) + N) : (stoi(p2));
		len[x][y] = len[y][x] = le;
		v[x].push_back(y);
		v[y].push_back(x);
		
	}
	for (int i = N + 1; i <= N + 1 + M - 1; ++i)
	{
		if (bfs(i) == false)
			continue;
	}
	if (res.size() == 0)
		printf("No Solution\n");
	else{
		sort(res.begin(), res.end(), cmp);
		cout << "G" << res[0].start << endl;
		printf("%.1lf %.1lf", res[0].res_min, res[0].avg);
	}

	system("pause");
	return 0;
}