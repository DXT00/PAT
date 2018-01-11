#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;
int N, L, k, x, qr, query;
int find(vector<vector<int> > &v, int qr){
	std::vector<bool> visited(N + 1, false);
	visited[qr] = true;
	queue<int> q;
	int cnt = 0;
	int res = 0;
	int cur;
	int tail;
	for (int i = 0; i <v[qr].size(); ++i)
	{
		if (visited[v[qr][i]] == false){
			visited[v[qr][i]] = true;			
			q.push(v[qr][i]);
			tail = v[qr][i];
		}
	}
	while (cnt<L&&!q.empty()){
		int w = q.front();
		q.pop();
		res++;

			for (int i = 0; i <v[w].size(); ++i)
			{
				if (visited[v[w][i]] == false){
					visited[v[w][i]] = true;
					
					q.push(v[w][i]);
					//if (w==tail)
						cur= v[w][i];
				}
				
			}
			if (w == tail){   /*经典求bfs层数cnt模型！！*/
				tail = cur;
				cnt++;
			}
	}
	return res;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &L);
	std::vector<int> cur(N + 1, 0);
	std::vector<vector<int> > v(N + 1);//只记录入度
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &k);
		for (int j = 0; j <k; ++j)
		{
			scanf("%d", &x);
			v[x].push_back(i);
		}
	}
	scanf("%d", &query);
	for (int i = 0; i <query; ++i)
	{
		scanf("%d", &qr);
		cout << find(v, qr) << endl;
	}
	getchar();
	system("pause");
	return 0;
}