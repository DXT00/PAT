#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
int N,x,y,k=0;
struct Node{
	int left,right,data;	
};
std::vector<Node> v;
std::vector<int> order;
void dfs(int root){
	if(root==-1)return;
	dfs(v[root].left);
	v[root].data=order[k++];
	dfs(v[root].right);
}
void bfs(){
	queue<int> q;
	int c=0;
	q.push(0);
	while(!q.empty()){
		int w=q.front();
		q.pop();
		if(c!=0)
			printf(" ");
		printf("%d",v[w].data);
		c++;
		if(v[w].left!=-1)q.push(v[w].left);
		if(v[w].right!=-1)q.push(v[w].right);
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	v.assign(N,Node());
	order.assign(N,0);
	for (int i = 0; i <N; ++i){
		scanf("%d%d",&v[i].left,&v[i].right);
	}
	for (int i = 0; i <N; ++i)
		scanf("%d",&order[i]);
	sort(order.begin(), order.end());
	dfs(0);
	bfs();
	system("pause");
	return 0;
}
