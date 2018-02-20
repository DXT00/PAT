#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Node{
	int add,data,next;
};
int start,N,K,x;
vector<Node> v(100002);
vector<Node> res;
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&start,&N,&K);
	for (int i = 0; i <N; ++i){
		scanf("%d",&x);
		scanf("%d%d",&v[x].data,&v[x].next);
		v[x].add=x;
	}
	int cur=start;
	while(cur!=-1){
		res.push_back(v[cur]);
		cur=v[cur].next;
	}
	for ( int i = 0; i <res.size()/K; ++i)
		reverse(res.begin()+i*K,res.begin()+(i+1)*K);
	
	for (int i = 0; i+1 <res.size(); ++i){
		printf("%05d %d %05d\n",res[i].add,res[i].data,res[i+1].add);
	}printf("%05d %d %d\n",res[res.size()-1].add,res[res.size()-1].data,-1);
	system("pause");
	return 0;
}
