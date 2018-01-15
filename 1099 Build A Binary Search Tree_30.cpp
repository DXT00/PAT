#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int N;
struct Node
{
	int left,right;
	int data;
};
std::vector<int> in_order;

void in_or(vector<Node> &v,int root){
	if(root==-1)return;

	in_or(v,v[root].left);
	in_order.push_back(root);
	in_or(v,v[root].right);
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	std::vector<Node> v(N);
	std::vector<int> num(N);	
	queue<int> q;
	for (int i = 0; i <N; ++i)
		scanf("%d%d",&v[i].left,&v[i].right);
	for (int i = 0; i <N; ++i)
		scanf("%d",&num[i]);
	in_or(v,0);
	sort(num.begin(), num.end());
	for (int i = 0; i <N; ++i)
	{
		v[in_order[i]].data=num[i];
	}
	q.push(0);
	while(!q.empty()){
		int w=q.front();
		q.pop();
		if(w!=0)printf(" ");
		printf("%d",v[w].data);
		if(v[w].left!=-1)q.push(v[w].left);
		if(v[w].right!=-1)q.push(v[w].right);
	}
	printf("\n");
	getchar();
	system("pause");
	return 0;
}