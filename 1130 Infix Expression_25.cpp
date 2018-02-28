#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int N;
struct Node
{
	string data;
	int left,right;
};
std::vector<Node> v;
char na[15];
int Root;
std::vector<bool> visited;
void dfs(int root){
	if(root==-1)return;
	if(root!=Root&&!(v[root].left==-1&&v[root].right==-1))//只要不是根节点并且不是叶子节点就加括号！
		printf("(");
	dfs(v[root].left);
	printf("%s",v[root].data.c_str());
	dfs(v[root].right);
	if(root!=Root&&!(v[root].left==-1&&v[root].right==-1))
		printf(")");
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	visited.assign(N+1,false);
	v.assign(N+1,Node());
	for (int i = 1; i <=N; ++i){
		scanf("%s%d%d",na,&v[i].left,&v[i].right);
		v[i].data=string(na);
		if(v[i].left!=-1)
			visited[v[i].left]=true;
		if(v[i].right!=-1)
			visited[v[i].right]=true;
	}
	for (int i = 1; i <=N; ++i)
	{
		if(visited[i]==false){
			Root=i;
			break;
		}
	}
	dfs(Root);
	system("pause");
	return 0;
}