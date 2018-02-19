#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int N;
int in[1005],level[1005];
int num=0;
void dfs(int index){//就相当于中序遍历完全二叉树，然后依次往里头放中序遍历的数in[N]

	if(index>=N)
		return;
	dfs(2*index+1);//左孩子节点
	level[index]=in[num++];
	dfs(2*index+2);//右孩子节点
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for (int i = 0; i <N; ++i)
		scanf("%d",&in[i]);
	sort(in,in+N);
	dfs(0);
	for (int i = 0; i <N; ++i){
		if(i!=0)printf(" ");
		printf("%d",level[i]);
	}
	system("pause");
	return 0;
}