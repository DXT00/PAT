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
	int left, right, data;
	Node() :left(-1), right(-1), data(-1){}
};
vector<Node> v;
std::vector<bool> visited(10, false);
void invert(vector<Node> &v, int root){
	int tmp;
	if (root == -1)return;
	invert(v, v[root].left);
	invert(v, v[root].right);
	tmp = v[root].left;
	v[root].left = v[root].right;
	v[root].right = tmp;
}
int cnt1 = 0,cnt2=0;
void bfs(vector<Node> &v, int root){
	queue<Node> q;
	q.push(v[root]);
	while (!q.empty()){
		Node w = q.front();
		if (cnt2 != 0)printf(" ");
		printf("%d", w.data);
		cnt2++;
		q.pop();
		if (w.left != -1)
			q.push(v[w.left]);
		if (w.right != -1){
			q.push(v[w.right]);
		}
	}
}
void in_order(vector<Node> &v, int root){
	if (root == -1)return;
	in_order(v, v[root].left);
	if (cnt1 != 0)printf(" ");
	printf("%d", v[root].data);
	cnt1++;
	in_order(v, v[root].right);
}
int main(int argc, char const *argv[])
{
	string lstr, rstr;
	scanf("%d", &N);
	v.assign(N, Node());
	int root;
	for (int i = 0; i <N; ++i)
	{
		cin >> lstr >> rstr;
		if (lstr != "-")visited[lstr[0] - '0'] = true;
		if (rstr != "-")visited[rstr[0] - '0'] = true;
		v[i].left = (lstr == "-") ? -1 : (lstr[0] - '0');
		v[i].right = (rstr == "-") ? -1 : (rstr[0] - '0');
		v[i].data = i;
	}
	//find root
	for (int i = 0; i <N; ++i)
		if (visited[i] == false)root = i;
	
	invert(v, root);
	bfs(v, root);
	printf("\n");
	in_order(v, root);
	printf("\n");
	getchar();
	system("pause");
	return 0;
}