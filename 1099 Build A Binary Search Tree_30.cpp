/*
不需要bfs了，直接再dfs中记录层数就好
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;
int N,k=0;
struct Node
{
	int data,left,right;
	Node():left(-1),right(-1){}
};
std::vector<Node> v;
std::vector<int> level[105];
std::vector<int> inorder;
void dfs(int root,int le){
	if(root==-1)return;
	dfs(v[root].left,le+1);
	v[root].data=inorder[k++];
	level[le].push_back(v[root].data);
	dfs(v[root].right,le+1);
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	v.assign(N,Node());
	for (int i = 0; i <N; ++i)
	{
		scanf("%d%d",&v[i].left,&v[i].right);
	}
	inorder.assign(N,0);
	for (int i = 0; i <N; ++i)
	{
		scanf("%d",&inorder[i]);
	}
	sort(inorder.begin(), inorder.end());
	dfs(0,0);
	int c=0;
	for (int i = 0; level[i].size()>0; ++i)
	{
		for (int j = 0; j <level[i].size(); ++j)
		{
			if(c!=0)printf(" ");
			printf("%d",level[i][j]);
			c++;
		}
	}
	system("pause");
	return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <stdio.h>
// #include <queue>
// using namespace std;
// int N,x,y,k=0;
// struct Node{
// 	int left,right,data;	
// };
// std::vector<Node> v;
// std::vector<int> order;
// void dfs(int root){
// 	if(root==-1)return;
// 	dfs(v[root].left);
// 	v[root].data=order[k++];
// 	dfs(v[root].right);
// }
// void bfs(){
// 	queue<int> q;
// 	int c=0;
// 	q.push(0);
// 	while(!q.empty()){
// 		int w=q.front();
// 		q.pop();
// 		if(c!=0)
// 			printf(" ");
// 		printf("%d",v[w].data);
// 		c++;
// 		if(v[w].left!=-1)q.push(v[w].left);
// 		if(v[w].right!=-1)q.push(v[w].right);
// 	}
// }
// int main(int argc, char const *argv[])
// {
// 	scanf("%d",&N);
// 	v.assign(N,Node());
// 	order.assign(N,0);
// 	for (int i = 0; i <N; ++i){
// 		scanf("%d%d",&v[i].left,&v[i].right);
// 	}
// 	for (int i = 0; i <N; ++i)
// 		scanf("%d",&order[i]);
// 	sort(order.begin(), order.end());
// 	dfs(0);
// 	bfs();
// 	system("pause");
// 	return 0;
// }
