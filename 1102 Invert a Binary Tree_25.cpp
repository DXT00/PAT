/*
压根就不需要dfs来反转二叉树再遍历，
只要在遍历时先遍历右孩子，再遍历左孩子即可，bfs-->就相当于右孩子先入队，左孩子再入队；in_order--->相当于右左根遍历

（还有一种更狠的方法：输入时直接把每个节点的左右孩子调换输入就好了！）

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;
struct Node{
	int left, right, data;
};
int N, root;
int visited[15];
std::vector<Node> v;
void bfs(){
	queue<Node> q;
	int c = 0;
	q.push(v[root]);
	while (!q.empty()){
		Node w = q.front();
		q.pop();
		if (c != 0)printf(" ");
		printf("%d", w.data);
		c++;
		if (w.right != -1)
			q.push(v[w.right]);
		if (w.left != -1)
			q.push(v[w.left]);
	}
	printf("\n");
}
int c2 = 0;
void in_order(int root){
	if (root == -1)return;
	in_order(v[root].right);
	if (c2 != 0)printf(" ");
	printf("%d", v[root].data);
	c2++;
	in_order(v[root].left);

}
int main(int argc, char const *argv[])
{
	scanf_s("%d", &N);
	v.assign(N, Node());
	string s1, s2;
	for (int i = 0; i <N; ++i){
		cin >> s1 >> s2;
		v[i].data = i;
		v[i].left = (s1[0] == '-') ? -1 : stoi(s1);
		v[i].right = (s2[0] == '-') ? -1 : stoi(s2);
		if (s1[0] != '-')visited[stoi(s1)] = 1;
		if (s2[0] != '-')visited[stoi(s2)] = 1;
	}
	for (int i = 0; i <N; ++i){
		if (visited[i] == 0){
			root = i;
			break;
		}
	}
	bfs();
	in_order(root);
	system("pause");
	return 0;
}



// #include <vector>
// #include <stdio.h>
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <queue>
// using namespace std;
// int N;
// struct Node
// {
// 	int left, right, data;
// 	Node() :left(-1), right(-1), data(-1){}
// };
// vector<Node> v;
// std::vector<bool> visited(10, false);
// void invert(vector<Node> &v, int root){
// 	int tmp;
// 	if (root == -1)return;
// 	invert(v, v[root].left);
// 	invert(v, v[root].right);
// 	tmp = v[root].left;
// 	v[root].left = v[root].right;
// 	v[root].right = tmp;
// }
// int cnt1 = 0,cnt2=0;
// void bfs(vector<Node> &v, int root){
// 	queue<Node> q;
// 	q.push(v[root]);
// 	while (!q.empty()){
// 		Node w = q.front();
// 		if (cnt2 != 0)printf(" ");
// 		printf("%d", w.data);
// 		cnt2++;
// 		q.pop();
// 		if (w.left != -1)
// 			q.push(v[w.left]);
// 		if (w.right != -1){
// 			q.push(v[w.right]);
// 		}
// 	}
// }
// void in_order(vector<Node> &v, int root){
// 	if (root == -1)return;
// 	in_order(v, v[root].left);
// 	if (cnt1 != 0)printf(" ");
// 	printf("%d", v[root].data);
// 	cnt1++;
// 	in_order(v, v[root].right);
// }
// int main(int argc, char const *argv[])
// {
// 	string lstr, rstr;
// 	scanf("%d", &N);
// 	v.assign(N, Node());
// 	int root;
// 	for (int i = 0; i <N; ++i)
// 	{
// 		cin >> lstr >> rstr;
// 		if (lstr != "-")visited[lstr[0] - '0'] = true;
// 		if (rstr != "-")visited[rstr[0] - '0'] = true;
// 		v[i].left = (lstr == "-") ? -1 : (lstr[0] - '0');
// 		v[i].right = (rstr == "-") ? -1 : (rstr[0] - '0');
// 		v[i].data = i;
// 	}
// 	//find root
// 	for (int i = 0; i <N; ++i)
// 		if (visited[i] == false)root = i;
	
// 	invert(v, root);
// 	bfs(v, root);
// 	printf("\n");
// 	in_order(v, root);
// 	printf("\n");
// 	getchar();
// 	system("pause");
// 	return 0;
// }
