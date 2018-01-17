#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int M, N, L, T;
struct Node
{
	int x, y, z;
	Node(int x, int y, int z) :x(x), y(y), z(z){}
};
int v[80][1300][130];
bool visited[80][1300][130];
int X[6] = { 1, -1, 0, 0, 0, 0 };
int Y[6] = { 0, 0, 1, -1, 0, 0 };
int Z[6] = { 0, 0, 0, 0, 1, -1 };
bool judge(int x, int y, int z){
	if (x<0 || x >= M || y<0 || y >= N || z<0 || z >= L)return false;
	if (v[z][x][y] == 0 || visited[z][x][y] == true) return false;

	return true;
}
int bfs(int x, int y, int z){
	int cnt = 0;
	queue<Node> q;
	Node tmp = Node(x, y, z);
	q.push(tmp);
	while (!q.empty()){
		Node w = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i <6; ++i)
		{
			int tx = w.x + X[i];
			int ty = w.y + Y[i];
			int tz = w.z + Z[i];

			if (judge(tx, ty, tz)){
				visited[tz][tx][ty] = true;
				q.push(Node(tx, ty, tz));
				//cout << tx << " " << ty << " " << tz << endl;
			}
		}
	}
	if (cnt >= T)
		return cnt;
	else
		return 0;
}
int main(int argc, char const *argv[])
{
	int res = 0;
	scanf("%d%d%d%d", &M, &N, &L, &T);
	for (int i = 0; i <L; ++i)
		for (int j = 0; j <M; ++j)
			for (int k = 0; k < N; ++k)
				scanf("%d", &v[i][j][k]);

	for (int i = 0; i <L; ++i)
		for (int j = 0; j <M; ++j)
			for (int k = 0; k < N; ++k){
				if (v[i][j][k] == 1 && visited[i][j][k] == false){
					visited[i][j][k] = true;
					res += bfs(j, k, i);
				}
			}
	cout << res << endl;
	getchar();
	system("pause");
	return 0;
}

