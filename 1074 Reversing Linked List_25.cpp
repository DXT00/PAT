#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int start,ad,da,ne,N,K;
struct Node
{
	int add,data,next;
};
std::vector<Node> v(100005);
std::vector<Node> res;
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&start,&N,&K);
	if(N==0)return 0;
	for (int i = 0; i <N; ++i)
	{
		scanf("%d%d%d",&ad,&da,&ne);	
			v[ad].add=ad;
			v[ad].data=da;
			v[ad].next=ne;
		}
	for (int i = start; i!=-1; i=v[i].next)
		res.push_back(v[i]);	

	for (int i=0; i <res.size()/K; ++i)///!!!!有坑！i<res.size()/K-----而不是i<N/K！！！（链表节点<=N个）题目给出的N个节点不一定都在链表中！！
		reverse(res.begin()+i*K,res.begin()+(i+1)*K);
	
	int j = 0;
	for ( j=0;j+1 < res.size(); ++j)
	{
		printf("%05d %d %05d\n",res[j].add,res[j].data,res[j+1].add);
	}
	printf("%05d %d -1\n",res[res.size()-1].add,res[res.size()-1].data);
	getchar();
	system("pause");
	return 0;
}
