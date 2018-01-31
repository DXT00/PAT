#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N;
struct Node
{
	int data, left, right;
	Node() :left(-1), right(-1){}
};
vector<Node> v;
int last;
int find_root(vector<int> &visited){
	for (int i = 0; i < N; i++)
		if (visited[i] == false)
			return i;
}
bool judge(int root){
	int cnt = 0;
	queue<Node> q;
	q.push(v[root]);
	cnt++;
	while (!q.empty())
	{
		Node w = q.front();
		q.pop();
		if (w.left != -1){
			q.push(v[w.left]);
			cnt++;
			if (cnt == N){
				last = w.left;
			}
		}
		else{
			if (cnt < N)return false;
		}
		if (w.right != -1){
			q.push(v[w.right]);
			cnt++;
			if (cnt == N)
				last = w.right;
		}
		else
		{
			if (cnt < N)return false;
		}
	}
	return true;

}
int main(int argc, char const *argv[])
{
	string l, r;
	scanf_s("%d", &N);
	int root;
	v.assign(N, Node());
	vector<int> visited(N, false);
	for (int i = 0; i < N; i++)
	{
		cin >> l >> r;
		v[i].data = i;
		if (l != "-"){
			v[i].left = stoi(l);
			visited[v[i].left] = true;
		}
		if (r != "-"){
			v[i].right = stoi(r);
			visited[v[i].right] = true;
		}
	}
	root = find_root(visited);
	if (judge(root)){
		printf("YES %d\n", last);
	}
	else
		printf("NO %d\n", root);
	system("pause");
	return 0;
}